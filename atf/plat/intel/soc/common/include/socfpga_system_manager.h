/*
 * Copyright (c) 2019-2020, Intel Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef SOCFPGA_SYSTEMMANAGER_H
#define SOCFPGA_SYSTEMMANAGER_H

#include "socfpga_plat_def.h"

/* System Manager Register Map */

#define SOCFPGA_SYSMGR_SDMMC				0x28

#define SOCFPGA_SYSMGR_EMAC_0				0x44
#define SOCFPGA_SYSMGR_EMAC_1				0x48
#define SOCFPGA_SYSMGR_EMAC_2				0x4c
#define SOCFPGA_SYSMGR_FPGAINTF_EN_3			0x70

#define SOCFPGA_SYSMGR_NOC_TIMEOUT			0xc0
#define SOCFPGA_SYSMGR_NOC_IDLEREQ_SET			0xc4
#define SOCFPGA_SYSMGR_NOC_IDLEREQ_CLR			0xc8
#define SOCFPGA_SYSMGR_NOC_IDLEREQ_VAL			0xcc
#define SOCFPGA_SYSMGR_NOC_IDLEACK			0xd0
#define SOCFPGA_SYSMGR_NOC_IDLESTATUS			0xd4

#define SOCFPGA_SYSMGR_BOOT_SCRATCH_COLD_0		0x200
#define SOCFPGA_SYSMGR_BOOT_SCRATCH_COLD_1		0x204
#define SOCFPGA_SYSMGR_BOOT_SCRATCH_COLD_2		0x208

/* Field Masking */

#define SYSMGR_SDMMC_DRVSEL(x)			(((x) & 0x7) << 0)

#define IDLE_DATA_LWSOC2FPGA				BIT(0)
#define IDLE_DATA_SOC2FPGA				BIT(4)
#define IDLE_DATA_MASK		(IDLE_DATA_LWSOC2FPGA | IDLE_DATA_SOC2FPGA)

#define SCR_AXI_AP_MASK					BIT(24)
#define SCR_FPGA2SOC_MASK				BIT(16)
#define SCR_MPU_MASK					BIT(0)
#define DISABLE_L4_FIREWALL	(SCR_AXI_AP_MASK | SCR_FPGA2SOC_MASK \
					| SCR_MPU_MASK)
#define DISABLE_BRIDGE_FIREWALL				0x0ffe0101

/* Macros */

#define SOCFPGA_SYSMGR(_reg)		(SOCFPGA_SYSMGR_REG_BASE \
						+ (SOCFPGA_SYSMGR_##_reg))

#define SOCFPGA_L4_PER_SCR(_reg)	(SOCFPGA_L4_PER_SCR_REG_BASE \
					+ (SOCFPGA_NOC_FW_L4_PER_SCR_##_reg))

#define SOCFPGA_L4_SYS_SCR(_reg)	(SOCFPGA_L4_SYS_SCR_REG_BASE \
					+ (SOCFPGA_NOC_FW_L4_SYS_SCR_##_reg))

/* L3 Interconnect Register Map */
#define SOCFPGA_NOC_FW_L4_PER_SCR_NAND_REGISTER			0x0000
#define SOCFPGA_NOC_FW_L4_PER_SCR_NAND_DATA			0x0004
#define SOCFPGA_NOC_FW_L4_PER_SCR_USB0_REGISTER			0x000c
#define SOCFPGA_NOC_FW_L4_PER_SCR_USB1_REGISTER			0x0010
#define SOCFPGA_NOC_FW_L4_PER_SCR_SPI_MASTER0			0x001c
#define SOCFPGA_NOC_FW_L4_PER_SCR_SPI_MASTER1			0x0020
#define SOCFPGA_NOC_FW_L4_PER_SCR_SPI_SLAVE0			0x0024
#define SOCFPGA_NOC_FW_L4_PER_SCR_SPI_SLAVE1			0x0028
#define SOCFPGA_NOC_FW_L4_PER_SCR_EMAC0				0x002c
#define SOCFPGA_NOC_FW_L4_PER_SCR_EMAC1				0x0030
#define SOCFPGA_NOC_FW_L4_PER_SCR_EMAC2				0x0034
#define SOCFPGA_NOC_FW_L4_PER_SCR_SDMMC				0x0040
#define SOCFPGA_NOC_FW_L4_PER_SCR_GPIO0				0x0044
#define SOCFPGA_NOC_FW_L4_PER_SCR_GPIO1				0x0048
#define SOCFPGA_NOC_FW_L4_PER_SCR_I2C0				0x0050
#define SOCFPGA_NOC_FW_L4_PER_SCR_I2C1				0x0054
#define SOCFPGA_NOC_FW_L4_PER_SCR_I2C2				0x0058
#define SOCFPGA_NOC_FW_L4_PER_SCR_I2C3				0x005c
#define SOCFPGA_NOC_FW_L4_PER_SCR_I2C4				0x0060
#define SOCFPGA_NOC_FW_L4_PER_SCR_SP_TIMER0			0x0064
#define SOCFPGA_NOC_FW_L4_PER_SCR_SP_TIMER1			0x0068
#define SOCFPGA_NOC_FW_L4_PER_SCR_UART0				0x006c
#define SOCFPGA_NOC_FW_L4_PER_SCR_UART1				0x0070

#define SOCFPGA_NOC_FW_L4_SYS_SCR_DMA_ECC			0x0008
#define SOCFPGA_NOC_FW_L4_SYS_SCR_EMAC0RX_ECC			0x000c
#define SOCFPGA_NOC_FW_L4_SYS_SCR_EMAC0TX_ECC			0x0010
#define SOCFPGA_NOC_FW_L4_SYS_SCR_EMAC1RX_ECC			0x0014
#define SOCFPGA_NOC_FW_L4_SYS_SCR_EMAC1TX_ECC			0x0018
#define SOCFPGA_NOC_FW_L4_SYS_SCR_EMAC2RX_ECC			0x001c
#define SOCFPGA_NOC_FW_L4_SYS_SCR_EMAC2TX_ECC			0x0020
#define SOCFPGA_NOC_FW_L4_SYS_SCR_NAND_ECC			0x002c
#define SOCFPGA_NOC_FW_L4_SYS_SCR_NAND_READ_ECC			0x0030
#define SOCFPGA_NOC_FW_L4_SYS_SCR_NAND_WRITE_ECC		0x0034
#define SOCFPGA_NOC_FW_L4_SYS_SCR_OCRAM_ECC			0x0038
#define SOCFPGA_NOC_FW_L4_SYS_SCR_SDMMC_ECC			0x0040
#define SOCFPGA_NOC_FW_L4_SYS_SCR_USB0_ECC			0x0044
#define SOCFPGA_NOC_FW_L4_SYS_SCR_USB1_ECC			0x0048
#define SOCFPGA_NOC_FW_L4_SYS_SCR_CLK_MGR			0x004c
#define SOCFPGA_NOC_FW_L4_SYS_SCR_IO_MGR			0x0054
#define SOCFPGA_NOC_FW_L4_SYS_SCR_RST_MGR			0x0058
#define SOCFPGA_NOC_FW_L4_SYS_SCR_SYS_MGR			0x005c
#define SOCFPGA_NOC_FW_L4_SYS_SCR_OSC0_TIMER			0x0060
#define SOCFPGA_NOC_FW_L4_SYS_SCR_OSC1_TIMER			0x0064
#define SOCFPGA_NOC_FW_L4_SYS_SCR_WATCHDOG0			0x0068
#define SOCFPGA_NOC_FW_L4_SYS_SCR_WATCHDOG1			0x006c
#define SOCFPGA_NOC_FW_L4_SYS_SCR_WATCHDOG2			0x0070
#define SOCFPGA_NOC_FW_L4_SYS_SCR_WATCHDOG3			0x0074
#define SOCFPGA_NOC_FW_L4_SYS_SCR_DAP				0x0078
#define SOCFPGA_NOC_FW_L4_SYS_SCR_L4_NOC_PROBES			0x0090
#define SOCFPGA_NOC_FW_L4_SYS_SCR_L4_NOC_QOS			0x0094

#define SOCFPGA_CCU_NOC_CPU0_RAMSPACE0_0			0xf7004688
#define SOCFPGA_CCU_NOC_IOM_RAMSPACE0_0				0xf7018628

void enable_ns_peripheral_access(void);
void enable_ns_bridge_access(void);

#endif /* SOCFPGA_SYSTEMMANAGER_H */
