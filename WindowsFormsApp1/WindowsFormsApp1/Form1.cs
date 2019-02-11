using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1{
    public partial class Form1 : Form{
        string path = @"C:\Users\user\Desktop\Campro\ToolWear\ToolWear\bin\Debug\data\FFT\";
        int count = 0;
        public Form1(){
            InitializeComponent();
            chart1.Legends.Clear();
            //string[] file = new string[] { "1-1.cp" , "1-2.cp" , "1-3.cp" , "1-4.cp" , "1-5.cp" , "new1-2.cp" };
            //for (int i = 0; i < file.Length; i++){
            //    StreamReader sr = new StreamReader(path + file[i]);
            //    int count = 1;
            //    while (!sr.EndOfStream){
            //        chart1.Series[i].Points.AddXY(count * 5, sr.ReadLine());
            //        count++;
            //    }
            //}
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            //if (chart1.Series[0].Points.Count == 5)
            //    chart1.Series[0].Points.RemoveAt(0);
            Random ran = new Random();
            chart1.Series[0].Points.AddXY(count, 25 + ran.NextDouble());
            count++;
        }
    }
}
