/*
 * $QNXLicenseC:
 * Copyright 2010, QNX Software Systems. 
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
* IMX6X SOC devices
*
* This file contains names for all of the devices that may exists on any IMX6X
* processor variant (i.MX6 Quad, i.MX6 Dual, i.MX6 Solo). Specifically, these 
* are the internal devices that are part of the IMX6X SOC and not board specific
* devices. Board specific devices are defined in a similarly named board specific file
* 
* The names are added to the hwinfo section of the syspage (at the discretion of
* the startup writer) so that drivers can use hwi_find_device() to determine
* the existence of SOC device instances in a portable fashion and optionally
* retrieve device specific information like interrupt vectors, etc.
* 
* Not all of the devices are on every processor so hwi_find_device() may return
* HWI_NULL_OFF if a device, or device instance (ie. unit) is not found.
*
*/

#ifndef __HWINFO_IMX61_H_INCLUDED
#define __HWINFO_IMX61_H_INCLUDED

#include <hw/sysinfo.h>

/*
 * =============================================================================
 * 
 *                                B U S E S
 * 
 * =============================================================================
*/
/* I2C - 1 interrupt */
#define IMX6_HWI_I2C						HWI_ITEM_BUS_I2C

/* USB */
#define IMX6_HWI_USB						HWI_ITEM_BUS_USB

/* SPI */
#define IMX6_HWI_SPI						HWI_ITEM_BUS_SPI

/*
 * =============================================================================
 * 
 *                              D E V I C E S
 * 
 * =============================================================================
*/
/* SDHC */
#define IMX6_HWI_SDHC						"sdhc"

/* DMA - multiple interrupts are assigned per available channel for each device */
#define IMX6_HWI_DMA						"dma"

/* FEC - interrupts are assigned */
#define IMX6_HWI_FEC						"FEC"  // "fec"
#define IMX6_HWI_LEGACY_FEC					"fec"  // "tsec"

/* DUART - 1 interrupt */
#define IMX6_HWI_UART						"uart"

/* Security - 1 interrupt per device */
#define IMX6_HWI_SECURITY					"security"

/* GPIO - 1 interrupt per device */
#define IMX6_HWI_GPIO						"gpio"

/* SSI BUS  */
#define IMX6_HWI_SSI						"ssi"

/* SDRAM  */
#define IMX6_HWI_SDRAM						"sdram"

/* Watchdog  */
#define IMX6_HWI_WDOG						"wdog"

/* MLB  */
#define IMX6_HWI_MLB						"mlb"

/* Graphics 2D  */
#define IMX6_HWI_GPU_2D						"gpu2d"

/* Graphics 3D  */
#define IMX6_HWI_GPU_3D						"gpu3d"

/* Image Processing Unit  */
#define IMX6_HWI_IPU						"ipu"

/* Video Processing Unit  */
#define IMX6_HWI_VPU						"vpu"

/* ESAI  */  
#define IMX6_HWI_ESAI                                           "esai"

#endif  /* __HWINFO_IMX61_H_INCLUDED */

__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/SP1/hardware/startup/lib/public/hw/hwinfo_imx6x.h $ $Rev: 592152 $" )
