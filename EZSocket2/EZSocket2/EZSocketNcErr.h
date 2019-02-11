/********************************************************************************/
/*																			    */
/*	<FILENAME>	EZSocketNcErr.h												    */
/*		Meldas用ｴﾗｰ定義用ﾍｯﾀﾞﾌｧｲﾙ											    */
/*																			    */
/*																			    */
/* Copyright (C) 2000-2010 MITSUBISHI Electric Corporation All Rights Reserved	*/
/********************************************************************************/
//
/////////////////////////////////////////////////////////////////////////////
#ifndef __EZSOCKETNCERR_H_
#define __EZSOCKETNCERR_H_

#ifndef	INCmelErrh
#define	INCmelErrh

/* =================================================================== */
/* --- Type Definition		------------------------------------------ */
/* =================================================================== */
typedef	unsigned long	RETV;

/* =================================================================== */
/* --- Macro Definition		------------------------------------------ */
/* =================================================================== */
#define	ME_ERR_FLG			(0x80000000)
#define	ME_GROUP_MASK		(0x0fff0000)
#define	ME_CORD_MASK		(0x0000ffff)
#define	ME_CMD_MASK			(0x0000ff00)

#define	RetvIsError(retv)	(( (retv) & ME_ERR_FLG ) ? TRUE : FALSE)
#define	RetGroup(retv)		(( (retv) & ME_GROUP_MASK ) >> 16)
#define	RetCode(retv)		( (retv) & ME_CORD_MASK )
#define	RetGroupChange(retv, group)	(( (retv) & (~(ME_GROUP_MASK)) ) | group)
#define	RetCmdChange(retv, cmd)	(( (retv) & (~(ME_GROUP_MASK|ME_CMD_MASK)) ) | cmd)

/* =================================================================== */
/* --- Error Code			------------------------------------------ */
/* =================================================================== */
/*
  型 : RETV (unsigned long)

  コード体系 :

    31      27                    16                               0
    ┌┬┬┬┬───────────┬───────────────┐
    └┴┴┴┴───────────┴───────────────┘
     ｜  ｜            ｜                        ｜
     ｜  ｜            ｜                        └──── 戻り値コード
     │  │            │                                   (必要に応じて
     │  │            │                                    上位1byteを
     │  │            │                                    コマンドコード
     │  │            │                                    とする)
     │  │            └─────────────────── 区分コード
     │  └────────────────────────── 予備
     └──────────────────────────── エラーフラグ
*/

/* 共通コード(全コマンド)	-------------------------------------------	*/
#define	ME_ARG1					(0x81)
#define	ME_ARG2					(ME_ARG1 + 0x1)
#define	ME_ARG3					(ME_ARG1 + 0x2)
#define	ME_ARG4					(ME_ARG1 + 0x3)
#define	ME_ARG5					(ME_ARG1 + 0x4)
#define	ME_ARG6					(ME_ARG1 + 0x5)
#define	ME_ARG7					(ME_ARG1 + 0x6)
#define	ME_ARG8					(ME_ARG1 + 0x7)
#define	ME_ARG9					(ME_ARG1 + 0x8)
#define	ME_ARG10				(ME_ARG1 + 0x9)
#define	ME_ARG11				(ME_ARG1 + 0xa)
#define	ME_ARG12				(ME_ARG1 + 0xb)
#define	ME_ARG13				(ME_ARG1 + 0xc)
#define	ME_ARG14				(ME_ARG1 + 0xd)
#define	ME_ARG15				(ME_ARG1 + 0xe)
/* 共通コード(一般関連)	-------------------------------------------	*/
#define	ME_COMMON_SYNTAXERR			(0x40)
#define	ME_COMMON_CONTROLLER		(0x41)
#define	ME_COMMON_NOFILE			(0x42)
#define	ME_COMMON_FILESYSTEM		(0x43)
#define	ME_COMMON_CMDFORMAT			(0x44)
#define	ME_COMMON_SAMPLINGACTIVE	(0x45)
#define	ME_COMMON_PLCRUN			(0x46)
#define	ME_COMMON_FILEBUSY			(0x47)
#define	ME_COMMON_STRINGLENGTH		(0x48)
#define	ME_COMMON_NOTSUPPORTED		(0x49)
#define	ME_COMMON_PROTECT			(0x4A)
#define	ME_COMMON_PGLKC				(0x4B)
#define	ME_COMMON_EXECUTING			(0x4C)
#define	ME_COMMON_SAFETYPWLOCK		(0x4D)
#define	ME_COMMON_RESET				(0x4E)
/* 共通コード(ファイル関連)	-------------------------------------------	*/
#define	ME_FILE_BUSY			ME_COMMON_FILEBUSY
#define	ME_FILE_NOFILE			ME_COMMON_NOFILE
#define	ME_FILE_NAMELENGTH		ME_COMMON_STRINGLENGTH
#define	ME_FILE_NOTOPEN			(0x90)
#define	ME_FILE_NODIR			(0x91)
#define	ME_FILE_OPEN			(0x92)
#define	ME_FILE_CREATE			(0x93)
#define	ME_FILE_READERR			(0x94)
#define	ME_FILE_WRITEERR		(0x95)
#define	ME_FILE_WRITEDATAOVER	(0x96)
#define	ME_FILE_WRITEDATANAME	(0x97)
#define	ME_FILE_ILLEGALNAME		(0x98)
#define	ME_FILE_FILEFULL		(0x99)
#define	ME_FILE_ALREADYEXIST	(0x9A)
#define	ME_FILE_NODRIVE			(0x9B)
#define	ME_FILE_UOPEN_FORMAT	(0x9C)
#define ME_FILE_ILLEGALFORMAT	(0x9D)
#define ME_FILE_WRONGPASSWORD	(0x9E)
#define	ME_FILE_SORT			(0x9F)
#define	ME_FILE_SAFE_NOPASSWD	(0xB0)
#define	ME_PCFILE_NOTOPEN		(0xa0)
#define	ME_PCFILE_NOFILE		(0xa1)
#define	ME_PCFILE_NODIR			(0xa2)
#define	ME_PCFILE_OPEN			(0xa3)
#define	ME_PCFILE_CREATE		(0xa4)
#define	ME_PCFILE_READERR		(0xa5)
#define	ME_PCFILE_WRITEERR		(0xa6)
#define	ME_PCFILE_ILLEGALNAME	(0xa7)
#define	ME_PCFILE_NODRIVE		(0xa8)
#define	ME_PCFILE_NAMELENGTH	(0xa9)
/* 共通コード(データ関連)	-------------------------------------------	*/
#define	ME_DATA_ADDR			(0x90)
#define	ME_DATA_SECTION			(0x91)
#define	ME_DATA_SUBSECTION		(0x92)
#define	ME_DATA_ADDR2			(0x93)
#define	ME_DATA_SECTION2		(0x94)
#define	ME_DATA_SUBSECTION2		(0x95)
#define	ME_DATA_SIZE			(0x96)
#define	ME_DATA_DATATYPE		(0x97)
#define	ME_DATA_SIZE2			(0x98)
#define	ME_DATA_DATATYPE2		(0x99)
#define	ME_DATA_VALUE			(0x9A)
#define	ME_DATA_READONLY		(0x9B)
#define	ME_DATA_TABLEFULL		(0x9C)
#define	ME_DATA_READERR			(0x9D)
#define	ME_DATA_WRITEERR		(0x9E)
#define	ME_DATA_WRITEONLY		(0x9F)
#define	ME_DATA_AXIS			(0xA0)
#define	ME_DATA_DATANUM			(0xA1)
#define	ME_DATA_UOPEN_FORMAT	(0xA2)
#define	ME_DATA_NODATA			(0xA3)
#define	ME_DATA_REGIST			(0xA4)
#define	ME_DATA_RELEASE			(0xA5)
#define	ME_DATA_SAFE_PASSWDERR	(0xA6)
#define	ME_DATA_SAFE_CHECKERR	(0xA7)
#define	ME_DATA_SORT			(0xA8)
#define	ME_DATA_DATATYPE3		(0xA9)
/* 共通コード(運転操作関連)	-------------------------------------------	*/
#define	ME_OPE_NOFILE			ME_COMMON_NOFILE
#define	ME_OPE_FILEBUSY			ME_COMMON_FILEBUSY
#define	ME_OPE_NAMELENGTH		ME_COMMON_STRINGLENGTH
#define	ME_OPE_ADDR				(0x90)
#define	ME_OPE_MODE				(0x91)
#define	ME_OPE_VALUE			(0x92)
#define	ME_OPE_DATASIZE			(0x93)
#define	ME_OPE_DATATYPE			(0x94)
#define	ME_OPE_LOCALMODE		(0x95)
#define	ME_OPE_EXTERNAL			(0x96)
#define	ME_OPE_PARAM			(0x97)
#define	ME_OPE_RESETACTIVE		(0x98)
#define	ME_OPE_EMG				(0x99)
#define	ME_OPE_RESETWAIT		(0x9A)
#define	ME_OPE_OPERATINGAXIS	(0x9B)
#define	ME_OPE_ENCDATAFAIL		(0x9C)
#define	ME_OPE_ENCDATAREADFAIL	(0x9D)
#define	ME_OPE_SETUPOFF			(0x9E)
#define	ME_OPE_OPERATING		(0x9F)
#define	ME_OPE_SAMPLINGACTIVE	ME_COMMON_SAMPLINGACTIVE
#define	ME_OPE_NOTSAMPLING		(0xA1)
#define	ME_OPE_PLCRUN			ME_COMMON_PLCRUN
#define	ME_OPE_AMPALARM			(0xA3)
#define	ME_OPE_AMPNOTEXIST		(0xA4)
#define	ME_OPE_AMPRDYOFF		(0xA5)
#define	ME_OPE_AMPSERVOOFF		(0xA6)
#define	ME_OPE_AMPTYPEERR		(0xA7)
#define	ME_OPE_DIRECTMODE		(0xA8)
#define	ME_OPE_NOTDIRECTMODE	(0xA9)
#define	ME_OPE_DIRECTMODEBUFFULL	(0xAA)
#define	ME_OPE_ABSSYSTEM		(0xAB)
#define	ME_OPE_NOTABSSYSTEM		(0xAC)
#define	ME_OPE_AXISMOVING		(0xAD)
#define	ME_OPE_NOTPASSZ			(0xAE)

/* 共通コード(運転サーチ操作関連)	-------------------------------------------	*/
#define	ME_OPESRC_PRGFORMAT			(0x01)
#define	ME_OPESRC_NOPRG				(0x02)
#define	ME_OPESRC_RUNNING			(0x03)
#define	ME_OPESRC_RESET				(0x04)
#define	ME_OPESRC_LONGPATH			(0x05)
#define	ME_OPESRC_NCPCCOM			(0x06)
#define	ME_OPESRC_TIMEOUT			(0x07)
#define	ME_OPESRC_NBNOTFOUND		(0x08)
#define	ME_OPESRC_TOPSEARCH			(0x09)
#define	ME_OPESRC_SEARCHING			(0x0a)
#define	ME_OPESRC_ALREADYSEARCHED	(0x0b)
#define	ME_OPESRC_OTHERSEARCHING	(0x0c)
#define	ME_OPESRC_CHECKING			(0x0d)
#define	ME_OPESRC_ILLEGALPOS		(0x0e)
#define	ME_OPESRC_REVERSE			(0x0f)
#define	ME_OPESRC_SORT				(0x10)

/* 共通コード(Device関連)	-------------------------------------------	*/
#define	ME_DEV_ALREADYOPEN		1
#define	ME_DEV_NOTOPEN			2
#define	ME_DEV_CARDNOTEXIST		4
#define	ME_DEV_BADCHANNEL		6
#define	ME_DEV_BADFD			7
#define	ME_DEV_CANNOTOPEN		8
#define	ME_DEV_NOTCONNECT		10
#define	ME_DEV_NOTCLOSE			11
#define	ME_DEV_TIMEOUT			20
#define	ME_DEV_DATAERR			21
#define	ME_DEV_CANCELED			22
#define	ME_DEV_ILLEGALSIZE		23
#define	ME_DEV_TASKQUIT			24
#define	ME_DEV_HARDWAREERR		25
#define	ME_DEV_SYSTEMDOWN		26
#define	ME_DEV_UNKNOWNFUNC		50
#define	ME_DEV_SETDATAERR		51

/* コマンド一般エラー	===============================================	*/
#define	ME_CMD				(0x0010000)
#define	ME_CMD_ERR			(ME_ERR_FLG | ME_CMD)			/* コマンド一般エラー */

#define	ME_CMD_NOOPTION			(ME_CMD_ERR | 0x01)			/* オプションなし */
#define	ME_CMD_NOCOMMAND		(ME_CMD_ERR | 0x02)			/* コマンドなし */
#define	ME_CMD_SYNTAX			(ME_CMD_ERR | 0x03)			/* シンタックスエラー */
#define	ME_CMD_DIFFER			(ME_CMD_ERR | 0x04)			/* 送信コマンドと回答コマンドが不一致*/
#define	ME_CMD_ERRNUMGETFAIL	(ME_CMD_ERR | 0x05)			/* エラー番号が取得できない */

/* システム関連エラー	===============================================	*/
#define	ME_SYSFUNC			(0x0020000)
#define	ME_SYSFUNC_ERR			(ME_ERR_FLG | ME_SYSFUNC)					/* システム関連エラー */

#define	ME_SYSFUNC_IOCTL		(ME_SYSFUNC_ERR | 0x0100)
#define	ME_SYSFUNC_IOCTL_ADDR		(ME_SYSFUNC_IOCTL | ME_DATA_ADDR)		/* アドレス不正 */
#define	ME_SYSFUNC_IOCTL_NOTOPEN	(ME_SYSFUNC_IOCTL | ME_DEV_NOTOPEN)		/* デバイスがオープンされていない */
#define	ME_SYSFUNC_IOCTL_FUNCTION	(ME_SYSFUNC_IOCTL | ME_DEV_UNKNOWNFUNC)	/* コマンド不正 */
#define	ME_SYSFUNC_IOCTL_DATA		(ME_SYSFUNC_IOCTL | ME_DEV_SETDATAERR)	/* データ範囲不正 */

/* ファイルアクセス関連エラー	===================================	*/
#define	ME_FILE				(0x0030000)
#define	ME_FILE_ERR			(ME_ERR_FLG | ME_FILE)			/* ファイルアクセス関連エラー */

#define	ME_FILE_DIR					(ME_FILE_ERR | 0x0100)
#define	ME_FILE_DIR_ALREADYOPENED	(ME_FILE_DIR | 0x01)				/* すでに別ディレクトリをオープンしている */
#define	ME_FILE_DIR_NODIR			(ME_FILE_DIR | ME_FILE_NODIR)		/* ディレクトリが存在しない */
#define	ME_FILE_DIR_NOTOPEN			(ME_FILE_DIR | ME_FILE_NOTOPEN)		/* ディレクトリがオープンされていない */
#define	ME_FILE_DIR_READ			(ME_FILE_DIR | ME_FILE_READERR)		/* ファイル情報リードエラー */
#define	ME_FILE_DIR_DATASIZE		(ME_FILE_DIR | 0x03)				/* アプリケーションが用意したバッファに入りきらない*/
#define	ME_FILE_DIR_NODRIVE			(ME_FILE_DIR | ME_FILE_NODRIVE)		/* ドライブが存在しない*/
#define	ME_FILE_DIR_FILESYSTEM		(ME_FILE_DIR | ME_COMMON_FILESYSTEM)/* ファイルシステムに異常がある*/
#define	ME_FILE_DIR_NAMELENGTH		(ME_FILE_DIR | ME_FILE_NAMELENGTH)	/* ファイル名が長い */
#define	ME_FILE_DIR_ILLEGALNAME		(ME_FILE_DIR | ME_FILE_ILLEGALNAME)	/* ファイル名フォーマットが不正 */
#define	ME_PCFILE_DIR_ALREADYOPENED	(ME_FILE_DIR | 0x02)				/* すでに別ディレクトリをオープンしている(PC) */
#define	ME_PCFILE_DIR_NODIR			(ME_FILE_DIR | ME_PCFILE_NODIR)		/* ディレクトリが存在しない(PC)*/
#define	ME_PCFILE_DIR_NOFILE		(ME_FILE_DIR | ME_COMMON_NOFILE)	/* ファイルが存在しない */
#define	ME_PCFILE_DIR_NOTOPEN		(ME_FILE_DIR | ME_PCFILE_NOTOPEN)	/* ディレクトリがオープンされていない(PC) */
#define	ME_PCFILE_DIR_READ			(ME_FILE_DIR | ME_PCFILE_READERR)	/* ファイル情報リードエラー(PC) */
#define	ME_PCFILE_DIR_NODRIVE		(ME_FILE_DIR | ME_PCFILE_NODRIVE)	/* ドライブが存在しない(PC)*/

#define	ME_FILE_DELETE			(ME_FILE_ERR | 0x0200)
#define	ME_FILE_DEL_NOTDELETE	(ME_FILE_DELETE | 0x01)					/* 削除できないファイル */
#define	ME_FILE_DEL_NODIR		(ME_FILE_DELETE | ME_FILE_NODIR)		/* ディレクトリが存在しない*/
#define	ME_FILE_DEL_NOFILE		(ME_FILE_DELETE | ME_COMMON_NOFILE)		/* ファイルが存在しない */
#define	ME_FILE_DEL_ILLEGALNAME	(ME_FILE_DELETE | ME_FILE_ILLEGALNAME)	/* ファイル名フォーマットが不正*/
#define	ME_FILE_DEL_BUSY		(ME_FILE_DELETE | ME_COMMON_FILEBUSY)	/* ファイルが削除できない状態にある(運転中)*/
#define	ME_FILE_DEL_NODRIVE		(ME_FILE_DELETE | ME_FILE_NODRIVE)		/* ドライブが存在しない*/
#define	ME_FILE_DEL_FILESYSTEM	(ME_FILE_DELETE | ME_COMMON_FILESYSTEM)	/* ファイルシステムに異常がある*/
#define	ME_FILE_DEL_NAMELENGTH	(ME_FILE_DELETE | ME_FILE_NAMELENGTH)	/* ファイル名が長い */
#define	ME_FILE_DEL_PROTECT		(ME_FILE_DELETE | ME_COMMON_PROTECT)	/* プログラムの運転／編集禁止中 */
#define	ME_PCFILE_DEL_NOTDELETE	(ME_FILE_DELETE | 0x02)					/* 削除できないファイル(PC)*/
#define	ME_PCFILE_DEL_NODIR		(ME_FILE_DELETE | ME_PCFILE_NODIR)		/* ディレクトリが存在しない(PC)*/
#define	ME_PCFILE_DEL_NOFILE	(ME_FILE_DELETE | ME_PCFILE_NOFILE)		/* ファイルが存在しない(PC)*/
#define	ME_PCFILE_DEL_ILLEGALNAME	(ME_FILE_DELETE | ME_PCFILE_ILLEGALNAME) /* ファイル名フォーマットが不正(PC) */
#define	ME_PCFILE_DEL_NODRIVE	(ME_FILE_DELETE | ME_PCFILE_NODRIVE)	/* ドライブが存在しない(PC)*/

#define	ME_FILE_RENAME			(ME_FILE_ERR | 0x0300)
#define	ME_FILE_REN_FILEEXIST	(ME_FILE_RENAME | 0x01)					/* 新ファイル名がすでに存在する*/
#define	ME_FILE_REN_NODIR		(ME_FILE_RENAME | ME_FILE_NODIR)		/* ディレクトリが存在しない*/
#define	ME_FILE_REN_NOFILE		(ME_FILE_RENAME | ME_COMMON_NOFILE)		/* ファイルが存在しない*/
#define	ME_FILE_REN_ILLEGALNAME	(ME_FILE_RENAME | ME_FILE_ILLEGALNAME)	/* ファイル名フォーマットが不正*/
#define	ME_FILE_REN_BUSY		(ME_FILE_RENAME | ME_COMMON_FILEBUSY)	/* リネームできない状態にある(運転中)*/
#define	ME_FILE_REN_NODRIVE		(ME_FILE_RENAME | ME_FILE_NODRIVE)		/* ドライブが存在しない*/
#define	ME_FILE_REN_FILESYSTEM	(ME_FILE_RENAME | ME_COMMON_FILESYSTEM)	/* ファイルシステムに異常がある*/
#define	ME_FILE_REN_NOTRENAME	(ME_FILE_RENAME | 0x03)					/* リネームできないファイル*/
#define	ME_FILE_REN_SAMENAME	(ME_FILE_RENAME | 0x05)					/* 新旧ファイル名が同じ*/
#define	ME_FILE_REN_NAMELENGTH	(ME_FILE_RENAME | ME_FILE_NAMELENGTH)	/* ファイル名が長い */
#define	ME_FILE_REN_PROTECT		(ME_FILE_RENAME | ME_COMMON_PROTECT)	/* リネームできない状態にある(プロテクト中)*/
#define	ME_PCFILE_REN_FILEEXIST	(ME_FILE_RENAME | 0x02)					/* 新ファイル名が存在する(PC)*/
#define	ME_PCFILE_REN_NODIR		(ME_FILE_RENAME | ME_PCFILE_NODIR)		/* ディレクトリが存在しない(PC)*/
#define	ME_PCFILE_REN_NOFILE	(ME_FILE_RENAME | ME_PCFILE_NOFILE)		/* ファイルが存在しない(PC)*/
#define	ME_PCFILE_REN_ILLEGALNAME	(ME_FILE_RENAME | ME_PCFILE_ILLEGALNAME) /* ファイル名フォーマットが不正(PC)*/
#define	ME_PCFILE_REN_NOTRENAME		(ME_FILE_RENAME | 0x04)				/* リネームできないファイル(PC)*/
#define	ME_PCFILE_REN_SAMENAME		(ME_FILE_RENAME | 0x06)				/* 新旧ファイル名が同じ(PC)*/
#define	ME_PCFILE_REN_NODRIVE		(ME_FILE_RENAME | ME_PCFILE_NODRIVE) /* ドライブが存在しない(PC)*/

#define	ME_FILE_COPY				(ME_FILE_ERR | 0x0400)
#define	ME_FILE_COPY_FILEEXIST		(ME_FILE_COPY | 0x01)				/* コピー先ファイルがすでに存在する*/
#define	ME_FILE_COPY_NODIR			(ME_FILE_COPY | ME_FILE_NODIR)		/* ディレクトリが存在しない*/
#define	ME_FILE_COPY_NOFILE			(ME_FILE_COPY | ME_COMMON_NOFILE)	/* ファイルが存在しない*/
#define	ME_FILE_COPY_ILLEGALNAME	(ME_FILE_COPY | ME_FILE_ILLEGALNAME)	/* ファイル名フォーマットが不正*/
#define	ME_FILE_COPY_READ			(ME_FILE_COPY | ME_FILE_READERR)	/* コピー元ファイルが読めない*/
#define	ME_FILE_COPY_WRITE			(ME_FILE_COPY | ME_FILE_WRITEERR)	/* コピー先ファイルに書き込めない*/
#define	ME_FILE_COPY_BUSY			(ME_FILE_COPY | ME_COMMON_FILEBUSY)	/* コピーできない状態にある(運転中)*/
#define	ME_FILE_COPY_SAMPLING		(ME_FILE_COPY | ME_COMMON_SAMPLINGACTIVE) /* <未使用> */
#define	ME_FILE_COPY_PLCRUN			(ME_FILE_COPY | ME_COMMON_PLCRUN)	/* コピーできない状態にある(PLC動作中)*/
#define	ME_FILE_COPY_NODRIVE		(ME_FILE_COPY | ME_FILE_NODRIVE)	/* ドライブが存在しない*/
#define	ME_FILE_COPY_FILESYSTEM		(ME_FILE_COPY | ME_COMMON_FILESYSTEM)	/* ファイルシステムに異常がある*/
#define	ME_FILE_COPY_ENTRYOVER		(ME_FILE_COPY | 0x03)				/* 登録本数オーバ*/
#define	ME_FILE_COPY_MEMORYOVER		(ME_FILE_COPY | 0x04)				/* メモリ容量オーバ*/
#define	ME_FILE_COPY_NAMELENGTH		(ME_FILE_COPY | ME_FILE_NAMELENGTH)	/* ファイル名が長い */
#define	ME_FILE_COPY_PROTECT		(ME_FILE_COPY | ME_COMMON_PROTECT)	/* コピーできない状態にある(プロテクト中)*/
#define	ME_FILE_COPY_WRITE_WARNING	(ME_FILE_COPY | ME_FILE_WRITEERR)	/* コピー先ファイルに書き込めない*/
#define ME_FILE_COPY_DIFFER			(ME_FILE_COPY | 0x05)					/* 照合エラー */
#define ME_FILE_COPY_NOTSUPPORTED	(ME_FILE_COPY | ME_COMMON_NOTSUPPORTED) /* 照合機能をサポートしていない  */
#define	ME_FILE_COPY_NOTOPEN		(ME_FILE_COPY | ME_FILE_NOTOPEN)	/* ファイルがオープンされていない*/
#define ME_FILE_COPY_EXECUTING		(ME_FILE_COPY | ME_COMMON_EXECUTING)	/* ファイルコピー中*/
#define	ME_FILE_COPY_SAFETYPWLOCK	(ME_FILE_COPY | ME_COMMON_SAFETYPWLOCK)	/* 安全パスワードロック中*/
#define ME_FILE_COPY_ILLEGALFORMAT	(ME_FILE_COPY | ME_FILE_ILLEGALFORMAT)	/* ファイルフォーマット不正 */
#define	ME_FILE_COPY_WRONGPASSWORD	(ME_FILE_COPY | ME_FILE_WRONGPASSWORD)	/* パスワードが異なる 		*/
#define	ME_PCFILE_COPY_FILEEXIST	(ME_FILE_COPY | 0x02)				/* コピー先ファイルがすでに存在する(PC)*/
#define	ME_PCFILE_COPY_NODIR		(ME_FILE_COPY | ME_PCFILE_NODIR)	/* ディレクトリが存在しない(PC)*/
#define	ME_PCFILE_COPY_NOFILE		(ME_FILE_COPY | ME_PCFILE_NOFILE)	/* ファイルが存在しない(PC)*/
#define	ME_PCFILE_COPY_ILLEGALNAME	(ME_FILE_COPY | ME_PCFILE_ILLEGALNAME)	/* ファイル名フォーマットが不正(PC)*/
#define	ME_PCFILE_COPY_OPEN			(ME_FILE_COPY | ME_PCFILE_OPEN)		/* ファイルをオープンできない(PC)*/
#define	ME_PCFILE_COPY_CREATE		(ME_FILE_COPY | ME_PCFILE_CREATE)	/* ファイルを生成できない(PC)*/
#define	ME_PCFILE_COPY_READ			(ME_FILE_COPY | ME_PCFILE_READERR)	/* コピー元ファイルが読めない(PC)*/
#define	ME_PCFILE_COPY_WRITE		(ME_FILE_COPY | ME_PCFILE_WRITEERR)	/* コピー先ファイルに書き込めない(PC)*/
#define	ME_PCFILE_COPY_NODRIVE		(ME_FILE_COPY | ME_PCFILE_NODRIVE)	/* ドライブが存在しない(PC)*/
#define	ME_PCFILE_COPY_NOTOPEN		(ME_FILE_COPY | ME_PCFILE_NOTOPEN)	/* ファイルがオープンされていない*/
#define	ME_PCFILE_COPY_MEMORYOVER	(ME_FILE_COPY | 0x06)				/* ディスク容量オーバ*/

#define	ME_FILE_CONDENSE		(ME_FILE_ERR | 0x0500)
#define	ME_FILE_COND_NOFILE			(ME_FILE_CONDENSE | ME_COMMON_NOFILE)	/* */
#define	ME_FILE_COND_READ			(ME_FILE_CONDENSE | ME_FILE_READERR)	/* */
#define	ME_FILE_COND_WRITE			(ME_FILE_CONDENSE | ME_FILE_WRITEERR)	/* */
#define	ME_FILE_COND_NODRIVE		(ME_FILE_CONDENSE | ME_FILE_NODRIVE)	/* */
#define	ME_FILE_COND_FILESYSTEM		(ME_FILE_CONDENSE | ME_COMMON_FILESYSTEM) /* */

#define	ME_FILE_DISKFREE		(ME_FILE_ERR | 0x0600)
#define	ME_FILE_DISKFREE_NODIR		(ME_FILE_DISKFREE | ME_FILE_NODIR)		/* ディレクトリが存在しない*/
#define	ME_FILE_DISKFREE_NODRIVE	(ME_FILE_DISKFREE | ME_FILE_NODRIVE)	/* ドライブが存在しない*/
#define	ME_FILE_DISKFREE_FILESYSTEM	(ME_FILE_DISKFREE | ME_COMMON_FILESYSTEM) /* ファイルシステムに異常がある*/
#define	ME_FILE_DISKFREE_NAMELENGTH	(ME_FILE_DISKFREE | ME_FILE_NAMELENGTH)	/* ファイル名が長い */
#define	ME_FILE_DISKFREE_ILLEGALNAME	(ME_FILE_DISKFREE | ME_FILE_NAMELENGTH)	/* ファイル名フォーマットが不正 */
#define	ME_PCFILE_DISKFREE_NODIR	(ME_FILE_DISKFREE | ME_PCFILE_NODIR)	/* ディレクトリが存在しない(PC)*/
#define	ME_PCFILE_DISKFREE_NODRIVE	(ME_FILE_DISKFREE | ME_PCFILE_NODRIVE)	/* ドライブが存在しない(PC)*/

#define	ME_FILE_DRIVELIST		(ME_FILE_ERR | 0x0700)
#define	ME_FILE_DRVLIST_DATASIZE	(ME_FILE_DRIVELIST | 0x01)				/* アプリケーションが用意したバッファに入りきらない */
#define	ME_FILE_DRVLIST_READ		(ME_FILE_DRIVELIST | ME_FILE_READERR)	/* ドライブリストリードエラー */

#define	ME_FILE_VERIFY			(ME_FILE_ERR | 0x0800)
#define	ME_FILE_VERIFY_NODIR		(ME_FILE_VERIFY | ME_FILE_NODIR)		/* ディレクトリが存在しない*/
#define	ME_FILE_VERIFY_NOFILE		(ME_FILE_VERIFY | ME_COMMON_NOFILE)		/* ファイルが存在しない*/
#define	ME_FILE_VERIFY_ILLEGALNAME	(ME_FILE_VERIFY | ME_FILE_ILLEGALNAME)	/* ファイル名フォーマットが不正*/
#define	ME_FILE_VERIFY_READ			(ME_FILE_VERIFY | ME_FILE_READERR)		/* 照合ファイルが読めない*/
#define	ME_FILE_VERIFY_NODRIVE		(ME_FILE_VERIFY | ME_FILE_NODRIVE)		/* ドライブが存在しない*/
#define	ME_FILE_VERIFY_FILESYSTEM	(ME_FILE_VERIFY | ME_COMMON_FILESYSTEM)	/* ファイルシステムに異常がある*/
#define	ME_FILE_VERIFY_NAMELENGTH	(ME_FILE_VERIFY | ME_FILE_NAMELENGTH)	/* ファイル名が長い */
#define	ME_FILE_VERIFY_DIFFER		(ME_FILE_VERIFY | 0x05)					/* 照合エラー*/
#define	ME_FILE_VERIFY_NOTSUPPORTED	(ME_FILE_VERIFY | ME_COMMON_NOTSUPPORTED) /* 照合機能をサポートしていない*/
#define	ME_PCFILE_VERIFY_NODIR		(ME_FILE_VERIFY | ME_PCFILE_NODIR)		/* ディレクトリが存在しない(PC)*/
#define	ME_PCFILE_VERIFY_NOFILE		(ME_FILE_VERIFY | ME_PCFILE_NOFILE)		/* ファイルが存在しない(PC)*/
#define	ME_PCFILE_VERIFY_OPEN		(ME_FILE_VERIFY | ME_PCFILE_OPEN)		/* ファイルをオープンできない(PC)*/
#define	ME_PCFILE_VERIFY_NODRIVE	(ME_FILE_VERIFY | ME_PCFILE_NODRIVE)	/* ドライブが存在しない(PC)*/

#define	ME_FILE_REGISTINFO	(ME_FILE_ERR | 0x0900)
#define	ME_FILE_REGISTINFO_ILLEGALNAME		(ME_FILE_REGISTINFO | ME_FILE_ILLEGALNAME)	/* ファイル名不正 */
#define	ME_FILE_REGISTINFO_ILLIGALINDEX		(ME_FILE_REGISTINFO | 0x01)		/* ファイル情報番号不正 */
#define	ME_FILE_REGISTINFO_ILLEGALCOMMENT	(ME_FILE_REGISTINFO | 0x02)		/* コメント不正 */
#define	ME_FILE_REGISTINFO_MEMADDR			(ME_FILE_REGISTINFO | 0x03)		/* メモリアドレス不正 */


#define	ME_FILE_CREATEDIR				(ME_FILE_ERR | 0x0a00)						/* ディレクトリ作成				*/
#define	ME_FILE_CREATEDIR_FILESYSTEM	(ME_FILE_CREATEDIR | ME_COMMON_FILESYSTEM)	/*ファイルシステムに異常がある	*/
#define	ME_FILE_CREATEDIR_ILLEGALNAME	(ME_FILE_CREATEDIR | ME_FILE_ILLEGALNAME)	/* ファイル名フォーマットが不正	*/
#define	ME_FILE_CREATEDIR_NAMELENGTH	(ME_FILE_CREATEDIR | ME_FILE_NAMELENGTH)	/* パスが長い					*/
#define	ME_FILE_CREATEDIR_NODIR			(ME_FILE_CREATEDIR | ME_FILE_NODIR)			/* ディレクトリが存在しない		*/
#define	ME_FILE_CREATEDIR_WRITEERR		(ME_FILE_CREATEDIR | ME_FILE_WRITEERR)		/* 書き込めない					*/
#define	ME_FILE_CREATEDIR_NOTSUPPORTED	(ME_FILE_CREATEDIR | ME_COMMON_NOTSUPPORTED) /* 未サポート					*/
#define	ME_FILE_CREATEDIR_ALREADYOPENED	(ME_FILE_CREATEDIR | 0x01)					/* すでに別ディレクトリをオープンしている	*/
#define	ME_FILE_CREATEDIR_FILEEXIST		(ME_FILE_CREATEDIR | 0x03)					/* ディレクトリがすでに存在する	*/
#define	ME_FILE_CREATEDIR_MEMORYOVER	(ME_FILE_CREATEDIR | 0x05)					/* 容量オーバ					*/
#define	ME_FILE_CREATEDIR_ROOTDIRFULL	(ME_FILE_CREATEDIR | 0x07)					/* ルートディレクトリの最大ファイル数を越えた*/
#define	ME_PCFILE_CREATEDIR_ILLEGALNAME	  (ME_FILE_CREATEDIR | ME_PCFILE_ILLEGALNAME) /* ファイル名フォーマットが不正*/
#define	ME_PCFILE_CREATEDIR_NAMELENGTH	  (ME_FILE_CREATEDIR | ME_PCFILE_NAMELENGTH)  /* パスが長い					*/
#define	ME_PCFILE_CREATEDIR_NODIR		  (ME_FILE_CREATEDIR | ME_PCFILE_NODIR)		/* ディレクトリが存在しない		*/
#define	ME_PCFILE_CREATEDIR_WRITEERR	  (ME_FILE_CREATEDIR | ME_PCFILE_WRITEERR)	/* 書き込めない					*/
#define	ME_PCFILE_CREATEDIR_ALREADYOPENED (ME_FILE_CREATEDIR | 0x02)				/* すでに別ディレクトリをオープンしている	*/
#define	ME_PCFILE_CREATEDIR_FILEEXIST	  (ME_FILE_CREATEDIR | 0x04)				/* ディレクトリがすでに存在する	*/
#define	ME_PCFILE_CREATEDIR_MEMORYOVER	  (ME_FILE_CREATEDIR | 0x06)				/* 容量オーバ					*/
#define	ME_PCFILE_CREATEDIR_ROOTDIRFULL	  (ME_FILE_CREATEDIR | 0x08)				/* ルートディレクトリの最大ファイル数を越えた*/

#define	ME_FILE_DELETEDIR				(ME_FILE_ERR | 0x0b00)						/* ディレクトリ削除				*/
#define	ME_FILE_DELETEDIR_FILESYSTEM	(ME_FILE_DELETEDIR | ME_COMMON_FILESYSTEM)	/*ファイルシステムに異常がある	*/
#define	ME_FILE_DELETEDIR_ILLEGALNAME	(ME_FILE_DELETEDIR | ME_FILE_ILLEGALNAME)	/* ファイル名フォーマットが不正	*/
#define	ME_FILE_DELETEDIR_NAMELENGTH	(ME_FILE_DELETEDIR | ME_FILE_NAMELENGTH)	/* パスが長い					*/
#define	ME_FILE_DELETEDIR_NODIR			(ME_FILE_DELETEDIR | ME_FILE_NODIR)			/* ディレクトリが存在しない		*/
#define	ME_FILE_DELETEDIR_NOTSUPPORTED	(ME_FILE_DELETEDIR | ME_COMMON_NOTSUPPORTED) /* 未サポート					*/
#define	ME_FILE_DELETEDIR_ALREADYOPENED	(ME_FILE_DELETEDIR | 0x01)					/* すでに別ディレクトリをオープンしている	*/
#define	ME_FILE_DELETEDIR_NOTEMPTY		(ME_FILE_DELETEDIR | 0x03)					/* ディレクトリが空でない		*/
#define	ME_FILE_DELETEDIR_NOTDELETE		(ME_FILE_DELETEDIR | 0x05)					/* 削除できない					*/
#define	ME_PCFILE_DELETEDIR_ILLEGALNAME	  (ME_FILE_DELETEDIR | ME_PCFILE_ILLEGALNAME) /* ファイル名フォーマットが不正*/
#define	ME_PCFILE_DELETEDIR_NAMELENGTH	  (ME_FILE_DELETEDIR | ME_PCFILE_NAMELENGTH)  /* パスが長い					*/
#define	ME_PCFILE_DELETEDIR_NODIR		  (ME_FILE_DELETEDIR | ME_PCFILE_NODIR)		/* ディレクトリが存在しない		*/
#define	ME_PCFILE_DELETEDIR_ALREADYOPENED (ME_FILE_DELETEDIR | 0x02)				/* すでに別ディレクトリをオープンしている	*/
#define	ME_PCFILE_DELETEDIR_NOTEMPTY	  (ME_FILE_DELETEDIR | 0x04)				/* ディレクトリが空でない		*/
#define	ME_PCFILE_DELETEDIR_NOTDELETE	  (ME_FILE_DELETEDIR | 0x06)				/* 削除できない					*/

/* データアクセス関連エラー	===========================================	*/
#define	ME_DATA				(0x0040000)
#define	ME_DATA_ERR			(ME_ERR_FLG | ME_DATA)			/* データアクセス関連エラー */

#define	ME_DATA_READ			(ME_DATA_ERR | 0x0100)
#define	ME_DATA_READ_ADDR		(ME_DATA_READ | ME_DATA_ADDR)			/* アドレス不正*/
#define	ME_DATA_READ_SECT		(ME_DATA_READ | ME_DATA_SECTION)		/* 大区分番号不正*/
#define	ME_DATA_READ_SUBSECT	(ME_DATA_READ | ME_DATA_SUBSECTION)		/* 小区分番号不正*/
#define	ME_DATA_READ_AXIS		(ME_DATA_READ | ME_DATA_AXIS)			/* 軸指定不正*/
#define	ME_DATA_READ_DATASIZE	(ME_DATA_READ |	ME_DATA_SIZE)			/* アプリケーションが用意したバッファに入りきらない*/
#define	ME_DATA_READ_DATATYPE	(ME_DATA_READ | ME_DATA_DATATYPE)		/* データタイプ不正*/
#define	ME_DATA_READ_WRITEONLY	(ME_DATA_READ |	ME_DATA_WRITEONLY)		/* 書き込み専用データ*/
#define	ME_DATA_READ_READ		(ME_DATA_READ |	ME_DATA_READERR)		/* データが読み出せない状態にある*/
#define	ME_DATA_READ_DATANUM	(ME_DATA_READ |	ME_DATA_DATANUM)		/* データ番号不正*/
#define	ME_DATA_READ_NODATA		(ME_DATA_READ | ME_DATA_NODATA)			/* 読み出しデータなし*/
#define	ME_DATA_READ_VALUE		(ME_DATA_READ | ME_DATA_VALUE)			/* 読み出しデータ範囲不正*/

#define	ME_DATA_WRITE			(ME_DATA_ERR | 0x0200)
#define	ME_DATA_WRITE_ADDR		(ME_DATA_WRITE | ME_DATA_ADDR)			/* アドレス不正*/
#define	ME_DATA_WRITE_SECT		(ME_DATA_WRITE | ME_DATA_SECTION)		/* 大区分番号不正*/
#define	ME_DATA_WRITE_SUBSECT	(ME_DATA_WRITE | ME_DATA_SUBSECTION)	/* 小区分番号不正*/
#define	ME_DATA_WRITE_AXIS		(ME_DATA_WRITE | ME_DATA_AXIS)			/* 軸指定不正*/
#define	ME_DATA_WRITE_DATASIZE	(ME_DATA_WRITE | ME_DATA_SIZE)			/* アプリケーションが用意したバッファに入りきらない*/
#define	ME_DATA_WRITE_DATATYPE	(ME_DATA_WRITE | ME_DATA_DATATYPE)		/* データタイプ不正*/
#define	ME_DATA_WRITE_READONLY	(ME_DATA_WRITE | ME_DATA_READONLY)		/* 読み出し専用データ*/
#define	ME_DATA_WRITE_WRITE		(ME_DATA_WRITE | ME_DATA_WRITEERR)		/* データが書き込めない状態にある*/
#define	ME_DATA_WRITE_SAFETYPWLOCK	(ME_DATA_WRITE | ME_COMMON_SAFETYPWLOCK)	/* 安全パスワードロック中*/
#define	ME_DATA_WRITE_UOPEN_FORMAT	(ME_DATA_WRITE | ME_DATA_UOPEN_FORMAT)	/* SRAM開放パラメータ不正によりフォーマット中止した		*/
#define	ME_DATA_WRITE_EDTFILE_REGIST	(ME_DATA_WRITE | ME_DATA_REGIST)	/* 編集ファイルを登録できない(既に編集中)			*/
#define	ME_DATA_WRITE_EDTFILE_RELEASE	(ME_DATA_WRITE | ME_DATA_RELEASE)	/* 編集ファイルを解除できない						*/
#define	ME_DATA_WRITE_NODATA	(ME_DATA_WRITE | ME_DATA_NODATA)			/* 書き込み先データなし*/
#define	ME_DATA_WRITE_VALUE		(ME_DATA_WRITE | ME_DATA_VALUE)				/* 書き込みデータ範囲不正*/
#define	ME_DATA_WRITE_SAFE_NOPASSWD	(ME_DATA_WRITE | ME_DATA_SAFE_PASSWDERR)	/* 安全パスワード未設定*/
#define	ME_DATA_WRITE_SAFE_CHECKERR	(ME_DATA_WRITE | ME_DATA_SAFE_CHECKERR)		/* 安全データ整合性チェックエラー*/
#define	ME_DATA_WRITE_SAFE_DATATYPE	(ME_DATA_WRITE | ME_DATA_DATATYPE3)			/* 安全用データタイプ不正*/
#define	ME_DATA_WRITE_SORT		(ME_DATA_WRITE | ME_DATA_SORT)				/* 工具データソート中で書き込みできない */

#define	ME_DATA_COPY			(ME_DATA_ERR | 0x0300)
#define	ME_DATA_COPY_SRCADDR		(ME_DATA_COPY | ME_DATA_ADDR)
#define	ME_DATA_COPY_SRCSECT		(ME_DATA_COPY | ME_DATA_SECTION)
#define	ME_DATA_COPY_SRCSUBSECT		(ME_DATA_COPY | ME_DATA_SUBSECTION)
#define	ME_DATA_COPY_DSTADDR		(ME_DATA_COPY | ME_DATA_ADDR2)
#define	ME_DATA_COPY_DSTSECT		(ME_DATA_COPY | ME_DATA_SECTION2)
#define	ME_DATA_COPY_DSTSUBSECT		(ME_DATA_COPY | ME_DATA_SUBSECTION2)
#define	ME_DATA_COPY_READ		(ME_DATA_COPY | ME_DATA_READERR)
#define	ME_DATA_COPY_WRITE		(ME_DATA_COPY | ME_DATA_WRITEERR)

#define	ME_DATA_MDLREGIST		(ME_DATA_ERR | 0x0400)
#define	ME_DATA_MDLREGIST_ADDR		(ME_DATA_MDLREGIST | ME_DATA_ADDR)		/* アドレス不正*/
#define	ME_DATA_MDLREGIST_SECT		(ME_DATA_MDLREGIST | ME_DATA_SECTION)	/* 大区分番号不正*/
#define	ME_DATA_MDLREGIST_SUBSECT	(ME_DATA_MDLREGIST | ME_DATA_SUBSECTION) /* 小区分番号不正*/
#define	ME_DATA_MDLREGIST_AXIS		(ME_DATA_MDLREGIST | ME_DATA_AXIS) 		/* 軸指定不正*/
#define	ME_DATA_MDLREGIST_REGIST	(ME_DATA_MDLREGIST | 0x01)				/* データ登録数をオーバした*/
#define	ME_DATA_MDLREGIST_PRIORITY	(ME_DATA_MDLREGIST | 0x02)				/* プライオリティ指定不正*/
#define	ME_DATA_MDLREGIST_WRITEONLY	(ME_DATA_MDLREGIST | ME_DATA_WRITEONLY)	/* 書き込み専用データ*/
#define	ME_DATA_MDLREGIST_READONLY	(ME_DATA_MDLREGIST | ME_DATA_READONLY)	/* 読み出し専用データ*/
#define	ME_DATA_MDLREGIST_DATATYPE	(ME_DATA_MDLREGIST | ME_DATA_DATATYPE)	/* データタイプ不正*/
#define	ME_DATA_MDLREGIST_READ		(ME_DATA_MDLREGIST | ME_DATA_READERR)	/* データが読み出せない状態にある*/

#define	ME_DATA_MDLCANCEL		(ME_DATA_ERR | 0x0500)
#define	ME_DATA_MDLCANCEL_ADDR		(ME_DATA_MDLCANCEL | ME_DATA_ADDR)		/* アドレス不正*/
#define	ME_DATA_MDLCANCEL_NOTREGIST	(ME_DATA_MDLCANCEL | 0x01)				/* モーダルIDが登録されていない*/

#define	ME_DATA_MDLREAD			(ME_DATA_ERR | 0x0600)
#define	ME_DATA_MDLREAD_ADDR		(ME_DATA_MDLREAD | ME_DATA_ADDR)		/* アドレス不正*/
#define	ME_DATA_MDLREAD_NOTREGIST	(ME_DATA_MDLREAD | 0x01)				/* モーダルIDが登録されていない*/
#define	ME_DATA_MDLREAD_DATASIZE	(ME_DATA_MDLREAD |	ME_DATA_SIZE)		/* アプリケーションが用意したバッファに入りきらない*/
#define	ME_DATA_MDLREAD_DATATYPE	(ME_DATA_MDLREAD | ME_DATA_DATATYPE)	/* データタイプ不正*/
#define	ME_DATA_MDLREAD_WRITEONLY	(ME_DATA_MDLREAD |	ME_DATA_WRITEONLY)	/* 書き込み専用データ*/
#define	ME_DATA_MDLREAD_READ		(ME_DATA_MDLREAD | ME_DATA_READERR)		/* データが読み出せない状態にある*/

#define	ME_DATA_CLCTREGIST		(ME_DATA_ERR | 0x0700)
#define	ME_DATA_CLCTREGIST_ADDR		(ME_DATA_CLCTREGIST | ME_DATA_ADDR)
#define	ME_DATA_CLCTREGIST_SECT		(ME_DATA_CLCTREGIST | ME_DATA_SECTION)
#define	ME_DATA_CLCTREGIST_SUBSECT	(ME_DATA_CLCTREGIST | ME_DATA_SUBSECTION)
#define	ME_DATA_CLCTREGIST_TABLEFULL	(ME_DATA_CLCTREGIST | ME_DATA_TABLEFULL)
#define	ME_DATA_CLCTREGIST_REGIST	(ME_DATA_CLCTREGIST | 0x01)

#define ME_DATA_CLCTCANCEL  	(ME_DATA_ERR | 0x0800)
#define	ME_DATA_CLCTCANCEL_ADDR		(ME_DATA_CLCTCANCEL | ME_DATA_ADDR)
#define	ME_DATA_CLCTCANCEL_ID		(ME_DATA_CLCTCANCEL | 0x01)

#define ME_DATA_CLCTREAD		(ME_DATA_ERR | 0x0900)
#define	ME_DATA_CLCTREAD_ADDR		(ME_DATA_CLCTREAD | ME_DATA_ADDR)
#define	ME_DATA_CLCTREAD_DATATYPE	(ME_DATA_CLCTREAD | ME_DATA_DATATYPE)

#define	ME_DATA_MDLWRITE		(ME_DATA_ERR | 0x0a00)
#define	ME_DATA_MDLWRITE_ADDR		(ME_DATA_MDLWRITE | ME_DATA_ADDR)			/* アドレス不正*/
#define	ME_DATA_MDLWRITE_NOTREGIST	(ME_DATA_MDLWRITE | 0x01)					/* モーダルIDが登録されていない*/
#define	ME_DATA_MDLWRITE_DATASIZE		(ME_DATA_MDLWRITE |	ME_DATA_SIZE)		/* アプリケーションが用意したバッファに入りきらない*/
#define	ME_DATA_MDLWRITE_DATATYPE		(ME_DATA_MDLWRITE | ME_DATA_DATATYPE)	/* データタイプ不正*/
#define	ME_DATA_MDLWRITE_WRITEONLY		(ME_DATA_MDLWRITE |	ME_DATA_WRITEONLY)	/* 書き込み専用データ*/
#define	ME_DATA_MDLWRITE_READONLY		(ME_DATA_MDLWRITE |	ME_DATA_READONLY)	/* 読み出し専用データ*/
#define	ME_DATA_MDLWRITE_WRITE		(ME_DATA_MDLWRITE | ME_DATA_WRITEERR)		/* データが書き込めない状態にある*/

#define	ME_DATA_RETHREADWRITE	(ME_DATA_ERR | 0x0b00)
#define	ME_DATA_RETHREADWRITE_NODATA	(ME_DATA_RETHREADWRITE | ME_DATA_NODATA)	/* 再ねじ切り位置設定なし	*/

#define	ME_DATA_TLFGROUP		(ME_DATA_ERR | 0x1000)
#define	ME_DATA_TLFGROUP_ADDR		(ME_DATA_TLFGROUP | ME_DATA_ADDR)	/* アドレス不正					*/
#define	ME_DATA_TLFGROUP_EXIST		(ME_DATA_TLFGROUP | 0x91)			/* グループ番号が既に存在する	*/
#define	ME_DATA_TLFGROUP_NONEXIST	(ME_DATA_TLFGROUP | 0x92)			/* グループ番号が存在しない		*/
#define	ME_DATA_TLFGROUP_OVER		(ME_DATA_TLFGROUP | 0x93)			/* 登録グループ数オーバ			*/
#define	ME_DATA_TLFGROUP_NONFORMAT	(ME_DATA_TLFGROUP | 0x94)			/* フォーマット未完				*/
#define	ME_DATA_TLFGROUP_UNMACH		(ME_DATA_TLFGROUP | 0x96)			/* 設定グループ番号不一致		*/
#define	ME_DATA_TLFGROUP_OUTOFSPEC	(ME_DATA_TLFGROUP | 0x97)			/* 指定グループ番号が仕様外		*/

#define	ME_DATA_TLFTOOL			(ME_DATA_ERR | 0x1100)
#define	ME_DATA_TLFTOOL_ADDR		(ME_DATA_TLFTOOL | ME_DATA_ADDR)	/* アドレス不正					*/
#define	ME_DATA_TLFTOOL_EXIST		(ME_DATA_TLFTOOL | 0x91)			/* 工具番号が既に存在する		*/
#define	ME_DATA_TLFTOOL_NONEXIST	(ME_DATA_TLFTOOL | 0x92)			/* 工具番号が存在しない			*/
#define	ME_DATA_TLFTOOL_OVER		(ME_DATA_TLFTOOL | 0x93)			/* 登録工具数オーバ				*/
#define	ME_DATA_TLFTOOL_PARAMERR	(ME_DATA_TLFTOOL | 0x94)			/* 寿命管理データの種類指定不正 */
#define	ME_DATA_TLFTOOL_MAXMINERR	(ME_DATA_TLFTOOL | 0x95)			/* 設定データ範囲オーバ			*/
#define	ME_DATA_TLFTOOL_UNMACH		(ME_DATA_TLFTOOL | 0x96)			/* 設定工具番号不一致			*/
#define	ME_DATA_TLFTOOL_OUTOFSPEC	(ME_DATA_TLFTOOL | 0x97)			/* 指定工具番号が仕様外			*/

/* 運転操作関連エラー	===============================================	*/
#define	ME_OPE				(0x0050000)
#define	ME_OPE_ERR			(ME_ERR_FLG | ME_OPE)			/* 運転操作関連エラー */

#define	ME_OPE_RESET		(ME_OPE_ERR | 0x0100)
#define	ME_OPE_RESET_EXEC		(ME_OPE_RESET | 0x01)
#define	ME_OPE_RESET_ADDR		(ME_OPE_RESET | ME_OPE_ADDR)
#define	ME_OPE_RESET_MODE		(ME_OPE_RESET | ME_OPE_MODE)
#define	ME_OPE_RESET_LOCALMODE		(ME_OPE_RESET | ME_OPE_LOCALMODE)
#define	ME_OPE_RESET_EXTERNAL		(ME_OPE_RESET | ME_OPE_EXTERNAL)

#define	ME_OPE_BLKSTOP		(ME_OPE_ERR | 0x0200)
#define	ME_OPE_BLKSTOP_ADDR		(ME_OPE_BLKSTOP | ME_OPE_ADDR)
#define	ME_OPE_BLKSTOP_MODE		(ME_OPE_BLKSTOP | ME_OPE_MODE)
#define	ME_OPE_BLKSTOP_LOCALMODE	(ME_OPE_BLKSTOP | ME_OPE_LOCALMODE)
#define	ME_OPE_BLKSTOP_EXTERNAL		(ME_OPE_BLKSTOP | ME_OPE_EXTERNAL)

#define	ME_OPE_OPEMODE		(ME_OPE_ERR | 0x0300)
#define	ME_OPE_OPEMODE_ADDR		(ME_OPE_OPEMODE | ME_OPE_ADDR)
#define	ME_OPE_OPEMODE_MODE		(ME_OPE_OPEMODE | ME_OPE_MODE)
#define	ME_OPE_OPEMODE_LOCALMODE	(ME_OPE_OPEMODE | ME_OPE_LOCALMODE)
#define	ME_OPE_OPEMODE_EXTERNAL		(ME_OPE_OPEMODE | ME_OPE_EXTERNAL)
#define	ME_OPE_OPEMODE_OPERATINGAXIS	(ME_OPE_OPEMODE | ME_OPE_OPERATINGAXIS)

#define	ME_OPE_OVERRIDE		(ME_OPE_ERR | 0x0400)
#define	ME_OPE_OVERRIDE_ADDR		(ME_OPE_OVERRIDE | ME_OPE_ADDR)
#define	ME_OPE_OVERRIDE_VALUE		(ME_OPE_OVERRIDE | ME_OPE_VALUE)
#define	ME_OPE_OVERRIDE_LOCALMODE	(ME_OPE_OVERRIDE | ME_OPE_LOCALMODE)
#define	ME_OPE_OVERRIDE_EXTERNAL	(ME_OPE_OVERRIDE | ME_OPE_EXTERNAL)

#define	ME_OPE_MSPEED		(ME_OPE_ERR | 0x0500)
#define	ME_OPE_MSPEED_ADDR		(ME_OPE_MSPEED | ME_OPE_ADDR)
#define	ME_OPE_MSPEED_VALUE		(ME_OPE_MSPEED | ME_OPE_VALUE)
#define	ME_OPE_MSPEED_LOCALMODE		(ME_OPE_MSPEED | ME_OPE_LOCALMODE)
#define	ME_OPE_MSPEED_EXTERNAL		(ME_OPE_MSPEED | ME_OPE_EXTERNAL)

#define	ME_OPE_HNDLMAG		(ME_OPE_ERR | 0x0600)
#define	ME_OPE_HNDLMAG_ADDR		(ME_OPE_HNDLMAG | ME_OPE_ADDR)
#define	ME_OPE_HNDLMAG_VALUE		(ME_OPE_HNDLMAG | ME_OPE_VALUE)
#define	ME_OPE_HNDLMAG_LOCALMODE	(ME_OPE_HNDLMAG | ME_OPE_LOCALMODE)
#define	ME_OPE_HNDLMAG_EXTERNAL		(ME_OPE_HNDLMAG | ME_OPE_EXTERNAL)

#define	ME_OPE_STARTAXOPE	(ME_OPE_ERR | 0x0700)
#define	ME_OPE_STARTAXOPE_OPEMODE	(ME_OPE_STARTAXOPE | 0x01)
#define	ME_OPE_STARTAXOPE_ADDR		(ME_OPE_STARTAXOPE | ME_OPE_ADDR)
#define	ME_OPE_STARTAXOPE_MODE		(ME_OPE_STARTAXOPE | ME_OPE_MODE)
#define	ME_OPE_STARTAXOPE_LOCALMODE	(ME_OPE_STARTAXOPE | ME_OPE_LOCALMODE)
#define	ME_OPE_STARTAXOPE_EXTERNAL	(ME_OPE_STARTAXOPE | ME_OPE_EXTERNAL)
#define	ME_OPE_STARTAXOPE_OPERATINGAXIS	(ME_OPE_STARTAXOPE | ME_OPE_OPERATINGAXIS)

#define	ME_OPE_TRANSPLC		(ME_OPE_ERR | 0x0800)
#define	ME_OPE_TRANSPLC_READ		(ME_OPE_TRANSPLC | 0x01)
#define	ME_OPE_TRANSPLC_WRITE		(ME_OPE_TRANSPLC | 0x02)
#define	ME_OPE_TRANSPLC_ADDR		(ME_OPE_TRANSPLC | ME_OPE_ADDR)
#define	ME_OPE_TRANSPLC_MODE		(ME_OPE_TRANSPLC | ME_OPE_MODE)
#define	ME_OPE_TRANSPLC_PLCRUN		(ME_OPE_TRANSPLC | ME_COMMON_PLCRUN)

#define	ME_OPE_ACTPLC		(ME_OPE_ERR | 0x0900)
#define	ME_OPE_ACTPLC_ADDR		(ME_OPE_ACTPLC | ME_OPE_ADDR)		/* アドレス不正 */
#define	ME_OPE_ACTPLC_MODE		(ME_OPE_ACTPLC | ME_OPE_MODE)		/* モード不正 */

#define	ME_OPE_SAMPLING		(ME_OPE_ERR | 0x0a00)
#define	ME_OPE_SAMPLING_ALREADY		(ME_OPE_SAMPLING | ME_COMMON_SAMPLINGACTIVE)
#define	ME_OPE_SAMPLING_NOT		(ME_OPE_SAMPLING | ME_OPE_NOTSAMPLING)
#define	ME_OPE_SAMPLING_ADDR		(ME_OPE_SAMPLING | ME_OPE_ADDR)
#define	ME_OPE_SAMPLING_MODE		(ME_OPE_SAMPLING | ME_OPE_MODE)
#define	ME_OPE_SAMPLING_PARAM		(ME_OPE_SAMPLING | ME_OPE_PARAM)

#define	ME_OPE_GETPRGPOINT	(ME_OPE_ERR | 0x0b00)
#define	ME_OPE_GETPRGPOINT_ADDR		(ME_OPE_GETPRGPOINT | ME_OPE_ADDR)
#define	ME_OPE_GETPRGPOINT_DATASIZE	(ME_OPE_GETPRGPOINT | ME_OPE_DATASIZE)
#define	ME_OPE_GETPRGPOINT_DATATYPE	(ME_OPE_GETPRGPOINT | ME_OPE_DATATYPE)

#define	ME_OPE_GETPRGBLK	(ME_OPE_ERR | 0x0c00)
#define	ME_OPE_GETPRGBLK_NOS		(ME_OPE_GETPRGBLK | 0x01)		/* ブロック数指定が不正 */
#define	ME_OPE_GETPRGBLK_NOSEARCH	(ME_OPE_GETPRGBLK | 0x02)		/* 運転サーチ未完了 */
#define	ME_OPE_GETPRGBLK_DATAERR	(ME_OPE_GETPRGBLK | 0x03)		/* NCとPC間の通信データにエラーがある */
#define	ME_OPE_GETPRGBLK_ADDR		(ME_OPE_GETPRGBLK | ME_OPE_ADDR)	/* アドレス不正 */
#define	ME_OPE_GETPRGBLK_DATASIZE	(ME_OPE_GETPRGBLK | ME_OPE_DATASIZE)	/* アプリケーションが用意したバッファに入りきらない */
#define	ME_OPE_GETPRGBLK_DATATYPE	(ME_OPE_GETPRGBLK | ME_OPE_DATATYPE)	/* データタイプ不正 */

#define	ME_OPE_CURRALM		(ME_OPE_ERR | 0x0d00)
#define	ME_OPE_CURRALM_NOS		(ME_OPE_CURRALM | 0x01)			/* 取得メッセージ数が不正*/
#define	ME_OPE_CURRALM_ALMTYPE		(ME_OPE_CURRALM | 0x02)			/* アラーム種類が不正*/
#define	ME_OPE_CURRALM_DATAERR		(ME_OPE_CURRALM | 0x03)			/* NCとPC間の通信データにエラーがある*/
#define	ME_OPE_CURRALM_NOALM		(ME_OPE_CURRALM | 0x04)			/* <未使用>*/
#define	ME_OPE_CURRALM_ADDR		(ME_OPE_CURRALM | ME_OPE_ADDR)		/* アドレス不正*/
#define	ME_OPE_CURRALM_DATASIZE		(ME_OPE_CURRALM | ME_OPE_DATASIZE)	/* アプリケーションが用意したバッファに入りきらない*/
#define	ME_OPE_CURRALM_DATATYPE		(ME_OPE_CURRALM | ME_OPE_DATATYPE)	/* データタイプ不正*/

#define	ME_OPE_ALMMSG		(ME_OPE_ERR | 0x0e00)
#define	ME_OPE_ALMMSG_ALMNUM		(ME_OPE_ALMMSG | 0x01)
#define	ME_OPE_ALMMSG_ALMTYPE		(ME_OPE_ALMMSG | 0x02)
#define	ME_OPE_ALMMSG_ADDR		(ME_OPE_ALMMSG | ME_OPE_ADDR)
#define	ME_OPE_ALMMSG_DATASIZE		(ME_OPE_ALMMSG | ME_OPE_DATASIZE)
#define	ME_OPE_ALMMSG_DATATYPE		(ME_OPE_ALMMSG | ME_OPE_DATATYPE)

#define	ME_OPE_STARTOPE		(ME_OPE_ERR | 0x0f00)
#define	ME_OPE_STARTOPE_PRGFORMAT	(ME_OPE_STARTOPE | 0x01)
#define	ME_OPE_STARTOPE_FILESYSTEM	(ME_OPE_STARTOPE | ME_COMMON_FILESYSTEM)
#define	ME_OPE_STARTOPE_ADDR		(ME_OPE_STARTOPE | ME_OPE_ADDR)
#define	ME_OPE_STARTOPE_NOPRG		(ME_OPE_STARTOPE | ME_COMMON_NOFILE)
#define	ME_OPE_STARTOPE_RESET		(ME_OPE_STARTOPE | ME_OPE_RESETACTIVE)
#define	ME_OPE_STARTOPE_EMG		(ME_OPE_STARTOPE | ME_OPE_EMG)
#define	ME_OPE_STARTOPE_RESETWAIT	(ME_OPE_STARTOPE | ME_OPE_RESETWAIT)
#define	ME_OPE_STARTOPE_LOCALMODE	(ME_OPE_STARTOPE | ME_OPE_LOCALMODE)
#define	ME_OPE_STARTOPE_EXTERNAL	(ME_OPE_STARTOPE | ME_OPE_EXTERNAL)
#define	ME_OPE_STARTOPE_DATATYPE	(ME_OPE_STARTOPE | ME_OPE_DATATYPE)
#define	ME_OPE_STARTOPE_DIRECTMODE	(ME_OPE_STARTOPE | ME_OPE_DIRECTMODE)

#define	ME_OPE_SELECTPRG	(ME_OPE_ERR | 0x1000)
#define	ME_OPE_SELECTPRG_PRGFORMAT	(ME_OPE_SELECTPRG | ME_OPESRC_PRGFORMAT)	/* プログラムファイル名フォーマットが不正	*/
#define	ME_OPE_SELECTPRG_NOTPRG		(ME_OPE_SELECTPRG | ME_OPESRC_NOPRG)		/* プログラムファイルがない					*/
#define	ME_OPE_SELECTPRG_NOPRG		(ME_OPE_SELECTPRG | ME_OPESRC_NOPRG)		/* プログラムファイルがない */
#define	ME_OPE_SELECTPRG_RUNNING	(ME_OPE_SELECTPRG | ME_OPESRC_RUNNING)		/* 運転サーチができない状態にある(運転中)	*/
#define	ME_OPE_SELECTPRG_RESET		(ME_OPE_SELECTPRG | ME_OPESRC_RESET)		/* 運転サーチができない状態にある(リセット中)*/
#define ME_OPE_SELECTPRG_LONGPATH	(ME_OPE_SELECTPRG | ME_OPESRC_LONGPATH )	/* パス名が長い								*/
#define ME_OPE_SELECTPRG_NCPCCOM	(ME_OPE_SELECTPRG | ME_OPESRC_NCPCCOM )		/* ncpccom.exeが無い						*/
#define	ME_OPE_SELECTPRG_TIMEOUT	(ME_OPE_SELECTPRG | ME_OPESRC_TIMEOUT)		/* タイムアウト終了 						*/
#define	ME_OPE_SELECTPRG_SEARCHING	(ME_OPE_SELECTPRG | ME_OPESRC_SEARCHING)	/* 運転サーチができない状態にある(サーチ中)	*/
#define	ME_OPE_SELECTPRG_CHECKING	(ME_OPE_SELECTPRG | ME_OPESRC_CHECKING)		/* サーチができない状態にある(チェック中)	*/
#define	ME_OPE_SELECTPRG_FILEREAD	(ME_OPE_SELECTPRG | ME_FILE_READERR)		/* ファイル読込エラー */
#define	ME_OPE_SELECTPRG_FILEWRITE	(ME_OPE_SELECTPRG | ME_FILE_WRITEERR)		/* ファイル書込エラー */
#define	ME_OPE_SELECTPRG_FILESYSTEM	(ME_OPE_SELECTPRG | ME_COMMON_FILESYSTEM)	/* ファイルシステムに異常がある*/
#define	ME_OPE_SELECTPRG_DATATYPE	(ME_OPE_SELECTPRG | ME_OPE_DATATYPE) 		/* データタイプ不正 */
#define	ME_OPE_SELECTPRG_ADDR		(ME_OPE_SELECTPRG | ME_OPE_ADDR)			/* アドレス不正 */
#define	ME_OPE_SELECTPRG_MODE		(ME_OPE_SELECTPRG | ME_OPE_MODE) 			/* モード不正 								*/
#define	ME_OPE_SELECTPRG_NOTSUPPORTED	(ME_OPE_SELECTPRG | ME_COMMON_NOTSUPPORTED)	/* サーチができない(オプションなし)		*/
#define	ME_OPE_SELECTPRG_PGLKC		(ME_OPE_SELECTPRG | ME_COMMON_PGLKC)		/* サーチができない(プログラム表示ロックC)	*/
#define	ME_OPE_SELECTPRG_ILLEGALPOS	(ME_OPE_SELECTPRG | ME_OPESRC_ILLEGALPOS)	/* 指定位置不正								*/
#define	ME_OPE_SELECTPRG_REVERSE	(ME_OPE_SELECTPRG | ME_OPESRC_REVERSE)		/* 任意逆行中								*/
#define	ME_OPE_SELECTPRG_PROTECT	(ME_OPE_SELECTPRG | ME_COMMON_PROTECT)		/* サーチができない(プログラムの運転／編集禁止中) */

#define	ME_OPE_RMTLCLMODE	(ME_OPE_ERR | 0x1100)
#define	ME_OPE_RMTLCLMODE_LOCALMODE	(ME_OPE_RMTLCLMODE | ME_OPE_LOCALMODE)
#define	ME_OPE_RMTLCLMODE_ADDR		(ME_OPE_RMTLCLMODE | ME_OPE_ADDR)
#define	ME_OPE_RMTLCLMODE_MODE		(ME_OPE_RMTLCLMODE | ME_OPE_MODE)

#define	ME_OPE_SENDCMD		(ME_OPE_ERR | 0x1200)
#define	ME_OPE_SENDCMD_ADDR		(ME_OPE_SENDCMD | ME_OPE_ADDR)
#define	ME_OPE_SENDCMD_DATATYPE		(ME_OPE_SENDCMD | ME_OPE_DATATYPE)
#define	ME_OPE_SENDCMD_DATASIZE		(ME_OPE_SENDCMD | ME_OPE_DATASIZE)

#define	ME_OPE_SIMUSETMODE	(ME_OPE_ERR | 0x1300)
#define	ME_OPE_SIMUSETMODE_ADDR		(ME_OPE_SIMUSETMODE | ME_OPE_ADDR)			/* アドレス不正 */
#define	ME_OPE_SIMUSETMODE_PARAM	(ME_OPE_SIMUSETMODE | ME_OPE_PARAM)			/* 系統指定不正 */
#define	ME_OPE_SIMUSETMODE_START	(ME_OPE_SIMUSETMODE | 0x01)					/* シミュレーションが開始できない状態にある */
#define	ME_OPE_SIMUSETMODE_THRDCHKSTART	(ME_OPE_SIMUSETMODE | 0x02)				/* 3D機械干渉チェックが開始できない状態にある */

#define ME_OPE_SIMURESETMODE	(ME_OPE_ERR | 0x1400)
#define	ME_OPE_SIMURESETMODE_NOTREGIST	(ME_OPE_SIMURESETMODE | 0x01)			/* シミュレーションIDが不正 */
#define	ME_OPE_SIMURESETMODE_END		(ME_OPE_SIMURESETMODE | 0x02)			/* シミュレーションが終了できない状態にある */

#define	ME_OPE_SIMUREAD		(ME_OPE_ERR | 0x1500)
#define	ME_OPE_SIMUREAD_NOTREGIST	(ME_OPE_SIMUREAD | 0x01)					/* シミュレーションIDが不正 */
#define	ME_OPE_SIMUREAD_READ		(ME_OPE_SIMUREAD | 0x02)					/* データが読み出せない状態にある */
#define	ME_OPE_SIMUREAD_THRDCHKNOMODE	(ME_OPE_SIMUREAD | 0x03)				/* 3D機械干渉チェックモードでない 			*/

#define	ME_OPE_RSTARTPRG			(ME_OPE_ERR | 0x1600)
#define	ME_OPE_RSTARTPRG_PRGFORMAT	(ME_OPE_RSTARTPRG | ME_OPESRC_PRGFORMAT)	/* プログラムファイル名フォーマットが不正	*/
#define	ME_OPE_RSTARTPRG_NOPRG		(ME_OPE_RSTARTPRG | ME_OPESRC_NOPRG)		/* プログラムファイルがない 				*/
#define	ME_OPE_RSTARTPRG_RUNNING	(ME_OPE_RSTARTPRG | ME_OPESRC_RUNNING)		/* 再開サーチができない状態にある(運転中)	*/
#define	ME_OPE_RSTARTPRG_RESET		(ME_OPE_RSTARTPRG | ME_OPESRC_RESET)		/* 再開サーチができない状態にある(リセット中) */
#define	ME_OPE_RSTARTPRG_LONGPATH	(ME_OPE_RSTARTPRG | ME_OPESRC_LONGPATH)		/* パス名が長い 							*/
#define	ME_OPE_RSTARTPRG_NCPCCOM	(ME_OPE_RSTARTPRG | ME_OPESRC_NCPCCOM)		/* ncpccom.exeが無い 						*/
#define	ME_OPE_RSTARTPRG_TIMEOUT	(ME_OPE_RSTARTPRG | ME_OPESRC_TIMEOUT)		/* タイムアウト 							*/
#define	ME_OPE_RSTARTPRG_NBNOTFOUND	(ME_OPE_RSTARTPRG | ME_OPESRC_NBNOTFOUND)	/* Ｎ／Ｂ番号なし 							*/
#define	ME_OPE_RSTARTPRG_TOPSEARCH	(ME_OPE_RSTARTPRG | ME_OPESRC_TOPSEARCH)	/* トップサーチ未完了 						*/
#define	ME_OPE_RSTARTPRG_SEARCHING	(ME_OPE_RSTARTPRG | ME_OPESRC_SEARCHING)	/* 再開サーチができない状態にある(サーチ中)	*/
#define	ME_OPE_RSTARTPRG_CHECKING	(ME_OPE_RSTARTPRG | ME_OPESRC_CHECKING)		/* サーチができない状態にある(チェック中)	*/
#define	ME_OPE_RSTARTPRG_ALREADYSEARCHED	(ME_OPE_RSTARTPRG | ME_OPESRC_ALREADYSEARCHED)	/* 再開サーチができない状態にある(サーチ済み)	*/
#define	ME_OPE_RSTARTPRG_OTHERSEARCHING	(ME_OPE_RSTARTPRG | ME_OPESRC_OTHERSEARCHING)		/* 再開サーチができない状態にある(運転サーチ中)	*/
#define	ME_OPE_RSTARTPRG_FILEREAD	(ME_OPE_RSTARTPRG | ME_FILE_READERR)		/* ファイル読込エラー 						*/
#define	ME_OPE_RSTARTPRG_FILEWRITE	(ME_OPE_RSTARTPRG | ME_FILE_WRITEERR)		/* ファイル書込エラー 						*/
#define	ME_OPE_RSTARTPRG_FILESYSTEM	(ME_OPE_RSTARTPRG | ME_COMMON_FILESYSTEM)	/* ファイルシステムに異常がある				*/
#define	ME_OPE_RSTARTPRG_DATATYPE	(ME_OPE_RSTARTPRG | ME_OPE_DATATYPE)		/* データタイプ不正							*/
#define	ME_OPE_RSTARTPRG_ADDR		(ME_OPE_RSTARTPRG | ME_OPE_ADDR)			/* アドレス不正 							*/
#define	ME_OPE_RSTARTPRG_EMG		(ME_OPE_RSTARTPRG | ME_OPE_EMG)				/*再開サーチができない状態にある(非常停止中)*/
#define	ME_OPE_RSTARTPRG_NOTSUPPORTED	(ME_OPE_RSTARTPRG | ME_COMMON_NOTSUPPORTED)	/* サーチができない(オプションなし)		*/
#define	ME_OPE_RSTARTPRG_PGLKC		(ME_OPE_RSTARTPRG | ME_COMMON_PGLKC)		/* サーチができない(プログラム表示ロックC)	*/
#define	ME_OPE_RSTARTPRG_SORT		(ME_OPE_RSTARTPRG | ME_OPESRC_SORT)			/* 工具データソート中で再開サーチできない	*/

#define ME_OPE_RSTRPRG		(ME_OPE_ERR | 0x1600)
#define ME_OPE_RSTRPRG_PRGFORMAT	(ME_OPE_RSTRPRG | ME_OPESRC_PRGFORMAT)	  /* プログラムファイル名フォーマットが不正*/
#define ME_OPE_RSTRPRG_NOPRG		(ME_OPE_RSTRPRG | ME_OPESRC_NOPRG)		  /* プログラムファイルがない */
#define ME_OPE_RSTRPRG_RUNNING	(ME_OPE_RSTRPRG | ME_OPESRC_RUNNING)		  /* 再開サーチができない状態にある(運転中)*/
#define ME_OPE_RSTRPRG_RESET		(ME_OPE_RSTRPRG | ME_OPESRC_RESET)		  /* 再開サーチができない状態にある(リセット中) */
#define ME_OPE_RSTRPRG_LONGPATH (ME_OPE_RSTRPRG | ME_OPESRC_LONGPATH)		  /* パス名が長い */
#define ME_OPE_RSTRPRG_NCPCCOM	(ME_OPE_RSTRPRG | ME_OPESRC_NCPCCOM)		  /* ncpccom.exeが無い */
#define ME_OPE_RSTRPRG_TIMEOUT	(ME_OPE_RSTRPRG | ME_OPESRC_TIMEOUT)		  /* タイムアウト */
#define ME_OPE_RSTRPRG_NBNOTFOUND (ME_OPE_RSTRPRG | ME_OPESRC_NBNOTFOUND)	  /* Ｎ／Ｂ番号なし */
#define ME_OPE_RSTRPRG_TOPSEARCH  (ME_OPE_RSTRPRG | ME_OPESRC_TOPSEARCH)	  /* トップサーチ未完了 */
#define ME_OPE_RSTRPRG_SEARCHING  (ME_OPE_RSTRPRG | ME_OPESRC_SEARCHING)	  /* 再開サーチができない状態にある(サーチ中)*/
#define	ME_OPE_RSTRPRG_CHECKING	(ME_OPE_RSTRPRG | ME_OPESRC_CHECKING)		  /* サーチができない状態にある(チェック中)	*/
#define ME_OPE_RSTRPRG_ALREADYSEARCHED	  (ME_OPE_RSTRPRG | ME_OPESRC_ALREADYSEARCHED) /* 再開サーチができない状態にある(サーチ済み)*/
#define ME_OPE_RSTRPRG_OTHERSEARCHING (ME_OPE_RSTRPRG | ME_OPESRC_ALREADYSEARCHED) /* 再開サーチができない状態にある(運転サーチ中)*/
#define ME_OPE_RSTRPRG_FILEREAD (ME_OPE_RSTRPRG | ME_FILE_READERR)			  /* ファイル読込エラー */
#define ME_OPE_RSTRPRG_FILEWRITE	(ME_OPE_RSTRPRG | ME_FILE_WRITEERR) 	  /* ファイル書込エラー */
#define ME_OPE_RSTRPRG_FILESYSTEM	(ME_OPE_RSTRPRG | ME_COMMON_FILESYSTEM)   /* ファイルシステムに異常がある*/
#define ME_OPE_RSTRPRG_DATATYPE (ME_OPE_RSTRPRG | ME_OPE_DATATYPE)			  /* データタイプ不正 */
#define ME_OPE_RSTRPRG_ADDR 	(ME_OPE_RSTRPRG | ME_OPE_ADDR)				  /* アドレス不正 */
#define ME_OPE_RSTRPRG_EMG	   	(ME_OPE_RSTRPRG | ME_OPE_EMG)				  /* 再開サーチができない状態にある(EMG) */
#define	ME_OPE_RSTRPRG_NOTSUPPORTED	(ME_OPE_RSTRPRG | ME_COMMON_NOTSUPPORTED)	/* サーチができない(オプションなし)		*/
#define	ME_OPE_RSTRPRG_PGLKC		(ME_OPE_RSTRPRG | ME_COMMON_PGLKC)		/* サーチができない(プログラム表示ロックC)	*/

#define	ME_OPE_BUFFEDIT				(ME_OPE_ERR | 0x1700)
#define	ME_OPE_BUFFEDIT_OPTION		(ME_OPE_BUFFEDIT | 0x01)					/* オプション無し 							*/
#define	ME_OPE_BUFFEDIT_ALREADYOPEN	(ME_OPE_BUFFEDIT | 0x02)					/* バッファ修正開始中 						*/
#define	ME_OPE_BUFFEDIT_RUNNING		(ME_OPE_BUFFEDIT | 0x03)					/* プログラム運転中 						*/
#define	ME_OPE_BUFFEDIT_DEVICE		(ME_OPE_BUFFEDIT | 0x04)					/* バッファ修正書き込み不可 				*/
#define	ME_OPE_BUFFEDIT_NCPCCOM		(ME_OPE_BUFFEDIT | 0x05)					/* PC側ファイルサーバと交信できなかった 	*/
#define	ME_OPE_BUFFEDIT_TIMEOUT		(ME_OPE_BUFFEDIT | 0x06)					/* タイムアウト 							*/
#define	ME_OPE_BUFFEDIT_PRGSTOP		(ME_OPE_BUFFEDIT | 0x07)					/* サイクルスタートを開始していない 		*/
#define	ME_OPE_BUFFEDIT_NOBLOCK		(ME_OPE_BUFFEDIT | 0x08)					/* 次指令無し 								*/
#define	ME_OPE_BUFFEDIT_RUNNING2	(ME_OPE_BUFFEDIT | 0x09)					/* 別系統でプログラム運転中 				*/
#define	ME_OPE_BUFFEDIT_NESTING		(ME_OPE_BUFFEDIT | 0x0a)					/* サブプロ呼び出し中 						*/
#define	ME_OPE_BUFFEDIT_NSEARCH		(ME_OPE_BUFFEDIT | 0x0b)					/* 別系統でシーケンス番号サーチ中 			*/
#define	ME_OPE_BUFFEDIT_WRITING		(ME_OPE_BUFFEDIT | 0x0c)					/* 書き込み中 								*/
#define	ME_OPE_BUFFEDIT_NOS			(ME_OPE_BUFFEDIT | 0x0d)					/* 取得メッセージ数が不正 					*/
#define	ME_OPE_BUFFEDIT_DATAERR		(ME_OPE_BUFFEDIT | 0x0e)					/* NCとPC間の通信データにエラーがある 		*/
#define	ME_OPE_BUFFEDIT_SIZEOVER	(ME_OPE_BUFFEDIT | 0x0f)					/* 書き込みサイズオーバー 					*/
#define	ME_OPE_BUFFEDIT_NOTGETTING	(ME_OPE_BUFFEDIT | 0x10)					/* バッファ修正プログラムを読み出していない */
#define	ME_OPE_BUFFEDIT_NOTSETTING	(ME_OPE_BUFFEDIT | 0x11)					/* バッファ修正プログラムを書き込んでいない */
#define	ME_OPE_BUFFEDIT_DATAFORMAT	(ME_OPE_BUFFEDIT | 0x12)					/* 書き込みデータ不正 						*/
#define	ME_OPE_BUFFEDIT_FILESYSTEM	(ME_OPE_BUFFEDIT | ME_COMMON_FILESYSTEM)	/* ファイルシステムに異常がある 			*/
#define	ME_OPE_BUFFEDIT_PROTECT		(ME_OPE_BUFFEDIT | ME_COMMON_PROTECT)		/* 編集ロック中 							*/
#define	ME_OPE_BUFFEDIT_ADDR		(ME_OPE_BUFFEDIT | ME_OPE_ADDR)				/* アドレス不正 							*/
#define	ME_OPE_BUFFEDIT_MODE		(ME_OPE_BUFFEDIT | ME_OPE_MODE)				/* バッファ修正モードでない 				*/
#define	ME_OPE_BUFFEDIT_DATASIZE	(ME_OPE_BUFFEDIT | ME_OPE_DATASIZE)			/* Appが用意したバッファに入りきらない 		*/
#define	ME_OPE_BUFFEDIT_DATATYPE	(ME_OPE_BUFFEDIT | ME_OPE_DATATYPE)			/* データタイプ不正 						*/
#define	ME_OPE_BUFFEDIT_PGLKC		(ME_OPE_BUFFEDIT | ME_COMMON_PGLKC)			/* バッファ修正できない(プログラム表示ロックC)	*/

#define	ME_OPE_SELECTPRGEX		(ME_OPE_ERR | 0x1800)
#define	ME_OPE_SELECTPRGEX_PRGFORMAT	(ME_OPE_SELECTPRGEX | ME_OPESRC_PRGFORMAT)	/* プログラムファイル名フォーマットが不正	*/
#define	ME_OPE_SELECTPRGEX_NOPRG		(ME_OPE_SELECTPRGEX | ME_OPESRC_NOPRG)	/* プログラムファイルがない 				*/
#define	ME_OPE_SELECTPRGEX_RUNNING	(ME_OPE_SELECTPRGEX | ME_OPESRC_RUNNING)	/* 運転サーチができない状態にある(運転中)	*/
#define	ME_OPE_SELECTPRGEX_LONGPATH	(ME_OPE_SELECTPRGEX | ME_OPESRC_LONGPATH)	/* パス名が長い 							*/
#define	ME_OPE_SELECTPRGEX_NCPCCOM	(ME_OPE_SELECTPRGEX | ME_OPESRC_NCPCCOM)	/* ncpccom.exeが無い 						*/
#define	ME_OPE_SELECTPRGEX_TIMEOUT	(ME_OPE_SELECTPRGEX | ME_OPESRC_TIMEOUT)	/* タイムアウト 							*/
#define	ME_OPE_SELECTPRGEX_SEARCHING	(ME_OPE_SELECTPRGEX | ME_OPESRC_SEARCHING)	/* 再開サーチができない状態にある(サーチ中)	*/
#define	ME_OPE_SELECTPRGEX_CHECKING	(ME_OPE_SELECTPRGEX | ME_OPESRC_CHECKING)	/* サーチができない状態にある(チェック中)	*/
#define	ME_OPE_SELECTPRGEX_FILEREAD	(ME_OPE_SELECTPRGEX | ME_FILE_READERR)		/* ファイル読込エラー 						*/
#define	ME_OPE_SELECTPRGEX_FILEWRITE	(ME_OPE_SELECTPRGEX | ME_FILE_WRITEERR)	/* ファイル書込エラー 						*/
#define	ME_OPE_SELECTPRGEX_FILESYSTEM	(ME_OPE_SELECTPRGEX | ME_COMMON_FILESYSTEM) /* ファイルシステムに異常がある			*/
#define	ME_OPE_SELECTPRGEX_DATATYPE	(ME_OPE_SELECTPRGEX | ME_OPE_DATATYPE) 		/* データタイプ不正 						*/
#define	ME_OPE_SELECTPRGEX_ADDR		(ME_OPE_SELECTPRGEX | ME_OPE_ADDR)			/* アドレス不正 							*/
#define	ME_OPE_SELECTPRGEX_NOTSUPPORTED	(ME_OPE_SELECTPRGEX | ME_COMMON_NOTSUPPORTED)	/* サーチができない(オプションなし)	*/
#define	ME_OPE_SELECTPRGEX_PGLKC		(ME_OPE_SELECTPRGEX | ME_COMMON_PGLKC)	/* サーチができない(プログラム表示ロックC)	*/
#define	ME_OPE_SELECTPRGEX_ILLEGALPOS	(ME_OPE_SELECTPRGEX | ME_OPESRC_ILLEGALPOS)		/* 指定位置不正						*/
#define	ME_OPE_SELECTPRGEX_REVERSE	(ME_OPE_SELECTPRGEX | ME_OPESRC_REVERSE)	/* 任意逆行中								*/
#define	ME_OPE_SELECTPRGEX_PROTECT		(ME_OPE_SELECTPRGEX | ME_COMMON_PROTECT)/* サーチができない(プログラムの運転／編集禁止中) */

#define	ME_OPE_GETPRGSTAK				(ME_OPE_ERR | 0x1900)
#define ME_OPE_GETPRGSTAK_NOTSUPPORTED	(ME_OPE_GETPRGSTAK | ME_COMMON_NOTSUPPORTED)	/* サポートしていない						  */
#define ME_OPE_GETPRGSTAK_ADDR			(ME_OPE_GETPRGSTAK | ME_OPE_ADDR)				/* アドレス不正 							  */
#define ME_OPE_GETPRGSTAK_DATASIZE		(ME_OPE_GETPRGSTAK | ME_OPE_DATASIZE)			/* アプリケーションが用意したバッファに入りきらない */

#define	ME_OPE_COLLATION		(ME_OPE_ERR | 0x1A00)
#define	ME_OPE_COLLATION_PRGFORMAT	(ME_OPE_COLLATION | ME_OPESRC_PRGFORMAT)	/* ﾌﾟﾛｸﾞﾗﾑﾌｧｲﾙ名フォーマットが不正 			*/
#define	ME_OPE_COLLATION_NOPRG		(ME_OPE_COLLATION | ME_OPESRC_NOPRG)		/* プログラムファイルがない 				*/
#define	ME_OPE_COLLATION_RUNNING	(ME_OPE_COLLATION | ME_OPESRC_RUNNING)		/* プログラム運転中 						*/
#define	ME_OPE_COLLATION_RESET		(ME_OPE_COLLATION | ME_OPESRC_RESET)		/* リセット中 								*/
#define	ME_OPE_COLLATION_FILESYSTEM	(ME_OPE_COLLATION | ME_COMMON_FILESYSTEM)	/* ﾌｧｲﾙｼｽﾃﾑに何らかの異常がある 			*/
#define	ME_OPE_COLLATION_SEARCHING	(ME_OPE_COLLATION | ME_OPESRC_SEARCHING)	/* 照合中 									*/
#define	ME_OPE_COLLATION_DATATYPE	(ME_OPE_COLLATION | ME_OPE_DATATYPE)		/* データタイプ不正							*/
#define	ME_OPE_COLLATION_ADDR		(ME_OPE_COLLATION | ME_OPE_ADDR)			/* アドレスが不正 							*/
#define	ME_OPE_COLLATION_NOTSUPPORTED	(ME_OPE_COLLATION | ME_COMMON_NOTSUPPORTED)	/* サーチができない(オプションなし)		*/
#define	ME_OPE_COLLATION_CHECKING	(ME_OPE_COLLATION | ME_OPESRC_CHECKING)		/* 照合停止ができない状態にある(チェック中)	*/
#define	ME_OPE_COLLATION_LONGPATH	(ME_OPE_COLLATION | ME_OPESRC_LONGPATH)		/* パス名が長い								*/

#define	ME_OPE_CHECKPRG			(ME_OPE_ERR | 0x1B00)
#define	ME_OPE_CHECKPRG_PRGFORMAT	(ME_OPE_CHECKPRG | ME_OPESRC_PRGFORMAT)		/* ﾌﾟﾛｸﾞﾗﾑﾌｧｲﾙ名フォーマットが不正 			*/
#define	ME_OPE_CHECKPRG_NOPRG		(ME_OPE_CHECKPRG | ME_OPESRC_NOPRG)			/* プログラムファイルがない 				*/
#define	ME_OPE_CHECKPRG_NOTPRG		(ME_OPE_CHECKPRG | ME_OPESRC_NOPRG)			/* プログラムファイルがない 				*/
#define	ME_OPE_CHECKPRG_RUNNING		(ME_OPE_CHECKPRG | ME_OPESRC_RUNNING)		/* プログラム運転中 						*/
#define	ME_OPE_CHECKPRG_RESET		(ME_OPE_CHECKPRG | ME_OPESRC_RESET)			/* リセット中 								*/
#define	ME_OPE_CHECKPRG_LONGPATH	(ME_OPE_CHECKPRG | ME_OPESRC_LONGPATH)		/* パス名が長い 							*/
#define	ME_OPE_CHECKPRG_NCPCCOM		(ME_OPE_CHECKPRG | ME_OPESRC_NCPCCOM)		/* ncpccom.exeが無い 						*/
#define	ME_OPE_CHECKPRG_TIMEOUT		(ME_OPE_CHECKPRG | ME_OPESRC_TIMEOUT)		/* タイムアウト 							*/
#define	ME_OPE_CHECKPRG_SEARCHING	(ME_OPE_CHECKPRG | ME_OPESRC_SEARCHING)		/* サーチ中 								*/
#define	ME_OPE_CHECKPRG_CHECKING	(ME_OPE_CHECKPRG | ME_OPESRC_CHECKING)		/* サーチができない状態にある(チェック中)	*/
#define ME_OPE_CHECKPRG_FILEREAD	(ME_OPE_CHECKPRG | ME_FILE_READERR )		/* ファイル読み込みエラー					*/
#define ME_OPE_CHECKPRG_FILEWRITE	(ME_OPE_CHECKPRG | ME_FILE_WRITEERR )		/* ファイル書き込みエラー					*/
#define	ME_OPE_CHECKPRG_FILESYSTEM	(ME_OPE_CHECKPRG | ME_COMMON_FILESYSTEM)	/* ﾌｧｲﾙｼｽﾃﾑに何らかの異常がある 			*/
#define	ME_OPE_CHECKPRG_DATATYPE	(ME_OPE_CHECKPRG | ME_OPE_DATATYPE)			/* データタイプ不正							*/
#define	ME_OPE_CHECKPRG_ADDR		(ME_OPE_CHECKPRG | ME_OPE_ADDR)				/* アドレスが不正 							*/
#define	ME_OPE_CHECKPRG_NOTSUPPORTED	(ME_OPE_CHECKPRG | ME_COMMON_NOTSUPPORTED)	/* サーチができない(オプションなし)		*/
#define	ME_OPE_CHECKPRG_PGLKC		(ME_OPE_CHECKPRG | ME_COMMON_PGLKC)			/* サーチができない(プログラム表示ロックC)	*/

#define	ME_OPE_BOTTOMCHK		(ME_OPE_ERR | 0x1C00)
#define	ME_OPE_BOTTOMCHK_PRGFORMAT	(ME_OPE_BOTTOMCHK | ME_OPESRC_PRGFORMAT)	/* ﾌﾟﾛｸﾞﾗﾑﾌｧｲﾙ名フォーマットが不正 			*/
#define	ME_OPE_BOTTOMCHK_NOPRG		(ME_OPE_BOTTOMCHK | ME_OPESRC_NOPRG)		/* プログラムファイルがない 				*/
#define	ME_OPE_BOTTOMCHK_RUNNING	(ME_OPE_BOTTOMCHK | ME_OPESRC_RUNNING)		/* プログラム運転中							*/
#define	ME_OPE_BOTTOMCHK_RESET		(ME_OPE_BOTTOMCHK | ME_OPESRC_RESET)		/* リセット中 								*/
#define	ME_OPE_BOTTOMCHK_LONGPATH	(ME_OPE_BOTTOMCHK | ME_OPESRC_LONGPATH)		/* パス名が長い 							*/
#define	ME_OPE_BOTTOMCHK_NCPCCOM	(ME_OPE_BOTTOMCHK | ME_OPESRC_NCPCCOM)		/* ncpccom.exeが無い 						*/
#define	ME_OPE_BOTTOMCHK_TIMEOUT	(ME_OPE_BOTTOMCHK | ME_OPESRC_TIMEOUT)		/* タイムアウト 							*/
#define	ME_OPE_BOTTOMCHK_SEARCHING	(ME_OPE_BOTTOMCHK | ME_OPESRC_SEARCHING)	/* サーチ中 								*/
#define	ME_OPE_BOTTOMCHK_CHECKING	(ME_OPE_BOTTOMCHK | ME_OPESRC_CHECKING)		/* サーチができない状態にある(チェック中)	*/
#define	ME_OPE_BOTTOMCHK_TOPSEARCH	(ME_OPE_BOTTOMCHK | ME_OPESRC_TOPSEARCH)	/* サーチ未完								*/
#define ME_OPE_BOTTOMCHK_FILEREAD	(ME_OPE_BOTTOMCHK | ME_FILE_READERR )		/* ファイル読み込みエラー					*/
#define ME_OPE_BOTTOMCHK_FILEWRITE	(ME_OPE_BOTTOMCHK | ME_FILE_WRITEERR )		/* ファイル書き込みエラー					*/
#define	ME_OPE_BOTTOMCHK_FILESYSTEM	(ME_OPE_BOTTOMCHK | ME_COMMON_FILESYSTEM)	/* ﾌｧｲﾙｼｽﾃﾑに何らかの異常がある 			*/
#define	ME_OPE_BOTTOMCHK_DATATYPE	(ME_OPE_BOTTOMCHK | ME_OPE_DATATYPE)		/* データタイプ不正							*/
#define	ME_OPE_BOTTOMCHK_ADDR		(ME_OPE_BOTTOMCHK | ME_OPE_ADDR)			/* アドレスが不正 							*/
#define	ME_OPE_BOTTOMCHK_NOTSUPPORTED	(ME_OPE_BOTTOMCHK | ME_COMMON_NOTSUPPORTED)	/* サーチができない(オプションなし)		*/

#define	ME_OPE_RESETCHECK	(ME_OPE_ERR | 0x1D00)
#define	ME_OPE_RESETCHECK_SEARCHING	(ME_OPE_RESETCHECK | ME_OPESRC_SEARCHING)	/* サーチ中 								*/
#define	ME_OPE_RESETCHECK_RUNNING	(ME_OPE_RESETCHECK | ME_OPESRC_RUNNING)		/* プログラム運転中 						*/
#define	ME_OPE_RESETCHECK_ADDR		(ME_OPE_RESETCHECK | ME_OPE_ADDR)			/* アドレスが不正							*/

#define	ME_OPE_EXECCHECK	(ME_OPE_ERR | 0x1E00)
#define	ME_OPE_EXECCHECK_RESET		(ME_OPE_EXECCHECK | ME_OPESRC_RESET)		/* リセット中								*/
#define	ME_OPE_EXECCHECK_TIMEOUT	(ME_OPE_EXECCHECK | ME_OPESRC_TIMEOUT)		/* タイムアウト								*/
#define	ME_OPE_EXECCHECK_TOPSEARCH	(ME_OPE_EXECCHECK | ME_OPESRC_TOPSEARCH)	/* サーチ未完								*/
#define	ME_OPE_EXECCHECK_SEARCHING	(ME_OPE_EXECCHECK | ME_OPESRC_SEARCHING)	/* サーチ中 								*/
#define	ME_OPE_EXECCHECK_RUNNING	(ME_OPE_EXECCHECK | ME_OPESRC_RUNNING)		/* プログラム運転中 						*/
#define	ME_OPE_EXECCHECK_ADDR		(ME_OPE_EXECCHECK | ME_OPE_ADDR)			/* アドレスが不正							*/
#define	ME_OPE_EXECCHECK_PRGERR		(ME_OPE_EXECCHECK | 0x20)					/* プログラム実行エラー						*/
#define	ME_OPE_EXECCHECK_ERRREQUEST	(ME_OPE_EXECCHECK | 0x21)					/* 要求とNCの状態が一致しない				*/
#define	ME_OPE_EXECCHECK_SORT		(ME_OPE_EXECCHECK | ME_OPESRC_SORT)			/* 工具データソート中でプログラム実行できない	*/
#define	ME_OPE_EXECCHECK_NOSHAPE	(ME_OPE_EXECCHECK | 0x22)					/* チェック高速モード切削ブロックなし		*//* P8X-A0176 */
#define	ME_OPE_EXECCHECK_CTRLFLAG	(ME_OPE_EXECCHECK | 0x23)					/* 制御フラグ不正							*//* P8X-A0176 */

#define	ME_OPE_GETDRAWDATA	(ME_OPE_ERR | 0x1F00)
#define	ME_OPE_GETDRAWDATA_RESET	(ME_OPE_GETDRAWDATA | ME_OPESRC_RESET)		/* リセット中								*/
#define	ME_OPE_GETDRAWDATA_TIMEOUT	(ME_OPE_GETDRAWDATA | ME_OPESRC_TIMEOUT)	/* タイムアウト								*/
#define	ME_OPE_GETDRAWDATA_ADDR		(ME_OPE_GETDRAWDATA | ME_OPE_ADDR)			/* アドレスが不正							*/
#define	ME_OPE_GETDRAWDATA_NOSEARCH	(ME_OPE_GETDRAWDATA | ME_OPESRC_TOPSEARCH)	/* チェックサーチされていない				*/
#define	ME_OPE_GETDRAWDATA_NOTCHECK	(ME_OPE_GETDRAWDATA | 0x20)					/* 取得できない状態にある(チェック中でない)	*/
#define	ME_OPE_GETDRAWDATA_DATAERR	(ME_OPE_GETDRAWDATA | 0x21)					/* NCとPC間の通信データにエラーがある		*/

#define	ME_OPE_SETKEY		(ME_ERR_FLG | 0x2000)
#define	ME_OPE_SETKEY_DATA	(ME_OPE_SETKEY | ME_DATA_VALUE)						/* データ範囲不正							*/

#define	ME_OPE_SIMUCTRL		(ME_OPE_ERR | 0x2100)
#define	ME_OPE_SIMUCTRL_ADDR			(ME_OPE_SIMUCTRL | ME_OPE_ADDR)			/* アドレスが不正 							*/
#define	ME_OPE_SIMUCTRL_NOOPTION		(ME_OPE_SIMUCTRL | 0x01)				/* シミュレーションI/Fなし 					*/
#define	ME_OPE_SIMUCTRL_MODE			(ME_OPE_SIMUCTRL | 0x02)				/* シミュレーションが実行中 				*/
#define	ME_OPE_SIMUCTRL_FUNC			(ME_OPE_SIMUCTRL | 0x03)				/* ファンクションコードが不正 				*/
#define	ME_OPE_SIMUCTRL_DATA			(ME_OPE_SIMUCTRL | 0x04)				/* データが不正 							*/

#define	ME_OPE_CURRALMEX	(ME_OPE_ERR | 0x2200)
#define	ME_OPE_CURRALMEX_NOS		(ME_OPE_CURRALMEX | 0x01)					/* 取得メッセージ数が不正					*/
#define	ME_OPE_CURRALMEX_ALMTYPE	(ME_OPE_CURRALMEX | 0x02)					/* アラーム種類が不正						*/
#define	ME_OPE_CURRALMEX_DATAERR	(ME_OPE_CURRALMEX | 0x03)					/* NCとPC間の通信データにエラーがある		*/
#define	ME_OPE_CURRALMEX_NOALM		(ME_OPE_CURRALMEX | 0x04)					/* <未使用>									*/
#define	ME_OPE_CURRALMEX_ADDR		(ME_OPE_CURRALMEX | ME_OPE_ADDR)			/* アドレス不正								*/
#define	ME_OPE_CURRALMEX_DATASIZE	(ME_OPE_CURRALMEX | ME_OPE_DATASIZE)		/* アプリケーションが用意したバッファに入りきらない*/
#define	ME_OPE_CURRALMEX_DATATYPE	(ME_OPE_CURRALMEX | ME_OPE_DATATYPE)		/* データタイプ不正							*/

/* データキャッシュ関連エラー	===============================================	*/
#define	ME_READ				(0x0060000)
#define	ME_READ_ERR			(ME_ERR_FLG | ME_READ)								/* データキャッシュ関連エラー				*/
#define	ME_READ_CACHE_ADDR	(ME_READ_ERR | ME_DATA_ADDR)						/* アドレス不正								*/
#define	ME_READ_CACHE_DATA	(ME_READ_ERR | ME_DATA_VALUE)						/* データ範囲不正							*/
#define	ME_READ_CACHE_SECT		(ME_READ_ERR | ME_DATA_SECTION)					/* 大区分番号不正							*/
#define	ME_READ_CACHE_SUBSECT	(ME_READ_ERR | ME_DATA_SUBSECTION)				/* 小区分番号不正							*/
#define	ME_READ_CACHE_AXIS		(ME_READ_ERR | ME_DATA_AXIS)					/* 軸指定不正								*/
#define	ME_READ_CACHE_WRITEONLY	(ME_READ_ERR | ME_DATA_WRITEONLY)				/* データタイプ不正							*/
#define	ME_READ_CACHE_READ		(ME_READ_ERR | ME_DATA_READERR)					/* データが読み出せない状態にある			*/
#define	ME_READ_CACHE_DATATYPE	(ME_READ_ERR | ME_DATA_DATATYPE)				/* データタイプ不正							*/
#define	ME_READ_CACHE_REGIST	(ME_READ_ERR | 0x01)							/* データリードキャッシュが無効				*/

/* NCファイルアクセス関連エラー	===================================	*/
#define	ME_FS_FILE			(0x0070000)
#define	ME_FS_FILE_ERR		(ME_ERR_FLG | ME_FS_FILE)			/* ファイルアクセス関連エラー */

#define	ME_FS_OPEN_FILE			(ME_FS_FILE_ERR | 0x0100)
#define	ME_FS_OPEN_FILE_FILEFULL		(ME_FS_OPEN_FILE | ME_FILE_FILEFULL)		/* 最大ファイルオープン数を越えた				*/
#define	ME_FS_OPEN_FILE_ALREADYOPEN		(ME_FS_OPEN_FILE | ME_FILE_OPEN)			/* すでにオープンされている						*/
#define	ME_FS_OPEN_FILE_BUSY			(ME_FS_OPEN_FILE | ME_FILE_BUSY)			/* ファイルがオープンできない状態にある(運転中)	*/
#define	ME_FS_OPEN_FILE_OPEN			(ME_FS_OPEN_FILE | ME_FILE_NOFILE)			/* ファイルをオープンできない					*/
#define	ME_FS_OPEN_FILE_MALLOC			(ME_FS_OPEN_FILE | 0x40)					/* 作業領域を確保できない						*/
#define	ME_FS_OPEN_FILE_NOTSUPPORTED	(ME_FS_OPEN_FILE | ME_COMMON_NOTSUPPORTED)	/* 未サポート(CF未対応)							*/
#define	ME_FS_OPEN_FILE_NODRIVE			(ME_FS_OPEN_FILE | ME_FILE_NODRIVE)			/* ドライブが存在しない							*/
#define	ME_FS_OPEN_FILE_NAMELENGTH		(ME_FS_OPEN_FILE | ME_FILE_NAMELENGTH)		/* ファイルパスが長い							*/
#define	ME_FS_OPEN_FILE_SORT			(ME_FS_OPEN_FILE | ME_FILE_SORT)			/* 工具データソート中でオープンができない		*/
#define	ME_FS_OPEN_FILE_SAFE_NOPASSWD	(ME_FS_OPEN_FILE | ME_FILE_SAFE_NOPASSWD)	/* 安全パスワードが未認証						*/

#define	ME_FS_CLOSE_FILE		(ME_FS_FILE_ERR | 0x0200)
#define	ME_FS_CLOSE_FILE_NOTOPEN		(ME_FS_CLOSE_FILE | ME_FILE_NOTOPEN)		/* ファイルがオープンされていない				*/

#define	ME_FS_CREATE_FILE		(ME_FS_FILE_ERR | 0x0300)
#define	ME_FS_CREATE_FILE_FILEFULL		(ME_FS_CREATE_FILE | ME_FILE_FILEFULL)		/* 最大ファイルオープン数を越えた				*/
#define	ME_FS_CREATE_FILE_ALREADYOPEN	(ME_FS_CREATE_FILE | ME_FILE_OPEN)			/* すでに生成されている							*/
#define	ME_FS_CREATE_FILE_BUSY			(ME_FS_CREATE_FILE | ME_FILE_BUSY)			/* ファイルが生成できない状態にある(運転中)		*/
#define	ME_FS_CREATE_FILE_CREATE		(ME_FS_CREATE_FILE | ME_FILE_CREATE)		/* ファイルを生成できない						*/
#define	ME_FS_CREATE_FILE_MALLOC		(ME_FS_CREATE_FILE | 0x40)					/* 作業領域を確保できない						*/
#define	ME_FS_CREATE_FILE_NOTSUPPORTED	(ME_FS_CREATE_FILE | ME_COMMON_NOTSUPPORTED) /* 未サポート(CF未対応)						*/
#define	ME_FS_CREATE_FILE_NODRIVE		(ME_FS_CREATE_FILE | ME_FILE_NODRIVE)		/* ドライブが存在しない							*/
#define	ME_FS_CREATE_FILE_NAMELENGTH	(ME_FS_CREATE_FILE | ME_FILE_NAMELENGTH)	/* ファイルパスが長い							*/

#define	ME_FS_READ_FILE			(ME_FS_FILE_ERR | 0x0400)
#define	ME_FS_READ_FILE_NOTOPEN			(ME_FS_READ_FILE | ME_FILE_NOTOPEN)			/* ファイルがオープンされていない				*/
#define	ME_FS_READ_FILE_READ			(ME_FS_READ_FILE | ME_FILE_READERR)			/* ファイル情報リードエラー						*/

#define	ME_FS_WRITE_FILE		(ME_FS_FILE_ERR | 0x0500)
#define	ME_FS_WRITE_FILE_NOTOPEN		(ME_FS_WRITE_FILE | ME_FILE_NOTOPEN)		/* ファイルがオープンされていない				*/
#define	ME_FS_WRITE_FILE_WRITE			(ME_FS_WRITE_FILE | ME_FILE_WRITEERR)		/* ファイル書き込みエラー						*/
#define	ME_FS_WRITE_FILE_NOTSUPPORTED	(ME_FS_WRITE_FILE | ME_COMMON_NOTSUPPORTED)	/* 書き込み不可									*/

#define	ME_FS_LSEEK_FILE		(ME_FS_FILE_ERR | 0x0600)
#define	ME_FS_LSEEK_FILE_NOTOPEN		(ME_FS_LSEEK_FILE | ME_FILE_NOTOPEN)		/* ファイルがオープンされていない				*/
#define	ME_FS_LSEEK_FILE_FUNCTION		(ME_FS_LSEEK_FILE | ME_COMMON_CMDFORMAT)	/* シークモード不正(未対応)						*/
#define	ME_FS_LSEEK_FILE_SEEKERR		(ME_FS_LSEEK_FILE | 0x40)					/* ファイルシークエラー							*/

#define	ME_FS_REMOVE_FILE		(ME_FS_FILE_ERR | 0x0700)
#define	ME_FS_REMOVE_FILE_ALREADYOPEN	(ME_FS_REMOVE_FILE | ME_FILE_OPEN)			/* ファイルがオープンされている					*/
#define	ME_FS_REMOVE_FILE_BUSY			(ME_FS_REMOVE_FILE | ME_FILE_BUSY)			/* ファイルが削除できない状態にある(運転中)		*/
#define	ME_FS_REMOVE_FILE_NOFILE		(ME_FS_REMOVE_FILE | ME_FILE_NOFILE)		/* ファイルが存在しない							*/
#define	ME_FS_REMOVE_FILE_REMOVEERR		(ME_FS_REMOVE_FILE | 0x40)					/* ファイル削除エラー							*/
#define	ME_FS_REMOVE_FILE_NOTSUPPORTED	(ME_FS_REMOVE_FILE | ME_COMMON_NOTSUPPORTED) /* 未サポート(CF未対応)						*/
#define	ME_FS_REMOVE_FILE_NODRIVE		(ME_FS_REMOVE_FILE | ME_FILE_NODRIVE)		/* ドライブが存在しない							*/
#define	ME_FS_REMOVE_FILE_NAMELENGTH	(ME_FS_REMOVE_FILE | ME_FILE_NAMELENGTH)	/* ファイルパスが長い							*/

#define	ME_FS_RENAME_FILE		(ME_FS_FILE_ERR | 0x0800)
#define	ME_FS_RENAME_FILE_NOFILE		(ME_FS_RENAME_FILE | ME_FILE_NOFILE)		/* ファイルが存在しない							*/
#define	ME_FS_RENAME_FILE_ALREADYOPEN	(ME_FS_RENAME_FILE | ME_FILE_OPEN)			/* ファイルがオープンされている					*/
#define	ME_FS_RENAME_FILE_FILEFULL		(ME_FS_RENAME_FILE | ME_FILE_FILEFULL)		/* 最大ファイルオープン数を越えた				*/
#define	ME_FS_RENAME_FILE_NOTRENAME		(ME_FS_RENAME_FILE | ME_COMMON_FILESYSTEM)	/* リネームできないファイル						*/
#define	ME_FS_RENAME_FILE_NOTSUPPORTED	(ME_FS_RENAME_FILE | ME_COMMON_NOTSUPPORTED) /* 未サポート(CF未対応)						*/
#define	ME_FS_RENAME_FILE_NODRIVE		(ME_FS_RENAME_FILE | ME_FILE_NODRIVE)		/* ドライブが存在しない							*/
#define	ME_FS_RENAME_FILE_NAMELENGTH	(ME_FS_RENAME_FILE | ME_FILE_NAMELENGTH)	/* ファイルパスが長い							*/

#define	ME_FS_IOCTL_FILE		(ME_FS_FILE_ERR | 0x0900)
#define	ME_FS_IOCTL_FILE_NOTOPEN		(ME_FS_IOCTL_FILE | ME_FILE_NOTOPEN)		/* オープンされていない							*/
#define	ME_FS_IOCTL_FILE_READ			(ME_FS_IOCTL_FILE | ME_FILE_READERR)		/* リードエラー									*/
#define	ME_FS_IOCTL_FILE_WRITE			(ME_FS_IOCTL_FILE | ME_FILE_WRITEERR)		/* ライトエラー									*/
#define	ME_FS_IOCTL_FILE_FUNCTION		(ME_FS_IOCTL_FILE | ME_COMMON_CMDFORMAT)	/* コマンド不正(未対応)							*/
#define	ME_FS_IOCTL_FILE_NOTSUPPORTED	(ME_FS_IOCTL_FILE | ME_COMMON_NOTSUPPORTED) /* 未サポート(CF未対応)							*/
#define	ME_FS_IOCTL_FILE_DATATYPE		(ME_FS_IOCTL_FILE | ME_DATA_DATATYPE)		/* データタイプ不正								*/
#define	ME_FS_IOCTL_FILE_DATASIZE		(ME_FS_IOCTL_FILE | ME_DATA_SIZE)			/* アプリケーションが用意したバッファに入りきらない	*/

#define	ME_FS_OPEN_DIRECTORY	(ME_FS_FILE_ERR | 0x0a00)
#define	ME_FS_OPEN_DIR_FILEFULL			(ME_FS_OPEN_DIRECTORY | ME_FILE_FILEFULL)	/* 最大ディレクトリオープン数を越えた			*/
#define	ME_FS_OPEN_DIR_NOTOPEN			(ME_FS_OPEN_DIRECTORY | ME_FILE_OPEN)		/* すでにオープンされている						*/
#define	ME_FS_OPEN_DIR_BUSY				(ME_FS_OPEN_DIRECTORY | ME_FILE_BUSY)		/* ディレクトリがオープンできない状態にある(運転中)	*/
#define	ME_FS_OPEN_DIR_NODIR			(ME_FS_OPEN_DIRECTORY | ME_FILE_NODIR)		/* ディレクトリが存在しない						*/
#define	ME_FS_OPEN_DIR_MALLOC			(ME_FS_OPEN_DIRECTORY | 0x40)				/* 作業領域を確保できない						*/
#define	ME_FS_OPEN_DIR_NOTSUPPORTED		(ME_FS_OPEN_DIRECTORY | ME_COMMON_NOTSUPPORTED)	/* 未サポート(CF未対応)						*/
#define	ME_FS_OPEN_DIR_NODRIVE			(ME_FS_OPEN_DIRECTORY | ME_FILE_NODRIVE)	/* ドライブが存在しない							*/
#define	ME_FS_OPEN_DIR_NAMELENGTH		(ME_FS_OPEN_DIRECTORY | ME_FILE_NAMELENGTH)	/* ファイルパスが長い							*/

#define	ME_FS_READ_DIRECTORY	(ME_FS_FILE_ERR | 0x0b00)
#define	ME_FS_READ_DIR_NOTOPEN			(ME_FS_READ_DIRECTORY | ME_FILE_NOTOPEN)	/* ディレクトリがオープンされていない			*/
#define	ME_FS_READ_DIR_NODIR			(ME_FS_READ_DIRECTORY | ME_FILE_NODIR) 		/* ディレクトリが存在しない						*/
#define	ME_FS_READ_DIR_DATASIZE			(ME_FS_READ_DIRECTORY | ME_DATA_SIZE) 		/* アプリケーションが用意したバッファに入りきらない	*/

#define	ME_FS_REWIND_DIRECTORY	(ME_FS_FILE_ERR | 0x0c00)
#define	ME_FS_REWIND_DIR_NOTOPEN		(ME_FS_REWIND_DIRECTORY | ME_FILE_NOTOPEN)	/* ディレクトリがオープンされていない			*/
#define	ME_FS_REWIND_DIR_REWINDERR		(ME_FS_REWIND_DIRECTORY | 0x40)				/* リワインドエラー								*/

#define	ME_FS_CLOSE_DIRECTORY	(ME_FS_FILE_ERR | 0x0d00)
#define	ME_FS_CLOSE_DIR_NOTOPEN			(ME_FS_CLOSE_DIRECTORY | ME_FILE_NOTOPEN)	/* ディレクトリがオープンされていない			*/

#define	ME_FS_STAT_FILE			(ME_FS_FILE_ERR | 0x0e00)
#define	ME_FS_STAT_FILE_FILEFULL		(ME_FS_STAT_FILE | ME_FILE_FILEFULL)		/* 最大ファイルオープン数を越えた				*/
#define	ME_FS_STAT_FILE_STATERR			(ME_FS_STAT_FILE | ME_FILE_READERR)			/* ファイル情報読み込みエラー					*/
#define	ME_FS_STAT_FILE_NOTSUPPORTED	(ME_FS_STAT_FILE | ME_COMMON_NOTSUPPORTED)	/* 未サポート(CF未対応)							*/
#define	ME_FS_STAT_FILE_NODRIVE			(ME_FS_STAT_FILE | ME_FILE_NODRIVE)			/* ドライブが存在しない							*/
#define	ME_FS_STAT_FILE_NAMELENGTH		(ME_FS_STAT_FILE | ME_FILE_NAMELENGTH)		/* ファイルパスが長い							*/

#define	ME_FS_FSTAT_FILE		(ME_FS_FILE_ERR | 0x0f00)
#define	ME_FS_FSTAT_FILE_NOTOPEN		(ME_FS_FSTAT_FILE | ME_FILE_NOTOPEN)		/* ファイルがオープンされていないた				*/
#define	ME_FS_FSTAT_FILE_STATERR		(ME_FS_FSTAT_FILE | ME_FILE_READERR)		/* ファイル情報読み込みエラー					*/
#define	ME_FS_FSTAT_FILE_NOTSUPPORTED	(ME_FS_FSTAT_FILE | ME_COMMON_NOTSUPPORTED)	/* 未サポート(CF未対応)							*/
#define	ME_FS_FSTAT_FILE_NODRIVE		(ME_FS_FSTAT_FILE | ME_FILE_NODRIVE)		/* ドライブが存在しない							*/
#define	ME_FS_FSTAT_FILE_NAMELENGTH		(ME_FS_FSTAT_FILE | ME_FILE_NAMELENGTH)		/* ファイルパスが長い							*/

#define	ME_FS_IOCTL_UOPEN_FORMAT	(ME_FS_IOCTL_FILE | ME_FILE_UOPEN_FORMAT)			/* SRAM開放パラ不正でフォーマット中止	*/

/* FTP通信関連エラー	=======================================	*/
#define	ME_FTP				(0x0080000)
#define	ME_FTP_ERR			(ME_ERR_FLG | ME_FTP)
#define	ME_FTP_IOCTL		(ME_FTP_ERR | 0x1000)					/* FTP通信エラー				*/
#define	ME_FTP_UNKNOWNFUNC	(ME_FTP_ERR | ME_DEV_UNKNOWNFUNC)		/* コマンド不正					*/

#define	ME_FTP_SOCKET		(ME_FTP_IOCTL | 0x0100)					/* ソケット作成エラー			*/
#define	ME_FTP_BIND			(ME_FTP_IOCTL | 0x0200)					/* バインドエラー				*/
#define	ME_FTP_LISTEN		(ME_FTP_IOCTL | 0x0300)					/* リッスンエラー				*/
#define	ME_FTP_ACCEPT		(ME_FTP_IOCTL | 0x0400)					/* アクセプトエラー				*/
#define	ME_FTP_CLOSE		(ME_FTP_IOCTL | 0x0500)					/* クローズエラー				*/
#define	ME_FTP_CONNECT		(ME_FTP_IOCTL | 0x0600)					/* コネクトエラー				*/
#define	ME_FTP_SEND			(ME_FTP_IOCTL | 0x0700)					/* 送信エラー					*/
#define	ME_FTP_RECV			(ME_FTP_IOCTL | 0x0800)					/* 受信エラー					*/
#define	ME_FTP_GETSCKNAME	(ME_FTP_IOCTL | 0x0900)					/* ソケット名取得エラー			*/
#define	ME_FTP_HOSTNAME		(ME_FTP_IOCTL | 0x0a00)					/* IPアドレス取得エラー			*/

#define	ME_FTP_EACCES				(0x01)				/* アクセス許可がない						*/
#define	ME_FTP_EAFNOSUPPORT			(0x02)				/* アドレスファミリー未サポート				*/
#define	ME_FTP_EINVAL				(0x03)				/* 無効な引数								*/
#define	ME_FTP_EMFILE				(0x04)				/* ファイルテーブルオーバーフロー			*/
#define	ME_FTP_ENOMEM				(0x05)				/* メモリ不足(同 ENFILE,ENOBUFS)			*/
#define	ME_FTP_EPROTONOSUPPORT		(0x06)				/* プロトコル未サポート						*/
#define	ME_FTP_EAGAIN				(0x07)				/* ソケット非停止(同 EWOULDBLOCK)			*/
#define	ME_FTP_EBADF				(0x08)				/* ディスクリプタ不正(同 ENOTSOCK)			*/
#define	ME_FTP_ECONNREFUSED			(0x09)				/* リモートホストのネットワーク接続拒否		*/
#define	ME_FTP_EFAULT				(0x0a)				/* アドレス不正								*/
#define	ME_FTP_EINTR				(0x0b)				/* シグナルによる処理中断					*/
#define	ME_FTP_ENOTCONN				(0x0c)				/* ソケット未接続							*/
#define	ME_FTP_ECONNRESET			(0x0d)				/* 接続リセット								*/
#define	ME_FTP_EDESTADDRREQ			(0x0e)				/* 送信先アドレス未設定						*/
#define	ME_FTP_EISCONN				(0x0f)				/* 接続先の受信者指定不一致					*/
#define	ME_FTP_EMSGSIZE				(0x10)				/* 送信サイズ超過							*/
#define	ME_FTP_EOPNOTSUPP			(0x11)				/* フラグ不正								*/
#define	ME_FTP_EPIPE				(0x12)				/* ローカルソケット切断						*/
#define	ME_FTP_EADDRINUSE			(0x13)				/* アドレス使用中							*/
#define	ME_FTP_UNKNOWN				(0xFF)				/* その他エラー								*/

/* NCカード システム関連エラー	===========================================	*/
#define	ME_SYS				(0x1000000)
#define	ME_SYS_ERR			(ME_ERR_FLG | ME_SYS)					/* NCカード システム関連エラー */

#define	ME_SYS_CONTROLER		(ME_SYS_ERR | 0x0100)
#define	ME_SYS_READYON			(ME_SYS_CONTROLER | 0x01)			/* <未使用> */
#define	ME_SYS_SYSTEMDOWN		(ME_SYS_CONTROLER | 0x02)			/* NCカードがシステムダウンしている*/

#define	ME_SYS_OS			(ME_SYS_ERR | 0x8000)
#define	ME_SYS_MALLOC			(ME_SYS_OS | 0x01)					/* 作業領域を確保できない*/

/* PC システム関連エラー	===========================================	*/
#define	ME_PCSYS			(0x1010000)
#define	ME_PCSYS_ERR			(ME_ERR_FLG | ME_PCSYS)				/* PC システム関連エラー */

#define	ME_PCSYS_WIN			(ME_PCSYS_ERR | 0x0100)
#define	ME_PCSYS_EXECCOMTASK		(ME_PCSYS_WIN |0x01)			/* 通信タスクを起動できない*/
#define	ME_PCSYS_SEMAPHRETIMEOUT 	(ME_PCSYS_WIN | ME_DEV_TIMEOUT)	/* 排他制御タイムアウト*/

#define	ME_PCSYS_OS			(ME_PCSYS_ERR | 0x8000)
#define	ME_PCSYS_MALLOC			(ME_PCSYS_OS | 0x01)				/* 作業領域を確保できない*/
#define	ME_PCSYS_MLOCK			(ME_PCSYS_OS | 0x02)				/* 作業領域が不正*/
#define	ME_PCSYS_SEMAPHRE		(ME_PCSYS_OS | 0x03)				/* 排他制御ができない */
#define	ME_PCSYS_TRANSLATION	(ME_PCSYS_OS | 0x04)				/* 文字列変換が出来ない	*/
#define	ME_PCSYS_VALUE			(ME_PCSYS_OS | ME_DATA_VALUE)		/* データ値が不正 */

/* ２ポートメモリ通信関連エラー	=======================================	*/
#define	ME_SMEM				(0x2000000)
#define	ME_SMEM_ERR			(ME_ERR_FLG | ME_SMEM)			/* ２ポートメモリ通信関連エラー */

#define	ME_SMEM_ALREADYOPEN		(ME_SMEM_ERR | ME_DEV_ALREADYOPEN)	/* すでにオープンされている*/
#define	ME_SMEM_NOTOPEN			(ME_SMEM_ERR | ME_DEV_NOTOPEN)		/* オープンされていない*/
#define	ME_SMEM_CARDNOTEXIST		(ME_SMEM_ERR | ME_DEV_CARDNOTEXIST)	/* カードが存在しない*/
#define	ME_SMEM_BADCHANNEL		(ME_SMEM_ERR | ME_DEV_BADCHANNEL)	/* チャンネル番号不正*/
#define	ME_SMEM_BADFD			(ME_SMEM_ERR | ME_DEV_BADFD)		/* ファイルディスクプリタ不正*/
#define	ME_SMEM_CANNOTOPEN		(ME_SMEM_ERR | ME_DEV_CANNOTOPEN)	/* オープンできない*/
#define	ME_SMEM_TIMEOUT			(ME_SMEM_ERR | ME_DEV_TIMEOUT)		/* タイムアウト*/
#define	ME_SMEM_DATAERR			(ME_SMEM_ERR | ME_DEV_DATAERR)		/* <未使用> */
#define	ME_SMEM_CANCELED		(ME_SMEM_ERR | ME_DEV_CANCELED)		/* キャンセル要求により終了した*/
#define	ME_SMEM_ILLEGALSIZE		(ME_SMEM_ERR | ME_DEV_ILLEGALSIZE)	/* パケットサイズ不正*/
#define	ME_SMEM_TASKQUIT		(ME_SMEM_ERR | ME_DEV_TASKQUIT)		/* タスク終了により終了した*/
#define	ME_SMEM_UNKNOWNFUNC		(ME_SMEM_ERR | ME_DEV_UNKNOWNFUNC)	/* コマンド不正*/
#define	ME_SMEM_SETDATAERR		(ME_SMEM_ERR | ME_DEV_SETDATAERR)	/* <未使用> */

/* シリアル通信関連エラー	===========================================	*/
#define	ME_SIO				(0x2010000)
#define	ME_SIO_ERR			(ME_ERR_FLG | ME_SIO)			/* シリアル通信関連エラー */
#define	ME_SIO_ERR_IO			(ME_SIO_ERR | 0x01)			/* I/Oエラー			  */
#define	ME_SIO_ERR_HANDLER		(ME_SIO_ERR | 0x02)			/* ハンドル不正			  */
#define	ME_SIO_ERR_OPENED		(ME_SIO_ERR | 0x0a)			/* オープン済み			  */
#define	ME_SIO_ERR_PARAMETER	(ME_SIO_ERR | 0x0e)			/* パラメータ不正		  */
#define	ME_SIO_ERR_NOT_READY	(ME_SIO_ERR | 0x10)			/* 指定port使用不可		  */
#define	ME_SIO_ERR_TIMEOUT		(ME_SIO_ERR | 0x1e)			/* タイムアウト発生		  */
#define	ME_SIO_ERR_OVER_RUN		(ME_SIO_ERR | 0x20)			/* オーバーラン			  */
#define	ME_SIO_ERR_PARITY		(ME_SIO_ERR | 0x21)			/* パリティエラー		  */
#define	ME_SIO_ERR_PARITYV		(ME_SIO_ERR | 0x22)			/* パリティＶエラー		  */
#define	ME_SIO_ERR_UNKNOWN		(ME_SIO_ERR | 0xff)			/* その他エラー			  */

/* イーサネット通信関連エラー	=======================================	*/
#define	ME_ENET				(0x2020000)
#define	ME_ENET_ERR			(ME_ERR_FLG | ME_ENET)

#define	ME_ENET_ALREADYOPEN		(ME_ENET_ERR | ME_DEV_ALREADYOPEN)	/* すでにオープンされている		M65*/
#define	ME_ENET_NOTOPEN			(ME_ENET_ERR | ME_DEV_NOTOPEN)		/* オープンされていない			M65*/
#define	ME_ENET_CARDNOTEXIST	(ME_ENET_ERR | ME_DEV_CARDNOTEXIST)	/* カードが存在しない			M65*/
#define	ME_ENET_BADCHANNEL		(ME_ENET_ERR | ME_DEV_BADCHANNEL)	/* チャンネル番号不正			M65*/
#define	ME_ENET_BADFD			(ME_ENET_ERR | ME_DEV_BADFD)		/* ファイルディスクプリタ不正	M65*/
#define	ME_ENET_NOTCONNECT		(ME_ENET_ERR | ME_DEV_NOTCONNECT)	/* コネクトされていない			M65*/
#define	ME_ENET_NOTCLOSE		(ME_ENET_ERR | ME_DEV_NOTCLOSE)		/* クローズされていない			M65*/
#define	ME_ENET_TIMEOUT			(ME_ENET_ERR | ME_DEV_TIMEOUT)		/* タイムアウト					M65*/
#define	ME_ENET_DATAERR			(ME_ENET_ERR | ME_DEV_DATAERR)		/* 								M65*/
#define	ME_ENET_CANCELED		(ME_ENET_ERR | ME_DEV_CANCELED)		/* キャンセル要求により終了した	M65*/
#define	ME_ENET_ILLEGALSIZE		(ME_ENET_ERR | ME_DEV_ILLEGALSIZE)	/* パケットサイズ不正			M65*/
#define	ME_ENET_TASKQUIT		(ME_ENET_ERR | ME_DEV_TASKQUIT)		/* タスク終了により終了した		M65*/
#define	ME_ENET_UNKNOWNFUNC		(ME_ENET_ERR | ME_DEV_UNKNOWNFUNC)	/* コマンド不正					M65*/
#define	ME_ENET_SETDATAERR		(ME_ENET_ERR | ME_DEV_SETDATAERR)	/* 								M65*/

/* EasySocketPC通信関連エラー	=======================================	*/
#define ME_EZPC					(0x2040000)
#define ME_EZPC_ERR				(ME_ERR_FLG | ME_EZPC)		/* EasySocketPC通信エラー */
#define ME_EZPC_OBJCTFREE		(ME_EZPC_ERR | 0x01)		/* すでにEasySocketPC通信オブジェクトが解放されている */

/* その他	===========================================================	*/
#define	ME_X				(0x0fff0000)
#define	ME_STS_OK			0										/* 正常終了						   */
#define	ME_STS_ERR			(-1)									/* 異常終了						   */

#ifdef TWOPORT														/* 								M65*/
/* リザルト	===========================================================	*/
#define	ME_RESULT			(0x0090000)								/*								M65*/
#define	ME_RESULT_ERR		(ME_ERR_FLG | ME_RESULT)				/*								M65*/
#define	ME_RESULT_NO		(ME_RESULT_ERR | 0x01)					/* ノーリザルトエラー			M65*/
#define	ME_RESULT_CONNECT	(ME_RESULT_ERR | 0x02)					/* コネクトエラー				M65*/
#define	ME_RESULT_TIMEOUT	(ME_RESULT_ERR | 0x03)					/* タイムアウトエラー			M65*/
#define	ME_RESULT_SOCKET	(ME_RESULT_ERR | 0x04)					/* ソケット切断エラー			M65*/
#define	ME_RESULT_TRANSMIT	(ME_RESULT_ERR | 0x05)					/* 通信エラー(システムコールエラー)	M65*/
#define	ME_RESULT_OVER		(ME_RESULT_ERR | 0x06)					/* オーバーフロー				M65*/
#define	ME_RESULT_PROTOCOL	(ME_RESULT_ERR | 0x07)					/* プロトコルエラー				M65*/
#endif /* TWOPORT M65*/

#endif	/*INCmelErrh*/

// 共通エラー定義ヘッダ
#include	"EZSocketCommonErr.h"

//EZSocketNc
#define EZ_ERR_MEMORY_ALLOC				0x80B00101	//ﾒﾓﾘの確保ができない
#define EZNC_ERR_MEMORY_ALLOC			0x80B00101	//ﾒﾓﾘの確保ができない
#define EZNC_ERR_CANNOT_GETPCERR		0x80B00102	//EZSocketPcのエラーが取得できない

#define EZNC_FILE_OPEN_MODE				0x80B00201	//モード指定不正
#define EZNC_FILE_OPEN_NOTOPEN			0x80B00202	//未ファイルオープン
#define EZNC_FILE_OPEN_FILEEXIST		0x80B00203	//ファイルが既に存在する
#define EZNC_FILE_OPEN_ALREADYOPENED	0x80B00204	//既にファイルオープンしている
#define EZNC_FILE_OPEN_CREATE			0x80B00205	//テンポラリファイルを作成できない
#define EZNC_FILE_WRITEFILE_NOTOPEN		0x80B00206	//書き込みモード指定でファイルオープンしていない
#define EZNC_FILE_WRITEFILE_LENGTH		0x80B00207	//書き込みデータサイズ不正
#define EZNC_FILE_WRITEFILE_WRITE		0x80B00208	//書き込みできない状態
#define EZNC_FILE_READFILE_NOTOPEN		0x80B00209	//読み出しモード指定でファイルオープンしていない
#define EZNC_FILE_READFILE_READ			0x80B0020A	//読み出しできない状態
#define EZNC_FILE_READFILE_CREATE		0x80B0020B	//テンポラリファイルを作成できない
#define EZNC_FILE_OPEN_FILENOTEXIST		0x80B0020C	//ファイルが存在しない
#define EZNC_FILE_OPEN_OPEN				0x80B0020D	//ファイルがオープンできない
#define EZNC_FILE_OPEN_ILLEGALPATH		0x80B0020E	//ファイルのパスが不正
#define EZNC_FILE_READFILE_ILLEGALFILE	0x80B0020F	//読み出しファイルが不正
#define EZNC_FILE_WRITEFILE_ILLEGALFILE	0x80B00210	//書き込みファイルが不正

#define	EZNC_COMM_CANNOT_OPEN			0x80B00301
#define	EZNC_COMM_NOTSETUP_PROTOCOL		0x80B00302	//TCP/IP通信が設定されていない
#define	EZNC_COMM_ALREADYOPENED			0x80B00303	//既に通信中なので設定できない
#define EZNC_COMM_NOTMODULE				0x80B00304	//下位モジュールがない
#define EZNC_COMM_CREATEPC				0x80B00305	//EZSocketPcオブジェクトが生成できない

#define	EZNC_DATA_NOT_EXIST				0x80B00401	//データが存在しない
#define	EZNC_DATA_DUPLICATE				0x80B00402	//データ重複

#define	EZNC_PARAM_FILENOTEXIST			0x80B00501	//パラメータ情報ファイルがありません

#define EZNC_SYSFUNC_IOCTL_ADDR			ME_SYSFUNC_IOCTL_ADDR		// NCｶｰﾄﾞ番号不正
#define EZNC_SYSFUNC_IOCTL_NOTOPEN		ME_SYSFUNC_IOCTL_NOTOPEN	// ﾃﾞﾊﾞｲｽがｵｰﾌﾟﾝされていない
#define EZNC_SYSFUNC_IOCTL_DATA			ME_SYSFUNC_IOCTL_DATA		// 通信パラメータデータ範囲不正
#define EZNC_SYSFUNC_IOCTL_FUNCTION		ME_SYSFUNC_IOCTL_FUNCTION	// ｺﾏﾝﾄﾞ不正

#define EZNC_OPE_ACTPLC_ADDR			ME_OPE_ACTPLC_ADDR			// アドレス不正
#define EZNC_OPE_ACTPLC_MODE			ME_OPE_ACTPLC_MODE			// ﾓｰﾄﾞ不正

#define EZNC_OPE_CURRALM_ADDR			ME_OPE_CURRALM_ADDR			// 系統､軸指定が不正
#define EZNC_OPE_CURRALM_ALMTYPE		ME_OPE_CURRALM_ALMTYPE		// ｱﾗｰﾑ種類が不正
#define EZNC_OPE_CURRALM_DATAERR		ME_OPE_CURRALM_DATAERR		// NCとPC間の通信ﾃﾞｰﾀにｴﾗｰがある
#define EZNC_OPE_CURRALM_DATASIZE		ME_OPE_CURRALM_DATASIZE		// ｱﾌﾟﾘｹｰｼｮﾝが用意したﾊﾞｯﾌｧに入りきらない
#define EZNC_OPE_CURRALM_NOS			ME_OPE_CURRALM_NOS			// 取得ﾒｯｾｰｼﾞ数が不正
#define	EZNC_OPE_CURRALM_DATATYPE		ME_OPE_CURRALM_DATATYPE		// データタイプ不正

#define	EZNC_OPE_CURRALMEX_NOS			ME_OPE_CURRALMEX_NOS		// 取得メッセージ数が不正
#define	EZNC_OPE_CURRALMEX_ALMTYPE		ME_OPE_CURRALMEX_ALMTYPE	// アラーム種類が不正
#define	EZNC_OPE_CURRALMEX_DATAERR		ME_OPE_CURRALMEX_DATAERR	// NCとPC間の通信データにエラーがある
#define	EZNC_OPE_CURRALMEX_ADDR			ME_OPE_CURRALMEX_ADDR		// アドレス不正
#define	EZNC_OPE_CURRALMEX_DATASIZE		ME_OPE_CURRALMEX_DATASIZE	// アプリケーションが用意したバッファに入りきらない
#define	EZNC_OPE_CURRALMEX_DATATYPE		ME_OPE_CURRALMEX_DATATYPE	// データタイプ不正

#define EZNC_OPE_GETPRGBLK_NOS			ME_OPE_GETPRGBLK_NOS		// ﾌﾞﾛｯｸ数指定が不正
#define EZNC_OPE_GETPRGBLK_ADDR			ME_OPE_GETPRGBLK_ADDR		// 系統､軸指定が不正
#define EZNC_OPE_GETPRGBLK_NOSEARCH		ME_OPE_GETPRGBLK_NOSEARCH	// 運転ｻｰﾁ未完了
#define EZNC_OPE_GETPRGBLK_DATAERR		ME_OPE_GETPRGBLK_DATAERR	// NCとPC間の通信ﾃﾞｰﾀにｴﾗｰがある
#define EZNC_OPE_GETPRGBLK_DATASIZE		ME_OPE_GETPRGBLK_DATASIZE	// ｱﾌﾟﾘｹｰｼｮﾝが用意したﾊﾞｯﾌｧに入りきらない
#define EZNC_OPE_GETPRGBLK_DATATYPE		ME_OPE_GETPRGBLK_DATATYPE	// ﾃﾞｰﾀﾀｲﾌﾟ不正

#define EZNC_OPE_SELECTPRG_ADDR			ME_OPE_SELECTPRG_ADDR		// 系統指定が不正
#define EZNC_OPE_SELECTPRG_FILESYSTEM	ME_OPE_SELECTPRG_FILESYSTEM	// ﾌｧｲﾙｼｽﾃﾑに異常がある
#define EZNC_OPE_SELECTPRG_NOPRG 		ME_OPE_SELECTPRG_NOPRG		// ﾌﾟﾛｸﾞﾗﾑﾌｧｲﾙがない
#define EZNC_OPE_SELECTPRG_PRGFORMAT	ME_OPE_SELECTPRG_PRGFORMAT	// ﾌﾟﾛｸﾞﾗﾑﾌｧｲﾙ名ﾌｫｰﾏｯﾄが不正
#define EZNC_OPE_SELECTPRG_RUNNING		ME_OPE_SELECTPRG_RUNNING	// ﾌﾟﾛｸﾞﾗﾑ運転中
#define	EZNC_OPE_SELECTPRG_RESET		ME_OPE_SELECTPRG_RESET		// 運転サーチができない状態にある(リセット中)
#define	EZNC_OPE_SELECTPRG_LONGPATH		ME_OPE_SELECTPRG_LONGPATH	// パス名が長い
#define	EZNC_OPE_SELECTPRG_TIMEOUT		ME_OPE_SELECTPRG_TIMEOUT	// タイムアウト
#define	EZNC_OPE_SELECTPRG_FILEREAD		ME_OPE_SELECTPRG_FILEREAD	// ファイル読込エラー
#define	EZNC_OPE_SELECTPRG_FILEWRITE	ME_OPE_SELECTPRG_FILEWRITE	// ファイル書込エラー
#define	EZNC_OPE_SELECTPRG_DATATYPE		ME_OPE_SELECTPRG_DATATYPE 	// データタイプ不正
#define	EZNC_OPE_SELECTPRG_NOTPRG		ME_OPE_SELECTPRG_NOTPRG		// ﾌﾟﾛｸﾞﾗﾑﾌｧｲﾙがない
#define	EZNC_OPE_SELECTPRG_NCPCCOM		ME_OPE_SELECTPRG_NCPCCOM	// ncpccom.exeが無い
#define	EZNC_OPE_SELECTPRG_SEARCHING	ME_OPE_SELECTPRG_SEARCHING	// 運転ｻｰﾁができない状態にある(ｻｰﾁ中)
#define	EZNC_OPE_SELECTPRG_CHECKING		ME_OPE_SELECTPRG_CHECKING	// ｻｰﾁができない状態にある(ﾁｪｯｸ中)
#define	EZNC_OPE_SELECTPRG_MODE			ME_OPE_SELECTPRG_MODE		// ﾓｰﾄﾞ不正
#define	EZNC_OPE_SELECTPRG_NOTSUPPORTED	ME_OPE_SELECTPRG_NOTSUPPORTED	// ｻｰﾁができない(ｵﾌﾟｼｮﾝなし)
#define	EZNC_OPE_SELECTPRG_PGLKC		ME_OPE_SELECTPRG_PGLKC		// ｻｰﾁができない(ﾌﾟﾛｸﾞﾗﾑ表示ﾛｯｸC)
#define	EZNC_OPE_SELECTPRG_ILLEGALPOS	ME_OPE_SELECTPRG_ILLEGALPOS	// 指定位置不正
#define	EZNC_OPE_SELECTPRG_REVERSE		ME_OPE_SELECTPRG_REVERSE	// 任意逆行中
#define	EZNC_OPE_SELECTPRG_PROTECT		ME_OPE_SELECTPRG_PROTECT	// サーチができない(プログラムの運転／編集禁止中)
#define EZNC_DATA_READ_ADDR				ME_DATA_READ_ADDR			// 系統､軸指定が不正
#define EZNC_DATA_READ_DATASIZE			ME_DATA_READ_DATASIZE		// ｱﾌﾟﾘｹｰｼｮﾝが用意したﾊﾞｯﾌｧに入りきらない
#define EZNC_DATA_READ_READ				ME_DATA_READ_READ			// ﾃﾞｰﾀが読み出せない状態にある
#define EZNC_DATA_READ_DATATYPE			ME_DATA_READ_DATATYPE		// ﾃﾞｰﾀﾀｲﾌﾟ不正
#define EZNC_DATA_READ_SECT				ME_DATA_READ_SECT			// 大区分不正
#define EZNC_DATA_READ_SUBSECT			ME_DATA_READ_SUBSECT		// 小区分不正
#define	EZNC_DATA_READ_WRITEONLY		ME_DATA_READ_WRITEONLY		// 書き込み専用データ
#define	EZNC_DATA_READ_AXIS				ME_DATA_READ_AXIS			// 軸指定不正
#define	EZNC_DATA_READ_DATANUM			ME_DATA_READ_DATANUM		// データ番号不正
#define	EZNC_DATA_READ_NODATA			ME_DATA_READ_NODATA			// 読み出しデータなし
#define	EZNC_DATA_READ_VALUE			ME_DATA_READ_VALUE			// 読み出しデータ範囲不正

#define EZNC_DATA_WRITE_ADDR			ME_DATA_WRITE_ADDR			// 系統､軸指定が不正
#define EZNC_DATA_WRITE_DATASIZE		ME_DATA_WRITE_DATASIZE		// ｱﾌﾟﾘｹｰｼｮﾝが用意したﾊﾞｯﾌｧに入りきらない
#define EZNC_DATA_WRITE_WRITE			ME_DATA_WRITE_WRITE			// ﾃﾞｰﾀが書き込めない状態にある
#define EZNC_DATA_WRITE_DATATYPE		ME_DATA_WRITE_DATATYPE		// ﾃﾞｰﾀﾀｲﾌﾟ不正
#define EZNC_DATA_WRITE_SECT			ME_DATA_WRITE_SECT			// 大区分不正
#define EZNC_DATA_WRITE_SUBSECT			ME_DATA_WRITE_SUBSECT		// 小区分不正
#define	EZNC_DATA_WRITE_READONLY		ME_DATA_WRITE_READONLY		// 読み出し専用データ
#define	EZNC_DATA_WRITE_AXIS			ME_DATA_WRITE_AXIS			// 軸指定不正
#define	EZNCDATA_WRITE_SAFETYPWLOCK		ME_DATA_WRITE_SAFETYPWLOCK	// 安全パスワードロック中
#define	EZNCDATA_WRITE_UOPEN_FORMAT		ME_DATA_WRITE_UOPEN_FORMAT	// SRAM開放パラメータ不正によりフォーマット中止した
#define	EZNCDATA_WRITE_EDTFILE_REGIST	ME_DATA_WRITE_EDTFILE_REGIST	// 編集ァイルを登録できない(既に編集中)
#define	EZNCDATA_WRITE_EDTFILE_RELEASE	ME_DATA_WRITE_EDTFILE_RELEASE	// 編集ファイルを解除できない
#define	EZNCDATA_WRITE_NODATA			ME_DATA_WRITE_NODATA		// 書き込み先データなし
#define	EZNCDATA_WRITE_VALUE			ME_DATA_WRITE_VALUE			// 書き込みデータ範囲不正
#define	EZNCDATA_WRITE_SAFE_NOPASSWD	ME_DATA_WRITE_SAFE_NOPASSWD	// 安全パスワード未設定
#define	EZNCDATA_WRITE_SAFE_CHECKERR	ME_DATA_WRITE_SAFE_CHECKERR	// 安全データ整合性チェックエラー
#define	EZNCDATA_WRITE_SAFE_DATATYPE	ME_DATA_WRITE_SAFE_DATATYPE	// 安全用データタイプ不
#define	EZNCDATA_WRITE_SORT				ME_DATA_WRITE_SORT			// 工具データソート中で書き込みできない

#define EZNC_DATA_MDLCANCEL_NOTREGIST	ME_DATA_MDLCANCEL_NOTREGIST	// 高速読み出し登録されていない

#define EZNC_DATA_MDLREGIST_PRIORITY	ME_DATA_MDLREGIST_PRIORITY	// ﾌﾟﾗｲｵﾘﾃｨ指定不正
#define EZNC_DATA_MDLREGIST_REGIST		ME_DATA_MDLREGIST_REGIST	// 登録数をｵｰﾊﾞした
#define EZNC_DATA_MDLREGIST_ADDR		ME_DATA_MDLREGIST_ADDR		// ｱﾄﾞﾚｽ不正
#define EZNC_DATA_MDLREGIST_SECT		ME_DATA_MDLREGIST_SECT		// 大区分番号不正
#define EZNC_DATA_MDLREGIST_SUBSECT		ME_DATA_MDLREGIST_SUBSECT	// 小区分番号不正
#define EZNC_DATA_MDLREGIST_AXIS		ME_DATA_MDLREGIST_AXIS		// 軸指定不正
#define EZNC_DATA_MDLREGIST_WRITEONLY	ME_DATA_MDLREGIST_WRITEONLY	// 書き込み専用ﾃﾞｰﾀ
#define EZNC_DATA_MDLREGIST_READONLY	ME_DATA_MDLREGIST_READONLY	// 読み出し専用ﾃﾞｰﾀ
#define EZNC_DATA_MDLREGIST_DATATYPE	ME_DATA_MDLREGIST_DATATYPE	// ﾃﾞｰﾀﾀｲﾌﾟ不正
#define EZNC_DATA_MDLREGIST_READ		ME_DATA_MDLREGIST_READ		// ﾃﾞｰﾀが読み出せない状態にある

#define EZNC_DATA_RETHREADWRITE_NODATA	ME_DATA_RETHREADWRITE_NODATA	// 再ねじ切り位置設定なし

#define	EZNC_DATA_TLFGROUP_ADDR			ME_DATA_TLFGROUP_ADDR		// アドレス不正
#define	EZNC_DATA_TLFGROUP_EXIST		ME_DATA_TLFGROUP_EXIST		// グループ番号が既に存在する
#define	EZNC_DATA_TLFGROUP_NONEXIST		ME_DATA_TLFGROUP_NONEXIST	// グループ番号が存在しない
#define	EZNC_DATA_TLFGROUP_OVER			ME_DATA_TLFGROUP_OVER		// 登録グループ数オーバ
#define	EZNC_DATA_TLFGROUP_NONFORMAT	ME_DATA_TLFGROUP_NONFORMAT	// フォーマット未完
#define	EZNC_DATA_TLFGROUP_UNMACH		ME_DATA_TLFGROUP_UNMACH		// 設定グループ番号不一致
#define	EZNC_DATA_TLFGROUP_OUTOFSPEC	ME_DATA_TLFGROUP_OUTOFSPEC	// 指定グループ番号が仕様外

#define	EZNC_DATA_TLFTOOL_ADDR			ME_DATA_TLFTOOL_ADDR		// アドレス不正
#define	EZNC_DATA_TLFTOOL_EXIST			ME_DATA_TLFTOOL_EXIST		// 工具番号が既に存在する
#define	EZNC_DATA_TLFTOOL_NONEXIST		ME_DATA_TLFTOOL_NONEXIST	// 工具番号が存在しない
#define	EZNC_DATA_TLFTOOL_OVER			ME_DATA_TLFTOOL_OVER		// 登録工具数オーバ
#define	EZNC_DATA_TLFTOOL_PARAMERR		ME_DATA_TLFTOOL_PARAMERR	// 寿命管理データの種類指定不正
#define	EZNC_DATA_TLFTOOL_MAXMINERR		ME_DATA_TLFTOOL_MAXMINERR	// 設定データ範囲オーバ
#define	EZNC_DATA_TLFTOOL_UNMACH		ME_DATA_TLFTOOL_UNMACH		// 設定工具番号不一致
#define	EZNC_DATA_TLFTOOL_OUTOFSPEC		ME_DATA_TLFTOOL_OUTOFSPEC	// 指定工具番号が仕様外

#define EZNC_FILE_DIR_ALREADYOPENED		ME_FILE_DIR_ALREADYOPENED	//すでに別ﾃﾞｨﾚｸﾄﾘがｵｰﾌﾟﾝされている
#define EZNC_FILE_DIR_DATASIZE			ME_FILE_DIR_DATASIZE		// ﾃﾞｰﾀｻｲｽﾞｵｰﾊﾞ
#define EZNC_FILE_DIR_NOTOPEN			ME_FILE_DIR_NOTOPEN			// ｵｰﾌﾟﾝされていない
#define EZNC_FILE_DIR_READ				ME_FILE_DIR_READ			// ﾌｧｲﾙ情報ﾘｰﾄﾞｴﾗｰ
#define EZNC_FILE_DIR_FILESYSTEM		ME_FILE_DIR_FILESYSTEM		// ﾌｧｲﾙｼｽﾃﾑに異常がある
#define EZNC_FILE_DIR_NODIR				ME_FILE_DIR_NODIR			// ﾃﾞｨﾚｸﾄﾘが存在しない
#define EZNC_FILE_DIR_NODRIVE			ME_FILE_DIR_NODRIVE			// ﾄﾞﾗｲﾌﾞが存在しない
#define EZNC_FILE_DIR_NAMELENGTH		ME_FILE_DIR_NAMELENGTH		// ファイル名が長い
#define EZNC_FILE_DIR_ILLEGALNAME		ME_FILE_DIR_ILLEGALNAME		// ファイル名フォーマットが不正
#define EZNC_PCFILE_DIR_NODIR			ME_PCFILE_DIR_NODIR			// ﾃﾞｨﾚｸﾄﾘが存在しない
#define	EZNC_PCFILE_DIR_NOFILE			ME_PCFILE_DIR_NOFILE		// ファイルが存在しない
#define EZNC_PCFILE_DIR_NODRIVE			ME_PCFILE_DIR_NODRIVE		// ﾄﾞﾗｲﾌﾞが存在しない
#define EZNC_PCFILE_DIR_NOTOPEN			ME_PCFILE_DIR_NOTOPEN		// ﾃﾞｨﾚｸﾄﾘがｵｰﾌﾟﾝされていない
#define EZNC_PCFILE_DIR_READ			ME_PCFILE_DIR_READ			// ﾌｧｲﾙ情報ﾘｰﾄﾞｴﾗｰ
#define EZNC_PCFILE_DIR_ALREADYOPENED	ME_PCFILE_DIR_ALREADYOPENED	// すでに別ﾃﾞｨﾚｸﾄﾘがｵｰﾌﾟﾝされている(PCのみ)

#define EZNC_FILE_COPY_BUSY				ME_FILE_COPY_BUSY			// ｺﾋﾟｰできない状態にある(運転中)
#define EZNC_FILE_COPY_ENTRYOVER		ME_FILE_COPY_ENTRYOVER		// 登録本数ｵｰﾊﾞ
#define EZNC_FILE_COPY_FILEEXIST		ME_FILE_COPY_FILEEXIST		// ｺﾋﾟｰ先ﾌｧｲﾙが既に存在する
#define EZNC_FILE_COPY_FILESYSTEM		ME_FILE_COPY_FILESYSTEM		// ﾌｧｲﾙｼｽﾃﾑに異常がある
#define EZNC_FILE_COPY_ILLEGALNAME		ME_FILE_COPY_ILLEGALNAME	// ﾌｧｲﾙ名ﾌｫｰﾏｯﾄが不正
#define EZNC_FILE_COPY_MEMORYOVER		ME_FILE_COPY_MEMORYOVER		// ﾒﾓﾘ容量ｵｰﾊﾞ
#define	EZNC_FILE_COPY_NAMELENGTH		ME_FILE_COPY_NAMELENGTH		// ファイル名が長い
#define EZNC_FILE_COPY_PROTECT			ME_FILE_COPY_PROTECT		// コピーできない状態にある(プロテクト中)
#define EZNC_FILE_COPY_NODIR			ME_FILE_COPY_NODIR			// ﾃﾞｨﾚｸﾄﾘが存在しない
#define EZNC_FILE_COPY_NODRIVE			ME_FILE_COPY_NODRIVE		// ﾄﾞﾗｲﾌﾞが存在しない
#define EZNC_FILE_COPY_NOFILE			ME_FILE_COPY_NOFILE			// ﾌｧｲﾙが存在しない
#define EZNC_FILE_COPY_PLCRUN			ME_FILE_COPY_PLCRUN			// ｺﾋﾟｰできない状態にある(PLC動作中)
#define EZNC_FILE_COPY_READ				ME_FILE_COPY_READ			// 転送元ﾌｧｲﾙが読めない
#define EZNC_FILE_COPY_WRITE			ME_FILE_COPY_WRITE			// 転送先ﾌｧｲﾙに書き込めない
#define EZNC_FILE_COPY_WRITE_WARNING	ME_FILE_COPY_WRITE_WARNING	// ｺﾋﾟｰ先ﾌｧｲﾙに書き込めない
#define EZNC_FILE_COPY_DIFFER			ME_FILE_COPY_DIFFER			// 照合ｴﾗｰ
#define EZNC_FILE_COPY_NOTSUPPORTED		ME_FILE_COPY_NOTSUPPORTED	// 照合機能をｻﾎﾟｰﾄしていない
#define EZNC_FILE_COPY_NOTOPEN			ME_FILE_COPY_NOTOPEN		// ﾌｧｲﾙがｵｰﾌﾟﾝされていない
#define EZNC_FILE_COPY_EXECUTING		ME_FILE_COPY_EXECUTING		// ﾌｧｲﾙｺﾋﾟｰ中
#define EZNC_FILE_COPY_SAFETYPWLOCK		ME_FILE_COPY_SAFETYPWLOCK	// 安全パスワードロック中
#define EZNC_FILE_COPY_ILLEGALFORMAT	ME_FILE_COPY_ILLEGALFORMAT	// ファイルフォーマット不正
#define EZNC_FILE_COPY_WRONGPASSWORD	ME_FILE_COPY_WRONGPASSWORD	// パスワードが異なる
#define EZNC_PCFILE_COPY_CREATE			ME_PCFILE_COPY_CREATE		// ﾌｧｲﾙが生成できない(PCのみ)
#define EZNC_PCFILE_COPY_OPEN			ME_PCFILE_COPY_OPEN			// ﾌｧｲﾙをｵｰﾌﾟﾝできない(PCのみ)
#define EZNC_PCFILE_COPY_FILEEXIST		ME_PCFILE_COPY_FILEEXIST	// ｺﾋﾟｰ先ﾌｧｲﾙが既に存在する
#define EZNC_PCFILE_COPY_ILLEGALNAME	ME_PCFILE_COPY_ILLEGALNAME	// ﾌｧｲﾙ名ﾌｫｰﾏｯﾄが不正
#define EZNC_PCFILE_COPY_NODIR			ME_PCFILE_COPY_NODIR		// ﾃﾞｨﾚｸﾄﾘが存在しない
#define EZNC_PCFILE_COPY_NODRIVE		ME_PCFILE_COPY_NODRIVE		// ﾄﾞﾗｲﾌﾞが存在しない
#define EZNC_PCFILE_COPY_NOFILE			ME_PCFILE_COPY_NOFILE		// ﾌｧｲﾙが存在しない
#define EZNC_PCFILE_COPY_READ			ME_PCFILE_COPY_READ			// 転送元ﾌｧｲﾙが読めない
#define EZNC_PCFILE_COPY_WRITE			ME_PCFILE_COPY_WRITE		// 転送先ﾌｧｲﾙに書き込めない
#define EZNC_PCFILE_COPY_NOTOPEN		ME_PCFILE_COPY_NOTOPEN		// ﾌｧｲﾙがｵｰﾌﾟﾝされていない
#define EZNC_PCFILE_COPY_MEMORYOVER		ME_PCFILE_COPY_MEMORYOVER	// ﾃﾞｨｽｸ容量ｵｰﾊﾞ

#define EZNC_FILE_DEL_BUSY				ME_FILE_DEL_BUSY			// 削除できない状態にある(運転中)
#define	EZNC_FILE_DEL_NOTDELETE			ME_FILE_DEL_NOTDELETE		// 削除できないファイル
#define EZNC_FILE_DEL_FILESYSTEM		ME_FILE_DEL_FILESYSTEM		// ﾌｧｲﾙｼｽﾃﾑに異常がある
#define EZNC_FILE_DEL_ILLEGALNAME 		ME_FILE_DEL_ILLEGALNAME		// ﾌｧｲﾙ名ﾌｫｰﾏｯﾄが不正
#define EZNC_FILE_DEL_NODIR				ME_FILE_DEL_NODIR			// ﾃﾞｨﾚｸﾄﾘが存在しない
#define EZNC_FILE_DEL_NODRIVE			ME_FILE_DEL_NODRIVE			// ﾄﾞﾗｲﾌﾞが存在しない
#define EZNC_FILE_DEL_NOFILE			ME_FILE_DEL_NOFILE			// ﾌｧｲﾙが存在しない
#define	EZNC_FILE_DEL_NAMELENGTH		ME_FILE_DEL_NAMELENGTH		// ファイル名が長い
#define	EZNC_FILE_DEL_PROTECT			ME_FILE_DEL_PROTECT			// ファイルが削除できない状態にある(プロテクト中)
#define EZNC_PCFILE_DEL_NOTDELETE		ME_PCFILE_DEL_NOTDELETE		// 削除できないﾌｧｲﾙ
#define EZNC_PCFILE_DEL_ILLEGALNAME 	ME_PCFILE_DEL_ILLEGALNAME	// ﾌｧｲﾙ名ﾌｫｰﾏｯﾄが不正
#define EZNC_PCFILE_DEL_NODIR			ME_PCFILE_DEL_NODIR			// ﾃﾞｨﾚｸﾄﾘが存在しない
#define EZNC_PCFILE_DEL_NODRIVE			ME_PCFILE_DEL_NODRIVE		// ﾄﾞﾗｲﾌﾞが存在しない
#define EZNC_PCFILE_DEL_NOFILE			ME_PCFILE_DEL_NOFILE		// ﾌｧｲﾙが存在しない

#define EZNC_FILE_REN_NOTRENAME			ME_FILE_REN_NOTRENAME		// ﾘﾈｰﾑできない
#define EZNC_FILE_REN_BUSY				ME_FILE_REN_BUSY			// ﾘﾈｰﾑできない状態にある(運転中)
#define EZNC_FILE_REN_SAMENAME			ME_FILE_REN_SAMENAME		// 新旧ﾌｧｲﾙ名が同じ
#define EZNC_FILE_REN_FILEEXIST			ME_FILE_REN_FILEEXIST		// 新ﾌｧｲﾙ名が既に存在する
#define EZNC_FILE_REN_FILESYSTEM		ME_FILE_REN_FILESYSTEM		// ﾌｧｲﾙｼｽﾃﾑに異常がある
#define EZNC_FILE_REN_ILLEGALNAME		ME_FILE_REN_ILLEGALNAME		// ﾌｧｲﾙ名ﾌｫｰﾏｯﾄが不正
#define EZNC_FILE_REN_NODIR				ME_FILE_REN_NODIR			// ﾃﾞｨﾚｸﾄﾘが存在しない
#define EZNC_FILE_REN_NODRIVE			ME_FILE_REN_NODRIVE			// ﾄﾞﾗｲﾌﾞが存在しない
#define EZNC_FILE_REN_NOFILE			ME_FILE_REN_NOFILE			// ﾌｧｲﾙが存在しない
#define	EZNC_FILE_REN_NAMELENGTH		ME_FILE_REN_NAMELENGTH		// ファイル名が長い
#define	EZNC_FILE_REN_PROTECT			ME_FILE_REN_PROTECT			// リネームできない状態にある(プロテクト中)
#define EZNC_PCFILE_REN_NOTRENAME		ME_PCFILE_REN_NOTRENAME		// ﾘﾈｰﾑできない
#define EZNC_PCFILE_REN_SAMENAME		ME_PCFILE_REN_SAMENAME		// 新旧ﾌｧｲﾙ名が同じ
#define EZNC_PCFILE_REN_FILEEXIST		ME_PCFILE_REN_FILEEXIST		// 新ﾌｧｲﾙ名が既に存在する
#define EZNC_PCFILE_REN_ILLEGALNAME		ME_PCFILE_REN_ILLEGALNAME	// ﾌｧｲﾙ名ﾌｫｰﾏｯﾄが不正
#define EZNC_PCFILE_REN_NODIR			ME_PCFILE_REN_NODIR			// ﾃﾞｨﾚｸﾄﾘが存在しない
#define EZNC_PCFILE_REN_NODRIVE			ME_PCFILE_REN_NODRIVE		// ﾄﾞﾗｲﾌﾞが存在しない
#define EZNC_PCFILE_REN_NOFILE			ME_PCFILE_REN_NOFILE		// ﾌｧｲﾙが存在しない

#define	EZNC_FILE_DISKFREE_NODIR		ME_FILE_DISKFREE_NODIR		// ﾃﾞｨﾚｸﾄﾘが存在しない
#define EZNC_FILE_DISKFREE_NODRIVE		ME_FILE_DISKFREE_NODRIVE	// ﾄﾞﾗｲﾌﾞが存在しない
#define EZNC_FILE_DISKFREE_FILESYSTEM	ME_FILE_DISKFREE_FILESYSTEM	// ﾌｧｲﾙｼｽﾃﾑに異常がある
#define EZNC_FILE_DISKFREE_NAMELENGTH	ME_FILE_DISKFREE_NAMELENGTH	// ﾌｧｲﾙ名が長い
#define EZNC_FILE_DISKFREE_ILLEGALNAME	ME_FILE_DISKFREE_ILLEGALNAME	// ファイル名フォーマットが不正
#define EZNC_PCFILE_DISKFREE_NODIR		ME_PCFILE_DISKFREE_NODIR	// ﾃﾞｨﾚｸﾄﾘが存在しない(PCのみ)
#define EZNC_PCFILE_DISKFREE_NODRIVE	ME_PCFILE_DISKFREE_NODRIVE	// ﾄﾞﾗｲﾌﾞが存在しない(PCのみ)

#define EZNC_FILE_DRVLIST_DATASIZE		ME_FILE_DRVLIST_DATASIZE	// ｱﾌﾟﾘｹｰｼｮﾝが用意したﾊﾞｯﾌｧに入りきらない
#define EZNC_FILE_DRVLIST_READ			ME_FILE_DRVLIST_READ		// ﾄﾞﾗｲﾌﾞ情報ﾘｰﾄﾞｴﾗｰ

#define	EZNC_ENET_ALREADYOPEN			ME_ENET_ALREADYOPEN			// すでにオープンされている
#define	EZNC_ENET_NOTOPEN				ME_ENET_NOTOPEN				// オープンされていない
#define	EZNC_ENET_CARDNOTEXIST			ME_ENET_CARDNOTEXIST		// カードが存在しない
#define	EZNC_ENET_BADCHANNEL			ME_ENET_BADCHANNEL			// チャンネル番号不正
#define	EZNC_ENET_BADFD					ME_ENET_BADFD				// ファイルディスクプリタ不正
#define	EZNC_ENET_NOTCONNECT			ME_ENET_NOTCONNECT			// コネクトされていない
#define	EZNC_ENET_NOTCLOSE				ME_ENET_NOTCLOSE			// クローズされていない
#define	EZNC_ENET_TIMEOUT				ME_ENET_TIMEOUT				// タイムアウト
#define	EZNC_ENET_DATAERR				ME_ENET_DATAERR				// データ不正
#define	EZNC_ENET_CANCELED				ME_ENET_CANCELED			// キャンセル要求により終了した
#define	EZNC_ENET_ILLEGALSIZE			ME_ENET_ILLEGALSIZE			//  パケットサイズ不正
#define	EZNC_ENET_TASKQUIT				ME_ENET_TASKQUIT			// タスク終了により終了した
#define	EZNC_ENET_UNKNOWNFUNC			ME_ENET_UNKNOWNFUNC			// コマンド不正
#define	EZNC_ENET_SETDATAERR			ME_ENET_SETDATAERR			// 設定データ不正

#define	EZNC_READ_CACHE_ADDR			ME_READ_CACHE_ADDR			// アドレス不正
#define	EZNC_READ_CACHE_DATA			ME_READ_CACHE_DATA			// データ範囲不正
#define	EZNC_READ_CACHE_SECT			ME_READ_CACHE_SECT			// 大区分番号不正
#define	EZNC_READ_CACHE_SUBSECT			ME_READ_CACHE_SUBSECT		// 小区分番号不正
#define	EZNC_READ_CACHE_AXIS			ME_READ_CACHE_AXIS			// 軸指定不正
#define	EZNC_READ_CACHE_WRITEONLY		ME_READ_CACHE_WRITEONLY		// ﾃﾞｰﾀﾀｲﾌﾟ不正
#define	EZNC_READ_CACHE_READ			ME_READ_CACHE_READ			// ﾃﾞｰﾀが読み出せない状態にある
#define	EZNC_READ_CACHE_DATATYPE		ME_READ_CACHE_DATATYPE		// ﾃﾞｰﾀﾀｲﾌﾟ不正
#define	EZNC_READ_CACHE_REGIST			ME_READ_CACHE_REGIST		// ﾃﾞｰﾀﾘｰﾄﾞｷｬｯｼｭが無効

#define	EZNC_FS_OPEN_FILE_FILEFULL		ME_FS_OPEN_FILE_FILEFULL	// 最大ﾌｧｲﾙｵｰﾌﾟﾝ数を越えた
#define	EZNC_FS_OPEN_FILE_ALREADYOPEN	ME_FS_OPEN_FILE_ALREADYOPEN	// すでにｵｰﾌﾟﾝされている
#define	EZNC_FS_OPEN_FILE_BUSY			ME_FS_OPEN_FILE_BUSY		// ﾌｧｲﾙがｵｰﾌﾟﾝできない状態にある(運転中)
#define	EZNC_FS_OPEN_FILE_OPEN			ME_FS_OPEN_FILE_OPEN		// ﾌｧｲﾙをｵｰﾌﾟﾝできない
#define	EZNC_FS_OPEN_FILE_MALLOC		ME_FS_OPEN_FILE_MALLOC		// 作業領域を確保できない
#define	EZNC_FS_OPEN_FILE_NOTSUPPORTED	ME_FS_OPEN_FILE_NOTSUPPORTED	// 未ｻﾎﾟｰﾄ(CF未対応)
#define	EZNC_FS_OPEN_FILE_NODRIVE		ME_FS_OPEN_FILE_NODRIVE		// ﾄﾞﾗｲﾌﾞが存在しない
#define	EZNC_FS_OPEN_FILE_NAMELENGTH	ME_FS_OPEN_FILE_NAMELENGTH	// ﾌｧｲﾙﾊﾟｽが長い

#define	EZNC_FS_OPEN_FILE_SORT			ME_FS_OPEN_FILE_SORT		// 工具データソート中でオープンができない
#define	EZNC_FS_OPEN_FILE_SAFE_NOPASSWD	ME_FS_OPEN_FILE_SAFE_NOPASSWD	// 安全パスワードが未認証

#define	EZNC_FS_CLOSE_FILE_NOTOPEN		ME_FS_CLOSE_FILE_NOTOPEN	// ﾌｧｲﾙがｵｰﾌﾟﾝされていない

#define	EZNC_FS_CREATE_FILE_FILEFULL	ME_FS_CREATE_FILE_FILEFULL	// 最大ﾌｧｲﾙｵｰﾌﾟﾝ数を越えた
#define	EZNC_FS_CREATE_FILE_ALREADYOPEN	ME_FS_CREATE_FILE_ALREADYOPEN	// すでに生成されている
#define	EZNC_FS_CREATE_FILE_BUSY		ME_FS_CREATE_FILE_BUSY		// ﾌｧｲﾙが生成できない状態にある(運転中)
#define	EZNC_FS_CREATE_FILE_CREATE		ME_FS_CREATE_FILE_CREATE	// ﾌｧｲﾙを生成できない
#define	EZNC_FS_CREATE_FILE_MALLOC		ME_FS_CREATE_FILE_MALLOC	// 作業領域を確保できない
#define	EZNC_FS_CREATE_FILE_NOTSUPPORTED	ME_FS_CREATE_FILE_NOTSUPPORTED	// 未ｻﾎﾟｰﾄ(CF未対応)
#define	EZNC_FS_CREATE_FILE_NODRIVE		ME_FS_CREATE_FILE_NODRIVE	// ﾄﾞﾗｲﾌﾞが存在しない
#define	EZNC_FS_CREATE_FILE_NAMELENGTH	ME_FS_CREATE_FILE_NAMELENGTH	// ﾌｧｲﾙﾊﾟｽが長い
        
#define	EZNC_FS_READ_FILE_NOTOPEN		ME_FS_READ_FILE_NOTOPEN		// ﾌｧｲﾙがｵｰﾌﾟﾝされていない
#define	EZNC_FS_READ_FILE_READ			ME_FS_READ_FILE_READ		// ﾌｧｲﾙ情報ﾘｰﾄﾞｴﾗｰ
        
#define	EZNC_FS_WRITE_FILE_NOTOPEN		ME_FS_WRITE_FILE_NOTOPEN	// ﾌｧｲﾙがｵｰﾌﾟﾝされていない
#define	EZNC_FS_WRITE_FILE_WRITE		ME_FS_WRITE_FILE_WRITE		// ﾌｧｲﾙ書き込みｴﾗｰ
#define	EZNC_FS_WRITE_FILE_NOTSUPPORTED	ME_FS_WRITE_FILE_NOTSUPPORTED	// 書き込み不可
        
#define	EZNC_FS_REMOVE_FILE_ALREADYOPEN	ME_FS_REMOVE_FILE_ALREADYOPEN	// ﾌｧｲﾙがｵｰﾌﾟﾝされている
#define	EZNC_FS_REMOVE_FILE_BUSY		ME_FS_REMOVE_FILE_BUSY		// ﾌｧｲﾙが削除できない状態にある(運転中)
#define	EZNC_FS_REMOVE_FILE_NOFILE		ME_FS_REMOVE_FILE_NOFILE	// ﾌｧｲﾙが存在しない
#define	EZNC_FS_REMOVE_FILE_REMOVEERR	ME_FS_REMOVE_FILE_REMOVEERR	// ﾌｧｲﾙ削除ｴﾗｰ
#define	EZNC_FS_REMOVE_FILE_NOTSUPPORTED	ME_FS_REMOVE_FILE_NOTSUPPORTED	// 未ｻﾎﾟｰﾄ(CF未対応)
#define	EZNC_FS_REMOVE_FILE_NODRIVE		ME_FS_REMOVE_FILE_NODRIVE	// ﾄﾞﾗｲﾌﾞが存在しない
#define	EZNC_FS_REMOVE_FILE_NAMELENGTH	ME_FS_REMOVE_FILE_NAMELENGTH	// ﾌｧｲﾙﾊﾟｽが長い
        
#define	EZNC_FS_RENAME_FILE_NOFILE		ME_FS_RENAME_FILE_NOFILE	// ﾌｧｲﾙが存在しない
#define	EZNC_FS_RENAME_FILE_ALREADYOPEN	ME_FS_RENAME_FILE_ALREADYOPEN	// ﾌｧｲﾙがｵｰﾌﾟﾝされている
#define	EZNC_FS_RENAME_FILE_FILEFULL	ME_FS_RENAME_FILE_FILEFULL	// 最大ﾌｧｲﾙｵｰﾌﾟﾝ数を越えた
#define	EZNC_FS_RENAME_FILE_NOTRENAME	ME_FS_RENAME_FILE_NOTRENAME	// ﾘﾈｰﾑできないファイル
#define	EZNC_FS_RENAME_FILE_NOTSUPPORTED	ME_FS_RENAME_FILE_NOTSUPPORTED	// 未ｻﾎﾟｰﾄ(CF未対応)
#define	EZNC_FS_RENAME_FILE_NODRIVE		ME_FS_RENAME_FILE_NODRIVE	// ﾄﾞﾗｲﾌﾞが存在しない
#define	EZNC_FS_RENAME_FILE_NAMELENGTH	ME_FS_RENAME_FILE_NAMELENGTH	// ﾌｧｲﾙﾊﾟｽが長い
        
#define	EZNC_FS_IOCTL_FILE_NOTOPEN		ME_FS_IOCTL_FILE_NOTOPEN	// ｵｰﾌﾟﾝされていない
#define	EZNC_FS_IOCTL_FILE_READ			ME_FS_IOCTL_FILE_READ		// ﾘｰﾄﾞｴﾗｰ
#define	EZNC_FS_IOCTL_FILE_WRITE		ME_FS_IOCTL_FILE_WRITE		// ﾗｲﾄｴﾗｰ
#define	EZNC_FS_IOCTL_FILE_FUNCTION		ME_FS_IOCTL_FILE_FUNCTION	// ｺﾏﾝﾄﾞ不正(未対応)
#define	EZNC_FS_IOCTL_FILE_NOTSUPPORTED	ME_FS_IOCTL_FILE_NOTSUPPORTED	// 未サポート(CF未対応)	
#define	EZNC_FS_IOCTL_FILE_DATATYPE		ME_FS_IOCTL_FILE_DATATYPE	// ﾃﾞｰﾀﾀｲﾌﾟ不正
#define	EZNC_FS_IOCTL_FILE_DATASIZE		ME_FS_IOCTL_FILE_DATASIZE	// ｱﾌﾟﾘｹｰｼｮﾝが用意したﾊﾞｯﾌｧに入りきらない

#define	EZNC_FS_OPEN_DIR_FILEFULL		ME_FS_OPEN_DIR_FILEFULL		// 最大ﾃﾞｨﾚｸﾄﾘｵｰﾌﾟﾝ数を越えた
#define	EZNC_FS_OPEN_DIR_NOTOPEN		ME_FS_OPEN_DIR_NOTOPEN		// すでにｵｰﾌﾟﾝされている
#define	EZNC_FS_OPEN_DIR_BUSY			ME_FS_OPEN_DIR_BUSY			// ﾃﾞｨﾚｸﾄﾘがｵｰﾌﾟﾝできない状態にある(運転中)
#define	EZNC_FS_OPEN_DIR_NODIR			ME_FS_OPEN_DIR_NODIR		// ﾃﾞｨﾚｸﾄﾘが存在しない
#define	EZNC_FS_OPEN_DIR_MALLOC			ME_FS_OPEN_DIR_MALLOC		// 作業領域を確保できない
#define	EZNC_FS_OPEN_DIR_NOTSUPPORTED	ME_FS_OPEN_DIR_NOTSUPPORTED	// 未ｻﾎﾟｰﾄ(CF未対応)
#define	EZNC_FS_OPEN_DIR_NODRIVE		ME_FS_OPEN_DIR_NODRIVE		// ﾄﾞﾗｲﾌﾞが存在しない
#define	EZNC_FS_OPEN_DIR_NAMELENGTH		ME_FS_OPEN_DIR_NAMELENGTH	// ﾌｧｲﾙﾊﾟｽが長い
        
#define	EZNC_FS_READ_DIR_NOTOPEN		ME_FS_READ_DIR_NOTOPEN		// ﾃﾞｨﾚｸﾄﾘがｵｰﾌﾟﾝされていない
#define	EZNC_FS_READ_DIR_NODIR			ME_FS_READ_DIR_NODIR		// ﾃﾞｨﾚｸﾄﾘが存在しない
#define	EZNC_FS_READ_DIR_DATASIZE		ME_FS_READ_DIR_DATASIZE		// ｱﾌﾟﾘｹｰｼｮﾝが用意したﾊﾞｯﾌｧに入りきらない
        
#define	EZNC_FS_CLOSE_DIR_NOTOPEN		ME_FS_CLOSE_DIR_NOTOPEN		// ﾃﾞｨﾚｸﾄﾘがｵｰﾌﾟﾝされていない
        
#define	EZNC_FS_STAT_FILE_FILEFULL		ME_FS_STAT_FILE_FILEFULL	// 最大ﾌｧｲﾙｵｰﾌﾟﾝ数を越えた
#define	EZNC_FS_STAT_FILE_STATERR		ME_FS_STAT_FILE_STATERR		// ﾌｧｲﾙ情報読み込みｴﾗｰ
#define	EZNC_FS_STAT_FILE_NOTSUPPORTED	ME_FS_STAT_FILE_NOTSUPPORTED	// 未ｻﾎﾟｰﾄ(CF未対応)
#define	EZNC_FS_STAT_FILE_NODRIVE		ME_FS_STAT_FILE_NODRIVE		// ﾄﾞﾗｲﾌﾞが存在しない
#define	EZNC_FS_STAT_FILE_NAMELENGTH	ME_FS_STAT_FILE_NAMELENGTH	// ﾌｧｲﾙﾊﾟｽが長い
        
#define	EZNC_FS_FSTAT_FILE_NOTOPEN		ME_FS_FSTAT_FILE_NOTOPEN	// ﾌｧｲﾙがｵｰﾌﾟﾝされていない
#define	EZNC_FS_FSTAT_FILE_STATERR		ME_FS_FSTAT_FILE_STATERR	// ﾌｧｲﾙ情報読み込みｴﾗｰ
#define	EZNC_FS_FSTAT_FILE_NOTSUPPORTED	ME_FS_FSTAT_FILE_NOTSUPPORTED	// 未ｻﾎﾟｰﾄ(CF未対応)
#define	EZNC_FS_FSTAT_FILE_NODRIVE		ME_FS_FSTAT_FILE_NODRIVE	// ﾄﾞﾗｲﾌﾞが存在しない
#define	EZNC_FS_FSTAT_FILE_NAMELENGTH	ME_FS_FSTAT_FILE_NAMELENGTH	// ﾌｧｲﾙﾊﾟｽが長い

#define	EZNC_FS_IOCTL_UOPEN_FORMAT		ME_FS_IOCTL_UOPEN_FORMAT	// SRAM開放パラ不正でフォーマット中止

#endif //__EZSOCKETNCERR_H_
