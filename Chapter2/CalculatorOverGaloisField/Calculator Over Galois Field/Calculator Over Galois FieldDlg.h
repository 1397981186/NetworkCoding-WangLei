
// Calculator Over Galois FieldDlg.h : ͷ�ļ�
//

#pragma once


// CCalculatorOverGaloisFieldDlg �Ի���
class CCalculatorOverGaloisFieldDlg : public CDialogEx
{
// ����
public:
	CCalculatorOverGaloisFieldDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATOROVERGALOISFIELD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nAlter1;
	int m_nAlter2;
	int m_nResult;

	unsigned int m_nType;
	
	CString m_chOperator;

	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonExp();
	afx_msg void OnBnClickedButtonCal();
	int m;
	afx_msg void OnEnChangeEdit1();
};
