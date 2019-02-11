
// Para_RWDlg.cpp : ��@��
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

// CPara_RWDlg ��ܤ��




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


// CPara_RWDlg �T���B�z�`��

BOOL CPara_RWDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �]�w����ܤ�����ϥܡC�����ε{�����D�������O��ܤ���ɡA
	// �ج[�|�۰ʱq�Ʀ��@�~
	SetIcon(m_hIcon, TRUE);			// �]�w�j�ϥ�
	SetIcon(m_hIcon, FALSE);		// �]�w�p�ϥ�

	// TODO: �b���[�J�B�~����l�]�w

	return TRUE;  // �Ǧ^ TRUE�A���D�z�ﱱ��]�w�J�I
}

// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C

void CPara_RWDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ø�s���˸m���e

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N�ϥܸm����Τ�ݯx��
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �yø�ϥ�
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ��ϥΪ̩즲�̤p�Ƶ����ɡA
// �t�ΩI�s�o�ӥ\����o�����ܡC
HCURSOR CPara_RWDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPara_RWDlg::OnBnClickedOk()
{
	// TODO: �b���[�J����i���B�z�`���{���X
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
	// TODO: �b���[�J����i���B�z�`���{���X

	CDialogEx::OnCancel();
}
