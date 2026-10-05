// SPDX-License-Identifier: GPL-2.0+
/* Diagnostic override of the weak board late hook. */
extern void infiniti_fdt_checkpoint_reset(void);

void qcom_late_init(void)
{
	infiniti_fdt_checkpoint_reset();
}
