/*
 * QEMU RISC-V Board Compatible with Tillitis TK1 platform
 *
 * Copyright (c) 2022 Tillitis AB
 * SPDX-License-Identifier: GPL-2.0-only
 */

// clang-format off

#ifndef TK1_MEM_H
#define TK1_MEM_H

// The canonical location of this file is:
// repo: https://github.com/tillitis/tillitis-key1
// path: /hw/application_fpga/fw/tk1_mem.h

// The contents are derived from the Verilog code. For use by QEMU model,
// firmware, and apps.

enum {
    TK1_ROM_BASE       = 0x00000000, // 0b00000000...
    TK1_RAM_BASE       = 0x40000000, // 0b01000000...
    TK1_RAM_SIZE       = 0x20000,    // 128 KB
    TK1_RESERVED_BASE  = 0x80000000, // 0b10000000...
    TK1_MMIO_BASE      = 0xc0000000, // 0b11000000...
    TK1_MMIO_SIZE      = 0xffffffff - TK1_MMIO_BASE,

    TK1_APP_ADDR       = TK1_RAM_BASE + 0x7000, // 28 KB of stack
    TK1_APP_MAX_SIZE   = TK1_RAM_SIZE - (TK1_APP_ADDR - TK1_RAM_BASE),

    TK1_MMIO_TRNG_BASE        = TK1_MMIO_BASE | 0x00000000,
    TK1_MMIO_TIMER_BASE       = TK1_MMIO_BASE | 0x01000000,
    TK1_MMIO_UDS_BASE         = TK1_MMIO_BASE | 0x02000000,
    TK1_MMIO_UART_BASE        = TK1_MMIO_BASE | 0x03000000,
    TK1_MMIO_TOUCH_BASE       = TK1_MMIO_BASE | 0x04000000,
    TK1_MMIO_FW_RAM_BASE      = TK1_MMIO_BASE | 0x10000000,
    TK1_MMIO_FW_RAM_SIZE      = 1024,
    // This "core" only exists in QEMU
    TK1_MMIO_QEMU_BASE        = TK1_MMIO_BASE | 0x3e000000,
    TK1_MMIO_TK1_BASE         = TK1_MMIO_BASE | 0x3f000000, // 0xff000000

    TK1_NAME0_SUFFIX   = 0x00,
    TK1_NAME1_SUFFIX   = 0x04,
    TK1_VERSION_SUFFIX = 0x08,

    TK1_MMIO_TRNG_STATUS      = TK1_MMIO_TRNG_BASE | 0x24,
    TK1_MMIO_TRNG_STATUS_READY_BIT = 0,
    TK1_MMIO_TRNG_ENTROPY     = TK1_MMIO_TRNG_BASE | 0x80,

    TK1_MMIO_TIMER_CTRL       = TK1_MMIO_TIMER_BASE | 0x20,
    TK1_MMIO_TIMER_STATUS     = TK1_MMIO_TIMER_BASE | 0x24,
    TK1_MMIO_TIMER_STATUS_READY_BIT = 0,
    TK1_MMIO_TIMER_PRESCALER  = TK1_MMIO_TIMER_BASE | 0x28,
    TK1_MMIO_TIMER_TIMER      = TK1_MMIO_TIMER_BASE | 0x2c,

    TK1_MMIO_UDS_FIRST        = TK1_MMIO_UDS_BASE | 0x40,
    TK1_MMIO_UDS_LAST         = TK1_MMIO_UDS_BASE | 0x5c, // Address of last 32-bit word of UDS

    TK1_MMIO_UART_BIT_RATE    = TK1_MMIO_UART_BASE | 0x40,
    TK1_MMIO_UART_DATA_BITS   = TK1_MMIO_UART_BASE | 0x44,
    TK1_MMIO_UART_STOP_BITS   = TK1_MMIO_UART_BASE | 0x48,
    TK1_MMIO_UART_RX_STATUS   = TK1_MMIO_UART_BASE | 0x80,
    TK1_MMIO_UART_RX_DATA     = TK1_MMIO_UART_BASE | 0x84,
    TK1_MMIO_UART_TX_STATUS   = TK1_MMIO_UART_BASE | 0x100,
    TK1_MMIO_UART_TX_DATA     = TK1_MMIO_UART_BASE | 0x104,

    TK1_MMIO_TOUCH_STATUS     = TK1_MMIO_TOUCH_BASE | 0x24,
    TK1_MMIO_TOUCH_STATUS_EVENT_BIT = 0,

    // TODO HW core/addr is not yet defined for this:
    TK1_MMIO_QEMU_UDA         = TK1_MMIO_QEMU_BASE | 0x20,
    // This will only ever exist in QEMU:
    TK1_MMIO_QEMU_DEBUG       = TK1_MMIO_QEMU_BASE | 0x1000,

    TK1_MMIO_TK1_NAME0        = TK1_MMIO_TK1_BASE | TK1_NAME0_SUFFIX,
    TK1_MMIO_TK1_NAME1        = TK1_MMIO_TK1_BASE | TK1_NAME1_SUFFIX,
    TK1_MMIO_TK1_VERSION      = TK1_MMIO_TK1_BASE | TK1_VERSION_SUFFIX,
    TK1_MMIO_TK1_SWITCH_APP   = TK1_MMIO_TK1_BASE | 0x20,
    TK1_MMIO_TK1_LED          = TK1_MMIO_TK1_BASE | 0x24,
    TK1_MMIO_TK1_LED_R_BIT    = 2,
    TK1_MMIO_TK1_LED_G_BIT    = 1,
    TK1_MMIO_TK1_LED_B_BIT    = 0,
    TK1_MMIO_TK1_GPIO         = TK1_MMIO_TK1_BASE | 0x28,
    TK1_MMIO_TK1_GPIO1_BIT    = 0,
    TK1_MMIO_TK1_GPIO2_BIT    = 1,
    TK1_MMIO_TK1_GPIO3_BIT    = 2,
    TK1_MMIO_TK1_GPIO4_BIT    = 3,
    TK1_MMIO_TK1_APP_ADDR     = TK1_MMIO_TK1_BASE | 0x30,
    TK1_MMIO_TK1_APP_SIZE     = TK1_MMIO_TK1_BASE | 0x34,
    TK1_MMIO_TK1_CDI_FIRST    = TK1_MMIO_TK1_BASE | 0x80,
    TK1_MMIO_TK1_CDI_LAST     = TK1_MMIO_TK1_BASE | 0x9c, // Address of last 32-bit word of CDI.
    TK1_MMIO_TK1_UDI_FIRST    = TK1_MMIO_TK1_BASE | 0xc0,
    TK1_MMIO_TK1_UDI_LAST     = TK1_MMIO_TK1_BASE | 0xc4, // Address of last 32-bit word of UDI.
};

#endif
