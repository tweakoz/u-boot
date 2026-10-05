/* SPDX-License-Identifier: GPL-2.0+ */
#include <generated/infiniti-payload.h>
.section .rodata.infiniti_payload,"a"
.balign 8
.global infiniti_kernel_start, infiniti_kernel_end
infiniti_kernel_start:
.incbin INFINITI_KERNEL_FILE
infiniti_kernel_end:
.balign 8
.global infiniti_initrd_start, infiniti_initrd_end
infiniti_initrd_start:
.incbin INFINITI_INITRD_FILE
infiniti_initrd_end:
.balign 8
.global infiniti_fdt_start, infiniti_fdt_end
infiniti_fdt_start:
.incbin INFINITI_FDT_FILE
infiniti_fdt_end:
