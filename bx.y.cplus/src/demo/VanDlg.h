#pragma once


// CVanDlg �Ի���

class CVanDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CVanDlg)

public:
	CVanDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CVanDlg();

// �Ի�������
	enum { IDD = IDD_VANDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
