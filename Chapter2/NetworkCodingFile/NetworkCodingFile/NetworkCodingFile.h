
// NetworkCodingFile.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CNetworkCodingFileApp: 
// �йش����ʵ�֣������ NetworkCodingFile.cpp
//

class CNetworkCodingFileApp : public CWinApp
{
public:
	CNetworkCodingFileApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CNetworkCodingFileApp theApp;