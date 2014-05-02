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
 * MIPS 4122 interrupt number definitions
 *

 *
 */
#ifndef __MIPS_4122INTR_H_INCLUDED
#define __MIPS_4122INTR_H_INCLUDED

#include <mips/intr.h>

/* Cascaded off the MIPS_INTR_HW0 vector */
#define MIPS4122_INTR_CLASS_SYS			(0x8000UL<<16)
#define MIPS4122_INTR_BAT				(MIPS4122_INTR_CLASS_SYS+0)
#define MIPS4122_INTR_POWER				(MIPS4122_INTR_CLASS_SYS+1)
#define MIPS4122_INTR_ETIMER			(MIPS4122_INTR_CLASS_SYS+3)
#define MIPS4122_INTR_GIU				(MIPS4122_INTR_CLASS_SYS+8) /*cascades further*/
#define MIPS4122_INTR_SIU				(MIPS4122_INTR_CLASS_SYS+9)
#define MIPS4122_INTR_WRBERR			(MIPS4122_INTR_CLASS_SYS+10)
#define MIPS4122_INTR_SOFT				(MIPS4122_INTR_CLASS_SYS+11)
#define MIPS4122_INTR_CLKRUN			(MIPS4122_INTR_CLASS_SYS+12)
#define MIPS4122_INTR_LED				(MIPS4122_INTR_CLASS_SYS+17)
#define MIPS4122_INTR_TCLK				(MIPS4122_INTR_CLASS_SYS+19)
#define MIPS4122_INTR_FIR				(MIPS4122_INTR_CLASS_SYS+20)
#define MIPS4122_INTR_DSIU				(MIPS4122_INTR_CLASS_SYS+21)
#define MIPS4122_INTR_PCI				(MIPS4122_INTR_CLASS_SYS+22)
#define MIPS4122_INTR_SCU				(MIPS4122_INTR_CLASS_SYS+23)
#define MIPS4122_INTR_CSI				(MIPS4122_INTR_CLASS_SYS+24)
#define MIPS4122_INTR_BCU				(MIPS4122_INTR_CLASS_SYS+25)

/* Cascaded off the MIPS4122_INTR_GUI vector */
#define MIPS4122_INTR_CLASS_GIU			(0x8001UL<<16)
#define MIPS4122_INTR_GIU0				(MIPS4122_INTR_CLASS_GIU+0)
#define MIPS4122_INTR_GIU1				(MIPS4122_INTR_CLASS_GIU+1)
#define MIPS4122_INTR_GIU2				(MIPS4122_INTR_CLASS_GIU+2)
#define MIPS4122_INTR_GIU3				(MIPS4122_INTR_CLASS_GIU+3)
#define MIPS4122_INTR_GIU4				(MIPS4122_INTR_CLASS_GIU+4)
#define MIPS4122_INTR_GIU5				(MIPS4122_INTR_CLASS_GIU+5)
#define MIPS4122_INTR_GIU6				(MIPS4122_INTR_CLASS_GIU+6)
#define MIPS4122_INTR_GIU7				(MIPS4122_INTR_CLASS_GIU+7)
#define MIPS4122_INTR_GIU8				(MIPS4122_INTR_CLASS_GIU+8)
#define MIPS4122_INTR_GIU9				(MIPS4122_INTR_CLASS_GIU+9)
#define MIPS4122_INTR_GIU10				(MIPS4122_INTR_CLASS_GIU+10)
#define MIPS4122_INTR_GIU11				(MIPS4122_INTR_CLASS_GIU+11)
#define MIPS4122_INTR_GIU12				(MIPS4122_INTR_CLASS_GIU+12)
#define MIPS4122_INTR_GIU13				(MIPS4122_INTR_CLASS_GIU+13)
#define MIPS4122_INTR_GIU14				(MIPS4122_INTR_CLASS_GIU+14)
#define MIPS4122_INTR_GIU15				(MIPS4122_INTR_CLASS_GIU+15)
#define MIPS4122_INTR_GIU16				(MIPS4122_INTR_CLASS_GIU+16)
#define MIPS4122_INTR_GIU17				(MIPS4122_INTR_CLASS_GIU+17)
#define MIPS4122_INTR_GIU18				(MIPS4122_INTR_CLASS_GIU+18)
#define MIPS4122_INTR_GIU19				(MIPS4122_INTR_CLASS_GIU+19)
#define MIPS4122_INTR_GIU20				(MIPS4122_INTR_CLASS_GIU+20)
#define MIPS4122_INTR_GIU21				(MIPS4122_INTR_CLASS_GIU+21)
#define MIPS4122_INTR_GIU22				(MIPS4122_INTR_CLASS_GIU+22)
#define MIPS4122_INTR_GIU23				(MIPS4122_INTR_CLASS_GIU+23)
#define MIPS4122_INTR_GIU24				(MIPS4122_INTR_CLASS_GIU+24)
#define MIPS4122_INTR_GIU25				(MIPS4122_INTR_CLASS_GIU+25)
#define MIPS4122_INTR_GIU26				(MIPS4122_INTR_CLASS_GIU+26)
#define MIPS4122_INTR_GIU27				(MIPS4122_INTR_CLASS_GIU+27)
#define MIPS4122_INTR_GIU28				(MIPS4122_INTR_CLASS_GIU+28)
#define MIPS4122_INTR_GIU29				(MIPS4122_INTR_CLASS_GIU+29)
#define MIPS4122_INTR_GIU30				(MIPS4122_INTR_CLASS_GIU+30)
#define MIPS4122_INTR_GIU31				(MIPS4122_INTR_CLASS_GIU+31)

#define MIPS4122_INTR_RTC_LONG1			MIPS_INTR_HW1
#define MIPS4122_INTR_RTC_LONG2			MIPS_INTR_HW2
#define MIPS4122_INTR_HSP				MIPS_INTR_HW3

#endif

/* __SRCVERSION("4122intr.h $Rev: 152112 $"); */
