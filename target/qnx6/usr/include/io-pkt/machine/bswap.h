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





#ifndef _MACHINE_BSWAP_H_INCLUDED
#define _MACHINE_BSWAP_H_INCLUDED

#include <gulliver.h>

#define bswap16(x) ENDIAN_RET16(x)
#define bswap32(x) ENDIAN_RET32(x)
#define bswap64(x) ENDIAN_RET64(x)

#endif

__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/SP1/lib/io-pkt/sys/machine/bswap.h $ $Rev: 233581 $" )
