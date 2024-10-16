/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
/*
 * **** This file incorporates work covered by the following copyright and ****
 * **** permission notice:                                                 ****
 *
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

#include <hal.h>

#ifndef __SYS_ARCH_H__
#define __SYS_ARCH_H__

typedef semaphore_t *   sys_sem_t;
typedef mailbox_t *     sys_mbox_t;
typedef thread_t *      sys_thread_t;
typedef syssts_t        sys_prot_t;

#define SYS_MBOX_NULL   (mailbox_t *)0
#define SYS_THREAD_NULL (thread_t *)0
#define SYS_SEM_NULL    (semaphore_t *)0

/* let sys.h use binary semaphores for mutexes */
#define LWIP_COMPAT_MUTEX 1

/*
 * Check OSAL reslotuion equal u32_t
 */
#if OSAL_ST_RESOLUTION != 32
#error lwip expects u32_t timer resolution!
#endif
/*
 * lwip needs a u32_t timer that overflows at 32 bit boundary.
 * Best is to use OSAL_ST_FREQUENCY = 1000, if higher then a virtial timer
 * is created, to keep the lwip aware about system time.
 */
#if OSAL_ST_FREQUENCY > 1000
/*
 * Update time of sys_now counter in milliseconds.
 * For exact presssion set 1, that means every millisecond. Or set higher number
 * to relieve the virtual timer resources.
 */
#define LWIP_SYS_NOW_PRECISION 10
#elif OSAL_ST_FREQUENCY < 1000
#error lwip expects OSAL_ST_FREQUENCY >= 1000
#endif

#endif /* __SYS_ARCH_H__ */
