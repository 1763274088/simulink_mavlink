% Example for creating s-functions for encoding as well as decoding
% MAVLink messages

% See "examples_use_sfunctions.slx" for usage of these s-functions in
% Simulink

% Go to the top directory
clear all;
clc;
this_dir = fileparts(mfilename('fullpath'));
dir_sep = regexp(this_dir, filesep, 'split');
cd(fullfile(dir_sep{1:end-1}));

% Select the MAVLink header files for messages we want to use
filenames = {
    'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_heartbeat.h';
    'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_attitude.h';
    'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_raw_imu.h';
    'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_set_mode.h';
    'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_set_attitude_target.h';
    'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_set_position_target_local_ned.h';
    'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_att_pos_mocap.h';
    'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_data_stream.h';
    'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_request_data_stream.h';
    'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_attitude_target.h';
    'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_position_target_local_ned.h';
    'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_rc_channels_raw.h';
     'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_rc_channels.h';
     'D:\000_simulink_mavlink-udp-git\simulink_mavlink\include\mavlink\v1.0\common\mavlink_msg_rc_channels_scaled.h';
    };

%% Create encoder s-functions
% Calling create_sfun_encode will creates buses, header files, s-function
% cpp files, and will finally compile them. This will create one encoder
% s-function for each message

for i = 1:length(filenames)
    create_sfun_encode(filenames{i});
end

%% Create decider s-function
% Calling create_sfun_decode will creates buses, header files, s-function
% cpp file, and will finally compile it. This will create one decoder
% s-function in total

create_sfun_decode(filenames);
