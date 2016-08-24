
// NetworkCodingFileDlg.h : ͷ�ļ�
//

#pragma once


// CNetworkCodingFileDlg �Ի���
class CNetworkCodingFileDlg : public CDialogEx
{
// ����
public:
	CNetworkCodingFileDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_NETWORKCODINGFILE_DIALOG };

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
	int K;
	int N;
	afx_msg void OnBnClickedOpen();
	afx_msg void OnBnClickedEncode();
	afx_msg void OnBnClickedReencode();
	afx_msg void OnBnClickedRecover();
	afx_msg void OnBnClickedBrowse();
//	afx_msg void OnBnClickedClear();
	CString g_filePath;
	int g_flag=0;
	CString g_extName;
	CString Step_info;
	byte** Inverse(byte** G, int n);
	byte** Multiply(byte** matA, byte** matB, int nRow, int n, int nCol);
	void Scroll();
	void PostNcDestroy();
	void DeleteFiles();
	afx_msg void OnBnClickedDownload();
};
