/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *                                        
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
//***** temporarily flag *******
#define CONFIG_SINGLE_IMG
//#define CONFIG_DISABLE_ODM
//for FPGA VERIFICATION config
#define RTL8188E_FPGA_TRUE_PHY_VERIFICATION 0

//***** temporarily flag *******
/*
 * Public  General Config
 */
#define AUTOCONF_INCLUDED
#define RTL871X_MODULE_NAME "8812AE"
#define DRV_NAME "rtl8812ae"


#define CONFIG_PCI_HCI	1


#define PLATFORM_LINUX	1


//#define CONFIG_IOCTL_CFG80211 1

#ifdef CONFIG_IOCTL_CFG80211
	//#define RTW_USE_CFG80211_STA_EVENT /* Indecate new sta asoc through cfg80211_new_sta */
	#define CONFIG_CFG80211_FORCE_COMPATIBLE_2_6_37_UNDER
	//#define CONFIG_DEBUG_CFG80211 
	//#define CONFIG_DRV_ISSUE_PROV_REQ // IOT FOR S2
	#define CONFIG_SET_SCAN_DENY_TIMER
#endif

/*
 * Internal  General Config
 */
//#define CONFIG_PWRCTRL
//#define CONFIG_H2CLBK

#define CONFIG_EMBEDDED_FWIMG	1
//#define CONFIG_FILE_FWIMG

#define CONFIG_XMIT_ACK
#ifdef CONFIG_XMIT_ACK
	#define CONFIG_ACTIVE_KEEP_ALIVE_CHECK
#endif

#define CONFIG_80211N_HT	1

#ifdef CONFIG_80211N_HT
	#define CONFIG_80211AC_VHT 1
	#define CONFIG_BEAMFORMING
#endif

#define CONFIG_RECV_REORDERING_CTRL	1

//#define CONFIG_TCP_CSUM_OFFLOAD_RX	1

//#define CONFIG_DRVEXT_MODULE	1

#define CONFIG_DFS	1

//#ifndef CONFIG_MP_INCLUDED
	#define CONFIG_IPS	1
	#ifdef CONFIG_IPS
	//#define CONFIG_IPS_LEVEL_2	1 //enable this to set default IPS mode to IPS_LEVEL_2
	//#define CONFIG_IPS_CHECK_IN_WD // Do IPS Check in WatchDog.	
	#endif
	//#define SUPPORT_HW_RFOFF_DETECTED	1

	#define CONFIG_LPS	1
	#if defined(CONFIG_LPS)
	//#define CONFIG_LPS_LCLK	1
	#endif

	#ifdef CONFIG_LPS_LCLK
	//#define CONFIG_XMIT_THREAD_MODE
	#endif

	//befor link
	//#define CONFIG_ANTENNA_DIVERSITY

	//after link
	#ifdef CONFIG_ANTENNA_DIVERSITY	 
	#define CONFIG_HW_ANTENNA_DIVERSITY		
	#endif


	//#define CONFIG_CONCURRENT_MODE 1
	#ifdef CONFIG_CONCURRENT_MODE
		//#define CONFIG_HWPORT_SWAP				//Port0->Sec , Port1 -> Pri
		#define CONFIG_RUNTIME_PORT_SWITCH
		//#define DBG_RUNTIME_PORT_SWITCH
		#define CONFIG_STA_MODE_SCAN_UNDER_AP_MODE
		//#ifdef CONFIG_RTL8812A
		//	#define CONFIG_TSF_RESET_OFFLOAD 1		// For 2 PORT TSF SYNC.
		//#endif
		//#define CONFIG_MULTI_VIR_IFACES //besides primary&secondary interfaces, extend to support more interfaces
	#endif

	//#define CONFIG_IOL
//#else 	//#ifndef CONFIG_MP_INCLUDED
	
//#endif 	//#ifndef CONFIG_MP_INCLUDED

#define CONFIG_AP_MODE	1
#ifdef CONFIG_AP_MODE	
	#define CONFIG_NATIVEAP_MLME
	#ifndef CONFIG_NATIVEAP_MLME
		#define CONFIG_HOSTAPD_MLME	1
	#endif			
	#define CONFIG_FIND_BEST_CHANNEL	1
	//#define CONFIG_NO_WIRELESS_HANDLERS	1
	//#define CONFIG_AUTO_AP_MODE
#endif

#define CONFIG_P2P	1
#ifdef CONFIG_P2P
	//The CONFIG_WFD is for supporting the Wi-Fi display
	#define CONFIG_WFD
	
	#ifndef CONFIG_WIFI_TEST
		#define CONFIG_P2P_REMOVE_GROUP_INFO
	#endif
	//#define CONFIG_DBG_P2P

	#define CONFIG_P2P_PS
	//#define CONFIG_P2P_IPS
	#define CONFIG_P2P_OP_CHK_SOCIAL_CH
	#define CONFIG_CFG80211_ONECHANNEL_UNDER_CONCURRENT  //replace CONFIG_P2P_CHK_INVITE_CH_LIST flag
	#define CONFIG_P2P_INVITE_IOT
#endif

//	Added by Kurt 20110511
//#define CONFIG_TDLS	1
#ifdef CONFIG_TDLS
//	#ifndef CONFIG_WFD
//		#define CONFIG_WFD	1
//	#endif
//	#define CONFIG_TDLS_AUTOSETUP			1
//	#define CONFIG_TDLS_AUTOCHECKALIVE		1
#endif


#define CONFIG_SKB_COPY	1//for amsdu

#define CONFIG_LED
#ifdef CONFIG_LED
	#define CONFIG_SW_LED
	#ifdef CONFIG_SW_LED
		//#define CONFIG_LED_HANDLED_BY_CMD_THREAD
	#endif
#endif // CONFIG_LED

#ifdef CONFIG_IOL
	#define CONFIG_IOL_READ_EFUSE_MAP
	//#define DBG_IOL_READ_EFUSE_MAP
	#define CONFIG_IOL_LLT
#endif

#define CONFIG_GLOBAL_UI_PID

#define CONFIG_LAYER2_ROAMING
#define CONFIG_LAYER2_ROAMING_RESUME
//#define CONFIG_ADAPTOR_INFO_CACHING_FILE // now just applied on 8192cu only, should make it general...
//#define CONFIG_RESUME_IN_WORKQUEUE
//#define CONFIG_SET_SCAN_DENY_TIMER
#define CONFIG_LONG_DELAY_ISSUE
#define CONFIG_NEW_SIGNAL_STAT_PROCESS
//#define CONFIG_SIGNAL_DISPLAY_DBM //display RX signal with dbm
#define RTW_NOTCH_FILTER 0 /* 0:Disable, 1:Enable, */
#define CONFIG_DEAUTH_BEFORE_CONNECT

#define CONFIG_BR_EXT	1	// Enable NAT2.5 support for STA mode interface with a L2 Bridge
#ifdef CONFIG_BR_EXT
#define CONFIG_BR_EXT_BRNAME	"br0"
#endif	// CONFIG_BR_EXT

#define CONFIG_TX_MCAST2UNI	1	// Support IP multicast->unicast
//#define CONFIG_CHECK_AC_LIFETIME 1	// Check packet lifetime of 4 ACs.


/* 
 * Interface  Related Config 
 */

 
/*
 * HAL  Related Config
 */
#define RTL8812A_RX_PACKET_INCLUDE_CRC	0

#define CONFIG_RX_PACKET_APPEND_FCS

#define ENABLE_NEW_RFE_TYPE	0

#define DISABLE_BB_RF	0

#ifdef CONFIG_MP_INCLUDED
	#define MP_DRIVER 1
	#define CONFIG_MP_IWPRIV_SUPPORT	1
#else
	#define MP_DRIVER 0
#endif

#ifdef CONFIG_EFUSE_CONFIG_FILE
	#define EFUSE_FILE_PATH			"/system/etc/wifi/wifi_efuse.map"
	#define MAC_ADDRESS_FILE_PATH	"/data/wifimac.txt"
#endif

/*
 * Platform  Related Config
 */
#ifdef CONFIG_PLATFORM_MN10300
	#define CONFIG_SPECIAL_SETTING_FOR_FUNAI_TV
	
	#if	defined (CONFIG_SW_ANTENNA_DIVERSITY)
		#undef CONFIG_SW_ANTENNA_DIVERSITY
		#define CONFIG_HW_ANTENNA_DIVERSITY
	#endif

	#if	defined (CONFIG_POWER_SAVING)
		#undef CONFIG_POWER_SAVING
	#endif
	
#endif//CONFIG_PLATFORM_MN10300

/*
 * Outsource  Related Config
 */

#define TESTCHIP_SUPPORT				0

#define RTL8192CE_SUPPORT 				0
#define RTL8192CU_SUPPORT 				0
#define RTL8192C_SUPPORT 				(RTL8192CE_SUPPORT|RTL8192CU_SUPPORT)	

#define RTL8192DE_SUPPORT 				0
#define RTL8192DU_SUPPORT 				0
#define RTL8192D_SUPPORT 				(RTL8192DE_SUPPORT|RTL8192DU_SUPPORT)	

#define RTL8723AU_SUPPORT				0
#define RTL8723AS_SUPPORT				0
#define RTL8723AE_SUPPORT				0
#define RTL8723A_SUPPORT				(RTL8723AU_SUPPORT|RTL8723AS_SUPPORT|RTL8723AE_SUPPORT)
#define RTL8723_FPGA_VERIFICATION		0

#define RTL8188E_SUPPORT				0

#ifdef CONFIG_RTL8812A
#define RTL8812A_SUPPORT				1
#else
#define RTL8812A_SUPPORT				0
#endif

#ifdef CONFIG_RTL8821A
#define RTL8821A_SUPPORT				1
#else
#define RTL8821A_SUPPORT				0
#endif

#define RTL8723B_SUPPORT				0
#define RTL8192E_SUPPORT				0
#define RTL8813A_SUPPORT				0

#define RATE_ADAPTIVE_SUPPORT 			0
#define POWER_TRAINING_ACTIVE			0

//#define 	CONFIG_TX_EARLY_MODE
#define	RTL8188E_EARLY_MODE_PKT_NUM_10	0

#define CONFIG_80211D

#define CONFIG_ATTEMPT_TO_FIX_AP_BEACON_ERROR

/*
 * Debug Related Config
 */
#define DBG	1

#define CONFIG_DEBUG /* DBG_871X, etc... */
//#define CONFIG_DEBUG_RTL871X /* RT_TRACE, RT_PRINT_DATA, _func_enter_, _func_exit_ */

#define CONFIG_PROC_DEBUG

#define DBG_CONFIG_ERROR_DETECT
//#define DBG_CONFIG_ERROR_DETECT_INT
//#define DBG_CONFIG_ERROR_RESET

//#define DBG_IO
//#define DBG_DELAY_OS
//#define DBG_MEM_ALLOC
//#define DBG_IOCTL

//#define DBG_TX
//#define DBG_XMIT_BUF
//#define DBG_XMIT_BUF_EXT
//#define DBG_TX_DROP_FRAME

//#define DBG_RX_DROP_FRAME
//#define DBG_RX_SEQ
//#define DBG_RX_SIGNAL_DISPLAY_PROCESSING
//#define DBG_RX_SIGNAL_DISPLAY_SSID_MONITORED "jeff-ap"



//#define DBG_SHOW_MCUFWDL_BEFORE_51_ENABLE
//#define DBG_ROAMING_TEST

//#define DBG_HAL_INIT_PROFILING

//#define DBG_MEMORY_LEAK	1

