
// SNCcrackDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CSNCcrackDlg �Ի���
class CSNCcrackDlg : public CDialogEx
{
// ����
public:
	CSNCcrackDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SNCCRACK_DIALOG };

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
	UINT m_nM;
	CEdit m_Matrix;
	afx_msg void OnBnClickedButtonRead();
	afx_msg void OnBnClickedButtonBruteforce();
//	long factorial(int n);
//	void BruteForce();
//	void BruthForce(int** M, int nRow, int nCol);
//	void BruteForce(int& M, int nRow, int nCol);
//	void BruteForce(int* & M, int nRow, int nCol);
//	void Bruth(int** & M, int nRow, int nCol);
//	void BruteForce(const int** & M, int nRow, int nCol);
//	void BruteForce(const int** G, int nRow, int nCol);
//	void BruteForce(int** G, int nRow, int nCol);
//	bool BruteForce(int** G, int nRow, int nCol);
//	bool vectorComb(int** G, int nRow, int nCol);
//	bool vectorComb(int** G, int nRow, int nCol, int** matrix, int nTotal, int nCur, int i);
	bool BruteForce(int** G, int nRow, int nCol);
//	bool vectorComb(int** G, int nRow, int nCol, int** & matrix, int nTotal, int nCur, int i);
//	bool vectorComb(int** G, int nRow, int nCol, int** matrix, int nTotal, int nCur, int i);
};
