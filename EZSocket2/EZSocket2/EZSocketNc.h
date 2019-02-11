/******************************************************************************/
//
//  <FILENAME>      EZSocketNc.h
//                  Meldas用湧折箕荷
//
// Copyright (C) 2000-2015 MITSUBISHI Electric Corporation All Rights Reserved
/******************************************************************************/

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __EZSocketNc_h__
#define __EZSocketNc_h__

#include "EZSocketNc_i.c"

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IEZNcCommunication_FWD_DEFINED__
#define __IEZNcCommunication_FWD_DEFINED__
typedef interface IEZNcCommunication IEZNcCommunication;
#endif 	/* __IEZNcCommunication_FWD_DEFINED__ */


#ifndef __IEZNcSystem_FWD_DEFINED__
#define __IEZNcSystem_FWD_DEFINED__
typedef interface IEZNcSystem IEZNcSystem;
#endif 	/* __IEZNcSystem_FWD_DEFINED__ */


#ifndef __IEZNcPosition_FWD_DEFINED__
#define __IEZNcPosition_FWD_DEFINED__
typedef interface IEZNcPosition IEZNcPosition;
#endif 	/* __IEZNcPosition_FWD_DEFINED__ */


#ifndef __IEZNcProgram_FWD_DEFINED__
#define __IEZNcProgram_FWD_DEFINED__
typedef interface IEZNcProgram IEZNcProgram;
#endif 	/* __IEZNcProgram_FWD_DEFINED__ */


#ifndef __IEZNcTime_FWD_DEFINED__
#define __IEZNcTime_FWD_DEFINED__
typedef interface IEZNcTime IEZNcTime;
#endif 	/* __IEZNcTime_FWD_DEFINED__ */


#ifndef __IEZNcRunStatus_FWD_DEFINED__
#define __IEZNcRunStatus_FWD_DEFINED__
typedef interface IEZNcRunStatus IEZNcRunStatus;
#endif 	/* __IEZNcRunStatus_FWD_DEFINED__ */


#ifndef __IEZNcFile_FWD_DEFINED__
#define __IEZNcFile_FWD_DEFINED__
typedef interface IEZNcFile IEZNcFile;
#endif 	/* __IEZNcFile_FWD_DEFINED__ */


#ifndef __IEZNcOperation_FWD_DEFINED__
#define __IEZNcOperation_FWD_DEFINED__
typedef interface IEZNcOperation IEZNcOperation;
#endif 	/* __IEZNcOperation_FWD_DEFINED__ */


#ifndef __IEZNcCommand_FWD_DEFINED__
#define __IEZNcCommand_FWD_DEFINED__
typedef interface IEZNcCommand IEZNcCommand;
#endif 	/* __IEZNcCommand_FWD_DEFINED__ */


#ifndef __IEZNcCommonVariable_FWD_DEFINED__
#define __IEZNcCommonVariable_FWD_DEFINED__
typedef interface IEZNcCommonVariable IEZNcCommonVariable;
#endif 	/* __IEZNcCommonVariable_FWD_DEFINED__ */


#ifndef __IEZNcLocalVariable_FWD_DEFINED__
#define __IEZNcLocalVariable_FWD_DEFINED__
typedef interface IEZNcLocalVariable IEZNcLocalVariable;
#endif 	/* __IEZNcLocalVariable_FWD_DEFINED__ */


#ifndef __IEZNcAxisMonitor_FWD_DEFINED__
#define __IEZNcAxisMonitor_FWD_DEFINED__
typedef interface IEZNcAxisMonitor IEZNcAxisMonitor;
#endif 	/* __IEZNcAxisMonitor_FWD_DEFINED__ */


#ifndef __IEZNcTool_FWD_DEFINED__
#define __IEZNcTool_FWD_DEFINED__
typedef interface IEZNcTool IEZNcTool;
#endif 	/* __IEZNcTool_FWD_DEFINED__ */


#ifndef __IEZNcParameter_FWD_DEFINED__
#define __IEZNcParameter_FWD_DEFINED__
typedef interface IEZNcParameter IEZNcParameter;
#endif 	/* __IEZNcParameter_FWD_DEFINED__ */


#ifndef __IEZNcGeneric_FWD_DEFINED__
#define __IEZNcGeneric_FWD_DEFINED__
typedef interface IEZNcGeneric IEZNcGeneric;
#endif 	/* __IEZNcGeneric_FWD_DEFINED__ */


#ifndef __IEZNcCommonVariable2_FWD_DEFINED__
#define __IEZNcCommonVariable2_FWD_DEFINED__
typedef interface IEZNcCommonVariable2 IEZNcCommonVariable2;
#endif 	/* __IEZNcCommonVariable2_FWD_DEFINED__ */


#ifndef __IEZNcLocalVariable2_FWD_DEFINED__
#define __IEZNcLocalVariable2_FWD_DEFINED__
typedef interface IEZNcLocalVariable2 IEZNcLocalVariable2;
#endif 	/* __IEZNcLocalVariable2_FWD_DEFINED__ */


#ifndef __IEZNcTool2_FWD_DEFINED__
#define __IEZNcTool2_FWD_DEFINED__
typedef interface IEZNcTool2 IEZNcTool2;
#endif 	/* __IEZNcTool2_FWD_DEFINED__ */


#ifndef __IEZNcParameter2_FWD_DEFINED__
#define __IEZNcParameter2_FWD_DEFINED__
typedef interface IEZNcParameter2 IEZNcParameter2;
#endif 	/* __IEZNcParameter2_FWD_DEFINED__ */


#ifndef __IEZNcATC_FWD_DEFINED__
#define __IEZNcATC_FWD_DEFINED__
typedef interface IEZNcATC IEZNcATC;
#endif 	/* __IEZNcATC_FWD_DEFINED__ */


#ifndef __IEZNcDevice_FWD_DEFINED__
#define __IEZNcDevice_FWD_DEFINED__
typedef interface IEZNcDevice IEZNcDevice;
#endif 	/* __IEZNcDevice_FWD_DEFINED__ */


#ifndef __IEZNcGeneric2_FWD_DEFINED__
#define __IEZNcGeneric2_FWD_DEFINED__
typedef interface IEZNcGeneric2 IEZNcGeneric2;
#endif 	/* __IEZNcGeneric2_FWD_DEFINED__ */


#ifndef __IEZNcFile2_FWD_DEFINED__
#define __IEZNcFile2_FWD_DEFINED__
typedef interface IEZNcFile2 IEZNcFile2;
#endif 	/* __IEZNcFile2_FWD_DEFINED__ */


#ifndef __IEZNcTool3_FWD_DEFINED__
#define __IEZNcTool3_FWD_DEFINED__
typedef interface IEZNcTool3 IEZNcTool3;
#endif 	/* __IEZNcTool3_FWD_DEFINED__ */


#ifndef __IEZNcFile3_FWD_DEFINED__
#define __IEZNcFile3_FWD_DEFINED__
typedef interface IEZNcFile3 IEZNcFile3;
#endif 	/* __IEZNcFile3_FWD_DEFINED__ */


#ifndef __IEZNcFile4_FWD_DEFINED__
#define __IEZNcFile4_FWD_DEFINED__
typedef interface IEZNcFile4 IEZNcFile4;
#endif 	/* __IEZNcFile4_FWD_DEFINED__ */


#ifndef __IEZNcCommunication2_FWD_DEFINED__
#define __IEZNcCommunication2_FWD_DEFINED__
typedef interface IEZNcCommunication2 IEZNcCommunication2;
#endif 	/* __IEZNcCommunication2_FWD_DEFINED__ */


#ifndef __IEZNcSubFunction_FWD_DEFINED__
#define __IEZNcSubFunction_FWD_DEFINED__
typedef interface IEZNcSubFunction IEZNcSubFunction;
#endif 	/* __IEZNcSubFunction_FWD_DEFINED__ */


#ifndef __IEZNcSubFunction2_FWD_DEFINED__
#define __IEZNcSubFunction2_FWD_DEFINED__
typedef interface IEZNcSubFunction2 IEZNcSubFunction2;
#endif 	/* __IEZNcSubFunction2_FWD_DEFINED__ */


#ifndef __IEZNcSubFunction3_FWD_DEFINED__
#define __IEZNcSubFunction3_FWD_DEFINED__
typedef interface IEZNcSubFunction3 IEZNcSubFunction3;
#endif 	/* __IEZNcSubFunction3_FWD_DEFINED__ */


#ifndef __IEZNcCommand2_FWD_DEFINED__
#define __IEZNcCommand2_FWD_DEFINED__
typedef interface IEZNcCommand2 IEZNcCommand2;
#endif 	/* __IEZNcCommand2_FWD_DEFINED__ */


#ifndef __IEZNcProgram2_FWD_DEFINED__
#define __IEZNcProgram2_FWD_DEFINED__
typedef interface IEZNcProgram2 IEZNcProgram2;
#endif 	/* __IEZNcProgram2_FWD_DEFINED__ */


#ifndef __IEZNcFile5_FWD_DEFINED__
#define __IEZNcFile5_FWD_DEFINED__
typedef interface IEZNcFile5 IEZNcFile5;
#endif 	/* __IEZNcFile5_FWD_DEFINED__ */


#ifndef __IEZNcATC2_FWD_DEFINED__
#define __IEZNcATC2_FWD_DEFINED__
typedef interface IEZNcATC2 IEZNcATC2;
#endif 	/* __IEZNcATC2_FWD_DEFINED__ */


#ifndef __IEZNcCommunication3_FWD_DEFINED__
#define __IEZNcCommunication3_FWD_DEFINED__
typedef interface IEZNcCommunication3 IEZNcCommunication3;
#endif 	/* __IEZNcCommunication3_FWD_DEFINED__ */


#ifndef __IEZNcATC3_FWD_DEFINED__
#define __IEZNcATC3_FWD_DEFINED__
typedef interface IEZNcATC3 IEZNcATC3;
#endif 	/* __IEZNcATC3_FWD_DEFINED__ */


#ifndef __IEZNcParameter3_FWD_DEFINED__
#define __IEZNcParameter3_FWD_DEFINED__
typedef interface IEZNcParameter3 IEZNcParameter3;
#endif 	/* __IEZNcParameter3_FWD_DEFINED__ */


#ifndef __IEZNcFile6_FWD_DEFINED__
#define __IEZNcFile6_FWD_DEFINED__
typedef interface IEZNcFile6 IEZNcFile6;
#endif 	/* __IEZNcFile6_FWD_DEFINED__ */


#ifndef __IEZNcSystem2_FWD_DEFINED__
#define __IEZNcSystem2_FWD_DEFINED__
typedef interface IEZNcSystem2 IEZNcSystem2;
#endif 	/* __IEZNcSystem2_FWD_DEFINED__ */


#ifndef __EZNcCommunication_FWD_DEFINED__
#define __EZNcCommunication_FWD_DEFINED__

#ifdef __cplusplus
typedef class EZNcCommunication EZNcCommunication;
#else
typedef struct EZNcCommunication EZNcCommunication;
#endif /* __cplusplus */

#endif 	/* __EZNcCommunication_FWD_DEFINED__ */


#ifndef __EZNcCommunication230_FWD_DEFINED__
#define __EZNcCommunication230_FWD_DEFINED__

#ifdef __cplusplus
typedef class EZNcCommunication230 EZNcCommunication230;
#else
typedef struct EZNcCommunication230 EZNcCommunication230;
#endif /* __cplusplus */

#endif 	/* __EZNcCommunication230_FWD_DEFINED__ */


#ifndef __EZNcCommunication240_FWD_DEFINED__
#define __EZNcCommunication240_FWD_DEFINED__

#ifdef __cplusplus
typedef class EZNcCommunication240 EZNcCommunication240;
#else
typedef struct EZNcCommunication240 EZNcCommunication240;
#endif /* __cplusplus */

#endif 	/* __EZNcCommunication240_FWD_DEFINED__ */


#ifndef __EZNcCommunication250_FWD_DEFINED__
#define __EZNcCommunication250_FWD_DEFINED__

#ifdef __cplusplus
typedef class EZNcCommunication250 EZNcCommunication250;
#else
typedef struct EZNcCommunication250 EZNcCommunication250;
#endif /* __cplusplus */

#endif 	/* __EZNcCommunication250_FWD_DEFINED__ */


#ifndef __EZNcSubFunction_FWD_DEFINED__
#define __EZNcSubFunction_FWD_DEFINED__

#ifdef __cplusplus
typedef class EZNcSubFunction EZNcSubFunction;
#else
typedef struct EZNcSubFunction EZNcSubFunction;
#endif /* __cplusplus */

#endif 	/* __EZNcSubFunction_FWD_DEFINED__ */


#ifndef __EZNcCommunication270_FWD_DEFINED__
#define __EZNcCommunication270_FWD_DEFINED__

#ifdef __cplusplus
typedef class EZNcCommunication270 EZNcCommunication270;
#else
typedef struct EZNcCommunication270 EZNcCommunication270;
#endif /* __cplusplus */

#endif 	/* __EZNcCommunication270_FWD_DEFINED__ */


#ifndef __EZNcCommunication280_FWD_DEFINED__
#define __EZNcCommunication280_FWD_DEFINED__

#ifdef __cplusplus
typedef class EZNcCommunication280 EZNcCommunication280;
#else
typedef struct EZNcCommunication280 EZNcCommunication280;
#endif /* __cplusplus */

#endif 	/* __EZNcCommunication280_FWD_DEFINED__ */


#ifndef __EZNcCommunication283_FWD_DEFINED__
#define __EZNcCommunication283_FWD_DEFINED__

#ifdef __cplusplus
typedef class EZNcCommunication283 EZNcCommunication283;
#else
typedef struct EZNcCommunication283 EZNcCommunication283;
#endif /* __cplusplus */

#endif 	/* __EZNcCommunication283_FWD_DEFINED__ */


#ifndef __EZNcCommunication286_FWD_DEFINED__
#define __EZNcCommunication286_FWD_DEFINED__

#ifdef __cplusplus
typedef class EZNcCommunication286 EZNcCommunication286;
#else
typedef struct EZNcCommunication286 EZNcCommunication286;
#endif /* __cplusplus */

#endif 	/* __EZNcCommunication286_FWD_DEFINED__ */


#ifndef __EZNcCommunication289_FWD_DEFINED__
#define __EZNcCommunication289_FWD_DEFINED__

#ifdef __cplusplus
typedef class EZNcCommunication289 EZNcCommunication289;
#else
typedef struct EZNcCommunication289 EZNcCommunication289;
#endif /* __cplusplus */

#endif 	/* __EZNcCommunication289_FWD_DEFINED__ */


#ifndef __EZNcCommunication290_FWD_DEFINED__
#define __EZNcCommunication290_FWD_DEFINED__

#ifdef __cplusplus
typedef class EZNcCommunication290 EZNcCommunication290;
#else
typedef struct EZNcCommunication290 EZNcCommunication290;
#endif /* __cplusplus */

#endif 	/* __EZNcCommunication290_FWD_DEFINED__ */


#ifndef __EZNcCommunication291_FWD_DEFINED__
#define __EZNcCommunication291_FWD_DEFINED__

#ifdef __cplusplus
typedef class EZNcCommunication291 EZNcCommunication291;
#else
typedef struct EZNcCommunication291 EZNcCommunication291;
#endif /* __cplusplus */

#endif 	/* __EZNcCommunication291_FWD_DEFINED__ */


#ifndef __EZNcCommunication301_FWD_DEFINED__
#define __EZNcCommunication301_FWD_DEFINED__

#ifdef __cplusplus
typedef class EZNcCommunication301 EZNcCommunication301;
#else
typedef struct EZNcCommunication301 EZNcCommunication301;
#endif /* __cplusplus */

#endif 	/* __EZNcCommunication301_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "EZSocketNcStr.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IEZNcCommunication_INTERFACE_DEFINED__
#define __IEZNcCommunication_INTERFACE_DEFINED__

/* interface IEZNcCommunication */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcCommunication;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8A1-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcCommunication : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ LONG lSystemType,
            /* [in] */ LONG lMachine,
            /* [in] */ LONG lTimeOut,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE CommActivate( 
            /* [in] */ LONG lActivate,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetHead( 
            /* [in] */ LONG lHead,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetHead( 
            /* [out] */ LONG __RPC_FAR *plHead,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcCommunicationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcCommunication __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcCommunication __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcCommunication __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IEZNcCommunication __RPC_FAR * This,
            /* [in] */ LONG lSystemType,
            /* [in] */ LONG lMachine,
            /* [in] */ LONG lTimeOut,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IEZNcCommunication __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CommActivate )( 
            IEZNcCommunication __RPC_FAR * This,
            /* [in] */ LONG lActivate,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHead )( 
            IEZNcCommunication __RPC_FAR * This,
            /* [in] */ LONG lHead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHead )( 
            IEZNcCommunication __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plHead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcCommunicationVtbl;

    interface IEZNcCommunication
    {
        CONST_VTBL struct IEZNcCommunicationVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcCommunication_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcCommunication_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcCommunication_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcCommunication_Open(This,lSystemType,lMachine,lTimeOut,plRet)	\
    (This)->lpVtbl -> Open(This,lSystemType,lMachine,lTimeOut,plRet)

#define IEZNcCommunication_Close(This,plRet)	\
    (This)->lpVtbl -> Close(This,plRet)

#define IEZNcCommunication_CommActivate(This,lActivate,plRet)	\
    (This)->lpVtbl -> CommActivate(This,lActivate,plRet)

#define IEZNcCommunication_SetHead(This,lHead,plRet)	\
    (This)->lpVtbl -> SetHead(This,lHead,plRet)

#define IEZNcCommunication_GetHead(This,plHead,plRet)	\
    (This)->lpVtbl -> GetHead(This,plHead,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommunication_Open_Proxy( 
    IEZNcCommunication __RPC_FAR * This,
    /* [in] */ LONG lSystemType,
    /* [in] */ LONG lMachine,
    /* [in] */ LONG lTimeOut,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommunication_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommunication_Close_Proxy( 
    IEZNcCommunication __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommunication_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommunication_CommActivate_Proxy( 
    IEZNcCommunication __RPC_FAR * This,
    /* [in] */ LONG lActivate,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommunication_CommActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommunication_SetHead_Proxy( 
    IEZNcCommunication __RPC_FAR * This,
    /* [in] */ LONG lHead,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommunication_SetHead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommunication_GetHead_Proxy( 
    IEZNcCommunication __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plHead,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommunication_GetHead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcCommunication_INTERFACE_DEFINED__ */


#ifndef __IEZNcSystem_INTERFACE_DEFINED__
#define __IEZNcSystem_INTERFACE_DEFINED__

/* interface IEZNcSystem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcSystem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8A2-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcSystem : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSystemInformation( 
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plSystem,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAlarm( 
            /* [in] */ LONG lMessageNumber,
            /* [in] */ LONG lAlarmType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE BackUp( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcSystemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcSystem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcSystem __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcSystem __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVersion )( 
            IEZNcSystem __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSystemInformation )( 
            IEZNcSystem __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plSystem,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAlarm )( 
            IEZNcSystem __RPC_FAR * This,
            /* [in] */ LONG lMessageNumber,
            /* [in] */ LONG lAlarmType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BackUp )( 
            IEZNcSystem __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcSystemVtbl;

    interface IEZNcSystem
    {
        CONST_VTBL struct IEZNcSystemVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcSystem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcSystem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcSystem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcSystem_GetVersion(This,lAxisNo,lIndex,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetVersion(This,lAxisNo,lIndex,lppwszBuffer,plRet)

#define IEZNcSystem_GetSystemInformation(This,lType,plSystem,plRet)	\
    (This)->lpVtbl -> GetSystemInformation(This,lType,plSystem,plRet)

#define IEZNcSystem_GetAlarm(This,lMessageNumber,lAlarmType,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetAlarm(This,lMessageNumber,lAlarmType,lppwszBuffer,plRet)

#define IEZNcSystem_BackUp(This,lAxisNo,lIndex,plRet)	\
    (This)->lpVtbl -> BackUp(This,lAxisNo,lIndex,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSystem_GetVersion_Proxy( 
    IEZNcSystem __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSystem_GetVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSystem_GetSystemInformation_Proxy( 
    IEZNcSystem __RPC_FAR * This,
    /* [in] */ LONG lType,
    /* [out] */ LONG __RPC_FAR *plSystem,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSystem_GetSystemInformation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSystem_GetAlarm_Proxy( 
    IEZNcSystem __RPC_FAR * This,
    /* [in] */ LONG lMessageNumber,
    /* [in] */ LONG lAlarmType,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSystem_GetAlarm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSystem_BackUp_Proxy( 
    IEZNcSystem __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSystem_BackUp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcSystem_INTERFACE_DEFINED__ */


#ifndef __IEZNcPosition_INTERFACE_DEFINED__
#define __IEZNcPosition_INTERFACE_DEFINED__

/* interface IEZNcPosition */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcPosition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8A3-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcPosition : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetWorkPosition( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [in] */ LONG lSkipOn,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetWorkPosition2( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [in] */ LONG lSkipOn,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMachinePosition( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [in] */ LONG lSkipOn,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMachinePosition2( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [in] */ LONG lSkipOn,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentPosition( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetVectorDistance( 
            /* [out] */ DOUBLE __RPC_FAR *pdVector,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetVectorDistance2( 
            /* [out] */ DOUBLE __RPC_FAR *pdVector,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDistance( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdDistance,
            /* [in] */ LONG lSkipOn,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDistance2( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdDistance,
            /* [in] */ LONG lSkipOn,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNextDistance( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdDistance,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetInvalidOrigine( 
            /* [in] */ LONG lFlag,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetOrigine( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ DOUBLE dOrigine,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCounter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ DOUBLE dCounter,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetFeedSpeed( 
            /* [in] */ LONG lFeedType,
            /* [out] */ DOUBLE __RPC_FAR *pdSpeed,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetTCPSpeed( 
            /* [out] */ DOUBLE __RPC_FAR *pdSpeed,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetManualOverlap( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lType,
            /* [out] */ DOUBLE __RPC_FAR *pdLength,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetManualOverlap2( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lType,
            /* [out] */ DOUBLE __RPC_FAR *pdLength,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PositionRegister( 
            /* [in] */ LONG lPriority,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PositionCancel( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetSlidePosition( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProgramPosition( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProgramPosition3( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetToleranceInterval( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdInterval,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetProgramPosition2( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetTCPMachinePosition( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetTCPWorkPosition( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetFeedbackPosition( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetTableCoordinationPosition( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetWorkInstallationPosition( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetInclinedSurfacePosition( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcPositionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcPosition __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcPosition __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWorkPosition )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [in] */ LONG lSkipOn,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWorkPosition2 )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [in] */ LONG lSkipOn,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMachinePosition )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [in] */ LONG lSkipOn,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMachinePosition2 )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [in] */ LONG lSkipOn,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentPosition )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVectorDistance )( 
            IEZNcPosition __RPC_FAR * This,
            /* [out] */ DOUBLE __RPC_FAR *pdVector,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVectorDistance2 )( 
            IEZNcPosition __RPC_FAR * This,
            /* [out] */ DOUBLE __RPC_FAR *pdVector,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDistance )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdDistance,
            /* [in] */ LONG lSkipOn,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDistance2 )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdDistance,
            /* [in] */ LONG lSkipOn,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNextDistance )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdDistance,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInvalidOrigine )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lFlag,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOrigine )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ DOUBLE dOrigine,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCounter )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ DOUBLE dCounter,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFeedSpeed )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lFeedType,
            /* [out] */ DOUBLE __RPC_FAR *pdSpeed,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTCPSpeed )( 
            IEZNcPosition __RPC_FAR * This,
            /* [out] */ DOUBLE __RPC_FAR *pdSpeed,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetManualOverlap )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lType,
            /* [out] */ DOUBLE __RPC_FAR *pdLength,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetManualOverlap2 )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lType,
            /* [out] */ DOUBLE __RPC_FAR *pdLength,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PositionRegister )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lPriority,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PositionCancel )( 
            IEZNcPosition __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSlidePosition )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProgramPosition )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProgramPosition3 )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToleranceInterval )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdInterval,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProgramPosition2 )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTCPMachinePosition )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTCPWorkPosition )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFeedbackPosition )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTableCoordinationPosition )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWorkInstallationPosition )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInclinedSurfacePosition )( 
            IEZNcPosition __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdPosition,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcPositionVtbl;

    interface IEZNcPosition
    {
        CONST_VTBL struct IEZNcPositionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcPosition_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcPosition_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcPosition_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcPosition_GetWorkPosition(This,lAxisNo,pdPosition,lSkipOn,plRet)	\
    (This)->lpVtbl -> GetWorkPosition(This,lAxisNo,pdPosition,lSkipOn,plRet)

#define IEZNcPosition_GetWorkPosition2(This,lAxisNo,pdPosition,lSkipOn,plRet)	\
    (This)->lpVtbl -> GetWorkPosition2(This,lAxisNo,pdPosition,lSkipOn,plRet)

#define IEZNcPosition_GetMachinePosition(This,lAxisNo,pdPosition,lSkipOn,plRet)	\
    (This)->lpVtbl -> GetMachinePosition(This,lAxisNo,pdPosition,lSkipOn,plRet)

#define IEZNcPosition_GetMachinePosition2(This,lAxisNo,pdPosition,lSkipOn,plRet)	\
    (This)->lpVtbl -> GetMachinePosition2(This,lAxisNo,pdPosition,lSkipOn,plRet)

#define IEZNcPosition_GetCurrentPosition(This,lAxisNo,pdPosition,plRet)	\
    (This)->lpVtbl -> GetCurrentPosition(This,lAxisNo,pdPosition,plRet)

#define IEZNcPosition_GetVectorDistance(This,pdVector,plRet)	\
    (This)->lpVtbl -> GetVectorDistance(This,pdVector,plRet)

#define IEZNcPosition_GetVectorDistance2(This,pdVector,plRet)	\
    (This)->lpVtbl -> GetVectorDistance2(This,pdVector,plRet)

#define IEZNcPosition_GetDistance(This,lAxisNo,pdDistance,lSkipOn,plRet)	\
    (This)->lpVtbl -> GetDistance(This,lAxisNo,pdDistance,lSkipOn,plRet)

#define IEZNcPosition_GetDistance2(This,lAxisNo,pdDistance,lSkipOn,plRet)	\
    (This)->lpVtbl -> GetDistance2(This,lAxisNo,pdDistance,lSkipOn,plRet)

#define IEZNcPosition_GetNextDistance(This,lAxisNo,pdDistance,plRet)	\
    (This)->lpVtbl -> GetNextDistance(This,lAxisNo,pdDistance,plRet)

#define IEZNcPosition_SetInvalidOrigine(This,lFlag,plRet)	\
    (This)->lpVtbl -> SetInvalidOrigine(This,lFlag,plRet)

#define IEZNcPosition_SetOrigine(This,lAxisNo,dOrigine,plRet)	\
    (This)->lpVtbl -> SetOrigine(This,lAxisNo,dOrigine,plRet)

#define IEZNcPosition_SetCounter(This,lAxisNo,dCounter,plRet)	\
    (This)->lpVtbl -> SetCounter(This,lAxisNo,dCounter,plRet)

#define IEZNcPosition_GetFeedSpeed(This,lFeedType,pdSpeed,plRet)	\
    (This)->lpVtbl -> GetFeedSpeed(This,lFeedType,pdSpeed,plRet)

#define IEZNcPosition_GetTCPSpeed(This,pdSpeed,plRet)	\
    (This)->lpVtbl -> GetTCPSpeed(This,pdSpeed,plRet)

#define IEZNcPosition_GetManualOverlap(This,lAxisNo,lType,pdLength,plRet)	\
    (This)->lpVtbl -> GetManualOverlap(This,lAxisNo,lType,pdLength,plRet)

#define IEZNcPosition_GetManualOverlap2(This,lAxisNo,lType,pdLength,plRet)	\
    (This)->lpVtbl -> GetManualOverlap2(This,lAxisNo,lType,pdLength,plRet)

#define IEZNcPosition_PositionRegister(This,lPriority,plRet)	\
    (This)->lpVtbl -> PositionRegister(This,lPriority,plRet)

#define IEZNcPosition_PositionCancel(This,plRet)	\
    (This)->lpVtbl -> PositionCancel(This,plRet)

#define IEZNcPosition_GetSlidePosition(This,lAxisNo,pdPosition,plRet)	\
    (This)->lpVtbl -> GetSlidePosition(This,lAxisNo,pdPosition,plRet)

#define IEZNcPosition_GetProgramPosition(This,lAxisNo,pdPosition,plRet)	\
    (This)->lpVtbl -> GetProgramPosition(This,lAxisNo,pdPosition,plRet)

#define IEZNcPosition_GetProgramPosition3(This,lAxisNo,pdPosition,plRet)	\
    (This)->lpVtbl -> GetProgramPosition3(This,lAxisNo,pdPosition,plRet)

#define IEZNcPosition_GetToleranceInterval(This,lAxisNo,pdInterval,plRet)	\
    (This)->lpVtbl -> GetToleranceInterval(This,lAxisNo,pdInterval,plRet)

#define IEZNcPosition_GetProgramPosition2(This,lAxisNo,pdPosition,plRet)	\
    (This)->lpVtbl -> GetProgramPosition2(This,lAxisNo,pdPosition,plRet)

#define IEZNcPosition_GetTCPMachinePosition(This,lAxisNo,pdPosition,plRet)	\
    (This)->lpVtbl -> GetTCPMachinePosition(This,lAxisNo,pdPosition,plRet)

#define IEZNcPosition_GetTCPWorkPosition(This,lAxisNo,pdPosition,plRet)	\
    (This)->lpVtbl -> GetTCPWorkPosition(This,lAxisNo,pdPosition,plRet)

#define IEZNcPosition_GetFeedbackPosition(This,lAxisNo,pdPosition,plRet)	\
    (This)->lpVtbl -> GetFeedbackPosition(This,lAxisNo,pdPosition,plRet)

#define IEZNcPosition_GetTableCoordinationPosition(This,lAxisNo,pdPosition,plRet)	\
    (This)->lpVtbl -> GetTableCoordinationPosition(This,lAxisNo,pdPosition,plRet)

#define IEZNcPosition_GetWorkInstallationPosition(This,lAxisNo,pdPosition,plRet)	\
    (This)->lpVtbl -> GetWorkInstallationPosition(This,lAxisNo,pdPosition,plRet)

#define IEZNcPosition_GetInclinedSurfacePosition(This,lAxisNo,pdPosition,plRet)	\
    (This)->lpVtbl -> GetInclinedSurfacePosition(This,lAxisNo,pdPosition,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetWorkPosition_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [in] */ LONG lSkipOn,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetWorkPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetWorkPosition2_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [in] */ LONG lSkipOn,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetWorkPosition2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetMachinePosition_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [in] */ LONG lSkipOn,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetMachinePosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetMachinePosition2_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [in] */ LONG lSkipOn,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetMachinePosition2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetCurrentPosition_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetCurrentPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetVectorDistance_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [out] */ DOUBLE __RPC_FAR *pdVector,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetVectorDistance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetVectorDistance2_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [out] */ DOUBLE __RPC_FAR *pdVector,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetVectorDistance2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetDistance_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdDistance,
    /* [in] */ LONG lSkipOn,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetDistance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetDistance2_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdDistance,
    /* [in] */ LONG lSkipOn,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetDistance2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetNextDistance_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdDistance,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetNextDistance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_SetInvalidOrigine_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lFlag,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_SetInvalidOrigine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_SetOrigine_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ DOUBLE dOrigine,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_SetOrigine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_SetCounter_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ DOUBLE dCounter,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_SetCounter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetFeedSpeed_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lFeedType,
    /* [out] */ DOUBLE __RPC_FAR *pdSpeed,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetFeedSpeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetTCPSpeed_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [out] */ DOUBLE __RPC_FAR *pdSpeed,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetTCPSpeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetManualOverlap_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lType,
    /* [out] */ DOUBLE __RPC_FAR *pdLength,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetManualOverlap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetManualOverlap2_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lType,
    /* [out] */ DOUBLE __RPC_FAR *pdLength,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetManualOverlap2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_PositionRegister_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lPriority,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_PositionRegister_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_PositionCancel_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_PositionCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetSlidePosition_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetSlidePosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetProgramPosition_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetProgramPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetProgramPosition3_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetProgramPosition3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetToleranceInterval_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdInterval,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetToleranceInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetProgramPosition2_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetProgramPosition2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetTCPMachinePosition_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetTCPMachinePosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetTCPWorkPosition_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetTCPWorkPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetFeedbackPosition_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetFeedbackPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetTableCoordinationPosition_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetTableCoordinationPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetWorkInstallationPosition_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetWorkInstallationPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcPosition_GetInclinedSurfacePosition_Proxy( 
    IEZNcPosition __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdPosition,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcPosition_GetInclinedSurfacePosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcPosition_INTERFACE_DEFINED__ */


#ifndef __IEZNcProgram_INTERFACE_DEFINED__
#define __IEZNcProgram_INTERFACE_DEFINED__

/* interface IEZNcProgram */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcProgram;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8A4-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcProgram : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CurrentBlockRead( 
            /* [in] */ LONG lBlockNumber,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszProgramData,
            /* [out] */ LONG __RPC_FAR *plCurrentBlockNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProgramNumber( 
            /* [in] */ LONG lProgramType,
            /* [out] */ LONG __RPC_FAR *plProgramNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSequenceNumber( 
            /* [in] */ LONG lProgramType,
            /* [out] */ LONG __RPC_FAR *plSequenceNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetBlockNumber( 
            /* [in] */ LONG lProgramType,
            /* [out] */ LONG __RPC_FAR *plBlockNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSubProLevel( 
            /* [out] */ LONG __RPC_FAR *plLevel,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetInformation( 
            /* [in] */ LONG lInfoType,
            /* [out] */ LONG __RPC_FAR *plInfoData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcProgramVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcProgram __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcProgram __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcProgram __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CurrentBlockRead )( 
            IEZNcProgram __RPC_FAR * This,
            /* [in] */ LONG lBlockNumber,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszProgramData,
            /* [out] */ LONG __RPC_FAR *plCurrentBlockNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProgramNumber )( 
            IEZNcProgram __RPC_FAR * This,
            /* [in] */ LONG lProgramType,
            /* [out] */ LONG __RPC_FAR *plProgramNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSequenceNumber )( 
            IEZNcProgram __RPC_FAR * This,
            /* [in] */ LONG lProgramType,
            /* [out] */ LONG __RPC_FAR *plSequenceNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBlockNumber )( 
            IEZNcProgram __RPC_FAR * This,
            /* [in] */ LONG lProgramType,
            /* [out] */ LONG __RPC_FAR *plBlockNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSubProLevel )( 
            IEZNcProgram __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plLevel,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInformation )( 
            IEZNcProgram __RPC_FAR * This,
            /* [in] */ LONG lInfoType,
            /* [out] */ LONG __RPC_FAR *plInfoData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcProgramVtbl;

    interface IEZNcProgram
    {
        CONST_VTBL struct IEZNcProgramVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcProgram_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcProgram_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcProgram_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcProgram_CurrentBlockRead(This,lBlockNumber,lppwszProgramData,plCurrentBlockNo,plRet)	\
    (This)->lpVtbl -> CurrentBlockRead(This,lBlockNumber,lppwszProgramData,plCurrentBlockNo,plRet)

#define IEZNcProgram_GetProgramNumber(This,lProgramType,plProgramNo,plRet)	\
    (This)->lpVtbl -> GetProgramNumber(This,lProgramType,plProgramNo,plRet)

#define IEZNcProgram_GetSequenceNumber(This,lProgramType,plSequenceNo,plRet)	\
    (This)->lpVtbl -> GetSequenceNumber(This,lProgramType,plSequenceNo,plRet)

#define IEZNcProgram_GetBlockNumber(This,lProgramType,plBlockNo,plRet)	\
    (This)->lpVtbl -> GetBlockNumber(This,lProgramType,plBlockNo,plRet)

#define IEZNcProgram_GetSubProLevel(This,plLevel,plRet)	\
    (This)->lpVtbl -> GetSubProLevel(This,plLevel,plRet)

#define IEZNcProgram_GetInformation(This,lInfoType,plInfoData,plRet)	\
    (This)->lpVtbl -> GetInformation(This,lInfoType,plInfoData,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcProgram_CurrentBlockRead_Proxy( 
    IEZNcProgram __RPC_FAR * This,
    /* [in] */ LONG lBlockNumber,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszProgramData,
    /* [out] */ LONG __RPC_FAR *plCurrentBlockNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcProgram_CurrentBlockRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcProgram_GetProgramNumber_Proxy( 
    IEZNcProgram __RPC_FAR * This,
    /* [in] */ LONG lProgramType,
    /* [out] */ LONG __RPC_FAR *plProgramNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcProgram_GetProgramNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcProgram_GetSequenceNumber_Proxy( 
    IEZNcProgram __RPC_FAR * This,
    /* [in] */ LONG lProgramType,
    /* [out] */ LONG __RPC_FAR *plSequenceNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcProgram_GetSequenceNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcProgram_GetBlockNumber_Proxy( 
    IEZNcProgram __RPC_FAR * This,
    /* [in] */ LONG lProgramType,
    /* [out] */ LONG __RPC_FAR *plBlockNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcProgram_GetBlockNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcProgram_GetSubProLevel_Proxy( 
    IEZNcProgram __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plLevel,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcProgram_GetSubProLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcProgram_GetInformation_Proxy( 
    IEZNcProgram __RPC_FAR * This,
    /* [in] */ LONG lInfoType,
    /* [out] */ LONG __RPC_FAR *plInfoData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcProgram_GetInformation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcProgram_INTERFACE_DEFINED__ */


#ifndef __IEZNcTime_INTERFACE_DEFINED__
#define __IEZNcTime_INTERFACE_DEFINED__

/* interface IEZNcTime */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcTime;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8A5-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcTime : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ LONG __RPC_FAR *plDate,
            /* [out] */ LONG __RPC_FAR *plTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ LONG lDate,
            /* [in] */ LONG lTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAliveTime( 
            /* [out] */ LONG __RPC_FAR *plTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAliveTime( 
            /* [in] */ LONG lTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRunTime( 
            /* [out] */ LONG __RPC_FAR *plTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetRunTime( 
            /* [in] */ LONG lTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetStartTime( 
            /* [out] */ LONG __RPC_FAR *plTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetStartTime( 
            /* [in] */ LONG lTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetEstimateTime( 
            /* [in] */ LONG lKind,
            /* [out] */ LONG __RPC_FAR *plTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetEstimateTime( 
            /* [in] */ LONG lKind,
            /* [in] */ LONG lTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcTimeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcTime __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcTime __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcTime __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClockData )( 
            IEZNcTime __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plDate,
            /* [out] */ LONG __RPC_FAR *plTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClockData )( 
            IEZNcTime __RPC_FAR * This,
            /* [in] */ LONG lDate,
            /* [in] */ LONG lTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAliveTime )( 
            IEZNcTime __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAliveTime )( 
            IEZNcTime __RPC_FAR * This,
            /* [in] */ LONG lTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRunTime )( 
            IEZNcTime __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRunTime )( 
            IEZNcTime __RPC_FAR * This,
            /* [in] */ LONG lTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStartTime )( 
            IEZNcTime __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStartTime )( 
            IEZNcTime __RPC_FAR * This,
            /* [in] */ LONG lTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEstimateTime )( 
            IEZNcTime __RPC_FAR * This,
            /* [in] */ LONG lKind,
            /* [out] */ LONG __RPC_FAR *plTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEstimateTime )( 
            IEZNcTime __RPC_FAR * This,
            /* [in] */ LONG lKind,
            /* [in] */ LONG lTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcTimeVtbl;

    interface IEZNcTime
    {
        CONST_VTBL struct IEZNcTimeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcTime_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcTime_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcTime_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcTime_GetClockData(This,plDate,plTime,plRet)	\
    (This)->lpVtbl -> GetClockData(This,plDate,plTime,plRet)

#define IEZNcTime_SetClockData(This,lDate,lTime,plRet)	\
    (This)->lpVtbl -> SetClockData(This,lDate,lTime,plRet)

#define IEZNcTime_GetAliveTime(This,plTime,plRet)	\
    (This)->lpVtbl -> GetAliveTime(This,plTime,plRet)

#define IEZNcTime_SetAliveTime(This,lTime,plRet)	\
    (This)->lpVtbl -> SetAliveTime(This,lTime,plRet)

#define IEZNcTime_GetRunTime(This,plTime,plRet)	\
    (This)->lpVtbl -> GetRunTime(This,plTime,plRet)

#define IEZNcTime_SetRunTime(This,lTime,plRet)	\
    (This)->lpVtbl -> SetRunTime(This,lTime,plRet)

#define IEZNcTime_GetStartTime(This,plTime,plRet)	\
    (This)->lpVtbl -> GetStartTime(This,plTime,plRet)

#define IEZNcTime_SetStartTime(This,lTime,plRet)	\
    (This)->lpVtbl -> SetStartTime(This,lTime,plRet)

#define IEZNcTime_GetEstimateTime(This,lKind,plTime,plRet)	\
    (This)->lpVtbl -> GetEstimateTime(This,lKind,plTime,plRet)

#define IEZNcTime_SetEstimateTime(This,lKind,lTime,plRet)	\
    (This)->lpVtbl -> SetEstimateTime(This,lKind,lTime,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTime_GetClockData_Proxy( 
    IEZNcTime __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plDate,
    /* [out] */ LONG __RPC_FAR *plTime,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTime_GetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTime_SetClockData_Proxy( 
    IEZNcTime __RPC_FAR * This,
    /* [in] */ LONG lDate,
    /* [in] */ LONG lTime,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTime_SetClockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTime_GetAliveTime_Proxy( 
    IEZNcTime __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plTime,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTime_GetAliveTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTime_SetAliveTime_Proxy( 
    IEZNcTime __RPC_FAR * This,
    /* [in] */ LONG lTime,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTime_SetAliveTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTime_GetRunTime_Proxy( 
    IEZNcTime __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plTime,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTime_GetRunTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTime_SetRunTime_Proxy( 
    IEZNcTime __RPC_FAR * This,
    /* [in] */ LONG lTime,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTime_SetRunTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTime_GetStartTime_Proxy( 
    IEZNcTime __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plTime,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTime_GetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTime_SetStartTime_Proxy( 
    IEZNcTime __RPC_FAR * This,
    /* [in] */ LONG lTime,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTime_SetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTime_GetEstimateTime_Proxy( 
    IEZNcTime __RPC_FAR * This,
    /* [in] */ LONG lKind,
    /* [out] */ LONG __RPC_FAR *plTime,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTime_GetEstimateTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTime_SetEstimateTime_Proxy( 
    IEZNcTime __RPC_FAR * This,
    /* [in] */ LONG lKind,
    /* [in] */ LONG lTime,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTime_SetEstimateTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcTime_INTERFACE_DEFINED__ */


#ifndef __IEZNcRunStatus_INTERFACE_DEFINED__
#define __IEZNcRunStatus_INTERFACE_DEFINED__

/* interface IEZNcRunStatus */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcRunStatus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8A6-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcRunStatus : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetInvalidStatus( 
            /* [out] */ LONG __RPC_FAR *plStatus,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCommandStatus( 
            /* [out] */ LONG __RPC_FAR *plStatus,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCuttingMode( 
            /* [out] */ LONG __RPC_FAR *plMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAxisStatus( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plStatus,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetRunStatus( 
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plStatus,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StatusRegister( 
            /* [in] */ LONG lPriority,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StatusCancel( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetSlideState( 
            /* [in] */ LONG lAxisNo,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcRunStatusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcRunStatus __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcRunStatus __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcRunStatus __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInvalidStatus )( 
            IEZNcRunStatus __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plStatus,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommandStatus )( 
            IEZNcRunStatus __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plStatus,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCuttingMode )( 
            IEZNcRunStatus __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAxisStatus )( 
            IEZNcRunStatus __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plStatus,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRunStatus )( 
            IEZNcRunStatus __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plStatus,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StatusRegister )( 
            IEZNcRunStatus __RPC_FAR * This,
            /* [in] */ LONG lPriority,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StatusCancel )( 
            IEZNcRunStatus __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSlideState )( 
            IEZNcRunStatus __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcRunStatusVtbl;

    interface IEZNcRunStatus
    {
        CONST_VTBL struct IEZNcRunStatusVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcRunStatus_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcRunStatus_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcRunStatus_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcRunStatus_GetInvalidStatus(This,plStatus,plRet)	\
    (This)->lpVtbl -> GetInvalidStatus(This,plStatus,plRet)

#define IEZNcRunStatus_GetCommandStatus(This,plStatus,plRet)	\
    (This)->lpVtbl -> GetCommandStatus(This,plStatus,plRet)

#define IEZNcRunStatus_GetCuttingMode(This,plMode,plRet)	\
    (This)->lpVtbl -> GetCuttingMode(This,plMode,plRet)

#define IEZNcRunStatus_GetAxisStatus(This,lAxisNo,lType,plStatus,plRet)	\
    (This)->lpVtbl -> GetAxisStatus(This,lAxisNo,lType,plStatus,plRet)

#define IEZNcRunStatus_GetRunStatus(This,lIndex,plStatus,plRet)	\
    (This)->lpVtbl -> GetRunStatus(This,lIndex,plStatus,plRet)

#define IEZNcRunStatus_StatusRegister(This,lPriority,plRet)	\
    (This)->lpVtbl -> StatusRegister(This,lPriority,plRet)

#define IEZNcRunStatus_StatusCancel(This,plRet)	\
    (This)->lpVtbl -> StatusCancel(This,plRet)

#define IEZNcRunStatus_GetSlideState(This,lAxisNo,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetSlideState(This,lAxisNo,lppwszBuffer,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcRunStatus_GetInvalidStatus_Proxy( 
    IEZNcRunStatus __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plStatus,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcRunStatus_GetInvalidStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcRunStatus_GetCommandStatus_Proxy( 
    IEZNcRunStatus __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plStatus,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcRunStatus_GetCommandStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcRunStatus_GetCuttingMode_Proxy( 
    IEZNcRunStatus __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plMode,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcRunStatus_GetCuttingMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcRunStatus_GetAxisStatus_Proxy( 
    IEZNcRunStatus __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lType,
    /* [out] */ LONG __RPC_FAR *plStatus,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcRunStatus_GetAxisStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcRunStatus_GetRunStatus_Proxy( 
    IEZNcRunStatus __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plStatus,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcRunStatus_GetRunStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcRunStatus_StatusRegister_Proxy( 
    IEZNcRunStatus __RPC_FAR * This,
    /* [in] */ LONG lPriority,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcRunStatus_StatusRegister_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcRunStatus_StatusCancel_Proxy( 
    IEZNcRunStatus __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcRunStatus_StatusCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcRunStatus_GetSlideState_Proxy( 
    IEZNcRunStatus __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcRunStatus_GetSlideState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcRunStatus_INTERFACE_DEFINED__ */


#ifndef __IEZNcFile_INTERFACE_DEFINED__
#define __IEZNcFile_INTERFACE_DEFINED__

/* interface IEZNcFile */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcFile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8A7-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcFile : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindDir( 
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [in] */ LONG lFileType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindNextDir( 
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ResetDir( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Copy( 
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Rename( 
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDriveInformation( 
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszDriveInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDriveSize( 
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [out] */ LONG __RPC_FAR *plDriveSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcFileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcFile __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcFile __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcFile __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindDir )( 
            IEZNcFile __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [in] */ LONG lFileType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindNextDir )( 
            IEZNcFile __RPC_FAR * This,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetDir )( 
            IEZNcFile __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Copy )( 
            IEZNcFile __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IEZNcFile __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Rename )( 
            IEZNcFile __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveInformation )( 
            IEZNcFile __RPC_FAR * This,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszDriveInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveSize )( 
            IEZNcFile __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [out] */ LONG __RPC_FAR *plDriveSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcFileVtbl;

    interface IEZNcFile
    {
        CONST_VTBL struct IEZNcFileVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcFile_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcFile_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcFile_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcFile_FindDir(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindDir(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)

#define IEZNcFile_FindNextDir(This,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindNextDir(This,lppwszFileInfo,plRet)

#define IEZNcFile_ResetDir(This,plRet)	\
    (This)->lpVtbl -> ResetDir(This,plRet)

#define IEZNcFile_Copy(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Copy(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile_Delete(This,lpcwszFileName,plRet)	\
    (This)->lpVtbl -> Delete(This,lpcwszFileName,plRet)

#define IEZNcFile_Rename(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Rename(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile_GetDriveInformation(This,lppwszDriveInfo,plRet)	\
    (This)->lpVtbl -> GetDriveInformation(This,lppwszDriveInfo,plRet)

#define IEZNcFile_GetDriveSize(This,lpcwszDirectoryName,plDriveSize,plRet)	\
    (This)->lpVtbl -> GetDriveSize(This,lpcwszDirectoryName,plDriveSize,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile_FindDir_Proxy( 
    IEZNcFile __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
    /* [in] */ LONG lFileType,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile_FindDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile_FindNextDir_Proxy( 
    IEZNcFile __RPC_FAR * This,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile_FindNextDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile_ResetDir_Proxy( 
    IEZNcFile __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile_ResetDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile_Copy_Proxy( 
    IEZNcFile __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
    /* [string][in] */ LPCOLESTR lpcwszDstFileName,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile_Delete_Proxy( 
    IEZNcFile __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile_Rename_Proxy( 
    IEZNcFile __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
    /* [string][in] */ LPCOLESTR lpcwszDstFileName,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile_Rename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile_GetDriveInformation_Proxy( 
    IEZNcFile __RPC_FAR * This,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszDriveInfo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile_GetDriveInformation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile_GetDriveSize_Proxy( 
    IEZNcFile __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
    /* [out] */ LONG __RPC_FAR *plDriveSize,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile_GetDriveSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcFile_INTERFACE_DEFINED__ */


#ifndef __IEZNcOperation_INTERFACE_DEFINED__
#define __IEZNcOperation_INTERFACE_DEFINED__

/* interface IEZNcOperation */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcOperation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8A8-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcOperation : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Search( 
            /* [string][in] */ LPCOLESTR lpcwszSelectProgram,
            /* [in] */ LONG lSequenceNo,
            /* [in] */ LONG lBlockNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SelectMode( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Run( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Stop( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcOperationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcOperation __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcOperation __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcOperation __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Search )( 
            IEZNcOperation __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSelectProgram,
            /* [in] */ LONG lSequenceNo,
            /* [in] */ LONG lBlockNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SelectMode )( 
            IEZNcOperation __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Run )( 
            IEZNcOperation __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IEZNcOperation __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcOperationVtbl;

    interface IEZNcOperation
    {
        CONST_VTBL struct IEZNcOperationVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcOperation_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcOperation_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcOperation_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcOperation_Search(This,lpcwszSelectProgram,lSequenceNo,lBlockNo,plRet)	\
    (This)->lpVtbl -> Search(This,lpcwszSelectProgram,lSequenceNo,lBlockNo,plRet)

#define IEZNcOperation_SelectMode(This,lAxisNo,lIndex,lMode,plRet)	\
    (This)->lpVtbl -> SelectMode(This,lAxisNo,lIndex,lMode,plRet)

#define IEZNcOperation_Run(This,plRet)	\
    (This)->lpVtbl -> Run(This,plRet)

#define IEZNcOperation_Stop(This,plRet)	\
    (This)->lpVtbl -> Stop(This,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcOperation_Search_Proxy( 
    IEZNcOperation __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszSelectProgram,
    /* [in] */ LONG lSequenceNo,
    /* [in] */ LONG lBlockNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcOperation_Search_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcOperation_SelectMode_Proxy( 
    IEZNcOperation __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lMode,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcOperation_SelectMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcOperation_Run_Proxy( 
    IEZNcOperation __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcOperation_Run_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcOperation_Stop_Proxy( 
    IEZNcOperation __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcOperation_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcOperation_INTERFACE_DEFINED__ */


#ifndef __IEZNcCommand_INTERFACE_DEFINED__
#define __IEZNcCommand_INTERFACE_DEFINED__

/* interface IEZNcCommand */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcCommand;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8A9-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcCommand : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetGCodeCommand( 
            /* [in] */ LONG lType,
            /* [out] */ DOUBLE __RPC_FAR *pdValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetToolCommand( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetFeedCommand( 
            /* [in] */ LONG lType,
            /* [out] */ DOUBLE __RPC_FAR *pdValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCommand( 
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCommand( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lType,
            /* [in] */ LONG lValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CommandRegister( 
            /* [in] */ LONG lPriority,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CommandCancel( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcCommandVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcCommand __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcCommand __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGCodeCommand )( 
            IEZNcCommand __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [out] */ DOUBLE __RPC_FAR *pdValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolCommand )( 
            IEZNcCommand __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFeedCommand )( 
            IEZNcCommand __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [out] */ DOUBLE __RPC_FAR *pdValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommand )( 
            IEZNcCommand __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCommand )( 
            IEZNcCommand __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lType,
            /* [in] */ LONG lValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CommandRegister )( 
            IEZNcCommand __RPC_FAR * This,
            /* [in] */ LONG lPriority,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CommandCancel )( 
            IEZNcCommand __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcCommandVtbl;

    interface IEZNcCommand
    {
        CONST_VTBL struct IEZNcCommandVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcCommand_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcCommand_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcCommand_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcCommand_GetGCodeCommand(This,lType,pdValue,plRet)	\
    (This)->lpVtbl -> GetGCodeCommand(This,lType,pdValue,plRet)

#define IEZNcCommand_GetToolCommand(This,lAxisNo,lType,plValue,plRet)	\
    (This)->lpVtbl -> GetToolCommand(This,lAxisNo,lType,plValue,plRet)

#define IEZNcCommand_GetFeedCommand(This,lType,pdValue,plRet)	\
    (This)->lpVtbl -> GetFeedCommand(This,lType,pdValue,plRet)

#define IEZNcCommand_GetCommand(This,lType,plValue,plRet)	\
    (This)->lpVtbl -> GetCommand(This,lType,plValue,plRet)

#define IEZNcCommand_SetCommand(This,lAxisNo,lType,lValue,plRet)	\
    (This)->lpVtbl -> SetCommand(This,lAxisNo,lType,lValue,plRet)

#define IEZNcCommand_CommandRegister(This,lPriority,plRet)	\
    (This)->lpVtbl -> CommandRegister(This,lPriority,plRet)

#define IEZNcCommand_CommandCancel(This,plRet)	\
    (This)->lpVtbl -> CommandCancel(This,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommand_GetGCodeCommand_Proxy( 
    IEZNcCommand __RPC_FAR * This,
    /* [in] */ LONG lType,
    /* [out] */ DOUBLE __RPC_FAR *pdValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommand_GetGCodeCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommand_GetToolCommand_Proxy( 
    IEZNcCommand __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lType,
    /* [out] */ LONG __RPC_FAR *plValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommand_GetToolCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommand_GetFeedCommand_Proxy( 
    IEZNcCommand __RPC_FAR * This,
    /* [in] */ LONG lType,
    /* [out] */ DOUBLE __RPC_FAR *pdValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommand_GetFeedCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommand_GetCommand_Proxy( 
    IEZNcCommand __RPC_FAR * This,
    /* [in] */ LONG lType,
    /* [out] */ LONG __RPC_FAR *plValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommand_GetCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommand_SetCommand_Proxy( 
    IEZNcCommand __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lType,
    /* [in] */ LONG lValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommand_SetCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommand_CommandRegister_Proxy( 
    IEZNcCommand __RPC_FAR * This,
    /* [in] */ LONG lPriority,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommand_CommandRegister_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommand_CommandCancel_Proxy( 
    IEZNcCommand __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommand_CommandCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcCommand_INTERFACE_DEFINED__ */


#ifndef __IEZNcCommonVariable_INTERFACE_DEFINED__
#define __IEZNcCommonVariable_INTERFACE_DEFINED__

/* interface IEZNcCommonVariable */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcCommonVariable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8AA-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcCommonVariable : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CVRead( 
            /* [in] */ LONG lIndex,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CVWrite( 
            /* [in] */ LONG lIndex,
            /* [in] */ DOUBLE dData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSize( 
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszName,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ LONG lIndex,
            /* [string][in] */ LPCOLESTR lpcwszName,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCVNullData( 
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcCommonVariableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcCommonVariable __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcCommonVariable __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcCommonVariable __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CVRead )( 
            IEZNcCommonVariable __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CVWrite )( 
            IEZNcCommonVariable __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ DOUBLE dData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IEZNcCommonVariable __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IEZNcCommonVariable __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName )( 
            IEZNcCommonVariable __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [string][in] */ LPCOLESTR lpcwszName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCVNullData )( 
            IEZNcCommonVariable __RPC_FAR * This,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcCommonVariableVtbl;

    interface IEZNcCommonVariable
    {
        CONST_VTBL struct IEZNcCommonVariableVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcCommonVariable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcCommonVariable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcCommonVariable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcCommonVariable_CVRead(This,lIndex,pdData,plRet)	\
    (This)->lpVtbl -> CVRead(This,lIndex,pdData,plRet)

#define IEZNcCommonVariable_CVWrite(This,lIndex,dData,plRet)	\
    (This)->lpVtbl -> CVWrite(This,lIndex,dData,plRet)

#define IEZNcCommonVariable_GetSize(This,lType,plData,plRet)	\
    (This)->lpVtbl -> GetSize(This,lType,plData,plRet)

#define IEZNcCommonVariable_GetName(This,lIndex,lppwszName,plRet)	\
    (This)->lpVtbl -> GetName(This,lIndex,lppwszName,plRet)

#define IEZNcCommonVariable_SetName(This,lIndex,lpcwszName,plRet)	\
    (This)->lpVtbl -> SetName(This,lIndex,lpcwszName,plRet)

#define IEZNcCommonVariable_GetCVNullData(This,pdData,plRet)	\
    (This)->lpVtbl -> GetCVNullData(This,pdData,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommonVariable_CVRead_Proxy( 
    IEZNcCommonVariable __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ DOUBLE __RPC_FAR *pdData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommonVariable_CVRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommonVariable_CVWrite_Proxy( 
    IEZNcCommonVariable __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ DOUBLE dData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommonVariable_CVWrite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommonVariable_GetSize_Proxy( 
    IEZNcCommonVariable __RPC_FAR * This,
    /* [in] */ LONG lType,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommonVariable_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommonVariable_GetName_Proxy( 
    IEZNcCommonVariable __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszName,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommonVariable_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommonVariable_SetName_Proxy( 
    IEZNcCommonVariable __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [string][in] */ LPCOLESTR lpcwszName,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommonVariable_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommonVariable_GetCVNullData_Proxy( 
    IEZNcCommonVariable __RPC_FAR * This,
    /* [out] */ DOUBLE __RPC_FAR *pdData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommonVariable_GetCVNullData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcCommonVariable_INTERFACE_DEFINED__ */


#ifndef __IEZNcLocalVariable_INTERFACE_DEFINED__
#define __IEZNcLocalVariable_INTERFACE_DEFINED__

/* interface IEZNcLocalVariable */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcLocalVariable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("C00179B1-0446-11d4-898D-0050DA895B01")
    interface IEZNcLocalVariable : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE LVRead( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lLevel,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMacroLevel( 
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLVNullData( 
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcLocalVariableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcLocalVariable __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcLocalVariable __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcLocalVariable __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LVRead )( 
            IEZNcLocalVariable __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lLevel,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMacroLevel )( 
            IEZNcLocalVariable __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLVNullData )( 
            IEZNcLocalVariable __RPC_FAR * This,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcLocalVariableVtbl;

    interface IEZNcLocalVariable
    {
        CONST_VTBL struct IEZNcLocalVariableVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcLocalVariable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcLocalVariable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcLocalVariable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcLocalVariable_LVRead(This,lIndex,lLevel,pdData,plRet)	\
    (This)->lpVtbl -> LVRead(This,lIndex,lLevel,pdData,plRet)

#define IEZNcLocalVariable_GetMacroLevel(This,plData,plRet)	\
    (This)->lpVtbl -> GetMacroLevel(This,plData,plRet)

#define IEZNcLocalVariable_GetLVNullData(This,pdData,plRet)	\
    (This)->lpVtbl -> GetLVNullData(This,pdData,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcLocalVariable_LVRead_Proxy( 
    IEZNcLocalVariable __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lLevel,
    /* [out] */ DOUBLE __RPC_FAR *pdData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcLocalVariable_LVRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcLocalVariable_GetMacroLevel_Proxy( 
    IEZNcLocalVariable __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcLocalVariable_GetMacroLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcLocalVariable_GetLVNullData_Proxy( 
    IEZNcLocalVariable __RPC_FAR * This,
    /* [out] */ DOUBLE __RPC_FAR *pdData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcLocalVariable_GetLVNullData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcLocalVariable_INTERFACE_DEFINED__ */


#ifndef __IEZNcAxisMonitor_INTERFACE_DEFINED__
#define __IEZNcAxisMonitor_INTERFACE_DEFINED__

/* interface IEZNcAxisMonitor */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcAxisMonitor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8AB-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcAxisMonitor : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetServoMonitor( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSpindleMonitor( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lSpindle,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MonitorRegister( 
            /* [in] */ LONG lPriority,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE MonitorCancel( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetServoVersion( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetServoDiagnosis( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPowerVersion( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPowerDiagnosis( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSpindleVersion( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSpindleDiagnosis( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSynchroTolerance( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAbsPositionMonitor( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAbsPositionInit( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSAnalogAdjust( 
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSAnalogAdjust( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAuxAxisMonitor( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAuxAxisDiagnosis( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAuxAxisVersion( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Clear( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAuxAxisOpeMonitor( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDowelTime( 
            /* [out] */ DOUBLE __RPC_FAR *pdTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPowerConsumption( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *__RPC_FAR *ppdPower,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetIntegralPower( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ DOUBLE __RPC_FAR *__RPC_FAR *ppdPower,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcAxisMonitorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcAxisMonitor __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcAxisMonitor __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetServoMonitor )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpindleMonitor )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lSpindle,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MonitorRegister )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lPriority,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MonitorCancel )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetServoVersion )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetServoDiagnosis )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPowerVersion )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPowerDiagnosis )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpindleVersion )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpindleDiagnosis )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSynchroTolerance )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAbsPositionMonitor )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAbsPositionInit )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSAnalogAdjust )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSAnalogAdjust )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAuxAxisMonitor )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAuxAxisDiagnosis )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAuxAxisVersion )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Clear )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAuxAxisOpeMonitor )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDowelTime )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [out] */ DOUBLE __RPC_FAR *pdTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPowerConsumption )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *__RPC_FAR *ppdPower,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIntegralPower )( 
            IEZNcAxisMonitor __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ DOUBLE __RPC_FAR *__RPC_FAR *ppdPower,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcAxisMonitorVtbl;

    interface IEZNcAxisMonitor
    {
        CONST_VTBL struct IEZNcAxisMonitorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcAxisMonitor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcAxisMonitor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcAxisMonitor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcAxisMonitor_GetServoMonitor(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetServoMonitor(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)

#define IEZNcAxisMonitor_GetSpindleMonitor(This,lIndex,lSpindle,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetSpindleMonitor(This,lIndex,lSpindle,plData,lppwszBuffer,plRet)

#define IEZNcAxisMonitor_MonitorRegister(This,lPriority,plRet)	\
    (This)->lpVtbl -> MonitorRegister(This,lPriority,plRet)

#define IEZNcAxisMonitor_MonitorCancel(This,plRet)	\
    (This)->lpVtbl -> MonitorCancel(This,plRet)

#define IEZNcAxisMonitor_GetServoVersion(This,lAxisNo,lIndex,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetServoVersion(This,lAxisNo,lIndex,lppwszBuffer,plRet)

#define IEZNcAxisMonitor_GetServoDiagnosis(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetServoDiagnosis(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)

#define IEZNcAxisMonitor_GetPowerVersion(This,lAxisNo,lIndex,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetPowerVersion(This,lAxisNo,lIndex,lppwszBuffer,plRet)

#define IEZNcAxisMonitor_GetPowerDiagnosis(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetPowerDiagnosis(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)

#define IEZNcAxisMonitor_GetSpindleVersion(This,lAxisNo,lIndex,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetSpindleVersion(This,lAxisNo,lIndex,lppwszBuffer,plRet)

#define IEZNcAxisMonitor_GetSpindleDiagnosis(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetSpindleDiagnosis(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)

#define IEZNcAxisMonitor_GetSynchroTolerance(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetSynchroTolerance(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)

#define IEZNcAxisMonitor_GetAbsPositionMonitor(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetAbsPositionMonitor(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)

#define IEZNcAxisMonitor_SetAbsPositionInit(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetAbsPositionInit(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcAxisMonitor_GetSAnalogAdjust(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetSAnalogAdjust(This,lIndex,plData,plRet)

#define IEZNcAxisMonitor_SetSAnalogAdjust(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetSAnalogAdjust(This,lIndex,lData,plRet)

#define IEZNcAxisMonitor_GetAuxAxisMonitor(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetAuxAxisMonitor(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)

#define IEZNcAxisMonitor_GetAuxAxisDiagnosis(This,lAxisNo,lIndex,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetAuxAxisDiagnosis(This,lAxisNo,lIndex,lppwszBuffer,plRet)

#define IEZNcAxisMonitor_GetAuxAxisVersion(This,lAxisNo,lIndex,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetAuxAxisVersion(This,lAxisNo,lIndex,lppwszBuffer,plRet)

#define IEZNcAxisMonitor_Clear(This,lAxisNo,lIndex,plRet)	\
    (This)->lpVtbl -> Clear(This,lAxisNo,lIndex,plRet)

#define IEZNcAxisMonitor_GetAuxAxisOpeMonitor(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetAuxAxisOpeMonitor(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcAxisMonitor_GetDowelTime(This,pdTime,plRet)	\
    (This)->lpVtbl -> GetDowelTime(This,pdTime,plRet)

#define IEZNcAxisMonitor_GetPowerConsumption(This,lAxisNo,ppdPower,plRet)	\
    (This)->lpVtbl -> GetPowerConsumption(This,lAxisNo,ppdPower,plRet)

#define IEZNcAxisMonitor_GetIntegralPower(This,lAxisNo,lIndex,ppdPower,plRet)	\
    (This)->lpVtbl -> GetIntegralPower(This,lAxisNo,lIndex,ppdPower,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetServoMonitor_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetServoMonitor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetSpindleMonitor_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lSpindle,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetSpindleMonitor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_MonitorRegister_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lPriority,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_MonitorRegister_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_MonitorCancel_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_MonitorCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetServoVersion_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetServoVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetServoDiagnosis_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetServoDiagnosis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetPowerVersion_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetPowerVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetPowerDiagnosis_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetPowerDiagnosis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetSpindleVersion_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetSpindleVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetSpindleDiagnosis_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetSpindleDiagnosis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetSynchroTolerance_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetSynchroTolerance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetAbsPositionMonitor_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetAbsPositionMonitor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_SetAbsPositionInit_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_SetAbsPositionInit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetSAnalogAdjust_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetSAnalogAdjust_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_SetSAnalogAdjust_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_SetSAnalogAdjust_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetAuxAxisMonitor_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetAuxAxisMonitor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetAuxAxisDiagnosis_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetAuxAxisDiagnosis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetAuxAxisVersion_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetAuxAxisVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_Clear_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_Clear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetAuxAxisOpeMonitor_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetAuxAxisOpeMonitor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetDowelTime_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [out] */ DOUBLE __RPC_FAR *pdTime,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetDowelTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetPowerConsumption_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *__RPC_FAR *ppdPower,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetPowerConsumption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcAxisMonitor_GetIntegralPower_Proxy( 
    IEZNcAxisMonitor __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ DOUBLE __RPC_FAR *__RPC_FAR *ppdPower,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcAxisMonitor_GetIntegralPower_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcAxisMonitor_INTERFACE_DEFINED__ */


#ifndef __IEZNcTool_INTERFACE_DEFINED__
#define __IEZNcTool_INTERFACE_DEFINED__

/* interface IEZNcTool */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcTool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8AD-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcTool : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetToolSetSize( 
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetType( 
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetOffset( 
            /* [in] */ LONG lType,
            /* [in] */ LONG lKind,
            /* [in] */ LONG lToolSetNo,
            /* [out] */ DOUBLE __RPC_FAR *pdOffset,
            /* [out] */ LONG __RPC_FAR *plNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetOffset( 
            /* [in] */ LONG lType,
            /* [in] */ LONG lKind,
            /* [in] */ LONG lToolSetNo,
            /* [in] */ DOUBLE dOffset,
            /* [in] */ LONG lNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSurface( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdHight,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSurface( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ DOUBLE dHight,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetATCControl( 
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetATCSize( 
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetATCReady( 
            /* [in] */ LONG lReady,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetATCPot( 
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetATCPot( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetATCPotEx( 
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetATCPotEx( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetATCAux( 
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetATCAux( 
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetToolLifeType( 
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetToolLifeType( 
            /* [in] */ LONG lType,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE GetToolLifeData( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE SetToolLifeData( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcToolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcTool __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcTool __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcTool __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolSetSize )( 
            IEZNcTool __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetType )( 
            IEZNcTool __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOffset )( 
            IEZNcTool __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [in] */ LONG lKind,
            /* [in] */ LONG lToolSetNo,
            /* [out] */ DOUBLE __RPC_FAR *pdOffset,
            /* [out] */ LONG __RPC_FAR *plNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOffset )( 
            IEZNcTool __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [in] */ LONG lKind,
            /* [in] */ LONG lToolSetNo,
            /* [in] */ DOUBLE dOffset,
            /* [in] */ LONG lNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSurface )( 
            IEZNcTool __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdHight,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSurface )( 
            IEZNcTool __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ DOUBLE dHight,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCControl )( 
            IEZNcTool __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCSize )( 
            IEZNcTool __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCReady )( 
            IEZNcTool __RPC_FAR * This,
            /* [in] */ LONG lReady,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCPot )( 
            IEZNcTool __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetATCPot )( 
            IEZNcTool __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCPotEx )( 
            IEZNcTool __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetATCPotEx )( 
            IEZNcTool __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCAux )( 
            IEZNcTool __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetATCAux )( 
            IEZNcTool __RPC_FAR * This,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeType )( 
            IEZNcTool __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeType )( 
            IEZNcTool __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeData )( 
            IEZNcTool __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeData )( 
            IEZNcTool __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcToolVtbl;

    interface IEZNcTool
    {
        CONST_VTBL struct IEZNcToolVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcTool_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcTool_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcTool_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcTool_GetToolSetSize(This,plSize,plRet)	\
    (This)->lpVtbl -> GetToolSetSize(This,plSize,plRet)

#define IEZNcTool_GetType(This,plType,plRet)	\
    (This)->lpVtbl -> GetType(This,plType,plRet)

#define IEZNcTool_GetOffset(This,lType,lKind,lToolSetNo,pdOffset,plNo,plRet)	\
    (This)->lpVtbl -> GetOffset(This,lType,lKind,lToolSetNo,pdOffset,plNo,plRet)

#define IEZNcTool_SetOffset(This,lType,lKind,lToolSetNo,dOffset,lNo,plRet)	\
    (This)->lpVtbl -> SetOffset(This,lType,lKind,lToolSetNo,dOffset,lNo,plRet)

#define IEZNcTool_GetSurface(This,lAxisNo,pdHight,plRet)	\
    (This)->lpVtbl -> GetSurface(This,lAxisNo,pdHight,plRet)

#define IEZNcTool_SetSurface(This,lAxisNo,dHight,plRet)	\
    (This)->lpVtbl -> SetSurface(This,lAxisNo,dHight,plRet)

#define IEZNcTool_GetATCControl(This,plData,plRet)	\
    (This)->lpVtbl -> GetATCControl(This,plData,plRet)

#define IEZNcTool_GetATCSize(This,plSize,plRet)	\
    (This)->lpVtbl -> GetATCSize(This,plSize,plRet)

#define IEZNcTool_GetATCReady(This,lReady,plToolNo,plRet)	\
    (This)->lpVtbl -> GetATCReady(This,lReady,plToolNo,plRet)

#define IEZNcTool_GetATCPot(This,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetATCPot(This,lIndex,plToolNo,plRet)

#define IEZNcTool_SetATCPot(This,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetATCPot(This,lIndex,lToolNo,plRet)

#define IEZNcTool_GetATCPotEx(This,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetATCPotEx(This,lIndex,plToolNo,plRet)

#define IEZNcTool_SetATCPotEx(This,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetATCPotEx(This,lIndex,lToolNo,plRet)

#define IEZNcTool_GetATCAux(This,plData,plRet)	\
    (This)->lpVtbl -> GetATCAux(This,plData,plRet)

#define IEZNcTool_SetATCAux(This,lData,plRet)	\
    (This)->lpVtbl -> SetATCAux(This,lData,plRet)

#define IEZNcTool_GetToolLifeType(This,plType,plRet)	\
    (This)->lpVtbl -> GetToolLifeType(This,plType,plRet)

#define IEZNcTool_SetToolLifeType(This,lType,plRet)	\
    (This)->lpVtbl -> SetToolLifeType(This,lType,plRet)

#define IEZNcTool_GetToolLifeData(This,plRet)	\
    (This)->lpVtbl -> GetToolLifeData(This,plRet)

#define IEZNcTool_SetToolLifeData(This,plRet)	\
    (This)->lpVtbl -> SetToolLifeData(This,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_GetToolSetSize_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plSize,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_GetToolSetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_GetType_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plType,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_GetOffset_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [in] */ LONG lType,
    /* [in] */ LONG lKind,
    /* [in] */ LONG lToolSetNo,
    /* [out] */ DOUBLE __RPC_FAR *pdOffset,
    /* [out] */ LONG __RPC_FAR *plNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_GetOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_SetOffset_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [in] */ LONG lType,
    /* [in] */ LONG lKind,
    /* [in] */ LONG lToolSetNo,
    /* [in] */ DOUBLE dOffset,
    /* [in] */ LONG lNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_SetOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_GetSurface_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdHight,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_GetSurface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_SetSurface_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ DOUBLE dHight,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_SetSurface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_GetATCControl_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_GetATCControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_GetATCSize_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plSize,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_GetATCSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_GetATCReady_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [in] */ LONG lReady,
    /* [out] */ LONG __RPC_FAR *plToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_GetATCReady_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_GetATCPot_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_GetATCPot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_SetATCPot_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_SetATCPot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_GetATCPotEx_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_GetATCPotEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_SetATCPotEx_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_SetATCPotEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_GetATCAux_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_GetATCAux_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_SetATCAux_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_SetATCAux_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_GetToolLifeType_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plType,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_GetToolLifeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_SetToolLifeType_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [in] */ LONG lType,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_SetToolLifeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_GetToolLifeData_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_GetToolLifeData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool_SetToolLifeData_Proxy( 
    IEZNcTool __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool_SetToolLifeData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcTool_INTERFACE_DEFINED__ */


#ifndef __IEZNcParameter_INTERFACE_DEFINED__
#define __IEZNcParameter_INTERFACE_DEFINED__

/* interface IEZNcParameter */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcParameter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8AE-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcParameter : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProcessParameter( 
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetProcessParameter( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetControlParameter( 
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetControlParameter( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAxisParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAxisParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetBarrierData( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plDataX,
            /* [out] */ LONG __RPC_FAR *plDataZ,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetBarrierData( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDataX,
            /* [in] */ LONG lDataZ,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetIoParameter( 
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetIoParameter( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSerialParameter( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDeviceNo,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszDeviceName,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSerialParameter( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDeviceNo,
            /* [in] */ LONG lData,
            /* [string][in] */ LPCOLESTR lpcwszDeviceName,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetWorkOffset( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plOffset,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetWorkOffset( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lOffset,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPositionSwitch( 
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plDog1,
            /* [out] */ LONG __RPC_FAR *plDog2,
            /* [out] */ LONG __RPC_FAR *plAxisName,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetPositionSwitch( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDog1,
            /* [in] */ LONG lDog2,
            /* [in] */ LONG lAxisName,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetBaseParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetBaseParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [string][in] */ LPCOLESTR lpcwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAxisSpecParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAxisSpecParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetToleranceParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetToleranceParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAuxParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAuxParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPlcParameter( 
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetPlcParameter( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMacroParameter( 
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetMacroParameter( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAuxAxisParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetAuxAxisParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [string][in] */ LPCOLESTR lpcwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetServoParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetServoParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSPJParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSPJParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSpindleParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSpindleParameter( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcParameterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcParameter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcParameter __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProcessParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProcessParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetControlParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetControlParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAxisParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAxisParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBarrierData )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plDataX,
            /* [out] */ LONG __RPC_FAR *plDataZ,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBarrierData )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDataX,
            /* [in] */ LONG lDataZ,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIoParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIoParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSerialParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDeviceNo,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszDeviceName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSerialParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDeviceNo,
            /* [in] */ LONG lData,
            /* [string][in] */ LPCOLESTR lpcwszDeviceName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWorkOffset )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plOffset,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetWorkOffset )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lOffset,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPositionSwitch )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plDog1,
            /* [out] */ LONG __RPC_FAR *plDog2,
            /* [out] */ LONG __RPC_FAR *plAxisName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPositionSwitch )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDog1,
            /* [in] */ LONG lDog2,
            /* [in] */ LONG lAxisName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBaseParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBaseParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [string][in] */ LPCOLESTR lpcwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAxisSpecParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAxisSpecParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToleranceParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToleranceParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAuxParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAuxParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPlcParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPlcParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMacroParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMacroParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAuxAxisParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAuxAxisParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [string][in] */ LPCOLESTR lpcwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetServoParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetServoParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSPJParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSPJParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpindleParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSpindleParameter )( 
            IEZNcParameter __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcParameterVtbl;

    interface IEZNcParameter
    {
        CONST_VTBL struct IEZNcParameterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcParameter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcParameter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcParameter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcParameter_GetProcessParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetProcessParameter(This,lIndex,plData,plRet)

#define IEZNcParameter_SetProcessParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetProcessParameter(This,lIndex,lData,plRet)

#define IEZNcParameter_GetControlParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetControlParameter(This,lIndex,plData,plRet)

#define IEZNcParameter_SetControlParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetControlParameter(This,lIndex,lData,plRet)

#define IEZNcParameter_GetAxisParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetAxisParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter_SetAxisParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetAxisParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter_GetBarrierData(This,lAxisNo,lIndex,plDataX,plDataZ,plRet)	\
    (This)->lpVtbl -> GetBarrierData(This,lAxisNo,lIndex,plDataX,plDataZ,plRet)

#define IEZNcParameter_SetBarrierData(This,lAxisNo,lIndex,lDataX,lDataZ,plRet)	\
    (This)->lpVtbl -> SetBarrierData(This,lAxisNo,lIndex,lDataX,lDataZ,plRet)

#define IEZNcParameter_GetIoParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetIoParameter(This,lIndex,plData,plRet)

#define IEZNcParameter_SetIoParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetIoParameter(This,lIndex,lData,plRet)

#define IEZNcParameter_GetSerialParameter(This,lIndex,lDeviceNo,plData,lppwszDeviceName,plRet)	\
    (This)->lpVtbl -> GetSerialParameter(This,lIndex,lDeviceNo,plData,lppwszDeviceName,plRet)

#define IEZNcParameter_SetSerialParameter(This,lIndex,lDeviceNo,lData,lpcwszDeviceName,plRet)	\
    (This)->lpVtbl -> SetSerialParameter(This,lIndex,lDeviceNo,lData,lpcwszDeviceName,plRet)

#define IEZNcParameter_GetWorkOffset(This,lAxisNo,lIndex,plOffset,plRet)	\
    (This)->lpVtbl -> GetWorkOffset(This,lAxisNo,lIndex,plOffset,plRet)

#define IEZNcParameter_SetWorkOffset(This,lAxisNo,lIndex,lOffset,lMode,plRet)	\
    (This)->lpVtbl -> SetWorkOffset(This,lAxisNo,lIndex,lOffset,lMode,plRet)

#define IEZNcParameter_GetPositionSwitch(This,lIndex,plDog1,plDog2,plAxisName,plRet)	\
    (This)->lpVtbl -> GetPositionSwitch(This,lIndex,plDog1,plDog2,plAxisName,plRet)

#define IEZNcParameter_SetPositionSwitch(This,lIndex,lDog1,lDog2,lAxisName,plRet)	\
    (This)->lpVtbl -> SetPositionSwitch(This,lIndex,lDog1,lDog2,lAxisName,plRet)

#define IEZNcParameter_GetBaseParameter(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetBaseParameter(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)

#define IEZNcParameter_SetBaseParameter(This,lAxisNo,lIndex,lData,lpcwszBuffer,plRet)	\
    (This)->lpVtbl -> SetBaseParameter(This,lAxisNo,lIndex,lData,lpcwszBuffer,plRet)

#define IEZNcParameter_GetAxisSpecParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetAxisSpecParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter_SetAxisSpecParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetAxisSpecParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter_GetToleranceParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetToleranceParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter_SetToleranceParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetToleranceParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter_GetAuxParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetAuxParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter_SetAuxParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetAuxParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter_GetPlcParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetPlcParameter(This,lIndex,plData,plRet)

#define IEZNcParameter_SetPlcParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetPlcParameter(This,lIndex,lData,plRet)

#define IEZNcParameter_GetMacroParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetMacroParameter(This,lIndex,plData,plRet)

#define IEZNcParameter_SetMacroParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetMacroParameter(This,lIndex,lData,plRet)

#define IEZNcParameter_GetAuxAxisParameter(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetAuxAxisParameter(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)

#define IEZNcParameter_SetAuxAxisParameter(This,lAxisNo,lIndex,lData,lpcwszBuffer,plRet)	\
    (This)->lpVtbl -> SetAuxAxisParameter(This,lAxisNo,lIndex,lData,lpcwszBuffer,plRet)

#define IEZNcParameter_GetServoParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetServoParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter_SetServoParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetServoParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter_GetSPJParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetSPJParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter_SetSPJParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetSPJParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter_GetSpindleParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetSpindleParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter_SetSpindleParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetSpindleParameter(This,lAxisNo,lIndex,lData,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetProcessParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetProcessParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetProcessParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetProcessParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetControlParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetControlParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetControlParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetControlParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetAxisParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetAxisParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetAxisParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetAxisParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetBarrierData_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plDataX,
    /* [out] */ LONG __RPC_FAR *plDataZ,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetBarrierData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetBarrierData_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lDataX,
    /* [in] */ LONG lDataZ,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetBarrierData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetIoParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetIoParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetIoParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetIoParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetSerialParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lDeviceNo,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszDeviceName,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetSerialParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetSerialParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lDeviceNo,
    /* [in] */ LONG lData,
    /* [string][in] */ LPCOLESTR lpcwszDeviceName,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetSerialParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetWorkOffset_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plOffset,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetWorkOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetWorkOffset_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lOffset,
    /* [in] */ LONG lMode,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetWorkOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetPositionSwitch_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plDog1,
    /* [out] */ LONG __RPC_FAR *plDog2,
    /* [out] */ LONG __RPC_FAR *plAxisName,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetPositionSwitch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetPositionSwitch_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lDog1,
    /* [in] */ LONG lDog2,
    /* [in] */ LONG lAxisName,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetPositionSwitch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetBaseParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetBaseParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetBaseParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [string][in] */ LPCOLESTR lpcwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetBaseParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetAxisSpecParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetAxisSpecParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetAxisSpecParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetAxisSpecParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetToleranceParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetToleranceParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetToleranceParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetToleranceParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetAuxParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetAuxParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetAuxParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetAuxParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetPlcParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetPlcParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetPlcParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetPlcParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetMacroParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetMacroParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetMacroParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetMacroParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetAuxAxisParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetAuxAxisParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetAuxAxisParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [string][in] */ LPCOLESTR lpcwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetAuxAxisParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetServoParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetServoParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetServoParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetServoParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetSPJParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetSPJParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetSPJParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetSPJParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_GetSpindleParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_GetSpindleParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter_SetSpindleParameter_Proxy( 
    IEZNcParameter __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter_SetSpindleParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcParameter_INTERFACE_DEFINED__ */


#ifndef __IEZNcGeneric_INTERFACE_DEFINED__
#define __IEZNcGeneric_INTERFACE_DEFINED__

/* interface IEZNcGeneric */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcGeneric;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B272F8AF-FE59-11d3-A28E-00101E002AAB")
    interface IEZNcGeneric : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadData( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lSectionNum,
            /* [in] */ LONG lSubSectionNum,
            /* [out][in] */ VARIANT __RPC_FAR *pvReadData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WriteData( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lSectionNum,
            /* [in] */ LONG lSubSectionNum,
            /* [in] */ VARIANT vWriteData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcGenericVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcGeneric __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcGeneric __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcGeneric __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadData )( 
            IEZNcGeneric __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lSectionNum,
            /* [in] */ LONG lSubSectionNum,
            /* [out][in] */ VARIANT __RPC_FAR *pvReadData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteData )( 
            IEZNcGeneric __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lSectionNum,
            /* [in] */ LONG lSubSectionNum,
            /* [in] */ VARIANT vWriteData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcGenericVtbl;

    interface IEZNcGeneric
    {
        CONST_VTBL struct IEZNcGenericVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcGeneric_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcGeneric_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcGeneric_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcGeneric_ReadData(This,lAxisNo,lSectionNum,lSubSectionNum,pvReadData,plRet)	\
    (This)->lpVtbl -> ReadData(This,lAxisNo,lSectionNum,lSubSectionNum,pvReadData,plRet)

#define IEZNcGeneric_WriteData(This,lAxisNo,lSectionNum,lSubSectionNum,vWriteData,plRet)	\
    (This)->lpVtbl -> WriteData(This,lAxisNo,lSectionNum,lSubSectionNum,vWriteData,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcGeneric_ReadData_Proxy( 
    IEZNcGeneric __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lSectionNum,
    /* [in] */ LONG lSubSectionNum,
    /* [out][in] */ VARIANT __RPC_FAR *pvReadData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcGeneric_ReadData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcGeneric_WriteData_Proxy( 
    IEZNcGeneric __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lSectionNum,
    /* [in] */ LONG lSubSectionNum,
    /* [in] */ VARIANT vWriteData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcGeneric_WriteData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcGeneric_INTERFACE_DEFINED__ */


#ifndef __IEZNcCommonVariable2_INTERFACE_DEFINED__
#define __IEZNcCommonVariable2_INTERFACE_DEFINED__

/* interface IEZNcCommonVariable2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcCommonVariable2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("C29040E0-BEA4-11d4-A2AF-00A0245B34C6")
    interface IEZNcCommonVariable2 : public IEZNcCommonVariable
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CommonVRead( 
            /* [in] */ LONG lIndex,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CommonVWrite( 
            /* [in] */ LONG lIndex,
            /* [in] */ DOUBLE dData,
            /* [in] */ LONG lType,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcCommonVariable2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcCommonVariable2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcCommonVariable2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcCommonVariable2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CVRead )( 
            IEZNcCommonVariable2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CVWrite )( 
            IEZNcCommonVariable2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ DOUBLE dData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSize )( 
            IEZNcCommonVariable2 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName )( 
            IEZNcCommonVariable2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName )( 
            IEZNcCommonVariable2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [string][in] */ LPCOLESTR lpcwszName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCVNullData )( 
            IEZNcCommonVariable2 __RPC_FAR * This,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CommonVRead )( 
            IEZNcCommonVariable2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CommonVWrite )( 
            IEZNcCommonVariable2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ DOUBLE dData,
            /* [in] */ LONG lType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcCommonVariable2Vtbl;

    interface IEZNcCommonVariable2
    {
        CONST_VTBL struct IEZNcCommonVariable2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcCommonVariable2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcCommonVariable2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcCommonVariable2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcCommonVariable2_CVRead(This,lIndex,pdData,plRet)	\
    (This)->lpVtbl -> CVRead(This,lIndex,pdData,plRet)

#define IEZNcCommonVariable2_CVWrite(This,lIndex,dData,plRet)	\
    (This)->lpVtbl -> CVWrite(This,lIndex,dData,plRet)

#define IEZNcCommonVariable2_GetSize(This,lType,plData,plRet)	\
    (This)->lpVtbl -> GetSize(This,lType,plData,plRet)

#define IEZNcCommonVariable2_GetName(This,lIndex,lppwszName,plRet)	\
    (This)->lpVtbl -> GetName(This,lIndex,lppwszName,plRet)

#define IEZNcCommonVariable2_SetName(This,lIndex,lpcwszName,plRet)	\
    (This)->lpVtbl -> SetName(This,lIndex,lpcwszName,plRet)

#define IEZNcCommonVariable2_GetCVNullData(This,pdData,plRet)	\
    (This)->lpVtbl -> GetCVNullData(This,pdData,plRet)


#define IEZNcCommonVariable2_CommonVRead(This,lIndex,pdData,plType,plRet)	\
    (This)->lpVtbl -> CommonVRead(This,lIndex,pdData,plType,plRet)

#define IEZNcCommonVariable2_CommonVWrite(This,lIndex,dData,lType,plRet)	\
    (This)->lpVtbl -> CommonVWrite(This,lIndex,dData,lType,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommonVariable2_CommonVRead_Proxy( 
    IEZNcCommonVariable2 __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ DOUBLE __RPC_FAR *pdData,
    /* [out] */ LONG __RPC_FAR *plType,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommonVariable2_CommonVRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommonVariable2_CommonVWrite_Proxy( 
    IEZNcCommonVariable2 __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ DOUBLE dData,
    /* [in] */ LONG lType,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommonVariable2_CommonVWrite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcCommonVariable2_INTERFACE_DEFINED__ */


#ifndef __IEZNcLocalVariable2_INTERFACE_DEFINED__
#define __IEZNcLocalVariable2_INTERFACE_DEFINED__

/* interface IEZNcLocalVariable2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcLocalVariable2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("20316502-BEA3-11d4-A2AF-00A0245B34C6")
    interface IEZNcLocalVariable2 : public IEZNcLocalVariable
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE LocalVRead( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lLevel,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcLocalVariable2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcLocalVariable2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcLocalVariable2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcLocalVariable2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LVRead )( 
            IEZNcLocalVariable2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lLevel,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMacroLevel )( 
            IEZNcLocalVariable2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLVNullData )( 
            IEZNcLocalVariable2 __RPC_FAR * This,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LocalVRead )( 
            IEZNcLocalVariable2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lLevel,
            /* [out] */ DOUBLE __RPC_FAR *pdData,
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcLocalVariable2Vtbl;

    interface IEZNcLocalVariable2
    {
        CONST_VTBL struct IEZNcLocalVariable2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcLocalVariable2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcLocalVariable2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcLocalVariable2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcLocalVariable2_LVRead(This,lIndex,lLevel,pdData,plRet)	\
    (This)->lpVtbl -> LVRead(This,lIndex,lLevel,pdData,plRet)

#define IEZNcLocalVariable2_GetMacroLevel(This,plData,plRet)	\
    (This)->lpVtbl -> GetMacroLevel(This,plData,plRet)

#define IEZNcLocalVariable2_GetLVNullData(This,pdData,plRet)	\
    (This)->lpVtbl -> GetLVNullData(This,pdData,plRet)


#define IEZNcLocalVariable2_LocalVRead(This,lIndex,lLevel,pdData,plType,plRet)	\
    (This)->lpVtbl -> LocalVRead(This,lIndex,lLevel,pdData,plType,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcLocalVariable2_LocalVRead_Proxy( 
    IEZNcLocalVariable2 __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lLevel,
    /* [out] */ DOUBLE __RPC_FAR *pdData,
    /* [out] */ LONG __RPC_FAR *plType,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcLocalVariable2_LocalVRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcLocalVariable2_INTERFACE_DEFINED__ */


#ifndef __IEZNcTool2_INTERFACE_DEFINED__
#define __IEZNcTool2_INTERFACE_DEFINED__

/* interface IEZNcTool2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcTool2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("1BCB76D1-BEA5-11d4-A2AF-00A0245B34C6")
    interface IEZNcTool2 : public IEZNcTool
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetToolWorkOffset( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ DOUBLE __RPC_FAR *pdOffset,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetToolWorkOffset( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ DOUBLE dOffset,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcTool2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcTool2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcTool2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolSetSize )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetType )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOffset )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [in] */ LONG lKind,
            /* [in] */ LONG lToolSetNo,
            /* [out] */ DOUBLE __RPC_FAR *pdOffset,
            /* [out] */ LONG __RPC_FAR *plNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOffset )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [in] */ LONG lKind,
            /* [in] */ LONG lToolSetNo,
            /* [in] */ DOUBLE dOffset,
            /* [in] */ LONG lNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSurface )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdHight,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSurface )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ DOUBLE dHight,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCControl )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCSize )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCReady )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ LONG lReady,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCPot )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetATCPot )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCPotEx )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetATCPotEx )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCAux )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetATCAux )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeType )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeType )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeData )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeData )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolWorkOffset )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ DOUBLE __RPC_FAR *pdOffset,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolWorkOffset )( 
            IEZNcTool2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ DOUBLE dOffset,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcTool2Vtbl;

    interface IEZNcTool2
    {
        CONST_VTBL struct IEZNcTool2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcTool2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcTool2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcTool2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcTool2_GetToolSetSize(This,plSize,plRet)	\
    (This)->lpVtbl -> GetToolSetSize(This,plSize,plRet)

#define IEZNcTool2_GetType(This,plType,plRet)	\
    (This)->lpVtbl -> GetType(This,plType,plRet)

#define IEZNcTool2_GetOffset(This,lType,lKind,lToolSetNo,pdOffset,plNo,plRet)	\
    (This)->lpVtbl -> GetOffset(This,lType,lKind,lToolSetNo,pdOffset,plNo,plRet)

#define IEZNcTool2_SetOffset(This,lType,lKind,lToolSetNo,dOffset,lNo,plRet)	\
    (This)->lpVtbl -> SetOffset(This,lType,lKind,lToolSetNo,dOffset,lNo,plRet)

#define IEZNcTool2_GetSurface(This,lAxisNo,pdHight,plRet)	\
    (This)->lpVtbl -> GetSurface(This,lAxisNo,pdHight,plRet)

#define IEZNcTool2_SetSurface(This,lAxisNo,dHight,plRet)	\
    (This)->lpVtbl -> SetSurface(This,lAxisNo,dHight,plRet)

#define IEZNcTool2_GetATCControl(This,plData,plRet)	\
    (This)->lpVtbl -> GetATCControl(This,plData,plRet)

#define IEZNcTool2_GetATCSize(This,plSize,plRet)	\
    (This)->lpVtbl -> GetATCSize(This,plSize,plRet)

#define IEZNcTool2_GetATCReady(This,lReady,plToolNo,plRet)	\
    (This)->lpVtbl -> GetATCReady(This,lReady,plToolNo,plRet)

#define IEZNcTool2_GetATCPot(This,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetATCPot(This,lIndex,plToolNo,plRet)

#define IEZNcTool2_SetATCPot(This,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetATCPot(This,lIndex,lToolNo,plRet)

#define IEZNcTool2_GetATCPotEx(This,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetATCPotEx(This,lIndex,plToolNo,plRet)

#define IEZNcTool2_SetATCPotEx(This,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetATCPotEx(This,lIndex,lToolNo,plRet)

#define IEZNcTool2_GetATCAux(This,plData,plRet)	\
    (This)->lpVtbl -> GetATCAux(This,plData,plRet)

#define IEZNcTool2_SetATCAux(This,lData,plRet)	\
    (This)->lpVtbl -> SetATCAux(This,lData,plRet)

#define IEZNcTool2_GetToolLifeType(This,plType,plRet)	\
    (This)->lpVtbl -> GetToolLifeType(This,plType,plRet)

#define IEZNcTool2_SetToolLifeType(This,lType,plRet)	\
    (This)->lpVtbl -> SetToolLifeType(This,lType,plRet)

#define IEZNcTool2_GetToolLifeData(This,plRet)	\
    (This)->lpVtbl -> GetToolLifeData(This,plRet)

#define IEZNcTool2_SetToolLifeData(This,plRet)	\
    (This)->lpVtbl -> SetToolLifeData(This,plRet)


#define IEZNcTool2_GetToolWorkOffset(This,lAxisNo,lIndex,pdOffset,plRet)	\
    (This)->lpVtbl -> GetToolWorkOffset(This,lAxisNo,lIndex,pdOffset,plRet)

#define IEZNcTool2_SetToolWorkOffset(This,lAxisNo,lIndex,dOffset,lMode,plRet)	\
    (This)->lpVtbl -> SetToolWorkOffset(This,lAxisNo,lIndex,dOffset,lMode,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool2_GetToolWorkOffset_Proxy( 
    IEZNcTool2 __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ DOUBLE __RPC_FAR *pdOffset,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool2_GetToolWorkOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool2_SetToolWorkOffset_Proxy( 
    IEZNcTool2 __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ DOUBLE dOffset,
    /* [in] */ LONG lMode,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool2_SetToolWorkOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcTool2_INTERFACE_DEFINED__ */


#ifndef __IEZNcParameter2_INTERFACE_DEFINED__
#define __IEZNcParameter2_INTERFACE_DEFINED__

/* interface IEZNcParameter2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcParameter2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("1BCB76D2-BEA5-11d4-A2AF-00A0245B34C6")
    interface IEZNcParameter2 : public IEZNcParameter
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetParameterData( 
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetParameterData( 
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *lppwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcParameter2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcParameter2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcParameter2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProcessParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProcessParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetControlParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetControlParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAxisParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAxisParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBarrierData )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plDataX,
            /* [out] */ LONG __RPC_FAR *plDataZ,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBarrierData )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDataX,
            /* [in] */ LONG lDataZ,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIoParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIoParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSerialParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDeviceNo,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszDeviceName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSerialParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDeviceNo,
            /* [in] */ LONG lData,
            /* [string][in] */ LPCOLESTR lpcwszDeviceName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWorkOffset )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plOffset,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetWorkOffset )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lOffset,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPositionSwitch )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plDog1,
            /* [out] */ LONG __RPC_FAR *plDog2,
            /* [out] */ LONG __RPC_FAR *plAxisName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPositionSwitch )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDog1,
            /* [in] */ LONG lDog2,
            /* [in] */ LONG lAxisName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBaseParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBaseParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [string][in] */ LPCOLESTR lpcwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAxisSpecParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAxisSpecParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToleranceParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToleranceParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAuxParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAuxParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPlcParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPlcParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMacroParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMacroParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAuxAxisParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAuxAxisParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [string][in] */ LPCOLESTR lpcwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetServoParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetServoParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSPJParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSPJParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpindleParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSpindleParameter )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParameterData )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParameterData )( 
            IEZNcParameter2 __RPC_FAR * This,
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *lppwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcParameter2Vtbl;

    interface IEZNcParameter2
    {
        CONST_VTBL struct IEZNcParameter2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcParameter2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcParameter2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcParameter2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcParameter2_GetProcessParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetProcessParameter(This,lIndex,plData,plRet)

#define IEZNcParameter2_SetProcessParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetProcessParameter(This,lIndex,lData,plRet)

#define IEZNcParameter2_GetControlParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetControlParameter(This,lIndex,plData,plRet)

#define IEZNcParameter2_SetControlParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetControlParameter(This,lIndex,lData,plRet)

#define IEZNcParameter2_GetAxisParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetAxisParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter2_SetAxisParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetAxisParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter2_GetBarrierData(This,lAxisNo,lIndex,plDataX,plDataZ,plRet)	\
    (This)->lpVtbl -> GetBarrierData(This,lAxisNo,lIndex,plDataX,plDataZ,plRet)

#define IEZNcParameter2_SetBarrierData(This,lAxisNo,lIndex,lDataX,lDataZ,plRet)	\
    (This)->lpVtbl -> SetBarrierData(This,lAxisNo,lIndex,lDataX,lDataZ,plRet)

#define IEZNcParameter2_GetIoParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetIoParameter(This,lIndex,plData,plRet)

#define IEZNcParameter2_SetIoParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetIoParameter(This,lIndex,lData,plRet)

#define IEZNcParameter2_GetSerialParameter(This,lIndex,lDeviceNo,plData,lppwszDeviceName,plRet)	\
    (This)->lpVtbl -> GetSerialParameter(This,lIndex,lDeviceNo,plData,lppwszDeviceName,plRet)

#define IEZNcParameter2_SetSerialParameter(This,lIndex,lDeviceNo,lData,lpcwszDeviceName,plRet)	\
    (This)->lpVtbl -> SetSerialParameter(This,lIndex,lDeviceNo,lData,lpcwszDeviceName,plRet)

#define IEZNcParameter2_GetWorkOffset(This,lAxisNo,lIndex,plOffset,plRet)	\
    (This)->lpVtbl -> GetWorkOffset(This,lAxisNo,lIndex,plOffset,plRet)

#define IEZNcParameter2_SetWorkOffset(This,lAxisNo,lIndex,lOffset,lMode,plRet)	\
    (This)->lpVtbl -> SetWorkOffset(This,lAxisNo,lIndex,lOffset,lMode,plRet)

#define IEZNcParameter2_GetPositionSwitch(This,lIndex,plDog1,plDog2,plAxisName,plRet)	\
    (This)->lpVtbl -> GetPositionSwitch(This,lIndex,plDog1,plDog2,plAxisName,plRet)

#define IEZNcParameter2_SetPositionSwitch(This,lIndex,lDog1,lDog2,lAxisName,plRet)	\
    (This)->lpVtbl -> SetPositionSwitch(This,lIndex,lDog1,lDog2,lAxisName,plRet)

#define IEZNcParameter2_GetBaseParameter(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetBaseParameter(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)

#define IEZNcParameter2_SetBaseParameter(This,lAxisNo,lIndex,lData,lpcwszBuffer,plRet)	\
    (This)->lpVtbl -> SetBaseParameter(This,lAxisNo,lIndex,lData,lpcwszBuffer,plRet)

#define IEZNcParameter2_GetAxisSpecParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetAxisSpecParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter2_SetAxisSpecParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetAxisSpecParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter2_GetToleranceParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetToleranceParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter2_SetToleranceParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetToleranceParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter2_GetAuxParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetAuxParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter2_SetAuxParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetAuxParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter2_GetPlcParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetPlcParameter(This,lIndex,plData,plRet)

#define IEZNcParameter2_SetPlcParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetPlcParameter(This,lIndex,lData,plRet)

#define IEZNcParameter2_GetMacroParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetMacroParameter(This,lIndex,plData,plRet)

#define IEZNcParameter2_SetMacroParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetMacroParameter(This,lIndex,lData,plRet)

#define IEZNcParameter2_GetAuxAxisParameter(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetAuxAxisParameter(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)

#define IEZNcParameter2_SetAuxAxisParameter(This,lAxisNo,lIndex,lData,lpcwszBuffer,plRet)	\
    (This)->lpVtbl -> SetAuxAxisParameter(This,lAxisNo,lIndex,lData,lpcwszBuffer,plRet)

#define IEZNcParameter2_GetServoParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetServoParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter2_SetServoParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetServoParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter2_GetSPJParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetSPJParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter2_SetSPJParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetSPJParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter2_GetSpindleParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetSpindleParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter2_SetSpindleParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetSpindleParameter(This,lAxisNo,lIndex,lData,plRet)


#define IEZNcParameter2_SetParameterData(This,lGroup,lItem,lSize,lAxis,lppcwszValue,plRet)	\
    (This)->lpVtbl -> SetParameterData(This,lGroup,lItem,lSize,lAxis,lppcwszValue,plRet)

#define IEZNcParameter2_GetParameterData(This,lGroup,lItem,lSize,lAxis,lppwszValue,plRet)	\
    (This)->lpVtbl -> GetParameterData(This,lGroup,lItem,lSize,lAxis,lppwszValue,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter2_SetParameterData_Proxy( 
    IEZNcParameter2 __RPC_FAR * This,
    /* [in] */ LONG lGroup,
    /* [in] */ LONG lItem,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lAxis,
    /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter2_SetParameterData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter2_GetParameterData_Proxy( 
    IEZNcParameter2 __RPC_FAR * This,
    /* [in] */ LONG lGroup,
    /* [in] */ LONG lItem,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lAxis,
    /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *lppwszValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter2_GetParameterData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcParameter2_INTERFACE_DEFINED__ */


#ifndef __IEZNcATC_INTERFACE_DEFINED__
#define __IEZNcATC_INTERFACE_DEFINED__

/* interface IEZNcATC */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcATC;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("1BCB76D3-BEA5-11d4-A2AF-00A0245B34C6")
    interface IEZNcATC : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMGNControl( 
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMGNSize( 
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMGNReady( 
            /* [in] */ LONG lReady,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMGNPot( 
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetMGNPot( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMGNPotEx( 
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetMGNPotEx( 
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMGNAux( 
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetMGNAux( 
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMGNSize2( 
            /* [in] */ LONG lMagazineNo,
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMGNPot2( 
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetMGNPot2( 
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcATCVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcATC __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcATC __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcATC __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNControl )( 
            IEZNcATC __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNSize )( 
            IEZNcATC __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNReady )( 
            IEZNcATC __RPC_FAR * This,
            /* [in] */ LONG lReady,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNPot )( 
            IEZNcATC __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNPot )( 
            IEZNcATC __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNPotEx )( 
            IEZNcATC __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNPotEx )( 
            IEZNcATC __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNAux )( 
            IEZNcATC __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNAux )( 
            IEZNcATC __RPC_FAR * This,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNSize2 )( 
            IEZNcATC __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNPot2 )( 
            IEZNcATC __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNPot2 )( 
            IEZNcATC __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcATCVtbl;

    interface IEZNcATC
    {
        CONST_VTBL struct IEZNcATCVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcATC_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcATC_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcATC_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcATC_GetMGNControl(This,plData,plRet)	\
    (This)->lpVtbl -> GetMGNControl(This,plData,plRet)

#define IEZNcATC_GetMGNSize(This,plSize,plRet)	\
    (This)->lpVtbl -> GetMGNSize(This,plSize,plRet)

#define IEZNcATC_GetMGNReady(This,lReady,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNReady(This,lReady,plToolNo,plRet)

#define IEZNcATC_GetMGNPot(This,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNPot(This,lIndex,plToolNo,plRet)

#define IEZNcATC_SetMGNPot(This,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetMGNPot(This,lIndex,lToolNo,plRet)

#define IEZNcATC_GetMGNPotEx(This,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNPotEx(This,lIndex,plToolNo,plRet)

#define IEZNcATC_SetMGNPotEx(This,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetMGNPotEx(This,lIndex,lToolNo,plRet)

#define IEZNcATC_GetMGNAux(This,plData,plRet)	\
    (This)->lpVtbl -> GetMGNAux(This,plData,plRet)

#define IEZNcATC_SetMGNAux(This,lData,plRet)	\
    (This)->lpVtbl -> SetMGNAux(This,lData,plRet)

#define IEZNcATC_GetMGNSize2(This,lMagazineNo,plSize,plRet)	\
    (This)->lpVtbl -> GetMGNSize2(This,lMagazineNo,plSize,plRet)

#define IEZNcATC_GetMGNPot2(This,lMagazineNo,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNPot2(This,lMagazineNo,lIndex,plToolNo,plRet)

#define IEZNcATC_SetMGNPot2(This,lMagazineNo,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetMGNPot2(This,lMagazineNo,lIndex,lToolNo,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC_GetMGNControl_Proxy( 
    IEZNcATC __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC_GetMGNControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC_GetMGNSize_Proxy( 
    IEZNcATC __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plSize,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC_GetMGNSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC_GetMGNReady_Proxy( 
    IEZNcATC __RPC_FAR * This,
    /* [in] */ LONG lReady,
    /* [out] */ LONG __RPC_FAR *plToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC_GetMGNReady_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC_GetMGNPot_Proxy( 
    IEZNcATC __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC_GetMGNPot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC_SetMGNPot_Proxy( 
    IEZNcATC __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC_SetMGNPot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC_GetMGNPotEx_Proxy( 
    IEZNcATC __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC_GetMGNPotEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC_SetMGNPotEx_Proxy( 
    IEZNcATC __RPC_FAR * This,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC_SetMGNPotEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC_GetMGNAux_Proxy( 
    IEZNcATC __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC_GetMGNAux_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC_SetMGNAux_Proxy( 
    IEZNcATC __RPC_FAR * This,
    /* [in] */ LONG lData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC_SetMGNAux_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC_GetMGNSize2_Proxy( 
    IEZNcATC __RPC_FAR * This,
    /* [in] */ LONG lMagazineNo,
    /* [out] */ LONG __RPC_FAR *plSize,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC_GetMGNSize2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC_GetMGNPot2_Proxy( 
    IEZNcATC __RPC_FAR * This,
    /* [in] */ LONG lMagazineNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC_GetMGNPot2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC_SetMGNPot2_Proxy( 
    IEZNcATC __RPC_FAR * This,
    /* [in] */ LONG lMagazineNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC_SetMGNPot2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcATC_INTERFACE_DEFINED__ */


#ifndef __IEZNcDevice_INTERFACE_DEFINED__
#define __IEZNcDevice_INTERFACE_DEFINED__

/* interface IEZNcDevice */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("1BCB76D4-BEA5-11d4-A2AF-00A0245B34C6")
    interface IEZNcDevice : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszDevice,
            /* [size_is][in] */ LPDWORD lpdwDataType,
            /* [size_is][in] */ LPDWORD lpdwValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteDeviceAll( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadDevice( 
            /* [out] */ LPDWORD lpdwLength,
            /* [size_is][size_is][out] */ LPDWORD __RPC_FAR *lppdwValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WriteDevice( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadBlockDevice( 
            /* [in] */ DWORD dwLength,
            /* [string][in] */ LPCOLESTR lpcwszDevice,
            /* [in] */ DWORD dwDataType,
            /* [size_is][out] */ LPDWORD __RPC_FAR *lppdwValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WriteBlockDevice( 
            /* [in] */ DWORD dwLength,
            /* [string][in] */ LPCOLESTR lpcwszDevice,
            /* [in] */ DWORD dwDataType,
            /* [size_is][in] */ LPDWORD lpdwValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcDevice __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcDevice __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcDevice __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDevice )( 
            IEZNcDevice __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszDevice,
            /* [size_is][in] */ LPDWORD lpdwDataType,
            /* [size_is][in] */ LPDWORD lpdwValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteDeviceAll )( 
            IEZNcDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadDevice )( 
            IEZNcDevice __RPC_FAR * This,
            /* [out] */ LPDWORD lpdwLength,
            /* [size_is][size_is][out] */ LPDWORD __RPC_FAR *lppdwValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteDevice )( 
            IEZNcDevice __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBlockDevice )( 
            IEZNcDevice __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [string][in] */ LPCOLESTR lpcwszDevice,
            /* [in] */ DWORD dwDataType,
            /* [size_is][out] */ LPDWORD __RPC_FAR *lppdwValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBlockDevice )( 
            IEZNcDevice __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [string][in] */ LPCOLESTR lpcwszDevice,
            /* [in] */ DWORD dwDataType,
            /* [size_is][in] */ LPDWORD lpdwValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcDeviceVtbl;

    interface IEZNcDevice
    {
        CONST_VTBL struct IEZNcDeviceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcDevice_SetDevice(This,dwLength,lppcwszDevice,lpdwDataType,lpdwValue,plRet)	\
    (This)->lpVtbl -> SetDevice(This,dwLength,lppcwszDevice,lpdwDataType,lpdwValue,plRet)

#define IEZNcDevice_DeleteDeviceAll(This,plRet)	\
    (This)->lpVtbl -> DeleteDeviceAll(This,plRet)

#define IEZNcDevice_ReadDevice(This,lpdwLength,lppdwValue,plRet)	\
    (This)->lpVtbl -> ReadDevice(This,lpdwLength,lppdwValue,plRet)

#define IEZNcDevice_WriteDevice(This,plRet)	\
    (This)->lpVtbl -> WriteDevice(This,plRet)

#define IEZNcDevice_ReadBlockDevice(This,dwLength,lpcwszDevice,dwDataType,lppdwValue,plRet)	\
    (This)->lpVtbl -> ReadBlockDevice(This,dwLength,lpcwszDevice,dwDataType,lppdwValue,plRet)

#define IEZNcDevice_WriteBlockDevice(This,dwLength,lpcwszDevice,dwDataType,lpdwValue,plRet)	\
    (This)->lpVtbl -> WriteBlockDevice(This,dwLength,lpcwszDevice,dwDataType,lpdwValue,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcDevice_SetDevice_Proxy( 
    IEZNcDevice __RPC_FAR * This,
    /* [in] */ DWORD dwLength,
    /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszDevice,
    /* [size_is][in] */ LPDWORD lpdwDataType,
    /* [size_is][in] */ LPDWORD lpdwValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcDevice_SetDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcDevice_DeleteDeviceAll_Proxy( 
    IEZNcDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcDevice_DeleteDeviceAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcDevice_ReadDevice_Proxy( 
    IEZNcDevice __RPC_FAR * This,
    /* [out] */ LPDWORD lpdwLength,
    /* [size_is][size_is][out] */ LPDWORD __RPC_FAR *lppdwValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcDevice_ReadDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcDevice_WriteDevice_Proxy( 
    IEZNcDevice __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcDevice_WriteDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcDevice_ReadBlockDevice_Proxy( 
    IEZNcDevice __RPC_FAR * This,
    /* [in] */ DWORD dwLength,
    /* [string][in] */ LPCOLESTR lpcwszDevice,
    /* [in] */ DWORD dwDataType,
    /* [size_is][out] */ LPDWORD __RPC_FAR *lppdwValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcDevice_ReadBlockDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcDevice_WriteBlockDevice_Proxy( 
    IEZNcDevice __RPC_FAR * This,
    /* [in] */ DWORD dwLength,
    /* [string][in] */ LPCOLESTR lpcwszDevice,
    /* [in] */ DWORD dwDataType,
    /* [size_is][in] */ LPDWORD lpdwValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcDevice_WriteBlockDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcDevice_INTERFACE_DEFINED__ */


#ifndef __IEZNcGeneric2_INTERFACE_DEFINED__
#define __IEZNcGeneric2_INTERFACE_DEFINED__

/* interface IEZNcGeneric2 */
/* [unique][helpstring][uuid][object] */ 

typedef struct  EZNcStGenData
    {
    LONG lAxisNo;
    LONG lSectionNum;
    LONG lSubSectionNum;
    LONG lDataType;
    /* [string] */ LPCOLESTR lpcwszSrcData;
    }	EZNCST_GENDATA;


EXTERN_C const IID IID_IEZNcGeneric2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("99E76486-C037-11d4-A384-00D0B721C9A7")
    interface IEZNcGeneric2 : public IEZNcGeneric
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetData( 
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ EZNCST_GENDATA __RPC_FAR *pstGenData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteDataAll( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadBlockData( 
            /* [out] */ LPDWORD lpdwLength,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WriteBlockData( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcGeneric2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcGeneric2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcGeneric2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcGeneric2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadData )( 
            IEZNcGeneric2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lSectionNum,
            /* [in] */ LONG lSubSectionNum,
            /* [out][in] */ VARIANT __RPC_FAR *pvReadData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteData )( 
            IEZNcGeneric2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lSectionNum,
            /* [in] */ LONG lSubSectionNum,
            /* [in] */ VARIANT vWriteData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetData )( 
            IEZNcGeneric2 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ EZNCST_GENDATA __RPC_FAR *pstGenData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteDataAll )( 
            IEZNcGeneric2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadBlockData )( 
            IEZNcGeneric2 __RPC_FAR * This,
            /* [out] */ LPDWORD lpdwLength,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteBlockData )( 
            IEZNcGeneric2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcGeneric2Vtbl;

    interface IEZNcGeneric2
    {
        CONST_VTBL struct IEZNcGeneric2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcGeneric2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcGeneric2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcGeneric2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcGeneric2_ReadData(This,lAxisNo,lSectionNum,lSubSectionNum,pvReadData,plRet)	\
    (This)->lpVtbl -> ReadData(This,lAxisNo,lSectionNum,lSubSectionNum,pvReadData,plRet)

#define IEZNcGeneric2_WriteData(This,lAxisNo,lSectionNum,lSubSectionNum,vWriteData,plRet)	\
    (This)->lpVtbl -> WriteData(This,lAxisNo,lSectionNum,lSubSectionNum,vWriteData,plRet)


#define IEZNcGeneric2_SetData(This,dwLength,pstGenData,plRet)	\
    (This)->lpVtbl -> SetData(This,dwLength,pstGenData,plRet)

#define IEZNcGeneric2_DeleteDataAll(This,plRet)	\
    (This)->lpVtbl -> DeleteDataAll(This,plRet)

#define IEZNcGeneric2_ReadBlockData(This,lpdwLength,lpppwszData,plRet)	\
    (This)->lpVtbl -> ReadBlockData(This,lpdwLength,lpppwszData,plRet)

#define IEZNcGeneric2_WriteBlockData(This,plRet)	\
    (This)->lpVtbl -> WriteBlockData(This,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcGeneric2_SetData_Proxy( 
    IEZNcGeneric2 __RPC_FAR * This,
    /* [in] */ DWORD dwLength,
    /* [size_is][in] */ EZNCST_GENDATA __RPC_FAR *pstGenData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcGeneric2_SetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcGeneric2_DeleteDataAll_Proxy( 
    IEZNcGeneric2 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcGeneric2_DeleteDataAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcGeneric2_ReadBlockData_Proxy( 
    IEZNcGeneric2 __RPC_FAR * This,
    /* [out] */ LPDWORD lpdwLength,
    /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcGeneric2_ReadBlockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcGeneric2_WriteBlockData_Proxy( 
    IEZNcGeneric2 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcGeneric2_WriteBlockData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcGeneric2_INTERFACE_DEFINED__ */


#ifndef __IEZNcFile2_INTERFACE_DEFINED__
#define __IEZNcFile2_INTERFACE_DEFINED__

/* interface IEZNcFile2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcFile2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("B9FCD5AC-A71E-4943-BB86-95B9C27EE837")
    interface IEZNcFile2 : public IEZNcFile
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OpenFile( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CloseFile( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbortFile( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WriteFile( 
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ BYTE __RPC_FAR *pbData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadFile( 
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcFile2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcFile2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcFile2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindDir )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [in] */ LONG lFileType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindNextDir )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetDir )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Copy )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Rename )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveInformation )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszDriveInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveSize )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [out] */ LONG __RPC_FAR *plDriveSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenFile )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseFile )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AbortFile )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteFile )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ BYTE __RPC_FAR *pbData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFile )( 
            IEZNcFile2 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcFile2Vtbl;

    interface IEZNcFile2
    {
        CONST_VTBL struct IEZNcFile2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcFile2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcFile2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcFile2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcFile2_FindDir(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindDir(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)

#define IEZNcFile2_FindNextDir(This,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindNextDir(This,lppwszFileInfo,plRet)

#define IEZNcFile2_ResetDir(This,plRet)	\
    (This)->lpVtbl -> ResetDir(This,plRet)

#define IEZNcFile2_Copy(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Copy(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile2_Delete(This,lpcwszFileName,plRet)	\
    (This)->lpVtbl -> Delete(This,lpcwszFileName,plRet)

#define IEZNcFile2_Rename(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Rename(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile2_GetDriveInformation(This,lppwszDriveInfo,plRet)	\
    (This)->lpVtbl -> GetDriveInformation(This,lppwszDriveInfo,plRet)

#define IEZNcFile2_GetDriveSize(This,lpcwszDirectoryName,plDriveSize,plRet)	\
    (This)->lpVtbl -> GetDriveSize(This,lpcwszDirectoryName,plDriveSize,plRet)


#define IEZNcFile2_OpenFile(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenFile(This,lpcwszFileName,lMode,plRet)

#define IEZNcFile2_CloseFile(This,plRet)	\
    (This)->lpVtbl -> CloseFile(This,plRet)

#define IEZNcFile2_AbortFile(This,plRet)	\
    (This)->lpVtbl -> AbortFile(This,plRet)

#define IEZNcFile2_WriteFile(This,dwLength,pbData,plRet)	\
    (This)->lpVtbl -> WriteFile(This,dwLength,pbData,plRet)

#define IEZNcFile2_ReadFile(This,dwLength,ppbData,pdwNumRead,plRet)	\
    (This)->lpVtbl -> ReadFile(This,dwLength,ppbData,pdwNumRead,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile2_OpenFile_Proxy( 
    IEZNcFile2 __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [in] */ LONG lMode,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile2_OpenFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile2_CloseFile_Proxy( 
    IEZNcFile2 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile2_CloseFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile2_AbortFile_Proxy( 
    IEZNcFile2 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile2_AbortFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile2_WriteFile_Proxy( 
    IEZNcFile2 __RPC_FAR * This,
    /* [in] */ DWORD dwLength,
    /* [size_is][in] */ BYTE __RPC_FAR *pbData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile2_WriteFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile2_ReadFile_Proxy( 
    IEZNcFile2 __RPC_FAR * This,
    /* [in] */ DWORD dwLength,
    /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
    /* [out] */ DWORD __RPC_FAR *pdwNumRead,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile2_ReadFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcFile2_INTERFACE_DEFINED__ */


#ifndef __IEZNcTool3_INTERFACE_DEFINED__
#define __IEZNcTool3_INTERFACE_DEFINED__

/* interface IEZNcTool3 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcTool3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("05AC1691-BD26-11d5-A488-00D0B721C9A7")
    interface IEZNcTool3 : public IEZNcTool2
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetToolLifeType2( 
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetToolLifeType2( 
            /* [in] */ LONG lType,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetToolLifeGroupList( 
            /* [out] */ LPDWORD lpdwLength,
            /* [size_is][size_is][out] */ LPDWORD __RPC_FAR *lppdwGroup,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddToolLifeGroup( 
            /* [in] */ DWORD dwGroup,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ChangeToolLifeGroup( 
            /* [in] */ DWORD dwSrcGroup,
            /* [in] */ DWORD dwDstGroup,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteToolLifeGroup( 
            /* [in] */ DWORD dwGroup,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetToolLifeToolNoList( 
            /* [in] */ DWORD dwGroup,
            /* [out] */ LPDWORD lpdwLength,
            /* [size_is][size_is][out] */ LPDWORD __RPC_FAR *lppdwToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AddToolLifeToolNo( 
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ChangeToolLifeToolNo( 
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwSrcToolNo,
            /* [in] */ DWORD dwDstToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteToolLifeToolNo( 
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetToolLifeValue( 
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetToolLifeValue( 
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwToolNo,
            /* [in] */ DWORD dwKind,
            /* [string][in] */ LPCOLESTR lpcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSpareTool( 
            /* [in] */ DWORD dwNo,
            /* [in] */ DWORD dwToolKind,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSpareTool( 
            /* [in] */ DWORD dwNo,
            /* [in] */ DWORD dwToolKind,
            /* [in] */ DWORD dwKind,
            /* [string][in] */ LPCOLESTR lpcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetToolLifeValue2( 
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetOffset2( 
            /* [in] */ LONG lType,
            /* [in] */ LONG lKind,
            /* [in] */ LONG lToolSetNo,
            /* [out] */ DOUBLE __RPC_FAR *pdOffset,
            /* [out] */ LONG __RPC_FAR *plNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSurface2( 
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdHight,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetToolWorkOffset2( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ DOUBLE __RPC_FAR *pdOffset,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetToolWorkOffset2( 
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ DOUBLE dOffset,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcTool3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcTool3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcTool3 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolSetSize )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetType )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOffset )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [in] */ LONG lKind,
            /* [in] */ LONG lToolSetNo,
            /* [out] */ DOUBLE __RPC_FAR *pdOffset,
            /* [out] */ LONG __RPC_FAR *plNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOffset )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [in] */ LONG lKind,
            /* [in] */ LONG lToolSetNo,
            /* [in] */ DOUBLE dOffset,
            /* [in] */ LONG lNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSurface )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdHight,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSurface )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ DOUBLE dHight,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCControl )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCSize )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCReady )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lReady,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCPot )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetATCPot )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCPotEx )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetATCPotEx )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetATCAux )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetATCAux )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeType )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeType )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeData )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeData )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolWorkOffset )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ DOUBLE __RPC_FAR *pdOffset,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolWorkOffset )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ DOUBLE dOffset,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeType2 )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeType2 )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeGroupList )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [out] */ LPDWORD lpdwLength,
            /* [size_is][size_is][out] */ LPDWORD __RPC_FAR *lppdwGroup,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddToolLifeGroup )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ DWORD dwGroup,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeToolLifeGroup )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ DWORD dwSrcGroup,
            /* [in] */ DWORD dwDstGroup,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteToolLifeGroup )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ DWORD dwGroup,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeToolNoList )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ DWORD dwGroup,
            /* [out] */ LPDWORD lpdwLength,
            /* [size_is][size_is][out] */ LPDWORD __RPC_FAR *lppdwToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddToolLifeToolNo )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeToolLifeToolNo )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwSrcToolNo,
            /* [in] */ DWORD dwDstToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteToolLifeToolNo )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeValue )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeValue )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwToolNo,
            /* [in] */ DWORD dwKind,
            /* [string][in] */ LPCOLESTR lpcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpareTool )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ DWORD dwNo,
            /* [in] */ DWORD dwToolKind,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSpareTool )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ DWORD dwNo,
            /* [in] */ DWORD dwToolKind,
            /* [in] */ DWORD dwKind,
            /* [string][in] */ LPCOLESTR lpcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeValue2 )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOffset2 )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [in] */ LONG lKind,
            /* [in] */ LONG lToolSetNo,
            /* [out] */ DOUBLE __RPC_FAR *pdOffset,
            /* [out] */ LONG __RPC_FAR *plNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSurface2 )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [out] */ DOUBLE __RPC_FAR *pdHight,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolWorkOffset2 )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ DOUBLE __RPC_FAR *pdOffset,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolWorkOffset2 )( 
            IEZNcTool3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ DOUBLE dOffset,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcTool3Vtbl;

    interface IEZNcTool3
    {
        CONST_VTBL struct IEZNcTool3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcTool3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcTool3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcTool3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcTool3_GetToolSetSize(This,plSize,plRet)	\
    (This)->lpVtbl -> GetToolSetSize(This,plSize,plRet)

#define IEZNcTool3_GetType(This,plType,plRet)	\
    (This)->lpVtbl -> GetType(This,plType,plRet)

#define IEZNcTool3_GetOffset(This,lType,lKind,lToolSetNo,pdOffset,plNo,plRet)	\
    (This)->lpVtbl -> GetOffset(This,lType,lKind,lToolSetNo,pdOffset,plNo,plRet)

#define IEZNcTool3_SetOffset(This,lType,lKind,lToolSetNo,dOffset,lNo,plRet)	\
    (This)->lpVtbl -> SetOffset(This,lType,lKind,lToolSetNo,dOffset,lNo,plRet)

#define IEZNcTool3_GetSurface(This,lAxisNo,pdHight,plRet)	\
    (This)->lpVtbl -> GetSurface(This,lAxisNo,pdHight,plRet)

#define IEZNcTool3_SetSurface(This,lAxisNo,dHight,plRet)	\
    (This)->lpVtbl -> SetSurface(This,lAxisNo,dHight,plRet)

#define IEZNcTool3_GetATCControl(This,plData,plRet)	\
    (This)->lpVtbl -> GetATCControl(This,plData,plRet)

#define IEZNcTool3_GetATCSize(This,plSize,plRet)	\
    (This)->lpVtbl -> GetATCSize(This,plSize,plRet)

#define IEZNcTool3_GetATCReady(This,lReady,plToolNo,plRet)	\
    (This)->lpVtbl -> GetATCReady(This,lReady,plToolNo,plRet)

#define IEZNcTool3_GetATCPot(This,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetATCPot(This,lIndex,plToolNo,plRet)

#define IEZNcTool3_SetATCPot(This,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetATCPot(This,lIndex,lToolNo,plRet)

#define IEZNcTool3_GetATCPotEx(This,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetATCPotEx(This,lIndex,plToolNo,plRet)

#define IEZNcTool3_SetATCPotEx(This,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetATCPotEx(This,lIndex,lToolNo,plRet)

#define IEZNcTool3_GetATCAux(This,plData,plRet)	\
    (This)->lpVtbl -> GetATCAux(This,plData,plRet)

#define IEZNcTool3_SetATCAux(This,lData,plRet)	\
    (This)->lpVtbl -> SetATCAux(This,lData,plRet)

#define IEZNcTool3_GetToolLifeType(This,plType,plRet)	\
    (This)->lpVtbl -> GetToolLifeType(This,plType,plRet)

#define IEZNcTool3_SetToolLifeType(This,lType,plRet)	\
    (This)->lpVtbl -> SetToolLifeType(This,lType,plRet)

#define IEZNcTool3_GetToolLifeData(This,plRet)	\
    (This)->lpVtbl -> GetToolLifeData(This,plRet)

#define IEZNcTool3_SetToolLifeData(This,plRet)	\
    (This)->lpVtbl -> SetToolLifeData(This,plRet)


#define IEZNcTool3_GetToolWorkOffset(This,lAxisNo,lIndex,pdOffset,plRet)	\
    (This)->lpVtbl -> GetToolWorkOffset(This,lAxisNo,lIndex,pdOffset,plRet)

#define IEZNcTool3_SetToolWorkOffset(This,lAxisNo,lIndex,dOffset,lMode,plRet)	\
    (This)->lpVtbl -> SetToolWorkOffset(This,lAxisNo,lIndex,dOffset,lMode,plRet)


#define IEZNcTool3_GetToolLifeType2(This,plType,plRet)	\
    (This)->lpVtbl -> GetToolLifeType2(This,plType,plRet)

#define IEZNcTool3_SetToolLifeType2(This,lType,plRet)	\
    (This)->lpVtbl -> SetToolLifeType2(This,lType,plRet)

#define IEZNcTool3_GetToolLifeGroupList(This,lpdwLength,lppdwGroup,plRet)	\
    (This)->lpVtbl -> GetToolLifeGroupList(This,lpdwLength,lppdwGroup,plRet)

#define IEZNcTool3_AddToolLifeGroup(This,dwGroup,plRet)	\
    (This)->lpVtbl -> AddToolLifeGroup(This,dwGroup,plRet)

#define IEZNcTool3_ChangeToolLifeGroup(This,dwSrcGroup,dwDstGroup,plRet)	\
    (This)->lpVtbl -> ChangeToolLifeGroup(This,dwSrcGroup,dwDstGroup,plRet)

#define IEZNcTool3_DeleteToolLifeGroup(This,dwGroup,plRet)	\
    (This)->lpVtbl -> DeleteToolLifeGroup(This,dwGroup,plRet)

#define IEZNcTool3_GetToolLifeToolNoList(This,dwGroup,lpdwLength,lppdwToolNo,plRet)	\
    (This)->lpVtbl -> GetToolLifeToolNoList(This,dwGroup,lpdwLength,lppdwToolNo,plRet)

#define IEZNcTool3_AddToolLifeToolNo(This,dwGroup,dwToolNo,plRet)	\
    (This)->lpVtbl -> AddToolLifeToolNo(This,dwGroup,dwToolNo,plRet)

#define IEZNcTool3_ChangeToolLifeToolNo(This,dwGroup,dwSrcToolNo,dwDstToolNo,plRet)	\
    (This)->lpVtbl -> ChangeToolLifeToolNo(This,dwGroup,dwSrcToolNo,dwDstToolNo,plRet)

#define IEZNcTool3_DeleteToolLifeToolNo(This,dwGroup,dwToolNo,plRet)	\
    (This)->lpVtbl -> DeleteToolLifeToolNo(This,dwGroup,dwToolNo,plRet)

#define IEZNcTool3_GetToolLifeValue(This,dwGroup,dwToolNo,lpppwszData,plRet)	\
    (This)->lpVtbl -> GetToolLifeValue(This,dwGroup,dwToolNo,lpppwszData,plRet)

#define IEZNcTool3_SetToolLifeValue(This,dwGroup,dwToolNo,dwKind,lpcwszData,plRet)	\
    (This)->lpVtbl -> SetToolLifeValue(This,dwGroup,dwToolNo,dwKind,lpcwszData,plRet)

#define IEZNcTool3_GetSpareTool(This,dwNo,dwToolKind,lpppwszData,plRet)	\
    (This)->lpVtbl -> GetSpareTool(This,dwNo,dwToolKind,lpppwszData,plRet)

#define IEZNcTool3_SetSpareTool(This,dwNo,dwToolKind,dwKind,lpcwszData,plRet)	\
    (This)->lpVtbl -> SetSpareTool(This,dwNo,dwToolKind,dwKind,lpcwszData,plRet)

#define IEZNcTool3_SetToolLifeValue2(This,dwGroup,dwToolNo,lppcwszData,plRet)	\
    (This)->lpVtbl -> SetToolLifeValue2(This,dwGroup,dwToolNo,lppcwszData,plRet)

#define IEZNcTool3_GetOffset2(This,lType,lKind,lToolSetNo,pdOffset,plNo,plRet)	\
    (This)->lpVtbl -> GetOffset2(This,lType,lKind,lToolSetNo,pdOffset,plNo,plRet)

#define IEZNcTool3_GetSurface2(This,lAxisNo,pdHight,plRet)	\
    (This)->lpVtbl -> GetSurface2(This,lAxisNo,pdHight,plRet)

#define IEZNcTool3_GetToolWorkOffset2(This,lAxisNo,lIndex,pdOffset,plRet)	\
    (This)->lpVtbl -> GetToolWorkOffset2(This,lAxisNo,lIndex,pdOffset,plRet)

#define IEZNcTool3_SetToolWorkOffset2(This,lAxisNo,lIndex,dOffset,lMode,plRet)	\
    (This)->lpVtbl -> SetToolWorkOffset2(This,lAxisNo,lIndex,dOffset,lMode,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_GetToolLifeType2_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plType,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_GetToolLifeType2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_SetToolLifeType2_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ LONG lType,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_SetToolLifeType2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_GetToolLifeGroupList_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [out] */ LPDWORD lpdwLength,
    /* [size_is][size_is][out] */ LPDWORD __RPC_FAR *lppdwGroup,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_GetToolLifeGroupList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_AddToolLifeGroup_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ DWORD dwGroup,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_AddToolLifeGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_ChangeToolLifeGroup_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ DWORD dwSrcGroup,
    /* [in] */ DWORD dwDstGroup,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_ChangeToolLifeGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_DeleteToolLifeGroup_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ DWORD dwGroup,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_DeleteToolLifeGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_GetToolLifeToolNoList_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ DWORD dwGroup,
    /* [out] */ LPDWORD lpdwLength,
    /* [size_is][size_is][out] */ LPDWORD __RPC_FAR *lppdwToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_GetToolLifeToolNoList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_AddToolLifeToolNo_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ DWORD dwGroup,
    /* [in] */ DWORD dwToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_AddToolLifeToolNo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_ChangeToolLifeToolNo_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ DWORD dwGroup,
    /* [in] */ DWORD dwSrcToolNo,
    /* [in] */ DWORD dwDstToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_ChangeToolLifeToolNo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_DeleteToolLifeToolNo_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ DWORD dwGroup,
    /* [in] */ DWORD dwToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_DeleteToolLifeToolNo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_GetToolLifeValue_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ DWORD dwGroup,
    /* [in] */ DWORD dwToolNo,
    /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_GetToolLifeValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_SetToolLifeValue_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ DWORD dwGroup,
    /* [in] */ DWORD dwToolNo,
    /* [in] */ DWORD dwKind,
    /* [string][in] */ LPCOLESTR lpcwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_SetToolLifeValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_GetSpareTool_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ DWORD dwNo,
    /* [in] */ DWORD dwToolKind,
    /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_GetSpareTool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_SetSpareTool_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ DWORD dwNo,
    /* [in] */ DWORD dwToolKind,
    /* [in] */ DWORD dwKind,
    /* [string][in] */ LPCOLESTR lpcwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_SetSpareTool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_SetToolLifeValue2_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ DWORD dwGroup,
    /* [in] */ DWORD dwToolNo,
    /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_SetToolLifeValue2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_GetOffset2_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ LONG lType,
    /* [in] */ LONG lKind,
    /* [in] */ LONG lToolSetNo,
    /* [out] */ DOUBLE __RPC_FAR *pdOffset,
    /* [out] */ LONG __RPC_FAR *plNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_GetOffset2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_GetSurface2_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [out] */ DOUBLE __RPC_FAR *pdHight,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_GetSurface2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_GetToolWorkOffset2_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [out] */ DOUBLE __RPC_FAR *pdOffset,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_GetToolWorkOffset2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcTool3_SetToolWorkOffset2_Proxy( 
    IEZNcTool3 __RPC_FAR * This,
    /* [in] */ LONG lAxisNo,
    /* [in] */ LONG lIndex,
    /* [in] */ DOUBLE dOffset,
    /* [in] */ LONG lMode,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcTool3_SetToolWorkOffset2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcTool3_INTERFACE_DEFINED__ */


#ifndef __IEZNcFile3_INTERFACE_DEFINED__
#define __IEZNcFile3_INTERFACE_DEFINED__

/* interface IEZNcFile3 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcFile3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("05AC1690-BD26-11d5-A488-00D0B721C9A7")
    interface IEZNcFile3 : public IEZNcFile2
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OpenFile2( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcFile3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcFile3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcFile3 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindDir )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [in] */ LONG lFileType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindNextDir )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetDir )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Copy )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Rename )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveInformation )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszDriveInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveSize )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [out] */ LONG __RPC_FAR *plDriveSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenFile )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseFile )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AbortFile )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteFile )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ BYTE __RPC_FAR *pbData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFile )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenFile2 )( 
            IEZNcFile3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcFile3Vtbl;

    interface IEZNcFile3
    {
        CONST_VTBL struct IEZNcFile3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcFile3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcFile3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcFile3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcFile3_FindDir(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindDir(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)

#define IEZNcFile3_FindNextDir(This,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindNextDir(This,lppwszFileInfo,plRet)

#define IEZNcFile3_ResetDir(This,plRet)	\
    (This)->lpVtbl -> ResetDir(This,plRet)

#define IEZNcFile3_Copy(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Copy(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile3_Delete(This,lpcwszFileName,plRet)	\
    (This)->lpVtbl -> Delete(This,lpcwszFileName,plRet)

#define IEZNcFile3_Rename(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Rename(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile3_GetDriveInformation(This,lppwszDriveInfo,plRet)	\
    (This)->lpVtbl -> GetDriveInformation(This,lppwszDriveInfo,plRet)

#define IEZNcFile3_GetDriveSize(This,lpcwszDirectoryName,plDriveSize,plRet)	\
    (This)->lpVtbl -> GetDriveSize(This,lpcwszDirectoryName,plDriveSize,plRet)


#define IEZNcFile3_OpenFile(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenFile(This,lpcwszFileName,lMode,plRet)

#define IEZNcFile3_CloseFile(This,plRet)	\
    (This)->lpVtbl -> CloseFile(This,plRet)

#define IEZNcFile3_AbortFile(This,plRet)	\
    (This)->lpVtbl -> AbortFile(This,plRet)

#define IEZNcFile3_WriteFile(This,dwLength,pbData,plRet)	\
    (This)->lpVtbl -> WriteFile(This,dwLength,pbData,plRet)

#define IEZNcFile3_ReadFile(This,dwLength,ppbData,pdwNumRead,plRet)	\
    (This)->lpVtbl -> ReadFile(This,dwLength,ppbData,pdwNumRead,plRet)


#define IEZNcFile3_OpenFile2(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenFile2(This,lpcwszFileName,lMode,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile3_OpenFile2_Proxy( 
    IEZNcFile3 __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [in] */ LONG lMode,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile3_OpenFile2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcFile3_INTERFACE_DEFINED__ */


#ifndef __IEZNcFile4_INTERFACE_DEFINED__
#define __IEZNcFile4_INTERFACE_DEFINED__

/* interface IEZNcFile4 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcFile4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("7A37318D-589D-4874-8735-397650169676")
    interface IEZNcFile4 : public IEZNcFile3
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OpenNCFile( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CloseNCFile( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbortNCFile( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE WriteNCFile( 
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ BYTE __RPC_FAR *pbData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadNCFile( 
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcFile4Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcFile4 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcFile4 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindDir )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [in] */ LONG lFileType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindNextDir )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetDir )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Copy )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Rename )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveInformation )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszDriveInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveSize )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [out] */ LONG __RPC_FAR *plDriveSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenFile )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseFile )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AbortFile )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteFile )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ BYTE __RPC_FAR *pbData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFile )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenFile2 )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenNCFile )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseNCFile )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AbortNCFile )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteNCFile )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ BYTE __RPC_FAR *pbData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadNCFile )( 
            IEZNcFile4 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcFile4Vtbl;

    interface IEZNcFile4
    {
        CONST_VTBL struct IEZNcFile4Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcFile4_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcFile4_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcFile4_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcFile4_FindDir(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindDir(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)

#define IEZNcFile4_FindNextDir(This,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindNextDir(This,lppwszFileInfo,plRet)

#define IEZNcFile4_ResetDir(This,plRet)	\
    (This)->lpVtbl -> ResetDir(This,plRet)

#define IEZNcFile4_Copy(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Copy(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile4_Delete(This,lpcwszFileName,plRet)	\
    (This)->lpVtbl -> Delete(This,lpcwszFileName,plRet)

#define IEZNcFile4_Rename(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Rename(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile4_GetDriveInformation(This,lppwszDriveInfo,plRet)	\
    (This)->lpVtbl -> GetDriveInformation(This,lppwszDriveInfo,plRet)

#define IEZNcFile4_GetDriveSize(This,lpcwszDirectoryName,plDriveSize,plRet)	\
    (This)->lpVtbl -> GetDriveSize(This,lpcwszDirectoryName,plDriveSize,plRet)


#define IEZNcFile4_OpenFile(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenFile(This,lpcwszFileName,lMode,plRet)

#define IEZNcFile4_CloseFile(This,plRet)	\
    (This)->lpVtbl -> CloseFile(This,plRet)

#define IEZNcFile4_AbortFile(This,plRet)	\
    (This)->lpVtbl -> AbortFile(This,plRet)

#define IEZNcFile4_WriteFile(This,dwLength,pbData,plRet)	\
    (This)->lpVtbl -> WriteFile(This,dwLength,pbData,plRet)

#define IEZNcFile4_ReadFile(This,dwLength,ppbData,pdwNumRead,plRet)	\
    (This)->lpVtbl -> ReadFile(This,dwLength,ppbData,pdwNumRead,plRet)


#define IEZNcFile4_OpenFile2(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenFile2(This,lpcwszFileName,lMode,plRet)


#define IEZNcFile4_OpenNCFile(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenNCFile(This,lpcwszFileName,lMode,plRet)

#define IEZNcFile4_CloseNCFile(This,plRet)	\
    (This)->lpVtbl -> CloseNCFile(This,plRet)

#define IEZNcFile4_AbortNCFile(This,plRet)	\
    (This)->lpVtbl -> AbortNCFile(This,plRet)

#define IEZNcFile4_WriteNCFile(This,dwLength,pbData,plRet)	\
    (This)->lpVtbl -> WriteNCFile(This,dwLength,pbData,plRet)

#define IEZNcFile4_ReadNCFile(This,dwLength,ppbData,pdwNumRead,plRet)	\
    (This)->lpVtbl -> ReadNCFile(This,dwLength,ppbData,pdwNumRead,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile4_OpenNCFile_Proxy( 
    IEZNcFile4 __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [in] */ LONG lMode,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile4_OpenNCFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile4_CloseNCFile_Proxy( 
    IEZNcFile4 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile4_CloseNCFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile4_AbortNCFile_Proxy( 
    IEZNcFile4 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile4_AbortNCFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile4_WriteNCFile_Proxy( 
    IEZNcFile4 __RPC_FAR * This,
    /* [in] */ DWORD dwLength,
    /* [size_is][in] */ BYTE __RPC_FAR *pbData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile4_WriteNCFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile4_ReadNCFile_Proxy( 
    IEZNcFile4 __RPC_FAR * This,
    /* [in] */ DWORD dwLength,
    /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
    /* [out] */ DWORD __RPC_FAR *pdwNumRead,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile4_ReadNCFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcFile4_INTERFACE_DEFINED__ */


#ifndef __IEZNcCommunication2_INTERFACE_DEFINED__
#define __IEZNcCommunication2_INTERFACE_DEFINED__

/* interface IEZNcCommunication2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcCommunication2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("4F438B03-1C24-4a6d-A6FF-2EA6545CA1DD")
    interface IEZNcCommunication2 : public IEZNcCommunication
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetModalCondition( 
            /* [in] */ LONG lRegistTime,
            /* [in] */ LONG lCancelTime,
            /* [in] */ LONG lIntervalTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetModalCondition( 
            /* [out] */ LONG __RPC_FAR *plRegistTime,
            /* [out] */ LONG __RPC_FAR *plCancelTime,
            /* [out] */ LONG __RPC_FAR *plIntervalTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetTCPIPProtocol( 
            /* [string][in] */ LPCOLESTR lpcwszIPAddress,
            /* [in] */ LONG lPort,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcCommunication2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcCommunication2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcCommunication2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcCommunication2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IEZNcCommunication2 __RPC_FAR * This,
            /* [in] */ LONG lSystemType,
            /* [in] */ LONG lMachine,
            /* [in] */ LONG lTimeOut,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IEZNcCommunication2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CommActivate )( 
            IEZNcCommunication2 __RPC_FAR * This,
            /* [in] */ LONG lActivate,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHead )( 
            IEZNcCommunication2 __RPC_FAR * This,
            /* [in] */ LONG lHead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHead )( 
            IEZNcCommunication2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plHead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetModalCondition )( 
            IEZNcCommunication2 __RPC_FAR * This,
            /* [in] */ LONG lRegistTime,
            /* [in] */ LONG lCancelTime,
            /* [in] */ LONG lIntervalTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetModalCondition )( 
            IEZNcCommunication2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plRegistTime,
            /* [out] */ LONG __RPC_FAR *plCancelTime,
            /* [out] */ LONG __RPC_FAR *plIntervalTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTCPIPProtocol )( 
            IEZNcCommunication2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszIPAddress,
            /* [in] */ LONG lPort,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcCommunication2Vtbl;

    interface IEZNcCommunication2
    {
        CONST_VTBL struct IEZNcCommunication2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcCommunication2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcCommunication2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcCommunication2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcCommunication2_Open(This,lSystemType,lMachine,lTimeOut,plRet)	\
    (This)->lpVtbl -> Open(This,lSystemType,lMachine,lTimeOut,plRet)

#define IEZNcCommunication2_Close(This,plRet)	\
    (This)->lpVtbl -> Close(This,plRet)

#define IEZNcCommunication2_CommActivate(This,lActivate,plRet)	\
    (This)->lpVtbl -> CommActivate(This,lActivate,plRet)

#define IEZNcCommunication2_SetHead(This,lHead,plRet)	\
    (This)->lpVtbl -> SetHead(This,lHead,plRet)

#define IEZNcCommunication2_GetHead(This,plHead,plRet)	\
    (This)->lpVtbl -> GetHead(This,plHead,plRet)


#define IEZNcCommunication2_SetModalCondition(This,lRegistTime,lCancelTime,lIntervalTime,plRet)	\
    (This)->lpVtbl -> SetModalCondition(This,lRegistTime,lCancelTime,lIntervalTime,plRet)

#define IEZNcCommunication2_GetModalCondition(This,plRegistTime,plCancelTime,plIntervalTime,plRet)	\
    (This)->lpVtbl -> GetModalCondition(This,plRegistTime,plCancelTime,plIntervalTime,plRet)

#define IEZNcCommunication2_SetTCPIPProtocol(This,lpcwszIPAddress,lPort,plRet)	\
    (This)->lpVtbl -> SetTCPIPProtocol(This,lpcwszIPAddress,lPort,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommunication2_SetModalCondition_Proxy( 
    IEZNcCommunication2 __RPC_FAR * This,
    /* [in] */ LONG lRegistTime,
    /* [in] */ LONG lCancelTime,
    /* [in] */ LONG lIntervalTime,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommunication2_SetModalCondition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommunication2_GetModalCondition_Proxy( 
    IEZNcCommunication2 __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *plRegistTime,
    /* [out] */ LONG __RPC_FAR *plCancelTime,
    /* [out] */ LONG __RPC_FAR *plIntervalTime,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommunication2_GetModalCondition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommunication2_SetTCPIPProtocol_Proxy( 
    IEZNcCommunication2 __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszIPAddress,
    /* [in] */ LONG lPort,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommunication2_SetTCPIPProtocol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcCommunication2_INTERFACE_DEFINED__ */


#ifndef __IEZNcSubFunction_INTERFACE_DEFINED__
#define __IEZNcSubFunction_INTERFACE_DEFINED__

/* interface IEZNcSubFunction */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcSubFunction;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("E0580F2B-5E97-4F19-AFAB-653D508FFDDB")
    interface IEZNcSubFunction : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ChangeInit( 
            /* [in] */ LONG lSystemType,
            /* [in] */ LONG lReserve1,
            /* [in] */ LONG lReserve2,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetToolLifeValueOfFile( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetToolLifeValueOfFile( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwMode,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSpareToolOfFile( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwNo,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetSpareToolOfFile( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwMode,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwNo,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetToolWorkOffsetOfFile( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lHead,
            /* [in] */ LONG lIndex,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszAxis,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetToolWorkOffsetOfFile( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [in] */ LONG lHead,
            /* [in] */ LONG lIndex,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszAxis,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcSubFunctionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcSubFunction __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcSubFunction __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcSubFunction __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeInit )( 
            IEZNcSubFunction __RPC_FAR * This,
            /* [in] */ LONG lSystemType,
            /* [in] */ LONG lReserve1,
            /* [in] */ LONG lReserve2,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeValueOfFile )( 
            IEZNcSubFunction __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeValueOfFile )( 
            IEZNcSubFunction __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwMode,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpareToolOfFile )( 
            IEZNcSubFunction __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwNo,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSpareToolOfFile )( 
            IEZNcSubFunction __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwMode,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwNo,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolWorkOffsetOfFile )( 
            IEZNcSubFunction __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lHead,
            /* [in] */ LONG lIndex,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszAxis,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolWorkOffsetOfFile )( 
            IEZNcSubFunction __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [in] */ LONG lHead,
            /* [in] */ LONG lIndex,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszAxis,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcSubFunctionVtbl;

    interface IEZNcSubFunction
    {
        CONST_VTBL struct IEZNcSubFunctionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcSubFunction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcSubFunction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcSubFunction_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcSubFunction_ChangeInit(This,lSystemType,lReserve1,lReserve2,plRet)	\
    (This)->lpVtbl -> ChangeInit(This,lSystemType,lReserve1,lReserve2,plRet)

#define IEZNcSubFunction_GetToolLifeValueOfFile(This,lpcwszFileName,dwHead,dwToolNo,lpppwszData,plRet)	\
    (This)->lpVtbl -> GetToolLifeValueOfFile(This,lpcwszFileName,dwHead,dwToolNo,lpppwszData,plRet)

#define IEZNcSubFunction_SetToolLifeValueOfFile(This,lpcwszFileName,dwMode,dwHead,dwToolNo,lppcwszData,plRet)	\
    (This)->lpVtbl -> SetToolLifeValueOfFile(This,lpcwszFileName,dwMode,dwHead,dwToolNo,lppcwszData,plRet)

#define IEZNcSubFunction_GetSpareToolOfFile(This,lpcwszFileName,dwHead,dwNo,lpppwszData,plRet)	\
    (This)->lpVtbl -> GetSpareToolOfFile(This,lpcwszFileName,dwHead,dwNo,lpppwszData,plRet)

#define IEZNcSubFunction_SetSpareToolOfFile(This,lpcwszFileName,dwMode,dwHead,dwNo,lppcwszData,plRet)	\
    (This)->lpVtbl -> SetSpareToolOfFile(This,lpcwszFileName,dwMode,dwHead,dwNo,lppcwszData,plRet)

#define IEZNcSubFunction_GetToolWorkOffsetOfFile(This,lpcwszFileName,lHead,lIndex,lppcwszAxis,lpppwszData,plRet)	\
    (This)->lpVtbl -> GetToolWorkOffsetOfFile(This,lpcwszFileName,lHead,lIndex,lppcwszAxis,lpppwszData,plRet)

#define IEZNcSubFunction_SetToolWorkOffsetOfFile(This,lpcwszFileName,lMode,lHead,lIndex,lppcwszAxis,lppcwszData,plRet)	\
    (This)->lpVtbl -> SetToolWorkOffsetOfFile(This,lpcwszFileName,lMode,lHead,lIndex,lppcwszAxis,lppcwszData,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSubFunction_ChangeInit_Proxy( 
    IEZNcSubFunction __RPC_FAR * This,
    /* [in] */ LONG lSystemType,
    /* [in] */ LONG lReserve1,
    /* [in] */ LONG lReserve2,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSubFunction_ChangeInit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSubFunction_GetToolLifeValueOfFile_Proxy( 
    IEZNcSubFunction __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [in] */ DWORD dwHead,
    /* [in] */ DWORD dwToolNo,
    /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSubFunction_GetToolLifeValueOfFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSubFunction_SetToolLifeValueOfFile_Proxy( 
    IEZNcSubFunction __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [in] */ DWORD dwMode,
    /* [in] */ DWORD dwHead,
    /* [in] */ DWORD dwToolNo,
    /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSubFunction_SetToolLifeValueOfFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSubFunction_GetSpareToolOfFile_Proxy( 
    IEZNcSubFunction __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [in] */ DWORD dwHead,
    /* [in] */ DWORD dwNo,
    /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSubFunction_GetSpareToolOfFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSubFunction_SetSpareToolOfFile_Proxy( 
    IEZNcSubFunction __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [in] */ DWORD dwMode,
    /* [in] */ DWORD dwHead,
    /* [in] */ DWORD dwNo,
    /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSubFunction_SetSpareToolOfFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSubFunction_GetToolWorkOffsetOfFile_Proxy( 
    IEZNcSubFunction __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [in] */ LONG lHead,
    /* [in] */ LONG lIndex,
    /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszAxis,
    /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSubFunction_GetToolWorkOffsetOfFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSubFunction_SetToolWorkOffsetOfFile_Proxy( 
    IEZNcSubFunction __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [in] */ LONG lMode,
    /* [in] */ LONG lHead,
    /* [in] */ LONG lIndex,
    /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszAxis,
    /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSubFunction_SetToolWorkOffsetOfFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcSubFunction_INTERFACE_DEFINED__ */


#ifndef __IEZNcSubFunction2_INTERFACE_DEFINED__
#define __IEZNcSubFunction2_INTERFACE_DEFINED__

/* interface IEZNcSubFunction2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcSubFunction2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("AD436D8E-7784-4dd3-83A1-04BD2D11B032")
    interface IEZNcSubFunction2 : public IEZNcSubFunction
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetToolLifeValueOfFile2( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetToolLifeValueOfFile2( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwMode,
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcSubFunction2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcSubFunction2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcSubFunction2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcSubFunction2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeInit )( 
            IEZNcSubFunction2 __RPC_FAR * This,
            /* [in] */ LONG lSystemType,
            /* [in] */ LONG lReserve1,
            /* [in] */ LONG lReserve2,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeValueOfFile )( 
            IEZNcSubFunction2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeValueOfFile )( 
            IEZNcSubFunction2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwMode,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpareToolOfFile )( 
            IEZNcSubFunction2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwNo,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSpareToolOfFile )( 
            IEZNcSubFunction2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwMode,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwNo,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolWorkOffsetOfFile )( 
            IEZNcSubFunction2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lHead,
            /* [in] */ LONG lIndex,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszAxis,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolWorkOffsetOfFile )( 
            IEZNcSubFunction2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [in] */ LONG lHead,
            /* [in] */ LONG lIndex,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszAxis,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeValueOfFile2 )( 
            IEZNcSubFunction2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeValueOfFile2 )( 
            IEZNcSubFunction2 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwMode,
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcSubFunction2Vtbl;

    interface IEZNcSubFunction2
    {
        CONST_VTBL struct IEZNcSubFunction2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcSubFunction2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcSubFunction2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcSubFunction2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcSubFunction2_ChangeInit(This,lSystemType,lReserve1,lReserve2,plRet)	\
    (This)->lpVtbl -> ChangeInit(This,lSystemType,lReserve1,lReserve2,plRet)

#define IEZNcSubFunction2_GetToolLifeValueOfFile(This,lpcwszFileName,dwHead,dwToolNo,lpppwszData,plRet)	\
    (This)->lpVtbl -> GetToolLifeValueOfFile(This,lpcwszFileName,dwHead,dwToolNo,lpppwszData,plRet)

#define IEZNcSubFunction2_SetToolLifeValueOfFile(This,lpcwszFileName,dwMode,dwHead,dwToolNo,lppcwszData,plRet)	\
    (This)->lpVtbl -> SetToolLifeValueOfFile(This,lpcwszFileName,dwMode,dwHead,dwToolNo,lppcwszData,plRet)

#define IEZNcSubFunction2_GetSpareToolOfFile(This,lpcwszFileName,dwHead,dwNo,lpppwszData,plRet)	\
    (This)->lpVtbl -> GetSpareToolOfFile(This,lpcwszFileName,dwHead,dwNo,lpppwszData,plRet)

#define IEZNcSubFunction2_SetSpareToolOfFile(This,lpcwszFileName,dwMode,dwHead,dwNo,lppcwszData,plRet)	\
    (This)->lpVtbl -> SetSpareToolOfFile(This,lpcwszFileName,dwMode,dwHead,dwNo,lppcwszData,plRet)

#define IEZNcSubFunction2_GetToolWorkOffsetOfFile(This,lpcwszFileName,lHead,lIndex,lppcwszAxis,lpppwszData,plRet)	\
    (This)->lpVtbl -> GetToolWorkOffsetOfFile(This,lpcwszFileName,lHead,lIndex,lppcwszAxis,lpppwszData,plRet)

#define IEZNcSubFunction2_SetToolWorkOffsetOfFile(This,lpcwszFileName,lMode,lHead,lIndex,lppcwszAxis,lppcwszData,plRet)	\
    (This)->lpVtbl -> SetToolWorkOffsetOfFile(This,lpcwszFileName,lMode,lHead,lIndex,lppcwszAxis,lppcwszData,plRet)


#define IEZNcSubFunction2_GetToolLifeValueOfFile2(This,lpcwszFileName,dwGroup,dwHead,dwToolNo,lpppwszData,plRet)	\
    (This)->lpVtbl -> GetToolLifeValueOfFile2(This,lpcwszFileName,dwGroup,dwHead,dwToolNo,lpppwszData,plRet)

#define IEZNcSubFunction2_SetToolLifeValueOfFile2(This,lpcwszFileName,dwMode,dwGroup,dwHead,dwToolNo,lppcwszData,plRet)	\
    (This)->lpVtbl -> SetToolLifeValueOfFile2(This,lpcwszFileName,dwMode,dwGroup,dwHead,dwToolNo,lppcwszData,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSubFunction2_GetToolLifeValueOfFile2_Proxy( 
    IEZNcSubFunction2 __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [in] */ DWORD dwGroup,
    /* [in] */ DWORD dwHead,
    /* [in] */ DWORD dwToolNo,
    /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSubFunction2_GetToolLifeValueOfFile2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSubFunction2_SetToolLifeValueOfFile2_Proxy( 
    IEZNcSubFunction2 __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [in] */ DWORD dwMode,
    /* [in] */ DWORD dwGroup,
    /* [in] */ DWORD dwHead,
    /* [in] */ DWORD dwToolNo,
    /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSubFunction2_SetToolLifeValueOfFile2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcSubFunction2_INTERFACE_DEFINED__ */


#ifndef __IEZNcSubFunction3_INTERFACE_DEFINED__
#define __IEZNcSubFunction3_INTERFACE_DEFINED__

/* interface IEZNcSubFunction3 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcSubFunction3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("7513A636-A850-4017-8C40-00E5632715F3")
    interface IEZNcSubFunction3 : public IEZNcSubFunction2
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ChangeInit2( 
            /* [in] */ LONG lSystemType,
            /* [in] */ LONG lReserve1,
            /* [in] */ LONG lReserve2,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcSubFunction3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcSubFunction3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcSubFunction3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcSubFunction3 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeInit )( 
            IEZNcSubFunction3 __RPC_FAR * This,
            /* [in] */ LONG lSystemType,
            /* [in] */ LONG lReserve1,
            /* [in] */ LONG lReserve2,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeValueOfFile )( 
            IEZNcSubFunction3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeValueOfFile )( 
            IEZNcSubFunction3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwMode,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpareToolOfFile )( 
            IEZNcSubFunction3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwNo,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSpareToolOfFile )( 
            IEZNcSubFunction3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwMode,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwNo,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolWorkOffsetOfFile )( 
            IEZNcSubFunction3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lHead,
            /* [in] */ LONG lIndex,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszAxis,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolWorkOffsetOfFile )( 
            IEZNcSubFunction3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [in] */ LONG lHead,
            /* [in] */ LONG lIndex,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszAxis,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolLifeValueOfFile2 )( 
            IEZNcSubFunction3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *__RPC_FAR *lpppwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToolLifeValueOfFile2 )( 
            IEZNcSubFunction3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ DWORD dwMode,
            /* [in] */ DWORD dwGroup,
            /* [in] */ DWORD dwHead,
            /* [in] */ DWORD dwToolNo,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChangeInit2 )( 
            IEZNcSubFunction3 __RPC_FAR * This,
            /* [in] */ LONG lSystemType,
            /* [in] */ LONG lReserve1,
            /* [in] */ LONG lReserve2,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcSubFunction3Vtbl;

    interface IEZNcSubFunction3
    {
        CONST_VTBL struct IEZNcSubFunction3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcSubFunction3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcSubFunction3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcSubFunction3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcSubFunction3_ChangeInit(This,lSystemType,lReserve1,lReserve2,plRet)	\
    (This)->lpVtbl -> ChangeInit(This,lSystemType,lReserve1,lReserve2,plRet)

#define IEZNcSubFunction3_GetToolLifeValueOfFile(This,lpcwszFileName,dwHead,dwToolNo,lpppwszData,plRet)	\
    (This)->lpVtbl -> GetToolLifeValueOfFile(This,lpcwszFileName,dwHead,dwToolNo,lpppwszData,plRet)

#define IEZNcSubFunction3_SetToolLifeValueOfFile(This,lpcwszFileName,dwMode,dwHead,dwToolNo,lppcwszData,plRet)	\
    (This)->lpVtbl -> SetToolLifeValueOfFile(This,lpcwszFileName,dwMode,dwHead,dwToolNo,lppcwszData,plRet)

#define IEZNcSubFunction3_GetSpareToolOfFile(This,lpcwszFileName,dwHead,dwNo,lpppwszData,plRet)	\
    (This)->lpVtbl -> GetSpareToolOfFile(This,lpcwszFileName,dwHead,dwNo,lpppwszData,plRet)

#define IEZNcSubFunction3_SetSpareToolOfFile(This,lpcwszFileName,dwMode,dwHead,dwNo,lppcwszData,plRet)	\
    (This)->lpVtbl -> SetSpareToolOfFile(This,lpcwszFileName,dwMode,dwHead,dwNo,lppcwszData,plRet)

#define IEZNcSubFunction3_GetToolWorkOffsetOfFile(This,lpcwszFileName,lHead,lIndex,lppcwszAxis,lpppwszData,plRet)	\
    (This)->lpVtbl -> GetToolWorkOffsetOfFile(This,lpcwszFileName,lHead,lIndex,lppcwszAxis,lpppwszData,plRet)

#define IEZNcSubFunction3_SetToolWorkOffsetOfFile(This,lpcwszFileName,lMode,lHead,lIndex,lppcwszAxis,lppcwszData,plRet)	\
    (This)->lpVtbl -> SetToolWorkOffsetOfFile(This,lpcwszFileName,lMode,lHead,lIndex,lppcwszAxis,lppcwszData,plRet)


#define IEZNcSubFunction3_GetToolLifeValueOfFile2(This,lpcwszFileName,dwGroup,dwHead,dwToolNo,lpppwszData,plRet)	\
    (This)->lpVtbl -> GetToolLifeValueOfFile2(This,lpcwszFileName,dwGroup,dwHead,dwToolNo,lpppwszData,plRet)

#define IEZNcSubFunction3_SetToolLifeValueOfFile2(This,lpcwszFileName,dwMode,dwGroup,dwHead,dwToolNo,lppcwszData,plRet)	\
    (This)->lpVtbl -> SetToolLifeValueOfFile2(This,lpcwszFileName,dwMode,dwGroup,dwHead,dwToolNo,lppcwszData,plRet)


#define IEZNcSubFunction3_ChangeInit2(This,lSystemType,lReserve1,lReserve2,plRet)	\
    (This)->lpVtbl -> ChangeInit2(This,lSystemType,lReserve1,lReserve2,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSubFunction3_ChangeInit2_Proxy( 
    IEZNcSubFunction3 __RPC_FAR * This,
    /* [in] */ LONG lSystemType,
    /* [in] */ LONG lReserve1,
    /* [in] */ LONG lReserve2,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSubFunction3_ChangeInit2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcSubFunction3_INTERFACE_DEFINED__ */


#ifndef __IEZNcCommand2_INTERFACE_DEFINED__
#define __IEZNcCommand2_INTERFACE_DEFINED__

/* interface IEZNcCommand2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcCommand2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("33741E3A-42DF-448e-AA5E-8B0EC24F1C70")
    interface IEZNcCommand2 : public IEZNcCommand
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCommand2( 
            /* [in] */ LONG lType,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCommand2( 
            /* [in] */ LONG lType,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcCommand2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcCommand2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcCommand2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcCommand2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGCodeCommand )( 
            IEZNcCommand2 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [out] */ DOUBLE __RPC_FAR *pdValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToolCommand )( 
            IEZNcCommand2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFeedCommand )( 
            IEZNcCommand2 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [out] */ DOUBLE __RPC_FAR *pdValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommand )( 
            IEZNcCommand2 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCommand )( 
            IEZNcCommand2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lType,
            /* [in] */ LONG lValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CommandRegister )( 
            IEZNcCommand2 __RPC_FAR * This,
            /* [in] */ LONG lPriority,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CommandCancel )( 
            IEZNcCommand2 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommand2 )( 
            IEZNcCommand2 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCommand2 )( 
            IEZNcCommand2 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcCommand2Vtbl;

    interface IEZNcCommand2
    {
        CONST_VTBL struct IEZNcCommand2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcCommand2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcCommand2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcCommand2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcCommand2_GetGCodeCommand(This,lType,pdValue,plRet)	\
    (This)->lpVtbl -> GetGCodeCommand(This,lType,pdValue,plRet)

#define IEZNcCommand2_GetToolCommand(This,lAxisNo,lType,plValue,plRet)	\
    (This)->lpVtbl -> GetToolCommand(This,lAxisNo,lType,plValue,plRet)

#define IEZNcCommand2_GetFeedCommand(This,lType,pdValue,plRet)	\
    (This)->lpVtbl -> GetFeedCommand(This,lType,pdValue,plRet)

#define IEZNcCommand2_GetCommand(This,lType,plValue,plRet)	\
    (This)->lpVtbl -> GetCommand(This,lType,plValue,plRet)

#define IEZNcCommand2_SetCommand(This,lAxisNo,lType,lValue,plRet)	\
    (This)->lpVtbl -> SetCommand(This,lAxisNo,lType,lValue,plRet)

#define IEZNcCommand2_CommandRegister(This,lPriority,plRet)	\
    (This)->lpVtbl -> CommandRegister(This,lPriority,plRet)

#define IEZNcCommand2_CommandCancel(This,plRet)	\
    (This)->lpVtbl -> CommandCancel(This,plRet)


#define IEZNcCommand2_GetCommand2(This,lType,lIndex,plValue,plRet)	\
    (This)->lpVtbl -> GetCommand2(This,lType,lIndex,plValue,plRet)

#define IEZNcCommand2_SetCommand2(This,lType,lIndex,lValue,plRet)	\
    (This)->lpVtbl -> SetCommand2(This,lType,lIndex,lValue,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommand2_GetCommand2_Proxy( 
    IEZNcCommand2 __RPC_FAR * This,
    /* [in] */ LONG lType,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommand2_GetCommand2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommand2_SetCommand2_Proxy( 
    IEZNcCommand2 __RPC_FAR * This,
    /* [in] */ LONG lType,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommand2_SetCommand2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcCommand2_INTERFACE_DEFINED__ */


#ifndef __IEZNcProgram2_INTERFACE_DEFINED__
#define __IEZNcProgram2_INTERFACE_DEFINED__

/* interface IEZNcProgram2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcProgram2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("706EF8FD-28A1-45d8-9CB0-0FC8CD1D7E0C")
    interface IEZNcProgram2 : public IEZNcProgram
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetProgramNumber2( 
            /* [in] */ LONG lProgramType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszProgramNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCurrentBlockByByte( 
            /* [out] */ LONG __RPC_FAR *pdSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcProgram2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcProgram2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcProgram2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcProgram2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CurrentBlockRead )( 
            IEZNcProgram2 __RPC_FAR * This,
            /* [in] */ LONG lBlockNumber,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszProgramData,
            /* [out] */ LONG __RPC_FAR *plCurrentBlockNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProgramNumber )( 
            IEZNcProgram2 __RPC_FAR * This,
            /* [in] */ LONG lProgramType,
            /* [out] */ LONG __RPC_FAR *plProgramNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSequenceNumber )( 
            IEZNcProgram2 __RPC_FAR * This,
            /* [in] */ LONG lProgramType,
            /* [out] */ LONG __RPC_FAR *plSequenceNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBlockNumber )( 
            IEZNcProgram2 __RPC_FAR * This,
            /* [in] */ LONG lProgramType,
            /* [out] */ LONG __RPC_FAR *plBlockNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSubProLevel )( 
            IEZNcProgram2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plLevel,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInformation )( 
            IEZNcProgram2 __RPC_FAR * This,
            /* [in] */ LONG lInfoType,
            /* [out] */ LONG __RPC_FAR *plInfoData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProgramNumber2 )( 
            IEZNcProgram2 __RPC_FAR * This,
            /* [in] */ LONG lProgramType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszProgramNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCurrentBlockByByte )( 
            IEZNcProgram2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *pdSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcProgram2Vtbl;

    interface IEZNcProgram2
    {
        CONST_VTBL struct IEZNcProgram2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcProgram2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcProgram2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcProgram2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcProgram2_CurrentBlockRead(This,lBlockNumber,lppwszProgramData,plCurrentBlockNo,plRet)	\
    (This)->lpVtbl -> CurrentBlockRead(This,lBlockNumber,lppwszProgramData,plCurrentBlockNo,plRet)

#define IEZNcProgram2_GetProgramNumber(This,lProgramType,plProgramNo,plRet)	\
    (This)->lpVtbl -> GetProgramNumber(This,lProgramType,plProgramNo,plRet)

#define IEZNcProgram2_GetSequenceNumber(This,lProgramType,plSequenceNo,plRet)	\
    (This)->lpVtbl -> GetSequenceNumber(This,lProgramType,plSequenceNo,plRet)

#define IEZNcProgram2_GetBlockNumber(This,lProgramType,plBlockNo,plRet)	\
    (This)->lpVtbl -> GetBlockNumber(This,lProgramType,plBlockNo,plRet)

#define IEZNcProgram2_GetSubProLevel(This,plLevel,plRet)	\
    (This)->lpVtbl -> GetSubProLevel(This,plLevel,plRet)

#define IEZNcProgram2_GetInformation(This,lInfoType,plInfoData,plRet)	\
    (This)->lpVtbl -> GetInformation(This,lInfoType,plInfoData,plRet)


#define IEZNcProgram2_GetProgramNumber2(This,lProgramType,lppwszProgramNo,plRet)	\
    (This)->lpVtbl -> GetProgramNumber2(This,lProgramType,lppwszProgramNo,plRet)

#define IEZNcProgram2_GetCurrentBlockByByte(This,pdSize,plRet)	\
    (This)->lpVtbl -> GetCurrentBlockByByte(This,pdSize,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcProgram2_GetProgramNumber2_Proxy( 
    IEZNcProgram2 __RPC_FAR * This,
    /* [in] */ LONG lProgramType,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszProgramNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcProgram2_GetProgramNumber2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcProgram2_GetCurrentBlockByByte_Proxy( 
    IEZNcProgram2 __RPC_FAR * This,
    /* [out] */ LONG __RPC_FAR *pdSize,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcProgram2_GetCurrentBlockByByte_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcProgram2_INTERFACE_DEFINED__ */


#ifndef __IEZNcFile5_INTERFACE_DEFINED__
#define __IEZNcFile5_INTERFACE_DEFINED__

/* interface IEZNcFile5 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcFile5;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("CAB101CF-63AC-4aee-99CB-15A5206B0D3B")
    interface IEZNcFile5 : public IEZNcFile4
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OpenFile3( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CloseFile2( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Copy2( 
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Delete2( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Rename2( 
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbortFile2( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadFile2( 
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OpenNCFile2( 
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CloseNCFile2( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE AbortNCFile2( 
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadNCFile2( 
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcFile5Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcFile5 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcFile5 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindDir )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [in] */ LONG lFileType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindNextDir )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetDir )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Copy )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Rename )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveInformation )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszDriveInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveSize )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [out] */ LONG __RPC_FAR *plDriveSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenFile )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseFile )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AbortFile )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteFile )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ BYTE __RPC_FAR *pbData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFile )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenFile2 )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenNCFile )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseNCFile )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AbortNCFile )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteNCFile )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ BYTE __RPC_FAR *pbData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadNCFile )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenFile3 )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseFile2 )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Copy2 )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete2 )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Rename2 )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AbortFile2 )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFile2 )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenNCFile2 )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseNCFile2 )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AbortNCFile2 )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadNCFile2 )( 
            IEZNcFile5 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcFile5Vtbl;

    interface IEZNcFile5
    {
        CONST_VTBL struct IEZNcFile5Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcFile5_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcFile5_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcFile5_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcFile5_FindDir(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindDir(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)

#define IEZNcFile5_FindNextDir(This,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindNextDir(This,lppwszFileInfo,plRet)

#define IEZNcFile5_ResetDir(This,plRet)	\
    (This)->lpVtbl -> ResetDir(This,plRet)

#define IEZNcFile5_Copy(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Copy(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile5_Delete(This,lpcwszFileName,plRet)	\
    (This)->lpVtbl -> Delete(This,lpcwszFileName,plRet)

#define IEZNcFile5_Rename(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Rename(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile5_GetDriveInformation(This,lppwszDriveInfo,plRet)	\
    (This)->lpVtbl -> GetDriveInformation(This,lppwszDriveInfo,plRet)

#define IEZNcFile5_GetDriveSize(This,lpcwszDirectoryName,plDriveSize,plRet)	\
    (This)->lpVtbl -> GetDriveSize(This,lpcwszDirectoryName,plDriveSize,plRet)


#define IEZNcFile5_OpenFile(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenFile(This,lpcwszFileName,lMode,plRet)

#define IEZNcFile5_CloseFile(This,plRet)	\
    (This)->lpVtbl -> CloseFile(This,plRet)

#define IEZNcFile5_AbortFile(This,plRet)	\
    (This)->lpVtbl -> AbortFile(This,plRet)

#define IEZNcFile5_WriteFile(This,dwLength,pbData,plRet)	\
    (This)->lpVtbl -> WriteFile(This,dwLength,pbData,plRet)

#define IEZNcFile5_ReadFile(This,dwLength,ppbData,pdwNumRead,plRet)	\
    (This)->lpVtbl -> ReadFile(This,dwLength,ppbData,pdwNumRead,plRet)


#define IEZNcFile5_OpenFile2(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenFile2(This,lpcwszFileName,lMode,plRet)


#define IEZNcFile5_OpenNCFile(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenNCFile(This,lpcwszFileName,lMode,plRet)

#define IEZNcFile5_CloseNCFile(This,plRet)	\
    (This)->lpVtbl -> CloseNCFile(This,plRet)

#define IEZNcFile5_AbortNCFile(This,plRet)	\
    (This)->lpVtbl -> AbortNCFile(This,plRet)

#define IEZNcFile5_WriteNCFile(This,dwLength,pbData,plRet)	\
    (This)->lpVtbl -> WriteNCFile(This,dwLength,pbData,plRet)

#define IEZNcFile5_ReadNCFile(This,dwLength,ppbData,pdwNumRead,plRet)	\
    (This)->lpVtbl -> ReadNCFile(This,dwLength,ppbData,pdwNumRead,plRet)


#define IEZNcFile5_OpenFile3(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenFile3(This,lpcwszFileName,lMode,plRet)

#define IEZNcFile5_CloseFile2(This,plRet)	\
    (This)->lpVtbl -> CloseFile2(This,plRet)

#define IEZNcFile5_Copy2(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Copy2(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile5_Delete2(This,lpcwszFileName,plRet)	\
    (This)->lpVtbl -> Delete2(This,lpcwszFileName,plRet)

#define IEZNcFile5_Rename2(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Rename2(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile5_AbortFile2(This,plRet)	\
    (This)->lpVtbl -> AbortFile2(This,plRet)

#define IEZNcFile5_ReadFile2(This,dwLength,ppbData,pdwNumRead,plRet)	\
    (This)->lpVtbl -> ReadFile2(This,dwLength,ppbData,pdwNumRead,plRet)

#define IEZNcFile5_OpenNCFile2(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenNCFile2(This,lpcwszFileName,lMode,plRet)

#define IEZNcFile5_CloseNCFile2(This,plRet)	\
    (This)->lpVtbl -> CloseNCFile2(This,plRet)

#define IEZNcFile5_AbortNCFile2(This,plRet)	\
    (This)->lpVtbl -> AbortNCFile2(This,plRet)

#define IEZNcFile5_ReadNCFile2(This,dwLength,ppbData,pdwNumRead,plRet)	\
    (This)->lpVtbl -> ReadNCFile2(This,dwLength,ppbData,pdwNumRead,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile5_OpenFile3_Proxy( 
    IEZNcFile5 __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [in] */ LONG lMode,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile5_OpenFile3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile5_CloseFile2_Proxy( 
    IEZNcFile5 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile5_CloseFile2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile5_Copy2_Proxy( 
    IEZNcFile5 __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
    /* [string][in] */ LPCOLESTR lpcwszDstFileName,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile5_Copy2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile5_Delete2_Proxy( 
    IEZNcFile5 __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile5_Delete2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile5_Rename2_Proxy( 
    IEZNcFile5 __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
    /* [string][in] */ LPCOLESTR lpcwszDstFileName,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile5_Rename2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile5_AbortFile2_Proxy( 
    IEZNcFile5 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile5_AbortFile2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile5_ReadFile2_Proxy( 
    IEZNcFile5 __RPC_FAR * This,
    /* [in] */ DWORD dwLength,
    /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
    /* [out] */ DWORD __RPC_FAR *pdwNumRead,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile5_ReadFile2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile5_OpenNCFile2_Proxy( 
    IEZNcFile5 __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszFileName,
    /* [in] */ LONG lMode,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile5_OpenNCFile2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile5_CloseNCFile2_Proxy( 
    IEZNcFile5 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile5_CloseNCFile2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile5_AbortNCFile2_Proxy( 
    IEZNcFile5 __RPC_FAR * This,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile5_AbortNCFile2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile5_ReadNCFile2_Proxy( 
    IEZNcFile5 __RPC_FAR * This,
    /* [in] */ DWORD dwLength,
    /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
    /* [out] */ DWORD __RPC_FAR *pdwNumRead,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile5_ReadNCFile2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcFile5_INTERFACE_DEFINED__ */


#ifndef __IEZNcATC2_INTERFACE_DEFINED__
#define __IEZNcATC2_INTERFACE_DEFINED__

/* interface IEZNcATC2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcATC2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("7E457455-A748-41e3-AABF-BE936EF60689")
    interface IEZNcATC2 : public IEZNcATC
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMGNPot3( 
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetMGNPot3( 
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcATC2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcATC2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcATC2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNControl )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNSize )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNReady )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [in] */ LONG lReady,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNPot )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNPot )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNPotEx )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNPotEx )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNAux )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNAux )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNSize2 )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNPot2 )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNPot2 )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNPot3 )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNPot3 )( 
            IEZNcATC2 __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcATC2Vtbl;

    interface IEZNcATC2
    {
        CONST_VTBL struct IEZNcATC2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcATC2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcATC2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcATC2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcATC2_GetMGNControl(This,plData,plRet)	\
    (This)->lpVtbl -> GetMGNControl(This,plData,plRet)

#define IEZNcATC2_GetMGNSize(This,plSize,plRet)	\
    (This)->lpVtbl -> GetMGNSize(This,plSize,plRet)

#define IEZNcATC2_GetMGNReady(This,lReady,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNReady(This,lReady,plToolNo,plRet)

#define IEZNcATC2_GetMGNPot(This,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNPot(This,lIndex,plToolNo,plRet)

#define IEZNcATC2_SetMGNPot(This,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetMGNPot(This,lIndex,lToolNo,plRet)

#define IEZNcATC2_GetMGNPotEx(This,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNPotEx(This,lIndex,plToolNo,plRet)

#define IEZNcATC2_SetMGNPotEx(This,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetMGNPotEx(This,lIndex,lToolNo,plRet)

#define IEZNcATC2_GetMGNAux(This,plData,plRet)	\
    (This)->lpVtbl -> GetMGNAux(This,plData,plRet)

#define IEZNcATC2_SetMGNAux(This,lData,plRet)	\
    (This)->lpVtbl -> SetMGNAux(This,lData,plRet)

#define IEZNcATC2_GetMGNSize2(This,lMagazineNo,plSize,plRet)	\
    (This)->lpVtbl -> GetMGNSize2(This,lMagazineNo,plSize,plRet)

#define IEZNcATC2_GetMGNPot2(This,lMagazineNo,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNPot2(This,lMagazineNo,lIndex,plToolNo,plRet)

#define IEZNcATC2_SetMGNPot2(This,lMagazineNo,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetMGNPot2(This,lMagazineNo,lIndex,lToolNo,plRet)


#define IEZNcATC2_GetMGNPot3(This,lMagazineNo,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNPot3(This,lMagazineNo,lIndex,plToolNo,plRet)

#define IEZNcATC2_SetMGNPot3(This,lMagazineNo,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetMGNPot3(This,lMagazineNo,lIndex,lToolNo,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC2_GetMGNPot3_Proxy( 
    IEZNcATC2 __RPC_FAR * This,
    /* [in] */ LONG lMagazineNo,
    /* [in] */ LONG lIndex,
    /* [out] */ LONG __RPC_FAR *plToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC2_GetMGNPot3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC2_SetMGNPot3_Proxy( 
    IEZNcATC2 __RPC_FAR * This,
    /* [in] */ LONG lMagazineNo,
    /* [in] */ LONG lIndex,
    /* [in] */ LONG lToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC2_SetMGNPot3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcATC2_INTERFACE_DEFINED__ */


#ifndef __IEZNcCommunication3_INTERFACE_DEFINED__
#define __IEZNcCommunication3_INTERFACE_DEFINED__

/* interface IEZNcCommunication3 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcCommunication3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("62A22C79-F26F-4842-BB82-165E95B15424")
    interface IEZNcCommunication3 : public IEZNcCommunication2
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Open2( 
            /* [in] */ LONG lSystemType,
            /* [in] */ LONG lMachine,
            /* [in] */ LONG lTimeOut,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetMelsecProtocol( 
            /* [in] */ EZNCST_OPEN __RPC_FAR *pstOpen,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcCommunication3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcCommunication3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcCommunication3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcCommunication3 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open )( 
            IEZNcCommunication3 __RPC_FAR * This,
            /* [in] */ LONG lSystemType,
            /* [in] */ LONG lMachine,
            /* [in] */ LONG lTimeOut,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Close )( 
            IEZNcCommunication3 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [hidden][helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CommActivate )( 
            IEZNcCommunication3 __RPC_FAR * This,
            /* [in] */ LONG lActivate,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetHead )( 
            IEZNcCommunication3 __RPC_FAR * This,
            /* [in] */ LONG lHead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHead )( 
            IEZNcCommunication3 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plHead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetModalCondition )( 
            IEZNcCommunication3 __RPC_FAR * This,
            /* [in] */ LONG lRegistTime,
            /* [in] */ LONG lCancelTime,
            /* [in] */ LONG lIntervalTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetModalCondition )( 
            IEZNcCommunication3 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plRegistTime,
            /* [out] */ LONG __RPC_FAR *plCancelTime,
            /* [out] */ LONG __RPC_FAR *plIntervalTime,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTCPIPProtocol )( 
            IEZNcCommunication3 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszIPAddress,
            /* [in] */ LONG lPort,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Open2 )( 
            IEZNcCommunication3 __RPC_FAR * This,
            /* [in] */ LONG lSystemType,
            /* [in] */ LONG lMachine,
            /* [in] */ LONG lTimeOut,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMelsecProtocol )( 
            IEZNcCommunication3 __RPC_FAR * This,
            /* [in] */ EZNCST_OPEN __RPC_FAR *pstOpen,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcCommunication3Vtbl;

    interface IEZNcCommunication3
    {
        CONST_VTBL struct IEZNcCommunication3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcCommunication3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcCommunication3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcCommunication3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcCommunication3_Open(This,lSystemType,lMachine,lTimeOut,plRet)	\
    (This)->lpVtbl -> Open(This,lSystemType,lMachine,lTimeOut,plRet)

#define IEZNcCommunication3_Close(This,plRet)	\
    (This)->lpVtbl -> Close(This,plRet)

#define IEZNcCommunication3_CommActivate(This,lActivate,plRet)	\
    (This)->lpVtbl -> CommActivate(This,lActivate,plRet)

#define IEZNcCommunication3_SetHead(This,lHead,plRet)	\
    (This)->lpVtbl -> SetHead(This,lHead,plRet)

#define IEZNcCommunication3_GetHead(This,plHead,plRet)	\
    (This)->lpVtbl -> GetHead(This,plHead,plRet)


#define IEZNcCommunication3_SetModalCondition(This,lRegistTime,lCancelTime,lIntervalTime,plRet)	\
    (This)->lpVtbl -> SetModalCondition(This,lRegistTime,lCancelTime,lIntervalTime,plRet)

#define IEZNcCommunication3_GetModalCondition(This,plRegistTime,plCancelTime,plIntervalTime,plRet)	\
    (This)->lpVtbl -> GetModalCondition(This,plRegistTime,plCancelTime,plIntervalTime,plRet)

#define IEZNcCommunication3_SetTCPIPProtocol(This,lpcwszIPAddress,lPort,plRet)	\
    (This)->lpVtbl -> SetTCPIPProtocol(This,lpcwszIPAddress,lPort,plRet)


#define IEZNcCommunication3_Open2(This,lSystemType,lMachine,lTimeOut,plRet)	\
    (This)->lpVtbl -> Open2(This,lSystemType,lMachine,lTimeOut,plRet)

#define IEZNcCommunication3_SetMelsecProtocol(This,pstOpen,plRet)	\
    (This)->lpVtbl -> SetMelsecProtocol(This,pstOpen,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommunication3_Open2_Proxy( 
    IEZNcCommunication3 __RPC_FAR * This,
    /* [in] */ LONG lSystemType,
    /* [in] */ LONG lMachine,
    /* [in] */ LONG lTimeOut,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommunication3_Open2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcCommunication3_SetMelsecProtocol_Proxy( 
    IEZNcCommunication3 __RPC_FAR * This,
    /* [in] */ EZNCST_OPEN __RPC_FAR *pstOpen,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcCommunication3_SetMelsecProtocol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcCommunication3_INTERFACE_DEFINED__ */


#ifndef __IEZNcATC3_INTERFACE_DEFINED__
#define __IEZNcATC3_INTERFACE_DEFINED__

/* interface IEZNcATC3 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcATC3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("5B6A10F0-C17C-4a93-8ED6-D880385CBC53")
    interface IEZNcATC3 : public IEZNcATC2
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMGNReady2( 
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lReady,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcATC3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcATC3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcATC3 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNControl )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNSize )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNReady )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [in] */ LONG lReady,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNPot )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNPot )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNPotEx )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNPotEx )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNAux )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNAux )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNSize2 )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [out] */ LONG __RPC_FAR *plSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNPot2 )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNPot2 )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNPot3 )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMGNPot3 )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMGNReady2 )( 
            IEZNcATC3 __RPC_FAR * This,
            /* [in] */ LONG lMagazineNo,
            /* [in] */ LONG lReady,
            /* [out] */ LONG __RPC_FAR *plToolNo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcATC3Vtbl;

    interface IEZNcATC3
    {
        CONST_VTBL struct IEZNcATC3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcATC3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcATC3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcATC3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcATC3_GetMGNControl(This,plData,plRet)	\
    (This)->lpVtbl -> GetMGNControl(This,plData,plRet)

#define IEZNcATC3_GetMGNSize(This,plSize,plRet)	\
    (This)->lpVtbl -> GetMGNSize(This,plSize,plRet)

#define IEZNcATC3_GetMGNReady(This,lReady,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNReady(This,lReady,plToolNo,plRet)

#define IEZNcATC3_GetMGNPot(This,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNPot(This,lIndex,plToolNo,plRet)

#define IEZNcATC3_SetMGNPot(This,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetMGNPot(This,lIndex,lToolNo,plRet)

#define IEZNcATC3_GetMGNPotEx(This,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNPotEx(This,lIndex,plToolNo,plRet)

#define IEZNcATC3_SetMGNPotEx(This,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetMGNPotEx(This,lIndex,lToolNo,plRet)

#define IEZNcATC3_GetMGNAux(This,plData,plRet)	\
    (This)->lpVtbl -> GetMGNAux(This,plData,plRet)

#define IEZNcATC3_SetMGNAux(This,lData,plRet)	\
    (This)->lpVtbl -> SetMGNAux(This,lData,plRet)

#define IEZNcATC3_GetMGNSize2(This,lMagazineNo,plSize,plRet)	\
    (This)->lpVtbl -> GetMGNSize2(This,lMagazineNo,plSize,plRet)

#define IEZNcATC3_GetMGNPot2(This,lMagazineNo,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNPot2(This,lMagazineNo,lIndex,plToolNo,plRet)

#define IEZNcATC3_SetMGNPot2(This,lMagazineNo,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetMGNPot2(This,lMagazineNo,lIndex,lToolNo,plRet)


#define IEZNcATC3_GetMGNPot3(This,lMagazineNo,lIndex,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNPot3(This,lMagazineNo,lIndex,plToolNo,plRet)

#define IEZNcATC3_SetMGNPot3(This,lMagazineNo,lIndex,lToolNo,plRet)	\
    (This)->lpVtbl -> SetMGNPot3(This,lMagazineNo,lIndex,lToolNo,plRet)


#define IEZNcATC3_GetMGNReady2(This,lMagazineNo,lReady,plToolNo,plRet)	\
    (This)->lpVtbl -> GetMGNReady2(This,lMagazineNo,lReady,plToolNo,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcATC3_GetMGNReady2_Proxy( 
    IEZNcATC3 __RPC_FAR * This,
    /* [in] */ LONG lMagazineNo,
    /* [in] */ LONG lReady,
    /* [out] */ LONG __RPC_FAR *plToolNo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcATC3_GetMGNReady2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcATC3_INTERFACE_DEFINED__ */


#ifndef __IEZNcParameter3_INTERFACE_DEFINED__
#define __IEZNcParameter3_INTERFACE_DEFINED__

/* interface IEZNcParameter3 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcParameter3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("3D69AA9E-7845-4739-AF26-2D3402675FBF")
    interface IEZNcParameter3 : public IEZNcParameter2
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetParameterData2( 
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetParameterData2( 
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *lppwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetParameterData3( 
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetParameterData3( 
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *lppwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcParameter3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcParameter3 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcParameter3 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProcessParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProcessParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetControlParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetControlParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAxisParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAxisParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBarrierData )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plDataX,
            /* [out] */ LONG __RPC_FAR *plDataZ,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBarrierData )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDataX,
            /* [in] */ LONG lDataZ,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIoParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIoParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSerialParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDeviceNo,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszDeviceName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSerialParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDeviceNo,
            /* [in] */ LONG lData,
            /* [string][in] */ LPCOLESTR lpcwszDeviceName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWorkOffset )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plOffset,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetWorkOffset )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lOffset,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPositionSwitch )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plDog1,
            /* [out] */ LONG __RPC_FAR *plDog2,
            /* [out] */ LONG __RPC_FAR *plAxisName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPositionSwitch )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lDog1,
            /* [in] */ LONG lDog2,
            /* [in] */ LONG lAxisName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBaseParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBaseParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [string][in] */ LPCOLESTR lpcwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAxisSpecParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAxisSpecParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetToleranceParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetToleranceParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAuxParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAuxParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPlcParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPlcParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMacroParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMacroParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAuxAxisParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAuxAxisParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [string][in] */ LPCOLESTR lpcwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetServoParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetServoParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSPJParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSPJParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSpindleParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [out] */ LONG __RPC_FAR *plData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSpindleParameter )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParameterData )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParameterData )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *lppwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParameterData2 )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParameterData2 )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *lppwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetParameterData3 )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParameterData3 )( 
            IEZNcParameter3 __RPC_FAR * This,
            /* [in] */ LONG lGroup,
            /* [in] */ LONG lItem,
            /* [in] */ LONG lSize,
            /* [in] */ LONG lAxis,
            /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *lppwszValue,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcParameter3Vtbl;

    interface IEZNcParameter3
    {
        CONST_VTBL struct IEZNcParameter3Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcParameter3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcParameter3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcParameter3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcParameter3_GetProcessParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetProcessParameter(This,lIndex,plData,plRet)

#define IEZNcParameter3_SetProcessParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetProcessParameter(This,lIndex,lData,plRet)

#define IEZNcParameter3_GetControlParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetControlParameter(This,lIndex,plData,plRet)

#define IEZNcParameter3_SetControlParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetControlParameter(This,lIndex,lData,plRet)

#define IEZNcParameter3_GetAxisParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetAxisParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter3_SetAxisParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetAxisParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter3_GetBarrierData(This,lAxisNo,lIndex,plDataX,plDataZ,plRet)	\
    (This)->lpVtbl -> GetBarrierData(This,lAxisNo,lIndex,plDataX,plDataZ,plRet)

#define IEZNcParameter3_SetBarrierData(This,lAxisNo,lIndex,lDataX,lDataZ,plRet)	\
    (This)->lpVtbl -> SetBarrierData(This,lAxisNo,lIndex,lDataX,lDataZ,plRet)

#define IEZNcParameter3_GetIoParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetIoParameter(This,lIndex,plData,plRet)

#define IEZNcParameter3_SetIoParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetIoParameter(This,lIndex,lData,plRet)

#define IEZNcParameter3_GetSerialParameter(This,lIndex,lDeviceNo,plData,lppwszDeviceName,plRet)	\
    (This)->lpVtbl -> GetSerialParameter(This,lIndex,lDeviceNo,plData,lppwszDeviceName,plRet)

#define IEZNcParameter3_SetSerialParameter(This,lIndex,lDeviceNo,lData,lpcwszDeviceName,plRet)	\
    (This)->lpVtbl -> SetSerialParameter(This,lIndex,lDeviceNo,lData,lpcwszDeviceName,plRet)

#define IEZNcParameter3_GetWorkOffset(This,lAxisNo,lIndex,plOffset,plRet)	\
    (This)->lpVtbl -> GetWorkOffset(This,lAxisNo,lIndex,plOffset,plRet)

#define IEZNcParameter3_SetWorkOffset(This,lAxisNo,lIndex,lOffset,lMode,plRet)	\
    (This)->lpVtbl -> SetWorkOffset(This,lAxisNo,lIndex,lOffset,lMode,plRet)

#define IEZNcParameter3_GetPositionSwitch(This,lIndex,plDog1,plDog2,plAxisName,plRet)	\
    (This)->lpVtbl -> GetPositionSwitch(This,lIndex,plDog1,plDog2,plAxisName,plRet)

#define IEZNcParameter3_SetPositionSwitch(This,lIndex,lDog1,lDog2,lAxisName,plRet)	\
    (This)->lpVtbl -> SetPositionSwitch(This,lIndex,lDog1,lDog2,lAxisName,plRet)

#define IEZNcParameter3_GetBaseParameter(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetBaseParameter(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)

#define IEZNcParameter3_SetBaseParameter(This,lAxisNo,lIndex,lData,lpcwszBuffer,plRet)	\
    (This)->lpVtbl -> SetBaseParameter(This,lAxisNo,lIndex,lData,lpcwszBuffer,plRet)

#define IEZNcParameter3_GetAxisSpecParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetAxisSpecParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter3_SetAxisSpecParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetAxisSpecParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter3_GetToleranceParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetToleranceParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter3_SetToleranceParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetToleranceParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter3_GetAuxParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetAuxParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter3_SetAuxParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetAuxParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter3_GetPlcParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetPlcParameter(This,lIndex,plData,plRet)

#define IEZNcParameter3_SetPlcParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetPlcParameter(This,lIndex,lData,plRet)

#define IEZNcParameter3_GetMacroParameter(This,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetMacroParameter(This,lIndex,plData,plRet)

#define IEZNcParameter3_SetMacroParameter(This,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetMacroParameter(This,lIndex,lData,plRet)

#define IEZNcParameter3_GetAuxAxisParameter(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetAuxAxisParameter(This,lAxisNo,lIndex,plData,lppwszBuffer,plRet)

#define IEZNcParameter3_SetAuxAxisParameter(This,lAxisNo,lIndex,lData,lpcwszBuffer,plRet)	\
    (This)->lpVtbl -> SetAuxAxisParameter(This,lAxisNo,lIndex,lData,lpcwszBuffer,plRet)

#define IEZNcParameter3_GetServoParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetServoParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter3_SetServoParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetServoParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter3_GetSPJParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetSPJParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter3_SetSPJParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetSPJParameter(This,lAxisNo,lIndex,lData,plRet)

#define IEZNcParameter3_GetSpindleParameter(This,lAxisNo,lIndex,plData,plRet)	\
    (This)->lpVtbl -> GetSpindleParameter(This,lAxisNo,lIndex,plData,plRet)

#define IEZNcParameter3_SetSpindleParameter(This,lAxisNo,lIndex,lData,plRet)	\
    (This)->lpVtbl -> SetSpindleParameter(This,lAxisNo,lIndex,lData,plRet)


#define IEZNcParameter3_SetParameterData(This,lGroup,lItem,lSize,lAxis,lppcwszValue,plRet)	\
    (This)->lpVtbl -> SetParameterData(This,lGroup,lItem,lSize,lAxis,lppcwszValue,plRet)

#define IEZNcParameter3_GetParameterData(This,lGroup,lItem,lSize,lAxis,lppwszValue,plRet)	\
    (This)->lpVtbl -> GetParameterData(This,lGroup,lItem,lSize,lAxis,lppwszValue,plRet)


#define IEZNcParameter3_SetParameterData2(This,lGroup,lItem,lSize,lAxis,lppcwszValue,plRet)	\
    (This)->lpVtbl -> SetParameterData2(This,lGroup,lItem,lSize,lAxis,lppcwszValue,plRet)

#define IEZNcParameter3_GetParameterData2(This,lGroup,lItem,lSize,lAxis,lppwszValue,plRet)	\
    (This)->lpVtbl -> GetParameterData2(This,lGroup,lItem,lSize,lAxis,lppwszValue,plRet)

#define IEZNcParameter3_SetParameterData3(This,lGroup,lItem,lSize,lAxis,lppcwszValue,plRet)	\
    (This)->lpVtbl -> SetParameterData3(This,lGroup,lItem,lSize,lAxis,lppcwszValue,plRet)

#define IEZNcParameter3_GetParameterData3(This,lGroup,lItem,lSize,lAxis,lppwszValue,plRet)	\
    (This)->lpVtbl -> GetParameterData3(This,lGroup,lItem,lSize,lAxis,lppwszValue,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter3_SetParameterData2_Proxy( 
    IEZNcParameter3 __RPC_FAR * This,
    /* [in] */ LONG lGroup,
    /* [in] */ LONG lItem,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lAxis,
    /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter3_SetParameterData2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter3_GetParameterData2_Proxy( 
    IEZNcParameter3 __RPC_FAR * This,
    /* [in] */ LONG lGroup,
    /* [in] */ LONG lItem,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lAxis,
    /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *lppwszValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter3_GetParameterData2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter3_SetParameterData3_Proxy( 
    IEZNcParameter3 __RPC_FAR * This,
    /* [in] */ LONG lGroup,
    /* [in] */ LONG lItem,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lAxis,
    /* [size_is][size_is][in] */ LPCOLESTR __RPC_FAR *lppcwszValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter3_SetParameterData3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcParameter3_GetParameterData3_Proxy( 
    IEZNcParameter3 __RPC_FAR * This,
    /* [in] */ LONG lGroup,
    /* [in] */ LONG lItem,
    /* [in] */ LONG lSize,
    /* [in] */ LONG lAxis,
    /* [size_is][size_is][out] */ LPOLESTR __RPC_FAR *lppwszValue,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcParameter3_GetParameterData3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcParameter3_INTERFACE_DEFINED__ */


#ifndef __IEZNcFile6_INTERFACE_DEFINED__
#define __IEZNcFile6_INTERFACE_DEFINED__

/* interface IEZNcFile6 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcFile6;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("AE3803A9-353D-42b2-903C-98879747570A")
    interface IEZNcFile6 : public IEZNcFile5
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindDir2( 
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [in] */ LONG lFileType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindNextDir2( 
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDriveSize2( 
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [out] */ LONGLONG __RPC_FAR *plDriveSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcFile6Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcFile6 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcFile6 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindDir )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [in] */ LONG lFileType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindNextDir )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetDir )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Copy )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Rename )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveInformation )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszDriveInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveSize )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [out] */ LONG __RPC_FAR *plDriveSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenFile )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseFile )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AbortFile )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteFile )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ BYTE __RPC_FAR *pbData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFile )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenFile2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenNCFile )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseNCFile )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AbortNCFile )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WriteNCFile )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ BYTE __RPC_FAR *pbData,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadNCFile )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenFile3 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseFile2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Copy2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Delete2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Rename2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszSrcFileName,
            /* [string][in] */ LPCOLESTR lpcwszDstFileName,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AbortFile2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadFile2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenNCFile2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszFileName,
            /* [in] */ LONG lMode,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseNCFile2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AbortNCFile2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReadNCFile2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][size_is][out] */ BYTE __RPC_FAR *__RPC_FAR *ppbData,
            /* [out] */ DWORD __RPC_FAR *pdwNumRead,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindDir2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [in] */ LONG lFileType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FindNextDir2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDriveSize2 )( 
            IEZNcFile6 __RPC_FAR * This,
            /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
            /* [out] */ LONGLONG __RPC_FAR *plDriveSize,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcFile6Vtbl;

    interface IEZNcFile6
    {
        CONST_VTBL struct IEZNcFile6Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcFile6_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcFile6_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcFile6_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcFile6_FindDir(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindDir(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)

#define IEZNcFile6_FindNextDir(This,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindNextDir(This,lppwszFileInfo,plRet)

#define IEZNcFile6_ResetDir(This,plRet)	\
    (This)->lpVtbl -> ResetDir(This,plRet)

#define IEZNcFile6_Copy(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Copy(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile6_Delete(This,lpcwszFileName,plRet)	\
    (This)->lpVtbl -> Delete(This,lpcwszFileName,plRet)

#define IEZNcFile6_Rename(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Rename(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile6_GetDriveInformation(This,lppwszDriveInfo,plRet)	\
    (This)->lpVtbl -> GetDriveInformation(This,lppwszDriveInfo,plRet)

#define IEZNcFile6_GetDriveSize(This,lpcwszDirectoryName,plDriveSize,plRet)	\
    (This)->lpVtbl -> GetDriveSize(This,lpcwszDirectoryName,plDriveSize,plRet)


#define IEZNcFile6_OpenFile(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenFile(This,lpcwszFileName,lMode,plRet)

#define IEZNcFile6_CloseFile(This,plRet)	\
    (This)->lpVtbl -> CloseFile(This,plRet)

#define IEZNcFile6_AbortFile(This,plRet)	\
    (This)->lpVtbl -> AbortFile(This,plRet)

#define IEZNcFile6_WriteFile(This,dwLength,pbData,plRet)	\
    (This)->lpVtbl -> WriteFile(This,dwLength,pbData,plRet)

#define IEZNcFile6_ReadFile(This,dwLength,ppbData,pdwNumRead,plRet)	\
    (This)->lpVtbl -> ReadFile(This,dwLength,ppbData,pdwNumRead,plRet)


#define IEZNcFile6_OpenFile2(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenFile2(This,lpcwszFileName,lMode,plRet)


#define IEZNcFile6_OpenNCFile(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenNCFile(This,lpcwszFileName,lMode,plRet)

#define IEZNcFile6_CloseNCFile(This,plRet)	\
    (This)->lpVtbl -> CloseNCFile(This,plRet)

#define IEZNcFile6_AbortNCFile(This,plRet)	\
    (This)->lpVtbl -> AbortNCFile(This,plRet)

#define IEZNcFile6_WriteNCFile(This,dwLength,pbData,plRet)	\
    (This)->lpVtbl -> WriteNCFile(This,dwLength,pbData,plRet)

#define IEZNcFile6_ReadNCFile(This,dwLength,ppbData,pdwNumRead,plRet)	\
    (This)->lpVtbl -> ReadNCFile(This,dwLength,ppbData,pdwNumRead,plRet)


#define IEZNcFile6_OpenFile3(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenFile3(This,lpcwszFileName,lMode,plRet)

#define IEZNcFile6_CloseFile2(This,plRet)	\
    (This)->lpVtbl -> CloseFile2(This,plRet)

#define IEZNcFile6_Copy2(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Copy2(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile6_Delete2(This,lpcwszFileName,plRet)	\
    (This)->lpVtbl -> Delete2(This,lpcwszFileName,plRet)

#define IEZNcFile6_Rename2(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)	\
    (This)->lpVtbl -> Rename2(This,lpcwszSrcFileName,lpcwszDstFileName,plRet)

#define IEZNcFile6_AbortFile2(This,plRet)	\
    (This)->lpVtbl -> AbortFile2(This,plRet)

#define IEZNcFile6_ReadFile2(This,dwLength,ppbData,pdwNumRead,plRet)	\
    (This)->lpVtbl -> ReadFile2(This,dwLength,ppbData,pdwNumRead,plRet)

#define IEZNcFile6_OpenNCFile2(This,lpcwszFileName,lMode,plRet)	\
    (This)->lpVtbl -> OpenNCFile2(This,lpcwszFileName,lMode,plRet)

#define IEZNcFile6_CloseNCFile2(This,plRet)	\
    (This)->lpVtbl -> CloseNCFile2(This,plRet)

#define IEZNcFile6_AbortNCFile2(This,plRet)	\
    (This)->lpVtbl -> AbortNCFile2(This,plRet)

#define IEZNcFile6_ReadNCFile2(This,dwLength,ppbData,pdwNumRead,plRet)	\
    (This)->lpVtbl -> ReadNCFile2(This,dwLength,ppbData,pdwNumRead,plRet)


#define IEZNcFile6_FindDir2(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindDir2(This,lpcwszDirectoryName,lFileType,lppwszFileInfo,plRet)

#define IEZNcFile6_FindNextDir2(This,lppwszFileInfo,plRet)	\
    (This)->lpVtbl -> FindNextDir2(This,lppwszFileInfo,plRet)

#define IEZNcFile6_GetDriveSize2(This,lpcwszDirectoryName,plDriveSize,plRet)	\
    (This)->lpVtbl -> GetDriveSize2(This,lpcwszDirectoryName,plDriveSize,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile6_FindDir2_Proxy( 
    IEZNcFile6 __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
    /* [in] */ LONG lFileType,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile6_FindDir2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile6_FindNextDir2_Proxy( 
    IEZNcFile6 __RPC_FAR * This,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszFileInfo,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile6_FindNextDir2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcFile6_GetDriveSize2_Proxy( 
    IEZNcFile6 __RPC_FAR * This,
    /* [string][in] */ LPCOLESTR lpcwszDirectoryName,
    /* [out] */ LONGLONG __RPC_FAR *plDriveSize,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcFile6_GetDriveSize2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcFile6_INTERFACE_DEFINED__ */


#ifndef __IEZNcSystem2_INTERFACE_DEFINED__
#define __IEZNcSystem2_INTERFACE_DEFINED__

/* interface IEZNcSystem2 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IEZNcSystem2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    //MIDL_INTERFACE("C73F2855-7242-42ce-8499-DC9BC6041D3B")
    interface IEZNcSystem2 : public IEZNcSystem
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetAlarm2( 
            /* [in] */ LONG lMessageNumber,
            /* [in] */ LONG lAlarmType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEZNcSystem2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IEZNcSystem2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IEZNcSystem2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IEZNcSystem2 __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVersion )( 
            IEZNcSystem2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSystemInformation )( 
            IEZNcSystem2 __RPC_FAR * This,
            /* [in] */ LONG lType,
            /* [out] */ LONG __RPC_FAR *plSystem,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAlarm )( 
            IEZNcSystem2 __RPC_FAR * This,
            /* [in] */ LONG lMessageNumber,
            /* [in] */ LONG lAlarmType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BackUp )( 
            IEZNcSystem2 __RPC_FAR * This,
            /* [in] */ LONG lAxisNo,
            /* [in] */ LONG lIndex,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAlarm2 )( 
            IEZNcSystem2 __RPC_FAR * This,
            /* [in] */ LONG lMessageNumber,
            /* [in] */ LONG lAlarmType,
            /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
            /* [retval][out] */ LONG __RPC_FAR *plRet);
        
        END_INTERFACE
    } IEZNcSystem2Vtbl;

    interface IEZNcSystem2
    {
        CONST_VTBL struct IEZNcSystem2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEZNcSystem2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEZNcSystem2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEZNcSystem2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEZNcSystem2_GetVersion(This,lAxisNo,lIndex,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetVersion(This,lAxisNo,lIndex,lppwszBuffer,plRet)

#define IEZNcSystem2_GetSystemInformation(This,lType,plSystem,plRet)	\
    (This)->lpVtbl -> GetSystemInformation(This,lType,plSystem,plRet)

#define IEZNcSystem2_GetAlarm(This,lMessageNumber,lAlarmType,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetAlarm(This,lMessageNumber,lAlarmType,lppwszBuffer,plRet)

#define IEZNcSystem2_BackUp(This,lAxisNo,lIndex,plRet)	\
    (This)->lpVtbl -> BackUp(This,lAxisNo,lIndex,plRet)


#define IEZNcSystem2_GetAlarm2(This,lMessageNumber,lAlarmType,lppwszBuffer,plRet)	\
    (This)->lpVtbl -> GetAlarm2(This,lMessageNumber,lAlarmType,lppwszBuffer,plRet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IEZNcSystem2_GetAlarm2_Proxy( 
    IEZNcSystem2 __RPC_FAR * This,
    /* [in] */ LONG lMessageNumber,
    /* [in] */ LONG lAlarmType,
    /* [string][out] */ LPOLESTR __RPC_FAR *lppwszBuffer,
    /* [retval][out] */ LONG __RPC_FAR *plRet);


void __RPC_STUB IEZNcSystem2_GetAlarm2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEZNcSystem2_INTERFACE_DEFINED__ */



#ifndef __EZSOCKETNCLib_LIBRARY_DEFINED__
#define __EZSOCKETNCLib_LIBRARY_DEFINED__

/* library EZSOCKETNCLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_EZSOCKETNCLib;

EXTERN_C const CLSID CLSID_EZNcCommunication;

#ifdef __cplusplus

class DECLSPEC_UUID("CDB486A8-DF29-44dc-84A1-A5112D9B8907")
EZNcCommunication;
#endif

EXTERN_C const CLSID CLSID_EZNcCommunication230;

#ifdef __cplusplus

class DECLSPEC_UUID("53402374-C15A-11D5-A48B-00D0B721C9A7")
EZNcCommunication230;
#endif

EXTERN_C const CLSID CLSID_EZNcCommunication240;

#ifdef __cplusplus

class DECLSPEC_UUID("05E98153-773E-4226-B02C-CAB00E44AA51")
EZNcCommunication240;
#endif

EXTERN_C const CLSID CLSID_EZNcCommunication250;

#ifdef __cplusplus

class DECLSPEC_UUID("4CFAF57A-1FC7-4034-A519-B1B4031572DA")
EZNcCommunication250;
#endif

EXTERN_C const CLSID CLSID_EZNcSubFunction;

#ifdef __cplusplus

class DECLSPEC_UUID("5DA876EA-3E78-468d-BDC0-4A14C6B4DB9E")
EZNcSubFunction;
#endif

EXTERN_C const CLSID CLSID_EZNcCommunication270;

#ifdef __cplusplus

class DECLSPEC_UUID("14D661BE-1055-433B-BFB3-0D389C0A6ECC")
EZNcCommunication270;
#endif

EXTERN_C const CLSID CLSID_EZNcCommunication280;

#ifdef __cplusplus

class DECLSPEC_UUID("E86664C1-C7CD-4EC4-A0DC-247A4A6998DC")
EZNcCommunication280;
#endif

EXTERN_C const CLSID CLSID_EZNcCommunication283;

#ifdef __cplusplus

class DECLSPEC_UUID("06CFE532-3FE4-486f-A149-D8B6CF5C342A")
EZNcCommunication283;
#endif

EXTERN_C const CLSID CLSID_EZNcCommunication286;

#ifdef __cplusplus

class DECLSPEC_UUID("2C27ED2F-2216-4a6e-B2AC-08DFEADD03DD")
EZNcCommunication286;
#endif

EXTERN_C const CLSID CLSID_EZNcCommunication289;

#ifdef __cplusplus

class DECLSPEC_UUID("33A66BEC-CC79-4e99-8224-78581AC9B0B4")
EZNcCommunication289;
#endif

EXTERN_C const CLSID CLSID_EZNcCommunication290;

#ifdef __cplusplus

class DECLSPEC_UUID("BEEDDF8B-69C7-4959-A3F3-0258DD6F72BF")
EZNcCommunication290;
#endif

EXTERN_C const CLSID CLSID_EZNcCommunication291;

#ifdef __cplusplus

class DECLSPEC_UUID("95318CAC-F86D-4d52-817F-9AD184AA11B2")
EZNcCommunication291;
#endif

EXTERN_C const CLSID CLSID_EZNcCommunication301;

#ifdef __cplusplus

class DECLSPEC_UUID("E42511A8-FEB7-44fa-888F-8327294ACFB0")
EZNcCommunication301;
#endif
#endif /* __EZSOCKETNCLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
