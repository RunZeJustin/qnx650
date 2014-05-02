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
 *  ppc/p4080cpu.h
 *
 * Registers specific to the Freescale P4080
 *

 */

#ifndef __PPC_P4080CPU_H_INCLUDED
#define __PPC_P4080CPU_H_INCLUDED

#ifndef __PPC_E500CPU_H_INCLUDED
#include <ppc/e500cpu.h>
#endif

#define PPCP4080_CCSR_OFF_BSTRH 			0x00020
#define PPCP4080_CCSR_OFF_BSTRL				0x00024
#define PPCP4080_CCSR_OFF_BSTAR				0x00028
#define PPCP4080_CCSR_OFF_BRR				0xe00e4


#define PPCP4080_CCSR_OFF_CSn_BNDS(n)		(0x08000 + (n)*8)
#define PPCP4080_CCSR_OFF_CSn_CONFIG(n)		(0x08080 + (n)*4)

/*
 * DDR Chip Select n Memory Bounds
 */
#define PPCP4080_CSn_BNDS_SA_MASK	_BITFIELD32B(15,0xfff)
#define PPCP4080_CSn_BNDS_SA_SHIFT	(31-15)
#define PPCP4080_CSn_BNDS_EA_MASK	_BITFIELD32B(31,0xfff)
#define PPCP4080_CSn_BNDS_EA_SHIFT	0

/*
 * DDR Chip Select n Configuration
 */
#define PPCP4080_CSn_CONFIG_CS_EN			_ONEBIT32B(0)
#define PPCP4080_CSn_CONFIG_CS_INTLV_EN		_ONEBIT32B(2)
#define PPCP4080_CSn_CONFIG_AP_EN			_ONEBIT32B(8)
#define PPCP4080_CSn_CONFIG_ROW_BITS_MASK	_BITFIELD32B(23,0x7)
#define PPCP4080_CSn_CONFIG_ROW_BITS_SHIFT	(31-23)
#define PPCP4080_CSn_CONFIG_ROW_BITS_12		_BITFIELD32B(23,0x0)
#define PPCP4080_CSn_CONFIG_ROW_BITS_13		_BITFIELD32B(23,0x1)
#define PPCP4080_CSn_CONFIG_ROW_BITS_14		_BITFIELD32B(23,0x2)
#define PPCP4080_CSn_CONFIG_COL_BITS_MASK	_BITFIELD32B(31,0x7)
#define PPCP4080_CSn_CONFIG_COL_BITS_SHIFT	(31-31)
#define PPCP4080_CSn_CONFIG_COL_BITS_8		_BITFIELD32B(31,0x0)
#define PPCP4080_CSn_CONFIG_COL_BITS_9		_BITFIELD32B(31,0x1)
#define PPCP4080_CSn_CONFIG_COL_BITS_10		_BITFIELD32B(31,0x2)
#define PPCP4080_CSn_CONFIG_COL_BITS_11		_BITFIELD32B(31,0x3)

/*
 * CoreNet Platform Cache configuration 
 */
#define PPCP4080_CCSR_OFF_CPCSR0		0x10000
#define PPCP4080_CCSR_OFF_CPCSR1		0x11000
#define PPCP4080_CPC_EN				0x80000000
#define PPCP4080_CPC_PE				0x40000000
#define PPCP4080_CPC_FI				0x00200000
#define PPCP4080_CPC_LFC			0x00000400

/*
 * RCW Status Register 1
 */
#define PPCP4080_SYS_PLL_CFG_MASK		_BITFIELD32B(1,0x3)
#define PPCP4080_SYS_PLL_CFG_SHIFT		(31-1)
#define PPCP4080_SYS_PLL_RAT_MASK		_BITFIELD32B(6,0x1f)
#define PPCP4080_SYS_PLL_RAT_SHIFT		(31-6)
#define PPCP4080_MEM_PLL_CFG_MASK		_BITFIELD32B(9,0x3)
#define PPCP4080_MEM_PLL_CFG_SHIFT		(31-9)
#define PPCP4080_MEM_PLL_RAT_MASK		_BITFIELD32B(14,0x1f)
#define PPCP4080_MEM_PLL_RAT_SHIFT		(31-14)

/*
 * RCW Status Register 2
 */
#define PPCP4080_CC1_PLL_CFG_MASK		_BITFIELD32B(1,0x3)
#define PPCP4080_CC1_PLL_CFG_SHIFT		(31-1)
#define PPCP4080_CC1_PLL_RAT_MASK		_BITFIELD32B(6,0x1f)
#define PPCP4080_CC1_PLL_RAT_SHIFT		(31-6)
#define PPCP4080_CC2_PLL_RAT_MASK		_BITFIELD32B(14,0x1f)
#define PPCP4080_CC2_PLL_RAT_SHIFT		(31-14)
#define PPCP4080_CC3_PLL_RAT_MASK		_BITFIELD32B(22,0x1f)
#define PPCP4080_CC3_PLL_RAT_SHIFT		(31-22)
#define PPCP4080_CC4_PLL_RAT_MASK		_BITFIELD32B(30,0x1f)
#define PPCP4080_CC4_PLL_RAT_SHIFT		(31-30)

/*
 * RCW Status Register 3
 */
#define PPCP4080_C0_PLL_SEL_MASK		_BITFIELD32B(3,0xf)
#define PPCP4080_C0_PLL_SEL_SHIFT		(31-3)
#define PPCP4080_C1_PLL_SEL_MASK		_BITFIELD32B(7,0xf)
#define PPCP4080_C1_PLL_SEL_SHIFT		(31-7)
#define PPCP4080_C2_PLL_SEL_MASK		_BITFIELD32B(11,0xf)
#define PPCP4080_C2_PLL_SEL_SHIFT		(31-11)
#define PPCP4080_C3_PLL_SEL_MASK		_BITFIELD32B(15,0xf)
#define PPCP4080_C3_PLL_SEL_SHIFT		(31-15)
#define PPCP4080_C4_PLL_SEL_MASK		_BITFIELD32B(19,0xf)
#define PPCP4080_C4_PLL_SEL_SHIFT		(31-19)
#define PPCP4080_C5_PLL_SEL_MASK		_BITFIELD32B(23,0xf)
#define PPCP4080_C5_PLL_SEL_SHIFT		(31-23)
#define PPCP4080_C6_PLL_SEL_MASK		_BITFIELD32B(27,0xf)
#define PPCP4080_C6_PLL_SEL_SHIFT		(31-27)
#define PPCP4080_C7_PLL_SEL_MASK		_BITFIELD32B(31,0xf)
#define PPCP4080_C7_PLL_SEL_SHIFT		(31-31)

/*
 * PIC Feature Reporting Register
 */
#define PPCP4080_FRR_NIRQ_MASK			_BITFIELD32B(15,0x7ff)
#define PPCP4080_FRR_NIRQ_SHIFT			(31-15)
#define PPCP4080_FRR_NCPU_MASK			_BITFIELD32B(23,0x1f)
#define PPCP4080_FRR_NCPU_SHIFT			(31-23)
#define PPCP4080_FRR_VID_MASK			_BITFIELD32B(31,0xff)
#define PPCP4080_FRR_VID_SHIFT			(31-31)

/*
 * PIC Global Configuration Register
 */
#define PPCP4080_GCR_RST				_ONEBIT32B(0)
#define PPCP4080_GCR_M					_ONEBIT32B(2)

/*
 * PIC Vendor Identification Register
 */
#define PPCP4080_VIR_STEP_MASK			_BITFIELD32B(15,0xff)
#define PPCP4080_VIR_STEP_SHIFT			(31-15)
#define PPCP4080_VIR_DEVICE_ID_MASK		_BITFIELD32B(23,0xff)
#define PPCP4080_VIR_DEVICE_ID_SHIFT	(31-23)
#define PPCP4080_VIR_VENDOR_ID_MASK		_BITFIELD32B(31,0xff)
#define PPCP4080_VIR_VENDOR_ID_SHIFT	(31-31)

/*
 * PIC Processor Initialization Register
 */
#define PPCP4080_PIR_P0					_ONEBIT32B(31)

/*
 * PIC IPI/Timer/Message/External/Internal Interrupt Vector/Priority Regster
 */
#define PPCP4080_xIVPR_MSK				_ONEBIT32B(0)
#define PPCP4080_xIVPR_A				_ONEBIT32B(1)
#define PPCP4080_xIVPR_P				_ONEBIT32B(8)
#define PPCP4080_xIVPR_S				_ONEBIT32B(9)
#define PPCP4080_xIVPR_PRIORITY_MASK	_BITFIELD32B(15,0xf)
#define PPCP4080_xIVPR_PRIORITY_SHIFT	(31-15)
#define PPCP4080_xIVPR_VECTOR_MASK		_BITFIELD32B(31,0xffff)
#define PPCP4080_xIVPR_VECTOR_SHIFT		(31-31)

/*
 * PIC IPI/Timer/Message/External/Internal Interrupt Destination Regster
 */
#define PPCP4080_xIDR_EP				_ONEBIT32B(0)
#define PPCP4080_xIDR_CI				_ONEBIT32B(1)
#define PPCP4080_xIDR_P0				_ONEBIT32B(31)

/*
 * PIC Global Timer Current Count Register
 */
#define PPCP4080_GTCCR_TOG				_ONEBIT32B(0)
#define PPCP4080_GTCCR_COUNT_MASK		_BITFIELD32B(31,0x7fffffff)
#define PPCP4080_GTCCR_COUNT_SHIFT		(31-31)

/*
 * PIC Global Timer Base Count Register
 */
#define PPCP4080_GTBCR_CI				_ONEBIT32B(0)
#define PPCP4080_GTBCR_BASE_CNT_MASK	_BITFIELD32B(31,0x7fffffff)
#define PPCP4080_GTBCR_BASE_CNT_SHIFT	(31-31)

/*
 * PIC Timer Control Register
 */
#define PPCP4080_TCR_ROVR_MASK			_BITFIELD32B(7,0x7)
#define PPCP4080_TCR_ROVR_SHIFT			(31-7)
#define PPCP4080_TCR_ROVR_0				_ONEBIT32B(7)
#define PPCP4080_TCR_ROVR_1				_ONEBIT32B(6)
#define PPCP4080_TCR_ROVR_2				_ONEBIT32B(5)
#define PPCP4080_TCR_CLKR_MASK			_BITFIELD32B(23,0x3)
#define PPCP4080_TCR_CLKR_SHIFT			(31-23)
#define PPCP4080_TCR_CLKR_DIV8			_BITFIELD32B(23,0x0)
#define PPCP4080_TCR_CLKR_DIV16			_BITFIELD32B(23,0x1)
#define PPCP4080_TCR_CLKR_DIV32			_BITFIELD32B(23,0x2)
#define PPCP4080_TCR_CLKR_DIV64			_BITFIELD32B(23,0x3)
#define PPCP4080_TCR_CASC_MASK			_BITFIELD32B(31,0x7)
#define PPCP4080_TCR_CASC_SHIFT			(31-31)
#define PPCP4080_TCR_CASC_NONE			_BITFIELD32B(31,0x0)
#define PPCP4080_TCR_CASC_0AND1			_BITFIELD32B(31,0x1)
#define PPCP4080_TCR_CASC_1AND2			_BITFIELD32B(31,0x2)
#define PPCP4080_TCR_CASC_0AND1AND2		_BITFIELD32B(31,0x3)
#define PPCP4080_TCR_CASC_2AND3			_BITFIELD32B(31,0x4)
#define PPCP4080_TCR_CASC_0AND1_2AND3	_BITFIELD32B(31,0x5)
#define PPCP4080_TCR_CASC_1AND2AND3		_BITFIELD32B(31,0x6)
#define PPCP4080_TCR_CASC_0AND1AND2AND3	_BITFIELD32B(31,0x7)

/*
 * PIC Performance Monitor Mask Register (Even)
 */
#define PPCP4080_PMMRE_IPI(n)			_ONEBIT32B(8+(n))
#define PPCP4080_PMMRE_TIMER(n)			_ONEBIT32B(12+(n))
#define PPCP4080_PMMRE_MSG(n)			_ONEBIT32B(16+(n))
#define PPCP4080_PMMRE_EXT(n)			_ONEBIT32B(20+(n))

/*
 * PIC Performance Monitor Mask Register (Odd)
 */
#define PPCP4080_PMMRO_INT(n)			_ONEBIT32B((n))

/*
 * PIC Message Enable Register
 */
#define PPCP4080_MER_E3					_ONEBIT32B(28)
#define PPCP4080_MER_E2					_ONEBIT32B(29)
#define PPCP4080_MER_E1					_ONEBIT32B(30)
#define PPCP4080_MER_E0					_ONEBIT32B(31)

/*
 * PIC Message Status Register
 */
#define PPCP4080_MSR_S3					_ONEBIT32B(28)
#define PPCP4080_MSR_S2					_ONEBIT32B(29)
#define PPCP4080_MSR_S1					_ONEBIT32B(30)
#define PPCP4080_MSR_S0					_ONEBIT32B(31)

/*
 * PIC Interprocessor Interrupt Dispatch Register
 */
#define PPCP4080_IPIDR_P0				_ONEBIT32B(31)

/*
 * ECB CCB Port Configuration register
 */
#define PPCP4080_EEBPCR_CPU1_EN			_ONEBIT32B(6)
#define PPCP4080_EEBPCR_CPU0_EN			_ONEBIT32B(7)

/*
 * Boot Page Translation Register
 */
#define PPCP4080_BPTR_EN				_ONEBIT32B(0)

/*
 * POR Status Register 2
 */
#define PPCP4080_PORSR2_DRAM_TYPE		_ONEBIT32B(2)

/*
 * Core Disable Register
 */
#define PPCP4080_COREDISR_CD0			_ONEBIT32B(31)
#define PPCP4080_COREDISR_CD1			_ONEBIT32B(30)
#define PPCP4080_COREDISR_CD2			_ONEBIT32B(29)
#define PPCP4080_COREDISR_CD3			_ONEBIT32B(28)
#define PPCP4080_COREDISR_CD4			_ONEBIT32B(27)
#define PPCP4080_COREDISR_CD5			_ONEBIT32B(26)
#define PPCP4080_COREDISR_CD6			_ONEBIT32B(25)
#define PPCP4080_COREDISR_CD7			_ONEBIT32B(24)

/*
 * Reset Control Register
 */
#define PPCP4080_RSTCR_RESET_REQ		_ONEBIT32B(30)

/*
 * CCSR Offsets of memory mapped registers
 */
#define PPCP4080_CCSR_OFF_CCSRBAR		0x00000
#define PPCP4080_CCSR_OFF_ALTCBAR		0x00008
#define PPCP4080_CCSR_OFF_ALTCSR		0x00010
#define PPCP4080_CCSR_OFF_BPTR			0x00020
#define PPCP4080_CCSR_OFF_EEBPCR		0x01010
#define PPCP4080_CCSR_OFF_PVR			0xe00a0
#define PPCP4080_CCSR_OFF_SVR			0xe00a4
/* Clock stuff */
#define PPCP4080_CCSR_OFF_PORSR1		0xe0000
#define PPCP4080_CCSR_OFF_PORSR2		0xe0004
#define PPCP4080_CCSR_OFF_GPPORCR1		0xe0020
#define PPCP4080_CCSR_OFF_DEVDISR1		0xe0070
#define PPCP4080_CCSR_OFF_DEVDISR2		0xe0074
#define PPCP4080_CCSR_OFF_COREDISR		0xe0094
#define PPCP4080_CCSR_OFF_RSTCR			0xe00b0
#define PPCP4080_CCSR_OFF_RSTRQPBLSR	0xe00b4
#define PPCP4080_CCSR_OFF_RSTRQMR1		0xe00c0
#define PPCP4080_CCSR_OFF_RSTRQSR1		0xe00c8
#define PPCP4080_CCSR_OFF_RSTRQWDTMR	0xe00d4
#define PPCP4080_CCSR_OFF_RSTRQWDTSR	0xe00dc
/* Reset Configuration Word Status Registers */
#define PPCP4080_CCSR_OFF_RCWSR1		0xe0100
#define PPCP4080_CCSR_OFF_RCWSR2		0xe0104
#define PPCP4080_CCSR_OFF_RCWSR3		0xe0108
#define PPCP4080_CCSR_OFF_RCWSR4		0xe010c
#define PPCP4080_CCSR_OFF_RCWSR5		0xe0110
#define PPCP4080_CCSR_OFF_RCWSR6		0xe0114
#define PPCP4080_CCSR_OFF_RCWSR7		0xe0118
#define PPCP4080_CCSR_OFF_RCWSR8		0xe011c
#define PPCP4080_CCSR_OFF_RCWSR9		0xe0120
#define PPCP4080_CCSR_OFF_RCWSR10		0xe0124
#define PPCP4080_CCSR_OFF_RCWSR11		0xe0128
#define PPCP4080_CCSR_OFF_RCWSR12		0xe012c
#define PPCP4080_CCSR_OFF_RCWSR13		0xe0130
#define PPCP4080_CCSR_OFF_RCWSR14		0xe0134
#define PPCP4080_CCSR_OFF_RCWSR15		0xe0138
#define PPCP4080_CCSR_OFF_RCWSR16		0xe013c
/* Scratch Registers */
#define PPCP4080_CCSR_OFF_SCRATCHRW(n)	(0xe0200 + ((n) - 1)*0x4) /*n = 1 to 4 */
#define PPCP4080_CCSR_OFF_SCRATCHW1R(n)	(0xe0300 + ((n) - 1)*0x4) /*n = 1 to 4 */
/* Core Reset Status Registers */
#define PPCP4080_CCSR_OFF_CRSTSR(n)		(0xe0400 + (n)*0x4) /*n = 0 to 7 */
/* Peripheral Logical I/O Device Number (LIODN) Registers */
#define PPCP4080_CCSR_OFF_PEX1LIODNR	0xe0500
#define PPCP4080_CCSR_OFF_PEX2LIODNR	0xe0504
#define PPCP4080_CCSR_OFF_PEX3LIODNR	0xe0508
#define PPCP4080_CCSR_OFF_RIO1LIODNR	0xe0510
#define PPCP4080_CCSR_OFF_RIO2LIODNR	0xe0514
#define PPCP4080_CCSR_OFF_USB1LIODNR	0xe0520
#define PPCP4080_CCSR_OFF_USB2LIODNR	0xe0524
#define PPCP4080_CCSR_OFF_eSDHCLIODNR	0xe0530
#define PPCP4080_CCSR_OFF_RMULIODNR		0xe0540
#define PPCP4080_CCSR_OFF_DMA1LIODNR	0xe0580
#define PPCP4080_CCSR_OFF_DMA2LIODNR	0xe0584
/* Peripheral Registers */
#define PPCP4080_CCSR_OFF_PAMUBYPENR	0xe0604
#define PPCP4080_CCSR_OFF_DMACR1		0xe0608
/* General Pin Multiplexing Control Register */
#define PPCP4080_CCSR_OFF_PMUXCR		0xe0e00
/* I/O Voltage Selection Registers */
#define PPCP4080_CCSR_OFF_IOVSELSR		0xe0e40
/* Clock Disable Control Registers */
#define PPCP4080_CCSR_OFF_DDRCLKDR		0xe0e60
#define PPCP4080_CCSR_OFF_ELBCCLKDR		0xe0e68
/* Polarity Control Registers */
#define PPCP4080_CCSR_OFF_SDHCPCR		0xe0e80

/* Interrupt controller */
#define PPCP4080_CCSR_OFF_IPIDR(n)		(0x40040 + (n)*0x10)
#define PPCP4080_CCSR_OFF_CTPR			0x40080
#define PPCP4080_CCSR_OFF_WHOAMI		0x40090
#define PPCP4080_CCSR_OFF_IACK			0x400a0
#define PPCP4080_CCSR_OFF_EOI			0x400b0
#define PPCP4080_CCSR_OFF_FRR			0x41000
#define PPCP4080_CCSR_OFF_GCR			0x41020
#define PPCP4080_CCSR_OFF_VIR			0x41080
#define PPCP4080_CCSR_OFF_PIR			0x41090
#define PPCP4080_CCSR_OFF_IPIVPR(n)		(0x410a0 + (n)*0x10)
#define PPCP4080_CCSR_OFF_PIC_SVR		0x410e0
#define PPCP4080_CCSR_OFF_TFRR			0x410f0
#define PPCP4080_CCSR_OFF_GTCCR(n)		(0x41100 + (n)*0x40)
#define PPCP4080_CCSR_OFF_GTBCR(n)		(0x41110 + (n)*0x40)
#define PPCP4080_CCSR_OFF_GTVPR(n)		(0x41120 + (n)*0x40)
#define PPCP4080_CCSR_OFF_GTDR(n)		(0x41130 + (n)*0x40)
#define PPCP4080_CCSR_OFF_TCR			0x41300
#define PPCP4080_CCSR_OFF_IRQSR0		0x41310
#define PPCP4080_CCSR_OFF_IRQSR1		0x41320
#define PPCP4080_CCSR_OFF_CIRSR0		0x41330
#define PPCP4080_CCSR_OFF_CIRSR1		0x41340
#define PPCP4080_CCSR_OFF_PMMR_even(n)	(0x41350+ (n)*0x10) /* n = 0,2,4,6 */
#define PPCP4080_CCSR_OFF_PMMR_odd(n)	(0x41350+ (n)*0x10) /* n = 1,3,5,7 */
#define PPCP4080_CCSR_OFF_MSGR(n)		(0x41400 + (n)*0x10)
#define PPCP4080_CCSR_OFF_MER			0x41500
#define PPCP4080_CCSR_OFF_MSR			0x41510
#define PPCP4080_CCSR_OFF_EIVPR(n)		(0x50000 + (n)*0x20)
#define PPCP4080_CCSR_OFF_EIDR(n)		(0x50010 + (n)*0x20)
#define PPCP4080_CCSR_OFF_EILR(n)		(0x50018 + (n)*0x20)
#define PPCP4080_CCSR_OFF_IIVPR(n)		(0x50200 + (n)*0x20)
#define PPCP4080_CCSR_OFF_IIDR(n)		(0x50210 + (n)*0x20)
#define PPCP4080_CCSR_OFF_IILR(n)		(0x50218 + (n)*0x20)
#define PPCP4080_CCSR_OFF_MIVPR(n)		(0x51600 + (n)*0x20)
#define PPCP4080_CCSR_OFF_MIDR(n)		(0x51610 + (n)*0x20)
#define PPCP4080_CCSR_OFF_MSIVPR(n)		(0x51c00 + (n)*0x20)
#define PPCP4080_CCSR_OFF_MSIDR(n)		(0x51C10 + (n)*0x20)
#define PPCP4080_CCSR_OFF_PC_IPIDR(n)	(0x60040 + (n)*0x10)
#define PPCP4080_CCSR_OFF_PC_CTPTR		0x60080
#define PPCP4080_CCSR_OFF_PC_WHOAMI		0x60090
#define PPCP4080_CCSR_OFF_PC_IACK		0x600a0
#define PPCP4080_CCSR_OFF_PC_EOI		0x600b0

#endif


__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/SP1/services/system/public/ppc/p4080cpu.h $ $Rev: 648509 $" )
