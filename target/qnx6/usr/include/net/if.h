/*
 * $QNXtpLicenseC:
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



/*	$NetBSD: if.h,v 1.121 2006/11/23 19:41:58 yamt Exp $	*/

/*-
 * Copyright (c) 1999, 2000, 2001 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by William Studenmund and Jason R. Thorpe.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the NetBSD
 *	Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Copyright (c) 1982, 1986, 1989, 1993
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
 *	@(#)if.h	8.3 (Berkeley) 2/9/95
 */

#ifndef _NET_IF_H_INCLUDED
#define _NET_IF_H_INCLUDED

#ifndef __PLATFORM_H_INCLUDED
#include <sys/platform.h>
#endif


/*
 * Length of interface external name, including terminating '\0'.
 * Note: this is the same size as a generic device's external name.
 */
#define IF_NAMESIZE 16

#if defined(__EXT_BSD)

#ifndef _STDINT_H_INCLUDED
#include <stdint.h>
#endif

#ifndef __TYPES_H_INCLUDED
#include <sys/types.h>
#endif

#ifndef __QUEUE_H_INCLUDED
#include <sys/queue.h>
#endif

#ifndef _NET_DLT_H_INCLUDED
#include <net/dlt.h>
#endif

#ifndef _NET_PFIL_H_INCLUDED
#include <net/pfil.h>
#endif

#ifndef _NET_CACHELINE_H_INCLUDED
#include <net/cacheline.h>
#endif

#ifndef __SOCKET_H_INCLUDED
#include <sys/socket.h>
#endif

#ifndef _PTHREAD_H_INCLUDED
#include <pthread.h>
#endif

/*
 * Always include ALTQ glue here -- we use the ALTQ interface queue
 * structure even when ALTQ is not configured into the kernel so that
 * the size of struct ifnet does not changed based on the option.  The
 * ALTQ queue structure is API-compatible with the legacy ifqueue.
 */
#ifndef _ALTQ_IF_ALTQ_H_INCLUDED
#include <altq/if_altq.h>
#endif

/*
 * Structures defining a network interface, providing a packet
 * transport mechanism (ala level 0 of the PUP protocols).
 *
 * Each interface accepts output datagrams of a specified maximum
 * length, and provides higher level routines with input datagrams
 * received from its medium.
 *
 * Output occurs when the routine if_output is called, with four parameters:
 *	(*ifp->if_output)(ifp, m, dst, rt)
 * Here m is the mbuf chain to be sent and dst is the destination address.
 * The output routine encapsulates the supplied datagram if necessary,
 * and then transmits it on its medium.
 *
 * On input, each interface unwraps the data received by it, and either
 * places it on the input queue of a internetwork datagram routine
 * and posts the associated software interrupt, or passes the datagram to a raw
 * packet input routine.
 *
 * Routines exist for locating interfaces by their addresses
 * or for locating a interface on a certain network, as well as more general
 * routing and gateway routines maintaining information used to locate
 * interfaces.  These routines live in the files if.c and route.c
 */
/*  XXX fast fix for SNMP, going away soon */
#ifndef __TIME_H_INCLUDED
#include <sys/time.h>
#endif

#if defined(_KERNEL_OPT)
#include "opt_compat_netbsd.h"
#endif

struct mbuf;
struct proc;
struct rtentry;
struct socket;
struct ether_header;
struct ifaddr;
struct ifnet;
struct rt_addrinfo;
#ifdef __QNXNTO__
struct stk_context_callback;
#endif

#define	IFNAMSIZ	IF_NAMESIZE

/*
 * Structure describing a `cloning' interface.
 */
struct if_clone {
	LIST_ENTRY(if_clone) ifc_list;	/* on list of cloners */
	const char *ifc_name;		/* name of device, e.g. `gif' */
	size_t ifc_namelen;		/* length of name */

	int	(*ifc_create)(struct if_clone *, int);
	int	(*ifc_destroy)(struct ifnet *);
};

#define	IF_CLONE_INITIALIZER(name, create, destroy)			\
	{ { NULL, NULL }, name, sizeof(name) - 1, create, destroy }

/*
 * Structure used to query names of interface cloners.
 */
struct if_clonereq {
	int	ifcr_total;		/* total cloners (out) */
	int	ifcr_count;		/* room for this many in user buffer */
	char	*ifcr_buffer;		/* buffer for cloner names */
};

/*
 * Structure defining statistics and other data kept regarding a network
 * interface.
 */
struct if_data {
	/* generic interface information */
	unsigned char	ifi_type;		/* ethernet, tokenring, etc. */
	unsigned char	ifi_addrlen;		/* media address length */
	unsigned char	ifi_hdrlen;		/* media header length */
	int	ifi_link_state;		/* current link state */
	uint64_t ifi_mtu;		/* maximum transmission unit */
	uint64_t ifi_metric;		/* routing metric (external only) */
	uint64_t ifi_baudrate;		/* linespeed */
	/* volatile statistics */
	uint64_t ifi_ipackets;		/* packets received on interface */
	uint64_t ifi_ierrors;		/* input errors on interface */
	uint64_t ifi_opackets;		/* packets sent on interface */
	uint64_t ifi_oerrors;		/* output errors on interface */
	uint64_t ifi_collisions;	/* collisions on csma interfaces */
	uint64_t ifi_ibytes;		/* total number of octets received */
	uint64_t ifi_obytes;		/* total number of octets sent */
	uint64_t ifi_imcasts;		/* packets received via multicast */
	uint64_t ifi_omcasts;		/* packets sent via multicast */
	uint64_t ifi_iqdrops;		/* dropped on input, this interface */
	uint64_t ifi_noproto;		/* destined for unsupported protocol */
	struct	timeval ifi_lastchange;	/* last operational state change */
#ifdef __QNXNTO__
/*
 * If you add something to struct if_data, make 
 * sure you touch struct ifnet, if_data_gather() 
 * and possibly if_volatile_clr as well.
 */
#endif
};

/*
 * Values for if_link_state.
 */
#define	LINK_STATE_UNKNOWN	0	/* link invalid/unknown */
#define	LINK_STATE_DOWN		1	/* link is down */
#define	LINK_STATE_UP		2	/* link is up */

#if defined(_KERNEL) && defined(COMPAT_14)
/* Pre-1.5 if_data struct */
struct if_data14 {
	/* generic interface information */
	unsigned char	ifi_type;	/* ethernet, tokenring, etc. */
	unsigned char	ifi_addrlen;	/* media address length */
	unsigned char	ifi_hdrlen;	/* media header length */
	unsigned long	ifi_mtu;	/* maximum transmission unit */
	unsigned long	ifi_metric;	/* routing metric (external only) */
	unsigned long	ifi_baudrate;	/* linespeed */
	/* volatile statistics */
	unsigned long	ifi_ipackets;	/* packets received on interface */
	unsigned long	ifi_ierrors;	/* input errors on interface */
	unsigned long	ifi_opackets;	/* packets sent on interface */
	unsigned long	ifi_oerrors;	/* output errors on interface */
	unsigned long	ifi_collisions;	/* collisions on csma interfaces */
	unsigned long	ifi_ibytes;	/* total number of octets received */
	unsigned long	ifi_obytes;	/* total number of octets sent */
	unsigned long	ifi_imcasts;	/* packets received via multicast */
	unsigned long	ifi_omcasts;	/* packets sent via multicast */
	unsigned long	ifi_iqdrops;	/* dropped on input, this interface */
	unsigned long	ifi_noproto;	/* destined for unsupported protocol */
	struct	timeval ifi_lastchange;	/* last operational state change */
};
#endif /* _KERNEL && COMPAT_14 */

/*
 * Structure defining a queue for a network interface.
 */
struct ifqueue {
	struct	mbuf *ifq_head;
	struct	mbuf *ifq_tail;
	int	ifq_len;
	int	ifq_maxlen;
	int	ifq_drops;
#ifdef __QNXNTO__
	void	(*ifq_intr)(void *);
	struct	ifqueue *ifq_next;
	struct	ifqueue **ifq_prev;
	void *	(*ifq_dequeue)(struct ifqueue *);
#endif
};

/*
 * Structure defining a queue for a network interface.
 *
 * (Would like to call this struct ``if'', but C isn't PL/1.)
 */
TAILQ_HEAD(ifnet_head, ifnet);		/* the actual queue head */

#ifndef __QNXNTO__
struct ifnet {				/* and the entries */
	void	*if_softc;		/* lower-level data for this if */
	TAILQ_ENTRY(ifnet) if_list;	/* all struct ifnets are chained */
	TAILQ_HEAD(, ifaddr) if_addrlist; /* linked list of addresses per if */
	char	if_xname[IFNAMSIZ];	/* external name (name + unit) */
	int	if_pcount;		/* number of promiscuous listeners */
	caddr_t	if_bpf;			/* packet filter structure */
	u_short	if_index;		/* numeric abbreviation for this if */
	short	if_timer;		/* time 'til if_watchdog called */
	short	if_flags;		/* up/down, broadcast, etc. */
	short	if__pad1;		/* be nice to m68k ports */
	struct	if_data if_data;	/* statistics and other data about if */
	/*
	 * Procedure handles.  If you add more of these, don't forget the
	 * corresponding NULL stub in if.c.
	 */
	int	(*if_output)		/* output routine (enqueue) */
		    (struct ifnet *, struct mbuf *, struct sockaddr *,
		     struct rtentry *);
	void	(*if_input)		/* input routine (from h/w driver) */
		    (struct ifnet *, struct mbuf *);
	void	(*if_start)		/* initiate output routine */
		    (struct ifnet *);
	int	(*if_ioctl)		/* ioctl routine */
		    (struct ifnet *, u_long, caddr_t);
	int	(*if_init)		/* init routine */
		    (struct ifnet *);
	void	(*if_stop)		/* stop routine */
		    (struct ifnet *, int);
	void	(*if_watchdog)		/* timer routine */
		    (struct ifnet *);
	void	(*if_drain)		/* routine to release resources */
		    (struct ifnet *);
	struct ifaltq if_snd;		/* output queue (includes altq) */
	struct ifaddr	*if_dl;		/* identity of this interface. */
	const struct	sockaddr_dl *if_sadl;	/* pointer to our sockaddr_dl */
	const uint8_t *if_broadcastaddr;/* linklevel broadcast bytestring */
	void	*if_bridge;		/* bridge glue */
	int	if_dlt;			/* data link type (<net/dlt.h>) */
	struct pfil_head if_pfil;	/* filtering point */
	uint64_t if_capabilities;	/* interface capabilities */
	uint64_t if_capenable;		/* capabilities enabled */
	union {
		caddr_t		carp_s;	/* carp structure (used by !carp ifs) */
		struct ifnet	*carp_d;/* ptr to carpdev (used by carp ifs) */
	} if_carp_ptr;
#define if_carp		if_carp_ptr.carp_s
#define if_carpdev	if_carp_ptr.carp_d
	/*
	 * These are pre-computed based on an interfaces enabled
	 * capabilities, for speed elsewhere.
	 */
	int	if_csum_flags_tx;	/* M_CSUM_* flags for Tx */
	int	if_csum_flags_rx;	/* M_CSUM_* flags for Rx */

	void	*if_afdata[AF_MAX];
	struct	mowner *if_mowner;	/* who owns mbufs for this interface */

	void	*if_agrprivate;		/* used only when #if NAGR > 0 */
};
#define	if_mtu		if_data.ifi_mtu
#define	if_type		if_data.ifi_type
#define	if_addrlen	if_data.ifi_addrlen
#define	if_hdrlen	if_data.ifi_hdrlen
#define	if_metric	if_data.ifi_metric
#define	if_link_state	if_data.ifi_link_state
#define	if_baudrate	if_data.ifi_baudrate
#define	if_ipackets	if_data.ifi_ipackets
#define	if_ierrors	if_data.ifi_ierrors
#define	if_opackets	if_data.ifi_opackets
#define	if_oerrors	if_data.ifi_oerrors
#define	if_collisions	if_data.ifi_collisions
#define	if_ibytes	if_data.ifi_ibytes
#define	if_obytes	if_data.ifi_obytes
#define	if_imcasts	if_data.ifi_imcasts
#define	if_omcasts	if_data.ifi_omcasts
#define	if_iqdrops	if_data.ifi_iqdrops
#define	if_noproto	if_data.ifi_noproto
#define	if_lastchange	if_data.ifi_lastchange
#else
/*
 * Similiar to above but we try to keep things
 * that are obviously tx / rx related grouped
 * together.  We also use an unsigned for time
 * to aid atomicity.
 */
struct ifnet {				/* and the entries */

	/* General entries */

	void			*if_softc;		/* lower-level data for this if */
	TAILQ_ENTRY(ifnet)	if_list;		/* all struct ifnets are chained */
	TAILQ_HEAD(, ifaddr)	if_addrlist;		 /* linked list of addresses per if */
	char			if_xname[IFNAMSIZ];	/* external name (name + unit) */
	int			if_pcount;		/* number of promiscuous listeners */
	caddr_t			if_bpf;			/* packet filter structure */
	unsigned short		if_index;		/* numeric abbreviation for this if */
	short			if__pad1;		/* be nice to m68k ports */
	int			if_flags;		/* up/down, broadcast, etc. */

	int			(*if_ioctl)		/* ioctl routine */
				    (struct ifnet *, unsigned long, caddr_t);
	int			(*if_init)		/* init routine */
				    (struct ifnet *);
	void			(*if_stop)		/* stop routine */
				    (struct ifnet *, int);
	void			(*if_watchdog)		/* timer routine */
				    (struct ifnet *);
	void			(*if_drain)		/* routine to release resources */
				    (struct ifnet *);

	struct ifaddr		*if_dl;			/* identity of this interface. */
	const struct sockaddr_dl *if_sadl;		/* pointer to our sockaddr_dl */
	const uint8_t		*if_broadcastaddr;	/* linklevel broadcast bytestring */
	int			if_dlt;			/* data link type (<net/dlt.h>) */
	struct pfil_head	 if_pfil;		/* filtering point */
	void			*if_afdata[AF_MAX];
	void			*if_afdata_res[3];	/* future: in case AF_MAX is ever increased */
	struct mowner		*if_mowner;		/* who owns mbufs for this interface */
	unsigned char		if_type;		/* ethernet, tokenring, etc. */
	unsigned char		if_addrlen;		/* media address length */
	unsigned char		if_hdrlen;		/* media header length */
	int			if_link_state;		/* current link state */
	uint64_t		if_mtu;			/* maximum transmission unit */
	uint64_t		if_metric;		/* routing metric (external only) */
	uint64_t		if_baudrate;		/* linespeed */
	struct timeval		if_lastchange;		/* last operational state change */
	void			*if_agrprivate;		/* used only when #if NAGR > 0 */
	union {
		caddr_t		carp_s;	/* carp structure (used by !carp ifs) */
		struct ifnet	*carp_d;/* ptr to carpdev (used by carp ifs) */
	} if_carp_ptr;
	void			*if_gen_res[4];		/* future */
#define if_carp		if_carp_ptr.carp_s
#define if_carpdev	if_carp_ptr.carp_d





	/* TX entries */
	int			(*if_output)		/* output routine (enqueue) */
				    (struct ifnet *, struct mbuf *, struct sockaddr *,
				    struct rtentry *) __attribute__((aligned (NET_CACHELINE_SIZE)));
	void			(*if_start)		/* initiate output routine */
				    (struct ifnet *);
	int			if_csum_flags_tx;	/* M_CSUM_* flags for Tx */
	void			*if_bridge_tx;		/* bridge glue */
	unsigned		if_timer;
	uint64_t		if_capabilities_tx;	/* interface capabilities (tx) */
	uint64_t		if_capenable_tx;	/* capabilities enabled (tx) */

	uint64_t		if_opackets;		/* packets sent on interface */
	uint64_t		if_oerrors;		/* output errors on interface */
	uint64_t		if_obytes;		/* total number of octets sent */
	uint64_t		if_omcasts;		/* packets sent via multicast */
	uint64_t		if_collisions;		/* collisions on csma interfaces */

	pthread_mutex_t		if_snd_ex;
	struct ifaltq		if_snd;			/* output queue (includes altq) */
	int			if_flags_tx;		/* As above but protected by the mutex */
	void			*if_tx_res[4];		/* future */




	/* RX entries */
	void			(*if_input)		/* input routine (from h/w driver) */
				    (struct ifnet *, struct mbuf *) __attribute__((aligned (NET_CACHELINE_SIZE)));
	uint64_t		if_capabilities_rx;	/* interface capabilities (rx) */
	uint64_t		if_capenable_rx;	/* capabilities enabled (rx) */
	int			if_csum_flags_rx;	/* M_CSUM_* flags for Rx */
	void			*if_bridge_rx;		/* bridge glue */

	uint64_t		if_ipackets;		/* packets received on interface */
	uint64_t		if_ierrors;		/* input errors on interface */
	uint64_t		if_ibytes;		/* total number of octets received */
	uint64_t		if_imcasts;		/* packets received via multicast */
	uint64_t		if_iqdrops;		/* dropped on input, this interface */
	uint64_t		if_noproto;		/* destined for unsupported protocol */
	void			*if_rx_res[4];		/* future */

} __attribute__((aligned (NET_CACHELINE_SIZE)));
#endif

#define	IFF_UP		0x00000001	/* interface is up */
#define	IFF_BROADCAST	0x00000002	/* broadcast address valid */
#define	IFF_DEBUG	0x00000004	/* turn on debugging */
#define	IFF_LOOPBACK	0x00000008	/* is a loopback net */
#define	IFF_POINTOPOINT	0x00000010	/* interface is point-to-point link */
#define	IFF_NOTRAILERS	0x00000020	/* avoid use of trailers */
#define	IFF_RUNNING	0x00000040	/* resources allocated */
#define	IFF_NOARP	0x00000080	/* no address resolution protocol */
#define	IFF_PROMISC	0x00000100	/* receive all packets */
#define	IFF_ALLMULTI	0x00000200	/* receive all multicast packets */
#define	IFF_OACTIVE	0x00000400	/* transmission in progress */
#define	IFF_SIMPLEX	0x00000800	/* can't hear own transmissions */
#define	IFF_LINK0	0x00001000	/* per link layer defined bit */
#define	IFF_LINK1	0x00002000	/* per link layer defined bit */
#define	IFF_LINK2	0x00004000	/* per link layer defined bit */
#define	IFF_MULTICAST	0x00008000	/* supports multicast */
#define	IFF_SHIM	0x80000000	/* io-net2 shim interface */

#define	IFFBITS \
    "\020\1UP\2BROADCAST\3DEBUG\4LOOPBACK\5POINTOPOINT\6NOTRAILERS" \
    "\7RUNNING\10NOARP\11PROMISC\12ALLMULTI\13OACTIVE\14SIMPLEX" \
    "\15LINK0\16LINK1\17LINK2\20MULTICAST\40SHIM"

/* flags set internally only: */
#define	IFF_CANTCHANGE \
	(IFF_BROADCAST|IFF_POINTOPOINT|IFF_RUNNING|IFF_OACTIVE|\
	    IFF_SIMPLEX|IFF_MULTICAST|IFF_ALLMULTI|IFF_PROMISC|IFF_SHIM)

/*
 * Some convenience macros used for setting ifi_baudrate.
 * XXX 1000 vs. 1024? --thorpej@NetBSD.org
 */
#define	IF_Kbps(x)	((x) * 1000)		/* kilobits/sec. */
#define	IF_Mbps(x)	(IF_Kbps((x) * 1000))	/* megabits/sec. */
#define	IF_Gbps(x)	(IF_Mbps((x) * 1000))	/* gigabits/sec. */

/* Capabilities that interfaces can advertise. */
#define	IFCAP_CSUM_IPv4		0x0001	/* can do IPv4 header checksums */
#define	IFCAP_CSUM_TCPv4	0x0002	/* can do IPv4/TCP checksums */
#define	IFCAP_CSUM_UDPv4	0x0004	/* can do IPv4/UDP checksums */
#define	IFCAP_CSUM_TCPv6	0x0008	/* can do IPv6/TCP checksums */
#define	IFCAP_CSUM_UDPv6	0x0010	/* can do IPv6/UDP checksums */
#define	IFCAP_TSOv4		0x0020	/* can do TCPv4 segmentation offload */
#define	IFCAP_TSOv6		0x0040	/* can do TCPv6 segmentation offload */

#define	IFCAPBITS \
    "\020\1IP4CSUM\2TCP4CSUM\3UDP4CSUM\4TCP6CSUM\5UDP6CSUM\6TSO4\7TSO6"

/*
 * Output queues (ifp->if_snd) and internetwork datagram level (pup level 1)
 * input routines have queues of messages stored on ifqueue structures
 * (defined above).  Entries are added to and deleted from these structures
 * by these macros, which should be called with ipl raised to splnet().
 */
#define	IF_QFULL(ifq)		((ifq)->ifq_len >= (ifq)->ifq_maxlen)
#define	IF_DROP(ifq)		((ifq)->ifq_drops++)
#define	IF_ENQUEUE(ifq, m) do { \
	(m)->m_nextpkt = 0; \
	if ((ifq)->ifq_tail == 0) \
		(ifq)->ifq_head = m; \
	else \
		(ifq)->ifq_tail->m_nextpkt = m; \
	(ifq)->ifq_tail = m; \
	(ifq)->ifq_len++; \
} while (/*CONSTCOND*/0)
#define	IF_PREPEND(ifq, m) do { \
	(m)->m_nextpkt = (ifq)->ifq_head; \
	if ((ifq)->ifq_tail == 0) \
		(ifq)->ifq_tail = (m); \
	(ifq)->ifq_head = (m); \
	(ifq)->ifq_len++; \
} while (/*CONSTCOND*/0)
#define	IF_DEQUEUE(ifq, m) do { \
	(m) = (ifq)->ifq_head; \
	if (m) { \
		if (((ifq)->ifq_head = (m)->m_nextpkt) == 0) \
			(ifq)->ifq_tail = 0; \
		(m)->m_nextpkt = 0; \
		(ifq)->ifq_len--; \
	} \
} while (/*CONSTCOND*/0) 
#define	IF_POLL(ifq, m)		((m) = (ifq)->ifq_head)
#define	IF_PURGE(ifq)							\
do {									\
	struct mbuf *__m0;						\
									\
	for (;;) {							\
		IF_DEQUEUE((ifq), __m0);				\
		if (__m0 == NULL)					\
			break;						\
		else							\
			m_freem(__m0);					\
	}								\
} while (/*CONSTCOND*/ 0)
#define	IF_IS_EMPTY(ifq)	((ifq)->ifq_len == 0)

#ifndef IFQ_MAXLEN
#define	IFQ_MAXLEN	256
#endif
#define	IFNET_SLOWHZ	1		/* granularity is 1 second */

/*
 * Structure defining statistics and other data kept regarding an address
 * on a network interface.
 */
struct ifaddr_data {
	int64_t	ifad_inbytes;
	int64_t	ifad_outbytes;
};

/*
 * The ifaddr structure contains information about one address
 * of an interface.  They are maintained by the different address families,
 * are allocated and attached when an address is set, and are linked
 * together so all addresses for an interface can be located.
 */
struct ifaddr {
	struct	sockaddr *ifa_addr;	/* address of interface */
	struct	sockaddr *ifa_dstaddr;	/* other end of p-to-p link */
#define	ifa_broadaddr	ifa_dstaddr	/* broadcast address interface */
	struct	sockaddr *ifa_netmask;	/* used to determine subnet */
	struct	ifnet *ifa_ifp;		/* back-pointer to interface */
	TAILQ_ENTRY(ifaddr) ifa_list;	/* list of addresses for interface */
	struct	ifaddr_data	ifa_data;	/* statistics on the address */
	void	(*ifa_rtrequest)	/* check or clean routes (+ or -)'d */
		        (int, struct rtentry *, struct rt_addrinfo *);
	unsigned int	ifa_flags;		/* mostly rt_flags for cloning */
	int	ifa_refcnt;		/* count of references */
	int	ifa_metric;		/* cost of going out this interface */
	struct ifaddr	*(*ifa_getifa)(struct ifaddr *,
			               const struct sockaddr *);
	uint32_t	*ifa_seqno;
	int16_t	ifa_preference;	/* preference level for this address */
};
#define	IFA_ROUTE	RTF_UP /* 0x01 *//* route installed */

/*
 * Message format for use in obtaining information about interfaces
 * from sysctl and the routing socket.
 */
struct if_msghdr {
	unsigned short	ifm_msglen;	/* to skip over non-understood messages */
	unsigned char	ifm_version;	/* future binary compatibility */
	unsigned char	ifm_type;	/* message type */
	int	ifm_addrs;	/* like rtm_addrs */
	int	ifm_flags;	/* value of if_flags */
	unsigned short	ifm_index;	/* index for associated ifp */
	struct	if_data ifm_data;/* statistics and other data about if */
};

#if defined(_KERNEL) && defined(COMPAT_14)
/* pre-1.5 if_msghdr (ifm_data changed) */
struct if_msghdr14 {
	unsigned short	ifm_msglen;	/* to skip over non-understood messages */
	unsigned char	ifm_version;	/* future binary compatibility */
	unsigned char	ifm_type;	/* message type */
	int	ifm_addrs;	/* like rtm_addrs */
	int	ifm_flags;	/* value of if_flags */
	unsigned short	ifm_index;	/* index for associated ifp */
	struct	if_data14 ifm_data; /* statistics and other data about if */
};
#endif /* _KERNEL && COMPAT_14 */

/*
 * Message format for use in obtaining information about interface addresses
 * from sysctl and the routing socket.
 */
struct ifa_msghdr {
	unsigned short	ifam_msglen;	/* to skip over non-understood messages */
	unsigned char	ifam_version;	/* future binary compatibility */
	unsigned char	ifam_type;	/* message type */
	int	ifam_addrs;	/* like rtm_addrs */
	int	ifam_flags;	/* value of ifa_flags */
	unsigned short	ifam_index;	/* index for associated ifp */
	int	ifam_metric;	/* value of ifa_metric */
};

/*
 * Message format announcing the arrival or departure of a network interface.
 */
struct if_announcemsghdr {
	unsigned short	ifan_msglen;	/* to skip over non-understood messages */
	unsigned char	ifan_version;	/* future binary compatibility */
	unsigned char	ifan_type;	/* message type */
	unsigned short	ifan_index;	/* index for associated ifp */
	char	ifan_name[IFNAMSIZ]; /* if name, e.g. "en0" */
	unsigned short	ifan_what;	/* what type of announcement */
};

#define	IFAN_ARRIVAL	0	/* interface arrival */
#define	IFAN_DEPARTURE	1	/* interface departure */

/*
 * Interface request structure used for socket
 * ioctl's.  All interface ioctl's must have parameter
 * definitions which begin with ifr_name.  The
 * remainder may be interface specific.
 */
struct	ifreq {
	char	ifr_name[IFNAMSIZ];		/* if name, e.g. "en0" */
	union {
		struct	sockaddr ifru_addr;
		struct	sockaddr ifru_dstaddr;
		struct	sockaddr ifru_broadaddr;
		struct	sockaddr_storage ifru_space;
#ifndef __QNXNTO__
		short	ifru_flags;
#else
		int	ifru_flags;
#endif
		int	ifru_metric;
		int	ifru_mtu;
		int	ifru_dlt;
		unsigned int	ifru_value;
		void *	ifru_data;
		struct {
			uint32_t	b_buflen;
			void		*b_buf;
		} ifru_b;
	} ifr_ifru;
#define	ifr_addr	ifr_ifru.ifru_addr	/* address */
#define	ifr_dstaddr	ifr_ifru.ifru_dstaddr	/* other end of p-to-p link */
#define	ifr_broadaddr	ifr_ifru.ifru_broadaddr	/* broadcast address */
#define	ifr_space	ifr_ifru.ifru_space	/* sockaddr_storage */
#define	ifr_flags	ifr_ifru.ifru_flags	/* flags */
#define	ifr_metric	ifr_ifru.ifru_metric	/* metric */
#define	ifr_mtu		ifr_ifru.ifru_mtu	/* mtu */
#define	ifr_dlt		ifr_ifru.ifru_dlt	/* data link type (DLT_*) */
#define	ifr_value	ifr_ifru.ifru_value	/* generic value */
#define	ifr_media	ifr_ifru.ifru_metric	/* media options (overload) */
#define	ifr_data	ifr_ifru.ifru_data	/* for use by interface
						 * XXX deprecated
						 */
#define	ifr_buf		ifr_ifru.ifru_b.b_buf	/* new interface ioctls */
#define	ifr_buflen	ifr_ifru.ifru_b.b_buflen
};

#ifdef _KERNEL
#define	ifreq_setdstaddr	ifreq_setaddr
#define	ifreq_setbroadaddr	ifreq_setaddr
#define	ifreq_getdstaddr	ifreq_getaddr
#define	ifreq_getbroadaddr	ifreq_getaddr

static inline const struct sockaddr *
ifreq_getaddr(u_long cmd, const struct ifreq *ifr)
{
	return &ifr->ifr_addr;
}
#endif /* _KERNEL */

struct ifcapreq {
	char		ifcr_name[IFNAMSIZ];	/* if name, e.g. "en0" */
	uint64_t	ifcr_capabilities_rx;	/* supported capabiliites */
	uint64_t	ifcr_capabilities_tx;
	uint64_t	ifcr_capenable_rx;	/* capabilities enabled */
	uint64_t	ifcr_capenable_tx;
};

struct ifaliasreq {
	char	ifra_name[IFNAMSIZ];		/* if name, e.g. "en0" */
	struct	sockaddr ifra_addr;
	struct	sockaddr ifra_dstaddr;
#define	ifra_broadaddr	ifra_dstaddr
	struct	sockaddr ifra_mask;
};

struct ifdatareq {
	char	ifdr_name[IFNAMSIZ];		/* if name, e.g. "en0" */
	struct	if_data ifdr_data;
};

struct ifmediareq {
	char	ifm_name[IFNAMSIZ];		/* if name, e.g. "en0" */
	int	ifm_current;			/* current media options */
	int	ifm_mask;			/* don't care mask */
	int	ifm_status;			/* media status */
	int	ifm_active;			/* active options */
	int	ifm_count;			/* # entries in ifm_ulist
						   array */
	int	*ifm_ulist;			/* media words */
};


struct  ifdrv {
	char		ifd_name[IFNAMSIZ];	/* if name, e.g. "en0" */
	unsigned long	ifd_cmd;
	size_t		ifd_len;
	void		*ifd_data;
};

#ifdef __QNXNTO__
/*
 * Pull out info common across drivers (or
 * classes of drivers).  See ifdrvcom.h.
 * As above but of different size to avoid burning
 * another 'i' ioctl code (we don't use ifd_data
 * anyway).
 */
struct  ifdrv_com {
	char		ifdc_name[IFNAMSIZ];	/* if name, e.g. "en0" */
	unsigned long	ifdc_cmd;
	size_t		ifdc_len;
};
#endif

/*
 * Structure used in SIOCGIFCONF request.
 * Used to retrieve interface configuration
 * for machine (useful for programs which
 * must know all networks accessible).
 */
struct	ifconf {
#ifndef __QNXNTO__
	int	ifc_len;		/* size of associated buffer */
#else
	short	ifc_len;
#endif
	union {
		caddr_t	ifcu_buf;
		struct	ifreq *ifcu_req;
	} ifc_ifcu;
#define	ifc_buf	ifc_ifcu.ifcu_buf	/* buffer address */
#define	ifc_req	ifc_ifcu.ifcu_req	/* array of structures returned */
};

/*
 * Structure for SIOC[AGD]LIFADDR
 */
struct if_laddrreq {
	char iflr_name[IFNAMSIZ];
	unsigned int flags;
#define IFLR_PREFIX	0x8000	/* in: prefix given  out: kernel fills id */
#define IFLR_ACTIVE	0x4000	/* in/out: link-layer address activation */
	unsigned int prefixlen;		/* in/out */
	struct sockaddr_storage addr;	/* in/out */
	struct sockaddr_storage dstaddr; /* out */
};

/*
 * Structure for SIOC[SG]IFADDRPREF
 */
struct if_addrprefreq {
	char			ifap_name[IFNAMSIZ];
	int16_t			ifap_preference;	/* in/out */
	struct sockaddr_storage	ifap_addr;		/* in/out */
};

#ifndef _NET_IF_ARP_INCLUDED
#include <net/if_arp.h>
#endif

#endif /* __EXT_BSD */

#ifdef _KERNEL
struct nw_work_thread;

#ifdef IFAREF_DEBUG
#define	IFAREF(ifa)							\
do {									\
	printf("IFAREF: %s:%d %p -> %d\n", __FILE__, __LINE__,		\
	    (ifa), ++(ifa)->ifa_refcnt);				\
} while (/*CONSTCOND*/ 0)

#define	IFAFREE(ifa)							\
do {									\
	if ((ifa)->ifa_refcnt <= 0)					\
		panic("%s:%d: %p ifa_refcnt <= 0", __FILE__,		\
		    __LINE__, (ifa));					\
	printf("IFAFREE: %s:%d %p -> %d\n", __FILE__, __LINE__,		\
	    (ifa), --(ifa)->ifa_refcnt);				\
	if ((ifa)->ifa_refcnt == 0)					\
		ifafree(ifa);						\
} while (/*CONSTCOND*/ 0)
#else
#define	IFAREF(ifa)	(ifa)->ifa_refcnt++

#ifdef DIAGNOSTIC
#define	IFAFREE(ifa)							\
do {									\
	if ((ifa)->ifa_refcnt <= 0)					\
		panic("%s:%d: %p ifa_refcnt <= 0", __FILE__,		\
		    __LINE__, (ifa));					\
	if (--(ifa)->ifa_refcnt == 0)					\
		ifafree(ifa);						\
} while (/*CONSTCOND*/ 0)
#else
#define	IFAFREE(ifa)							\
do {									\
	if (--(ifa)->ifa_refcnt == 0)					\
		ifafree(ifa);						\
} while (/*CONSTCOND*/ 0)
#endif /* DIAGNOSTIC */
#endif /* IFAREF_DEBUG */

#ifdef ALTQ
#define	ALTQ_DECL(x)		x
#define ALTQ_COMMA		,

#define IFQ_ENQUEUE(ifq, m, pattr, err)					\
do {									\
	if (ALTQ_IS_ENABLED((ifq)))					\
		ALTQ_ENQUEUE((ifq), (m), (pattr), (err));		\
	else {								\
		if (IF_QFULL((ifq))) {					\
			m_freem((m));					\
			(err) = ENOBUFS;				\
		} else {						\
			IF_ENQUEUE((ifq), (m));				\
			(err) = 0;					\
		}							\
	}								\
	if ((err))							\
		(ifq)->ifq_drops++;					\
} while (/*CONSTCOND*/ 0)

#define IFQ_DEQUEUE(ifq, m)						\
do {									\
	if (TBR_IS_ENABLED((ifq)))					\
		(m) = tbr_dequeue((ifq), ALTDQ_REMOVE);			\
	else if (ALTQ_IS_ENABLED((ifq)))				\
		ALTQ_DEQUEUE((ifq), (m));				\
	else								\
		IF_DEQUEUE((ifq), (m));					\
} while (/*CONSTCOND*/ 0)

#define	IFQ_POLL(ifq, m)						\
do {									\
	if (TBR_IS_ENABLED((ifq)))					\
		(m) = tbr_dequeue((ifq), ALTDQ_POLL);			\
	else if (ALTQ_IS_ENABLED((ifq)))				\
		ALTQ_POLL((ifq), (m));					\
	else								\
		IF_POLL((ifq), (m));					\
} while (/*CONSTCOND*/ 0)

#define	IFQ_PURGE(ifq)							\
do {									\
	if (ALTQ_IS_ENABLED((ifq)))					\
		ALTQ_PURGE((ifq));					\
	else								\
		IF_PURGE((ifq));					\
} while (/*CONSTCOND*/ 0)

#define	IFQ_SET_READY(ifq)						\
do {									\
	(ifq)->altq_flags |= ALTQF_READY;				\
} while (/*CONSTCOND*/ 0)

#define	IFQ_CLASSIFY(ifq, m, af, pattr)					\
do {									\
	if (ALTQ_IS_ENABLED((ifq))) {					\
		if (ALTQ_NEEDS_CLASSIFY((ifq)))				\
			(pattr)->pattr_class = (*(ifq)->altq_classify)	\
				((ifq)->altq_clfier, (m), (af));	\
		(pattr)->pattr_af = (af);				\
		(pattr)->pattr_hdr = mtod((m), caddr_t);		\
	}								\
} while (/*CONSTCOND*/ 0)
#else /* ! ALTQ */
#define	ALTQ_DECL(x)		/* nothing */
#define ALTQ_COMMA

#define	IFQ_ENQUEUE(ifq, m, pattr, err)					\
do {									\
	if (IF_QFULL((ifq))) {						\
		m_freem((m));						\
		(err) = ENOBUFS;					\
	} else {							\
		IF_ENQUEUE((ifq), (m));					\
		(err) = 0;						\
	}								\
	if ((err))							\
		(ifq)->ifq_drops++;					\
} while (/*CONSTCOND*/ 0)

#define	IFQ_DEQUEUE(ifq, m)	IF_DEQUEUE((ifq), (m))

#define	IFQ_POLL(ifq, m)	IF_POLL((ifq), (m))

#define	IFQ_PURGE(ifq)		IF_PURGE((ifq))

#define	IFQ_SET_READY(ifq)	/* nothing */

#define	IFQ_CLASSIFY(ifq, m, af, pattr) /* nothing */

#endif /* ALTQ */

#define	IFQ_IS_EMPTY(ifq)		IF_IS_EMPTY((ifq))
#define	IFQ_INC_LEN(ifq)		((ifq)->ifq_len++)
#define	IFQ_DEC_LEN(ifq)		(--(ifq)->ifq_len)
#define	IFQ_INC_DROPS(ifq)		((ifq)->ifq_drops++)
#define	IFQ_SET_MAXLEN(ifq, len)	((ifq)->ifq_maxlen = (len))

#include <sys/mallocvar.h>
MALLOC_DECLARE(M_IFADDR);
MALLOC_DECLARE(M_IFMADDR);

#define	IFNET_FOREACH(__ifp)		TAILQ_FOREACH(__ifp, &ifnet, if_list)
#define	IFADDR_FOREACH(__ifa, __ifp)	TAILQ_FOREACH(__ifa, \
					    &(__ifp)->if_addrlist, ifa_list)
#define	IFADDR_EMPTY(__ifp)		TAILQ_EMPTY(&(__ifp)->if_addrlist)

extern struct ifnet_head ifnet;
extern struct ifnet **ifindex2ifnet;
extern struct ifnet *lo0ifp;
extern size_t if_indexlim;

void    ether_input(struct ifnet *, struct mbuf *);

int ifreq_setaddr(u_long, struct ifreq *, const struct sockaddr *);

void if_initname(struct ifnet *, const char *, int);
struct ifaddr *if_dl_create(const struct ifnet *, const struct sockaddr_dl **);
void	if_set_sadl(struct ifnet *, const void *, u_char);
void	if_alloc_sadl(struct ifnet *);
void	if_free_sadl(struct ifnet *);
void	if_attach(struct ifnet *);
void	if_attachdomain(void);
void	if_attachdomain1(struct ifnet *);
void	if_deactivate(struct ifnet *);
void	if_detach(struct ifnet *);
void	if_down(struct ifnet *);
void	if_link_state_change(struct ifnet *, int);
void	if_slowtimo(void *);
void	if_up(struct ifnet *);
int	ifconf(u_long, caddr_t);
void	ifinit(void);
int	ifioctl(struct socket *, u_long, caddr_t, struct lwp *);
int	ifioctl_common(struct ifnet *, u_long, void *);
int	ifpromisc(struct ifnet *, int);
struct	ifnet *ifunit(const char *);
#ifdef __QNXNTO__
int	if_ctxt_check(struct ifnet *, struct stk_callback *);
#endif

void ifa_insert(struct ifnet *, struct ifaddr *);
void ifa_remove(struct ifnet *, struct ifaddr *);
struct	ifaddr *ifa_ifwithaddr(const struct sockaddr *, struct ifnet *);
#define ifa_ifwithaddr(s) (ifa_ifwithaddr)((s), NULL)
struct	ifaddr *ifa_ifwithaf(int);
struct	ifaddr *ifa_ifwithdstaddr(const struct sockaddr *, struct ifnet *);
#define ifa_ifwithdstaddr(s) (ifa_ifwithdstaddr)((s), NULL)
struct	ifaddr *ifa_ifwithnet(const struct sockaddr *, struct ifnet *);
#define ifa_ifwithnet(s) (ifa_ifwithnet)((s), NULL)
struct	ifaddr *ifa_ifwithladdr(const struct sockaddr *, struct ifnet *);
#define ifa_ifwithladdr(s) (ifa_ifwithladdr)((s), NULL)
struct	ifaddr *ifa_ifwithroute(int, const struct sockaddr *,
					const struct sockaddr *);
struct	ifaddr *ifaof_ifpforaddr(const struct sockaddr *, struct ifnet *);
void	ifafree(struct ifaddr *);
void	link_rtrequest(int, struct rtentry *, struct rt_addrinfo *);

void	if_clone_attach(struct if_clone *);
void	if_clone_detach(struct if_clone *);

int	if_clone_create(const char *);
int	if_clone_destroy(const char *);

int	ifq_enqueue(struct ifnet *, struct mbuf * ALTQ_COMMA
    ALTQ_DECL(struct altq_pktattr *));
#ifdef __QNXNTO__
int	ifq_enqueue_wtp(struct ifnet *, struct mbuf * ALTQ_COMMA
    ALTQ_DECL(struct altq_pktattr *), struct nw_work_thread *);
#endif
int	ifq_enqueue2(struct ifnet *, struct ifqueue *, struct mbuf * ALTQ_COMMA
    ALTQ_DECL(struct altq_pktattr *));

int	loioctl(struct ifnet *, u_long, caddr_t);
void	loopattach(int);
int	looutput(struct ifnet *,
	   struct mbuf *, struct sockaddr *, struct rtentry *);
void	lortrequest(int, struct rtentry *, struct rt_addrinfo *);

/*
 * These are exported because they're an easy way to tell if
 * an interface is going away without having to burn a flag.
 */
int	if_nulloutput(struct ifnet *, struct mbuf *,
	    struct sockaddr *, struct rtentry *);
void	if_nullinput(struct ifnet *, struct mbuf *);
void	if_nullstart(struct ifnet *);
int	if_nullioctl(struct ifnet *, u_long, caddr_t);
int	if_nullinit(struct ifnet *);
void	if_nullstop(struct ifnet *, int);
void	if_nullwatchdog(struct ifnet *);
void	if_nulldrain(struct ifnet *);
#ifdef __QNXNTO__
void	if_data_gather __P((struct if_data *, struct ifnet *));
void	if_data_clr __P((struct ifnet *));
#endif
#else /* !_KERNEL */
struct if_nameindex {
	unsigned int	if_index;	/* 1, 2, ... */
	char		*if_name;	/* null terminated name: "le0", ... */
};

#include <sys/cdefs.h>
__BEGIN_DECLS
unsigned int if_nametoindex(const char *);
char *	if_indextoname(unsigned int, char *);
struct	if_nameindex * if_nameindex(void);
void	if_freenameindex(struct if_nameindex *);
__END_DECLS
#endif /* _KERNEL */ /* XXX really ALTQ? */

#ifdef _KERNEL
/*
 * ifq sysctl support
 */
int	sysctl_ifq(int *name, u_int namelen, void *oldp,
		       size_t *oldlenp, void *newp, size_t newlen,
		       struct ifqueue *ifq);
/* symbolic names for terminal (per-protocol) CTL_IFQ_ nodes */
#define IFQCTL_LEN 1
#define IFQCTL_MAXLEN 2
#define IFQCTL_PEAK 3
#define IFQCTL_DROPS 4
#define IFQCTL_MAXID 5

#endif /* _KERNEL */

#ifdef __EXT_BSD
/*
 * sysctl for ifq (per-protocol packet input queue variant of ifqueue)
 */
#define CTL_IFQ_NAMES  { \
	{ 0, 0 }, \
	{ "len", CTLTYPE_INT }, \
	{ "maxlen", CTLTYPE_INT }, \
	{ "peak", CTLTYPE_INT }, \
	{ "drops", CTLTYPE_INT }, \
}
#endif /* __EXT_BSD */
#endif /* !_NET_IF_H_INCLUDED */

__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/SP1/lib/socket/public/net/if.h $ $Rev: 644488 $" )
