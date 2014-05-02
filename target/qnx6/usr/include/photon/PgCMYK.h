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
#ifndef __PG_CMYK_H_INCLUDED
#define __PG_CMYK_H_INCLUDED

#include <photon/PhPack.h>

#ifdef __cplusplus
extern "C" 
{
#endif

#define Pg_CMYK_CYAN	0
#define Pg_CMYK_MAGENTA	1
#define Pg_CMYK_YELLOW	2
#define Pg_CMYK_BLACK	3

#define Pg_CM_CMYK_ID	4

extern PgColorModel_t const Pg_CM_CMYK[1];

#ifdef __cplusplus
};
#endif

#include <photon/PhPackPop.h>

#endif /* __PG_CMYK_H_ */

#ifdef __QNXNTO__
#include <sys/srcversion.h>
__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/trunk/lib/ph/public/photon/PgCMYK.h $ $Rev: 224590 $" )
#endif
