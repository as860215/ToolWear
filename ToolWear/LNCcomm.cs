using System;
using System.Text;
using System.Runtime.InteropServices;

namespace LNCcomm
{	
	public class CLNCc
	{
        public const int LNC_MAX_CONNECT_NUM            = 1;

		//sensor type, lnc_svi_get_type(type)
		public const int LNC_TYPE_UNKNOWN				= 0;
		public const int LNC_TYPE_SVI1000				= 1;
		public const int LNC_TYPE_SVI2000				= 2;

		//sensor selection, lnc_svi_set_sel(svi), lnc_svi_get_sel(svi)
		public const int LNC_SEL_UNKNOWN				= 0;
		public const int LNC_SEL_AUTO					= 0;
		public const int LNC_SEL_SVI					= 1;
		public const int LNC_SEL_ETS0					= 2;
		public const int LNC_SEL_ETS1					= 3;
		public const int LNC_SEL_ETS2					= 4;
		public const int LNC_SEL_ETS3					= 5;
		public const int LNC_SEL_ETS4					= 6;
		public const int LNC_SEL_ETS5					= 7;
		public const int LNC_SEL_ETS6					= 8;
		public const int LNC_SEL_ETS7					= 9;

        //communication status, lnc_get_status(commSts); 
        public const int LNC_COMM_STATE_DISCONNECT      = 0;
        public const int LNC_COMM_STATE_CONNECTING      = 1;
        public const int LNC_COMM_STATE_FAIL            = 2;
        public const int LNC_COMM_STATE_OK              = 3;
        public const int LNC_COMM_STATE_NORESPONSE      = 4;

        //sensor status, lnc_get_status(sensorSts)
        public const int LNC_SENSOR_OFFLINE             = 0;
        public const int LNC_SENSOR_ONLINE              = 1;
        public const int LNC_SENSOR_BUFFER_OVERFLOW     = 2;

        //select the frequency domain data of the axis, lnc_svi_set_fd_axis(axis), default: LNC_FD_SEL_X
        public const int LNC_FD_SEL_X                   = 0;
        public const int LNC_FD_SEL_Y                   = 1;
        public const int LNC_FD_SEL_Z                   = 2;
        public const int LNC_FD_SEL_VECTOR              = 3;

        public const int LNC_FD_DATA_LENGTH_1D66K       = 830;
        public const int LNC_FD_DATA_LENGTH_6D66K       = 3320;

        // --- define function return code
        public const int LNC_ERR_NO_ERROR               = (0);
        public const int LNC_ERR_FAILED                 = (-1);
        public const int LNC_ERR_WRONG_PARAM            = (-2);
        public const int LNC_ERR_INCORRECT_NID          = (-3);
        public const int LNC_ERR_TIMEOUT                = (-4);
        public const int LNC_ERR_NOT_CONNECTED          = (-5);
        public const int LNC_ERR_CMD_QUEUE_FULL         = (-6);
        public const int LNC_ERR_NO_NEW_DATA            = (-7);
        public const int LNC_ERR_SENSOR_OFFLINE         = (-8);


        [DllImport("LNCcomm.dll", EntryPoint = "lnc_get_controller_cnt")]
        public static extern short lnc_get_controller_cnt(ref int existCnt);

        [DllImport("LNCcomm.dll", EntryPoint = "lnc_get_controller_info")]
        public static extern short lnc_get_controller_info(ushort index, [MarshalAsAttribute(UnmanagedType.LPStr)] StringBuilder name, [MarshalAsAttribute(UnmanagedType.LPStr)] StringBuilder ip);

        [DllImport("LNCcomm.dll", EntryPoint = "lnc_connect")]
        public static extern short lnc_connect(ushort nodeID, [MarshalAsAttribute(UnmanagedType.LPStr)] string IP, ushort timeout);

        [DllImport("LNCcomm.dll", EntryPoint = "lnc_disconnect")]
        public static extern short lnc_disconnect(ushort nodeID);

        [DllImport("LNCcomm.dll", EntryPoint = "lnc_get_status")]
        public static extern short lnc_get_status(ushort nodeID, ref byte commSts, ref byte sensorSts, ref int watchdogCnt);

		[DllImport("LNCcomm.dll", EntryPoint = "lnc_svi_get_type")]
        public static extern short lnc_svi_get_type(ushort nodeID, ref int type);
		
		[DllImport("LNCcomm.dll", EntryPoint = "lnc_svi_get_sts")]
        public static extern short lnc_svi_get_sts(ushort nodeID, ushort svi, ref byte sts);

		[DllImport("LNCcomm.dll", EntryPoint = "lnc_svi_set_sel")]
        public static extern short lnc_svi_set_sel(ushort nodeID, ushort svi);

		[DllImport("LNCcomm.dll", EntryPoint = "lnc_svi_get_sel")]
        public static extern short lnc_svi_get_sel(ushort nodeID, ref ushort svi);		

        [DllImport("LNCcomm.dll", EntryPoint = "lnc_svi_set_zero")]
        public static extern short lnc_svi_set_zero(ushort nodeID);

        [DllImport("LNCcomm.dll", EntryPoint = "lnc_svi_clear_zero")]
        public static extern short lnc_svi_clear_zero(ushort nodeID);

        [DllImport("LNCcomm.dll", EntryPoint = "lnc_svi_enable")]
        public static extern short lnc_svi_enable(ushort nodeID, byte enable);

        [DllImport("LNCcomm.dll", EntryPoint = "lnc_svi_get_td_data_length")]
        public static extern short lnc_svi_get_td_data_length(ushort nodeID, ref uint length);

        [DllImport("LNCcomm.dll", EntryPoint = "lnc_svi_get_td_data")]
        public static extern short lnc_svi_get_td_data(ushort nodeID, uint length, ref short arrData, ref uint getNum);

        [DllImport("LNCcomm.dll", EntryPoint = "lnc_svi_set_fd_axis")]
        public static extern short lnc_svi_set_fd_axis(ushort nodeID, byte axis);

        [DllImport("LNCcomm.dll", EntryPoint = "lnc_svi_get_fd_data")]
        public static extern short lnc_svi_get_fd_data(ushort nodeID, ref float arrData);

        [DllImport("LNCcomm.dll", EntryPoint = "lnc_svi_get_cmd_error_cnt")]
        public static extern short lnc_svi_get_cmd_error_cnt(ushort nodeID, ref int errorCnt);

        [DllImport("LNCcomm.dll", EntryPoint = "lnc_svi_reset_cmd_error_cnt")]
        public static extern short lnc_svi_reset_cmd_error_cnt(ushort nodeID);

    }	
}