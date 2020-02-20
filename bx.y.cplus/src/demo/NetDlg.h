#pragma once


// CNetDlg �Ի���

class CNetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNetDlg)

public:
	CNetDlg(card_unit* pUnit,CWnd* pParent = NULL);   // ��׼���캯��
	CNetDlg(char *ip,int port,BroadCast2* pCard,CWnd* pParent = NULL);
	virtual ~CNetDlg();

// �Ի�������
	enum { IDD = IDD_NETDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_IpMode;
	int m_ClientMode;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	int serversport;
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio1();
private:
	int card_mode;
	card_unit* m_pUnit;
	BroadCast2* m_pServerCard;
	int m_serversport;
	char m_serversip[20];
public:
	afx_msg void OnBnClickedRadio4();
};
