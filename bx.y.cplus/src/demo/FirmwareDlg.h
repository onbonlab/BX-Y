#pragma once


// CFirmwareDlg 对话框

class CFirmwareDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFirmwareDlg)

public:
	CFirmwareDlg(char *ip,CWnd* pParent = NULL);   // 标准构造函数
	CFirmwareDlg(char*ip,_TEXT_CHAR* pid,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFirmwareDlg();

// 对话框数据
	enum { IDD = IDD_FIRMWAREDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton3();
private:
	int card_mode;
	char card_ip[20];
    _TEXT_CHAR* card_PID;

public:
	afx_msg void OnStnClickedUnitAdd();
	afx_msg void OnEnChangeEdit1();
};
