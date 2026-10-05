// SPDX-License-Identifier: GPL-2.0+
/* Host-prepared experimental RAM payload. No storage driver or storage calls. */
#include <env.h>
#include <linux/kernel.h>
#include <linux/libfdt.h>
#include <linux/sizes.h>
#include <linux/string.h>
#include <vsprintf.h>

extern const unsigned char infiniti_kernel_start[], infiniti_kernel_end[];
extern const unsigned char infiniti_initrd_start[], infiniti_initrd_end[];
extern const unsigned char infiniti_fdt_start[], infiniti_fdt_end[];

void qcom_late_init(void)
{
	ulong kernel = env_get_hex("kernel_addr_r", 0);
	ulong initrd = env_get_hex("ramdisk_addr_r", 0);
	ulong fdt = env_get_hex("fdt_addr_r", 0);
	size_t ksize = infiniti_kernel_end - infiniti_kernel_start;
	size_t rsize = infiniti_initrd_end - infiniti_initrd_start;
	size_t fsize = infiniti_fdt_end - infiniti_fdt_start;

	/* These buffers are reserved by board_late_init() using ABL's RAM
	 * map and LMB, not fixed load addresses from another phone.
	 */
	if (!kernel || !initrd || !fdt || ksize > SZ_128M ||
	    rsize > SZ_128M || fsize > SZ_2M || ksize < 64 ||
	    memcmp(infiniti_kernel_start + 56, "ARM\x64", 4) ||
	    fdt_check_full(infiniti_fdt_start, fsize))
		panic("Infiniti RAM payload or LMB buffers invalid\n");

	memcpy((void *)kernel, infiniti_kernel_start, ksize);
	memcpy((void *)initrd, infiniti_initrd_start, rsize);
	memcpy((void *)fdt, infiniti_fdt_start, fsize);
	if (env_set_hex("infiniti_initrd_size", rsize) ||
	    env_set("bootargs", "rdinit=/init ro efi=noruntime console=tty0 loglevel=4 quiet splash oops=panic panic=5") ||
	    env_set("bootcmd", "echo Starting experimental Arch RAM payload; "
		"booti ${kernel_addr_r} ${ramdisk_addr_r}:${infiniti_initrd_size} ${fdt_addr_r}; "
		"echo Linux handoff failed - no storage fallback"))
		panic("Cannot set Infiniti RAM boot environment\n");
	printf("Infiniti RAM payload: kernel %zu, initrd %zu, FDT %zu bytes\n",
	       ksize, rsize, fsize);
}
