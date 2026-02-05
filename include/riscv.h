/**
 * @file riscv.h
 *
 * Contains constants for the RISC-V architecture.
 * NOTE: This file is included in assembly, thus it can only contain constants
 */
/* Embedded Xinu, Copyright (C) 2024.  All rights reserved. */

// TODO: 
// - refactor by removing unnecessary constants
// - rename constants to better reflect their 
//   usage in the new kernel boot sequence

#ifndef _RISCV_H_
#define _RISCV_H_

#define RISCV_SSTATUS_SUM (1L << 18) /* Enable S and M mode access to U mode memory */

#define RISCV_SIE_SEIE (1 << 9) /* Enable S mode external interrupts */
#define RISCV_SIE_STIE (1 << 5) /* Enable S mode timer interrupts */
#define RISCV_SIE_SSIE (1 << 1) /* Enable S mode _____ interrupts */

// Combined, enables all types of supervisor interrupts
#define RISCV_ENABLE_ALL_SMODE_INTR                                            \
  (RISCV_SIE_SEIE | RISCV_SIE_STIE | RISCV_SIE_SSIE)

#define MAXVIRTADDR 0x4000000000   //(1L << 38)
#define INTERRUPTADDR 0x3FFFFFF000 // truncpage((MAXVIRTADDR - PAGE_SIZE))
#define SWAPAREAADDR 0x3FFFFFE000  // truncpage((MAXVIRTADDR - PAGE_SIZE))
#define PROCSTACKADDR                                                          \
  0x3FFFFFD000 // truncpage((MAXVIRTADDR - PAGE_SIZE - PAGE_SIZE))

#define NULLUSER_STACK_SIZE 16384

#define SSTATUS_S_MODE (1L << 8)
#define SSTATUS_U_MODE 0x0
#define SSTATUS_PRIV_MODE_BIT (1L << 8)

/* toggleable debugging print */
#define debug_mode true /* use this to enable and disable log() prints */
#if debug_mode == true
#define log(string, ...)                                                       \
  kprintf("\033[93m" string "\033[0m\r\n", ##__va_args__);
#else
#define log(string, ...)
#endif

#endif /* _RISCV_H_ */
