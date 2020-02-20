// ServerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "ServerDlg.h"
#include "afxdialogex.h"

#include "ScreenProperty.h"
#include "NetDlg.h"
#include "VolumeDlg.h"
#include "BrightDlg.h"
#include "OnoffDlg.h"
#include "FirmwareDlg.h"
#include "PlaylistDlg.h"
#include "DynamicList.h"
#include <sstream>
#include <fstream>
// CServerDlg 对话框

IMPLEMENT_DYNAMIC(CServerDlg, CDialogEx)

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CServerDlg::IDD, pParent)
	,m_nServerPort(6005)
	,m_nFtpServerPort(8888)
{

}

CServerDlg::~CServerDlg()
{
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO9, m_cmbCardList);
	DDX_Text(pDX,IDC_EDIT3,m_nServerPort);
	DDX_Text(pDX,IDC_EDIT5,m_nFtpServerPort);
}


BEGIN_MESSAGE_MAP(CServerDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON29, &CServerDlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON30, &CServerDlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON33, &CServerDlg::OnBnClickedButton33)
	ON_BN_CLICKED(IDC_BUTTON1, &CServerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CServerDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &CServerDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CServerDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON11, &CServerDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON32, &CServerDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON10, &CServerDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON2, &CServerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON15, &CServerDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON9, &CServerDlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// CServerDlg 消息处理程序


void CServerDlg::OnBnClickedButton29()
{
	CString str;
	GetDlgItem(IDC_EDIT3)->GetWindowText(str);
	int port=_tstoi(str);
	int err=0;
	err=Start_Native_Server(port);
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
	}
	else
	{
		GetDlgItem(IDC_BUTTON30)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON29)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON33)->EnableWindow(TRUE);
		theApp.m_bServerRun=true;
	}
}


void CServerDlg::OnBnClickedButton30()
{	
	char name[155];
	char *host_ip;
	PHOSTENT hostinfo;
	if( gethostname ( name, sizeof(name)) == 0)
	{
		printf("hostname=%s\n", name );
		if((hostinfo = gethostbyname(name)) != NULL)
		{
			host_ip = inet_ntoa (*(struct in_addr *)*hostinfo->h_addr_list);
		}
	}
	_TEXT_CHAR* pid=_TEXT_T("");
	int index=m_cmbCardList.GetCurSel();
	TCHAR barcode[17]={0};
	memset(barcode,0,sizeof(barcode));
	Char2TCHAR(barcode,m_Cardlist[index].barcode);
	int err=set_screen_server(barcode,pid,host_ip,theApp.ftp_server_port,0);
	Stop_Server();
	GetDlgItem(IDC_BUTTON30)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON29)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON33)->EnableWindow(FALSE);
	m_cmbCardList.ResetContent();

	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON32)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	theApp.m_bServerRun=false;
}
void LOG(string str) 
{
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0;
	wstring path=szFilePath;
	ofstream m_logfile;
	m_logfile.open(path+_T("user_log.txt"),ios::app|ios::out);
	if (m_logfile.is_open()) {m_logfile <<str<<endl;}  
	m_logfile.close(); 
}
string char2hex(unsigned char v)
{
	stringstream ss;
	ss.width(2);
	ss.fill('0');
	ss <<hex  << v;
	return " "+ss.str();
}
void TcharToChar(const TCHAR * tchar, char * _char)
{
    int iLength;
    //获取字节长度   
    iLength = WideCharToMultiByte(CP_ACP, 0, tchar, -1, NULL, 0, NULL, NULL);
    //将tchar值赋给_char    
    WideCharToMultiByte(CP_ACP, 0, tchar, -1, _char, iLength, NULL, NULL);
}

void CServerDlg::OnBnClickedButton33()
{
	m_cmbCardList.ResetContent();
	BYTE card[4096]={0};
	int card_count=0;
	Sleep(200);
	Get_CardList(card,&card_count);
	for (int i=0;i<card_count;i++)
	{
		BroadCast2 data;
		memcpy(&data,card+(i*sizeof(BroadCast2)),sizeof(BroadCast2));
		m_datas[i]=data;
		/*TCHAR barcode[17];
		memset(barcode,0,sizeof(barcode));
		memcpy(barcode,card + (i+1) * 31 * 2,sizeof(barcode));
		TcharToChar(barcode,m_Cardlist[i].barcode);*/
		m_cmbCardList.AddString(data.barcode);
	}
	if (card_count>0)
	{
		m_cmbCardList.SetCurSel(0);

		GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON11)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON15)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON32)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON15)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON32)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	}
}



void CServerDlg::OnBnClickedButton1()
{
	CString str;
	GetDlgItem(IDC_IPADDRESS1)->GetWindowText(str);
	CString2Char(str,theApp.ftp_server_ip);
	GetDlgItem(IDC_EDIT5)->GetWindowText(str);
	theApp.ftp_server_port=_tstoi(str);
	GetDlgItem(IDC_EDIT7)->GetWindowText(str);
	CString2Char(str,theApp.ftp_server_user);
	GetDlgItem(IDC_EDIT14)->GetWindowText(str);
	CString2Char(str,theApp.ftp_server_pwd);
}


BOOL CServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (theApp.m_bServerRun)
	{
		GetDlgItem(IDC_BUTTON30)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON29)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON33)->EnableWindow(TRUE);
	} 
	else
	{
	GetDlgItem(IDC_BUTTON30)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON29)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON33)->EnableWindow(FALSE);
	}


	TCHAR szTemp[64]={0};
	memset(szTemp,0,sizeof(szTemp));
	Char2TCHAR(szTemp,theApp.ftp_server_ip);
	GetDlgItem(IDC_IPADDRESS1)->SetWindowText(szTemp);
	CString str;
	str.Format(_T("%d"),theApp.ftp_server_port);
	GetDlgItem(IDC_EDIT5)->SetWindowText(str);
	Char2TCHAR(szTemp,theApp.ftp_server_user);
	GetDlgItem(IDC_EDIT7)->SetWindowText(szTemp);
	Char2TCHAR(szTemp,theApp.ftp_server_pwd);
	GetDlgItem(IDC_EDIT14)->SetWindowText(szTemp);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CServerDlg::OnBnClickedButton5()
{
	int index=m_cmbCardList.GetCurSel();
	CScreenProperty dlg(theApp.ftp_server_ip,m_datas[m_cmbCardList.GetCurSel()].pid);
	dlg.DoModal();

}


void CServerDlg::OnBnClickedButton8()
{
	int index=m_cmbCardList.GetCurSel();
	CNetDlg dlg(theApp.ftp_server_ip,theApp.ftp_server_port,m_datas+m_cmbCardList.GetCurSel());

	dlg.DoModal();

}


void CServerDlg::OnBnClickedButton11()
{
	
	_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	int index=m_cmbCardList.GetCurSel();
	unsigned short port=Get_Port_Pid(m_datas[m_cmbCardList.GetCurSel()].pid);
	int err=check_time(theApp.ftp_server_ip,port,user_name,user_pwd);
	if (err!=ERR_NO)
	{
		AfxMessageBox(GetErrText(err));
	}

}


void CServerDlg::OnBnClickedButton32()
{
	int index=m_cmbCardList.GetCurSel();
	CVolumeDlg dlg(theApp.ftp_server_ip,m_datas[m_cmbCardList.GetCurSel()].pid);

	dlg.DoModal();
}


void CServerDlg::OnBnClickedButton10()
{
	CBrightDlg dlg(theApp.ftp_server_ip,m_datas[m_cmbCardList.GetCurSel()].pid);

	dlg.DoModal();
}


void CServerDlg::OnBnClickedButton9()
{
	int index=m_cmbCardList.GetCurSel();
	COnoffDlg dlg(theApp.ftp_server_ip,m_datas[m_cmbCardList.GetCurSel()].pid);

	dlg.DoModal();
}


void CServerDlg::OnBnClickedButton7()
{
	CFirmwareDlg dlg(theApp.ftp_server_ip,m_datas[m_cmbCardList.GetCurSel()].pid);

	dlg.DoModal();

}


void CServerDlg::OnBnClickedButton2()
{
	CPlaylistDlg dlg(theApp.ftp_server_ip,m_datas[m_cmbCardList.GetCurSel()].pid);

	dlg.DoModal();

}


void CServerDlg::OnBnClickedButton15()
{
	
	DynamicList dlg(theApp.ftp_server_ip,m_datas[m_cmbCardList.GetCurSel()].pid);

	dlg.DoModal();
}