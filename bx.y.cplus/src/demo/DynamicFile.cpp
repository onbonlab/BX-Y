// DynamicFile.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "DynamicFile.h"
#include "afxdialogex.h"

// CDynamicFile 对话框

IMPLEMENT_DYNAMIC(CDynamicFile, CDialogEx)

CDynamicFile::CDynamicFile(DynamicArea* pArea,CWnd* pParent /*=NULL*/)
	: CDialogEx(CDynamicFile::IDD, pParent)
	//,m_Program(0)
	, m_PlayRelation(0)
	, m_RunTime(0)
	, m_PageType(0)
	, m_X(0)
	, m_Y(0)
	, m_W(128)
	, m_H(96)
	, m_RelProgram(0)
{
	m_pArea=pArea;
}

CDynamicFile::~CDynamicFile()
{
}

void CDynamicFile::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO8, m_cmbAreaId);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
	DDX_Text(pDX,IDC_AREA_X,m_X);
	DDX_Text(pDX,IDC_AREA_Y,m_Y);
	DDX_Text(pDX,IDC_AREA_W,m_W);
	DDX_Text(pDX,IDC_AREA_H,m_H);
	DDX_Control(pDX, IDC_COMBO10, m_cmbRunMode);
	DDX_Control(pDX, IDC_COMBO1, m_cmbDisplayEffect);
	DDX_Control(pDX, IDC_LIST_UNIT, m_PageList);
}


BEGIN_MESSAGE_MAP(CDynamicFile, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDynamicFile::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDynamicFile::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_UNIT_ADD, &CDynamicFile::OnBnClickedUnitAdd)
	ON_LBN_SELCHANGE(IDC_LIST_UNIT, &CDynamicFile::OnLbnSelchangeListUnit)
	ON_CBN_KILLFOCUS(IDC_COMBO1, &CDynamicFile::OnCbnKillfocusCombo1)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CDynamicFile::OnEnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT31, &CDynamicFile::OnEnKillfocusEdit31)
	ON_BN_CLICKED(IDC_BUTTON3, &CDynamicFile::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDynamicFile 消息处理程序


BOOL CDynamicFile::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	for (int i=0;i<32;i++)
	{
		CString str;
		str.Format(_T("%d"),i);
		m_cmbAreaId.AddString(str);
	}
	m_cmbAreaId.SetCurSel(m_pArea->m_dynamic_id);
	m_ctrlSlider.SetRange(0,255);
	m_ctrlSlider.SetPos(m_pArea->m_transparency);
	
	CString str;
	str.Format(_T("%d"),m_pArea->m_x);
	GetDlgItem(IDC_AREA_X)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_y);
	GetDlgItem(IDC_AREA_Y)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_w);
	GetDlgItem(IDC_AREA_W)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_h);
	GetDlgItem(IDC_AREA_H)->SetWindowText(str);

	m_cmbRunMode.AddString(_T("全局播放动态区"));
	m_cmbRunMode.AddString(_T("全局动态区节目"));
	m_cmbRunMode.AddString(_T("全局动态区节目"));
	m_cmbRunMode.AddString(_T("绑定播放动态区，关联节目开始播放时播放动态区，直到关联节目播放完毕"));
	m_cmbRunMode.AddString(_T("绑定播放动态区，关联节目开始播放时播放动态区，显示完一遍后本轮不再显示"));
	m_cmbRunMode.AddString(_T("绑定播放动态区，关联节目开始播放时播放动态区，显示完一遍后静止显示该动态区的最后一个unit"));
	m_cmbRunMode.AddString(_T("绑定播放动态区，关联节目播放完后播放动态区"));
	m_cmbRunMode.SetCurSel(0);

	m_cmbDisplayEffect.AddString(_T("快速打出"));
	m_cmbDisplayEffect.AddString(_T("平滑向上推入"));
	m_cmbDisplayEffect.AddString(_T("平滑向下推入"));
	m_cmbDisplayEffect.AddString(_T("平滑向左推入"));
	m_cmbDisplayEffect.AddString(_T("平滑向右推入"));
	m_cmbDisplayEffect.AddString(_T("平滑向上移入"));
	m_cmbDisplayEffect.AddString(_T("平滑向下移入"));
	m_cmbDisplayEffect.AddString(_T("平滑向左移入"));
	m_cmbDisplayEffect.AddString(_T("平滑向右移入"));
	m_cmbDisplayEffect.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDynamicFile::OnBnClickedOk()
{
	//UpdateData(TRUE);
	m_pArea->m_dynamic_id=m_cmbAreaId.GetCurSel();
	CString str;
	GetDlgItem(IDC_AREA_X)->GetWindowText(str);
	m_pArea->m_x=_tstoi(str);

	GetDlgItem(IDC_AREA_Y)->GetWindowText(str);
	m_pArea->m_y=_tstoi(str);

	GetDlgItem(IDC_AREA_W)->GetWindowText(str);
	m_pArea->m_w=_tstoi(str);

	GetDlgItem(IDC_AREA_H)->GetWindowText(str);
	m_pArea->m_h=_tstoi(str);

	//CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	_tcscpy_s(m_pArea->m_relative_program,_TEXT_T("-1"));
	m_pArea->m_run_mode=0;
	_tcscpy_s(m_pArea->m_update_frequency,_TEXT_T(" "));
	m_pArea->m_transparency=m_ctrlSlider.GetPos();

	for (int i=0;i<m_vecUnit.size();i++)
	{
		m_pArea->m_DynamicAreaFile[i]=m_vecUnit[i];
	}
	m_pArea->m_PicCount=m_vecUnit.size();
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CDynamicFile::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CDynamicFile::OnBnClickedUnitAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE,_T("bmp"),NULL,OFN_HIDEREADONLY|OFN_ALLOWMULTISELECT,_T("(*.bmp;*.jpg;*.png;*.gif)|*.bmp;*.jpg;*.png;*.gif||"));
	if(dlg.DoModal() == IDOK)
	{
		DynamicAreaFile unit;
		
		_tcscpy_s(unit.file_path,dlg.GetPathName());
		unit.dynamic_type=0;
		unit.display_effects=0;
		unit.display_speed=16;
		unit.stay_time=5;
		unit.gif_flag=0;
		//_tcscpy_s(unit.bg_color, sizeof(unit.bg_color)/sizeof(unit.bg_color[0]), _TEXT_T("0xFF000000")); 
		_tcscpy_s(unit.bg_color,_TEXT_T("0xFF000000"));
		unit.font_size=12;
		_tcscpy_s(unit.font_name,_TEXT_T("SumSun"));
		_tcscpy_s(unit.font_color,_TEXT_T("0xFFFF0000"));
		_tcscpy_s(unit.font_attributes,_TEXT_T("normal"));
		_tcscpy_s(unit.align_h,_TEXT_T("0"));
		_tcscpy_s(unit.align_v,_TEXT_T("0"));
		unit.volumn=0;
		unit.scale_mode=0;
		unit.rolation_mode=0;
		m_vecUnit.push_back(unit);
		int item=m_PageList.AddString(dlg.GetPathName());
		m_PageList.SetCurSel(item);
		OnLbnSelchangeListUnit();
	}
}


void CDynamicFile::OnLbnSelchangeListUnit()
{
	// TODO: 在此添加控件通知处理程序代码
	int index=m_PageList.GetCurSel();

	switch(m_vecUnit[index].display_effects)
	{
	case 0:m_vecUnit[index].display_effects=0;
		break;
	case 50:m_vecUnit[index].display_effects=1;
		break;
	case 51:m_vecUnit[index].display_effects=2;
		break;
	case 52:m_vecUnit[index].display_effects=3;
		break;
	case 53:m_vecUnit[index].display_effects=4;
		break;
	case 54:m_vecUnit[index].display_effects=5;
		break;
	case 55:m_vecUnit[index].display_effects=6;
		break;
	case 56:m_vecUnit[index].display_effects=7;
		break;
	case 57:m_vecUnit[index].display_effects=8;
		break;
	default:m_vecUnit[index].display_effects=0;
		break;
	}

	m_cmbDisplayEffect.SetCurSel(m_vecUnit[index].display_effects);
	CString str;
	str.Format(_T("%d"),m_vecUnit[index].display_speed);
	GetDlgItem(IDC_EDIT1)->SetWindowText(str);
	str.Format(_T("%d"),m_vecUnit[index].stay_time);
	GetDlgItem(IDC_EDIT31)->SetWindowText(str);
}


void CDynamicFile::OnCbnKillfocusCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	int index=m_PageList.GetCurSel();
	if (index>=0)
	{
		switch(m_cmbDisplayEffect.GetCurSel())
		{
		case 0:m_vecUnit[index].display_effects=m_cmbDisplayEffect.GetCurSel();
			break;
		case 1:m_vecUnit[index].display_effects=50;
			break;
		case 2:m_vecUnit[index].display_effects=51;
			break;
		case 3:m_vecUnit[index].display_effects=52;
			break;
		case 4:m_vecUnit[index].display_effects=53;
			break;
		case 5:m_vecUnit[index].display_effects=54;
			break;
		case 6:m_vecUnit[index].display_effects=55;
			break;
		case 7:m_vecUnit[index].display_effects=56;
			break;
		case 8:m_vecUnit[index].display_effects=57;
			break;
		default:m_vecUnit[index].display_effects=0;
			break;
		}
	}
}


void CDynamicFile::OnEnKillfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码
	int index=m_PageList.GetCurSel();
	if (index>=0)
	{
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		m_vecUnit[index].display_speed=_tstoi(str);
	}
}


void CDynamicFile::OnEnKillfocusEdit31()
{
	// TODO: 在此添加控件通知处理程序代码
	int index=m_PageList.GetCurSel();
	if (index>=0)
	{
		CString str;
		GetDlgItem(IDC_EDIT31)->GetWindowText(str);
		m_vecUnit[index].stay_time=_tstoi(str);
	}
}


void CDynamicFile::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE,_T("txt"),NULL,OFN_HIDEREADONLY,_T("(*.txt)|*.txt||"));
	if(dlg.DoModal() == IDOK)
	{
		DynamicAreaFile unit;
		
		_tcscpy_s(unit.file_path,dlg.GetPathName());
		unit.dynamic_type=1;
		unit.display_effects=0;
		unit.display_speed=16;
		unit.stay_time=5;
		unit.gif_flag=0;
		//_tcscpy_s(unit.bg_color, sizeof(unit.bg_color)/sizeof(unit.bg_color[0]), _TEXT_T("0xFF000000")); 
		_tcscpy_s(unit.bg_color,_TEXT_T("0xFF000000"));
		unit.font_size=12;
		_tcscpy_s(unit.font_name,_TEXT_T("SumSun"));
		_tcscpy_s(unit.font_color,_TEXT_T("0xFFFF0000"));
		_tcscpy_s(unit.font_attributes,_TEXT_T("normal"));
		_tcscpy_s(unit.align_h,_TEXT_T("0"));
		_tcscpy_s(unit.align_v,_TEXT_T("0"));
		unit.volumn=0;
		unit.scale_mode=0;
		unit.rolation_mode=0;
		m_vecUnit.push_back(unit);
		int item=m_PageList.AddString(dlg.GetPathName());
		m_PageList.SetCurSel(item);
		OnLbnSelchangeListUnit();
	}
}
