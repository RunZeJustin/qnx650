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
 * 41xx interrupt classes
 *

 *
 */
#ifndef __MIPS_41XXINTR_H_INCLUDED
#define __MIPS_41XXINTR_H_INCLUDED

#include <mips/intr.h>

/* Cascaded off the MIPS_INTR_HW0 vector */
#define MIPS41XX_INTR_CLASS_SYS			(0x8000UL<<16)
#define MIPS41XX_INTR_BAT				(MIPS41XX_INTR_CLASS_SYS+0)
#define MIPS41XX_INTR_POWER				(MIPS41XX_INTR_CLASS_SYS+1)
#define MIPS41XX_INTR_ETIMER			(MIPS41XX_INTR_CLASS_SYS+3)
#define MIPS41XX_INTR_PIU				(MIPS41XX_INTR_CLASS_SYS+5)
#define MIPS41XX_INTR_AIU				(MIPS41XX_INTR_CLASS_SYS+6)
#define MIPS41XX_INTR_KIU				(MIPS41XX_INTR_CLASS_SYS+7)
#define MIPS41XX_INTR_GIU				(MIPS41XX_INTR_CLASS_SYS+8) /*cascades further*/
#define MIPS41XX_INTR_SIU				(MIPS41XX_INTR_CLASS_SYS+9)
#define MIPS41XX_INTR_WRBERR			(MIPS41XX_INTR_CLASS_SYS+10)
#define MIPS41XX_INTR_SOFT				(MIPS41XX_INTR_CLASS_SYS+11)
#define MIPS41XX_INTR_DOZEPIU			(MIPS41XX_INTR_CLASS_SYS+13)
#define MIPS41XX_INTR_LED				(MIPS41XX_INTR_CLASS_SYS+17)
#define MIPS41XX_INTR_TCLK				(MIPS41XX_INTR_CLASS_SYS+19)
#define MIPS41XX_INTR_FIR				(MIPS41XX_INTR_CLASS_SYS+20)
#define MIPS41XX_INTR_DSIU				(MIPS41XX_INTR_CLASS_SYS+21)

/* Cascaded off the MIPS41XX_INTR_GUI vector */
#define MIPS41XX_INTR_CLASS_GIU			(0x8001UL<<16)
#define MIPS41XX_INTR_GIU0				(MIPS41XX_INTR_CLASS_GIU+0)
#define MIPS41XX_INTR_GIU1				(MIPS41XX_INTR_CLASS_GIU+1)
#define MIPS41XX_INTR_GIU2				(MIPS41XX_INTR_CLASS_GIU+2)
#define MIPS41XX_INTR_GIU3				(MIPS41XX_INTR_CLASS_GIU+3)
#define MIPS41XX_INTR_GIU4				(MIPS41XX_INTR_CLASS_GIU+4)
#define MIPS41XX_INTR_GIU5				(MIPS41XX_INTR_CLASS_GIU+5)
#define MIPS41XX_INTR_GIU6				(MIPS41XX_INTR_CLASS_GIU+6)
#define MIPS41XX_INTR_GIU7				(MIPS41XX_INTR_CLASS_GIU+7)
#define MIPS41XX_INTR_GIU8				(MIPS41XX_INTR_CLASS_GIU+8)
#define MIPS41XX_INTR_GIU9				(MIPS41XX_INTR_CLASS_GIU+9)
#define MIPS41XX_INTR_GIU10				(MIPS41XX_INTR_CLASS_GIU+10)
#define MIPS41XX_INTR_GIU11				(MIPS41XX_INTR_CLASS_GIU+11)
#define MIPS41XX_INTR_GIU12				(MIPS41XX_INTR_CLASS_GIU+12)
#define MIPS41XX_INTR_GIU13				(MIPS41XX_INTR_CLASS_GIU+13)
#define MIPS41XX_INTR_GIU14				(MIPS41XX_INTR_CLASS_GIU+14)
#define MIPS41XX_INTR_GIU15				(MIPS41XX_INTR_CLASS_GIU+15)
#define MIPS41XX_INTR_GIU16				(MIPS41XX_INTR_CLASS_GIU+16)
#define MIPS41XX_INTR_GIU17				(MIPS41XX_INTR_CLASS_GIU+17)
#define MIPS41XX_INTR_GIU18				(MIPS41XX_INTR_CLASS_GIU+18)
#define MIPS41XX_INTR_GIU19				(MIPS41XX_INTR_CLASS_GIU+19)
#define MIPS41XX_INTR_GIU20				(MIPS41XX_INTR_CLASS_GIU+20)
#define MIPS41XX_INTR_GIU21				(MIPS41XX_INTR_CLASS_GIU+21)
#define MIPS41XX_INTR_GIU22				(MIPS41XX_INTR_CLASS_GIU+22)
#define MIPS41XX_INTR_GIU23				(MIPS41XX_INTR_CLASS_GIU+23)
#define MIPS41XX_INTR_GIU24				(MIPS41XX_INTR_CLASS_GIU+24)
#define MIPS41XX_INTR_GIU25				(MIPS41XX_INTR_CLASS_GIU+25)
#define MIPS41XX_INTR_GIU26				(MIPS41XX_INTR_CLASS_GIU+26)
#define MIPS41XX_INTR_GIU27				(MIPS41XX_INTR_CLASS_GIU+27)
#define MIPS41XX_INTR_GIU28				(MIPS41XX_INTR_CLASS_GIU+28)
#define MIPS41XX_INTR_GIU29				(MIPS41XX_INTR_CLASS_GIU+29)
#define MIPS41XX_INTR_GIU30				(MIPS41XX_INTR_CLASS_GIU+30)
#define MIPS41XX_INTR_GIU31				(MIPS41XX_INTR_CLASS_GIU+31)

#define MIPS41XX_INTR_RTC_LONG1			MIPS_INTR_HW1
#define MIPS41XX_INTR_RTC_LONG2			MIPS_INTR_HW2
#define MIPS41XX_INTR_HSP				MIPS_INTR_HW3

#endif

/* __SRCVERSION("41xxintr.h $Rev: 152112 $"); */
