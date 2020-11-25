/*
 * ZBOSS Zigbee 3.0
 *
 * Copyright (c) 2012-2020 DSR Corporation, Denver CO, USA.
 * http://www.dsr-zboss.com
 * http://www.dsr-corporation.com
 * All rights reserved.
 *
 *
 * Use in source and binary forms, redistribution in binary form only, with
 * or without modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 2. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 3. This software, with or without modification, must only be used with a Nordic
 *    Semiconductor ASA integrated circuit.
 *
 * 4. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*  PURPOSE: Common constants and definitions, mainly related to Zigbee protocol.
*/
#ifndef ZB_CONFIG_COMMON_H
#define ZB_CONFIG_COMMON_H 1

/*
Note: that file included form the very beginning of zb_config.h
Do not put there ifdefs depending on defines made in the middle of zb_config.h!
 */

/*! \addtogroup ZB_CONFIG */
/*! @{ */
/**@cond internals_doc*/
/* To compile MAC only build;
   TODO: Fix it. there should probably be another way to build without security
*/
/** @endcond *//* internals_doc */
/****************************Security options**************************/

/****************************Security keys***************************/

/* Always security on (both NWK and APS). Remove all special security configs */

/*
4.6.3.2.2.1 Standard Security Mode

A default global trust center link key must be supported by the device if no other
link key is specified by the application at the time of joining. This default link key
shall have a value of 5A 69 67 42 65 65 41 6C 6C 69 61 6E 63 65 30 39
(ZigbeeAlliance09).44
 */
/*! Define a default global trust center link key */
#define ZB_STANDARD_TC_KEY {0x5A, 0x69, 0x67, 0x42, 0x65, 0x65, 0x41, 0x6C, 0x6C, 0x69, 0x61, 0x6E, 0x63, 0x65, 0x30, 0x39 };


/**
 In ZLL specification this is ZLL Certification pre-installed link key - see
 8.7.2 Transfer ring the network key during classical Zigbee commissioning.


 The distributed security global link key is used to join a distributed security
 network. This link key is provided to a company as a result of a successful
 certification of a product. For testing, this key SHALL have this default value.


 See Base Device Behaviour Specification subclause 6.3.2 Distributed security global link key
 */
#define ZB_DISTRIBUTED_GLOBAL_KEY {0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf};

/** @cond touchlink */

/**
6.3.4 Touchlink preconfigured link key

The touchlink preconfigured link key is used to join a network via
touchlink. This link key is provided to a company as a result of a
successful certification of a product. For testing, this key SHALL have the
value of:

In ZLL specification this is 8.7.5.1.2 Certification key (key index 15)

In BDB 8.7.1.2 Key index and encrypted network key fields.
"This value SHALL be set to 0x04 during certification testing or 0x0f at all
other times."
In ZLL Table 67 Key encryption algorithms: 4 is Master key, 0xf is Certification
key. They use same algorithm.

 */
#define ZB_TOUCHLINK_PRECONFIGURED_KEY {0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf};

/** @endcond */ /* touchlink */

/* BDB does not mention using of Development ZLL key, so skip it. */
/** @cond internals_doc */
/**
 SECUR: if defined, implement Standard security

 @note High Security is obsolete and will never be implemented.
*/
#define ZB_STANDARD_SECURITY

/**
 SECUR: If defined, generate random keys at Trust Center at start of pre-configured key is not set.
*/
#define ZB_TC_GENERATES_KEYS

/* (currently - always)*/  
/**
 SECUR: If defined, trust Center is at ZC
*/
#define ZB_TC_AT_ZC
/** @endcond */ /* internals_doc */
/**
 SECUR: CCM key size. Hard-coded
*/
#define ZB_CCM_KEY_SIZE 16

/* NLS5 - All devices shall maintain at least 2 NWK keys with the frame
   counters consistent with the security mode of the network (Standard or High).*/
/*! Define number of network keys with the frame counter */
#define ZB_SECUR_N_SECUR_MATERIAL 3


/* parameters for security level 5 - the only security level supported */
/**
 SECUR: security level. Now fixed to be 5
*/
#define ZB_SECURITY_LEVEL 5
/** @cond internals_doc */
/*!
 CCM L parameter for security level 5.
*/
#define ZB_CCM_L 2

/*!
 CCM nonce length.
*/
#define ZB_CCM_NONCE_LEN  (15 - ZB_CCM_L)

/*!
 CCM M parameter for security level 5
*/
#define ZB_CCM_M 4

/*!
 Value of nwk packets counter which trigger nwk key switch
*/
#define ZB_SECUR_NWK_COUNTER_LIMIT (((zb_uint32_t)~0) - 128)

//#define ZB_DEFAULT_SECURE_ALL_FRAMES 0
/*!
 Default value for nib.secure_all_frames
*/
#define ZB_DEFAULT_SECURE_ALL_FRAMES 1

/*!
   Include long address into APS security header
 */
#define ZB_APS_SECUR_APS_USE_EXT_NONCE

/*!
  This macro defines total number of NWK frame unsecure attempts before NWK decides that
  frame can not be processed. Made as Workaround.
  If frame was not unsecured, cut 1 byte of buffer end and try to unsecure frame again.
 */
//#define ZB_NWK_SECUR_UNSECURE_FRAME_ATTEMPTS 4


/****************************APS layer options**************************/



/* APS */

/*
   APS: dup check timeout.

   APS dup checks resolution is 1 sec, so dup timeout is 21 sec. This
   interval guaranties total APS retransmission interval (1 original + 2 retransmits).
*/
/*! Dup check timeout */
#define ZB_APS_DUP_INITIAL_CLOCK 21
/*! Sets APS dup checks time out. By default it is 21 sec. This
*  interval guaranties total APS retransmission interval (1 original + 2 retransmits).
*/
#define ZB_APS_DUP_CHECK_TIMEOUT ZB_MILLISECONDS_TO_BEACON_INTERVAL(1000)

#ifndef ZB_APS_DUPS_TABLE_SIZE
/**
  * APS dups table size.
  *
  * @note This is a default value of the define. This value can be changed by user.
  */
#define ZB_APS_DUPS_TABLE_SIZE 32
#endif

/** @endcond *//* internals_doc */
/*!
   Maximum MAC packet waiting time to expire
 */
  #define ZB_MAC_INDIRECT_POLL_EXPIRE_TMO ZB_MILLISECONDS_TO_BEACON_INTERVAL(7680)



/**
   APS retransmissions
 */

/*
 APS: max number of packets waiting for APS ACK

 Derive it from the pool size. Keep some free buffers in the pool, remember some
 buffers are reserved at start (I see 4 out buffers reserved).
*/
#ifndef ZB_CONFIGURABLE_MEM
/**
 * APS: maximum number of packets waiting for APS ACK
 *
 * @note This is a default value of the define. This value can be changed by user.
 */
  #define ZB_N_APS_RETRANS_ENTRIES   ((ZB_IOBUF_POOL_SIZE / 3) > 0 ? (ZB_IOBUF_POOL_SIZE / 3) : (ZB_IOBUF_POOL_SIZE / 2))
#endif

/**
 * APS maximum of apscMaxFrameRetries times
 *
 * See Zigbee specification revision 22 section 2.2.7.1 APS Constants
*/
  #define ZB_N_APS_MAX_FRAME_RETRIES 3


/*!
 APS: APS ACK wait time from Sleepy devices. After this timeout resend APS packet
      see Zigbee specification revision 22 section 2.2.7.1 APS Constants
*/
  #define ZB_N_APS_ACK_WAIT_DURATION_FROM_SLEEPY (10*ZB_TIME_ONE_SECOND)
/** @cond internals_doc */
/*!
 APS: The base amount of delay before each broadcast parent announce is sent.
 */
#define ZB_APS_PARENT_ANNOUNCE_BASE_TIMER  (10 * ZB_TIME_ONE_SECOND)

/*!
The max amount of jitter that is added to the apsParentAnnounceBaseTimer before each broadcast parent announce is sent.
*/
#define ZB_APS_PARENT_ANNOUNCE_JITTER_MAX (10 * ZB_TIME_ONE_SECOND)
/** @endcond */ /*internals_doc*/

/**
 * APS: APS ACK wait time from Non Sleepy devices. After this timeout resend APS packet
 *
 *  See Zigbee specification revision 22 section 2.2.7.1 APS Constants
*/
  /* Some devices send APS_ACK to AF and ZDO commands after sending appropriate response or
   * DefaultResponse. For example, ZCL On/Off command can be done within 5-7 seconds,
   * so 2 seconds for wail duration is insufficiently. */
  #define ZB_N_APS_ACK_WAIT_DURATION_FROM_NON_SLEEPY (3*ZB_TIME_ONE_SECOND)

/**
 APS: maximum number of tables with information from a binding table to be sent to the devices
*/
  #define ZB_N_APS_BINDTRANS_ARR_MAX_SIZE            5

/**
 * APS: maximum number of elements in array with index from dst array in bind table
*/
  #define ZB_N_APS_BINDTRANS_DST_INDEX_ARR_MAX_SIZE  ZB_APS_DST_BINDING_TABLE_SIZE

/** @cond internals_doc */
/* Origin of this tweak is R21 version of core stack */
/* Also it is a kind of "everybody knows" issue */
/**
   Disable APS acknowledgement request bit in APS commands.
*/
#define ZB_APS_DISABLE_ACK_IN_COMMANDS
/** @endcond *//*internals_doc*/

/* EE: wrong place for that constant in zb_aps.h (this is not public APS API!) and wrong
 * calculation!
 * BTW that constant used at 1 place only.
 * ZB_ZDO_MAX_PAYLOAD_SIZE in zb_zdo.h is hard-coded!
 * And, zb_zdo.h is also bad place for it.
 *
 * Let's count supposing no APS security.
 * MAC header - 10 with fcf (suppose Pan ID compression)
 * NWK header - 24 unicast, but 16 broadcast
 * NWK ZB security header + MIC - cf 1 + fcnt 4 + ext src 8 + key seq 1 mic 4 = 18
 * APS hdr 8b
 * Totally for broadcast - 127 - (11+16+18+8) = 74
 * For unicast 74-8 = 66

Fixed that size for the certification test TP/R21/BV-24.
We actually fit 5 parent annce records into 127 bytes only for broadcast tx,
with Pan ID compression.

At the worst case our NWK can skip long address at tx: 8 bytes of reserve.

 */
/**@cond internals_doc*/
/*! Maximum broadcast APS payload size */
#define ZB_APS_MAX_BROADCAST_PAYLOAD_SIZE 74U
/**
   Maximum broadcast APS payload size supposing NWK encryption only, no long
   address in NWK header. That means definitely the largest possible size.
 */
#define ZB_APS_MAX_MAX_BROADCAST_PAYLOAD_SIZE (74U + 8U)

/**
   MAC hdr:
   3 (hdr, seq num) + 2 * 3  (short dst and src; dst panid)
   NWK hdr:
   4 + 2*2 (dst, src short) + 8*2 (dst, src long)
   NWK security:  18
   APS hdr: 8 (max, without ext header and security)
   MAC footer: 2

   Total: 69 bytes
   So we can send: 127-69 = 58 bytes
*/
#define ZB_APS_GUARANTEED_PAYLOAD_SIZE_WO_SECURITY 58

/**
   Maximum number of bytes that is additionally occupied by APS security (in case of extended nonce)
*/
#define ZB_APS_MAX_APS_SECURITY_SIZE 17

/**
   Maximal frame size
 */
#define MAX_PHY_FRM_SIZE              127U

/* ZB packet length must not exceed 127 bytes
 *
 * Old calculation by Maxim:
 *
 * MAC header (total: 11 bytes)
 * - FCF: 2 bytes
 * - Sequence number: 1 bytes
 * - PAN: 2 bytes
 * - Destination address: 2 bytes
 * - Source address: 2 bytes
 *
 * NWK header (total: 24 bytes)
 * - FCF: 2 bytes
 * - Destination short address: 2 bytes
 * - Source short address: 2 bytes
 * - Radius: 1 byte
 * - Sequence number: 1 byte
 * - Destination long address: 8 bytes
 * - Source long address: 8 bytes
 *
 * ZB security header (total: 31 bytes)
 *
 * APS header (total: 8 bytes)
 * - FCF: 1 byte
 * - Destination endpoint: 1 byte
 * - Cluster ID: 2 bytes
 * - Profile ID: 2 bytes
 * - Source endpoint: 1 byte
 * - Counter: 1 byte
 *
 * APS payload (total: variable length)
 *
 * MAC footer (total: 2 bytes)
 * - FCS: 2 bytes
 *
 * Total length w/o APS payload: 127-(11+24+31+8+2)= 51 bytes,
 * consequently APS payload max size is 51 bytes.
 */
/*
 * MAC (short source, short destination): MAX_MAC_OVERHEAD_SHORT_ADDRS bytes
 * NWK (broadcast, no destination IEEE): 16 bytes header + 18 bytes security
 * Total length: 127-(11+16+18) = 82 bytes  */
 /* nwk hdr include source IEEE address */

/*! Maximum broadcast NWK header size */
#define ZB_NWK_MAX_BROADCAST_HDR_SIZE 16
/*! Maximum security NWK header size */
#define ZB_NWK_MAX_SECURITY_HDR_SIZE 18
/*! Maximum broadcast NWK payload size */
#define ZB_NWK_MAX_BROADCAST_PAYLOAD_SIZE (MAX_PHY_FRM_SIZE - (MAX_MAC_OVERHEAD_SHORT_ADDRS + \
  ZB_NWK_MAX_BROADCAST_HDR_SIZE + ZB_NWK_MAX_SECURITY_HDR_SIZE))
/** @endcond */ /* internals_doc */
/*!
 * Maximum unicast APS payload size, if no APS encryption is provided
 */
#define ZB_APS_MAX_PAYLOAD_SIZE (ZB_APS_MAX_BROADCAST_PAYLOAD_SIZE - 8)
/** @cond internals_doc */
/*! Maximum ZDO payload size */
#define ZB_ZDO_MAX_PAYLOAD_SIZE (ZB_APS_MAX_PAYLOAD_SIZE-1)
/*! The size of the MAC header used by the Zigbee NWK layer. */
#define ZB_NWKC_MAC_FRAME_OVERHEAD 0xB
/*! The minimum number of octets added by the NWK layer to an NSDU. */
#define ZB_NWKC_MIN_HEADER_OVERHEAD 0x8

/*!
 * The number of network layer retries on unicast messages that are attempted before
 * reporting the result to the higher layer. It must be at least 3.
 * Value: 3
 */
#define ZB_NWKC_UNICAST_RETRIES 3

/*!
 * The delay between network layer retries.
 * Value: 50 ms
 */
#define ZB_NWKC_UNICAST_RETRY_DELAY ZB_MILLISECONDS_TO_BEACON_INTERVAL(50)

/* max nsdulength = aMaxPHYFrameSize -(nwkcMACFrameOverhead + nwkcMinHeaderOverhead) (D.4 aMaxMACFrameSize) */
/*! Maximum NSDU(Network Service Data Unit) length */
#define ZB_NSDU_MAX_LEN (MAX_PHY_FRM_SIZE - (ZB_NWKC_MAC_FRAME_OVERHEAD + ZB_NWKC_MIN_HEADER_OVERHEAD))
/*! The minimum number of octets added by the APS sub-layer to an ASDU. */
#define ZB_APSC_MIN_HEADER_OVERHEAD 0x0C
/* max asdu length 256*(NsduLength - apscMinHeaderOverhead); currently fragmentation
 * is not supported  */
/*! Maximum ASDU(APS service data unit) length*/
#define ZB_ASDU_MAX_LEN (ZB_NSDU_MAX_LEN - ZB_APSC_MIN_HEADER_OVERHEAD)

/* 06/20/2017 EE CR:MAJOR can't always count extra header bytes when calculating max packet length. It is not optimal, and we even may not pass tests checking for max payload length */
/* NK: Agree, but this define is called MAX_LEN, and includes maximum possible data. Better to
 * calculate maximum payload length dynamically (based on fragmentation, destination addr,
 * security mode etc).
 * Anyway, there are not too many cases where we use ZB_APS_HEADER_MAX_LEN or
 * ZB_APS_PAYLOAD_MAX_LEN.
 * EE: Can't we assert in zb_zdo_nwk_upd_notify()? You can define 2 constants: fragmented and not.
 */

/*  2 stands for  fc + aps counter( Packet either has dest and src endpoints (1+1 byte) if not group
* addressing or Group address elsewhere - so 2 anyway)
* + 2(cluster ID, profile ID)*
* + 4(fragmentation and Extended header are NOT included
*     TODO: handle fragmentation and Extended header.*)
* + 1(Security control field)
* + 4(Frame Counter)
* + 4(Message Integrity Code)
* + 0
*/

/*! Maximum length of APS header */
#define ZB_APS_HEADER_MAX_LEN (17)

/*! Maximum length of an APS payload.*/
#define ZB_APS_PAYLOAD_MAX_LEN ZB_ASDU_MAX_LEN - ZB_APS_HEADER_MAX_LEN

/* 01/24/2018 EE CR:MINOR Better move it out of zb_config.common.h */
/* Value 3 in this define comes for fragmentation and ext header  */
/*Take into account that ZB_ASDU_MAX_LEN counts minimum overhead, but it is sometimes
* impossible to send pkt with these conditions; add 10 more bytes for nwk security etc
*/
/*!
 * Length of an APS payload fragment
 * @param short_addr - address of the buffer containing APS fragment
 */
#define ZB_APS_FRAG_PAYLOAD_LEN(short_addr) ((zb_aps_get_max_buffer_size(short_addr)>40+ZB_APS_HEADER_MAX_LEN)?\
   (zb_aps_get_max_buffer_size(short_addr) - ZB_APS_HEADER_MAX_LEN \
   - 3                               \
   - 37 ):21)
/*!
 *   Maximum number of APS fragments
 *   See Zigbee specification revision 22 section 2.2.8.4.5 Fragmented Transmissions
 */
#define ZB_APS_MAX_FRAGMENT_NUM 8

/*!
*   Maximum number of fragments which can be
*   transmitted/received during one APS frame window.
*
*   See Zigbee specification revision 22 section 2.2.8.4.5 Fragmented Transmissions
*/
#define ZB_APS_MAX_FRAGMENT_NUM_IN_WINDOW 8
/** @endcond *//* internals_doc */
/** Maximum buffer size for APS fragmentation. Bigger buffer will not be created for APS fragmentation */
#define APS_IN_FRAG_MAX_BUF_SIZE 1500


/****************************NWK layer options**************************/
/** @cond internals_doc */
/*!
   Define maximum number of children per node.

 This value should be defined in stack profile.

 See Zigbee specification revision 22 subclause 3.5.2
*/
#define ZB_NWK_MAX_CHILDREN 4

/*!
 Define maximum number of routers per node.

 This value should be defined in stack profile.

 See Zigbee specification revision 22 subclause 3.5.2.
*/
#define ZB_NWK_MAX_ROUTERS  4

/**
 Define maximum network depth for a tree routing
*/
#define ZB_NWK_TREE_ROUTING_DEPTH    5

/**
 Define maximum network depth in stochastic addressing mode (NLF90)
*/
#define ZB_NWK_STOCH_DEPTH    15


/*!
   NWK Mesh route stuff: route discovery table size
*/
#ifndef ZB_NWK_ROUTE_DISCOVERY_TABLE_SIZE
#define ZB_NWK_ROUTE_DISCOVERY_TABLE_SIZE 5
#endif

/* nwkcRouteDiscoveryTime == 0x2710 ms == 10 sec. Expiry function called once
 * per second */
/*! Time period for calling route discovery expiry function */
#define ZB_NWK_ROUTE_DISCOVERY_EXPIRY 10
/*! Length of the route discovery function */
#define ZB_NWK_EXPIRY_ROUTE_DISCOVERY (ZB_N_APS_ACK_WAIT_DURATION_FROM_SLEEPY / ZB_NWK_ROUTE_DISCOVERY_EXPIRY)

/*#define ZB_NWK_RREQ_TABLE_SIZE 5*/

/*!
*  The number of times the first broadcast
*  transmission of a route request command
*  frame is retried.
*
*  Correspond to nwkcInitialRREQRetries in Zigbee Specification revision 22 subclause 3.5.1 NWK
*  Constants
*
*  The value is defined by specification.
*/
#define ZB_NWK_INITIAL_RREQ_RETRIES 3
/*!
 *  The number of times the broadcast
 *  transmission of a route request command
 *  frame is retried on relay by an intermediate
 *  Zigbee router or Zigbee coordinator.
 *
 *  Correspond to nwkcRREQRetries in Zigbee Specification revision 22 subclause 3.5.1 NWK Constants
 *  The value defined by specification.
 */
#define ZB_NWK_RREQ_RETRIES 2

#ifndef ZB_NWK_PENDING_TABLE_SIZE
/*! Pending table size */
#define ZB_NWK_PENDING_TABLE_SIZE 5
#endif

/*! Pending entry expiry during route request */
#define ZB_NWK_PENDING_ENTRY_EXPIRY 2
/*! Network static path cost */
#define ZB_NWK_STATIC_PATH_COST 7

/*!
*  Delay to wait before sending packet after receiving route replay.
*
*  Used only if ZB_CERT_HACKS().delay_pending_tx_on_rresp is 1.
*  Useful for test TP_PRO_BV-04.
*  Normally ZBOSS sends NWK immediately after receiving any route.
*/
#define ZB_NWK_SEND_AFTER_RRESP_RECV_DELAY_MS 1000


#ifndef ZB_NWK_BTR_TABLE_SIZE
/*!
*  Broadcast transaction record table size
*  See Zigbee Specification subclause 3.6.5
*/
#define ZB_NWK_BTR_TABLE_SIZE 16
#endif

#ifndef ZB_NWK_BRR_TABLE_SIZE
/*! Broadcast Retransmission table size */
#define ZB_NWK_BRR_TABLE_SIZE 8
#endif

/* 01/15/2019 EE CR:MINOR Can't it be better to keep ZB_NWK_MAX_BROADCAST_JITTER_INTERVAL define but internally define it using octets?
   In such case you minimize code modifications. same for all similar cases. Why movve "octets" to the upper layer? */
/* nwkcMaxBroadcastJitter */
/* 01/15/2019 EE CR:MINOR Add reference to the specification: here and in similar cases */
#define ZB_NWKC_MAX_BROADCAST_JITTER_OCTETS 0x7d0

/* nwkcMinRREQJitter */
#define ZB_NWKC_MIN_RREQ_JITTER_OCTETS 0x3f

/* nwkcMaxRREQJitter */
#define ZB_NWKC_MAX_RREQ_JITTER_OCTETS 0xfa0

/* nwkcRREQRetryInterval */
#define ZB_NWKC_RREQ_RETRY_INTERVAL 0x1f02

/*! Expiration time of pending period */
#define ZB_NWK_EXPIRY_PENDING (ZB_N_APS_ACK_WAIT_DURATION_FROM_SLEEPY / 2) /* 5 seconds */

/* 9 seconds */
/* According to 2013 PICS, it should be 9 sec.
   According to spec, it should be converted from broadcastDeliveryTime */
/** See Zigbee specification revision 22 section 3.5.2 NWK Information Base
 *  nwkBroadcastDeliveryTime */
#define ZB_NWK_EXPIRY_BROADCAST 9

/* Check if it is really should be so long. According to r21 spec, 3.6.3.2 - it is out of
 * the scope of this spec. */
/* Should correspond to ( 5 * minutes = 300 seconds / ZB_NWK_EXPIRY_PENDING )  */
/*! Expiration time of the network routing table  */
#define ZB_NWK_ROUTING_TABLE_EXPIRY 60

/*!
 * The maximum number of retries allowed after a broadcast transmission failure.
 *
 * See PICS NDF4.
*/
#define ZB_NWK_MAX_BROADCAST_RETRIES 0x02

/*!
 * The maximum time duration in milliseconds allowed for the parent and all
 * child devices to retransmit a broadcast message.
 *
 * See PICS NDF4.
 */
#define ZB_NWK_PASSIVE_ACK_TIMEOUT_OCTETS 0x3D09

/*!
 NWK Broadcast delivery time See 3.5.2.1
nwkBroadcastDeliveryTime = 2*nwkMaxDepth* ((0.05+(nwkcMaxBroadcastJitter/2))+ nwkPassiveAckTimeout*nwkBroadcastRetries/1000
nwkcMaxBroadcastJitter and nwkPassiveAckTimeout are measured in OctetDurations (!).

In PICS NDF4 for PRO:

nwkBroadcastDeliveryTime = 0x44AA2 Octet
durations (9 seconds on
2.4 GHz)
nwkPassiveAckTimeout =
0x3D09 Octet
Durations9 (500 ms on
2.4 GHz) maximum
nwkMaxBroadcastRetries
= 2
 */
#define ZB_NWK_BROADCAST_DELIVERY_TIME_OCTETS 0x44AA2
/** @endcond *//* internals_doc */

/*!
 * The time in seconds between link status command frames.
 *
 * Correspond to nwkLinkStatusPeriod in Zigbee Specification revision 22 subclause 3.5.1 NWK Constants
 * The value defined by specification.
 */
#define ZB_NWK_LINK_STATUS_PERIOD 0xf

/*!
 * The number of missed link status command frames before
 * resetting the link costs to zero.
 *
 * Correspond to nwkRouterAgeLimit in Zigbee Specification revision 22 subclause 3.5.1 NWK Constants
 * The value defined by specification.
*/
#define ZB_NWK_ROUTER_AGE_LIMIT 3
/** @cond internals_doc */
/*!
 Maximum number of rejoin requests in progress
*/
#define ZB_NWK_REJOIN_REQUEST_TABLE_SIZE 1
/** @endcond */ /* internals_doc */
/*! Rejoin timeout length */
#define ZB_NWK_REJOIN_TIMEOUT (ZB_TIME_ONE_SECOND * 5)

/*!
*  The rejoining sleeping end-device shall not poll before the response timeout (500ms), such that
*  the parent has enough time to process the rejoin request and put a response frame in its indirect
*  queue (same as for association response). Depending on the implementation, once a rejoining device
*  has performed an active scan and selected a new parent router, it sends a rejoin request (and at
*  that time considers this router to be its new parent, otherwise it cannot accept the rejoin
*  response), and polls for a response 500ms later.
 */
#define ZB_NWK_REJOIN_FIRST_POLL_DELAY (ZB_TIME_ONE_SECOND / 2)

/*! Number of poll attempts during rejoin */
#define ZB_NWK_REJOIN_POLL_ATTEMPTS 3
//#define ZB_NWK_REJOIN_POLL_ATTEMPTS 6 //TEST
/** @cond internals_doc */
/*!
 * Acceptable energy level on channel
 */
#define ZB_NWK_CHANNEL_ACCEPT_LEVEL 0x60

/**
   Devices which sends broadcast packets with rssi lower than this value will not be added
   to the neighbor table.
 */
#ifndef ZB_NWK_NEIGHBOR_RSSI_FILTER
#define ZB_NWK_NEIGHBOR_RSSI_FILTER (-80)
#endif

#ifndef ZB_DEFAULT_PERMIT_JOINING_DURATION
/*!
   Default duration to permit joining. Set to infinite by default.
*/
#define ZB_DEFAULT_PERMIT_JOINING_DURATION 0xff
#endif
/** @endcond *//* internals_doc */

/*!
 *   Default value of nib.max_children - max number of children which can join to this device
 *
 *   See Zigbee Specification revision 22 section 3.5.2 NWK Information Base
*/
#define ZB_DEFAULT_MAX_CHILDREN 32
/**@cond internals_doc */
/* Old feature from pre-3.0 (HA) era */
/* If there was an error in NWK security processing of incoming packet from parent,
 * then device tries to rejoin. This define disables this behavior */

/* By default device is rejoined if network key switch failed */
/*  #define ZB_DISABLE_REJOIN_AFTER_KEY_SWITCH_FAIL */

/*!
*  The default value of zb_tc_rejoin flag. Allows ZED to rejoin using Trust Center
*  rejoin procedure
*/
#define ZB_TC_REJOIN_ENABLE

 /*!
   Define policy of ignoring assoc. permit and corresponding flags during rejoin
 */
#define  ZB_REJOIN_IGNORES_FLAGS

/*!
Workaround for secure rejoin
*/
#define xZB_NO_KEY_AFTER_REJOIN

//#define ZB_MULTILEAVE_HACK

 /*! If the macro is defined, the device leaves the network according to application callback*/
#define ZB_LEAVE_USE_APP_CALLBACK
/** @endcond *//* internals_doc */
/**@cond DOXYGEN_MULTIMAC_SECTION */
/*!
* The rate, in seconds, of how often a Link Power Delta request is generated.
* In bands where this is optional, it should be set to 0, disabling the
* function. The default value should be 16.
 */
#define ZB_NWK_LINK_POWER_DELTA_TRANSMIT_RATE 16

/*! A Link Power Delta request rate jitter */
#define ZB_NWK_LINK_POWER_DELTA_TRANSMIT_RATE_JITTER 10 /* 10 seconds */
/** @endcond *//* DOXYGEN_MULTIMAC_SECTION */
/********************ZDO layer options*********************************/
/**@cond internals_doc*/
 /*!
   ZDO Indirect poll timer
 */
#define ZB_ZDO_INDIRECT_POLL_TIMER (5*ZB_TIME_ONE_SECOND) /* ZB_TIME_ONE_SECOND*10 */

/*!
   ZDO Max parent threshold retry
 */
#define ZB_ZDO_MAX_PARENT_THRESHOLD_RETRY 10

/*!
 Min scan duration for mgmt_nwk_update_req
*/
#define ZB_ZDO_MIN_SCAN_DURATION 0
/*!
 Max scan duration for mgmt_nwk_update_req
*/
#define ZB_ZDO_MAX_SCAN_DURATION 5
/*!
 Max scan count for mgmt_nwk_update_freq
*/
#define ZB_ZDO_MAX_SCAN_COUNT_PARAM 1
/*!
 * Special value of the ScanDuration for Mgmt_NWK_Update_req for channel change.
 *
 * See Zigbee Specification revision 22 Table 2.88, field ScanDuration.
 */
#define ZB_ZDO_NEW_ACTIVE_CHANNEL 0xFE
/*!
 * Special value of the ScanDuration for Mgmt_NWK_Update_req for channel mask change.
 *
 * See Zigbee Specification revision 22 Table 2.88, field ScanDuration.
*/
#define ZB_ZDO_NEW_CHANNEL_MASK   0xFF


/**
 * @todo{OLD_DESCRIPTION} Old (2015) and strange define
 * A countdown timer (in minutes) indicating the time to the next
 * permitted frequency agility channel change
 */
#define ZB_ZDO_APS_CHANEL_TIMER (1 * 60)

/*!
 1 minute timer to measure large timeouts
*/
#define ZB_ZDO_1_MIN_TIMEOUT (ZB_TIME_ONE_SECOND * 60)

/* Default values: see HA spec 9.6.4.2 Attribute Settings and Battery Life Considerations */
/** @endcond *//* intrenals_doc */
/*!
   Default fast poll timeout
 */
#define ZB_PIM_DEFAULT_FAST_POLL_TIMEOUT (ZB_TIME_ONE_SECOND * 10)

/*!
   Default fast poll interval
 */
#define ZB_PIM_DEFAULT_FAST_POLL_INTERVAL ZB_QUARTERECONDS_TO_BEACON_INTERVAL(2)


/*!
   Default long poll interval
 */
#define ZB_PIM_DEFAULT_LONG_POLL_INTERVAL (ZB_TIME_ONE_SECOND * 5)

/*!
   Default turbo poll interval
 */
#define ZB_PIM_DEFAULT_TURBO_POLL_INTERVAL ZB_MILLISECONDS_TO_BEACON_INTERVAL(100)

/*!
   Minimal possible turbo poll interval
 */
#define ZB_PIM_DEFAULT_MIN_TURBO_POLL_INTERVAL ZB_MILLISECONDS_TO_BEACON_INTERVAL(100)
//#define ZB_PIM_DEFAULT_MIN_TURBO_POLL_INTERVAL ZB_MILLISECONDS_TO_BEACON_INTERVAL(60)

/*!
   Maximal possible turbo poll interval
 */
#define ZB_PIM_DEFAULT_MAX_TURBO_POLL_INTERVAL ZB_MILLISECONDS_TO_BEACON_INTERVAL(3000)

/*!
   Timeout for turbo poll
 */
#define ZB_PIM_TURBO_POLL_PACKETS_TIMEOUT (ZB_TIME_ONE_SECOND * 15)

/*!
   Timeout for turbo poll
 */
#define ZB_PIM_TURBO_POLL_LEAVE_TIMEOUT (ZB_TIME_ONE_SECOND / 3)
/**@cond internals_doc*/
/*!
   Timeout for poll buffer allocation retry
 */
#define ZB_PIM_POLL_ALLOC_TIMEOUT ZB_MILLISECONDS_TO_BEACON_INTERVAL(500)
/** @endcond *//* internals_doc */
/*!
   Integer value representing the
   time duration (in milliseconds)
*/
#define ZB_ZDO_NWK_TIME_BTWN_SCANS 30
/**@cond internals_doc*/
/*!
 Timeout value in seconds
 employed in End Device
 Binding */
#define ZB_ZDO_ENDDEV_BIND_TIMEOUT 60


#ifndef ZDO_TRAN_TABLE_SIZE
/*!
 Transactions table size
*/
#define ZDO_TRAN_TABLE_SIZE 16
#endif

/*! Number of packets with "no ack" status before removing unreachable device from nbt. */
#define ZB_ZDO_NEIGHBOR_FAILURE_PKT_THRESHOLD 5
/* 60 seconds */
/*! Timeout before removing unreachable device from nbt. */
#define ZB_ZDO_NEIGHBOR_UNREACHABLE_TIMEOUT 60

/*! Checking channel timeout*/
#define ZB_ZDO_CHECK_CHANNEL_TIMEOUT (24 * 60 * 60 * ZB_TIME_ONE_SECOND)
/** @endcond *//* internals_doc */
/* Before r22 this value could be only 1, because scan attempts routine work
 * wrong. Rewritten/fixed in r22.  */
/*!
*  Integer value representing the number of scan attempts to make before the NWK layer decides
*  which Zigbee coordinator or router to associate with.
*
*  See Zigbee Specification revision 22 section 2.5.51 Configuration Attribute Definitions
*
*  Table 2-154 of Zigbee Specification revision 22 : Config_NWK_Scan_Attempts default value is 5.
*/
#define ZB_ZDO_NWK_SCAN_ATTEMPTS 5
/** @cond internals_doc */
/*! Delay for sending the end device request command. */
#define ZB_ZDO_SEND_ED_TIMEOUT_REQ_DELAY ZB_MILLISECONDS_TO_BEACON_INTERVAL(100)
/** @endcond *//*internals_doc*/
/**********************************************************************/
/************************** MAC SECTION********************************/
/**********************************************************************/
/*! @cond internals_doc */
/*
IEEE 802.15.4g p.7

Table 0 - MR-FSK symbol duration used for MAC and PHY timing parameters
Frequency band (MHz)                  MR-FSK symbol duration used for MAC
                                      and PHY timing parameters (us)
--------------------------------------------------------------------------
169.400-169.475 (Europe)              208+1/3
450-470 (US FCC Part 22/90)           104+1/6
470-510 (China)                       20
779-787 (China)                       20
863-870 (Europe)                      20
896-901 (US FCC Part 90)              100
901-902 (US FCC Part 24)              100
902-928 (US ISM)                      20
917-923.5 (Korea)                     20
928-960 (US FCC Part 22/24/90/101)    100
920-928 (Japan)                       20
950-958 (Japan)                       20
1427-1518 (US FCC Part 90)/(Canada    100
                      SRSP 301.4)
2400-2483.5 (Worldwide)               20
*/

#if   defined(ZB_SUB_GHZ_EU1) || defined(ZB_SUB_GHZ_EU2) || defined(ZB_SUB_GHZ_EU3)
#define ZB_SYMBOL_DURATION_USEC   20U
#elif defined(ZB_SUB_GHZ_US)
#define ZB_SYMBOL_DURATION_USEC   20U
#elif defined ZB_SUB_GHZ_JP
#define ZB_SYMBOL_DURATION_USEC   20U
#elif defined ZB_SUB_GHZ_CN
#else

/*!
 * @brief Symbol duration
 * @see 6.5.3.2 Symbol rate
 * The 2450 MHz PHY symbol rate shall be 62.
 * 5 ksymbol/s 40 ppm.
 */
#define ZB_SYMBOL_DURATION_USEC   16U      /* 1 symbol = 16e-6 sec (mac spec 6.5.3.2 Symbol rate) */
#endif

/*!
 * @brief Symbol duration for O-QPSK (2.4 GHz)
 * @see 12.3 section of 802.15.4-2015
 */
#define ZB_O_QPSK_2_4_GHZ_SYMBOL_DURATION_USEC 16U
#define ZB_O_QPSK_2_4_GHZ_PHY_SYMBOLS_PER_OCTET 2U

#define ZB_2_4_GHZ_OCTET_DURATION_USEC (ZB_O_QPSK_2_4_GHZ_SYMBOL_DURATION_USEC * ZB_O_QPSK_2_4_GHZ_PHY_SYMBOLS_PER_OCTET)

/*!
 * @brief Symbol duration for European FSK Sub-GHz
 * @see D.11.2 MAC Support for Listen Before Talk (LBT)
 */
#define ZB_EU_FSK_SYMBOL_DURATION_USEC 10U

#define ZB_EU_FSK_PHY_SYMBOLS_PER_OCTET 8U

/*!
 * @brief Synchronization header for European FSK Sub-GHz
 * @see D.10.1.1.1 SHR for European Sub-GHz FSK
 * synchronization header: 8 bytes preamble + 2 bytes SFD
 */
#define ZB_MAC_EU_FSK_SHR_LEN_BYTES   10U
#define ZB_MAC_EU_FSK_SHR_LEN_SYMBOLS \
  (ZB_MAC_EU_FSK_SHR_LEN_BYTES * ZB_EU_FSK_PHY_SYMBOLS_PER_OCTET)

/*!
 * @brief PHY header for European FSK Sub-GHz
 * @see D.10.1.1.2 PHR for European Sub-GHz FSK
 * PHY header: 2 bytes
 */
#define ZB_MAC_EU_FSK_PHR_LEN_BYTES 2U
#define ZB_MAC_EU_FSK_PHR_LEN_SYMBOLS \
  (ZB_MAC_EU_FSK_PHR_LEN_BYTES * ZB_EU_FSK_PHY_SYMBOLS_PER_OCTET)

/*!
   \par Time measurement unit is beacon interval.
   It is both internal representation and value used in API.
   It is still possible to convert it to/from msec.
   aBaseSuperframeDuration = aBaseSlotDuration * aNumSuperframeSlots
   aBaseSlotDuration = 60
   aNumSuperframeSlots = 16
*/
#define ZB_ABASE_SUPERFRAME_DURATION 960U


/*!
RX-to-TX or TX-to-RX maximum turnaround time
(in symbol periods) (see 6.9.1 and 6.9.2)
 */
#define ZB_MAC_A_TURNAROUND_TIME_SYM 12


/* @note: All packet tx timings are for 2.4 GHz radio. */

/*

6.3.1 Preamble field, octets
Table 19Preamble field length

24002483.5 MHz O-QPSK 4 octets 8 symbols
 */
/*! Preamble field length */
#define ZB_MAC_PREAMBLE_LEN 4


/*
   PHY hdr len, octets


6.3 PPDU format
This subclause specifies the
 */
/*! PHY header length */
#define ZB_MAC_PHR_LEN 1


/*

The SFD is a field indicating the end of the SHR and the start of the packet data.


6.3.2 SFD field
 */
/*! Start of length delimiter field length */
#define ZB_MAC_SFD_LEN 1



/**
 MAC frame preamble length, octets.

Each PPDU consists of the following basic components:
 +  A synchronization header (SHR), which allows a receiving device to synchronize and lock onto the
bit stream
 +  A PHY header (PHR), which contains frame length information
 +  A variable length payload, which carries the MAC sublayer frame

See IEEE Standard for Low-Rate Wireless Networks, section 5.7.3 Frame structure.
 */
/* MAC frame preamble length, octets. */
#define ZB_MAC_FRAME_PPDU_HDR_LEN (ZB_MAC_PREAMBLE_LEN + ZB_MAC_SFD_LEN + ZB_MAC_PHR_LEN)


 /* See D.10.1.1 PPDU Format for European Sub-GHz FSK */
 /*! MAC SUB GHZ preamble length */
#define ZB_MAC_SUBG_PREAMBLE_LEN 8
/*! MAC SUB GHZ start of frame delimiter length*/
#define ZB_MAC_SUBG_SFD_LEN     2
/*! MAC SUB GHZ PHY header length */
#define ZB_MAC_SUBG_PHR_LEN     2
/*! MAC SUB GHZ PHY protocol data unit frame header length */
#define ZB_MAC_SUBG_FRAME_PPDU_HDR_LEN (ZB_MAC_SUBG_PREAMBLE_LEN + ZB_MAC_SUBG_SFD_LEN + ZB_MAC_SUBG_PHR_LEN)
/*! MAC SUB GHZ PHY protocol data unit frame footer length */
#define ZB_MAC_SUBG_FRAME_PPDU_FOOTER_LEN 2
/*! MAC SUB GHZ symbol duration in microseconds */
#define ZB_MAC_SUBG_SYMBOL_DURATION_USEC 10
/*! MAC SUB GHZ transition octet to symbol */
#define ZB_MAC_SUBG_OCTET_TO_SYMBOL(octets) ((octets) * 8)
/* aRxTxTurnAround - see Table D-23 LBT MAC Sublayer Constants - Implementation */
/*!
*   Time for radio to switch between receive and transmit
*
*   See Table D-23 LBT MAC Sublayer Constants - Implementation
*/
#define ZB_MAC_SUBG_TURNAROUND_TIME_SYM 100

/*
   Define how many symbols used to transmit given number of octets

6.5.2.2 Bit-to-symbol mapping
All binary data contained in the PPDU shall be encoded using the modulation and spreading functions
shown in Figure 18. This subclause describes how binary information is mapped into data symbols.
The 4 LSBs (b0, b1, b2, b3) of each octet shall map into one data symbol, and the 4 MSBs (b4, b5, b6, b7) of
each octet shall map into the next data symbol. Each octet of the PPDU is processed through the modulation
and spreading functions (see Figure 18) sequentially, beginning with the Preamble field and ending with the
last octet of the PSDU.
 */
/*! Define how many symbols used to transmit given number of octets */
#define ZB_MAC_OCTET_TO_SYMBOL(octets) ((octets) * 2)

/*!
The maximum number of
backoffs the CSMA-CA
algorithm will attempt before
declaring a channel access
failure.
 */
#define ZB_MAC_MAX_CSMA_BACKOFFS 4

/*!
The number of symbols forming the basic time period
used by the CSMA-CA algorithm.

See 7.4.1 MAC constants
*/
#define ZB_MAC_A_UNIT_BACKOFF_PERIOD 20

/*!
6.9.9 Clear channel assessment (CCA)
The CCA detection time shall be equal to 8 symbol periods.
 */
/*! Clear channel assessment period */
#define ZB_MAC_CCA_PERIOD 8

/*! Number of times performed in slotted CSMA-CA by CCA */
#define ZB_MAC_NUM_CCA 2
/*! Total transmission attempts */
#define ZB_TX_TOTAL_THRESHOLD 20
/* TODO: check it */
/*!  Endpoint busy state value */
#define ZB_CHANNEL_BUSY_ED_VALUE 0x60
/* TODO: check it */
/*! Endpoint free state value  */
#define ZB_CHANNEL_FREE_ED_VALUE 0x60
/* use it as divider, 25% */
/*! Percentage of failures. Use it as divider to get 25 % */
#define ZB_FAILS_PERCENTAGE   4
/*! MAC queue size */
#define ZB_MAC_QUEUE_SIZE 5

/*
The maximum time, in
multiples of
aBaseSuperframeDuration, a
device shall wait for a
response command frame to
be available following a
request command frame.
*/
/*!
   Maximum time to wait for a response command frame, range 2-64
   Default is 32, 64 set for better compatibility
*/
#define ZB_MAC_RESPONSE_WAIT_TIME 32

/*! Make all MAC PIB attributes configurable */
#define ZB_CONFIGURABLE_MAC_PIB

/* Zigbee IEEE 802.15.4 Test Spec (Zigbee Doc. 14-0332-01), TP/154/MAC/DATA-04 test:
   macMaxFrameTotalWaitTime for 2.4 GHz 802.15.4-2003 Zigbee/PRO/RF4CE device is
   1220 symbols (or 20 msec) - minimal WaitTime to pass the test.

   Previous value was 500 msec, looks like it is too big. Big WaitTime values bring additional
   battery drain for ED devices.

   The value should be at least 1 beacon interval higher than in specs:
   ZBOSS timer resolution is 1 beacon interval, so there is a chance that 2 BI may correspond to
   16 ms of real time -- too low (especially for nsng).
 */
/*!
*  Maximum time to wait for indirect data.
*
*  See IEEE Standard for Low-Rate Wireless Networks 2006, section 7.4.2 MAC PIB attributes.
*
*  @note Make sure the time value is not too big.
*/
#define ZB_MAX_FRAME_TOTAL_WAIT_TIME_2_4_GHZ (ZB_MILLISECONDS_TO_BEACON_INTERVAL(40) + 1U)
/*!
*  Maximum time to wait for indirect data for SUB GHZ.
*
*  IEEE Standard for Low-Rate Wireless Networks 2006, section 7.4.2 MAC PIB attributes.
*
*  @note Make sure the time value is not too big.
*/
#define ZB_MAX_FRAME_TOTAL_WAIT_TIME_SUB_GHZ (ZB_MILLISECONDS_TO_BEACON_INTERVAL(48) + 1U)


/*!
*  The maximum number of retries allowed after a transmission failure 0-7
*/
#define ZB_MAC_MAX_FRAME_RETRIES 3


/* (currently - all platforms)*/
/*!
*  Sets MAC address at start
*/
#define ZB_SET_MAC_ADDRESS

#ifndef ZB_SEND_BEACON_IMMEDIATELY
/*!
*  Replay to the beacon request after a jitter (meaningful for DSR MAC only).
 */
#define ZB_SEND_BEACON_AFTER_RANDOM_DELAY
#endif /* ZB_SEND_BEACON_IMMEDIATELY */

/*!
*  External MAC
 */
#define ZB_MAC_EXT_DATA_REQ

/* Was 3, seems like it is too small when there are >7-10 beacons.
   Also it seems like we need some bottom line for this - it should not be 1 etc. */
/*! MAC beacon request timeout length (high bound of the random value) */
#ifndef ZB_MAC_HANDLE_BEACON_REQ_HI_TMO
/*! Default MAC beacon request timeout length */
#define ZB_MAC_HANDLE_BEACON_REQ_HI_TMO_DEFAULT 8U
/*! Extended MAC beacon request timeout length */
#define ZB_MAC_HANDLE_BEACON_REQ_HI_TMO_EXTENDED 20U

#ifdef ZB_CERTIFICATION_HACKS
/* Choose exact value depending on cert hack flags */
/*! Default MAC beacon request timeout length depending on certification hack flags */
#define ZB_MAC_HANDLE_BEACON_REQ_HI_TMO (ZB_CERT_HACKS().extended_beacon_send_jitter ? ZB_MAC_HANDLE_BEACON_REQ_HI_TMO_EXTENDED : ZB_MAC_HANDLE_BEACON_REQ_HI_TMO_DEFAULT)
#else
/* Otherwise use the default value*/
/*! Default MAC beacon request timeout length */
#define ZB_MAC_HANDLE_BEACON_REQ_HI_TMO ZB_MAC_HANDLE_BEACON_REQ_HI_TMO_DEFAULT
#endif

#endif /* ZB_MAC_HANDLE_BEACON_REQ_HI_TMO */

/*! MAC beacon request timeout length (low bound of the random value) */
#ifndef ZB_MAC_HANDLE_BEACON_REQ_LOW_TMO
/*! Default MAC beacon request timeout length */
#define ZB_MAC_HANDLE_BEACON_REQ_LOW_TMO_DEFAULT 1
/*! Extended MAC beacon request timeout length */
#define ZB_MAC_HANDLE_BEACON_REQ_LOW_TMO_EXTENDED 12

#ifdef ZB_STACK_REGRESSION_TESTING_API
/** Choose exact value depending on regression tests flags */
#define ZB_MAC_HANDLE_BEACON_REQ_LOW_TMO (ZB_REGRESSION_TESTS_API().extended_beacon_send_delay ? ZB_MAC_HANDLE_BEACON_REQ_LOW_TMO_EXTENDED : ZB_MAC_HANDLE_BEACON_REQ_LOW_TMO_DEFAULT)
#else
/** Otherwise use the default value */
#define ZB_MAC_HANDLE_BEACON_REQ_LOW_TMO ZB_MAC_HANDLE_BEACON_REQ_LOW_TMO_DEFAULT
#endif

#endif /* ZB_MAC_HANDLE_BEACON_REQ_LOW_TMO */
/*! @endcond */ /* internals_doc */
/** @cond DOXYGEN_MULTIMAC_SECTION */
/*!
*  European Sub-GHz FSK reverence sensitivity level, in dBm
*  D.10.2.2.1.2. Sensitivity Requirement,
*  Reference document 05-3474-22 Zigbee Specification R22
*
 */
#define ZB_EU_FSK_REFERENCE_SENSITIVITY -99


/* IMPORTANT!!!
 * As mentioned in section D.11.2 MAC Support for Listen Before Talk
 * of Zigbee Specification R22, document 05-3474-22, page 543
 *
 * Quote: "The UK have adopted the same values for ALL channel pages as defined
 * for pages 28 & 29. Other regions may use different values for pages 30 & 31
 * which as yet have not been defined or verified."
 *
 */
/* aLBTTxMinOff */
/* 100 ms */
/*! The minimum permitted off time between a device's own transmissions. */
#define ZB_MAC_LBT_TX_MIN_OFF_SYMBOLS 10000
/*! The minimum permitted off time between a device's own transmissions in microseconds. */
#define ZB_MAC_LBT_TX_MIN_OFF_USEC    (ZB_MAC_LBT_TX_MIN_OFF_SYMBOLS * ZB_EU_FSK_SYMBOL_DURATION_USEC)
/*! The minimum permitted off time between a device's own transmissions in ms.*/
#define ZB_MAC_LBT_TX_MIN_OFF_MS      (ZB_MAC_LBT_TX_MIN_OFF_USEC / 1000)

/* aLBTTxMaxPKT */
/* 1 second */
/*! The maximum permitted off time between a device's own transmissions. */
#define ZB_MAC_LBT_TX_MAX_PKT_SYMBOLS 100000
/*! The maximum permitted off time between a device's own transmissions in microseconds. */
#define ZB_MAC_LBT_TX_MAX_PKT_USEC    (ZB_MAC_LBT_TX_MAX_PKT_SYMBOLS * ZB_EU_FSK_SYMBOL_DURATION_USEC)
/*! The maximum permitted off time between a device's own transmissions in ms.*/
#define ZB_MAC_LBT_TX_MAX_PKT_MS      (ZB_MAC_LBT_TX_MAX_PKT_USEC / 1000)

/* aLBTMinFree */
/* 5 ms */
/*! The minimum duration a channel should be free */
#define ZB_MAC_LBT_MIN_FREE_SYMBOLS   500
/*! The minimum duration a channel should be free in microseconds*/
#define ZB_MAC_LBT_MIN_FREE_USEC      (ZB_MAC_LBT_MIN_FREE_SYMBOLS * ZB_EU_FSK_SYMBOL_DURATION_USEC)
/*! The minimum duration a channel should be free in ms*/
#define ZB_MAC_LBT_MIN_FREE_MS        (ZB_MAC_LBT_MIN_FREE_USEC / 1000)

/* aLBTMaxRandom */
/* 5 ms */
/*! The maximum period of the backoff */
#define ZB_MAC_LBT_MAX_RANDOM_SYMBOLS 500
/*! The maximum period of the backoff in microseconds */
#define ZB_MAC_LBT_MAX_RANDOM_USEC    (ZB_MAC_LBT_MAX_RANDOM_SYMBOLS * ZB_EU_FSK_SYMBOL_DURATION_USEC)
/*! The maximum period of the backoff in ms */
#define ZB_MAC_LBT_MAX_RANDOM_MS      (ZB_MAC_LBT_MAX_RANDOM_USEC / 1000)

/* aLBTMinRandom */
/* 0 ms */
/*! The minimum period of the backoff */
#define ZB_MAC_LBT_MIN_RANDOM_SYMBOLS 0
/*! The minimum period of the backoff in microseconds */
#define ZB_MAC_LBT_MIN_RANDOM_USEC    0
/*! The minimum period of the backoff in ms */
#define ZB_MAC_LBT_MIN_RANDOM_MS      0

/* aLBTGranularity */
/* 500 us */
/*! The granularity in the random backoff */
#define ZB_MAC_LBT_GRANULARITY_SYMBOLS 50
/*! The granularity in the random backoff in microseconds */
#define ZB_MAC_LBT_GRANULARITY_USEC    (ZB_MAC_LBT_GRANULARITY_SYMBOLS * ZB_EU_FSK_SYMBOL_DURATION_USEC)

/* aLBTThresholdLevelLp */
/*!
*   The level (in dBm) at which the receiver determines whether there
*   is activity in a low power channel (+14 dBm Tx).
*/
#define ZB_MAC_LBT_THRESHOLD_LEVEL_LP  (-87)

/* aLBTThresholdLevelHp */
/*!
*   The level (in dBm) at which the receiver determines whether
*   there is activity in a high power channel (+27 dBm Tx).
*/
#define ZB_MAC_LBT_THRESHOLD_LEVEL_HP  (-91)

/* aLBTMaxTxRetries */
/*! The maximum number of retries allowed while looking for a clear channel. 
 * 
 * See Zigbee Specification revision 22 Table D-23 LBT MAC Sublayer Constants - Implementation. 
*/
#define ZB_MAC_LBT_MAX_TX_RETRIES 3

/* aLBTAckWindowStart */
/* 450 us */
/*!
*   The minimum pause before acknowledging a received packet.
*   This is to allow a transmitting device to change from
*   transmit to receive mode. Starting an ACK before this time
*   may result in the transmitter missing the ACK.
*/
#define ZB_MAC_LBT_ACK_WINDOW_START_SYMBOLS 45
/*!
*   The minimum pause before acknowledging a received packet in microseconds.
*   This is to allow a transmitting device to change from
*   transmit to receive mode. Starting an ACK before this time
*   may result in the transmitter missing the ACK.
*/
#define ZB_MAC_LBT_ACK_WINDOW_START_USEC \
  (ZB_MAC_LBT_ACK_WINDOW_START_SYMBOLS * ZB_EU_FSK_SYMBOL_DURATION_USEC)

/* aLBTAckWindow */
/* 1ms */
/*!
*   The maximum wait time before acknowledging a received
*   packet (includes @ref ZB_MAC_LBT_ACK_WINDOW_START_SYMBOLS).
*   This time MUST be shorter than @ref ZB_MAC_LBT_MIN_FREE_SYMBOLS otherwise other
*   devices could interpret the quiet as an opportunity to transmit.
*/
#define ZB_MAC_LBT_ACK_WINDOW_SYMBOLS 100
/*!
*   The maximum wait time in microseconds before acknowledging a received
*   packet (includes @ref ZB_MAC_LBT_ACK_WINDOW_START_SYMBOLS).
*   This time MUST be shorter than @ref ZB_MAC_LBT_MIN_FREE_SYMBOLS otherwise other
*   devices could interpret the quiet as an opportunity to transmit.
*/
#define ZB_MAC_LBT_ACK_WINDOW_USEC    (ZB_MAC_LBT_ACK_WINDOW_SYMBOLS * ZB_EU_FSK_SYMBOL_DURATION_USEC)
/*!
*   The maximum wait time in ms before acknowledging a received
*   packet (includes @ref ZB_MAC_LBT_ACK_WINDOW_START_SYMBOLS).
*   This time MUST be shorter than @ref ZB_MAC_LBT_MIN_FREE_SYMBOLS otherwise other
*   devices could interpret the quiet as an opportunity to transmit.
*/
#define ZB_MAC_LBT_ACK_WINDOW_MS      (ZB_MAC_LBT_ACK_WINDOW_USEC / 1000)
/*aTxRxTurnAround */
/*!
*  Time for radio to switch between transmit and receive
*/
#define ZB_MAC_LBT_TX_RX_SWITCH_TIME_SYMBOLS 45
/* aLBTTimeout */
/* 6 ms */
/*!
*   Time before aborting LBT if it cannot find a free slot.
*   This value should be set to at least
*   [@ref ZB_MAC_LBT_MIN_FREE_SYMBOLS  + @ref ZB_MAC_LBT_MAX_TX_RETRIES * (@ref ZB_MAC_LBT_MIN_FREE_SYMBOLS + @ref ZB_MAC_LBT_MAX_RANDOM_SYMBOLS) + @ref ZB_MAC_LBT_TX_RX_SWITCH_TIME_SYMBOLS )]
*   to ensure that all re-tries can occur.
*/
#define ZB_MAC_LBT_TIMEOUT_SYMBOLS 6000
/*!
*   Time before aborting LBT if it cannot find a free slot in microseconds.
*   This value should be set to at least
*   [@ref ZB_MAC_LBT_MIN_FREE_SYMBOLS  + @ref ZB_MAC_LBT_MAX_TX_RETRIES * (@ref ZB_MAC_LBT_MIN_FREE_SYMBOLS + @ref ZB_MAC_LBT_MAX_RANDOM_SYMBOLS) + @ref ZB_MAC_LBT_TX_RX_SWITCH_TIME_SYMBOLS )]
*   to ensure that all re-tries can occur.
*/
#define ZB_MAC_LBT_TIMEOUT_USEC    (ZB_MAC_LBT_TIMEOUT_SYMBOLS * ZB_EU_FSK_SYMBOL_DURATION_USEC)
/*!
*   Time before aborting LBT if it cannot find a free slot in ms.
*   This value should be set to at least
*   [@ref ZB_MAC_LBT_MIN_FREE_SYMBOLS  + @ref ZB_MAC_LBT_MAX_TX_RETRIES * (@ref ZB_MAC_LBT_MIN_FREE_SYMBOLS + @ref ZB_MAC_LBT_MAX_RANDOM_SYMBOLS) + @ref ZB_MAC_LBT_TX_RX_SWITCH_TIME_SYMBOLS )]
*   to ensure that all re-tries can occur.
*/
#define ZB_MAC_LBT_TIMEOUT_MS      (ZB_MAC_LBT_TIMEOUT_USEC / 1000)
/*! LBT acknowledgement length for SUB GHZ */
#define ZB_MAC_LBT_SUB_GHZ_ACK_LEN_SYMBOLS (ZB_MAC_ACK_LEN_BYTES * ZB_EU_FSK_PHY_SYMBOLS_PER_OCTET)

/* Tuned to fit to 2 beacon intervals */
/*! LBT transmition wait period in ms */
#define ZB_MAC_LBT_TX_WAIT_QUANT_MS        33

/* aDUTYCYCLEMeasurementPeriod */
/*! The period over which the duty cycle is calculated. */
#define ZB_MAC_DUTY_CYCLE_MEASUREMENT_PERIOD_SYMBOLS 360000000
/*! The period over which the duty cycle is calculated in seconds */
#define ZB_MAC_DUTY_CYCLE_MEASUREMENT_PERIOD_SEC \
 (ZB_MAC_DUTY_CYCLE_MEASUREMENT_PERIOD_SYMBOLS / 1000000 * ZB_EU_FSK_SYMBOL_DURATION_USEC)

/* aDUTYCYCLERampUp */
#ifndef ZB_MAC_DUTY_CYCLE_RAMP_UP_SYMBOLS
/*! Time transmitter is transmitting carrier prior to start of data */
#define ZB_MAC_DUTY_CYCLE_RAMP_UP_SYMBOLS   0
#endif  /* ZB_MAC_DUTY_CYCLE_RAMP_UP_SYMBOLS */

/* aDUTYCYCLERampDown */
#ifndef ZB_MAC_DUTY_CYCLE_RAMP_DOWN_SYMBOLS
/*! Time transmitter is transmitting carrier after end of data */
#define ZB_MAC_DUTY_CYCLE_RAMP_DOWN_SYMBOLS   0
#endif  /* ZB_MAC_DUTY_CYCLE_RAMP_DOWN_SYMBOLS */



#ifndef ZB_USE_DUTY_CYCLE_PERCENT_ENABLE

/*! MAC duty cycle of limited threshold length */
#define ZB_MAC_DUTY_CYCLE_LIMITED_THRESHOLD_SYMBOLS  5400000
/*! MAC duty cycle of critical threshold length */
#define ZB_MAC_DUTY_CYCLE_CRITICAL_THRESHOLD_SYMBOLS 7500000

/*! MAC duty cycle of limited threshold length */
/*! Length of regulated MAC duty cycle pages 29 and 29 */
#define ZB_MAC_DUTY_CYCLE_REGULATED_SYMBOLS_PAGES_28_29 10000000
/*! Length of regulated MAC duty cycle pages 30 and 31 */
#define ZB_MAC_DUTY_CYCLE_REGULATED_SYMBOLS_PAGES_30_31  9000000

#endif /* ZB_USE_DUTY_CYCLE_PERCENT_ENABLE */

/* aDUTYCYCLEBuckets */
/*! Number of buckets used for duty cycle monitoring */
#define ZB_MAC_DUTY_CYCLE_BUCKETS 13

/*!
*   Duty cycle monitoring period
  */
#define ZB_MAC_DUTY_CYCLE_TIME_PERIOD_SEC \
  (ZB_MAC_DUTY_CYCLE_MEASUREMENT_PERIOD_SEC / (ZB_MAC_DUTY_CYCLE_BUCKETS - 1))

/*!
*   MAC power control information table size
*
*   See reference document 05-3474-22 section D.9.2 Zigbee Specification R22
  */
#define ZB_MAC_POWER_CONTROL_INFO_TABLE_SIZE 10
/*! MAC power control expiration time out */
#define ZB_MAC_POWER_CONTROL_EXPIRATION_TIMEOUT (10 * ZB_TIME_ONE_SECOND)
/*!
*   Optimal signal level for Eu FSK should be +20dB above the reference sensitivity @ref ZB_EU_FSK_REFERENCE_SENSITIVITY
*
*   See reference document 05-3474-22 section D.9.2.4.2. Zigbee Specification R22
 */
#define ZB_MAC_POWER_CONTROL_OPT_SIGNAL_LEVEL (ZB_EU_FSK_REFERENCE_SENSITIVITY + 20)


#ifndef ZB_MAC_DEFAULT_TX_POWER_SUB_GHZ
/*! Default MAC transmission power for SUB GHZ */
#define ZB_MAC_DEFAULT_TX_POWER_SUB_GHZ +14
#endif
/** @endcond */ /* DOXYGEN_MULTIMAC_SECTION */
/** @cond internals_doc */
#ifndef ZB_MAC_DEFAULT_TX_POWER_24_GHZ
/*! Default MAC transmission power for 2.4 GHZ */
#define ZB_MAC_DEFAULT_TX_POWER_24_GHZ  +20
#endif
/*! MAC diagnostic filter size */
#define ZB_MAC_DIAGNOSTICS_FILTER_SIZE 4
/*! MAC diagnostic time period in minutes */
#define ZB_MAC_DIAGNOSTICS_TIME_PERIOD_MIN 10
/*! MAC diagnostic time period in seconds */
#define ZB_MAC_DIAGNOSTICS_TIME_PERIOD_SEC \
  (ZB_MAC_DIAGNOSTICS_TIME_PERIOD_MIN * 60 * ZB_TIME_ONE_SECOND)

#ifndef ZB_MAC_ASSOCIATION_DATA_REQUEST_COUNT
/*! Count of MAC data association */
#define ZB_MAC_ASSOCIATION_DATA_REQUEST_COUNT 1
#endif
/* Base Device */

/**
*  See about bdbTrustCenterNodeJoinTimeout in Base Device Specification subclause 5.3.16.
*
*   The bdbTrustCenterNodeJoinTimeout attribute specifies a timeout in seconds
*   for the Trust Center to remove the Trust Center link key of the newly joined
*   node that did not successfully establish a new link key. This attribute
*   is used by Zigbee coordinator nodes.
 */
/*! Timeout in seconds for the Trust Center to remove the Trust Center link key of the newly joined
   node that did not successfully establish a new link key. This attribute
   is used by Zigbee coordinator nodes.*/
#define ZB_DEFAULT_BDB_TRUST_CENTER_NODE_JOIN_TIMEOUT ZB_MILLISECONDS_TO_BEACON_INTERVAL(0xf * 1000)
/*! Timeout in seconds for the Trust Center to exchange link keys with the newly joined node */
#define ZB_BDBC_TCLINK_KEY_EXCHANGE_TIMEOUT ZB_MILLISECONDS_TO_BEACON_INTERVAL(5000)
/*! Minimum commissioning period */
#define ZB_BDBC_MIN_COMMISSIONING_TIME_S 180
/*! Number of Trust Center link attempts to exchange link keys with the newly joined node. */
#define ZB_DEFAULT_BDB_TCLINK_KEY_EXCHANGE_ATTEMPTS_MAX 3
/** @endcond *//*internals_doc*/
/*! Specification version of the specification */
#define ZB_STACK_SPEC_VERSION 22


/*! @cond touchlink */
/* Table 2 Constants used by nodes supporting touchlink */
#define ZB_BDBC_TL_INTER_PANTRANS_ID_LIFETIME ZB_MILLISECONDS_TO_BEACON_INTERVAL(8000)
#define ZB_BDBC_TL_MIN_STARTUP_DELAY_TIME     ZB_MILLISECONDS_TO_BEACON_INTERVAL(2000)
/* used for a non-extended touchlink scan */
#define ZB_BDBC_TL_PRIMARY_CHANNEL_SET        0x02108800
#define ZB_BDBC_TL_RX_WINDOW_DURATION         ZB_MILLISECONDS_TO_BEACON_INTERVAL(5000)
#define ZB_BDBC_TL_SCAN_TIME_BASE_DURATION    ZB_MILLISECONDS_TO_BEACON_INTERVAL(250)
/* used for an extended touchlink scan after the bdbcTLPrimaryChannelSet
 * channels have been scanned. */
#define ZB_BDBC_TL_SECONDARY_CHANNEL_SET      (0x07fff800 ^ ZB_BDBC_TL_PRIMARY_CHANNEL_SET)
/*! @endcond */ /* touchlink */


/* Green Power */

/** @cond DOXYGEN_ZGP_SECTION  */
/*!
 * zgpDuplicateTimeout value
 *
 * The time the EPP of the ZGPS and ZGPP keeps the information on the received
 * GPDF with random sequence number, in order to filter out duplicates.
 *
 * The default value of 2 seconds can be modified by the application profile
 *
 * @see ZGP spec, A.3.6.1.2.1 */
#define ZB_ZGP_DUPLICATE_TIMEOUT    (1 * ZB_TIME_ONE_SECOND)

/*
  The OperationalChannel sub-field can take the following values: 0b0000: channel 11, 0b0001: channel
  12, , 0b1111: channel 26.
*/
/*! First Zigbee green power device channel value */
#define ZB_ZGPD_FIRST_CH        11
/*! Last Zigbee green power device channel value */
#define ZB_ZGPD_LAST_CH         26

/* ZGP spec, A.3.9.1:
 * If no Channel Request is received on channel TransmitChannel for 5sec,
 * the TempMaster removes the Channel Configuration GPDF from its
 * gpTxQueue and returns to the operational channel in commissioning mode
 */
/*! Timeout of Zigbee Green Power Device channel transition request */
#define ZB_ZGP_CHANNEL_REQ_ON_TX_CH_TIMEOUT (5 * ZB_TIME_ONE_SECOND)

/*!
 * If commissioning on the last stage, then it determines time to wait
 * until commissioning is complete. If commissioning is not completed
 * during this time, then commissioning cancel procedure is started.
 */
/*!
*  Timeout before completing commissioning if
*  the last stage is successful or,
*  otherwise, start the cancel procedure.
*/
#define ZB_ZGP_TIMEOUT_BEFORE_FORCE_CANCEL (3 * ZB_TIME_ONE_SECOND)

/*! Unspecified Zigbee Green Power device manufacturer ID */
#define ZB_ZGPD_MANUF_ID_UNSPEC     0xFFFF
/*! Default Zigbee Green Power device manufacturer ID */
#define ZB_ZGPD_DEF_MANUFACTURER_ID 0x10d0
/*! Maximum number of lightweight unicast address per Green Power device. */
#define ZB_ZGP_MAX_LW_UNICAST_ADDR_PER_GPD 2
/*! Maximum number of SINK groups per Green Power device */
#define ZB_ZGP_MAX_SINK_GROUP_PER_GPD 2
/*! Maximum number of paired endpoints*/
#define ZB_ZGP_MAX_PAIRED_ENDPOINTS 2
/*! Maximum number of paired Green Power devices commands */
#define ZB_ZGP_MAX_PAIRED_CONF_GPD_COMMANDS 2
/*! Maximum number of paired configuration clusters */
#define ZB_ZGP_MAX_PAIRED_CONF_CLUSTERS 2
/** @endcond */ /* DOXYGEN_ZGP_SECTION */
/*! @} */

/* ****************** Smart Energy parameters ******************* */
/* 5.3.8 APS Fragmentation Parameters
   For  the Smart Energy Profile the default value shall be set to 128 bytes. */
#define ZB_ASDU_MAX_FRAG_LEN (ZB_IO_BUF_SIZE - sizeof(zb_apsde_data_indication_t) - ZB_APS_HEADER_MAX_LEN - 3)
#define ZB_APS_MAX_WINDOW_SIZE 1
#define ZB_APS_INTERFRAME_DELAY 50 /* milliseconds */


#define ZB_SE_STEADY_STATE_CLUSTER_MATCH_DESC_TIME (ZB_TIME_ONE_SECOND * 20)
#define ZB_SE_STEADY_STATE_MAX_FAILURE_CNT 3

#define ZB_SE_PARTNER_LK_SETUP_TIMEOUT (ZB_TIME_ONE_SECOND * 30)

#define ZB_SE_HI_FREQ_MSG_TIMEOUT (ZB_TIME_ONE_SECOND * 30)
#define ZB_SE_HI_FREQ_MSG_N_SLOTS 4

/*! @cond internals_doc */
/* No need to set manufacturer code in node descriptor directly.
 * zb_set_node_descriptor should select the right one depending on defined platform and/or radio
 * For other codes see docs-05-3874-26-0csg-database-of-manufacturer-codes-for-use-in-the-node-descriptor.pdf */
#define ZB_MANUFACTURER_CODE_DSR            0x1234
/* That is not a joke, our manufacturer code is really 1234! */
/*! @endcond */ /* internals_doc */

#define ZB_DEFAULT_MANUFACTURER_CODE ZB_MANUFACTURER_CODE_DSR

#ifndef ZB_MULTITEST_HW_INIT_WAIT_ITERATIONS
#define ZB_MULTITEST_HW_INIT_WAIT_ITERATIONS 0
#endif

#ifndef ZB_MULTITEST_CONSOLE_SLEEP_TIMEOUT
#define ZB_MULTITEST_CONSOLE_SLEEP_TIMEOUT 4000000
#endif


#endif /* ZB_CONFIG_COMMON_H */
 
