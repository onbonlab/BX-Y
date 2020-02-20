#pragma once
#include "afxcmn.h"


// CVolumeDlg 对话框

class CVolumeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CVolumeDlg)

public:
	CVolumeDlg(char* ip,CWnd* pParent = NULL);   // 标准构造函数
	CVolumeDlg(char* ip ,_TEXT_CHAR* pid,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CVolumeDlg();

// 对话框数据
	enum { IDD = IDD_VOLUMEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CSliderCtrl m_VolumeSlider;
	afx_msg void OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult);
private:
	int card_mode;
	char card_ip[20];
    _TEXT_CHAR* card_PID;
public:
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
};
