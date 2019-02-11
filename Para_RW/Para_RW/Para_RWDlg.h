
// Para_RWDlg.h : 標頭檔
//

#pragma once


// CPara_RWDlg 對話方塊
class CPara_RWDlg : public CDialogEx
{
// 建構
public:
	CPara_RWDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_PARA_RW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
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
