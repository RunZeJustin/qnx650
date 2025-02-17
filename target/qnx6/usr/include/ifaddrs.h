/*	$NetBSD: ifaddrs.h,v 1.5 2005/02/03 04:39:32 perry Exp $	*/

/*
 * Copyright (c) 1995, 1999
 *	Berkeley Software Design, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * THIS SOFTWARE IS PROVIDED BY Berkeley Software Design, Inc. ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL Berkeley Software Design, Inc. BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	BSDI ifaddrs.h,v 2.5 2000/02/23 14:51:59 dab Exp
 */

#ifndef	_IFADDRS_H_INCLUDED
#define	_IFADDRS_H_INCLUDED

#ifndef __TYPES_H_INCLUDED
#include <sys/types.h>
#endif

struct ifaddrs {
	struct ifaddrs  *ifa_next;
	char		*ifa_name;
	u_int		 ifa_flags;
	struct sockaddr	*ifa_addr;
	struct sockaddr	*ifa_netmask;
	struct sockaddr	*ifa_dstaddr;
	void		*ifa_data;
};

/*
 * This may have been defined in <net/if.h>.  Note that if <net/if.h> is
 * to be included it must be included before this header file.
 */
#ifndef	ifa_broadaddr
#define	ifa_broadaddr	ifa_dstaddr	/* broadcast address interface */
#endif

#include <sys/cdefs.h>

__BEGIN_DECLS
int getifaddrs(struct ifaddrs **);
void freeifaddrs(struct ifaddrs *);
__END_DECLS

#endif /* !_IFADDRS_H_INCLUDED */

__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/SP1/lib/socket/public/ifaddrs.h $ $Rev: 233581 $" )
