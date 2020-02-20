// ImageAreaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "ImageAreaDlg.h"
#include "afxdialogex.h"


TCHAR* PIC_ShowMode[]=
{
	_T("快速打出		"),
	_T("随机显示		"),
	_T("静止显示		"),
	_T("向上移动		"),
	_T("向下移动		"),
	_T("向左移动		"),
	_T("向右移动		"),
	_T("从上移入		"),
	_T("从下移入		"),
	_T("从左移入		"),
	_T("从右移入		"),
	_T("向上镭射		"),
	_T("向下镭射		"),
	_T("向左镭射		"),
	_T("向右镭射		"),
	_T("向上拉幕		"),
	_T("向下拉幕		"),
	_T("向左拉幕		"),
	_T("向右拉幕		"),
	_T("左上角覆盖（直）"),
	_T("右上角覆盖（直）"),
	_T("左下角覆盖（直）"),
	_T("右下角覆盖（直）"),
	_T("四周向中间(矩形)"),
	_T("四周向中间(十字)"),
	_T("中间向四周(十字)"),
	_T("左右交叉拉幕	"),
	_T("上下交叉拉幕	"),
	_T("垂直百叶		"),
	_T("水平百叶		"),
	_T("上下闭合		"),
	_T("上下对开		"),
	_T("左右对开		"),
	_T("左右闭合		"),
	_T("中心放大		"),
	_T("马赛克		"),
	_T("左右对开		"),
	_T("箱盒擦除		"),
	_T("中间向四周(矩形)"),
	_T("中心缩小		"),
	_T("向左拉伸		"),
	_T("向右拉伸		"),
	_T("向上连移		"),
	_T("向下连移		"),
	_T("向左连移		"),
	_T("向右连移		"),
	_T("向下覆盖		"),
	_T("向上覆盖		"),
	_T("向右覆盖		"),
	_T("向左覆盖		"),
	_T("交叉百叶		"),
	_T("向左卷轴		"),
	_T("卷轴闭合		"),
	_T("卷轴展开		"),
	_T("旋转拉幕		"),
	_T("旋转放大		"),
	_T("旋转缩小		"),
	_T("翻转		     "),
	_T("左翻页		"),
	_T("右翻页		"),
	_T("上翻页		"),
	_T("下翻页		"),
	_T("右开门		"),
	_T("右关门		"),
	_T("快门		    "),
	_T("中心退出		"),
	_T("中心进入		"),
	_T("对角散开		"),
	_T("开门		    "),
	_T("波浪		    "),
	_T("中心淡出		"),
	_T("边缘淡出		"),
	_T("雨滴  		"),
	_T("碎屏		    "),
	_T("箱体旋转		"),
	_T("百叶翻转		"),
	_T("4点扩散		"),
	_T("分裂		    "),
	_T("叠层		    "),
	_T("马赛克	    "),
	_T("球体下落放大	"),
	_T("方体旋转放大	"),


};
// CImageAreaDlg 对话框

IMPLEMENT_DYNAMIC(CImageAreaDlg, CDialogEx)

CImageAreaDlg::CImageAreaDlg(PicArea* a,CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageAreaDlg::IDD, pParent)
{
	m_pArea=a;
}

CImageAreaDlg::~CImageAreaDlg()
{
}

void CImageAreaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
	DDX_Control(pDX, IDC_COMBO1, m_cmbDisplayEffect);
	DDX_Control(pDX, IDC_LIST_UNIT, m_ctrlUnitList);
}


BEGIN_MESSAGE_MAP(CImageAreaDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CImageAreaDlg::OnBnClickedOk)
	ON_LBN_SELCHANGE(IDC_LIST_UNIT, &CImageAreaDlg::OnLbnSelchangeListUnit)
	ON_BN_CLICKED(IDC_UNIT_ADD, &CImageAreaDlg::OnBnClickedUnitAdd)
	ON_BN_CLICKED(IDC_UNIT_REMOVE, &CImageAreaDlg::OnBnClickedUnitRemove)
	ON_BN_CLICKED(IDC_BUTTON3, &CImageAreaDlg::OnBnClickedButton3)
	ON_CBN_KILLFOCUS(IDC_COMBO1, &CImageAreaDlg::OnCbnKillfocusCombo1)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CImageAreaDlg::OnEnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT31, &CImageAreaDlg::OnEnKillfocusEdit31)
	ON_BN_CLICKED(IDCANCEL, &CImageAreaDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CImageAreaDlg 消息处理程序


void CImageAreaDlg::OnBnClickedOk()
{
	m_pArea->m_transparency=255-m_ctrlSlider.GetPos();
	CString str;
	GetDlgItem(IDC_AREA_X)->GetWindowText(str);
	m_pArea->m_x=_tstoi(str);

	GetDlgItem(IDC_AREA_Y)->GetWindowText(str);
	m_pArea->m_y=_tstoi(str);

	GetDlgItem(IDC_AREA_W)->GetWindowText(str);
	m_pArea->m_w=_tstoi(str);

	GetDlgItem(IDC_AREA_H)->GetWindowText(str);
	m_pArea->m_h=_tstoi(str);

	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	m_pArea->m_bBgTransparent=btn->GetCheck();

	for (int i=0;i<m_vecUnit.size();i++)
	{
		m_pArea->m_Piclist[i]=m_vecUnit[i];
	}
	m_pArea->m_PicCount=m_vecUnit.size();
	CDialogEx::OnOK();
}


BOOL CImageAreaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	for (int i=0;i<48;i++)
	{
		m_cmbDisplayEffect.AddString(PIC_ShowMode[i]);
	}

	m_ctrlSlider.SetRange(0,255);
	m_ctrlSlider.SetPos(255-m_pArea->m_transparency);

	CString str;
	str.Format(_T("%d"),m_pArea->m_x);
	GetDlgItem(IDC_AREA_X)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_y);
	GetDlgItem(IDC_AREA_Y)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_w);
	GetDlgItem(IDC_AREA_W)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_h);
	GetDlgItem(IDC_AREA_H)->SetWindowText(str);
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	btn->SetCheck(m_pArea->m_bBgTransparent);

	for (int i=0;i<m_pArea->m_PicCount;i++)
	{
		m_vecUnit.push_back(m_pArea->m_Piclist[i]);
		m_ctrlUnitList.AddString(m_pArea->m_Piclist[i].szFile);
	}
	if (m_vecUnit.size()>0)
	{
		m_ctrlUnitList.SetCurSel(0);
		OnLbnSelchangeListUnit();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CImageAreaDlg::OnLbnSelchangeListUnit()
{
	int index=m_ctrlUnitList.GetCurSel();
	m_cmbDisplayEffect.SetCurSel(m_vecUnit[index].display_effects);
	CString str;
	str.Format(_T("%d"),m_vecUnit[index].display_speed);
	GetDlgItem(IDC_EDIT1)->SetWindowText(str);
	str.Format(_T("%d"),m_vecUnit[index].stay_time);
	GetDlgItem(IDC_EDIT31)->SetWindowText(str);
}


void CImageAreaDlg::OnBnClickedUnitAdd()
{
	CFileDialog dlg(TRUE,_T("bmp"),NULL,OFN_HIDEREADONLY,_T("(*.bmp;*.jpg;*.png;*.gif)|*.bmp;*.jpg;*.png;*.gif||"));
	if(dlg.DoModal() == IDOK)
	{
		PicUnit unit;
		unit.bPic=true;
		_tcscpy_s(unit.szFile,dlg.GetPathName());
		unit.display_effects=1;
		unit.display_speed=16;
		unit.stay_time=5;
		m_vecUnit.push_back(unit);
		int item=m_ctrlUnitList.AddString(dlg.GetPathName());
		m_ctrlUnitList.SetCurSel(item);
		OnLbnSelchangeListUnit();
	}
}


void CImageAreaDlg::OnBnClickedUnitRemove()
{
	int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		m_vecUnit.erase(m_vecUnit.begin()+index);
		m_ctrlUnitList.DeleteString(index);
	}
}


void CImageAreaDlg::OnBnClickedButton3()
{
	CFileDialog dlg(TRUE,_T("rtf"),NULL,OFN_HIDEREADONLY,_T("(*.rtf;*.doc)|*.rtf;*.doc||"));
	if(dlg.DoModal() == IDOK)
	{
		PicUnit unit;
		unit.bPic=false;
		_tcscpy_s(unit.szFile,dlg.GetPathName());
		unit.display_effects=1;
		unit.display_speed=16;
		unit.stay_time=5;
		m_vecUnit.push_back(unit);
		int item=m_ctrlUnitList.AddString(dlg.GetPathName());
		m_ctrlUnitList.SetCurSel(item);
		OnLbnSelchangeListUnit();
	}
}



void CImageAreaDlg::OnCbnKillfocusCombo1()
{
	int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		m_vecUnit[index].display_effects=m_cmbDisplayEffect.GetCurSel();
	}
}


void CImageAreaDlg::OnEnKillfocusEdit1()
{
	int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		m_vecUnit[index].display_speed=_tstoi(str);
	}
}


void CImageAreaDlg::OnEnKillfocusEdit31()
{
	int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		CString str;
		GetDlgItem(IDC_EDIT31)->GetWindowText(str);
		m_vecUnit[index].stay_time=_tstoi(str);
	}
}

void CImageAreaDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
