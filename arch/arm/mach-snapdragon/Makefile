# SPDX-License-Identifier: GPL-2.0+
#
# (C) Copyright 2015 Mateusz Kulikowski <mateusz.kulikowski@gmail.com>

obj-y += board.o
obj-$(CONFIG_EFI_HAVE_CAPSULE_SUPPORT) += capsule_update.o
obj-$(CONFIG_OF_LIVE) += of_fixup.o

obj-$(CONFIG_INFINITI_RAM_PAYLOAD) += infiniti-ram.o infiniti-ramboot.o
obj-$(CONFIG_INFINITI_FDT_CHECKPOINT) += infiniti-checkpoint.o
obj-$(CONFIG_INFINITI_BOARD_CHECKPOINT) += infiniti-checkpoint.o
obj-$(CONFIG_INFINITI_LATE_CHECKPOINT) += infiniti-checkpoint.o infiniti-late-checkpoint.o
