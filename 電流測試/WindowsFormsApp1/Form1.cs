using EasyModbus;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1{
    public partial class Form1 : Form{
        private ModbusClient modbusClient;
        int count = 0;
        public Form1(){
            InitializeComponent();
            chart1.Legends.Clear();
        }
        private void btn_Connect_Click(object sender, EventArgs e){
            try{
                modbusClient = new ModbusClient(tb_ip.Text, 502);    //Ip-Address and Port of Modbus-TCP-Server
                modbusClient.Connect();     //Connect to Server
                timer.Enabled = true;
            }
            catch (Exception ex) { }
        }
        private void timer_Tick(object sender, EventArgs e){
            Get_Data("31");
        }
        int chart_max = 1000;
        List<string> tem_chart = new List<string>();
        private void draw_chart(float output){
            if (count > chart_max){
                tem_chart.RemoveAt(0);
                chart1.Series[0].Points.Clear();
                for (int i = 0; i < chart_max; i++) chart1.Series[0].Points.AddXY(count - (chart_max - i), tem_chart[i]);
            }
            chart1.Series[0].Points.AddXY(count + 1, output);
            count++;
            tem_chart.Add(output.ToString());
        }
        private void Get_Data(string address){
            try{
                modbusClient.UnitIdentifier = byte.Parse("1");
                int start = int.Parse(address) - 1;
                int[] readHoldingRegisters = modbusClient.ReadHoldingRegisters(start, 2);
                int tem = readHoldingRegisters[0];
                readHoldingRegisters[0] = readHoldingRegisters[1];
                readHoldingRegisters[1] = tem;
                float output = Show_Data_Float(readHoldingRegisters);
                //int output = readHoldingRegisters[0];
                draw_chart(output);
                //Console.Write(output);
            }
            catch (Exception ex){
                MessageBox.Show(ex.ToString());
            }
        }
        private static float Show_Data_Float(int[] date){
            float sum = 0;                                      //存放最終運算結果
            string date_1 = Convert.ToString(date[0], 2);       //將十進位數字轉為二進位
            while (date_1.Length < 16) date_1 = "0" + date_1;   //未滿16位將前方補0
            string date_2 = Convert.ToString(date[1], 2);       //將十進位數字轉為二進位
            while (date_2.Length < 16) date_2 = "0" + date_2;   //未滿16位將前方補0
            string tem = date_1 + date_2;                       //將二進位組合成32位元
            string sign = tem.Substring(0, 1);                  //代表正負號
            string exponent = tem.Substring(1, 8);                   //指數
            string fraction = tem.Substring(9, 23);                  //浮點數值
            if (sign.Equals("0")) sum = 1f;
            else sum = -1f;
            int expo = -127 + Convert.ToInt32(exponent, 2);     //計算指數值
            float frac = 1;                                     //有效數位的初始值為1
            char[] tem_c = fraction.ToCharArray();              //將有效數位轉為char陣列
            for (int i = 0; i < tem_c.Length; i++){
                if (tem_c[i] == '1')
                    frac += (float)Math.Pow(2, -(i + 1));
            }
            sum *= (float)(frac * Math.Pow(2, expo));           //計算浮點數(正負值 * 指數加權 * 有效數位)
            sum = (float)Math.Round(sum, 4);                    //四捨五入到小數點後第二位
            return sum;
        }
    }
}
