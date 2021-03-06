/*  *********************************************************************
    *  Broadcom Common Firmware Environment (CFE)
    *  
    *  Address space macros			File: addrspace.h
    *
    *  Macros to deal with physical, virtual, and uncached addresses.
    *  for MIPS, these map to the appropriate KSEG0/KSEG1 macros
    *  
    *  Author:  Mitch Lichtenberg (mpl@broadcom.com)
    *  
    *********************************************************************  
    *
    *  Copyright 2000,2001,2002,2003
    *  Broadcom Corporation. All rights reserved.
    *  
    *  This software is furnished under license and may be used and 
    *  copied only in accordance with the following terms and 
    *  conditions.  Subject to these conditions, you may download, 
    *  copy, install, use, modify and distribute modified or unmodified 
    *  copies of this software in source and/or binary form.  No title 
    *  or ownership is transferred hereby.
    *  
    *  1) Any source code used, modified or distributed must reproduce 
    *     and retain this copyright notice and list of conditions 
    *     as they appear in the source file.
    *  
    *  2) No right is granted to use any trade name, trademark, or 
    *     logo of Broadcom Corporation.  The "Broadcom Corporation" 
    *     name may not be used to endorse or promote products derived 
    *     from this software without the prior written permission of 
    *     Broadcom Corporation.
    *  
    *  3) THIS SOFTWARE IS PROVIDED "AS-IS" AND ANY EXPRESS OR
    *     IMPLIED WARRANTIES, INCLUDING BUT NOT LIMITED TO, ANY IMPLIED
    *     WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR 
    *     PURPOSE, OR NON-INFRINGEMENT ARE DISCLAIMED. IN NO EVENT 
    *     SHALL BROADCOM BE LIABLE FOR ANY DAMAGES WHATSOEVER, AND IN 
    *     PARTICULAR, BROADCOM SHALL NOT BE LIABLE FOR DIRECT, INDIRECT,
    *     INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
    *     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
    *     GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    *     BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY 
    *     OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR 
    *     TORT (INCLUDING NEGLIGENCE OR OTHERWISE), EVEN IF ADVISED OF 
    *     THE POSSIBILITY OF SUCH DAMAGE.
    ********************************************************************* */


#include "sbmips.h"

#define PHYSADDR(x)  K0_TO_PHYS(x)

/* If running uncached, force all kernel addresses to be uncached */
#if CFG_RUNFROMKSEG0
#define KERNADDR(x)  PHYS_TO_K0(x)
#else
#define KERNADDR(x)  PHYS_TO_K1(x)
#endif

#define _VA(pa)      PHYS_TO_K0(pa)
#define _VA_UC(pa)   PHYS_TO_K1(pa)

#define _PA(va)      K0_TO_PHYS(va)
#define _PA_UC(va)   K1_TO_PHYS(pa)
#define _BA(va)      _PA(va)

#define TO_VIRT(paddr)  KERNADDR(x)
#define TO_PHYS(vaddr)  PHYSADDR(x)

#define UNCADDR(x)  PHYS_TO_K1(x)



