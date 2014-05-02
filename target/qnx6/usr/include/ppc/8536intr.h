/*
 * $QNXLicenseC:
 * Copyright 2008, QNX Software Systems. 
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"). You 
 * may not reproduce, modify or distribute this software except in 
 * compliance with the License. You may obtain a copy of the License 
 * at: http://www.apache.org/licenses/LICENSE-2.0 
 * 
 * Unless required by applicable law or agreed to in writing, software 
 * distributed under the License is distributed on an "AS IS" basis, 
 * WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * This file may contain contributions from others, either as 
 * contributors under the License or as licensors under other terms.  
 * Please review this entire file for other proprietary rights or license 
 * notices, as well as the QNX Development Suite License Guide at 
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */






/*
 * PPC85xx interrupt number definitions
 *
 *
 */

#ifndef __PPC_85XXINTR_H_INCLUDED
#define __PPC_85XXINTR_H_INCLUDED

#include <ppc/intr.h>

#define PPC_INTR_CLASS_85xx			_NTO_INTR_CLASS_EXTERNAL

#define PPC85xx_INTR_L2_CACHE		(PPC_INTR_CLASS_85xx + 0)
#define PPC85xx_INTR_ECM			(PPC_INTR_CLASS_85xx + 1)
#define PPC85xx_INTR_DDR_DRAM		(PPC_INTR_CLASS_85xx + 2)
#define PPC85xx_INTR_LBC			(PPC_INTR_CLASS_85xx + 3)
#define PPC85xx_INTR_DMA0			(PPC_INTR_CLASS_85xx + 4)
#define PPC85xx_INTR_DMA1			(PPC_INTR_CLASS_85xx + 5)
#define PPC85xx_INTR_DMA2			(PPC_INTR_CLASS_85xx + 6)
#define PPC85xx_INTR_DMA3			(PPC_INTR_CLASS_85xx + 7)
#define PPC85xx_INTR_PCI			(PPC_INTR_CLASS_85xx + 8)

#define PPC85xx_INTR_PCI2			(PPC_INTR_CLASS_85xx + 9)  /* 8548 */
#define PPC85xx_INTR_PCI_EXPRESS	(PPC_INTR_CLASS_85xx + 10) /* 8548 */

/* Parallel RIO Interrupts */
#define PPC85xx_INTR_RIO_INBOUND_ERR (PPC_INTR_CLASS_85xx + 9)
#define PPC85xx_INTR_RIO_DOORBELL	(PPC_INTR_CLASS_85xx +10)
#define PPC85xx_INTR_RIO_OUTBOUND	(PPC_INTR_CLASS_85xx +11)
#define PPC85xx_INTR_RIO_INBOUND	(PPC_INTR_CLASS_85xx +12)

#define PPC85xx_INTR_TSEC1_TX		(PPC_INTR_CLASS_85xx +13)
#define PPC85xx_INTR_TSEC1_RX		(PPC_INTR_CLASS_85xx +14)
#define PPC85xx_INTR_TSEC3_TX		(PPC_INTR_CLASS_85xx +15) /* 8548 */
#define PPC85xx_INTR_TSEC3_RX		(PPC_INTR_CLASS_85xx +16) /* 8548 */
#define PPC85xx_INTR_TSEC3_ERROR	(PPC_INTR_CLASS_85xx +17) /* 8548 */
#define PPC85xx_INTR_TSEC1_ERROR	(PPC_INTR_CLASS_85xx +18)
#define PPC85xx_INTR_TSEC2_TX		(PPC_INTR_CLASS_85xx +19)
#define PPC85xx_INTR_TSEC2_RX		(PPC_INTR_CLASS_85xx +20)
#define PPC85xx_INTR_TSEC4_TX		(PPC_INTR_CLASS_85xx +21) /* 8548 */
#define PPC85xx_INTR_TSEC4_RX		(PPC_INTR_CLASS_85xx +22) /* 8548 */
#define PPC85xx_INTR_TSEC4_ERROR	(PPC_INTR_CLASS_85xx +23) /* 8548 */
#define PPC85xx_INTR_TSEC2_ERROR	(PPC_INTR_CLASS_85xx +24)
#define PPC85xx_INTR_FAST_ETHER		(PPC_INTR_CLASS_85xx +25) /* 8540 */
#define PPC85xx_INTR_DUART			(PPC_INTR_CLASS_85xx +26) /* 8540 */
#define PPC85xx_INTR_I2C			(PPC_INTR_CLASS_85xx +27)
#define PPC85xx_INTR_PMI			(PPC_INTR_CLASS_85xx +28)
#define PPC85xx_INTR_RESERVED7		(PPC_INTR_CLASS_85xx +29)
#define PPC85xx_INTR_SECURITY		(PPC_INTR_CLASS_85xx +29) /* 8548 */
#define PPC85xx_INTR_CPM			(PPC_INTR_CLASS_85xx +30) /* 8560 */
#define PPC85xx_INTR_RESERVED8		(PPC_INTR_CLASS_85xx +31)


#define PPC85xx_INTR_IRQ0			(PPC_INTR_CLASS_85xx +64)
#define PPC85xx_INTR_IRQ1			(PPC_INTR_CLASS_85xx +65)
#define PPC85xx_INTR_IRQ2			(PPC_INTR_CLASS_85xx +66)
#define PPC85xx_INTR_IRQ3			(PPC_INTR_CLASS_85xx +67)
#define PPC85xx_INTR_IRQ4			(PPC_INTR_CLASS_85xx +68)
#define PPC85xx_INTR_IRQ5			(PPC_INTR_CLASS_85xx +69)
#define PPC85xx_INTR_IRQ6			(PPC_INTR_CLASS_85xx +70)
#define PPC85xx_INTR_IRQ7			(PPC_INTR_CLASS_85xx +71)
#define PPC85xx_INTR_IRQ8			(PPC_INTR_CLASS_85xx +72)
#define PPC85xx_INTR_IRQ9			(PPC_INTR_CLASS_85xx +73)
#define PPC85xx_INTR_IRQ10			(PPC_INTR_CLASS_85xx +74)
#define PPC85xx_INTR_IRQ11			(PPC_INTR_CLASS_85xx +75)

#define PPC85xx_INTR_IPI0			(PPC_INTR_CLASS_85xx +76)
#define PPC85xx_INTR_IPI1			(PPC_INTR_CLASS_85xx +77)
#define PPC85xx_INTR_IPI2			(PPC_INTR_CLASS_85xx +78)
#define PPC85xx_INTR_IPI3			(PPC_INTR_CLASS_85xx +79)

#define PPC85xx_INTR_GT0			(PPC_INTR_CLASS_85xx +80)
#define PPC85xx_INTR_GT1			(PPC_INTR_CLASS_85xx +81)
#define PPC85xx_INTR_GT2			(PPC_INTR_CLASS_85xx +82)
#define PPC85xx_INTR_GT3			(PPC_INTR_CLASS_85xx +83)

#define PPC85xx_INTR_MSG0			(PPC_INTR_CLASS_85xx +84)
#define PPC85xx_INTR_MSG1			(PPC_INTR_CLASS_85xx +85)
#define PPC85xx_INTR_MSG2			(PPC_INTR_CLASS_85xx +86)
#define PPC85xx_INTR_MSG3			(PPC_INTR_CLASS_85xx +87)





#define PPC85xx_INTR_CPM_BASE		(PPC_INTR_CLASS_85xx + 64)

#define PPC85xx_INTR_CPM_I2C 		(PPC85xx_INTR_CPM_BASE + 0x0001)
#define PPC85xx_INTR_CPM_SPI 		(PPC85xx_INTR_CPM_BASE + 0x0002)
#define PPC85xx_INTR_CPM_RISCTIMERS	(PPC85xx_INTR_CPM_BASE + 0x0003)
#define PPC85xx_INTR_CPM_SMC1		(PPC85xx_INTR_CPM_BASE + 0x0004)
#define PPC85xx_INTR_CPM_SMC2		(PPC85xx_INTR_CPM_BASE + 0x0005)
#define PPC85xx_INTR_CPM_IDMA1		(PPC85xx_INTR_CPM_BASE + 0x0006)
#define PPC85xx_INTR_CPM_IDMA2		(PPC85xx_INTR_CPM_BASE + 0x0007)
#define PPC85xx_INTR_CPM_IDMA3		(PPC85xx_INTR_CPM_BASE + 0x0008)
#define PPC85xx_INTR_CPM_IDMA4		(PPC85xx_INTR_CPM_BASE + 0x0009)
#define PPC85xx_INTR_CPM_SDMA		(PPC85xx_INTR_CPM_BASE + 0x000a)
#define PPC85xx_INTR_CPM_TMR1		(PPC85xx_INTR_CPM_BASE + 0x000c)
#define PPC85xx_INTR_CPM_TMR2		(PPC85xx_INTR_CPM_BASE + 0x000d)
#define PPC85xx_INTR_CPM_TMR3		(PPC85xx_INTR_CPM_BASE + 0x000e)
#define PPC85xx_INTR_CPM_TMR4		(PPC85xx_INTR_CPM_BASE + 0x000f)
#define PPC85xx_INTR_CPM_TMCNT		(PPC85xx_INTR_CPM_BASE + 0x0010)
#define PPC85xx_INTR_CPM_PIT		(PPC85xx_INTR_CPM_BASE + 0x0011)
#define PPC85xx_INTR_CPM_IRQ1		(PPC85xx_INTR_CPM_BASE + 0x0013)
#define PPC85xx_INTR_CPM_IRQ2		(PPC85xx_INTR_CPM_BASE + 0x0014)
#define PPC85xx_INTR_CPM_IRQ3		(PPC85xx_INTR_CPM_BASE + 0x0015)
#define PPC85xx_INTR_CPM_IRQ4		(PPC85xx_INTR_CPM_BASE + 0x0016)
#define PPC85xx_INTR_CPM_IRQ5		(PPC85xx_INTR_CPM_BASE + 0x0017)
#define PPC85xx_INTR_CPM_IRQ6		(PPC85xx_INTR_CPM_BASE + 0x0018)
#define PPC85xx_INTR_CPM_IRQ7		(PPC85xx_INTR_CPM_BASE + 0x0019)
#define PPC85xx_INTR_CPM_FCC1		(PPC85xx_INTR_CPM_BASE + 0x0020)
#define PPC85xx_INTR_CPM_FCC2		(PPC85xx_INTR_CPM_BASE + 0x0021)
#define PPC85xx_INTR_CPM_FCC3		(PPC85xx_INTR_CPM_BASE + 0x0022)
#define PPC85xx_INTR_CPM_MCC1		(PPC85xx_INTR_CPM_BASE + 0x0024)
#define PPC85xx_INTR_CPM_MCC2		(PPC85xx_INTR_CPM_BASE + 0x0025)
#define PPC85xx_INTR_CPM_SCC1		(PPC85xx_INTR_CPM_BASE + 0x0028)
#define PPC85xx_INTR_CPM_SCC2		(PPC85xx_INTR_CPM_BASE + 0x0029)
#define PPC85xx_INTR_CPM_SCC3		(PPC85xx_INTR_CPM_BASE + 0x002a)
#define PPC85xx_INTR_CPM_SCC4		(PPC85xx_INTR_CPM_BASE + 0x002b)
#define PPC85xx_INTR_CPM_TCL		(PPC85xx_INTR_CPM_BASE + 0x002c)
#define PPC85xx_INTR_CPM_CORE		(PPC85xx_INTR_CPM_BASE + 0x002d)
#define PPC85xx_INTR_CPM_SDMASYS	(PPC85xx_INTR_CPM_BASE + 0x002e)
#define PPC85xx_INTR_CPM_SDMALCL	(PPC85xx_INTR_CPM_BASE + 0x002f)
#define PPC85xx_INTR_CPM_PC15		(PPC85xx_INTR_CPM_BASE + 0x0030)
#define PPC85xx_INTR_CPM_PC14		(PPC85xx_INTR_CPM_BASE + 0x0031)
#define PPC85xx_INTR_CPM_PC13		(PPC85xx_INTR_CPM_BASE + 0x0032)
#define PPC85xx_INTR_CPM_PC12		(PPC85xx_INTR_CPM_BASE + 0x0033)
#define PPC85xx_INTR_CPM_PC11		(PPC85xx_INTR_CPM_BASE + 0x0034)
#define PPC85xx_INTR_CPM_PC10		(PPC85xx_INTR_CPM_BASE + 0x0035)
#define PPC85xx_INTR_CPM_PC9		(PPC85xx_INTR_CPM_BASE + 0x0036)
#define PPC85xx_INTR_CPM_PC8		(PPC85xx_INTR_CPM_BASE + 0x0037)
#define PPC85xx_INTR_CPM_PC7		(PPC85xx_INTR_CPM_BASE + 0x0038)
#define PPC85xx_INTR_CPM_PC6		(PPC85xx_INTR_CPM_BASE + 0x0039)
#define PPC85xx_INTR_CPM_PC5		(PPC85xx_INTR_CPM_BASE + 0x003a)
#define PPC85xx_INTR_CPM_PC4		(PPC85xx_INTR_CPM_BASE + 0x003b)
#define PPC85xx_INTR_CPM_PC3		(PPC85xx_INTR_CPM_BASE + 0x003c)
#define PPC85xx_INTR_CPM_PC2		(PPC85xx_INTR_CPM_BASE + 0x003d)
#define PPC85xx_INTR_CPM_PC1		(PPC85xx_INTR_CPM_BASE + 0x003e)
#define PPC85xx_INTR_CPM_PC0		(PPC85xx_INTR_CPM_BASE + 0x003f)


/* Additional interrupts on 8548 */
#define PPC85xx_INTR_EXTND_BASE					(PPC_INTR_CLASS_85xx     +150)
#define PPC85xx_INTR_SRIO_ERROR_WRITEPORT		(PPC85xx_INTR_EXTND_BASE +0)
#define PPC85xx_INTR_SRIO_OUTBOUND_DOORBELL		(PPC85xx_INTR_EXTND_BASE +1)
#define PPC85xx_INTR_SRIO_INBOUND_DOORBELL		(PPC85xx_INTR_EXTND_BASE +2)
#define PPC85xx_INTR_RESERVED9					(PPC85xx_INTR_EXTND_BASE +3)
#define PPC85xx_INTR_RESERVED10					(PPC85xx_INTR_EXTND_BASE +4)
#define PPC85xx_INTR_SRIO_OUTBOUND_MESSAGE0		(PPC85xx_INTR_EXTND_BASE +5)
#define PPC85xx_INTR_SRIO_INBOUND_MESSAGE0		(PPC85xx_INTR_EXTND_BASE +6)
#define PPC85xx_INTR_SRIO_OUTBOUND_MESSAGE1		(PPC85xx_INTR_EXTND_BASE +7)
#define PPC85xx_INTR_SRIO_INBOUND_MESSAGE1		(PPC85xx_INTR_EXTND_BASE +8)
#define PPC85xx_INTR_RESERVED41					(PPC85xx_INTR_EXTND_BASE +9)
#define PPC85xx_INTR_RESERVED42					(PPC85xx_INTR_EXTND_BASE +10)
#define PPC85xx_INTR_RESERVED43					(PPC85xx_INTR_EXTND_BASE +11)
#define PPC85xx_INTR_RESERVED44					(PPC85xx_INTR_EXTND_BASE +12)
#define PPC85xx_INTR_RESERVED45					(PPC85xx_INTR_EXTND_BASE +13)
#define PPC85xx_INTR_RESERVED46					(PPC85xx_INTR_EXTND_BASE +14)
#define PPC85xx_INTR_RESERVED47					(PPC85xx_INTR_EXTND_BASE +15)


#define PPC85xx_INTR_MSGSHRD0					(PPC85XX_INTR_EXTND_BASE +16)
#define PPC85xx_INTR_MSGSHRD1					(PPC85XX_INTR_EXTND_BASE +17)
#define PPC85xx_INTR_MSGSHRD2					(PPC85XX_INTR_EXTND_BASE +18)
#define PPC85xx_INTR_MSGSHRD3					(PPC85XX_INTR_EXTND_BASE +19)
#define PPC85xx_INTR_MSGSHRD4					(PPC85XX_INTR_EXTND_BASE +20)
#define PPC85xx_INTR_MSGSHRD5					(PPC85XX_INTR_EXTND_BASE +21)
#define PPC85xx_INTR_MSGSHRD6					(PPC85XX_INTR_EXTND_BASE +22)
#define PPC85xx_INTR_MSGSHRD7					(PPC85XX_INTR_EXTND_BASE +23)


#endif

/* __SRCVERSION("85xxintr.h $Rev: 648519 $"); */

#ifdef __QNXNTO__
#include <sys/srcversion.h>
__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/SP1/hardware/startup/lib/public/ppc/8536intr.h $ $Rev: 648519 $" )
#endif
