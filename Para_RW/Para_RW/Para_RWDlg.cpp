
// Para_RWDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "Para_RW.h"
#include "Para_RWDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "EZSocketNc.h"
#include "EZSocketNcDef.h"
#include "EZSocketNcErr.h"
#include "EZSocketNcStr.h"

// CPara_RWDlg 對話方塊




CPara_RWDlg::CPara_RWDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPara_RWDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPara_RWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_mess, m_message);
	DDX_Control(pDX, IDC_err1, m_err1);
	DDX_Control(pDX, IDC_err2, m_err2);
	//  DDX_Control(pDX, IDC_err3, m_wee3);
	DDX_Control(pDX, IDC_err3, m_err3);
}

BEGIN_MESSAGE_MAP(CPara_RWDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CPara_RWDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPara_RWDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CPara_RWDlg 訊息處理常式

BOOL CPara_RWDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CPara_RWDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CPara_RWDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPara_RWDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	HRESULT hr;
	
	DWORD dwIPaddress;

	IEZNcCommunication3 *m_pezComm=NULL;
	IEZNcParameter3 *m_pezPara=NULL;
	long lRet;
	long wdlRet;
	
	LPOLESTR *lppwszData;
	lppwszData = new LPOLESTR[3];
	lppwszData[0] =L"";
	lppwszData[1] =L"";
	lppwszData[2] =L"";

	long lret = CoInitialize(NULL); 
		
	CLSID clsid;
	CLSIDFromProgID(L"EZSocketNc.EZNcCommunication",&clsid); 

	hr = CoCreateInstance(clsid,
						  NULL,
						  CLSCTX_INPROC_SERVER,
						  IID_IEZNcCommunication3,
						  (void**)&m_pezComm );
	if(hr == S_OK){
		hr = m_pezComm->QueryInterface(IID_IEZNcParameter,(void**)&m_pezPara);
		
		if(hr == S_OK){

			hr = m_pezComm->SetTCPIPProtocol(L"192.168.11.19" ,683,&lRet);

			if(hr == S_OK){

				hr = m_pezComm->Open2(EZNC_SYS_MELDAS700M, 1, 30, &lRet);

				if(hr == S_OK){

					hr = m_pezComm->SetHead(1 ,&lRet);//system setting

					if(hr == S_OK){
						
						//Read
						m_pezPara->GetParameterData3(NULL, 4101, 1, 0, &lppwszData[0], &wdlRet);
						m_pezPara->GetParameterData3(NULL, 4102, 1, 0, &lppwszData[1], &wdlRet);
						m_pezPara->GetParameterData3(NULL, 4103, 1, 0, &lppwszData[2], &wdlRet);
						if(wdlRet == S_OK){

							m_err1.SetWindowTextW(lppwszData[0]);
							m_err2.SetWindowTextW(lppwszData[1]);
							m_err3.SetWindowTextW(lppwszData[2]);						

						}else{
							m_message.SetWindowTextW(L"Read Error");
						}
						//Write
						
						LPCOLESTR lpcoszData;
						lpcoszData = L"-1";
						m_pezPara->SetParameterData3(NULL, 4104, 1, 0, &lpcoszData, &wdlRet);

						if(wdlRet != S_OK){
							m_message.SetWindowTextW(L"Write Error");
						}
					}else{
						m_message.SetWindowTextW(L"(SetHead):System No Error");
					}
				}else{
						 wchar_t _point[20];
						 swprintf(_point, L"%X", lRet);
	   					 m_message.SetWindowTextW(_point);

				}

			}else{
				m_message.SetWindowTextW(L"SetTCPIPProtocol Error");
			}
	}else{
		m_message.SetWindowTextW(L"QueryInterface error");
	}
	}else{
	m_message.SetWindowTextW(L"CoCreateInstance error");
	}


	long dwlRet;

	m_pezComm->Close(&dwlRet);

	if(dwlRet == S_OK){
		m_pezComm->Release();
		m_pezPara->Release();
		
		m_pezComm = NULL;
		m_pezPara=NULL;
	}

	CoUninitialize();




	//CDialogEx::OnOK();
}


void CPara_RWDlg::OnBnClickedCancel()
{
	// TODO: 在此加入控制項告知處理常式程式碼

	CDialogEx::OnCancel();
}
