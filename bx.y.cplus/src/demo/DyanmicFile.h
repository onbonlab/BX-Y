#pragma once


// CDyanmicFile 对话框

class CDyanmicFile : public CDialogEx
{
	DECLARE_DYNAMIC(CDyanmicFile)

public:
	CDyanmicFile(char* ip,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDyanmicFile();

// 对话框数据
	enum { IDD = IDD_DYNAMICFILEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	int card_mode;
	char card_ip[20];
	unsigned char card_barcode[17];
public:
	virtual BOOL OnInitDialog();
	CComboBox m_cmbRunMode;
	CComboBox m_cmbDisplayEffect;
	CComboBox m_cmbAreaId;
	CSliderCtrl m_ctrlSlider;
	CListBox m_PageList;
	int m_PlayRelation;
	int m_RunTime;
	int m_PageType;
	short m_X;
	short m_Y;
	short m_W;
	short m_H;
	int m_RelProgram;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	vector<DynamicAreaFile> m_vecDynamicAreaFile;
	afx_msg void OnLbnSelchangeList1();
};
