#pragma once
#include "afxcmn.h"
#include "afxdtctl.h"


// CProgramDlg �Ի���

class CProgramDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProgramDlg)

public:
	CProgramDlg(Program* p,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CProgramDlg();

// �Ի�������
	enum { IDD = IDD_PROGRAMDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
private:
	Program* m_Program;
	vector<Area*>m_vecArea;
public:
	CListCtrl m_ctrlAreaList;
	afx_msg void OnBnClickedButton3();
	virtual BOOL OnInitDialog();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	int m_Playmode;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck6();
	CDateTimeCtrl m_ctrlDate1;
	CDateTimeCtrl m_ctrlDate2;
	CDateTimeCtrl m_ctrlTime1;
	CDateTimeCtrl m_ctrlTime2;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnEnChangeEdit2();
};
