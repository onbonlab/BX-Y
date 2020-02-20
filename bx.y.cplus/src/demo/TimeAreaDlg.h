#pragma once
#include "afxfontcombobox.h"
#include "afxwin.h"
#include "afxcolorbutton.h"


// CTimeAreaDlg �Ի���

class CTimeAreaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTimeAreaDlg)

public:
	CTimeAreaDlg(TimeArea* p,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTimeAreaDlg();

// �Ի�������
	enum { IDD = IDD_TIMEAREADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	TimeArea* m_pArea;
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedCheck13();
	CMFCFontComboBox m_cmbFont;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	int m_bMultiLine;
public:
	CSliderCtrl m_ctrlSlider;
	CComboBox m_cmbFlag;
	CComboBox m_cmbAlign;
	CMFCColorButton m_btnText;
	CMFCColorButton m_btnTime;
	CMFCColorButton m_btnWeek;
	CMFCColorButton m_btnDate;
	afx_msg void OnEnChangeDayX();
};
