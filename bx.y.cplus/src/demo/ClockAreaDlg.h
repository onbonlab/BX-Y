#pragma once
#include "afxfontcombobox.h"
#include "afxwin.h"
#include "afxcolorbutton.h"
#include "afxcmn.h"


// CClockAreaDlg �Ի���

class CClockAreaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CClockAreaDlg)

public:
	CClockAreaDlg(ClockArea* p,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CClockAreaDlg();

// �Ի�������
	enum { IDD = IDD_CLOCKAREADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	ClockArea* m_pArea;
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck13();
	CMFCFontComboBox m_cmbFont;
	CComboBox m_cmbStyle;
	CMFCColorButton m_btnDate;
	CMFCColorButton m_btnWeek;
	CMFCColorButton m_btnText;
	CMFCColorButton m_btnHourPt;
	CMFCColorButton m_btnMinPt;
	CMFCColorButton m_btnQuarterPt;
	CMFCColorButton m_btnHour;
	CMFCColorButton m_btnMin;
	CMFCColorButton m_btnSec;
	CComboBox m_cmbFlag;

	CSliderCtrl m_ctrlSlider;
	afx_msg void OnBnClickedMfccolorbutton4();
};
