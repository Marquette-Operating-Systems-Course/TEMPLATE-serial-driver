/* *
 * @file start.S
 *
 * Initialization code for Embedded Xinu on the RISC-V
 *
 * Embedded Xinu, Copyright (C) 2024.  All rights reserved.
 *
 */
#include <riscv.h>

.section .init
.globl   _start

/* _start:  Entry point of the Xinu kernel.  This will be the very first
	/* byte of the kernel image and on the will be loaded at the start address.  */
.func _start

_start:
	// Continue at reset handler.
	j reset_handler
	.endfunc

	.section .text
/* reset_handler: Reset handler routine executed to start up the kernel,
 * when the processor is reset, or (currently) when an unhandled
* exception occurs. */
	.func reset_handler

reset_handler:

	// Add space for the stack
	la  a1, _end
	li  a3, NULLUSER_STACK_SIZE
	add sp, a1, a3

	// Clear the block starting symbol ("BSS") area, zeroed C variables.
	la   a0, _bss
	la   t0, _end
	sub  a1, t0, a0
	call bzero

	la a4, memheap
	sw sp, 0(a4)

	call nulluser
	.endfunc
