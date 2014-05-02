/* Copyright 2009, QNX Software Systems. All Rights Reserved.
 * 
 * You must obtain a written license from and pay applicable license fees to 
 * QNX Software Systems before you may reproduce, modify or distribute this 
 * software, or any work that includes all or part of this software.  Free 
 * development licenses are available for evaluation and non-commercial purposes.  
 * For more information visit http://licensing.qnx.com or email licensing@qnx.com.
 * 
 * This file may contain contributions from others.  Please review this entire 
 * file for other proprietary rights or license notices, as well as the QNX 
 * Development Suite License Guide at http://licensing.qnx.com/license-guide/
 * for other information.
 */

#if defined(PH_PACKING_IS_ON)
	#error PhPack.h included twice
#else
	#define PH_PACKING_IS_ON
#endif

#if defined(__QNXNTO__)
	#include <_pack64.h>
#else
	#if __WATCOMC__ > 1000
		#pragma pack(__push,1)
	#else
		#pragma pack(1)
	#endif
#endif


#ifdef __QNXNTO__
#include <sys/srcversion.h>
__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/trunk/lib/ph/public/photon/PhPack.h $ $Rev: 224590 $" )
#endif
