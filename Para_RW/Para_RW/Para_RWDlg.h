
// Para_RWDlg.h : ���Y��
//

#pragma once


// CPara_RWDlg ��ܤ��
class CPara_RWDlg : public CDialogEx
{
// �غc
public:
	CPara_RWDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
	enum { IDD = IDD_PARA_RW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit m_message;
	afx_msg void OnBnClickedCancel();
	CEdit m_err1;
	CEdit m_err2;
//	CEdit m_wee3;
	CEdit m_err3;
};
