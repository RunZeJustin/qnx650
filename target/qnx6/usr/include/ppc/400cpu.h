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
 *  ppc/400cpu.h
 *
 * Registers specific to the 400 series
 *

 */

#ifndef __PPC_400CPU_H_INCLUDED
#define __PPC_400CPU_H_INCLUDED

#ifndef __PLATFORM_H_INCLUDED
#include <sys/platform.h>
#endif

/*
 * Debug Control Register
 */
#define PPC400_DBCR_EDM			_ONEBIT32B( 0 )		/*401,403 only*/
#define PPC400_DBCR_IDM			_ONEBIT32B( 1 )
#define PPC400_DBCR_RST_MASK	_BITFIELD32B( 3, 3 )
#define PPC400_DBCR_RST_NORESET	_BITFIELD32B( 3, 0 )
#define PPC400_DBCR_RST_CORE	_BITFIELD32B( 3, 1 )
#define PPC400_DBCR_RST_CHIP	_BITFIELD32B( 3, 2 )
#define PPC400_DBCR_RST_SYSTEM	_BITFIELD32B( 3, 3 )
#define PPC400_DBCR_IC			_ONEBIT32B( 4 )
#define PPC400_DBCR_BT			_ONEBIT32B( 5 )
#define PPC400_DBCR_EDE			_ONEBIT32B( 6 )
#define PPC400_DBCR_TDE			_ONEBIT32B( 7 )
#define PPC400_DBCR_FER_MASK	_BITFIELD32B( 12, 0xf )	/*403 only*/
#define PPC400_DBCR_FER_SHIFT	(31-12)
#define PPC400_DBCR_FT			_ONEBIT32B( 13 )
#define PPC400_DBCR_IA1			_ONEBIT32B( 14 )
#define PPC400_DBCR_IA2			_ONEBIT32B( 15 )		/*403 only*/
#define PPC400_DBCR_D1R			_ONEBIT32B( 16 )
#define PPC400_DBCR_D1W			_ONEBIT32B( 17 )
#define PPC400_DBCR_D1S_MASK	_BITFIELD32B( 19, 0x3 )
#define PPC400_DBCR_D1S_IGN0LSB	_BITFIELD32B( 19, 0 )
#define PPC400_DBCR_D1S_IGN1LSB	_BITFIELD32B( 19, 1 )
#define PPC400_DBCR_D1S_IGN2LSB	_BITFIELD32B( 19, 2 )
#define PPC400_DBCR_D1S_IGN4LSB	_BITFIELD32B( 19, 3 )
#define PPC400_DBCR_D2R			_ONEBIT32B( 20 )		/*403 only*/
#define PPC400_DBCR_D2W			_ONEBIT32B( 21 )		/*403 only*/
#define PPC400_DBCR_D2S_MASK	_BITFIELD32B( 23, 0x3 ) /*403 only*/
#define PPC400_DBCR_D2S_IGN0LSB	_BITFIELD32B( 23, 0 )
#define PPC400_DBCR_D2S_IGN1LSB	_BITFIELD32B( 23, 1 )
#define PPC400_DBCR_D2S_IGN2LSB	_BITFIELD32B( 23, 2 )
#define PPC400_DBCR_D2S_IGN4LSB	_BITFIELD32B( 23, 3 )
#define PPC400_DBCR_SBT			_ONEBIT32B( 25 )		/*403 only*/
#define PPC400_DBCR_SED			_ONEBIT32B( 26 )		/*403 only*/
#define PPC400_DBCR_STD			_ONEBIT32B( 27 )		/*403 only*/
#define PPC400_DBCR_SIA			_ONEBIT32B( 28 )		/*403 only*/
#define PPC400_DBCR_SDA			_ONEBIT32B( 29 )		/*403 only*/
#define PPC400_DBCR_JOI			_ONEBIT32B( 30 )		/*403 only*/
#define PPC400_DBCR_JII			_ONEBIT32B( 31 )		/*403 only*/

/*
 * Debug Status Register
 */
#define PPC400_DBSR_IC			_ONEBIT32B( 0 )
#define PPC400_DBSR_BT			_ONEBIT32B( 1 )
#define PPC400_DBSR_EXC			_ONEBIT32B( 2 )
#define PPC400_DBSR_TIE			_ONEBIT32B( 3 )
#define PPC400_DBSR_UDE			_ONEBIT32B( 4 )
#define PPC400_DBSR_IA1			_ONEBIT32B( 5 )
#define PPC400_DBSR_IA2			_ONEBIT32B( 6 )		/*403,405 only*/
#define PPC400_DBSR_DR1			_ONEBIT32B( 7 )
#define PPC400_DBSR_DW1			_ONEBIT32B( 8 )
#define PPC400_DBSR_DR2			_ONEBIT32B( 9 )		/*403,405 only*/
#define PPC400_DBSR_DW2			_ONEBIT32B( 10 )	/*403,405 only*/
#define PPC400_DBSR_IDE			_ONEBIT32B( 11 )
#define PPC400_DBSR_IA3			_ONEBIT32B( 12 )	/*405 only*/
#define PPC400_DBSR_IA4			_ONEBIT32B( 13 )	/*405 only*/
#define PPC400_DBSR_MRR_MASK	_BITFIELD32B( 23, 0x3 )
#define PPC400_DBSR_MRR_NORESET	_BITFIELD32B( 23, 0 )
#define PPC400_DBSR_MRR_CORE	_BITFIELD32B( 23, 1 )
#define PPC400_DBSR_MRR_CHIP	_BITFIELD32B( 23, 2 )
#define PPC400_DBSR_MRR_SYSTEM	_BITFIELD32B( 23, 3 )
#define PPC400_DBSR_JIF			_ONEBIT32B( 29 )		/*403 only*/
#define PPC400_DBSR_JIO			_ONEBIT32B( 30 )		/*403 only*/
#define PPC400_DBSR_JOE			_ONEBIT32B( 31 )		/*403 only*/

/*
 * Data Cache Cacheability Register
 */
#define PPC400_DCCR_S0	_ONEBIT32B( 0 )
#define PPC400_DCCR_S1	_ONEBIT32B( 1 )
#define PPC400_DCCR_S2	_ONEBIT32B( 2 )
#define PPC400_DCCR_S3	_ONEBIT32B( 3 )
#define PPC400_DCCR_S4	_ONEBIT32B( 4 )
#define PPC400_DCCR_S5	_ONEBIT32B( 5 )
#define PPC400_DCCR_S6	_ONEBIT32B( 6 )
#define PPC400_DCCR_S7	_ONEBIT32B( 7 )
#define PPC400_DCCR_S8	_ONEBIT32B( 8 )
#define PPC400_DCCR_S9	_ONEBIT32B( 9 )
#define PPC400_DCCR_S10	_ONEBIT32B( 10 )
#define PPC400_DCCR_S11	_ONEBIT32B( 11 )
#define PPC400_DCCR_S12	_ONEBIT32B( 12 )
#define PPC400_DCCR_S13	_ONEBIT32B( 13 )
#define PPC400_DCCR_S14	_ONEBIT32B( 14 )
#define PPC400_DCCR_S15	_ONEBIT32B( 15 )
#define PPC400_DCCR_S16	_ONEBIT32B( 16 )
#define PPC400_DCCR_S17	_ONEBIT32B( 17 )
#define PPC400_DCCR_S18	_ONEBIT32B( 18 )
#define PPC400_DCCR_S19	_ONEBIT32B( 19 )
#define PPC400_DCCR_S20	_ONEBIT32B( 20 )
#define PPC400_DCCR_S21	_ONEBIT32B( 21 )
#define PPC400_DCCR_S22	_ONEBIT32B( 22 )
#define PPC400_DCCR_S23	_ONEBIT32B( 23 )
#define PPC400_DCCR_S24	_ONEBIT32B( 24 )
#define PPC400_DCCR_S25	_ONEBIT32B( 25 )
#define PPC400_DCCR_S26	_ONEBIT32B( 26 )
#define PPC400_DCCR_S27	_ONEBIT32B( 27 )
#define PPC400_DCCR_S28	_ONEBIT32B( 28 )
#define PPC400_DCCR_S29	_ONEBIT32B( 29 )
#define PPC400_DCCR_S30	_ONEBIT32B( 30 )
#define PPC400_DCCR_S31	_ONEBIT32B( 31 )

/*
 * Data Cache Write-thru Register
 */
#define PPC400_DCWR_S0	_ONEBIT32B( 0 )
#define PPC400_DCWR_S1	_ONEBIT32B( 1 )
#define PPC400_DCWR_S2	_ONEBIT32B( 2 )
#define PPC400_DCWR_S3	_ONEBIT32B( 3 )
#define PPC400_DCWR_S4	_ONEBIT32B( 4 )
#define PPC400_DCWR_S5	_ONEBIT32B( 5 )
#define PPC400_DCWR_S6	_ONEBIT32B( 6 )
#define PPC400_DCWR_S7	_ONEBIT32B( 7 )
#define PPC400_DCWR_S8	_ONEBIT32B( 8 )
#define PPC400_DCWR_S9	_ONEBIT32B( 9 )
#define PPC400_DCWR_S10	_ONEBIT32B( 10 )
#define PPC400_DCWR_S11	_ONEBIT32B( 11 )
#define PPC400_DCWR_S12	_ONEBIT32B( 12 )
#define PPC400_DCWR_S13	_ONEBIT32B( 13 )
#define PPC400_DCWR_S14	_ONEBIT32B( 14 )
#define PPC400_DCWR_S15	_ONEBIT32B( 15 )
#define PPC400_DCWR_S16	_ONEBIT32B( 16 )
#define PPC400_DCWR_S17	_ONEBIT32B( 17 )
#define PPC400_DCWR_S18	_ONEBIT32B( 18 )
#define PPC400_DCWR_S19	_ONEBIT32B( 19 )
#define PPC400_DCWR_S20	_ONEBIT32B( 20 )
#define PPC400_DCWR_S21	_ONEBIT32B( 21 )
#define PPC400_DCWR_S22	_ONEBIT32B( 22 )
#define PPC400_DCWR_S23	_ONEBIT32B( 23 )
#define PPC400_DCWR_S24	_ONEBIT32B( 24 )
#define PPC400_DCWR_S25	_ONEBIT32B( 25 )
#define PPC400_DCWR_S26	_ONEBIT32B( 26 )
#define PPC400_DCWR_S27	_ONEBIT32B( 27 )
#define PPC400_DCWR_S28	_ONEBIT32B( 28 )
#define PPC400_DCWR_S29	_ONEBIT32B( 29 )
#define PPC400_DCWR_S30	_ONEBIT32B( 30 )
#define PPC400_DCWR_S31	_ONEBIT32B( 31 )

/*
 * Exception Syndrome Register
 */
#define PPC403_ESR_IMCP	_ONEBIT32B( 0 )	/*403 only*/
#define PPC401_ESR_MCI	_ONEBIT32B( 0 )	/*401 only*/
#define PPC405_ESR_MCI	_ONEBIT32B( 0 )	/*405 only*/
#define PPC403_ESR_IMCN	_ONEBIT32B( 1 )	/*403 only*/
#define PPC403_ESR_IMCB	_ONEBIT32B( 2 )	/*403 only*/
#define PPC403_ESR_IMCT	_ONEBIT32B( 3 )	/*403 only*/
#define PPC400_ESR_PEI	_ONEBIT32B( 4 )
#define PPC400_ESR_PPR	_ONEBIT32B( 5 )
#define PPC400_ESR_PTR	_ONEBIT32B( 6 )
#define PPC400_ESR_PFE	_ONEBIT32B( 7 )
#define PPC400_ESR_DST	_ONEBIT32B( 8 )
#define PPC400_ESR_DIZ	_ONEBIT32B( 9 )
#define PPC400_ESR_PAU	_ONEBIT32B( 12 )
#define PPC400_ESR_PFP	_ONEBIT32B( 12 ) /*405 only*/
#define PPC400_ESR_PFEU _ONEBIT32B( 13 )
#define PPC400_ESR_PAE	_ONEBIT32B( 14 )
#define PPC400_ESR_E0F	_ONEBIT32B( 16 ) /*405 only*/

/*
 * Instruction Cache Cacheability Register
 */
#define PPC400_ICCR_S0	_ONEBIT32B( 0 )
#define PPC400_ICCR_S1	_ONEBIT32B( 1 )
#define PPC400_ICCR_S2	_ONEBIT32B( 2 )
#define PPC400_ICCR_S3	_ONEBIT32B( 3 )
#define PPC400_ICCR_S4	_ONEBIT32B( 4 )
#define PPC400_ICCR_S5	_ONEBIT32B( 5 )
#define PPC400_ICCR_S6	_ONEBIT32B( 6 )
#define PPC400_ICCR_S7	_ONEBIT32B( 7 )
#define PPC400_ICCR_S8	_ONEBIT32B( 8 )
#define PPC400_ICCR_S9	_ONEBIT32B( 9 )
#define PPC400_ICCR_S10	_ONEBIT32B( 10 )
#define PPC400_ICCR_S11	_ONEBIT32B( 11 )
#define PPC400_ICCR_S12	_ONEBIT32B( 12 )
#define PPC400_ICCR_S13	_ONEBIT32B( 13 )
#define PPC400_ICCR_S14	_ONEBIT32B( 14 )
#define PPC400_ICCR_S15	_ONEBIT32B( 15 )
#define PPC400_ICCR_S16	_ONEBIT32B( 16 )
#define PPC400_ICCR_S17	_ONEBIT32B( 17 )
#define PPC400_ICCR_S18	_ONEBIT32B( 18 )
#define PPC400_ICCR_S19	_ONEBIT32B( 19 )
#define PPC400_ICCR_S20	_ONEBIT32B( 20 )
#define PPC400_ICCR_S21	_ONEBIT32B( 21 )
#define PPC400_ICCR_S22	_ONEBIT32B( 22 )
#define PPC400_ICCR_S23	_ONEBIT32B( 23 )
#define PPC400_ICCR_S24	_ONEBIT32B( 24 )
#define PPC400_ICCR_S25	_ONEBIT32B( 25 )
#define PPC400_ICCR_S26	_ONEBIT32B( 26 )
#define PPC400_ICCR_S27	_ONEBIT32B( 27 )
#define PPC400_ICCR_S28	_ONEBIT32B( 28 )
#define PPC400_ICCR_S29	_ONEBIT32B( 29 )
#define PPC400_ICCR_S30	_ONEBIT32B( 30 )
#define PPC400_ICCR_S31	_ONEBIT32B( 31 )

/*
 * Storage Guarded Register
 */
#define PPC400_SGR_S0	_ONEBIT32B( 0 )
#define PPC400_SGR_S1	_ONEBIT32B( 1 )
#define PPC400_SGR_S2	_ONEBIT32B( 2 )
#define PPC400_SGR_S3	_ONEBIT32B( 3 )
#define PPC400_SGR_S4	_ONEBIT32B( 4 )
#define PPC400_SGR_S5	_ONEBIT32B( 5 )
#define PPC400_SGR_S6	_ONEBIT32B( 6 )
#define PPC400_SGR_S7	_ONEBIT32B( 7 )
#define PPC400_SGR_S8	_ONEBIT32B( 8 )
#define PPC400_SGR_S9	_ONEBIT32B( 9 )
#define PPC400_SGR_S10	_ONEBIT32B( 10 )
#define PPC400_SGR_S11	_ONEBIT32B( 11 )
#define PPC400_SGR_S12	_ONEBIT32B( 12 )
#define PPC400_SGR_S13	_ONEBIT32B( 13 )
#define PPC400_SGR_S14	_ONEBIT32B( 14 )
#define PPC400_SGR_S15	_ONEBIT32B( 15 )
#define PPC400_SGR_S16	_ONEBIT32B( 16 )
#define PPC400_SGR_S17	_ONEBIT32B( 17 )
#define PPC400_SGR_S18	_ONEBIT32B( 18 )
#define PPC400_SGR_S19	_ONEBIT32B( 19 )
#define PPC400_SGR_S20	_ONEBIT32B( 20 )
#define PPC400_SGR_S21	_ONEBIT32B( 21 )
#define PPC400_SGR_S22	_ONEBIT32B( 22 )
#define PPC400_SGR_S23	_ONEBIT32B( 23 )
#define PPC400_SGR_S24	_ONEBIT32B( 24 )
#define PPC400_SGR_S25	_ONEBIT32B( 25 )
#define PPC400_SGR_S26	_ONEBIT32B( 26 )
#define PPC400_SGR_S27	_ONEBIT32B( 27 )
#define PPC400_SGR_S28	_ONEBIT32B( 28 )
#define PPC400_SGR_S29	_ONEBIT32B( 29 )
#define PPC400_SGR_S30	_ONEBIT32B( 30 )
#define PPC400_SGR_S31	_ONEBIT32B( 31 )

/*
 * Storage Little Endian Register (not present on 403)
 */
#define PPC400_SLER_S0				_ONEBIT32B( 0 )
#define PPC400_SLER_S1				_ONEBIT32B( 1 )
#define PPC400_SLER_S2				_ONEBIT32B( 2 )
#define PPC400_SLER_S3				_ONEBIT32B( 3 )
#define PPC400_SLER_S4				_ONEBIT32B( 4 )
#define PPC400_SLER_S5				_ONEBIT32B( 5 )
#define PPC400_SLER_S6				_ONEBIT32B( 6 )
#define PPC400_SLER_S7				_ONEBIT32B( 7 )
#define PPC400_SLER_S8				_ONEBIT32B( 8 )
#define PPC400_SLER_S9				_ONEBIT32B( 9 )
#define PPC400_SLER_S10				_ONEBIT32B( 10 )
#define PPC400_SLER_S11				_ONEBIT32B( 11 )
#define PPC400_SLER_S12				_ONEBIT32B( 12 )
#define PPC400_SLER_S13				_ONEBIT32B( 13 )
#define PPC400_SLER_S14				_ONEBIT32B( 14 )
#define PPC400_SLER_S15				_ONEBIT32B( 15 )
#define PPC400_SLER_S16				_ONEBIT32B( 16 )
#define PPC400_SLER_S17				_ONEBIT32B( 17 )
#define PPC400_SLER_S18				_ONEBIT32B( 18 )
#define PPC400_SLER_S19				_ONEBIT32B( 19 )
#define PPC400_SLER_S20				_ONEBIT32B( 20 )
#define PPC400_SLER_S21				_ONEBIT32B( 21 )
#define PPC400_SLER_S22				_ONEBIT32B( 22 )
#define PPC400_SLER_S23				_ONEBIT32B( 23 )
#define PPC401_SLER_S24				_ONEBIT32B( 24 )
#define PPC401_SLER_S25				_ONEBIT32B( 25 )
#define PPC401_SLER_S26				_ONEBIT32B( 26 )
#define PPC401_SLER_S27				_ONEBIT32B( 27 )
#define PPC401_SLER_S28				_ONEBIT32B( 28 )
#define PPC401_SLER_S29				_ONEBIT32B( 29 )
#define PPC401_SLER_S30				_ONEBIT32B( 30 )
#define PPC401_SLER_S31				_ONEBIT32B( 31 )

/*
 * Storage Memory-coherent Register
 */
#define PPC400_SMR_S0	_ONEBIT32B( 0 )
#define PPC400_SMR_S1	_ONEBIT32B( 1 )
#define PPC400_SMR_S2	_ONEBIT32B( 2 )
#define PPC400_SMR_S3	_ONEBIT32B( 3 )
#define PPC400_SMR_S4	_ONEBIT32B( 4 )
#define PPC400_SMR_S5	_ONEBIT32B( 5 )
#define PPC400_SMR_S6	_ONEBIT32B( 6 )
#define PPC400_SMR_S7	_ONEBIT32B( 7 )
#define PPC400_SMR_S8	_ONEBIT32B( 8 )
#define PPC400_SMR_S9	_ONEBIT32B( 9 )
#define PPC400_SMR_S10	_ONEBIT32B( 10 )
#define PPC400_SMR_S11	_ONEBIT32B( 11 )
#define PPC400_SMR_S12	_ONEBIT32B( 12 )
#define PPC400_SMR_S13	_ONEBIT32B( 13 )
#define PPC400_SMR_S14	_ONEBIT32B( 14 )
#define PPC400_SMR_S15	_ONEBIT32B( 15 )
#define PPC400_SMR_S16	_ONEBIT32B( 16 )
#define PPC400_SMR_S17	_ONEBIT32B( 17 )
#define PPC400_SMR_S18	_ONEBIT32B( 18 )
#define PPC400_SMR_S19	_ONEBIT32B( 19 )
#define PPC400_SMR_S20	_ONEBIT32B( 20 )
#define PPC400_SMR_S21	_ONEBIT32B( 21 )
#define PPC400_SMR_S22	_ONEBIT32B( 22 )
#define PPC400_SMR_S23	_ONEBIT32B( 23 )
#define PPC400_SMR_S24	_ONEBIT32B( 24 )
#define PPC400_SMR_S25	_ONEBIT32B( 25 )
#define PPC400_SMR_S26	_ONEBIT32B( 26 )
#define PPC400_SMR_S27	_ONEBIT32B( 27 )
#define PPC400_SMR_S28	_ONEBIT32B( 28 )
#define PPC400_SMR_S29	_ONEBIT32B( 29 )
#define PPC400_SMR_S30	_ONEBIT32B( 30 )
#define PPC400_SMR_S31	_ONEBIT32B( 31 )

/*
 * Timer Control Register
 */
#define PPC400_TCR_WP_MASK			_BITFIELD32B( 1, 3 )
#define PPC400_TCR_WP_2P17			_BITFIELD32B( 1, 0 )
#define PPC400_TCR_WP_2P21			_BITFIELD32B( 1, 1 )
#define PPC400_TCR_WP_2P25			_BITFIELD32B( 1, 2 )
#define PPC400_TCR_WP_2P29			_BITFIELD32B( 1, 3 )
#define PPC400_TCR_WRC_MASK			_BITFIELD32B( 3, 3 )
#define PPC400_TCR_WRC_NORESET		_BITFIELD32B( 3, 0 )
#define PPC400_TCR_WRC_CORERESET	_BITFIELD32B( 3, 1 )
#define PPC400_TCR_WRC_CHIPRESET	_BITFIELD32B( 3, 2 )
#define PPC400_TCR_WRC_SYSTEMRESET	_BITFIELD32B( 3, 3 )
#define PPC400_TCR_WIE				_ONEBIT32B( 4 )
#define PPC400_TCR_PIE				_ONEBIT32B( 5 )
#define PPC400_TCR_FP_MASK			_BITFIELD32B( 7, 3 )
#define PPC400_TCR_FP_2P9			_BITFIELD32B( 7, 0 )
#define PPC400_TCR_FP_2P13			_BITFIELD32B( 7, 1 )
#define PPC400_TCR_FP_2P17			_BITFIELD32B( 7, 2 )
#define PPC400_TCR_FP_2P21			_BITFIELD32B( 7, 3 )
#define PPC400_TCR_FIE				_ONEBIT32B( 8 )
#define PPC400_TCR_ARE				_ONEBIT32B( 9 ) /*Note: ARE is buggy on some chips*/

/*
 * Timer Status Register
 */
#define PPC400_TSR_ENW				_ONEBIT32B( 0 )
#define PPC400_TSR_WIS				_ONEBIT32B( 1 )
#define PPC400_TSR_WRS_MASK			_BITFIELD32B( 3, 3 )
#define PPC400_TSR_WRS_NORESET		_BITFIELD32B( 3, 0 )
#define PPC400_TSR_WRS_CORERESET	_BITFIELD32B( 3, 1 )
#define PPC400_TSR_WRS_CHIPRESET	_BITFIELD32B( 3, 2 )
#define PPC400_TSR_WRS_SYSTEMRESET	_BITFIELD32B( 3, 3 )
#define PPC400_TSR_PIS				_ONEBIT32B( 4 )
#define PPC400_TSR_FIS				_ONEBIT32B( 5 )

/*
 * TLB high bits (tag entry)
 */
#define PPC400_TLBHI_EPN_MASK			_BITFIELD32B(21, 0x3fffff)
#define PPC400_TLBHI_EPN_SHIFT			(31-21)
#define PPC400_TLBHI_SIZE_MASK			_BITFIELD32B(24, 0x7)
#define PPC400_TLBHI_SIZE_1K			_BITFIELD32B(24, 0x0)
#define PPC400_TLBHI_SIZE_4K			_BITFIELD32B(24, 0x1)
#define PPC400_TLBHI_SIZE_16K			_BITFIELD32B(24, 0x2)
#define PPC400_TLBHI_SIZE_64K			_BITFIELD32B(24, 0x3)
#define PPC400_TLBHI_SIZE_256K			_BITFIELD32B(24, 0x4)
#define PPC400_TLBHI_SIZE_1M			_BITFIELD32B(24, 0x5)
#define PPC400_TLBHI_SIZE_4M			_BITFIELD32B(24, 0x6)
#define PPC400_TLBHI_SIZE_16M			_BITFIELD32B(24, 0x7)
#define PPC400_TLBHI_VALID				_ONEBIT32B(25)
#define PPC400_TLBHI_E					_ONEBIT32B(26) /*405 only*/
#define PPC400_TLBHI_U0					_ONEBIT32B(27) /*405 only*/

/*
 * TLB low bits (data entry)
 */
#define PPC400_TLBLO_RPN_MASK			_BITFIELD32B(21, 0x3fffff)
#define PPC400_TLBLO_RPN_SHIFT			(31-21)
#define PPC400_TLBLO_EX					_ONEBIT32B(22)
#define PPC400_TLBLO_WR					_ONEBIT32B(23)
#define PPC400_TLBLO_ZONE_MASK			_BITFIELD32B(27, 0xf)
#define PPC400_TLBLO_ZONE_SHIFT			(31-27)
#define PPC400_TLBLO_W					_ONEBIT32B(28)
#define PPC400_TLBLO_I					_ONEBIT32B(29)
#define PPC400_TLBLO_M					_ONEBIT32B(30)
#define PPC400_TLBLO_G					_ONEBIT32B(31)

/*
 * Zone Protection Register (VM chips only)
 */
#define PPC400_ZPR_Zx_MASK(z)		_BITFIELD32B(((z)*2)+1, 3)
#define PPC400_ZPR_Zx_PNSG(z)		_BITFIELD32B(((z)*2)+1, 0)
#define PPC400_ZPR_Zx_PGSG(z)		_BITFIELD32B(((z)*2)+1, 1)
#define PPC400_ZPR_Zx_PGSS(z)		_BITFIELD32B(((z)*2)+1, 2)
#define PPC400_ZPR_Zx_PSSS(z)		_BITFIELD32B(((z)*2)+1, 3)

/*
 * SPR numbers
 */
#define PPC400_SPR_DAC1		0x3f6
#define PPC400_SPR_DBCR		0x3f2
#define PPC400_SPR_DBSR		0x3f0
#define PPC400_SPR_DCCR		0x3fa
#define PPC400_SPR_DCWR		0x3ba
#define PPC400_SPR_DEAR		0x3d5
#define PPC400_SPR_ESR	 	0x3d4
#define PPC400_SPR_EVPR		0x3d6
#define PPC400_SPR_IAC1		0x3f4
#define PPC400_SPR_ICCR		0x3fb
#define PPC400_SPR_PID		0x3b1
#define PPC400_SPR_PIT	 	0x3db
#define PPC400_SPR_SGR	 	0x3b9
#define PPC400_SPR_SRR0		0x01a
#define PPC400_SPR_SRR1		0x01b
#define PPC400_SPR_SRR2		0x3de
#define PPC400_SPR_SRR3		0x3df
#define PPC400_SPR_TBHI	 	0x3dc
#define PPC400_SPR_TBLO	 	0x3dd
#define PPC400_SPR_TCR	 	0x3da
#define PPC400_SPR_TSR		0x3d8
#define PPC400_SPR_ZPR		0x3b0

/*
 * Exception table vectors
 */
#define PPC400_EXC_PIT			(0x1000/sizeof(uint32_t)) 
#define PPC400_EXC_FIT			(0x1010/sizeof(uint32_t)) 
#define PPC400_EXC_WATCHDOG		(0x1020/sizeof(uint32_t)) 
#define PPC400_EXC_DTLB_MISS	(0x1100/sizeof(uint32_t)) 
#define PPC400_EXC_ITLB_MISS	(0x1200/sizeof(uint32_t)) 
#define PPC400_EXC_DEBUG		(0x2000/sizeof(uint32_t)) 

#endif


__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/SP1/services/system/public/ppc/400cpu.h $ $Rev: 219613 $" )
