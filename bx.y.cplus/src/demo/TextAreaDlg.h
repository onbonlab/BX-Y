#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CTextAreaDlg �Ի���

class CTextAreaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTextAreaDlg)

public:
	CTextAreaDlg(StrArea* p,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTextAreaDlg();

// �Ի�������
	enum { IDD = IDD_TEXTAREADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	StrArea* m_pArea;
	vector<StrUnit*> m_vecUnit;
public:
	CSliderCtrl m_ctrlSlider;
	CComboBox m_cmbDisplayEffect;
	CListBox m_ctrlUnitList;
	CComboBox m_cmbunit_type;
public:
	afx_msg void OnBnClickedUnitRemove();
	afx_msg void OnLbnSelchangeListUnit();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit31();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButton4();
};
