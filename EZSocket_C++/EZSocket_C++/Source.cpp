#include "stdafx.h"
#include "C:\Program Files (x86)\EZSocket\EZSocketNc\Include\VC\EZSocketNc.h"
#include "C:\Program Files (x86)\EZSocket\EZSocketNc\Include\VC\EZSocketNcDef.h"
#include "C:\Program Files (x86)\EZSocket\EZSocketNc\Include\VC\EZSocketNcErr.h"
#include "C:\Program Files (x86)\EZSocket\EZSocketNc\Include\VC\EZSocketNcStr.h"
#include <fstream>
#include <iostream>
using namespace std;

//extern "C" __declspec(dllexport) int __stdcall GetPLCMemory(int iPLCAddr)
int GetPLCMemory(int iPLCAddr){
	int iRet = -1;
	long lRet;
	DWORD dwLength = 1;
	LPCOLESTR lppcwszDevice;
	DWORD lpdwLength;
	CLSID clsid;
	LPCOLESTR lpcwszIPAddress = L"192.168.11.220";
	LONG lPort = 683;
	LONG plRet;
	LONG lSystemType = EZNC_SYS_MELDAS800M;
	LONG lMachine = 1;
	LONG lTimeOut = 100;  // (unit: 100 ms)
	DWORD* lppdwValue;
	DWORD lpdwDataType;
	DWORD lpdwValue;

	//if (iPLCAddr == 10620) lppcwszDevice = L"R10620";
	lppcwszDevice = L"M1381";

	lpdwDataType = EZNC_PLC_BIT;
	lRet = CoInitialize(NULL);
	IEZNcCommunication3* m_pezComm;
	IEZNcDevice* m_pezDevice;
	HRESULT hr = S_OK;
	hr = CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER, IID_IEZNcCommunication3, (void**)&m_pezComm);
	if (S_OK != hr) {
		cout << "no" << endl;
	}
	CLSIDFromProgID(L"EZSocketNc.EZNcCommunication", &clsid);
	lRet = CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER, IID_IEZNcCommunication3, (void**)&m_pezComm);
	lRet = m_pezComm->QueryInterface(IID_IEZNcDevice, (void**)&m_pezDevice);
	lRet = m_pezComm->SetTCPIPProtocol(lpcwszIPAddress, lPort, &plRet);
	lRet = m_pezComm->Open2(lSystemType, lMachine, lTimeOut, &plRet);
	if (lRet == 0){
		lRet = m_pezComm->SetHead(1, &plRet);
		lRet = m_pezDevice->SetDevice(dwLength, &lppcwszDevice, &lpdwDataType, &lpdwValue, &plRet);
		lRet = m_pezDevice->ReadDevice(&lpdwLength, &lppdwValue, &plRet);

		//lppdwValue
		/*ofstream myfile;
		myfile.open("example.txt");
		myfile << lppdwValue << "\n";
		myfile.close();*/
		//

		lRet = m_pezDevice->DeleteDeviceAll(&plRet);
		if (*lppdwValue == 0) iRet = 0;
		if (*lppdwValue == 1) iRet = 1;
		lpdwLength = NULL;
		CoTaskMemFree(lppdwValue);
		lppdwValue = NULL;
		m_pezComm->Close(&lRet);

	}
	m_pezDevice->Release();
	m_pezDevice = NULL;
	m_pezComm->Release();
	m_pezComm = NULL;
	CoUninitialize();

	return iRet;
}
int main() {
	GetPLCMemory(10620);
	return 0;
}