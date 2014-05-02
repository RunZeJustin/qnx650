/*
 * $QNXLicenseC:
 * Copyright 2007, 2009, QNX Software Systems. All Rights Reserved.
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
 *  ppc/e500cpu.h
 *
 * Registers specific to the Motorola E500
 *

 */

#ifndef __PPC_E500CPU_H_INCLUDED
#define __PPC_E500CPU_H_INCLUDED

#ifndef __PPC_BOOKECPU_H_INCLUDED
#include <ppc/bookecpu.h>
#endif


/*
 * Extra Bits for the MSR register
 */
#define PPCE500_MSR_UCLE		_ONEBIT32B(37-32)
#define PPCE500_MSR_SPE			_ONEBIT32B(38-32)
#define PPCE500_MSR_UBLE		_ONEBIT32B(53-32)

/*
 * Extra bits for the ESR register
 */
#define PPCE500_ESR_ILK			_ONEBIT32B(43-32)
#define PPCE500_ESR_SPE			_ONEBIT32B(56-32)

/*
 * Machine Check Syndrome Register
 */
#define PPCE500_MCSR_MCP			_ONEBIT32B(32-32)
#define PPCE500_MCSR_ICPERR			_ONEBIT32B(33-32)
#define PPCE500_MCSR_DCP_PERR		_ONEBIT32B(34-32)
#define PPCE500_MCSR_DCPERR			_ONEBIT32B(35-32)
#define PPCE500_MCSR_GL_CI			_ONEBIT32B(47-32)
#define PPCE500_MCSR_ABIST_IC		_ONEBIT32B(48-32)
#define PPCE500_MCSR_ABIST_DC		_ONEBIT32B(49-32)
#define PPCE500_MCSR_ABIST_ITLB		_ONEBIT32B(50-32)
#define PPCE500_MCSR_ABIST_DTLB		_ONEBIT32B(51-32)
#define PPCE500_MCSR_ABIST_L2TLB	_ONEBIT32B(52-32)
#define PPCE500_MCSR_ABIST_TLB1		_ONEBIT32B(53-32)
#define PPCE500_MCSR_ABIST_BTB		_ONEBIT32B(54-32)
#define PPCE500_MCSR_BUS_IAERR		_ONEBIT32B(56-32)
#define PPCE500_MCSR_BUS_RAERR		_ONEBIT32B(57-32)
#define PPCE500_MCSR_BUS_WAERR		_ONEBIT32B(58-32)
#define PPCE500_MCSR_BUS_IBERR		_ONEBIT32B(59-32)
#define PPCE500_MCSR_BUS_RBERR		_ONEBIT32B(60-32)
#define PPCE500_MCSR_BUS_WBERR		_ONEBIT32B(61-32)
#define PPCE500_MCSR_BUS_IPERR		_ONEBIT32B(62-32)
#define PPCE500_MCSR_BUS_RPERR		_ONEBIT32B(63-32)

/*
 * HID0
 */
#define PPCE500_HID0_EMCP			_ONEBIT32B(32-32)
#define PPCE500_HID0_DOZE			_ONEBIT32B(40-32)
#define PPCE500_HID0_NAP			_ONEBIT32B(41-32)
#define PPCE500_HID0_SLEEP			_ONEBIT32B(42-32)
#define PPCE500_HID0_NHR			_ONEBIT32B(47-32)
#define PPCE500_HID0_TBEN			_ONEBIT32B(49-32)
#define PPCE500_HID0_SEL_TBCLK		_ONEBIT32B(50-32)
#define PPCE500_HID0_EN_MAS7_UPDATE	_ONEBIT32B(56-32)
#define PPCE500_HID0_DCFA		_ONEBIT32B(57-32)
#define PPCE500_HID0_NOPTI			_ONEBIT32B(63-32)

/*
 * HID1
 */
#define PPCE500_HID1_PLL_CFG_MASK	_BITFIELD32B(37-32,0x3f)
#define PPCE500_HID1_PLL_CFG_SHIFT	(63-37)
#define PPCE500_HID1_NEXEN			_ONEBIT32B(47-32)
#define PPCE500_HID1_R1DPE			_ONEBIT32B(48-32)
#define PPCE500_HID1_R2DPE			_ONEBIT32B(49-32)
#define PPCE500_HID1_ASTME			_ONEBIT32B(50-32)
#define PPCE500_HID1_ABE			_ONEBIT32B(51-32)
#define PPCE500_HID1_MPXTT			_ONEBIT32B(53-32)
#define PPCE500_HID1_MSHARS			_ONEBIT32B(54-32)
#define PPCE500_HID1_SSHAR			_ONEBIT32B(55-32)
#define PPCE500_HID1_ATS			_ONEBIT32B(56-32)
#define PPCE500_HID1_MID_MASK		_BITFIELD32B(63-32,0xf)
#define PPCE500_HID1_MID_SHIFT		(63-63)

/*
 * Branch Unit Control and Status Register
 */
#define PPCE500_BUCSR_BBFI			_ONEBIT32B(54-32)
#define PPCE500_BUCSR_BBLO			_ONEBIT32B(55-32)
#define PPCE500_BUCSR_BBUL			_ONEBIT32B(56-32)
#define PPCE500_BUCSR_BBLFC			_ONEBIT32B(57-32)
#define PPCE500_BUCSR_BPEN			_ONEBIT32B(63-32)

/*
 * Signal Processing and Embedded Floating Point Status and Control
 */
#define PPCE500_SPEFSCR_SOVH PPCBKE_APU_SPE_SPEFSCR_SOVH
#define PPCE500_SPEFSCR_OVH PPCBKE_APU_SPE_SPEFSCR_OVH
#define PPCE500_SPEFSCR_FGH PPCBKE_APU_SPE_SPEFSCR_FGH
#define PPCE500_SPEFSCR_FXH PPCBKE_APU_SPE_SPEFSCR_FXH
#define PPCE500_SPEFSCR_FINVH PPCBKE_APU_SPE_SPEFSCR_FINVH
#define PPCE500_SPEFSCR_FDBZH PPCBKE_APU_SPE_SPEFSCR_FDBZH
#define PPCE500_SPEFSCR_FUNFH PPCBKE_APU_SPE_SPEFSCR_FUNFH
#define PPCE500_SPEFSCR_FOVFH PPCBKE_APU_SPE_SPEFSCR_FOVFH
#define PPCE500_SPEFSCR_FINXS PPCBKE_APU_SPE_SPEFSCR_FINXS
#define PPCE500_SPEFSCR_FINVS PPCBKE_APU_SPE_SPEFSCR_FINVS
#define PPCE500_SPEFSCR_FFBZS PPCBKE_APU_SPE_SPEFSCR_FFBZS
#define PPCE500_SPEFSCR_FUNFS PPCBKE_APU_SPE_SPEFSCR_FUNFS
#define PPCE500_SPEFSCR_FOVFS PPCBKE_APU_SPE_SPEFSCR_FOVFS
#define PPCE500_SPEFSCR_MODE PPCBKE_APU_SPE_SPEFSCR_MODE
#define PPCE500_SPEFSCR_SOV PPCBKE_APU_SPE_SPEFSCR_SOV
#define PPCE500_SPEFSCR_OV PPCBKE_APU_SPE_SPEFSCR_OV
#define PPCE500_SPEFSCR_FG PPCBKE_APU_SPE_SPEFSCR_FG
#define PPCE500_SPEFSCR_FX PPCBKE_APU_SPE_SPEFSCR_FX
#define PPCE500_SPEFSCR_FINV PPCBKE_APU_SPE_SPEFSCR_FINV
#define PPCE500_SPEFSCR_FDBZ PPCBKE_APU_SPE_SPEFSCR_FDBZ
#define PPCE500_SPEFSCR_FUNF PPCBKE_APU_SPE_SPEFSCR_FUNF
#define PPCE500_SPEFSCR_FOVF PPCBKE_APU_SPE_SPEFSCR_FOVF
#define PPCE500_SPEFSCR_FINXE PPCBKE_APU_SPE_SPEFSCR_FINXE
#define PPCE500_SPEFSCR_FINVE PPCBKE_APU_SPE_SPEFSCR_FINVE
#define PPCE500_SPEFSCR_FDBZE PPCBKE_APU_SPE_SPEFSCR_FDBZE
#define PPCE500_SPEFSCR_FUNFE PPCBKE_APU_SPE_SPEFSCR_FUNFE
#define PPCE500_SPEFSCR_FOVFE PPCBKE_APU_SPE_SPEFSCR_FOVFE
#define PPCE500_SPEFSCR_FRMC_MASK PPCBKE_APU_SPE_SPEFSCR_FRMC_MASK
#define PPCE500_SPEFSCR_FRMC_SHIFT PPCBKE_APU_SPE_SPEFSCR_FRMC_SHIFT
#define PPCE500_SPEFSCR_FRMC_NEAR PPCBKE_APU_SPE_SPEFSCR_FRMC_NEAR
#define PPCE500_SPEFSCR_FRMC_ZERO PPCBKE_APU_SPE_SPEFSCR_FRMC_ZERO
#define PPCE500_SPEFSCR_FRMC_PINF PPCBKE_APU_SPE_SPEFSCR_FRMC_PINF
#define PPCE500_SPEFSCR_FRMC_NINF PPCBKE_APU_SPE_SPEFSCR_FRMC_NINF

/*
 * L1 Cache Control and Status Register 0 (data cache)
 */
#define PPCE500_L1CSR0_CPE			_ONEBIT32B(47-32)
#define PPCE500_L1CSR0_PIE			_ONEBIT32B(48-32)
#define PPCE500_L1CSR0_CSLC			_ONEBIT32B(52-32)
#define PPCE500_L1CSR0_CUL			_ONEBIT32B(53-32)
#define PPCE500_L1CSR0_CLO			_ONEBIT32B(54-32)
#define PPCE500_L1CSR0_CLFC			_ONEBIT32B(55-32)
#define PPCE500_L1CSR0_CFI			_ONEBIT32B(62-32)
#define PPCE500_L1CSR0_CE			_ONEBIT32B(63-32)

/*
 * L1 Cache Control and Status Register 1 (instruction cache)
 */
#define PPCE500_L1CSR1_ICPE			_ONEBIT32B(47-32)
#define PPCE500_L1CSR1_IPIE			_ONEBIT32B(48-32)
#define PPCE500_L1CSR1_ICSLC		_ONEBIT32B(52-32)
#define PPCE500_L1CSR1_ICUL			_ONEBIT32B(53-32)
#define PPCE500_L1CSR1_ICLO			_ONEBIT32B(54-32)
#define PPCE500_L1CSR1_ICLFC		_ONEBIT32B(55-32)
#define PPCE500_L1CSR1_ICFI			_ONEBIT32B(62-32)
#define PPCE500_L1CSR1_ICE			_ONEBIT32B(63-32)

/* Backside L2 Cache Control and Status Register 0 */
#define PPCE500_L2CSR0_L2E			_ONEBIT32B(32-32)
#define PPCE500_L2CSR0_L2PE			_ONEBIT32B(33-32)
#define PPCE500_L2CSR0_L2FI			_ONEBIT32B(42-32)
#define PPCE500_L2CSR0_L2IO			_ONEBIT32B(43-32)
#define PPCE500_L2CSR0_L2DO			_ONEBIT32B(47-32)
#define PPCE500_L2CSR0_L2FL			_ONEBIT32B(52-32)
#define PPCE500_L2CSR0_L2LFC			_ONEBIT32B(53-32)
#define PPCE500_L2CSR0_L2LOA			_ONEBIT32B(56-32)
#define PPCE500_L2CSR0_L2LO			_ONEBIT32B(58-32)

/*
 * Extra bits for the TCR register
 */
#define PPCE500_TCR_WPEXT_MASK                   _BITFIELD32B(46-32,0xf)
#define PPCE500_TCR_WPEXT_SHIFT                  (31-(46-32)
#define PPCE500_TCR_FPEXT_MASK                   _BITFIELD32B(50-32,0xf)
#define PPCE500_TCR_FPEXT_SHIFT                  (31-(50-32))

/*
 * SPR numbers
 */

#define PPCE500_SPR_IVOR32		528		/* SPE unavailable */
#define PPCE500_SPR_IVOR33		529		/* floating point data exception */
#define PPCE500_SPR_IVOR34		530		/* floating point round exception */
#define PPCE500_SPR_IVOR35		531		/* performance monitor */
#define PPCE500_SPR_IVOR36		532		/* processor doorbell */
#define PPCE500_SPR_IVOR37		533		/* processor critical doorbell */
#define PPCE500_SPR_IVOR38		432		/* guest doorbell */
#define PPCE500_SPR_IVOR39		433		/* guest critical doorbell */
#define PPCE500_SPR_IVOR40		434		/* hypervisor syscall */
#define PPCE500_SPR_IVOR41		435		/* hypervisor privilege */
#define PPCE500_SPR_L1CFG0		515
#define PPCE500_SPR_L1CFG1		516
#define PPCE500_SPR_L1CSR0		1010
#define PPCE500_SPR_L1CSR1		1011
#define PPCE500_SPR_L1CSR2		606
#define PPCE500_SPR_L2CAPTDATAHI 988	/* L2 cache error capture data high */
#define PPCE500_SPR_L2CAPTDATALO 989	/* L2 cache error capture data low */
#define PPCE500_SPR_L2CAPTECC	 990	/* L2 cache error capture ECC syndrome */
#define PPCE500_SPR_L2CFG0		519		/* L2 cache configuration register 0 */
#define PPCE500_SPR_L2CSR0		1017	/* L2 cache control and status register 0 */
#define PPCE500_SPR_L2CSR1		1018	/* L2 cache control and status register 1 */
#define PPCE500_SPR_L2ERRADDR	722		/* L2 cache error address */
#define PPCE500_SPR_L2ERRATTR	721		/* L2 cache error attribute */
#define PPCE500_SPR_L2ERRCTL	724		/* L2 cache error control */
#define PPCE500_SPR_L2ERRDET	991		/* L2 cache error detect */
#define PPCE500_SPR_L2ERRDIS	725		/* L2 cache error disable */
#define PPCE500_SPR_L2ERREADDR	723		/* L2 cache error extended address */
#define PPCE500_SPR_L2ERRINJCTL	987		/* L2 cache error injection control */
#define PPCE500_SPR_L2ERRINJHI	985		/* L2 cache error injection mask high */
#define PPCE500_SPR_L2ERRINJLO	986		/* L2 cache error injection mask low */
#define PPCE500_SPR_L2ERRINTEN	720		/* L2 cache error interrupt enable */
#define PPCE500_SPR_NPIDR		517
#define PPCE500_SPR_SPEFSCR		PPCBKE_APU_SPE_SPR_SPEFSCR
#define PPCE500_SPR_MCSRR0		PPCBKE_APU_MACHINE_CHECK_SPR_MCSRR0
#define PPCE500_SPR_MCSRR1		PPCBKE_APU_MACHINE_CHECK_SPR_MCSRR1
#define PPCE500_SPR_MCSR		PPCBKE_APU_MACHINE_CHECK_SPR_MCSR
#define PPCE500_SPR_MCAR		PPCBKE_APU_MACHINE_CHECK_SPR_MCAR
#define PPCE500_SPR_IARR		518
#define PPCE500_SPR_HID0		1008
#define PPCE500_SPR_HID1		1009
#define PPCE500_SPR_BUCSR		1013
#define PPCE500_SPR_PVR			287		/* Processor Version Register*/
#define PPCE500_SPR_SVR			1023

#endif


__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/SP1/services/system/public/ppc/e500cpu.h $ $Rev: 643330 $" )
