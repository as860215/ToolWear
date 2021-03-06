﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using EZNCAUTLib;

namespace ConsoleApp1{
    class Program{
        static void Main(string[] args){
            DispEZNcCommunication EZNcCom = new DispEZNcCommunication();
            long lRet;
            int lSystemType = 9;
            int ATC_NUM = 0;
            lRet = EZNcCom.SetTCPIPProtocol("192.168.11.220", 683);
            lRet = EZNcCom.Open2(lSystemType,1,100,"EZNC_LOCALHOST");

            //軸負載(0%為0，1%為65535，2%為65534，以此類推)
            int lAxisNo = 3;
            int lIndex = 3;
            lRet = EZNcCom.Monitor_GetServoMonitor(lAxisNo, lIndex, out int plData, out string pbstrBuffer);

            //lRet = EZNcCom.Operation_Stop();

            //lRet = EZNcCom.Operation_Run();

            //object vValues = null;
            //lRet = EZNcCom.Device_ReadBlock(2,"M4992",2,out vValues);
            //Console.WriteLine(vValues);

            //while (true)
            //{
            //    //取得目前使用刀號
            //    lRet = EZNcCom.ATC_GetMGNReady(0, out ATC_NUM);
            //    //display
            //    Console.WriteLine(DateTime.Now.ToString("HH:mm:ss : ") + ATC_NUM);

            //}



            //int lIndex = 2, lspindle = 1, plData = 0;
            //string buffer = "";
            //while (true)
            //{
            //    lRet = EZNcCom.Monitor_GetSpindleMonitor(lIndex, lspindle, out plData, out buffer);
            //    Console.WriteLine(DateTime.Now.ToString("HH:mm:ss : ") + plData);
            //}


            //while (true)
            //{
            //    int status = 0;
            //    lRet = EZNcCom.Status_GetRunStatus(2, out status);
            //    Thread.Sleep(100);
            //    string[] s = new string[3] { "run", "start", "alarm" };
            //    Console.WriteLine(DateTime.Now.ToString("HH:mm:ss : ") + s[status]);
            //}

            lRet = EZNcCom.Close();
            EZNcCom = null;
            Console.ReadKey();
        }
    }
}
