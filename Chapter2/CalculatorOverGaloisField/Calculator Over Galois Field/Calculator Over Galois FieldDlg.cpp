
// Calculator Over Galois FieldDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calculator Over Galois Field.h"
#include "Calculator Over Galois FieldDlg.h"
#include "afxdialogex.h"
#include "gf.c"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorOverGaloisFieldDlg �Ի���



CCalculatorOverGaloisFieldDlg::CCalculatorOverGaloisFieldDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculatorOverGaloisFieldDlg::IDD, pParent)
	, m_nAlter1(0)
	, m_nAlter2(0)
	, m_nResult(0)
	

	, m_nType(0)
	
	, m_chOperator(_T(""))
	, m(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorOverGaloisFieldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_nAlter1);
	DDX_Text(pDX, IDC_EDIT3, m_nAlter2);
	DDX_Text(pDX, IDC_EDIT4, m_nResult);


	DDX_Text(pDX, IDC_m_chOperator, m_chOperator);
	DDX_Text(pDX, IDC_EDIT1, m);
}

BEGIN_MESSAGE_MAP(CCalculatorOverGaloisFieldDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	
	
	ON_BN_CLICKED(IDC_BUTTON_Add, &CCalculatorOverGaloisFieldDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_Sub, &CCalculatorOverGaloisFieldDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_Mul, &CCalculatorOverGaloisFieldDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_Div, &CCalculatorOverGaloisFieldDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_Exp, &CCalculatorOverGaloisFieldDlg::OnBnClickedButtonExp)
	ON_BN_CLICKED(IDC_BUTTON_Cal, &CCalculatorOverGaloisFieldDlg::OnBnClickedButtonCal)
	ON_EN_CHANGE(IDC_EDIT1, &CCalculatorOverGaloisFieldDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CCalculatorOverGaloisFieldDlg ��Ϣ�������

BOOL CCalculatorOverGaloisFieldDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m = 8;
	m_chOperator = "+";
	m_nType = 1;
	UpdateData(FALSE);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCalculatorOverGaloisFieldDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCalculatorOverGaloisFieldDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCalculatorOverGaloisFieldDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CCalculatorOverGaloisFieldDlg::OnBnClickedButtonAdd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_nType = 1;
	m_chOperator = "+";
	UpdateData(FALSE);
}


void CCalculatorOverGaloisFieldDlg::OnBnClickedButtonSub()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_nType = 2;
	m_chOperator = "-";
	UpdateData(FALSE);

}


void CCalculatorOverGaloisFieldDlg::OnBnClickedButtonMul()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_nType = 3;
	m_chOperator = "*";
	UpdateData(FALSE);
}


void CCalculatorOverGaloisFieldDlg::OnBnClickedButtonDiv()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_nType = 4;
	m_chOperator = "/";
	UpdateData(FALSE);
}


void CCalculatorOverGaloisFieldDlg::OnBnClickedButtonExp()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_nType = 5;
	m_chOperator = "^";
	UpdateData(FALSE);
}


void CCalculatorOverGaloisFieldDlg::OnBnClickedButtonCal()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m < 0 || m>12){
		MessageBox(_T("Please input 0<m<13."));
		return;
	}
	gf_init(m, prim_poly[m]);
	if (m_nAlter1 > pow(2.0, m) || m_nAlter2 > pow(2.0, m))
	{
		MessageBox(_T("First value is greater than field size."));
		return;
	}
	if (m_nType == 1)
	{
		m_nResult = gf_add(m_nAlter1, m_nAlter2);
	}
	else if (m_nType == 2)
	{
		m_nResult = gf_sub(m_nAlter1, m_nAlter2);
	}
	else if (m_nType == 3)
	{
		m_nResult = gf_mul(m_nAlter1, m_nAlter2);
	}
	else if (m_nType == 4)
	{
		m_nResult = gf_div(m_nAlter1, m_nAlter2);
	}
	else if (m_nType == 5)
	{
		m_nResult = gf_exp(m_nAlter1, m_nAlter2);
	}
	UpdateData(FALSE);
}


void CCalculatorOverGaloisFieldDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
