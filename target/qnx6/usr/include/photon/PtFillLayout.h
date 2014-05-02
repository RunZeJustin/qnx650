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
#ifndef	__PT_FILL_LAYOUT_H_INCLUDED
#define	__PT_FILL_LAYOUT_H_INCLUDED

/* PtFillLayoutInfo_t flags */
#define	Pt_LAYOUT_HORIZONTAL	0
#define	Pt_LAYOUT_VERTICAL		1

typedef struct pt_fill_layout_info {
	short	type;
	short	spacing;
} PtFillLayoutInfo_t;

extern const PtLayoutDefinition_t *PtFillLayout;
extern const PtFillLayoutInfo_t PtFillLayoutInfoDflts;

#endif

#ifdef __QNXNTO__
#include <sys/srcversion.h>
__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/trunk/lib/ph/public/photon/PtFillLayout.h $ $Rev: 224590 $" )
#endif
