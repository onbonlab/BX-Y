#pragma once


// COnoffDlg �Ի���

class COnoffDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COnoffDlg)

public:
	COnoffDlg(char *ip,CWnd* pParent = NULL);   // ��׼���캯��
	COnoffDlg(char* ip,_TEXT_CHAR* pid,CWnd* pParent = NULL); 
	virtual ~COnoffDlg();

// �Ի�������
	enum { IDD = IDD_ONOFFDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	int m_Onoff;
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
private:
	int card_mode;
	char card_ip[20];
    _TEXT_CHAR* card_PID;
};
