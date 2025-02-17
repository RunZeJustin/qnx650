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


/*	$NetBSD: systm.h,v 1.190 2006/09/30 11:59:37 yamt Exp $	*/

/*-
 * Copyright (c) 1982, 1988, 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
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
 *	@(#)systm.h	8.7 (Berkeley) 3/29/95
 */

/*
 * The `securelevel' variable controls the security level of the system.
 * It can only be decreased by process 1 (/sbin/init).
 *
 * Security levels are as follows:
 *   -1	permanently insecure mode - always run system in level 0 mode.
 *    0	insecure mode - immutable and append-only flags may be turned off.
 *	All devices may be read or written subject to permission modes.
 *    1	secure mode - immutable and append-only flags may not be changed;
 *	raw disks of mounted filesystems, /dev/mem, and /dev/kmem are
 *	read-only.
 *    2	highly secure mode - same as (1) plus raw disks are always
 *	read-only whether mounted or not. This level precludes tampering
 *	with filesystems by unmounting them, but also inhibits running
 *	newfs while the system is secured.
 *
 * In normal operation, the system runs in level 0 mode while single user
 * and in level 1 mode while multiuser. If level 2 mode is desired while
 * running multiuser, it can be set in the multiuser startup script
 * (/etc/rc.local) using sysctl(8). If it is desired to run the system
 * in level 0 mode while multiuser, initialize the variable securelevel
 * in /sys/kern/kern_sysctl.c to -1. Note that it is NOT initialized to
 * zero as that would allow the vmunix binary to be patched to -1.
 * Without initialization, securelevel loads in the BSS area which only
 * comes into existence when the kernel is loaded and hence cannot be
 * patched by a stalking hacker.
 */

#ifndef _SYS_SYSTM_H_
#define _SYS_SYSTM_H_

#if defined(_KERNEL_OPT)
#include "opt_ddb.h"
#include "opt_multiprocessor.h"
#include "opt_syscall_debug.h"
#endif

#include <machine/endian.h>
struct stk_callback {
	void	(*func)(void *);
	void	*arg;
};
#include <sys/device.h>

#ifndef __QNXNTO__
#ifdef _KERNEL
#include <sys/types.h>
#endif

struct clockframe;
struct lwp;
#endif
struct proc;
struct timeval;
#ifndef __QNXNTO__
struct tty;
#endif
struct uio;
#ifndef __QNXNTO__
struct vnode;
struct vmspace;

#endif
extern int securelevel;		/* system security level */
#ifndef __QNXNTO__
extern const char *panicstr;	/* panic message */
extern int doing_shutdown;	/* shutting down */

extern const char copyright[];	/* system copyright */
extern char cpu_model[];	/* machine/cpu model name */
#endif
extern char machine[];		/* machine type */
extern char machine_arch[];	/* machine architecture */
#ifndef __QNXNTO__
extern const char osrelease[];	/* short system version */
extern const char ostype[];	/* system type */
extern const char kernel_ident[];/* kernel configuration ID */
extern const char version[];	/* system version */
#else
extern char osrelease[];	/* short system version */
extern char ostype[];		/* system type */
extern char version[];		/* system version */
#endif

#ifndef __QNXNTO__
extern int autonicetime;        /* time (in seconds) before autoniceval */
extern int autoniceval;         /* proc priority after autonicetime */

extern int selwait;		/* select timeout address */

extern int maxmem;		/* max memory per process */
extern int physmem;		/* physical memory */

extern dev_t dumpdev;		/* dump device */
extern long dumplo;		/* offset into dumpdev */
extern int dumpsize;		/* size of dump in pages */
extern const char *dumpspec;	/* how dump device was specified */

extern dev_t rootdev;		/* root device */
extern struct vnode *rootvp;	/* vnode equivalent to above */
extern struct device *root_device; /* device equivalent to above */
extern const char *rootspec;	/* how root device was specified */
#endif

extern const char hexdigits[];	/* "0123456789abcdef" in subr_prf.c */
extern const char HEXDIGITS[];	/* "0123456789ABCDEF" in subr_prf.c */
#ifndef __QNXNTO__

/*
 * These represent the swap pseudo-device (`sw').  This device
 * is used by the swap pager to indirect through the routines
 * in sys/vm/vm_swap.c.
 */
extern const dev_t swapdev;	/* swapping device */
extern struct vnode *swapdev_vp;/* vnode equivalent to above */

extern const dev_t zerodev;	/* /dev/zero */

typedef int	sy_call_t(struct lwp *, void *, register_t *);

extern struct sysent {		/* system call table */
	short	sy_narg;	/* number of args */
	short	sy_argsize;	/* total size of arguments */
	int	sy_flags;	/* flags. see below */
	sy_call_t *sy_call;     /* implementing function */
} sysent[];
extern int nsysent;
#if	BYTE_ORDER == BIG_ENDIAN
#define	SCARG(p,k)	((p)->k.be.datum)	/* get arg from args pointer */
#elif	BYTE_ORDER == LITTLE_ENDIAN
#define	SCARG(p,k)	((p)->k.le.datum)	/* get arg from args pointer */
#else
#error	"what byte order is this machine?"
#endif
#else /* __QNXNTO__ */
/*
 * Avoid window where neither BYTE_ORDER or *_ENDIAN are
 * defined.  If it occurs endian falls to first condtion
 * (big endian above).
 */
#if defined(__BIGENDIAN__)
#define	SCARG(p,k)	((p)->k.be.datum)	/* get arg from args pointer */
#elif defined(__LITTLEENDIAN__)
#define	SCARG(p,k)	((p)->k.le.datum)	/* get arg from args pointer */
#else
#error	"what byte order is this machine?"
#endif
#endif /* !__QNXNTO__ */

#define	SYCALL_MPSAFE	0x0001	/* syscall is MP-safe */

extern int boothowto;		/* reboot flags, from console subsystem */
#define	bootverbose	(boothowto & AB_VERBOSE)
#define	bootquiet	(boothowto & AB_QUIET)
#ifndef __QNXNTO__

extern void (*v_putc)(int); /* Virtual console putc routine */

extern	void	_insque(void *, void *);
extern	void	_remque(void *);

/* casts to keep lint happy, but it should be happy with void * */
#define	insque(q,p)	_insque(q, p)
#define	remque(q)	_remque(q)

/*
 * General function declarations.
 */
int	nullop(void *);
int	enodev(void);
int	enosys(void);
int	enoioctl(void);
int	enxio(void);
int	eopnotsupp(void);

#endif /* !__QNXNTO__ */
enum hashtype {
	HASH_LIST,
	HASH_TAILQ
};

struct malloc_type;
void	*hashinit(u_int, enum hashtype, struct malloc_type *, int, u_long *);
void	hashdone(void *, struct malloc_type *);
int	seltrue(dev_t, int, struct lwp *);
#ifndef __QNXNTO__
int	sys_nosys(struct lwp *, void *, register_t *);
#endif


#ifdef _KERNEL
void	aprint_normal(const char *, ...)
    __attribute__((__format__(__printf__,1,2)));
void	aprint_error(const char *, ...)
    __attribute__((__format__(__printf__,1,2)));
void	aprint_naive(const char *, ...)
    __attribute__((__format__(__printf__,1,2)));
void	aprint_verbose(const char *, ...)
    __attribute__((__format__(__printf__,1,2)));
void	aprint_debug(const char *, ...)
    __attribute__((__format__(__printf__,1,2)));
void	aprint_error_dev(device_t, const char *, ...)
    __attribute__((__format__(__printf__,2,3)));
void	aprint_verbose_dev(device_t, const char *, ...)
    __attribute__((__format__(__printf__,2,3)));

struct ifnet;

void	aprint_error_ifnet(struct ifnet *, const char *, ...)
    __attribute__((__format__(__printf__,2,3)));
void	aprint_verbose_ifnet(struct ifnet *, const char *, ...)
    __attribute__((__format__(__printf__,2,3)));
void	aprint_debug_ifnet(struct ifnet *, const char *, ...)
    __attribute__((__format__(__printf__,2,3)));
#ifndef __QNXNTO__

int	aprint_get_error_count(void);

void	printf_nolog(const char *, ...)
    __attribute__((__format__(__printf__,1,2)));

void	printf(const char *, ...)
    __attribute__((__format__(__printf__,1,2)));
#else
int	printf(const char *, ...)
    __attribute__((__format__(__printf__,1,2)));
#endif
int	sprintf(char *, const char *, ...)
    __attribute__((__format__(__printf__,2,3)));
int	snprintf(char *, size_t, const char *, ...)
    __attribute__((__format__(__printf__,3,4)));
#ifndef __QNXNTO__
void	vprintf(const char *, _BSD_VA_LIST_);
#else
int	vprintf(const char *, _BSD_VA_LIST_);
#endif
int	vsprintf(char *, const char *, _BSD_VA_LIST_);
int	vsnprintf(char *, size_t, const char *, _BSD_VA_LIST_);
#ifndef __QNXNTO__
int	humanize_number(char *, size_t, uint64_t, const char *, int);

void	twiddle(void);
#endif /* !__QNXNTO__ */
#endif /* _KERNEL */

void	panic(const char *, ...)
    __attribute__((__noreturn__,__format__(__printf__,1,2)));
#ifndef __QNXNTO__
void	uprintf(const char *, ...)
    __attribute__((__format__(__printf__,1,2)));
void	ttyprintf(struct tty *, const char *, ...)
    __attribute__((__format__(__printf__,2,3)));

char	*bitmask_snprintf(u_quad_t, const char *, char *, size_t);

int	format_bytes(char *, size_t, uint64_t);

void	tablefull(const char *, const char *);

int	kcopy(const void *, void *, size_t);
#endif /* !__QNXNTO__ */

#ifdef _KERNEL
#define bcopy(src, dst, len)	memcpy((dst), (src), (len))
#define bzero(src, len)		memset((src), 0, (len))
#define bcmp(a, b, len)		memcmp((a), (b), (len))
#endif /* KERNEL */

#ifndef __QNXNTO__
int	copystr(const void *, void *, size_t, size_t *);
int	copyinstr(const void *, void *, size_t, size_t *);
int	copyoutstr(const void *, void *, size_t, size_t *);
#endif
int	copyin(const void *, void *, size_t);
int	copyout(const void *, void *, size_t);

#ifdef _KERNEL
typedef	int	(*copyin_t)(const void *, void *, size_t);
typedef int	(*copyout_t)(const void *, void *, size_t);
#endif

#ifndef __QNXNTO__
int	copyin_proc(struct proc *, const void *, void *, size_t);
int	copyout_proc(struct proc *, const void *, void *, size_t);
int	copyin_vmspace(struct vmspace *, const void *, void *, size_t);
int	copyout_vmspace(struct vmspace *, const void *, void *, size_t);
#else
#ifdef _KERNEL
#include <lib/libkern/libkern.h>
#include <errno.h>
static __inline int	copyinstr(const void *, void *, size_t, size_t *);
static __inline int	copystr(const void *, void *, size_t, size_t *);

static __inline int
copyinstr(const void *src, void *dst, size_t len, size_t *done)
{
	size_t ret;

	ret = strlcpy(dst, src, len);
	if (ret > len)
		return ENAMETOOLONG;

	if (*done)
		*done = ret + 1;

	return 0;
}

static __inline int
copystr(const void *src, void *dst, size_t len, size_t *done)
{
	size_t ret;

	ret = strlcpy(dst, src, len);
	if (ret > len)
		return ENAMETOOLONG;

	if (*done)
		*done = ret + 1;

	return 0;
}
#endif
#endif

int	ioctl_copyin(int ioctlflags, const void *src, void *dst, size_t len);
int	ioctl_copyout(int ioctlflags, const void *src, void *dst, size_t len);

int	subyte(void *, int);
int	suibyte(void *, int);
int	susword(void *, short);
int	suisword(void *, short);
int	suswintr(void *, short);
int	suword(void *, long);
int	suiword(void *, long);

int	fubyte(const void *);
int	fuibyte(const void *);
int	fusword(const void *);
int	fuisword(const void *);
int	fuswintr(const void *);
long	fuword(const void *);
long	fuiword(const void *);

#ifndef __QNXNTO__
void	hardclock(struct clockframe *);
void	softclock(void *);
void	statclock(struct clockframe *);
#else
int	hardclock(void *arg);
int	softclock(void *);

int 	clock_intr_init(void *);
void	clock_intr_destroy(void *arg);

int stk_context_callback(struct stk_callback *);
#endif
#ifdef NTP
void	ntp_init(void);
#ifndef __HAVE_TIMECOUNTER
void	hardupdate(long offset);
#endif /* !__HAVE_TIMECOUNTER */
#ifdef PPS_SYNC
#ifdef __HAVE_TIMECOUNTER
void	hardpps(struct timespec *, long);
#else /* !__HAVE_TIMECOUNTER */
void	hardpps(struct timeval *, long);
extern void *pps_kc_hardpps_source;
extern int pps_kc_hardpps_mode;
#endif /* !__HAVE_TIMECOUNTER */
#endif /* PPS_SYNC */
#else
#ifdef __HAVE_TIMECOUNTER
void	ntp_init(void);	/* also provides adjtime() functionality */
#endif /* __HAVE_TIMECOUNTER */
#endif /* NTP */

#ifndef __QNXNTO__
void	initclocks(void);
void	inittodr(time_t);
void	resettodr(void);
void	cpu_initclocks(void);
void	setrootfstime(time_t);

void	startprofclock(struct proc *);
void	stopprofclock(struct proc *);
void	proftick(struct clockframe *);
void	setstatclockrate(int);
#endif

/*
 * Shutdown hooks.  Functions to be run with all interrupts disabled
 * immediately before the system is halted or rebooted.
 */
void	*shutdownhook_establish(void (*)(void *), void *);
void	shutdownhook_disestablish(void *);
void	doshutdownhooks(void);

/*
 * Power management hooks.
 */
void	*powerhook_establish(const char *, void (*)(int, void *), void *);
void	powerhook_disestablish(void *);
void	dopowerhooks(int);
#define PWR_RESUME	0
#define PWR_SUSPEND	1
#define PWR_STANDBY	2
#define PWR_SOFTRESUME	3
#define PWR_SOFTSUSPEND	4
#define PWR_SOFTSTANDBY	5

#ifndef __QNXNTO__
/*
 * Mountroot hooks (and mountroot declaration).  Device drivers establish
 * these to be executed just before (*mountroot)() if the passed device is
 * selected as the root device.
 */
extern int (*mountroot)(void);
void	*mountroothook_establish(void (*)(struct device *), struct device *);
void	mountroothook_disestablish(void *);
void	mountroothook_destroy(void);
void	domountroothook(void);

/*
 * Exec hooks. Subsystems may want to do cleanup when a process
 * execs.
 */
void	*exechook_establish(void (*)(struct proc *, void *), void *);
void	exechook_disestablish(void *);
void	doexechooks(struct proc *);

/*
 * Exit hooks. Subsystems may want to do cleanup when a process exits.
 */
void	*exithook_establish(void (*)(struct proc *, void *), void *);
void	exithook_disestablish(void *);
void	doexithooks(struct proc *);

/*
 * Fork hooks.  Subsystems may want to do special processing when a process
 * forks.
 */
void	*forkhook_establish(void (*)(struct proc *, struct proc *));
void	forkhook_disestablish(void *);
void	doforkhooks(struct proc *, struct proc *);

/*
 * kernel syscall tracing/debugging hooks.
 */
#ifdef _KERNEL
boolean_t trace_is_enabled(struct proc *);
int	trace_enter(struct lwp *, register_t, register_t,
	    const struct sysent *, void *);
void	trace_exit(struct lwp *, register_t, void *, register_t [], int);
#endif

#endif /* !__QNXNTO__ */
int	uiomove(void *, size_t, struct uio *);
int	uiomove_frombuf(void *, size_t, struct uio *);

#ifndef __QNXNTO__
#ifdef _KERNEL
int	setjmp(label_t *);
void	longjmp(label_t *) __attribute__((__noreturn__));
#endif

void	consinit(void);

void	cpu_startup(void);
void	cpu_configure(void);
void	cpu_rootconf(void);
void	cpu_dumpconf(void);

#ifdef GPROF
void	kmstartup(void);
#endif
#endif

#ifdef _KERNEL
#include <lib/libkern/libkern.h>

/*
 * Stuff to handle debugger magic key sequences.
 */
#define CNS_LEN			128
#define CNS_MAGIC_VAL(x)	((x)&0x1ff)
#define CNS_MAGIC_NEXT(x)	(((x)>>9)&0x7f)
#define CNS_TERM		0x7f	/* End of sequence */

typedef struct cnm_state {
	int	cnm_state;
	u_short	*cnm_magic;
} cnm_state_t;

/* Override db_console() in MD headers */
#ifndef cn_trap
#define cn_trap()	console_debugger()
#endif
#ifndef cn_isconsole
#define cn_isconsole(d)	(cn_tab != NULL && (d) == cn_tab->cn_dev)
#endif

void cn_init_magic(cnm_state_t *);
void cn_destroy_magic(cnm_state_t *);
int cn_set_magic(const char *);
int cn_get_magic(char *, size_t);
/* This should be called for each byte read */
#ifndef cn_check_magic
#define cn_check_magic(d, k, s)						\
	do {								\
		if (cn_isconsole(d)) {					\
			int _v = (s).cnm_magic[(s).cnm_state];		\
			if ((k) == CNS_MAGIC_VAL(_v)) {			\
				(s).cnm_state = CNS_MAGIC_NEXT(_v);	\
				if ((s).cnm_state == CNS_TERM) {	\
					cn_trap();			\
					(s).cnm_state = 0;		\
				}					\
			} else {					\
				(s).cnm_state = 0;			\
			}						\
		}							\
	} while (/* CONSTCOND */ 0)
#endif

/* Encode out-of-band events this way when passing to cn_check_magic() */
#define	CNC_BREAK		0x100

#if defined(DDB) || defined(sun3) || defined(sun2)
/* note that cpu_Debugger() is always available on sun[23] */
void	cpu_Debugger(void);
#define Debugger	cpu_Debugger
#endif

#ifdef DDB
/*
 * Enter debugger(s) from console attention if enabled
 */
extern int db_fromconsole; /* XXX ddb/ddbvar.h */
#define console_debugger() if (db_fromconsole) Debugger()
#elif defined(Debugger)
#define console_debugger() Debugger()
#else
#define console_debugger() do {} while (/* CONSTCOND */ 0) /* NOP */
#endif
#endif /* _KERNEL */

#ifdef SYSCALL_DEBUG
void scdebug_call(struct lwp *, register_t, register_t[]);
void scdebug_ret(struct lwp *, register_t, int, register_t[]);
#endif /* SYSCALL_DEBUG */

#if defined(MULTIPROCESSOR)
void	_kernel_lock_init(void);
void	_kernel_lock(int);
void	_kernel_unlock(void);
void	_kernel_proc_lock(struct lwp *);
void	_kernel_proc_unlock(struct lwp *);
int	_kernel_lock_release_all(void);
void	_kernel_lock_acquire_count(int);

#define	KERNEL_LOCK_INIT()		_kernel_lock_init()
#define	KERNEL_LOCK(flag)		_kernel_lock((flag))
#define	KERNEL_UNLOCK()			_kernel_unlock()
#define	KERNEL_PROC_LOCK(l)		_kernel_proc_lock((l))
#define	KERNEL_PROC_UNLOCK(l)		_kernel_proc_unlock((l))
#define	KERNEL_LOCK_RELEASE_ALL()	_kernel_lock_release_all()
#define	KERNEL_LOCK_ACQUIRE_COUNT(count) _kernel_lock_acquire_count(count)

#else /* ! MULTIPROCESSOR */

#define	KERNEL_LOCK_INIT()		/* nothing */
#define	KERNEL_LOCK(flag)		/* nothing */
#define	KERNEL_UNLOCK()			/* nothing */
#define	KERNEL_PROC_LOCK(l)		/* nothing */
#define	KERNEL_PROC_UNLOCK(l)		/* nothing */
#define	KERNEL_LOCK_RELEASE_ALL()	(0)
#define	KERNEL_LOCK_ACQUIRE_COUNT(count) /* nothing */

#endif /* MULTIPROCESSOR */

#if defined(MULTIPROCESSOR) && defined(DEBUG)
#define	KERNEL_LOCK_ASSERT_LOCKED()	_kernel_lock_assert_locked()
#define	KERNEL_LOCK_ASSERT_UNLOCKED()	_kernel_lock_assert_unlocked()
void _kernel_lock_assert_locked(void);
void _kernel_lock_assert_unlocked(void);
#else
#define	KERNEL_LOCK_ASSERT_LOCKED()	/* nothing */
#define	KERNEL_LOCK_ASSERT_UNLOCKED()	/* nothing */
#endif

#endif	/* !_SYS_SYSTM_H_ */

__SRCVERSION( "$URL: http://svn/product/branches/6.5.0/SP1/lib/io-pkt/sys/sys/systm.h $ $Rev: 644488 $" )
