/*
 * $QNXLicenseC:
 * Copyright 2007, QNX Software Systems. All Rights Reserved.
 * 
 * You must obtain a written license from and pay applicable license fees to QNX 
 * Software Systems before you may reproduce, modify or distribute this software, 
 * or any work that includes all or part of this software.   Free development 
 * licenses are available for evaluation and non-commercial purposes.  For more 
 * information visit http://licensing.qnx.com or email licensing@qnx.com.
 *  
 * This file may contain contributions from others.  Please review this entire 
 * file for other proprietary rights or license notices, as well as the QNX 
 * Development Suite License Guide at http://licensing.qnx.com/license-guide/ 
 * for other information.
 * $
 */



/*
 *  ppc/403cpu.h
 *
 * Registers specific to the 403 chip
 *

 */

#ifndef __PPC_403CPU_H_INCLUDED
#define __PPC_403CPU_H_INCLUDED

#ifndef __PLATFORM_H_INCLUDED
#include <sys/platform.h>
#endif

#ifndef __PPC_400CPU_H_INCLUDED
#include _NTO_HDR_(ppc/400cpu.h)
#endif

/*
 * Bus Error Syndrome Register Bits
 */
#define PPC403_BESR_DSES			_ONEBIT32B( 0 )
#define PPC403_BESR_DMES			_ONEBIT32B( 1 )
#define PPC403_BESR_RWS				_ONEBIT32B( 2 )
#define PPC403_BESR_ET_MASK			_BITFIELD32B( 4, 3 )
#define PPC403_BESR_ET_PROTVIOLATE	_BITFIELD32B( 4, 0 )
#define PPC403_BESR_ET_NONCONFIG	_BITFIELD32B( 4, 1 )
#define PPC403_BESR_ET_BUSERR		_BITFIELD32B( 4, 2 )
#define PPC403_BESR_ET_BUSTIMEOUT	_BITFIELD32B( 4, 3 )

/*
 * BR0-BR7 (SRAM configuration)
 */
#define PPC403_BRx_BAS_MASK		_BITFIELD32B( 7, 0xff )
#define PPC403_BRx_BS_MASK		_BITFIELD32B( 10, 0x7 )
#define PPC403_BRx_BS_1MB		_BITFIELD32B( 10, 0 )
#define PPC403_BRx_BS_2MB		_BITFIELD32B( 10, 1 )
#define PPC403_BRx_BS_4MB		_BITFIELD32B( 10, 2 )
#define PPC403_BRx_BS_8MB		_BITFIELD32B( 10, 3 )
#define PPC403_BRx_BS_16MB		_BITFIELD32B( 10, 4 )
#define PPC403_BRx_BS_32MB		_BITFIELD32B( 10, 5 )
#define PPC403_BRx_BS_64MB		_BITFIELD32B( 10, 6 )
#define PPC403_BRx_BU_MASK		_BITFIELD32B( 12, 2 )
#define PPC403_BRx_BU_DISABLED	_BITFIELD32B( 12, 0 )
#define PPC403_BRx_BU_RO		_BITFIELD32B( 12, 1 )
#define PPC403_BRx_BU_WO		_BITFIELD32B( 12, 2 )
#define PPC403_BRx_BU_RW		_BITFIELD32B( 12, 3 )
#define PPC403_BRx_SLF			_ONEBIT32B( 13 )
#define PPC403_BRx_BME			_ONEBIT32B( 14 )
#define PPC403_BRx_BW_MASK		_BITFIELD32B( 16, 3 )
#define PPC403_BRx_BW_8			_BITFIELD32B( 16, 0 )
#define PPC403_BRx_BW_16		_BITFIELD32B( 16, 1 )
#define PPC403_BRx_BW_32		_BITFIELD32B( 16, 2 )
#define PPC403_BRx_RE			_ONEBIT32B( 17 )
#define PPC403_BRx_TWT_MASK		_BITFIELD32B( 23, 0x3f )
#define PPC403_BRx_TWT_SHIFT	(31-23)
#define PPC403_BRx_FWT_MASK		_BITFIELD32B( 21, 0xf )
#define PPC403_BRx_FWT_SHIFT	(31-21)
#define PPC403_BRx_BWT_MASK		_BITFIELD32B( 23, 0x3 )
#define PPC403_BRx_BWT_SHIFT	(31-23)
#define PPC403_BRx_CSN			_ONEBIT32B( 24 )
#define PPC403_BRx_OEN			_ONEBIT32B( 25 )
#define PPC403_BRx_WBN			_ONEBIT32B( 26 )
#define PPC403_BRx_WBF			_ONEBIT32B( 27 )
#define PPC403_BRx_TH_MASK		_BITFIELD32B( 30, 0x3 )
#define PPC403_BRx_TH_SHIFT		(31-30)
#define PPC403_BRx_SD			_ONEBIT32B( 31 ) /* on for SRAM, off for DRAM */

/*
 * BR0-BR7 (DRAM configuration) Bits 0 -> 13, 15 -> 16 same as SRAM config
 */
#define PPC403_BRx_ERM			_ONEBIT32B( 14 )
#define PPC403_BRx_IEM			_ONEBIT32B( 17 )
#define PPC403_BRx_RCT			_ONEBIT32B( 18 )
#define PPC403_BRx_ARM			_ONEBIT32B( 19 )
#define PPC403_BRx_PM			_ONEBIT32B( 20 )
#define PPC403_BRx_FAC_MASK		_BITFIELD32B( 22, 0x3 )
#define PPC403_BRx_FAC_0CLKS	_BITFIELD32B( 22, 0 )
#define PPC403_BRx_FAC_1CLKS	_BITFIELD32B( 22, 1 )
#define PPC403_BRx_FAC_2CLKS	_BITFIELD32B( 22, 2 )
#define PPC403_BRx_FAC_3CLKS	_BITFIELD32B( 22, 3 )
#define PPC403_BRx_BAC_MASK		_BITFIELD32B( 24, 0x3 )
#define PPC403_BRx_BAC_0CLKS	_BITFIELD32B( 24, 0 )
#define PPC403_BRx_BAC_1CLKS	_BITFIELD32B( 24, 1 )
#define PPC403_BRx_BAC_2CLKS	_BITFIELD32B( 24, 2 )
#define PPC403_BRx_BAC_3CLKS	_BITFIELD32B( 24, 3 )
#define PPC403_BRx_PCC			_ONEBIT32B( 25 )
#define PPC403_BRx_RAR			_ONEBIT32B( 26 )
#define PPC403_BRx_RR_MASK		_BITFIELD32B( 30, 0xf )
#define PPC403_BRx_RR_SHIFT		(31-30)

/*
 * Cache Debug Control Register 
 */
#define PPC403_CDBCR_CIS_MASK	_ONEBIT32B( 27 )
#define PPC403_CDBCR_CIS_DATA	_BITFIELD32B( 27, 0 )
#define PPC403_CDBCR_CIS_TAG	_ONEBIT32B( 27 )
#define	PPC403_CDBCR_CSS_MASK	_ONEBIT32B( 31 )
#define PPC403_CDBCR_CSS_A		_BITFIELD32B( 31, 0 )
#define PPC403_CDBCR_CSS_B		_ONEBIT32B( 31 )

/*
 * DMA Channel Control Registers (DMACR0-DMACR3)
 */
#define PPC403_DMACRx_CE			_ONEBIT32B( 0 )
#define PPC403_DMACRx_CIE			_ONEBIT32B( 1 )
#define PPC403_DMACRx_TD			_ONEBIT32B( 2 )
#define PPC403_DMACRx_PL			_ONEBIT32B( 3 )
#define PPC403_DMACRx_PW_MASK		_BITFIELD32B( 5, 0x3 )
#define PPC403_DMACRx_PW_1			_BITFIELD32B( 5, 0 )
#define PPC403_DMACRx_PW_2			_BITFIELD32B( 5, 1 )
#define PPC403_DMACRx_PW_4			_BITFIELD32B( 5, 2 )
#define PPC403_DMACRx_PW_16			_BITFIELD32B( 5, 3 )
#define PPC403_DMACRx_DAI			_ONEBIT32B( 6 )
#define PPC403_DMACRx_SAI			_ONEBIT32B( 7 )
#define PPC403_DMACRx_CP			_ONEBITB( 8 )
#define PPC403_DMACRx_TM_MASK		_BITFIELD32B( 10, 0x3 )
#define PPC403_DMACRx_TM_BUFFERED	_BITFIELD32B( 10, 0 )
#define PPC403_DMACRx_TM_FLYBY		_BITFIELD32B( 10, 1 )
#define PPC403_DMACRx_TM_SOFTINIT	_BITFIELD32B( 10, 2 )
#define PPC403_DMACRx_TM_HARDINIT	_BITFIELD32B( 10, 3 )
#define PPC403_DMACRx_PSC_MASK		_BITFIELD32B( 12, 0x3 )
#define PPC403_DMACRx_PSC_0CLKS		_BITFIELD32B( 12, 0 )
#define PPC403_DMACRx_PSC_1CLKS		_BITFIELD32B( 12, 1 )
#define PPC403_DMACRx_PSC_2CLKS		_BITFIELD32B( 12, 2 )
#define PPC403_DMACRx_PSC_3CLKS		_BITFIELD32B( 12, 3 )
#define PPC403_DMACRx_PWC_MASK		_BITFIELD32B( 18, 0x3f )
#define PPC403_DMACRx_PWC_SHIFT		(31-18)
#define PPC403_DMACRx_PHC_MASK		_BITFIELD32B( 21, 0x7 )
#define PPC403_DMACRx_PHC_SHIFT		(31-21)
#define PPC403_DMACRx_ETD			_ONEBIT32B( 22 )
#define PPC403_DMACRx_TCE			_ONEBIT32B( 23 )
#define	PPC403_DMACRx_CH			_ONEBIT32B( 24 )
#define PPC403_DMACRx_BME			_ONEBIT32B( 25 )
#define PPC403_DMACRx_ECE			_ONEBIT32B( 26 )
#define PPC403_DMACRx_TCB			_ONEBIT32B( 27 )

/*
 * DMA Status Register
 */
#define PPC403_DMASR_CS0			_ONEBIT32B( 0 )
#define PPC403_DMASR_CS1			_ONEBIT32B( 1 )
#define PPC403_DMASR_CS2			_ONEBIT32B( 2 )
#define PPC403_DMASR_CS3			_ONEBIT32B( 3 )
#define PPC403_DMASR_TS0			_ONEBIT32B( 4 )
#define PPC403_DMASR_TS1			_ONEBIT32B( 5 )
#define PPC403_DMASR_TS2			_ONEBIT32B( 6 )
#define PPC403_DMASR_TS3			_ONEBIT32B( 7 )
#define PPC403_DMASR_RI0			_ONEBIT32B( 8 )
#define PPC403_DMASR_RI1			_ONEBIT32B( 9 )
#define PPC403_DMASR_RI2			_ONEBIT32B( 10 )
#define PPC403_DMASR_RI3			_ONEBIT32B( 11 )
#define PPC403_DMASR_CT0			_ONEBIT32B( 12 )
#define PPC403_DMASR_IR0			_ONEBIT32B( 13 )
#define PPC403_DMASR_IR1			_ONEBIT32B( 14 )
#define PPC403_DMASR_IR2			_ONEBIT32B( 15 )
#define PPC403_DMASR_IR3			_ONEBIT32B( 16 )
#define PPC403_DMASR_ER0			_ONEBIT32B( 17 )
#define PPC403_DMASR_ER1			_ONEBIT32B( 18 )
#define PPC403_DMASR_ER2			_ONEBIT32B( 19 )
#define PPC403_DMASR_ER3			_ONEBIT32B( 20 )
#define PPC403_DMASR_CB0			_ONEBIT32B( 21 )
#define PPC403_DMASR_CB1			_ONEBIT32B( 22 )
#define PPC403_DMASR_CB2			_ONEBIT32B( 23 )
#define PPC403_DMASR_CB3			_ONEBIT32B( 24 )
#define PPC403_DMASR_CT1			_ONEBIT32B( 25 )
#define PPC403_DMASR_CT2			_ONEBIT32B( 26 )
#define PPC403_DMASR_CT3			_ONEBIT32B( 27 )

/*
 * External Interrupt Enable Register
 */
#define PPC403_EXIER_CIE	_ONEBIT32B( 0 )
#define PPC403_EXIER_SRIE	_ONEBIT32B( 4 )
#define PPC403_EXIER_STIE	_ONEBIT32B( 5 )
#define PPC403_EXIER_JRIE	_ONEBIT32B( 6 )
#define PPC403_EXIER_JTIE	_ONEBIT32B( 7 )
#define PPC403_EXIER_D0IE	_ONEBIT32B( 8 )
#define PPC403_EXIER_D1IE	_ONEBIT32B( 9 )
#define PPC403_EXIER_D2IE	_ONEBIT32B( 10 )
#define PPC403_EXIER_D3IE	_ONEBIT32B( 11 )
#define PPC403_EXIER_E0IE	_ONEBIT32B( 27 )
#define PPC403_EXIER_E1IE	_ONEBIT32B( 28 )
#define PPC403_EXIER_E2IE	_ONEBIT32B( 29 )
#define PPC403_EXIER_E3IE	_ONEBIT32B( 30 )
#define PPC403_EXIER_E4IE	_ONEBIT32B( 31 )

/*
 * External Interrupt Status Register
 */
#define PPC403_EXISR_CIS	_ONEBIT32B( 0 )
#define PPC403_EXISR_SRIS	_ONEBIT32B( 4 )
#define PPC403_EXISR_STIS	_ONEBIT32B( 5 )
#define PPC403_EXISR_JRIS	_ONEBIT32B( 6 )
#define PPC403_EXISR_JTIS	_ONEBIT32B( 7 )
#define PPC403_EXISR_D0IS	_ONEBIT32B( 8 )
#define PPC403_EXISR_D1IS	_ONEBIT32B( 9 )
#define PPC403_EXISR_D2IS	_ONEBIT32B( 10 )
#define PPC403_EXISR_D3IS	_ONEBIT32B( 11 )
#define PPC403_EXISR_E0IS	_ONEBIT32B( 27 )
#define PPC403_EXISR_E1IS	_ONEBIT32B( 28 )
#define PPC403_EXISR_E2IS	_ONEBIT32B( 29 )
#define PPC403_EXISR_E3IS	_ONEBIT32B( 30 )
#define PPC403_EXISR_E4IS	_ONEBIT32B( 31 )

/*
 * Input/Output Configuration Register
 */
#define PPC403_IOCR_E0T					_ONEBIT32B( 0 )
#define PPC403_IOCR_E0L					_ONEBIT32B( 1 )
#define PPC403_IOCR_E1T					_ONEBIT32B( 2 )
#define PPC403_IOCR_E1L					_ONEBIT32B( 3 )
#define PPC403_IOCR_E2T					_ONEBIT32B( 4 )
#define PPC403_IOCR_E2L					_ONEBIT32B( 5 )
#define PPC403_IOCR_E3T					_ONEBIT32B( 6 )
#define PPC403_IOCR_E3L					_ONEBIT32B( 7 )
#define PPC403_IOCR_E4T					_ONEBIT32B( 8 )
#define PPC403_IOCR_E4L					_ONEBIT32B( 9 )
#define PPC403_IOCR_DRC					_ONEBIT32B( 26 )
#define PPC403_IOCR_RDM_MASK			_BITFIELD32B( 28, 3 )
#define PPC403_IOCR_RDM_TRACE_DISABLED	_BITFIELD32B( 28, 0 )
#define PPC403_IOCR_RDM_PROG_N_BUS		_BITFIELD32B( 28, 1 )
#define PPC403_IOCR_RDM_PROG_N_TRACE	_BITFIELD32B( 28, 2 )
#define PPC403_IOCR_TCS					_ONEBIT32B( 29 )
#define PPC403_IOCR_SCS					_ONEBIT32B( 30 )
#define PPC403_IOCR_SPC					_ONEBIT32B( 31 )


/*
 * SPR numbers
 */
#define PPC403_SPR_CDBCR	0x3d7
#define PPC403_SPR_DAC2		0x3f7
#define PPC403_SPR_IAC2		0x3f5
#define PPC403_SPR_ICDBDR	0x3d3
#define PPC403_SPR_PBL1		0x3fc
#define PPC403_SPR_PBL2		0x3fc
#define PPC403_SPR_PBU1		0x3fd
#define PPC403_SPR_PBU2		0x3ff

/*
 * DCR numbers
 */
#define PPC403_DCR_BEAR		0x90
#define PPC403_DCR_BESR		0x91
#define PPC403_DCR_BR0		0x80
#define PPC403_DCR_BR1		0x81
#define PPC403_DCR_BR2		0x82
#define PPC403_DCR_BR3		0x83
#define PPC403_DCR_BR4		0x84
#define PPC403_DCR_BR5		0x85
#define PPC403_DCR_BR6		0x86
#define PPC403_DCR_BR7		0x87
#define PPC403_DCR_DMACC0	0xc4
#define PPC403_DCR_DMACC1	0xcc
#define PPC403_DCR_DMACC2	0xd4
#define PPC403_DCR_DMACC3	0xdc
#define PPC403_DCR_DMACR0	0xc0
#define PPC403_DCR_DMACR1	0xc8
#define PPC403_DCR_DMACR2	0xd0
#define PPC403_DCR_DMACR3	0xd8
#define PPC403_DCR_DMACT0	0xc1
#define PPC403_DCR_DMACT1	0xc9
#define PPC403_DCR_DMACT2	0xd1
#define PPC403_DCR_DMACT3	0xd9
#define PPC403_DCR_DMADA0	0xc2
#define PPC403_DCR_DMADA1	0xca
#define PPC403_DCR_DMADA2	0xd2
#define PPC403_DCR_DMADA3	0xda
#define PPC403_DCR_DMASA0	0xc3
#define PPC403_DCR_DMASA1	0xcb
#define PPC403_DCR_DMASA2	0xd3
#define PPC403_DCR_DMASA3	0xdb
#define PPC403_DCR_DMASR	0xe0
#define PPC403_DCR_EXIER	0x42
#define PPC403_DCR_EXISR	0x40
#define PPC403_DCR_IOCR		0xa0

#endif


__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/SP1/services/system/public/ppc/403cpu.h $ $Rev: 219613 $" )
