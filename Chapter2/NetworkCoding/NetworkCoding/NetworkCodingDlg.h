
// NetworkCodingDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CNetworkCodingDlg �Ի���
class CNetworkCodingDlg : public CDialogEx
{
// ����
public:
	CNetworkCodingDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_NETWORKCODING_DIALOG };

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
	afx_msg void OnBnClickedSelect();
	int K;
	int N;
	CString g_filePath;

	afx_msg void OnBnClickedCode();
	byte** Multiply(byte** matA, byte** matB, int nRow, int n, int nCol);
	afx_msg void OnBnClickedRecovery();
	byte** Inverse(byte** G, int n);
	int g_flag = 0;
	afx_msg void OnBnClickedOpendirectory();
	
	afx_msg void OnBnClickedClear();
//	CString m_szProgress;
	afx_msg void OnEnChangeProgress();
//	CString m_szProg;
	CString Step_info;
	afx_msg void OnBnClickedRecode();
//	CEdit Scroll;
//	void OutputWithScroll(const CString& strNewText, CEdit & edtOutput);
//	CEdit* pedit;
//	void stepInfo();
	void Scroll();
	CString g_extName;
};
