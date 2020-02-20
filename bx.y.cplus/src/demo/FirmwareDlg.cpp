// FirmwareDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "FirmwareDlg.h"
#include "afxdialogex.h"


// CFirmwareDlg �Ի���

IMPLEMENT_DYNAMIC(CFirmwareDlg, CDialogEx)

CFirmwareDlg::CFirmwareDlg(char *ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(CFirmwareDlg::IDD, pParent)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}
CFirmwareDlg::CFirmwareDlg(char* ip,_TEXT_CHAR* pid,CWnd* pParent /*=NULL*/)
	: CDialogEx(CFirmwareDlg::IDD, pParent)
{
	card_mode=1;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
	card_PID=pid;
}
CFirmwareDlg::~CFirmwareDlg()
{
}

void CFirmwareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFirmwareDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CFirmwareDlg::OnBnClickedButton3)
	ON_STN_CLICKED(IDC_UNIT_ADD, &CFirmwareDlg::OnStnClickedUnitAdd)
	ON_EN_CHANGE(IDC_EDIT1, &CFirmwareDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()

BOOL CFirmwareDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	_TEXT_CHAR firmwareversion[64]={0};
	_TEXT_CHAR app_version[64]={0};
	_TEXT_CHAR fpga_version[60];
	int err=0;
	if (card_mode==0)
	{
		unsigned short port=80;
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		err= get_firmware_version(card_ip, port,user_name,user_pwd,firmwareversion,app_version,fpga_version);
	}
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		err=get_firmware_version(card_ip, port,user_name,user_pwd,firmwareversion,app_version,fpga_version);
	}
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
	}
	else
	{
		
		
		GetDlgItem(IDC_EDIT1)->SetWindowText(firmwareversion);
		GetDlgItem(IDC_EDIT2)->SetWindowText(app_version);
		GetDlgItem(IDC_EDIT3)->SetWindowText(fpga_version);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CFirmwareDlg::OnBnClickedButton3()
{
	CString str;
	GetDlgItem(IDC_MFCFONTCOMBO1)->GetWindowText(str);
	wstring path(str);
	_TEXT_CHAR src_path[256];
	wcscpy(src_path,path.c_str());
	_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	if (card_mode==0)
	{
		int err=0;
		unsigned short port=80;
		err=update_firmware(card_ip,port,user_name,user_pwd,src_path);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}
	else
	{		
		unsigned short port=Get_Port_Pid(card_PID);

		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	    int err=update_firmware(card_ip,port,user_name,user_pwd,src_path);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}
}


void CFirmwareDlg::OnStnClickedUnitAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CFirmwareDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
