
// NetworkCoding.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CNetworkCodingApp: 
// �йش����ʵ�֣������ NetworkCoding.cpp
//

class CNetworkCodingApp : public CWinApp
{
public:
	CNetworkCodingApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CNetworkCodingApp theApp;