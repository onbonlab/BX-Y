#pragma once
#include "afxdtctl.h"
#include "afxcolorbutton.h"


// CCounterAreaDlg �Ի���

class CCounterAreaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCounterAreaDlg)

public:
	CCounterAreaDlg(CounterArea* p,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCounterAreaDlg();

// �Ի�������
	enum { IDD = IDD_COUNTERAREADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CounterArea* m_pArea;
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CDateTimeCtrl m_ctrlDate;
	CDateTimeCtrl m_ctrlTime;
	CMFCColorButton m_btnCounter;
	CSliderCtrl m_ctrlSlider;

	CComboBox m_cmbAlign;
	CMFCColorButton m_btnText;
	int m_bMultiLine;
	CMFCFontComboBox m_cmbFont;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnEnChangeEdit3();
};
