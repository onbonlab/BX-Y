#pragma once
#include "afxcmn.h"


// CVideoAreaDlg �Ի���

class CVideoAreaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CVideoAreaDlg)

public:
	CVideoAreaDlg(VideoArea* p,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CVideoAreaDlg();

// �Ի�������
	enum { IDD = IDD_VIDEOAREADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	VideoArea* m_pArea;
	vector<VideoUnit> m_vecUnit;
public:
	CSliderCtrl m_ctrlSlider;
	CComboBox m_cmbDisplayScale;
	CListBox m_ctrlUnitList;
public:
	afx_msg void OnBnClickedUnitAdd();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedUnitRemove();
	afx_msg void OnCbnKillfocusCombo1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnLbnSelchangeListUnit();
	CSliderCtrl m_VolumeSlider;
	afx_msg void OnNMReleasedcaptureSlider2(NMHDR *pNMHDR, LRESULT *pResult);
};
