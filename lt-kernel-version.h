#ifndef _LT_KERNEL_VERSION_H
#define _LT_KERNEL_VERSION_H

/*
 * lt-kernel-version.h
 *
 * Contains helpers to check more complex kernel version conditions.
 *
 * Copyright (C) 2012 Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; only
 * version 2.1 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <linux/version.h>

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33))
#include <generated/utsrelease.h>
#else /* #if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)) */
#include <linux/utsrelease.h>
#endif /* #else #if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)) */

/*
 * This macro checks if the kernel version is between the two specified
 * versions (lower limit inclusive, upper limit exclusive).
 */
#define LT_KERNEL_RANGE(a_low, b_low, c_low, a_high, b_high, c_high) \
	(LINUX_VERSION_CODE >= KERNEL_VERSION(a_low, b_low, c_low) && \
	 LINUX_VERSION_CODE < KERNEL_VERSION(a_high, b_high, c_high))

/* Ubuntu */

#define LT_UBUNTU_KERNEL_VERSION(a, b, c, d) \
	(((a) << 24) + ((b) << 16) + ((c) << 8) + (d))

#ifdef UTS_UBUNTU_RELEASE_ABI
#define LT_UBUNTU_VERSION_CODE \
	((LINUX_VERSION_CODE << 8) + UTS_UBUNTU_RELEASE_ABI)
#else
#define LT_UBUNTU_VERSION_CODE 	0
#endif

#define LT_UBUNTU_KERNEL_RANGE(a_low, b_low, c_low, d_low, \
		a_high, b_high, c_high, d_high) \
	(LT_UBUNTU_VERSION_CODE >= \
		LT_UBUNTU_KERNEL_VERSION(a_low, b_low, c_low, d_low) && \
		LT_UBUNTU_VERSION_CODE < \
		LT_UBUNTU_KERNEL_VERSION(a_high, b_high, c_high, d_high))

/* Debian */

#define LT_DEBIAN_KERNEL_VERSION(a, b, c, d, e, f) \
	(((((a) << 16) + ((b) << 8) + (c)) * 1000000ULL) + ((d) * 10000) + ((e) * 100) + (f))

#ifdef DEBIAN_API_VERSION
#define LT_DEBIAN_VERSION_CODE \
	((LINUX_VERSION_CODE * 1000000ULL) + DEBIAN_API_VERSION)
#else
#define LT_DEBIAN_VERSION_CODE	0
#endif

#define LT_DEBIAN_KERNEL_RANGE(a_low, b_low, c_low, d_low, e_low, f_low, \
		a_high, b_high, c_high, d_high, e_high, f_high) \
	(LT_DEBIAN_VERSION_CODE >= \
		LT_DEBIAN_KERNEL_VERSION(a_low, b_low, c_low, d_low, e_low, f_low) && \
		LT_DEBIAN_VERSION_CODE < \
		LT_DEBIAN_KERNEL_VERSION(a_high, b_high, c_high, d_high, e_high, f_high))

#define LT_RHEL_KERNEL_VERSION(a, b, c, d, e, f) \
	(((((a) << 16) + ((b) << 8) + (c)) * 10000000ULL) + ((d) * 10000) + ((e) * 100) + (f))

/* RHEL */

#ifdef RHEL_API_VERSION
#define LT_RHEL_VERSION_CODE \
	((LINUX_VERSION_CODE * 10000000ULL) + RHEL_API_VERSION)
#else
#define LT_RHEL_VERSION_CODE		0
#endif

#define LT_RHEL_KERNEL_RANGE(a_low, b_low, c_low, d_low, e_low, f_low, \
		a_high, b_high, c_high, d_high, e_high, f_high) \
	(LT_RHEL_VERSION_CODE >= \
		LT_RHEL_KERNEL_VERSION(a_low, b_low, c_low, d_low, e_low, f_low) && \
		LT_RHEL_VERSION_CODE < \
		LT_RHEL_KERNEL_VERSION(a_high, b_high, c_high, d_high, e_high, f_high))

/* RT patch */

#define LT_RT_KERNEL_VERSION(a, b, c, d) \
	(((a) << 24) + ((b) << 16) + ((c) << 8) + (d))

#ifdef RT_PATCH_VERSION
#define LT_RT_VERSION_CODE \
	((LINUX_VERSION_CODE << 8) + RT_PATCH_VERSION)
#else
#define LT_RT_VERSION_CODE 	0
#endif

#define LT_RT_KERNEL_RANGE(a_low, b_low, c_low, d_low, \
		a_high, b_high, c_high, d_high) \
	(LT_RT_VERSION_CODE >= \
		LT_RT_KERNEL_VERSION(a_low, b_low, c_low, d_low) && \
		LT_RT_VERSION_CODE < \
		LT_RT_KERNEL_VERSION(a_high, b_high, c_high, d_high))

#endif /* _LT_KERNEL_VERSION_H */
