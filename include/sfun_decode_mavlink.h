/*
DO NOT EDIT.
This file was automatically created by the Matlab function 'create_sfun_decode' on 06-Sep-2018 11:02:29
as part of Simulink MAVLink library.
*/

#include "include/sfun_mavlink_msg_heartbeat.h"
#include "include/sfun_mavlink_msg_attitude.h"
#include "include/sfun_mavlink_msg_raw_imu.h"
#include "include/sfun_mavlink_msg_set_mode.h"
#include "include/sfun_mavlink_msg_set_attitude_target.h"
#include "include/sfun_mavlink_msg_set_position_target_local_ned.h"
#include "include/sfun_mavlink_msg_att_pos_mocap.h"
#include "include/sfun_mavlink_msg_data_stream.h"
#include "include/sfun_mavlink_msg_request_data_stream.h"
#include "include/sfun_mavlink_msg_attitude_target.h"
#include "include/sfun_mavlink_msg_position_target_local_ned.h"

#define NFIELDS_OUTPUT_BUS (NFIELDS_BUS_HEARTBEAT + NFIELDS_BUS_ATTITUDE + NFIELDS_BUS_RAW_IMU + NFIELDS_BUS_SET_MODE + NFIELDS_BUS_SET_ATTITUDE_TARGET + NFIELDS_BUS_SET_POSITION_TARGET_LOCAL_NED + NFIELDS_BUS_ATT_POS_MOCAP + NFIELDS_BUS_DATA_STREAM + NFIELDS_BUS_REQUEST_DATA_STREAM + NFIELDS_BUS_ATTITUDE_TARGET + NFIELDS_BUS_POSITION_TARGET_LOCAL_NED)

#define OFFSET_HEARTBEAT 0
#define OFFSET_ATTITUDE 2*(NFIELDS_BUS_HEARTBEAT)
#define OFFSET_RAW_IMU 2*(NFIELDS_BUS_ATTITUDE+NFIELDS_BUS_HEARTBEAT)
#define OFFSET_SET_MODE 2*(NFIELDS_BUS_RAW_IMU+NFIELDS_BUS_ATTITUDE+NFIELDS_BUS_HEARTBEAT)
#define OFFSET_SET_ATTITUDE_TARGET 2*(NFIELDS_BUS_SET_MODE+NFIELDS_BUS_RAW_IMU+NFIELDS_BUS_ATTITUDE+NFIELDS_BUS_HEARTBEAT)
#define OFFSET_SET_POSITION_TARGET_LOCAL_NED 2*(NFIELDS_BUS_SET_ATTITUDE_TARGET+NFIELDS_BUS_SET_MODE+NFIELDS_BUS_RAW_IMU+NFIELDS_BUS_ATTITUDE+NFIELDS_BUS_HEARTBEAT)
#define OFFSET_ATT_POS_MOCAP 2*(NFIELDS_BUS_SET_POSITION_TARGET_LOCAL_NED+NFIELDS_BUS_SET_ATTITUDE_TARGET+NFIELDS_BUS_SET_MODE+NFIELDS_BUS_RAW_IMU+NFIELDS_BUS_ATTITUDE+NFIELDS_BUS_HEARTBEAT)
#define OFFSET_DATA_STREAM 2*(NFIELDS_BUS_ATT_POS_MOCAP+NFIELDS_BUS_SET_POSITION_TARGET_LOCAL_NED+NFIELDS_BUS_SET_ATTITUDE_TARGET+NFIELDS_BUS_SET_MODE+NFIELDS_BUS_RAW_IMU+NFIELDS_BUS_ATTITUDE+NFIELDS_BUS_HEARTBEAT)
#define OFFSET_REQUEST_DATA_STREAM 2*(NFIELDS_BUS_DATA_STREAM+NFIELDS_BUS_ATT_POS_MOCAP+NFIELDS_BUS_SET_POSITION_TARGET_LOCAL_NED+NFIELDS_BUS_SET_ATTITUDE_TARGET+NFIELDS_BUS_SET_MODE+NFIELDS_BUS_RAW_IMU+NFIELDS_BUS_ATTITUDE+NFIELDS_BUS_HEARTBEAT)
#define OFFSET_ATTITUDE_TARGET 2*(NFIELDS_BUS_REQUEST_DATA_STREAM+NFIELDS_BUS_DATA_STREAM+NFIELDS_BUS_ATT_POS_MOCAP+NFIELDS_BUS_SET_POSITION_TARGET_LOCAL_NED+NFIELDS_BUS_SET_ATTITUDE_TARGET+NFIELDS_BUS_SET_MODE+NFIELDS_BUS_RAW_IMU+NFIELDS_BUS_ATTITUDE+NFIELDS_BUS_HEARTBEAT)
#define OFFSET_POSITION_TARGET_LOCAL_NED 2*(NFIELDS_BUS_ATTITUDE_TARGET+NFIELDS_BUS_REQUEST_DATA_STREAM+NFIELDS_BUS_DATA_STREAM+NFIELDS_BUS_ATT_POS_MOCAP+NFIELDS_BUS_SET_POSITION_TARGET_LOCAL_NED+NFIELDS_BUS_SET_ATTITUDE_TARGET+NFIELDS_BUS_SET_MODE+NFIELDS_BUS_RAW_IMU+NFIELDS_BUS_ATTITUDE+NFIELDS_BUS_HEARTBEAT)

/*
Decode the incoming MAVLink message
*/
static inline void decode_mavlink_msg (SimStruct *S, const mavlink_message_t *msg)
{
	int_T *busInfo = (int_T *) ssGetUserData(S);

	char* yvec0 = (char *) ssGetOutputPortRealSignal(S, 0);
	char* yvec1 = (char *) ssGetOutputPortRealSignal(S, 1);
	char* yvec2 = (char *) ssGetOutputPortRealSignal(S, 2);
	char* yvec3 = (char *) ssGetOutputPortRealSignal(S, 3);
	char* yvec4 = (char *) ssGetOutputPortRealSignal(S, 4);
	char* yvec5 = (char *) ssGetOutputPortRealSignal(S, 5);
	char* yvec6 = (char *) ssGetOutputPortRealSignal(S, 6);
	char* yvec7 = (char *) ssGetOutputPortRealSignal(S, 7);
	char* yvec8 = (char *) ssGetOutputPortRealSignal(S, 8);
	char* yvec9 = (char *) ssGetOutputPortRealSignal(S, 9);
	char* yvec10 = (char *) ssGetOutputPortRealSignal(S, 10);
	switch (msg->msgid) {

		case MAVLINK_MSG_ID_HEARTBEAT:
			decode_msg_heartbeat(msg, busInfo, yvec0, OFFSET_HEARTBEAT);

		case MAVLINK_MSG_ID_ATTITUDE:
			decode_msg_attitude(msg, busInfo, yvec1, OFFSET_ATTITUDE);

		case MAVLINK_MSG_ID_RAW_IMU:
			decode_msg_raw_imu(msg, busInfo, yvec2, OFFSET_RAW_IMU);

		case MAVLINK_MSG_ID_SET_MODE:
			decode_msg_set_mode(msg, busInfo, yvec3, OFFSET_SET_MODE);

		case MAVLINK_MSG_ID_SET_ATTITUDE_TARGET:
			decode_msg_set_attitude_target(msg, busInfo, yvec4, OFFSET_SET_ATTITUDE_TARGET);

		case MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED:
			decode_msg_set_position_target_local_ned(msg, busInfo, yvec5, OFFSET_SET_POSITION_TARGET_LOCAL_NED);

		case MAVLINK_MSG_ID_ATT_POS_MOCAP:
			decode_msg_att_pos_mocap(msg, busInfo, yvec6, OFFSET_ATT_POS_MOCAP);

		case MAVLINK_MSG_ID_DATA_STREAM:
			decode_msg_data_stream(msg, busInfo, yvec7, OFFSET_DATA_STREAM);

		case MAVLINK_MSG_ID_REQUEST_DATA_STREAM:
			decode_msg_request_data_stream(msg, busInfo, yvec8, OFFSET_REQUEST_DATA_STREAM);

		case MAVLINK_MSG_ID_ATTITUDE_TARGET:
			decode_msg_attitude_target(msg, busInfo, yvec9, OFFSET_ATTITUDE_TARGET);

		case MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED:
			decode_msg_position_target_local_ned(msg, busInfo, yvec10, OFFSET_POSITION_TARGET_LOCAL_NED);
	}
}
