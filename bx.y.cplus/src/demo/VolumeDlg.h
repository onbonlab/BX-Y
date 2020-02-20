#pragma once
#include "afxcmn.h"


// CVolumeDlg �Ի���

class CVolumeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CVolumeDlg)

public:
	CVolumeDlg(char* ip,CWnd* pParent = NULL);   // ��׼���캯��
	CVolumeDlg(char* ip ,_TEXT_CHAR* pid,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CVolumeDlg();

// �Ի�������
	enum { IDD = IDD_VOLUMEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
