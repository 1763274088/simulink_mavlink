/*
DO NOT EDIT.
This file was automatically created by the Matlab function 'create_sfun_decode' on 06-Sep-2018 11:02:29
as part of Simulink MAVLink library.
*/

#define S_FUNCTION_NAME  sfun_decode_mavlink
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"

// System and Component IDs for MAVLink communication
#define SYS_ID 100
#define COMP_ID 200

#include "include/mavlink/v1.0/common/mavlink.h"

#include "include/sfun_decode_mavlink.h"

/* Function: mdlInitializeSizes ================================================
 * REQUIRED METHOD
 * Abstract:
 *    The sizes information is used by Simulink to determine the S-function
 *    block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct *S)
{

    DECL_AND_INIT_DIMSINFO(inputDimsInfo);
    DECL_AND_INIT_DIMSINFO(outputDimsInfo);

    ssSetNumSFcnParams(S, 0);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch will be reported by Simulink */
    }

    if (!ssSetNumInputPorts(S, 1)) return;

    ssSetInputPortDirectFeedThrough(S, 0, 1);
    ssSetInputPortRequiredContiguous(S, 0, 1);
    ssSetInputPortDataType(S, 0, SS_UINT8);
    ssSetInputPortVectorDimension(S, 0, MAVLINK_MAX_PACKET_LEN);

	if (!ssSetNumOutputPorts(S, 11)) return;

	#if defined(MATLAB_MEX_FILE)
	if (ssGetSimMode(S) != SS_SIMMODE_SIZES_CALL_ONLY)
	{
		DTypeId dataTypeIdReg0;
		ssRegisterTypeFromNamedObject(S, BUS_NAME_HEARTBEAT, &dataTypeIdReg0);
		if (dataTypeIdReg0 == INVALID_DTYPE_ID) return;
		ssSetOutputPortDataType(S, 0, dataTypeIdReg0);

		DTypeId dataTypeIdReg1;
		ssRegisterTypeFromNamedObject(S, BUS_NAME_ATTITUDE, &dataTypeIdReg1);
		if (dataTypeIdReg1 == INVALID_DTYPE_ID) return;
		ssSetOutputPortDataType(S, 1, dataTypeIdReg1);

		DTypeId dataTypeIdReg2;
		ssRegisterTypeFromNamedObject(S, BUS_NAME_RAW_IMU, &dataTypeIdReg2);
		if (dataTypeIdReg2 == INVALID_DTYPE_ID) return;
		ssSetOutputPortDataType(S, 2, dataTypeIdReg2);

		DTypeId dataTypeIdReg3;
		ssRegisterTypeFromNamedObject(S, BUS_NAME_SET_MODE, &dataTypeIdReg3);
		if (dataTypeIdReg3 == INVALID_DTYPE_ID) return;
		ssSetOutputPortDataType(S, 3, dataTypeIdReg3);

		DTypeId dataTypeIdReg4;
		ssRegisterTypeFromNamedObject(S, BUS_NAME_SET_ATTITUDE_TARGET, &dataTypeIdReg4);
		if (dataTypeIdReg4 == INVALID_DTYPE_ID) return;
		ssSetOutputPortDataType(S, 4, dataTypeIdReg4);

		DTypeId dataTypeIdReg5;
		ssRegisterTypeFromNamedObject(S, BUS_NAME_SET_POSITION_TARGET_LOCAL_NED, &dataTypeIdReg5);
		if (dataTypeIdReg5 == INVALID_DTYPE_ID) return;
		ssSetOutputPortDataType(S, 5, dataTypeIdReg5);

		DTypeId dataTypeIdReg6;
		ssRegisterTypeFromNamedObject(S, BUS_NAME_ATT_POS_MOCAP, &dataTypeIdReg6);
		if (dataTypeIdReg6 == INVALID_DTYPE_ID) return;
		ssSetOutputPortDataType(S, 6, dataTypeIdReg6);

		DTypeId dataTypeIdReg7;
		ssRegisterTypeFromNamedObject(S, BUS_NAME_DATA_STREAM, &dataTypeIdReg7);
		if (dataTypeIdReg7 == INVALID_DTYPE_ID) return;
		ssSetOutputPortDataType(S, 7, dataTypeIdReg7);

		DTypeId dataTypeIdReg8;
		ssRegisterTypeFromNamedObject(S, BUS_NAME_REQUEST_DATA_STREAM, &dataTypeIdReg8);
		if (dataTypeIdReg8 == INVALID_DTYPE_ID) return;
		ssSetOutputPortDataType(S, 8, dataTypeIdReg8);

		DTypeId dataTypeIdReg9;
		ssRegisterTypeFromNamedObject(S, BUS_NAME_ATTITUDE_TARGET, &dataTypeIdReg9);
		if (dataTypeIdReg9 == INVALID_DTYPE_ID) return;
		ssSetOutputPortDataType(S, 9, dataTypeIdReg9);

		DTypeId dataTypeIdReg10;
		ssRegisterTypeFromNamedObject(S, BUS_NAME_POSITION_TARGET_LOCAL_NED, &dataTypeIdReg10);
		if (dataTypeIdReg10 == INVALID_DTYPE_ID) return;
		ssSetOutputPortDataType(S, 10, dataTypeIdReg10);

	}
	#endif

	ssSetBusOutputObjectName(S, 0, (void *) BUS_NAME_HEARTBEAT);
	ssSetBusOutputObjectName(S, 1, (void *) BUS_NAME_ATTITUDE);
	ssSetBusOutputObjectName(S, 2, (void *) BUS_NAME_RAW_IMU);
	ssSetBusOutputObjectName(S, 3, (void *) BUS_NAME_SET_MODE);
	ssSetBusOutputObjectName(S, 4, (void *) BUS_NAME_SET_ATTITUDE_TARGET);
	ssSetBusOutputObjectName(S, 5, (void *) BUS_NAME_SET_POSITION_TARGET_LOCAL_NED);
	ssSetBusOutputObjectName(S, 6, (void *) BUS_NAME_ATT_POS_MOCAP);
	ssSetBusOutputObjectName(S, 7, (void *) BUS_NAME_DATA_STREAM);
	ssSetBusOutputObjectName(S, 8, (void *) BUS_NAME_REQUEST_DATA_STREAM);
	ssSetBusOutputObjectName(S, 9, (void *) BUS_NAME_ATTITUDE_TARGET);
	ssSetBusOutputObjectName(S, 10, (void *) BUS_NAME_POSITION_TARGET_LOCAL_NED);

	ssSetOutputPortWidth(S, 0, 1);
	ssSetOutputPortWidth(S, 1, 1);
	ssSetOutputPortWidth(S, 2, 1);
	ssSetOutputPortWidth(S, 3, 1);
	ssSetOutputPortWidth(S, 4, 1);
	ssSetOutputPortWidth(S, 5, 1);
	ssSetOutputPortWidth(S, 6, 1);
	ssSetOutputPortWidth(S, 7, 1);
	ssSetOutputPortWidth(S, 8, 1);
	ssSetOutputPortWidth(S, 9, 1);
	ssSetOutputPortWidth(S, 10, 1);

	ssSetBusOutputAsStruct(S, 0, 1);
	ssSetBusOutputAsStruct(S, 1, 1);
	ssSetBusOutputAsStruct(S, 2, 1);
	ssSetBusOutputAsStruct(S, 3, 1);
	ssSetBusOutputAsStruct(S, 4, 1);
	ssSetBusOutputAsStruct(S, 5, 1);
	ssSetBusOutputAsStruct(S, 6, 1);
	ssSetBusOutputAsStruct(S, 7, 1);
	ssSetBusOutputAsStruct(S, 8, 1);
	ssSetBusOutputAsStruct(S, 9, 1);
	ssSetBusOutputAsStruct(S, 10, 1);

	ssSetOutputPortBusMode(S, 0, SL_BUS_MODE);
	ssSetOutputPortBusMode(S, 1, SL_BUS_MODE);
	ssSetOutputPortBusMode(S, 2, SL_BUS_MODE);
	ssSetOutputPortBusMode(S, 3, SL_BUS_MODE);
	ssSetOutputPortBusMode(S, 4, SL_BUS_MODE);
	ssSetOutputPortBusMode(S, 5, SL_BUS_MODE);
	ssSetOutputPortBusMode(S, 6, SL_BUS_MODE);
	ssSetOutputPortBusMode(S, 7, SL_BUS_MODE);
	ssSetOutputPortBusMode(S, 8, SL_BUS_MODE);
	ssSetOutputPortBusMode(S, 9, SL_BUS_MODE);
	ssSetOutputPortBusMode(S, 10, SL_BUS_MODE);

    ssSetNumSampleTimes(S, 1);

    /* specify the sim state compliance to be same as a built-in block */
    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);

    ssSetOptions(S, 0);   /* general options (SS_OPTION_xx) */

} /* end mdlInitializeSizes */


/* Function: mdlInitializeSampleTimes ==========================================
 * REQUIRED METHOD
 * Abstract:
 *    This function is used to specify the sample time(s) for your
 *    S-function. You must register the same number of sample times as
 *    specified in ssSetNumSampleTimes.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    /* Register one pair for each sample time */
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
    ssSetModelReferenceSampleTimeDefaultInheritance(S);

} /* end mdlInitializeSampleTimes */

/* Function: mdlStart ==========================================================
 * Abstract:
 *    This function is called once at start of model execution. If you
 *    have states that should be initialized once, this is the place
 *    to do it.
 */
#define MDL_START
static void mdlStart(SimStruct *S)
{
    int_T *busInfo = (int_T *) malloc(2*NFIELDS_OUTPUT_BUS*sizeof(int_T));
    if(busInfo == NULL) {
      ssSetErrorStatus(S, "Memory allocation failure");
      return;
    }

	encode_businfo_heartbeat(S, busInfo, OFFSET_HEARTBEAT);
	encode_businfo_attitude(S, busInfo, OFFSET_ATTITUDE);
	encode_businfo_raw_imu(S, busInfo, OFFSET_RAW_IMU);
	encode_businfo_set_mode(S, busInfo, OFFSET_SET_MODE);
	encode_businfo_set_attitude_target(S, busInfo, OFFSET_SET_ATTITUDE_TARGET);
	encode_businfo_set_position_target_local_ned(S, busInfo, OFFSET_SET_POSITION_TARGET_LOCAL_NED);
	encode_businfo_att_pos_mocap(S, busInfo, OFFSET_ATT_POS_MOCAP);
	encode_businfo_data_stream(S, busInfo, OFFSET_DATA_STREAM);
	encode_businfo_request_data_stream(S, busInfo, OFFSET_REQUEST_DATA_STREAM);
	encode_businfo_attitude_target(S, busInfo, OFFSET_ATTITUDE_TARGET);
	encode_businfo_position_target_local_ned(S, busInfo, OFFSET_POSITION_TARGET_LOCAL_NED);

    ssSetUserData(S, busInfo);
} /* end mdlStart */


/* Function: mdlOutputs ========================================================
 * REQUIRED METHOD
 * Abstract:
 *    In this function, you compute the outputs of your S-function
 *    block.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{

    int_T len_uvec = ssGetInputPortWidth(S, 0);
    const uint8_T* uvec = (uint8_T*) ssGetInputPortSignal(S, 0);

    mavlink_message_t msg;
    mavlink_status_t status;

    for (int uidx = 0; uidx < len_uvec; uidx++) {
      if(mavlink_parse_char(MAVLINK_COMM_0, uvec[uidx], &msg, &status)) {
        decode_mavlink_msg(S, &msg);
      }
    }

}

/* Function: mdlTerminate ======================================================
 * REQUIRED METHOD
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
 static void mdlTerminate(SimStruct *S)
 {
     /* Free stored bus information */
     int_T *busInfo = (int_T *) ssGetUserData(S);
     if(busInfo != NULL) {
         free(busInfo);
     }
 }

/*=============================*
 * Required S-function trailer *
 *=============================*/

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif

