// VanDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "VanDlg.h"
#include "afxdialogex.h"


// CVanDlg �Ի���

IMPLEMENT_DYNAMIC(CVanDlg, CDialogEx)

CVanDlg::CVanDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVanDlg::IDD, pParent)
{

}

CVanDlg::~CVanDlg()
{
}

void CVanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CVanDlg, CDialogEx)
END_MESSAGE_MAP()


// CVanDlg ��Ϣ�������


BOOL CVanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GetDlgItem(IDC_IPADDRESS1)->SetWindowText(_T("222.66.141.11"));
	GetDlgItem(IDC_EDIT7)->SetWindowText(_T("guest"));
	GetDlgItem(IDC_EDIT14)->SetWindowText(_T("guest"));

	GetDlgItem(IDC_EDIT10)->SetWindowText(_T("System"));
	GetDlgItem(IDC_EDIT11)->SetWindowText(_T("654321"));
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
