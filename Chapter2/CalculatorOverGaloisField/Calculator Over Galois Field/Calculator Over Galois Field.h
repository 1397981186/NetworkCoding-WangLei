
// Calculator Over Galois Field.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCalculatorOverGaloisFieldApp: 
// �йش����ʵ�֣������ Calculator Over Galois Field.cpp
//

class CCalculatorOverGaloisFieldApp : public CWinApp
{
public:
	CCalculatorOverGaloisFieldApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCalculatorOverGaloisFieldApp theApp;