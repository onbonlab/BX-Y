#pragma once


// CBrightDlg 对话框

class CBrightDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBrightDlg)

public:
	CBrightDlg(char *ip,CWnd* pParent = NULL);   // 标准构造函数
	CBrightDlg(char *ip,_TEXT_CHAR* pid,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBrightDlg();

// 对话框数据
	enum { IDD = IDD_BRIGHTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_Mode;
	afx_msg void OnBnClickedAdjustBright();
	virtual BOOL OnInitDialog();
private:
	int card_mode;
	char card_ip[20];
    _TEXT_CHAR* card_PID;
public:
	afx_msg void OnBnClickedRadio2();
};
