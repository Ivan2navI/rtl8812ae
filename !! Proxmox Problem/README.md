# RTL8812AE Proxmox

```console
root@pve:~# dmesg | grep rtl
[   18.317275] rtl8821ae: Using firmware rtlwifi/rtl8812aefw.bin
[   18.317282] rtl8821ae: Using firmware rtlwifi/rtl8812aefw_wowlan.bin
[   18.319987] ieee80211 phy0: Selected rate control algorithm 'rtl_rc'
[   18.320487] rtlwifi: rtlwifi: wireless switch is on
[   18.463905] rtl8821ae 0000:09:00.0 wlp9s0: renamed from wlan0
[   18.532181] rtl8821ae 0000:09:00.0: Direct firmware load for rtlwifi/rtl8812aefw.bin failed with error -2
[   18.532232] rtl8821ae 0000:09:00.0: Direct firmware load for rtlwifi/rtl8812aefw_wowlan.bin failed with error -2
[   18.810541] rtlwifi: Loading alternative firmware rtlwifi/rtl8821aefw.bin
[   18.810551] rtlwifi: Loading alternative firmware rtlwifi/rtl8821aefw.bin
[   35.573647] rtl8821ae: Polling FW ready fail!! REG_MCUFWDL:0x00070706 .
[   35.922323] rtl8821ae: Polling FW ready fail!! REG_MCUFWDL:0x00070706 .
[   36.393447] rtl8821ae: Polling FW ready fail!! REG_MCUFWDL:0x00070706 .
[   40.049367] rtl8821ae: Polling FW ready fail!! REG_MCUFWDL:0x00070706 .
[   45.144770] rtl8821ae: Polling FW ready fail!! REG_MCUFWDL:0x00070706 .
[   52.146812] rtl8821ae: Polling FW ready fail!! REG_MCUFWDL:0x00070706 .
[   62.150548] rtl8821ae: Polling FW ready fail!! REG_MCUFWDL:0x00070706 .
[   76.150716] rtl8821ae: Polling FW ready fail!! REG_MCUFWDL:0x00070706 .
[   96.146995] rtl8821ae: Polling FW ready fail!! REG_MCUFWDL:0x00070706 .
[  125.144148] rtl8821ae: Polling FW ready fail!! REG_MCUFWDL:0x00070706 .
[  168.147659] rtl8821ae: Polling FW ready fail!! REG_MCUFWDL:0x00070706 .


root@pve:~# lspci -nnk | grep -iA3 net
04:00.0 Ethernet controller [0200]: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller [10ec:8168] (rev 15)
        Subsystem: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller [10ec:0123]
        Kernel driver in use: r8169
        Kernel modules: r8169
05:00.0 Ethernet controller [0200]: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller [10ec:8168] (rev 15)
        Subsystem: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller [10ec:0123]
        Kernel driver in use: r8169
        Kernel modules: r8169
06:00.0 Ethernet controller [0200]: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller [10ec:8168] (rev 15)
        Subsystem: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller [10ec:0123]
        Kernel driver in use: r8169
        Kernel modules: r8169
07:00.0 Ethernet controller [0200]: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller [10ec:8168] (rev 15)
        Subsystem: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller [10ec:0123]
        Kernel driver in use: r8169
        Kernel modules: r8169
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
09:00.0 Network controller [0280]: Realtek Semiconductor Co., Ltd. RTL8812AE 802.11ac PCIe Wireless Network Adapter [10ec:8812] (rev 01)
        Subsystem: Realtek Semiconductor Co., Ltd. RTL8812AE 802.11ac PCIe Wireless Network Adapter [10ec:8812]
        Kernel driver in use: rtl8821ae
        Kernel modules: rtl8821ae
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
0a:00.0 Ethernet controller [0200]: Realtek Semiconductor Co., Ltd. RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller [10ec:8168] (rev 06)
        Subsystem: Dell RTL8111/8168/8411 PCI Express Gigabit Ethernet Controller [1028:04f5]
        Kernel driver in use: r8169
        Kernel modules: r8169

# (Not RTL8812AE)
root@pve:~# modinfo rtl8821ae
filename:       /lib/modules/5.15.107-1-pve/kernel/drivers/net/wireless/realtek/rtlwifi/rtl8821ae/rtl8821ae.ko
firmware:       rtlwifi/rtl8821aefw_29.bin
firmware:       rtlwifi/rtl8821aefw.bin
description:    Realtek 8821ae 802.11ac PCI wireless
license:        GPL
author:         Realtek WlanFAE <wlanfae@realtek.com>
srcversion:     C66A8DD0CE766ECC210B689
alias:          pci:v000010ECd00008821sv*sd*bc*sc*i*
alias:          pci:v000010ECd00008812sv*sd*bc*sc*i*
depends:        rtlwifi,rtl_pci,btcoexist,mac80211
retpoline:      Y
intree:         Y
name:           rtl8821ae
vermagic:       5.15.107-1-pve SMP mod_unload modversions
parm:           swenc:Set to 1 for software crypto (default 0)
 (bool)
parm:           ips:Set to 0 to not use link power save (default 1)
 (bool)
parm:           swlps:Set to 1 to use SW control power save (default 0)
 (bool)
parm:           fwlps:Set to 1 to use FW control power save (default 1)
 (bool)
parm:           msi:Set to 1 to use MSI interrupts mode (default 1)
 (bool)
parm:           aspm:Set to 1 to enable ASPM (default 1)
 (int)
parm:           debug_level:Set debug level (0-5) (default 0) (int)
parm:           debug_mask:Set debug mask (default 0) (ullong)
parm:           disable_watchdog:Set to 1 to disable the watchdog (default 0)
 (bool)
parm:           int_clear:Set to 0 to disable interrupt clear before set (default 1)
 (bool)        
```
