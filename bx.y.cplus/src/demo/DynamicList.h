#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// DynamicList �Ի���

class DynamicList : public CDialogEx
{
	DECLARE_DYNAMIC(DynamicList)

public:
	DynamicList(char* ip,CWnd* pParent = NULL);   // ��׼���캯��
	DynamicList(char*ip,_TEXT_CHAR* pid,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DynamicList();

// �Ի�������
	enum { IDD = IDD_DYNAMICLISTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton6();

private:
	int card_mode;
	char card_ip[20];
    _TEXT_CHAR* card_PID;
	ProgramDyanmic* m_ProgramDyanmic;
	vector<DynamicArea*> m_Area;
	DWORD m_hSend;
public:
	CListBox m_dynamicList;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedSend();
	afx_msg void OnBnClickedButton31();
};
