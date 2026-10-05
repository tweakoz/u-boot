/* SPDX-License-Identifier: GPL-2.0+ */
/* A five-second post-FDT checkpoint, then PSCI SYSTEM_RESET. */
.text
.global infiniti_fdt_checkpoint_reset
infiniti_fdt_checkpoint_reset:
	mrs x9, cntfrq_el0
	mrs x10, cntpct_el0
	add x9, x9, x9, lsl #2
	add x10, x10, x9
1:	mrs x11, cntpct_el0
	cmp x11, x10
	b.lo 1b
	mov x0, #9
	movk x0, #0x8400, lsl #16
	mov x1, xzr
	mov x2, xzr
	mov x3, xzr
	smc #0
2:	wfe
	b 2b
