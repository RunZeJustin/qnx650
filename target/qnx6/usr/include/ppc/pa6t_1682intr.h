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
 * PA6T 1862 interrupt number definitions
 *

 *
 */
#ifndef __PPC_PA6T_1862INTR_H_INCLUDED
#define __PPC_PA6T_1682INTR_H_INCLUDED

#include <ppc/intr.h>

/* CLASS GENERAL */
#define PPCPA6T_1682_INTR_CLASS_GENERAL	_NTO_INTR_CLASS_EXTERNAL
#define PPCPA6T_1862_INTR_GPIO(x)			(PPCPA6T_1682_INTR_CLASS_GENERAL + 0 + (x))
#define PPCPA6T_1862_INTR_SER_IRQ_FRAME(x)	(PPCPA6T_1682_INTR_CLASS_GENERAL + 16 + (x))
#define PPCPA6T_1862_INTR_PCI_INTA			(PPCPA6T_1682_INTR_CLASS_GENERAL + 48)
#define PPCPA6T_1862_INTR_PCI_INTB			(PPCPA6T_1682_INTR_CLASS_GENERAL + 49)
#define PPCPA6T_1862_INTR_PCI_INTC			(PPCPA6T_1682_INTR_CLASS_GENERAL + 50)
#define PPCPA6T_1862_INTR_PCI_INTD			(PPCPA6T_1682_INTR_CLASS_GENERAL + 51)
#define PPCPA6T_1862_INTR_PCI_EXP_PME		(PPCPA6T_1682_INTR_CLASS_GENERAL + 52)
#define PPCPA6T_1862_INTR_PCI_EXP_CORR_ERR	(PPCPA6T_1682_INTR_CLASS_GENERAL + 53)
#define PPCPA6T_1862_INTR_PCI_EXP_NONFATAL_ERR	(PPCPA6T_1682_INTR_CLASS_GENERAL + 54)
#define PPCPA6T_1862_INTR_PCI_EXP_FATAL_ERR	(PPCPA6T_1682_INTR_CLASS_GENERAL + 55)
#define PPCPA6T_1862_INTR_PCI_EXP_ROOT_PORT(x)	(PPCPA6T_1682_INTR_CLASS_GENERAL + 56 + (x))
#define PPCPA6T_1862_INTR_GIGE_INTERFACE(x)	(PPCPA6T_1682_INTR_CLASS_GENERAL + 65 + (x))
#define PPCPA6T_1862_INTR_XAUI_INTERFACE(x)	(PPCPA6T_1682_INTR_CLASS_GENERAL + 68 + (x))
#define PPCPA6T_1862_INTR_SMBUS_INTERFACE(x)	(PPCPA6T_1682_INTR_CLASS_GENERAL + 70 + (x))
#define PPCPA6T_1862_INTR_UART(x)			(PPCPA6T_1682_INTR_CLASS_GENERAL + 73 + (x))
#define PPCPA6T_1862_INTR_WATCHDOG(x)		(PPCPA6T_1682_INTR_CLASS_GENERAL + 75 + (x))
#define PPCPA6T_1862_INTR_POWER_MNGT(x)		(PPCPA6T_1682_INTR_CLASS_GENERAL + 77 + (x))
#define PPCPA6T_1862_INTR_PMU_BMC_COMM		(PPCPA6T_1682_INTR_CLASS_GENERAL + 79)
#define PPCPA6T_1862_INTR_RANDOM_NUMBER		(PPCPA6T_1682_INTR_CLASS_GENERAL + 80)
#define PPCPA6T_1862_INTR_LOCAL_BUS_ERR		(PPCPA6T_1682_INTR_CLASS_GENERAL + 81)
#define PPCPA6T_1862_INTR_L2_SOFT_ERR		(PPCPA6T_1682_INTR_CLASS_GENERAL + 82)
#define PPCPA6T_1862_INTR_L2_SERIOUS_ERR	(PPCPA6T_1682_INTR_CLASS_GENERAL + 83)
#define PPCPA6T_1862_INTR_SDC_SEVERE		(PPCPA6T_1682_INTR_CLASS_GENERAL + 84)
#define PPCPA6T_1862_INTR_IOB_SOFT_ERR		(PPCPA6T_1682_INTR_CLASS_GENERAL + 86)
#define PPCPA6T_1862_INTR_IOB_SERIOUS_ERR	(PPCPA6T_1682_INTR_CLASS_GENERAL + 87)
#define PPCPA6T_1862_INTR_MEM0_SOFT_ERR		(PPCPA6T_1682_INTR_CLASS_GENERAL + 88)
#define PPCPA6T_1862_INTR_MEM0_SERIOUS_ERR	(PPCPA6T_1682_INTR_CLASS_GENERAL + 89)
#define PPCPA6T_1862_INTR_MEM1_SOFT_ERR		(PPCPA6T_1682_INTR_CLASS_GENERAL + 90)
#define PPCPA6T_1862_INTR_MEM1_SERIOUS_ERR	(PPCPA6T_1682_INTR_CLASS_GENERAL + 91)
#define PPCPA6T_1862_INTR_SIMPLE_DMA(x)		(PPCPA6T_1682_INTR_CLASS_GENERAL + 92 + (x))
#define PPCPA6T_1862_INTR_DMA_TRANSMIT(x)	(PPCPA6T_1682_INTR_CLASS_GENERAL + 128 + (x))
#define PPCPA6T_1862_INTR_DMA_RECEIVE(x)	(PPCPA6T_1682_INTR_CLASS_GENERAL + 149 + (x))
#define PPCPA6T_1862_INTR_MSI(x)			(PPCPA6T_1682_INTR_CLASS_GENERAL + 512 + (x))

#endif

/* __SRCVERSION("pa6t_1682intr.h $Rev: 648519 $"); */

#ifdef __QNXNTO__
#include <sys/srcversion.h>
__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/SP1/hardware/startup/lib/public/ppc/pa6t_1682intr.h $ $Rev: 648519 $" )
#endif
