// FordFulkson.cpp: implementation of the CFordFulkson class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SRNC_Constructor.h"
#include "FordFulkson.h"
#include "Link.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFordFulkson::CFordFulkson()
{
	for (int i=0; i<20; i++)
	{
		for (int j=0; j<20; j++)
		{
			Route[i][j] = -1;
		}
	}
}

CFordFulkson::~CFordFulkson()
{
	for(int i = 0; i < nNodeNum; i++) 
	{
		delete []C[i]; 
	}
	delete []C; 
	
	delete []PreNode;
	delete []Visit;
	delete []Queue;
}
void CFordFulkson::Initialize()
{
	C = new int*[nNodeNum];
	for(int i=0; i<nNodeNum; i++)
	{
		C[i] = new int[nNodeNum];
	}
	
	Visit = new int[nNodeNum];
	PreNode = new int[nNodeNum];
	Queue = new int[nNodeNum];
	
}

int CFordFulkson::RunFF()
{
	int i = 0;
	int _min = 0;
	int total = 0;

	while(true)
	{
		if(!Edmonds_Karp())
		{	
			// �����ͱ�ʾû���ҵ�����·��
			// Ϊÿ����·�ҵ���һ����·
			POSITION pos = pLinkList->GetHeadPosition();
			while (pos != NULL)
			{
				CLink* pLink = (CLink*)pLinkList->GetAt(pos);
				if (pLink->nShared % 2 == 1)
				{
					
					POSITION pos2 = pLinkList->GetHeadPosition();
					bool bNeedExit = false;
					while (pos2 != NULL)
					{	
						CLink* pPreLink = (CLink*)pLinkList->GetAt(pos2);
						if ((pPreLink->nShared % 2 == 1) && pPreLink->nEndAt == pLink->nStartAt)
						{


							bool bFind = false;
							for (int k=0; k<pLink->nInputLink; k++)
							{
								if (pLink->nPreLink[k] == pPreLink->nLinkNum)
								{
									bFind = TRUE;
									break;
								}
							}
							if (bFind == TRUE)
							{
								bNeedExit = true;
							}
							else
							{
								int n = pLink->nInputLink;
								pLink->nPreLink[n] = pPreLink->nLinkNum;
								pLink->nInputLink++;
								bNeedExit = true;	
							}

						}

						if (bNeedExit == TRUE)
						{
							break;
						}
						else
						{
							pLinkList->GetNext(pos2);
						}
						
					}
					
					
				}
	
				pLinkList->GetNext(pos);
			
			}

			// ��ʱnSharedΪ������ʾ���û�۽ڵ������ʱ�õ�����·
			pos = pLinkList->GetHeadPosition();
			int nRouteNum = 0;
			while (pos != NULL)
			{
				CLink* pLink = (CLink*)pLinkList->GetAt(pos);
				if (pLink->nStartAt == nSrc && pLink->nShared%2 == 1  && pLink->bAddToRouteTable == FALSE)		//	���ΪԴ�ڵ�
				{
					// Output the route array to the sink node
					int nCurPos = nSrc;
					int nHopNum = 0;
					Route[nRouteNum][nHopNum++] = pLink->nLinkNum;	

					CLink *pPre_link = pLink;
					while(1)
					{		
						POSITION next_pos = pLinkList->GetHeadPosition();
						while (next_pos != NULL)
						{
							CLink* pNextLink = (CLink*)pLinkList->GetAt(next_pos);
							if (pNextLink->nStartAt == pPre_link->nEndAt && pNextLink->bAddToRouteTable == FALSE && pNextLink->nShared%2 == 1)
							{
								Route[nRouteNum][nHopNum++] = pNextLink->nLinkNum;
								pNextLink->bAddToRouteTable = TRUE;
								pPre_link = pNextLink;
								break;
							}

							pLinkList->GetNext(next_pos);

						}
						if (pPre_link->nEndAt == nDes)
						{
							break;
						}

					}
					nRouteNum++;
				}
				pLinkList->GetNext(pos);
				
			}



			 // ����Ҫ����·��ǳ���
			pos = pLinkList->GetHeadPosition();
			while (pos != NULL)
			{
				CLink* pLink = (CLink*)pLinkList->GetAt(pos);
				if (pLink->nShared % 2 == 1)
				{
					pLink->bInSubGraph = TRUE;
				
				}
				pLink->nShared = 0;
				pLink->bAddToRouteTable = FALSE;			// Reset
				pLinkList->GetNext(pos);
			}
		


			return total;;				//����Ҳ�������·�ͷ��أ��ھ���ʵ��ʱ�滻������
		}
		_min = (1<<30);
		int des = nDes - 1;
		int src = nSrc - 1;
		i = des;
		while(i != src)
		{								//ͨ��pre�����������·���ϵıߣ����������������Сֵ
			if(_min > C[PreNode[i]][i])
			{
				_min=C[PreNode[i]][i];
			}
			i = PreNode[i];
		}
		i = des;
		while (i != src)
		{    //�ٴα�������������·���ϱߵ���ֵ
			C[PreNode[i]][i] -= _min;
			C[i][PreNode[i]] += _min;
			i = PreNode[i];
		}
		total += _min;     //ÿ�μ��ϸ��µ�ֵ

		// Record the route
		int nHops = 0;
		i = des;
		int routeTemp[20];
		routeTemp[0] = des;
		while ( TRUE )
		{
			if (PreNode[i] == src)
			{
				nHops++;
				routeTemp[nHops] = PreNode[i];
				i= PreNode[i];
				break;
			}
			else
			{
				nHops++;
				routeTemp[nHops] = PreNode[i];
				i= PreNode[i];
				
			}
		}
		// Reverse the route, and store it into Routes array.
// 		for (i=0; i<nHops; i++)
// 		{
// 			Route[total-1][i] = routeTemp[nHops-1-i];
// 		}

		for (i=0; i<nHops; i++)
		{
			int nCnt = pLinkList->GetCount();
			POSITION pos = pLinkList->GetHeadPosition();
			while (pos != NULL)
			{
				// Both direction is ok.
				CLink* pLink = (CLink*)pLinkList->GetAt(pos);
				// Since the number of node start with 1, but the index in the array starts with 0,
				// So we must decrease 1.
				if (pLink->nStartAt-1 == routeTemp[i] && pLink->nEndAt-1 == routeTemp[i+1])
				{
					pLink->nShared = pLink->nShared+1;
				
				}
				// OR
				if (pLink->nEndAt-1 == routeTemp[i] && pLink->nStartAt-1 == routeTemp[i+1])
				{
					pLink->nShared = pLink->nShared+1;
				
				}
				pLinkList->GetNext(pos);
			}

		}	
		
	}
	// 


	

}

bool CFordFulkson::Edmonds_Karp()
{
	int v,i;

	for(i=0;i<nNodeNum;i++)
	{	
		Visit[i]=false;
	}
	
	int nfront = 0;
	int nRear = 0;
	int src = nSrc;
	int des = nDes;
	 
	src = nSrc - 1;
	des = nDes - 1;

	Queue[nRear++]=src;
	Visit[src] = true;
	while(nfront != nRear)
	{     
		v=Queue[nfront++]; 

		for(i=0; i<nNodeNum; i++)
		{ 
			if(!Visit[i] && C[v][i])
			{  
				Queue[nRear++] = i;
				Visit[i] = true;
				PreNode[i] = v;
				if(i == des)
				{
					return true;   //����Ѿ������㣬˵����������·������true
				}
			}
		}
	}
	return false;

}

