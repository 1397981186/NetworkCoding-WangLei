
// SNCcrack.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSNCcrackApp: 
// �йش����ʵ�֣������ SNCcrack.cpp
//

class CSNCcrackApp : public CWinApp
{
public:
	CSNCcrackApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSNCcrackApp theApp;