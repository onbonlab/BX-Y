#pragma once


// CScreenProperty 对话框

class CScreenProperty : public CDialogEx
{
	DECLARE_DYNAMIC(CScreenProperty)

public:
	CScreenProperty(char *ip,CWnd* pParent = NULL);   // 标准构造函数
	CScreenProperty(char *ip,_TEXT_CHAR* pid,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CScreenProperty();

// 对话框数据
	enum { IDD = IDD_SCREENPROPERTY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSetScreeninfo();
public:
	CComboBox m_cmbCardType;
	virtual BOOL OnInitDialog();
private:
	int card_mode;
	controllerInfo info;
	_TEXT_CHAR controller_name[128];
	char card_ip[20];
    _TEXT_CHAR* card_PID;
public:
	afx_msg void OnCbnSelchangeCombo4();
};
