/*
 * $QNXLicenseC:
 * Copyright 2009, QNX Software Systems. All Rights Reserved.
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

#ifndef _OVG_DRIVER_BACKEND_H
#define _OVG_DRIVER_BACKEND_H

#include "VG/ovg11_api_backend.h"

#include <graphics/display.h>
#include <gf/gf_internals.h>
// GN TODO The egl.h include needs to go in the egl_backend, but it would break GLES
// GN TODO so for now it can go here...
#include <EGL/egl.h>
#include <EGL/egl_backend.h>

typedef int (*get_vg11funcs_t)(disp_adapter_t *adapter, ovg11_interface_t *funcs, int tabsize);
typedef int (*get_egl14vgfuncs_t)(disp_adapter_t *adapter, egl_interface_t *funcs, int tabsize);

/* Main draw driver entry points */
extern int devg_get_vg11funcs(disp_adapter_t *adapter, ovg11_interface_t *funcs, int tabsize);
extern int devg_get_egl14vgfuncs(disp_adapter_t *adapter, egl_interface_t *funcs, int tabsize);

#endif // _OVG_DRIVER_BACKEND_H

__SRCVERSION( "$URL: http://svn.ott.qnx.com/product/trunk/lib/openvg/G12/ovg/bb2d/gx_2d.h $ $Rev: 219724 $" )
