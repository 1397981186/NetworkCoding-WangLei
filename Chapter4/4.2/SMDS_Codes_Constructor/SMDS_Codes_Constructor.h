
// SMDS_Codes_Constructor.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSMDS_Codes_ConstructorApp: 
// �йش����ʵ�֣������ SMDS_Codes_Constructor.cpp
//

class CSMDS_Codes_ConstructorApp : public CWinApp
{
public:
	CSMDS_Codes_ConstructorApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSMDS_Codes_ConstructorApp theApp;