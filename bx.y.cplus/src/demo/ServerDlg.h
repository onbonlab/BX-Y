#pragma once


// CServerDlg �Ի���

class CServerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CServerDlg)

public:
	CServerDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CServerDlg();

// �Ի�������
	enum { IDD = IDD_SERVERDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_cmbCardList;
	server_card m_Cardlist[1024];
	BroadCast2 m_datas[30];
	int m_nServerPort;
	int m_nFtpServerPort;
	afx_msg void OnBnClickedButton29();
	afx_msg void OnBnClickedButton30();
	afx_msg void OnBnClickedButton33();

	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton32();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton9();
};
