#pragma once
#include "afxcmn.h"
#include "afxdtctl.h"
#include "afxcolorbutton.h"
#include "afxfontcombobox.h"


// CStrPageDlg �Ի���

class CStrPageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStrPageDlg)

public:
	CStrPageDlg(StrUnit* pPage,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStrPageDlg();

// �Ի�������
	enum { IDD = IDD_STRPAGEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	
	CMFCColorButton m_btnTextColor;
	CMFCColorButton m_btnBgColor;
public:
	UINT m_BgColor;
	int m_Linespace;
	wstring m_Content;
	virtual BOOL OnInitDialog();
	CMFCFontComboBox m_cmbFont;
private:
	StrUnit* m_pPage;
public:
	afx_msg void OnBnClickedCancel();
};
