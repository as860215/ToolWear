using System;
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
            lRet = EZNcCom.SetTCPIPProtocol("192.168.11.205", 683);
            lRet = EZNcCom.Open2(lSystemType,1,100,"EZNC_LOCALHOST");
            //if (lRet == 0){
            //    //取得目前使用刀號
            //    lRet = EZNcCom.ATC_GetMGNReady(0,out ATC_NUM);
            //}

            ////display
            //Console.WriteLine(ATC_NUM);
            
            int lIndex = 2,lspindle = 1,plData = 0;
            string buffer = "";
            double dPosition = 0;
            while (true){
                lRet = EZNcCom.Monitor_GetSpindleMonitor(lIndex, lspindle, out plData, out buffer);
                //lRet = EZNcCom.Position_GetWorkPosition(1, out dPosition, 0);
                Console.WriteLine(DateTime.Now.ToString("HH:mm:ss : ") + plData);
            }


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
