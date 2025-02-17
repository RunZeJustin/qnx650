/*	$NetBSD: if_dl.h,v 1.18 2005/12/11 23:05:24 thorpej Exp $	*/

/*
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)if_dl.h	8.1 (Berkeley) 6/10/93
 */

/*
 * A Link-Level Sockaddr may specify the interface in one of two
 * ways: either by means of a system-provided index number (computed
 * anew and possibly differently on every reboot), or by a human-readable
 * string such as "il0" (for managerial convenience).
 *
 * Census taking actions, such as something akin to SIOCGCONF would return
 * both the index and the human name.
 *
 * High volume transactions (such as giving a link-level ``from'' address
 * in a recvfrom or recvmsg call) may be likely only to provide the indexed
 * form, (which requires fewer copy operations and less space).
 *
 * The form and interpretation  of the link-level address is purely a matter
 * of convention between the device driver and its consumers; however, it is
 * expected that all drivers for an interface of a given if_type will agree.
 */

#ifndef _NET_IF_DL_H_INCLUDED
#define _NET_IF_DL_H_INCLUDED

#ifndef __PLATFORM_H_INCLUDED
#include <sys/platform.h>
#endif

#ifndef __TYPES_H_INCLUDED
#include <sys/types.h>
#endif

#ifndef _STDINT_H_INCLUDED
#include <stdint.h>
#endif

#if defined(__SA_FAMILY_T)
typedef __SA_FAMILY_T sa_family_t;
#undef __SA_FAMILY_T
#endif

/*
 * Structure of a Link-Level sockaddr:
 */
struct sockaddr_dl {
	u_char	    sdl_len;	/* Total length of sockaddr */
	sa_family_t sdl_family;	/* AF_LINK */
	uint16_t   sdl_index;	/* if != 0, system given index for interface */
	u_char	    sdl_type;	/* interface type */
	u_char	    sdl_nlen;	/* interface name length, no trailing 0 reqd. */
	u_char	    sdl_alen;	/* link level address length */
	u_char	    sdl_slen;	/* link layer selector length */
	char	    sdl_data[12]; /* minimum work area, can be larger;
				     contains both if name and ll address */
};

#define	satosdl(__sa)	((struct sockaddr_dl *)(__sa))
#define	satocsdl(__sa)	((const struct sockaddr_dl *)(__sa))

/* We do arithmetic directly with these, so keep them char instead of void */
#define LLADDR(s) ((char *)((s)->sdl_data + (s)->sdl_nlen))
#define CLLADDR(s) ((const char *)((s)->sdl_data + (s)->sdl_nlen))

#ifdef _KERNEL
uint8_t sockaddr_dl_measure(uint8_t, uint8_t);
struct sockaddr *sockaddr_dl_alloc(uint16_t, uint8_t,
    const void *, uint8_t, const void *, uint8_t, int);
struct sockaddr_dl *sockaddr_dl_init(struct sockaddr_dl *, socklen_t, uint16_t,
    uint8_t, const void *, uint8_t, const void *, uint8_t);
struct sockaddr_dl *sockaddr_dl_setaddr(struct sockaddr_dl *, socklen_t,
    const void *, uint8_t);
#else

#include <sys/cdefs.h>

__BEGIN_DECLS
void	link_addr(const char *, struct sockaddr_dl *);
char	*link_ntoa(const struct sockaddr_dl *);
__END_DECLS

#endif /* !_KERNEL */

#endif /* !_NET_IF_DL_H_INCLUDED */

__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/SP1/lib/socket/public/net/if_dl.h $ $Rev: 233581 $" )
