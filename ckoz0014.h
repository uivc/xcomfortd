/* -*- Mode: C++; c-file-style: "stroustrup" -*- */

/*
 *  Reverse engineered from a variety of sources, for the purpose of
 *  interoperability.
 *
 *  Copyright 2016 Karl Anders Oygard. All rights reserved.
 *  Use of this source code is governed by a BSD-style license that can be
 *  found in the LICENSE file.
 */

#ifndef _CKOZ0014_H_
#define _CKOZ0014_H_

// Known commands that the CKOZ 00/14 understands

enum mci_pt_action
{
    MCI_PT_TX           = 0xB1,
    MCI_PT_MGMT         = 0xB2,
    MCI_PT_RX           = 0xC1,
    MCI_PT_ACK          = 0xC3,
    MCI_PT_FW           = 0xD1  // Messages relating to firmware
};

/* Events that can be sent to datapoints.  Not all events are valid
   for all devices. */

enum mci_tx_event
{
    SET_SCHAR           = 0x02,
    SET_BOOLEAN         = 0x0a,
    REQUEST_STATUS      = 0x0b, // Requests MSG_STATUS event from the datapoint
    SET_PERCENT         = 0x0c,
    DIM_STOP_OR_SET     = 0x0d,
    START_BOOL          = 0x0e, /* For dimmer, boolean value indicates direction.
                                   For shutter, 00 = move down
                                                01 = move up
                                                10 = step down
                                                11 = step up
                                                02 = stop */
    SET_SSHORT_1COMMA   = 0x11,
    SET_TIME            = 0x2a,
    SET_DATE            = 0x2b,
    SET_TEMP_KNOB       = 0x2c,
    SET_LONG_NO_COMMA   = 0x30,
    SET_LONG_1COMMA     = 0x31,
    SET_LONG_2COMMA     = 0x32,
    SET_LONG_3COMMA     = 0x33,
    SET_USHORT          = 0x40,
    SET_USHORT_1COMMA   = 0x41,
    SET_USHORT_2COMMA   = 0x42,
    SET_USHORT_3COMMA   = 0x43,
    SET_TEMP_MODE       = 0x44,
    SET_TEMP_KNOB2      = 0x45,
    SET_HRV_IN          = 0x46,
    SET_BASIC_MODE      = 0x80,
    SET_DIRECT_ON       = 0xa0
};

/* Events that can be received from datapoints.

   These are events that are known by MRF, they may not all be
   applicable to datapoints. */

enum mci_rx_event
{
    MSG_ACK             = 0x01,
    MSG_STAY_ONLINE     = 0x09,
    MSG_ALLIVE          = 0x11,
    MSG_GET_OFFLINE     = 0x18,
    MSG_GET_EEPROM      = 0x30,
    MSG_SET_EEPROM      = 0x31,
    MSG_GET_CRC         = 0x32,
    MSG_TIME            = 0x37,
    MSG_DATE            = 0x38,
    MSG_PAKET           = 0x39,
    MSG_KILL            = 0x43,
    MSG_FACTORY         = 0x44,
    MSG_ON              = 0x50,
    MSG_OFF             = 0x51,
    MSG_SWITCH_ON       = 0x52,
    MSG_SWITCH_OFF      = 0x53,
    MSG_UP_PRESSED      = 0x54,
    MSG_UP_RELEASED     = 0x55,
    MSG_DOWN_PRESSED    = 0x56,
    MSG_DOWN_RELEASED   = 0x57,
    MSG_PWM             = 0x59,
    MSG_FORCED          = 0x5a,
    MSG_SINGLE_ON       = 0x5b,
    MSG_TOGGLE          = 0x61,
    MSG_VALUE           = 0x62,
    MSG_ZU_KALT         = 0x63,
    MSG_ZU_WARM         = 0x64,
    MSG_STATUS          = 0x70,
    MSG_STATUS_APPL     = 0x71,
    MSG_STATUS_REQ_APPL = 0x72,
    MSG_STATUS_EXT = 0x73
};

/* Commands that can be sent to the stick itself. These are sent with
   the MCI_PT_MGMT message and is received via the MCI_PT_ACK
   message. */

enum mci_ck_management
{
    CK_ERROR            = 0x09,
    CK_TIMEACCOUNT      = 0x0a,
    CK_COUNTER_TX       = 0x0b,
    CK_COUNTER_RX       = 0x0c,
    CK_SERIAL           = 0x0e,
    CK_RELNO            = 0x1b,
    CK_SUCCESS          = 0x1c
};

// Battery status reported by datapoints

enum mci_battery_status
{
    BATTERY_NA          = 0x0,
    BATTERY_EMPTY       = 0x1,
    BATTERY_WEAK        = 0x2,
    BATTERY_AVERAGE     = 0x3,
    BATTERY_ALMOSTFULL  = 0x4,
    BATTERY_FULL        = 0x5,
    POWERLINE           = 0x10
};

// Shutter status reported by datapoints

enum mci_shutter_status
{
    SHUTTER_STOPPED     = 0x00,
    SHUTTER_UP          = 0x01,
    SHUTTER_DOWN        = 0x02
};

// Commands for shutters

enum mci_sb_command
{
    SHUTTER_CMD_DOWN      = 0x00,
    SHUTTER_CMD_UP        = 0x01,
    SHUTTER_CMD_STOP      = 0x02,
    SHUTTER_CMD_STEP_DOWN = 0x10,
    SHUTTER_CMD_STEP_UP   = 0x11
};

/* Data types that can be received from a datapoint

   These are events that are known by MRF, they may not all
   be applicable to datapoints. */

enum mci_rx_datatype
{
    NO_TELEGRAM_DATA         = 0x00,
    PERCENT                  = 0x01,
    DATA_TYPE_UCHAR          = 0x02,
    SSHORT_1COMMA            = 0x03,
    ANSI_FLOAT               = 0x04,
    MEMORY                   = 0x06,
    MEMORY_REQ               = 0x07,
    ALLIVE_FILTER            = 0x0c,
    USHORT_NO_COMMA          = 0x0d,
    ULONG_NO_COMMA           = 0x0e,
    ULONG_1COMMA             = 0x0f,
    ULONG_2COMMA             = 0x10,
    ULONG_3COMMA             = 0x11,
    RC_DATA                  = 0x17,
    MEMORY32                 = 0x1a,
    MEMORY32_REQ             = 0x1b,
    DATA_TYPE_TIME           = 0x1e,
    DATA_TYPE_DATE           = 0x37,
    DATA_TYPE_PACKET         = 0x20,
    USHORT_1COMMA            = 0x21,
    USHORT_2COMMA            = 0x22,
    USHORT_3COMMA            = 0x22,
    DATA_TYPE_UNSIGNED_LONG  = 0x25,
    DATA_TYPE_ULONG_1COMMA   = 0x26,
    DATA_TYPE_ULONG_2COMMA   = 0x27,
    DATA_TYPE_ULONG_3COMMA   = 0x28,
    //USHORT_1COMMA            = 0x29,
    //USHORT_2COMMA            = 0x2a,
    //USHORT_3COMMA            = 0x2b,
    DIMPLEX_DATA             = 0x2d,
    DATA_TYPE_SLONG_NOCOMMA  = 0x2e,
    DATA_TYPE_SLONG_1COMMA   = 0x2f,
    DATA_TYPE_SLONG_2COMMA   = 0x30,
    DATA_TYPE_SLONG_3COMMA   = 0x31,
    DATA_TYPE_SSHORT_NOCOMMA = 0x32,
    DATA_TYPE_SSHORT_2COMMA  = 0x33,
    DATA_TYPE_SSHORT_3COMMA  = 0x34,
    DATE                     = 0x37,
    ARRAY                    = 0xf0
};

#pragma pack(push,1)

// Message format 

struct xc_ci_message
{
    unsigned char      message_size;
    unsigned char      action;
    union
    {
	struct
	{
	    unsigned char  datapoint;
	    unsigned char  tx_event;
	    int            value;
	    unsigned char  message_id;
	}                  packet_tx;
	struct
	{
	    unsigned char  type;
	    unsigned char  mode;
	}                  packet_mgmt;
	struct
	{
	    unsigned char  datapoint;
	    unsigned char  rx_event;
	    unsigned char  rx_data_type;
	    int            value;
	    unsigned char  unknown;
	    unsigned char  signal;          // apparent range 0 - 120
	    unsigned char  battery;         // see BatteryStatus
	    unsigned char  sequence_number; // 0-15 monotonously increasing
	}                  packet_rx;
	struct
	{
	    unsigned char  type;
	    unsigned char  mode;
            int            data;
	}                  packet_ack; 
    };
};

#pragma pack(pop)

typedef void (*xc_recv_fn)(void* user_data,
			   enum mci_rx_event,
			   int,
			   enum mci_rx_datatype,
			   int,
			   int,
			   enum mci_battery_status);

typedef void (*xc_ack_fn)(void* user_data,
			  int success,
			  int message_id);

typedef void (*xc_relno_fn)(void* user_data,
			    int rf_major,
			    int rf_minor,
			    int usb_major,
			    int usb_minor);

struct xc_parse_data {
    xc_ack_fn ack;
    xc_recv_fn recv;
    xc_relno_fn relno;
    void* user_data;
};

void xc_parse_packet(const char* buffer, size_t size, xc_parse_data* data);

const char* xc_shutter_status_name(int state);

const char* xc_battery_status_name(enum mci_battery_status state);
const char* xc_rxevent_name(enum mci_rx_event event);

void xc_make_startbool_msg(char* buffer, int datapoint, mci_sb_command cmd, int message_id);
void xc_make_setpercent_msg(char* buffer, int datapoint, int value, int message_id);
void xc_make_switch_msg(char* buffer, int datapoint, int on, int message_id);
void xc_make_requeststatus_msg(char* buffer, int datapoint, int message_id);
void xc_make_mgmt_msg(char* buffer, int type, int mode);

#endif
