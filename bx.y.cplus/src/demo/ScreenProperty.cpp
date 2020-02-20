// ScreenProperty.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "ScreenProperty.h"
#include "afxdialogex.h"


// CScreenProperty 对话框

IMPLEMENT_DYNAMIC(CScreenProperty, CDialogEx)

CScreenProperty::CScreenProperty(char *ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(CScreenProperty::IDD, pParent)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}
CScreenProperty::CScreenProperty(char *ip,_TEXT_CHAR* pid,CWnd* pParent /*=NULL*/)
	: CDialogEx(CScreenProperty::IDD, pParent)
{
	card_mode=1;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
	card_PID=pid;
}

CScreenProperty::~CScreenProperty()
{
}

void CScreenProperty::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO4, m_cmbCardType);
}


BEGIN_MESSAGE_MAP(CScreenProperty, CDialogEx)
	ON_BN_CLICKED(IDC_SET_SCREENINFO, &CScreenProperty::OnBnClickedSetScreeninfo)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CScreenProperty::OnCbnSelchangeCombo4)
END_MESSAGE_MAP()


// CScreenProperty 消息处理程序


void CScreenProperty::OnBnClickedSetScreeninfo()
{
	CString str;
	GetDlgItem(IDC_EDIT12)->GetWindowText(str);
	short w=_tstoi(str);
	GetDlgItem(IDC_EDIT9)->GetWindowText(str);
	short h=_tstoi(str);
	_TEXT_CHAR* controllername[4]={_TEXT_T("BX-Y0"),_TEXT_T("BX-Y2"),_TEXT_T("BX-Y2L"),_TEXT_T("BX-Y3")};
	int type=-1,i=0;
	for (i=0;i<4;i++)
	{
		if (wcscmp(controllername[i],controller_name)==0)
		{
			int result=m_cmbCardType.SelectString(-1,controller_name);
			if (result!=CB_ERR)
			{
				type=i;
				break;
			}
		}
	}
	switch(type)
	{
	case 0://BX-Y0
		{
			if (w>1024||h>512||w*h>98304)
			{
				MessageBox(_T("BX-Y0 的宽高超出范围！"));
				return;
			} 
			break;
		}
	case 1://BX-Y2
		{
			if (w>2048||h>2048||w*h>614400)
			{
				MessageBox(_T("BX-Y2 的宽高超出范围！"));
				return;
			} 
			break;
		}
	case 2://BX-Y2L
		{
			if (w>2048||h>2048||w*h>196608)
			{
				MessageBox(_T("BX-Y2L 的宽高超出范围！"));
				return;
			} 
			break;
		}
	case 3://BX-Y3
		{
			if (w>2048||h>2048||w*h>1310720)
			{
				MessageBox(_T("BX-Y3 的宽高超出范围！"));
				return;
			} 
			break;
		}
	default:
		break;
	}
	_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
	if (card_mode==0)
	{
		int err=0;
		unsigned short port=80;
		 int screenrotation=0;
		err=set_screen_size(card_ip,port,user_name,user_pwd,w,h,screenrotation);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}	}
	else
	{
		int err=0;
		unsigned short port=Get_Port_Pid(card_PID);
		 int screenrotation=0;
		err=set_screen_size(card_ip,port,user_name,user_pwd,w,h,screenrotation);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}
	int nSel=m_cmbCardType.SetCurSel(type);
	if(nSel==CB_ERR)
		m_cmbCardType.SetCurSel(-1);
	
}


BOOL CScreenProperty::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	
	int w;
	int h;

	int err=0;
	if (card_mode==0)
	{
		unsigned short port=80;
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		unsigned short screen_type;
		BYTE cards[1024*32]={0}; 
		err=get_screen_parameters(card_ip,port,user_name,user_pwd,cards);
		 memset(&info,0,sizeof(controllerInfo));
		 memcpy(&info,cards,sizeof(controllerInfo));
		//err=get_screeninfo(card_ip,port,user_name,user_pwd,&w,&h,controller_name,&screen_type);
	} 
	else
	{
		unsigned short port=Get_Port_Pid(card_PID);
		_TEXT_CHAR* user_name=_TEXT_T("guest"),*user_pwd=_TEXT_T("guest");
		BYTE cards[1024*32]={0}; 
		err=get_screen_parameters(card_ip,port,user_name,user_pwd,cards);
		 memset(&info,0,sizeof(controllerInfo));
		 memcpy(&info,cards,sizeof(controllerInfo));
		/*unsigned short screen_type=0;
		err=get_screeninfo(card_ip,port,user_name,user_pwd,&w,&h,controller_name,&screen_type);*/
	}	
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
	}
	else
	{
		CString str;
		str.Format(_T("%d"),info.screen_w);
		GetDlgItem(IDC_EDIT12)->SetWindowText(str);

		str.Format(_T("%d"),info.screen_h);
		GetDlgItem(IDC_EDIT9)->SetWindowText(str);

		switch(info.screen_type)
		{
		case 8280:m_cmbCardType.SetCurSel(0);
			break;
		case 8536:m_cmbCardType.SetCurSel(1);
			break;
		case 8792:m_cmbCardType.SetCurSel(2);
			break;
		case 9304:m_cmbCardType.SetCurSel(3);
			break;
		case 9048:m_cmbCardType.SetCurSel(4);
			break;
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CScreenProperty::OnCbnSelchangeCombo4()
{
	// TODO: 在此添加控件通知处理程序代码
}
