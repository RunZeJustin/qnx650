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

/*	$NetBSD: route.h,v 1.45 2006/11/13 19:14:30 dyoung Exp $	*/

/*
 * Copyright (c) 1980, 1986, 1993
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
 *	@(#)route.h	8.5 (Berkeley) 2/8/95
 */

#ifndef _NET_ROUTE_H_INCLUDED
#define _NET_ROUTE_H_INCLUDED

#ifndef __QUEUE_H_INCLUDED
#include <sys/queue.h>
#endif

#ifndef __TYPES_H_INCLUDED
#include <sys/types.h>
#endif

#ifndef _STDINT_H_INCLUDED
#include <stdint.h>
#endif

#ifndef __SOCKET_H_INCLUDED
#include <sys/socket.h>
#endif

#ifndef _NET_IF_H_INCLUDED
#include <net/if.h>
#endif

/*
 * Kernel resident routing tables.
 *
 * The routing tables are initialized when interface addresses
 * are set by making entries for all directly connected interfaces.
 */

/*
 * A route consists of a destination address and a reference
 * to a routing entry.  These are often held by protocols
 * in their control blocks, e.g. inpcb.
 */
struct route {
	struct	rtentry *ro_rt;
	struct	sockaddr ro_dst;
};

/*
 * These numbers are used by reliable protocols for determining
 * retransmission behavior and are included in the routing structure.
 */
struct rt_metrics {
	u_long	rmx_locks;	/* Kernel must leave these values alone */
	u_long	rmx_mtu;	/* MTU for this path */
	u_long	rmx_hopcount;	/* max hops expected */
	u_long	rmx_expire;	/* lifetime for route, e.g. redirect */
	u_long	rmx_recvpipe;	/* inbound delay-bandwidth product */
	u_long	rmx_sendpipe;	/* outbound delay-bandwidth product */
	u_long	rmx_ssthresh;	/* outbound gateway buffer limit */
	u_long	rmx_rtt;	/* estimated round trip time */
	u_long	rmx_rttvar;	/* estimated rtt variance */
	u_long	rmx_pksent;	/* packets sent using this route */
};

/*
 * rmx_rtt and rmx_rttvar are stored as microseconds;
 * RTTTOPRHZ(rtt) converts to a value suitable for use
 * by a protocol slowtimo counter.
 */
#define	RTM_RTTUNIT	1000000	/* units for rtt, rttvar, as units per sec */
#define	RTTTOPRHZ(r)	((r) / (RTM_RTTUNIT / PR_SLOWHZ))

/*
 * We distinguish between routes to hosts and routes to networks,
 * preferring the former if available.  For each route we infer
 * the interface to use from the gateway address supplied when
 * the route was entered.  Routes that forward packets through
 * gateways are marked so that the output routines know to address the
 * gateway rather than the ultimate destination.
 */
#ifndef RNF_NORMAL
#include <net/radix.h>
#endif
struct rtentry {
	struct	radix_node rt_nodes[2];	/* tree glue, and other values */
/*XXXUNCONST*/
#define	rt_key(r)	((struct sockaddr *)__UNCONST((r)->rt_nodes->rn_key))
/*XXXUNCONST*/
#define	rt_mask(r)	((struct sockaddr *)__UNCONST((r)->rt_nodes->rn_mask))
	struct	sockaddr *rt_gateway;	/* value */
	int	rt_flags;		/* up/down?, host/net */
	int	rt_refcnt;		/* # held references */
	u_long	rt_use;			/* raw # packets forwarded */
	struct	ifnet *rt_ifp;		/* the answer: interface to use */
	struct	ifaddr *rt_ifa;		/* the answer: interface to use */
	uint32_t rt_ifa_seqno;
	const struct sockaddr *rt_genmask; /* for generation of cloned routes */
	caddr_t	rt_llinfo;		/* pointer to link level info cache */
	struct	rt_metrics rt_rmx;	/* metrics used by rx'ing protocols */
	struct	rtentry *rt_gwroute;	/* implied entry for gatewayed routes */
	LIST_HEAD(, rttimer) rt_timer;  /* queue of timeouts for misc funcs */
	struct	rtentry *rt_parent;	/* parent of cloned route */
};

/*
 * Following structure necessary for 4.3 compatibility;
 * We should eventually move it to a compat file.
 */
struct ortentry {
	uint32_t rt_hash;		/* to speed lookups */
	struct	sockaddr rt_dst;	/* key */
	struct	sockaddr rt_gateway;	/* value */
	struct	sockaddr rt_netmask;	/* netmask */
	int16_t	rt_flags;		/* up/down?, host/net */
	int16_t	rt_refcnt;		/* # held references */
	uint32_t rt_use;		/* raw # packets forwarded */
	struct	ifnet *rt_ifp;		/* the answer: interface to use */
};

#define	RTF_UP		0x0001		/* route usable */
#define	RTF_GATEWAY	0x0002		/* destination is a gateway */
#define	RTF_HOST	0x0004		/* host entry (net otherwise) */
#define	RTF_REJECT	0x0008		/* host or net unreachable */
#define	RTF_DYNAMIC	0x0010		/* created dynamically (by redirect) */
#define	RTF_MODIFIED	0x0020		/* modified dynamically (by redirect) */
#define RTF_DONE	0x0040		/* message confirmed */
#define RTF_MASK	0x0080		/* subnet mask present */
#define RTF_CLONING	0x0100		/* generate new routes on use */
#define RTF_XRESOLVE	0x0200		/* external daemon resolves name */
#define RTF_LLINFO	0x0400		/* generated by ARP or ESIS */
#define RTF_STATIC	0x0800		/* manually added */
#define RTF_BLACKHOLE	0x1000		/* just discard pkts (during updates) */
#define	RTF_CLONED	0x2000		/* this is a cloned route */
#define RTF_PROTO2	0x4000		/* protocol specific routing flag */
#define RTF_PROTO1	0x8000		/* protocol specific routing flag */
#define RTF_SRC		0x10000		/* route has fixed source address */


/*
 * Routing statistics.
 */
struct	rtstat {
	uint64_t rts_badredirect;	/* bogus redirect calls */
	uint64_t rts_dynamic;		/* routes created by redirects */
	uint64_t rts_newgateway;	/* routes modified by redirects */
	uint64_t rts_unreach;		/* lookups which failed */
	uint64_t rts_wildcard;		/* lookups satisfied by a wildcard */
};
/*
 * Structures for routing messages.
 */
struct rt_msghdr {
	u_short	rtm_msglen;	/* to skip over non-understood messages */
	u_char	rtm_version;	/* future binary compatibility */
	u_char	rtm_type;	/* message type */
	u_short	rtm_index;	/* index for associated ifp */
	u_short zero;		/* align structure */
	int	rtm_flags;	/* flags, incl. kern & message, e.g. DONE */
	int	rtm_addrs;	/* bitmask identifying sockaddrs in msg */
	pid_t	rtm_pid;	/* identify sender */
	int	rtm_seq;	/* for sender to identify action */
	int	rtm_errno;	/* why failed */
	int	rtm_use;	/* from rtentry */
	u_long	rtm_inits;	/* which metrics we are initializing */
	struct	rt_metrics rtm_rmx; /* metrics themselves */
};

#define RTM_VERSION	3	/* Up the ante and ignore older versions */

#define RTM_ADD		0x1	/* Add Route */
#define RTM_DELETE	0x2	/* Delete Route */
#define RTM_CHANGE	0x3	/* Change Metrics or flags */
#define RTM_GET		0x4	/* Report Metrics */
#define RTM_LOSING	0x5	/* Kernel Suspects Partitioning */
#define RTM_REDIRECT	0x6	/* Told to use different route */
#define RTM_MISS	0x7	/* Lookup failed on this address */
#define RTM_LOCK	0x8	/* fix specified metrics */
#define RTM_OLDADD	0x9	/* caused by SIOCADDRT */
#define RTM_OLDDEL	0xa	/* caused by SIOCDELRT */
#define RTM_RESOLVE	0xb	/* req to resolve dst to LL addr */
#define RTM_NEWADDR	0xc	/* address being added to iface */
#define RTM_DELADDR	0xd	/* address being removed from iface */
#define RTM_OIFINFO	0xe	/* Old (pre-1.5) RTM_IFINFO message */
#define RTM_IFINFO	0xf	/* iface/link going up/down etc. */
#define	RTM_IFANNOUNCE	0x10	/* iface arrival/departure */
#define	RTM_IEEE80211	0x11	/* IEEE80211 wireless event */

#define RTV_MTU		0x1	/* init or lock _mtu */
#define RTV_HOPCOUNT	0x2	/* init or lock _hopcount */
#define RTV_EXPIRE	0x4	/* init or lock _expire */
#define RTV_RPIPE	0x8	/* init or lock _recvpipe */
#define RTV_SPIPE	0x10	/* init or lock _sendpipe */
#define RTV_SSTHRESH	0x20	/* init or lock _ssthresh */
#define RTV_RTT		0x40	/* init or lock _rtt */
#define RTV_RTTVAR	0x80	/* init or lock _rttvar */

/*
 * Bitmask values for rtm_addr.
 */
#define RTA_DST		0x1	/* destination sockaddr present */
#define RTA_GATEWAY	0x2	/* gateway sockaddr present */
#define RTA_NETMASK	0x4	/* netmask sockaddr present */
#define RTA_GENMASK	0x8	/* cloning mask sockaddr present */
#define RTA_IFP		0x10	/* interface name sockaddr present */
#define RTA_IFA		0x20	/* interface addr sockaddr present */
#define RTA_AUTHOR	0x40	/* sockaddr for author of redirect */
#define RTA_BRD		0x80	/* for NEWADDR, broadcast or p-p dest addr */

/*
 * Index offsets for sockaddr array for alternate internal encoding.
 */
#define RTAX_DST	0	/* destination sockaddr present */
#define RTAX_GATEWAY	1	/* gateway sockaddr present */
#define RTAX_NETMASK	2	/* netmask sockaddr present */
#define RTAX_GENMASK	3	/* cloning mask sockaddr present */
#define RTAX_IFP	4	/* interface name sockaddr present */
#define RTAX_IFA	5	/* interface addr sockaddr present */
#define RTAX_AUTHOR	6	/* sockaddr for author of redirect */
#define RTAX_BRD	7	/* for NEWADDR, broadcast or p-p dest addr */
#define RTAX_MAX	8	/* size of array to allocate */

struct rt_addrinfo {
	int	rti_addrs;
	const struct	sockaddr *rti_info[RTAX_MAX];
	int	rti_flags;
	struct	ifaddr *rti_ifa;
	struct	ifnet *rti_ifp;
	struct	rt_msghdr *rti_rtm;
};

struct route_cb {
	int	ip_count;
	int	ip6_count;
	int	ipx_count;
	int	ns_count;
	int	iso_count;
	int	any_count;
};

/*
 * This structure, and the prototypes for the rt_timer_{init,remove_all,
 * add,timer} functions all used with the kind permission of BSDI.
 * These allow functions to be called for routes at specific times.
 */

struct rttimer {
	TAILQ_ENTRY(rttimer)	rtt_next;  /* entry on timer queue */
	LIST_ENTRY(rttimer) 	rtt_link;  /* multiple timers per rtentry */
	struct rttimer_queue   *rtt_queue; /* back pointer to queue */
	struct rtentry         *rtt_rt;    /* Back pointer to the route */
	void		      (*rtt_func)(struct rtentry *, struct rttimer *);
	time_t          	rtt_time;  /* When this timer was registered */
};

struct rttimer_queue {
	long				rtq_timeout;
	unsigned long			rtq_count;
	TAILQ_HEAD(, rttimer)		rtq_head;
	LIST_ENTRY(rttimer_queue)	rtq_link;
};


#ifdef _KERNEL
#define	RTFREE(rt) \
do { \
	if ((rt)->rt_refcnt <= 1) \
		rtfree(rt); \
	else \
		(rt)->rt_refcnt--; \
} while (/*CONSTCOND*/ 0)

extern	struct	route_cb route_cb;
extern	struct	rtstat	rtstat;
extern	struct	radix_node_head *rt_tables[AF_MAX+1];

struct socket;

void	 route_init(void);
int	 route_output(struct mbuf *, ...);
int	 route_usrreq(struct socket *,
	    int, struct mbuf *, struct mbuf *, struct mbuf *, struct lwp *);
void	 rt_ifannouncemsg(struct ifnet *, int);
void	 rt_ieee80211msg(struct ifnet *, int, void *, size_t);
void	 rt_ifmsg(struct ifnet *);
void	 rt_maskedcopy(const struct sockaddr *,
	    struct sockaddr *, const struct sockaddr *);
void	 rt_missmsg(int, struct rt_addrinfo *, int, int);
void	 rt_newaddrmsg(int, struct ifaddr *, int, struct rtentry *);
int	 rt_setgate(struct rtentry *,
	    const struct sockaddr *, const struct sockaddr *);
void	 rt_setmetrics(u_long, const struct rt_metrics *, struct rt_metrics *);
int      rt_timer_add(struct rtentry *,
             void(*)(struct rtentry *, struct rttimer *),
	     struct rttimer_queue *);
void	 rt_timer_init(void);
struct rttimer_queue *
	 rt_timer_queue_create(u_int);
void	 rt_timer_queue_change(struct rttimer_queue *, long);
void	 rt_timer_queue_remove_all(struct rttimer_queue *, int);
void	 rt_timer_queue_destroy(struct rttimer_queue *, int);
void	 rt_timer_remove_all(struct rtentry *, int);
unsigned long	rt_timer_count(struct rttimer_queue *);
void	 rt_timer_timer(void *);
void	 rtable_init(void **);
void	 rtalloc(struct route *, void *);
#define rtalloc(r) (rtalloc)((r), NULL)
struct rtentry *
	 rtalloc1(const struct sockaddr *, int, void *);
#define rtalloc1(r, i) (rtalloc1)((r), (i), NULL)
void	 rtfree(struct rtentry *);
int	 rt_getifa(struct rt_addrinfo *);
int	 rtinit(struct ifaddr *, int, int);
int	 rtioctl(u_long, caddr_t, struct lwp *);
void	 rtredirect(const struct sockaddr *, const struct sockaddr *,
	    const struct sockaddr *, int, const struct sockaddr *,
	    struct rtentry **);
int	 rtrequest(int, const struct sockaddr *,
	    const struct sockaddr *, const struct sockaddr *, int,
	    struct rtentry **);
int	 rtrequest1(int, struct rt_addrinfo *, struct rtentry **);
#ifdef __QNXNTO__
int	 rt_check(struct rtentry **, struct rtentry **, struct sockaddr *,
	     int);
#endif

static inline void
rt_set_ifa1(struct rtentry *rt, struct ifaddr *ifa)
{
	rt->rt_ifa = ifa;
	if (ifa->ifa_seqno != NULL)
		rt->rt_ifa_seqno = *ifa->ifa_seqno;
}

static inline void
rt_replace_ifa(struct rtentry *rt, struct ifaddr *ifa)
{
	IFAREF(ifa);
	IFAFREE(rt->rt_ifa);
	rt_set_ifa1(rt, ifa);
}

static inline struct ifaddr *
rt_get_ifa(struct rtentry *rt)
{
	struct ifaddr *ifa;

	if ((ifa = rt->rt_ifa) == NULL)
		return ifa;
	else if (ifa->ifa_getifa == NULL)
		return ifa;
#if 0
	else if (ifa->ifa_seqno != NULL && *ifa->ifa_seqno == rt->rt_ifa_seqno)
		return ifa;
#endif
	else {
		ifa = (*ifa->ifa_getifa)(ifa, rt_key(rt));
		rt_replace_ifa(rt, ifa);
		return ifa;
	}
}

static inline void
rt_set_ifa(struct rtentry *rt, struct ifaddr *ifa)
{
	IFAREF(ifa);
	rt_set_ifa1(rt, ifa);
}

#endif /* _KERNEL */
#endif /* !_NET_ROUTE_H_INCLUDED */

__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/SP1/lib/socket/public/net/route.h $ $Rev: 233581 $" )
