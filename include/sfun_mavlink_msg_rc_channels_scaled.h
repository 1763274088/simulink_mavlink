/*
DO NOT EDIT.
This file was automatically created by the Matlab function 'create_sfun_header' on 08-Sep-2018 10:51:54
as part of Simulink MAVLink library.
*/

#include "D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_rc_channels_scaled.h"
#define BUS_NAME_RC_CHANNELS_SCALED "mavlink_rc_channels_scaled_t"
#define NFIELDS_BUS_RC_CHANNELS_SCALED 11
#define ENCODED_LEN_RC_CHANNELS_SCALED (MAVLINK_NUM_NON_PAYLOAD_BYTES + MAVLINK_MSG_ID_RC_CHANNELS_SCALED_LEN)

/*
Encode the busInfo vector. This vector stores the starting index and total offset
for every element of the message bus. This is the standard way Simulink s-functions
handle bus interfaces.
*/
static inline void encode_businfo_rc_channels_scaled(SimStruct *S, int_T *busInfo, const int_T offset)
{
	slDataTypeAccess *dta = ssGetDataTypeAccess(S);
	const char *bpath = ssGetPath(S);
	DTypeId BUSId = ssGetDataTypeId(S, BUS_NAME_RC_CHANNELS_SCALED);
	
	busInfo[offset+0] = dtaGetDataTypeElementOffset(dta, bpath, BUSId, 0);
	busInfo[offset+1] = dtaGetDataTypeSize(dta, bpath, ssGetDataTypeId(S, "uint32"));
	busInfo[offset+2] = dtaGetDataTypeElementOffset(dta, bpath, BUSId, 1);
	busInfo[offset+3] = dtaGetDataTypeSize(dta, bpath, ssGetDataTypeId(S, "int16"));
	busInfo[offset+4] = dtaGetDataTypeElementOffset(dta, bpath, BUSId, 2);
	busInfo[offset+5] = dtaGetDataTypeSize(dta, bpath, ssGetDataTypeId(S, "int16"));
	busInfo[offset+6] = dtaGetDataTypeElementOffset(dta, bpath, BUSId, 3);
	busInfo[offset+7] = dtaGetDataTypeSize(dta, bpath, ssGetDataTypeId(S, "int16"));
	busInfo[offset+8] = dtaGetDataTypeElementOffset(dta, bpath, BUSId, 4);
	busInfo[offset+9] = dtaGetDataTypeSize(dta, bpath, ssGetDataTypeId(S, "int16"));
	busInfo[offset+10] = dtaGetDataTypeElementOffset(dta, bpath, BUSId, 5);
	busInfo[offset+11] = dtaGetDataTypeSize(dta, bpath, ssGetDataTypeId(S, "int16"));
	busInfo[offset+12] = dtaGetDataTypeElementOffset(dta, bpath, BUSId, 6);
	busInfo[offset+13] = dtaGetDataTypeSize(dta, bpath, ssGetDataTypeId(S, "int16"));
	busInfo[offset+14] = dtaGetDataTypeElementOffset(dta, bpath, BUSId, 7);
	busInfo[offset+15] = dtaGetDataTypeSize(dta, bpath, ssGetDataTypeId(S, "int16"));
	busInfo[offset+16] = dtaGetDataTypeElementOffset(dta, bpath, BUSId, 8);
	busInfo[offset+17] = dtaGetDataTypeSize(dta, bpath, ssGetDataTypeId(S, "int16"));
	busInfo[offset+18] = dtaGetDataTypeElementOffset(dta, bpath, BUSId, 9);
	busInfo[offset+19] = dtaGetDataTypeSize(dta, bpath, ssGetDataTypeId(S, "uint8"));
	busInfo[offset+20] = dtaGetDataTypeElementOffset(dta, bpath, BUSId, 10);
	busInfo[offset+21] = dtaGetDataTypeSize(dta, bpath, ssGetDataTypeId(S, "uint8"));
	ssSetUserData(S, busInfo);
}


/*
Encode the incoming character vector into the MAVLink bitstream. This process
consists of two stages - encode this character vector into a bus (using the
busInfo vector), and pass this struct to the MAVLink library to encode it into
a bitstream.
*/
static inline uint16_t encode_vector_rc_channels_scaled(const char *uvec, const int_T *busInfo, uint8_T *yvec, const int_T offset)
{
	mavlink_rc_channels_scaled_t ubus;
	mavlink_message_t msg_encoded;
	
	(void) memcpy(&ubus.time_boot_ms, uvec + busInfo[offset+0], busInfo[offset+1]);
	(void) memcpy(&ubus.chan1_scaled, uvec + busInfo[offset+2], busInfo[offset+3]);
	(void) memcpy(&ubus.chan2_scaled, uvec + busInfo[offset+4], busInfo[offset+5]);
	(void) memcpy(&ubus.chan3_scaled, uvec + busInfo[offset+6], busInfo[offset+7]);
	(void) memcpy(&ubus.chan4_scaled, uvec + busInfo[offset+8], busInfo[offset+9]);
	(void) memcpy(&ubus.chan5_scaled, uvec + busInfo[offset+10], busInfo[offset+11]);
	(void) memcpy(&ubus.chan6_scaled, uvec + busInfo[offset+12], busInfo[offset+13]);
	(void) memcpy(&ubus.chan7_scaled, uvec + busInfo[offset+14], busInfo[offset+15]);
	(void) memcpy(&ubus.chan8_scaled, uvec + busInfo[offset+16], busInfo[offset+17]);
	(void) memcpy(&ubus.port, uvec + busInfo[offset+18], busInfo[offset+19]);
	(void) memcpy(&ubus.rssi, uvec + busInfo[offset+20], busInfo[offset+21]);
	
	mavlink_msg_rc_channels_scaled_encode(SYS_ID, COMP_ID, &msg_encoded, &ubus);
	return mavlink_msg_to_send_buffer(yvec, &msg_encoded);
}


/*
Decode the incoming MAVLink message into an output character vector. This process
consists of two stages - use the MAVLink library to convert the MAVLink message
into its appropriate struct, and then decode this struct into the output character
vector according to busInfo.
*/
static inline void decode_msg_rc_channels_scaled(const mavlink_message_t* msg_encoded, const int_T *busInfo, char *yvec, const int_T offset)
{
	mavlink_rc_channels_scaled_t ybus;
	mavlink_msg_rc_channels_scaled_decode(msg_encoded, &ybus);
	
	(void) memcpy(yvec + busInfo[offset+0], &ybus.time_boot_ms, busInfo[offset+1]);
	(void) memcpy(yvec + busInfo[offset+2], &ybus.chan1_scaled, busInfo[offset+3]);
	(void) memcpy(yvec + busInfo[offset+4], &ybus.chan2_scaled, busInfo[offset+5]);
	(void) memcpy(yvec + busInfo[offset+6], &ybus.chan3_scaled, busInfo[offset+7]);
	(void) memcpy(yvec + busInfo[offset+8], &ybus.chan4_scaled, busInfo[offset+9]);
	(void) memcpy(yvec + busInfo[offset+10], &ybus.chan5_scaled, busInfo[offset+11]);
	(void) memcpy(yvec + busInfo[offset+12], &ybus.chan6_scaled, busInfo[offset+13]);
	(void) memcpy(yvec + busInfo[offset+14], &ybus.chan7_scaled, busInfo[offset+15]);
	(void) memcpy(yvec + busInfo[offset+16], &ybus.chan8_scaled, busInfo[offset+17]);
	(void) memcpy(yvec + busInfo[offset+18], &ybus.port, busInfo[offset+19]);
	(void) memcpy(yvec + busInfo[offset+20], &ybus.rssi, busInfo[offset+21]);
}
