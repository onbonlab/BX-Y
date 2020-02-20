#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDynamicFile 对话框

class CDynamicFile : public CDialogEx
{
	DECLARE_DYNAMIC(CDynamicFile)

public:
	CDynamicFile(DynamicArea* pArea,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDynamicFile();

// 对话框数据
	enum { IDD = IDD_DYNAMICFILEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	DynamicArea* m_pArea;
	vector<DynamicAreaFile> m_vecUnit;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	int m_PlayRelation;
	int m_RunTime;
	int m_PageType;
	short m_X;
	short m_Y;
	short m_W;
	short m_H;
	int m_RelProgram;
	CComboBox m_cmbAreaId;
	CSliderCtrl m_ctrlSlider;
	CComboBox m_cmbRunMode;
	CListBox m_PageList;
	CComboBox m_cmbDisplayEffect;
	afx_msg void OnBnClickedUnitAdd();
	afx_msg void OnLbnSelchangeListUnit();
	afx_msg void OnCbnKillfocusCombo1();
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit31();
	afx_msg void OnBnClickedButton3();
//	afx_msg void OnCbnSelchangeCombo1();
};
