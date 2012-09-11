/****************************************************************************
 * mm/mm_gran.h
 *
 *   Copyright (C) 2012 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __MM_MM_GRAN_H
#define __MM_MM_GRAN_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <nuttx/gran.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define SIZEOF_GAT(n) \
  ((n + 31) >> 5)
#define SIZEOF_GRAN_S(n) \
  (sizeof(struct gran_s) + sizeof(uint32_t) * (SIZEOF_GAT(n) - 1))

/****************************************************************************
 * Public Types
 ****************************************************************************/

/* This structure represents the state of on granual allocation */

struct gran_s
{
  uint8_t    log2gran;  /* Log base 2 of the size of one granule */
  uint16_t   ngranules; /* The total number of (aligned) granules in the heap */
  uintptr_t  heapstart; /* The aligned start of the granule heap */
  uint32_t   gat[i];    /* Start of the granule allocation table */
};

/****************************************************************************
 * Public Data
 ****************************************************************************/

/* State of the single GRAN allocator */

#ifdef CONFIG_GRAN_SINGLE
extern FAR struct gran_s *g_graninfo;
#endif

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

#endif /* __MM_MM_GRAN_H */