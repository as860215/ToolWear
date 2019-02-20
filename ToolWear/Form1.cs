using CenterSpace.NMath.Core;
using MathNet.Numerics.IntegralTransforms;
using NationalInstruments;
using NationalInstruments.DAQmx;
using System;
using System.Collections.Generic;
using System.Data;
using System.Drawing;
using System.IO;
using System.Numerics;
using System.Windows.Forms;
using EZNCAUTLib;
using System.Threading;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text;
using LNCcomm;
using System.Linq;

namespace ToolWear{
    public partial class Form1 : Form{
        private string path = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase;  //執行檔位置
        private bool machine_connect = false;
        public Form1(){
            InitializeComponent();
            //將視窗最大化
            this.WindowState = FormWindowState.Maximized;
            //隱藏工作列
            this.FormBorderStyle = FormBorderStyle.None;
            //強制置頂視窗
            //this.TopMost = true;
        }
        #region 初始化
        #region 物件初始化
        private void Form1_Shown(object sender, EventArgs e){
            //關閉所有panel
            panel_Dissable();
            //顯示讀取panel
            panel_Loading.Visible = true;
            //將Log panel調整至所有panel下方(以防卡到其他介面)
            panel_log.SendToBack();
            //將Home panel調整至所有panel下方
            panel_Home.SendToBack();
            //啟動背景讀取資料timer
            timer_load.Enabled = true;
            //顯示進度
            tb_Load_ProgressRate.Text = "讀取進度 ： 0 %";
        }
        private float Chart_PointMax = 0.5f, Chart_PointMin = -0.5f;  //折線圖預設上下限
        /// <summary>
        /// 初始化設定
        /// </summary>
        private void Setting(){
            //表單設定
            //this.WindowState = FormWindowState.Maximized; //最大化
            //折線圖Legends清除
            chart_Learn.Legends.Clear();
            chart_Thermal.Legends.Clear();
            chart_Threshold.Legends.Clear();
            chart_ToolWear.Legends.Clear();
            chart_FFT.Legends.Clear();
            chart_LearnFFT.Legends.Clear();
            chart_Thermal_M1.Legends.Clear();
            chart_Thermal_M2.Legends.Clear();
            chart_warring_1.Legends.Clear();
            chart_warring_2.Legends.Clear();
            chart_Blade.Legends.Clear();
            //折線圖上下限與x軸最大值預覽
            //chart_FFT.Series[2].Points.AddXY(1, -0.5);
            chart_Learn.Series[1].Points.AddXY(1, Chart_PointMax);
            chart_Threshold.Series[1].Points.AddXY(1, Chart_PointMax);
            chart_ToolWear.Series[1].Points.AddXY(1, Chart_PointMax);
            chart_warring_1.Series[1].Points.AddXY(1, Chart_PointMax);
            chart_warring_2.Series[1].Points.AddXY(1, Chart_PointMax);
            //震動偵測折線圖
            for (int i = 0; i < Chart_max; i++){
                chart_Learn.Series[2].Points.AddXY(i + 1, Chart_PointMin);
                chart_ToolWear.Series[2].Points.AddXY(i + 1, Chart_PointMin);
            }
            //警戒折線圖
            for(int i = 0; i < 2000; i++){
                chart_warring_1.Series[1].Points.AddXY(i + 1, Chart_PointMin);
                chart_warring_2.Series[1].Points.AddXY(i + 1, Chart_PointMin);
            }
            //FFT折線圖
            for (int i = 0; i < 100; i++){
                chart_FFT.Series[1].Points.AddXY(i + 1, 0.1);
                chart_LearnFFT.Series[1].Points.AddXY(i + 1, 0.1);
                chart_Blade.Series[1].Points.AddXY(i + 1, 0.1);
            }
            //溫度折線圖
            for (int i = 1; i <= 30; i++){
                chart_Thermal.Series[1].Points.AddXY(i, 25);
                chart_Thermal_M1.Series[1].Points.AddXY(i, 25);
                chart_Thermal_M2.Series[1].Points.AddXY(i, 25);
            }
            //Panel
            panel_Home.Visible = true;
        }
        /// <summary>
        /// 隱藏所有panel(主畫面除外)
        /// </summary>
        private void panel_Dissable(){
            //關閉所有panel
            panel_Thermal.Visible = false;
            panel_ThermalSetting.Visible = false;
            panel_Compensate.Visible = false;
            panel_ToolWear.Visible = false;
            panel_ToolWearSetting.Visible = false;
            panel_Learn.Visible = false;
            panel_Threshold.Visible = false;
            panel_ViewModule.Visible = false;
            panel_setting.Visible = false;
            panel_Loading.Visible = false;
            panel_ATCsetting.Visible = false;
            panel_Health.Visible = false;
            panel_SelectParts.Visible = false;
            panel_AddParts.Visible = false;
            //關閉所有主選單副組件
            btn_Learn.Enabled = false;
            //重置所有主選單副組件顯示圖片
            btn_Learn.BackgroundImage = ToolWear.Properties.Resources.tc_menubtn_blank;
        }
        /// <summary>
        /// 初始化資料
        /// </summary>
        private void Initialization(){
            //磨耗偵測 & 軸向設定
            Button[] btn_ToolWearSetting = new Button[20] { btn_ToolWearSetting_01, btn_ToolWearSetting_02, btn_ToolWearSetting_03,
            btn_ToolWearSetting_04,btn_ToolWearSetting_05,btn_ToolWearSetting_06,btn_ToolWearSetting_07,btn_ToolWearSetting_08,
            btn_ToolWearSetting_09,btn_ToolWearSetting_10,btn_ToolWearSetting_11,btn_ToolWearSetting_12,btn_ToolWearSetting_13,
            btn_ToolWearSetting_14,btn_ToolWearSetting_15,btn_ToolWearSetting_16,btn_ToolWearSetting_17,btn_ToolWearSetting_18,
            btn_ToolWearSetting_19,btn_ToolWearSetting_20};
            Button[] btn_ToolWear = new Button[20] { btn_ToolWear_01, btn_ToolWear_02, btn_ToolWear_03,
            btn_ToolWear_04,btn_ToolWear_05,btn_ToolWear_06,btn_ToolWear_07,btn_ToolWear_08,
            btn_ToolWear_09,btn_ToolWear_10,btn_ToolWear_11,btn_ToolWear_12,btn_ToolWear_13,
            btn_ToolWear_14,btn_ToolWear_15,btn_ToolWear_16,btn_ToolWear_17,btn_ToolWear_18,
            btn_ToolWear_19,btn_ToolWear_20};
            Button[] btn_Learn = new Button[20] { btn_Learn_01, btn_Learn_02, btn_Learn_03,
            btn_Learn_04,btn_Learn_05,btn_Learn_06,btn_Learn_07,btn_Learn_08,
            btn_Learn_09,btn_Learn_10,btn_Learn_11,btn_Learn_12,btn_Learn_13,
            btn_Learn_14,btn_Learn_15,btn_Learn_16,btn_Learn_17,btn_Learn_18,
            btn_Learn_19,btn_Learn_20};
            int count = 0;
            try {
                StreamReader sr_axial = new StreamReader(path + @"\data\axial.cp");
                while (!sr_axial.EndOfStream){
                    string axial = sr_axial.ReadLine().Split(',')[0];
                    btn_ToolWearSetting[count].Text = axial;
                    btn_ToolWear[count].Text = axial;
                    btn_Learn[count].Text = axial;
                    count++;
                }
                sr_axial.Close();
                sr_axial.Dispose();
            }
            catch {
                tb_Load_log.Text += "讀取不到軸向資料。\n";
            };
            //熱補償 & 熱補償設定
            Button[] btn_Compensate = new Button[20] { btn_Compensate_01, btn_Compensate_02, btn_Compensate_03,
            btn_Compensate_04,btn_Compensate_05,btn_Compensate_06,btn_Compensate_07,btn_Compensate_08,
            btn_Compensate_09,btn_Compensate_10,btn_Compensate_11,btn_Compensate_12,btn_Compensate_13,
            btn_Compensate_14,btn_Compensate_15,btn_Compensate_16,btn_Compensate_17,btn_Compensate_18,
            btn_Compensate_19,btn_Compensate_20};
            Button[] btn_Thermal = new Button[20] { btn_Thermal_01, btn_Thermal_02, btn_Thermal_03,
            btn_Thermal_04,btn_Thermal_05,btn_Thermal_06,btn_Thermal_07,btn_Thermal_08,
            btn_Thermal_09,btn_Thermal_10,btn_Thermal_11,btn_Thermal_12,btn_Thermal_13,
            btn_Thermal_14,btn_Thermal_15,btn_Thermal_16,btn_Thermal_17,btn_Thermal_18,
            btn_Thermal_19,btn_Thermal_20};
            count = 0;
            try{
                StreamReader sr_thermal = new StreamReader(path + @"\data\thermal.cp");
                while (!sr_thermal.EndOfStream){
                    string axial = sr_thermal.ReadLine().Split(',')[0];
                    btn_Compensate[count].Text = axial;
                    btn_Thermal[count].Text = axial;
                    count++;
                }
                sr_thermal.Close();
                sr_thermal.Dispose();
            }
            catch{
                tb_Load_log.Text += "讀取不到熱補償資料。\n";
            }

            //主畫面 > 設定
            setting_load(false);

            //讀取今日Log事件表
            Read_Log(DateTime.Now.ToString("yyyyMMdd"));
        }
        #endregion
        #region 背景讀取
        //讀取階段
        int Load_Step = 0;
        //正在讀取
        bool is_Load = false;
        //讀取程式計時器
        private void timer_load_Tick(object sender, EventArgs e){
            bar_load.Value = Load_Step;
            void_Loading(Load_Step);
        }
        /// <summary>
        /// 讀取程式
        /// </summary>
        /// <param name="push_in_step">為避免因多執行續造成的變數變化問題，在執行switch之前先暫存其</param>
        private void void_Loading(int push_in_step){
            int tem_step = push_in_step;
            if (tem_step != Load_Step) return;
            //如果有別的執行續已經進入讀取階段了就return
            if (is_Load == true) return;
            string tem = "";
            is_Load = true;
            switch (tem_step){
                case 0:
                    tem = "您好！";
                    //關閉按鈕功能
                    btn_Thermal.Enabled = false;
                    btn_ToolWear.Enabled = false;
                    btn_ATCsetting.Enabled = false;
                    btn_setting.Enabled = false;
                    btn_Health.Enabled = false;
                    btn_logo.Enabled = false;
                    break;
                //保留1~20初始化元件
                case 1:
                    tem = "正在搜尋DAQ訊號輸入...";
                    break;
                case 2:
                    DAQPhysicalChannels();
                    tem = "DAQ訊號輸入搜尋完畢";
                    break;
                case 3:
                    tem = "正在初始化元件屬性...";
                    break;
                case 4:
                    Initialization();
                    tem = "元件初始化完畢";
                    break;
                case 5:
                    tem = "正在設定元件屬性...";
                    break;
                case 6:
                    Setting();
                    tem = "元件屬性設定完畢";
                    break;
                case 7:
                    tem = "正在掃描LNC訊號...";
                    break;
                case 8:
                    LNC_Scan();
                    tem = "LNC訊號掃描完畢";
                    break;
                //保留20~?測試設備連線
                case 20:
                    tem = "正在測試控制器連線...";
                    break;
                case 25:
                    //long ret = Mitsubishi_Initialization();
                    //if (ret != 0)
                    //{
                    //    tb_Load_log.Text += "控制器連線失敗。 Error Code : " + ret.ToString();
                    //    machine_connect = false;
                    //}
                    //else
                    //    machine_connect = true;
                    break;
                case 26:
                    tem = "控制器連線測試完畢";
                    Load_Step = 80; //因中間已無讀取程式，跳到最後讀取緩衝
                    break;

                //預留最後95~100緩衝讀取
                case 95:
                    tem = "正在將您導入主頁面...";
                    timer_load.Interval = 100;
                    break;
                case 100:
                    tem = "完成";
                    timer_load.Enabled = false;
                    //開啟按鈕功能
                    btn_Thermal.Enabled = true;
                    btn_ToolWear.Enabled = true;
                    btn_ATCsetting.Enabled = true;
                    btn_setting.Enabled = true;
                    btn_Health.Enabled = true;
                    btn_logo.Enabled = true;
                    //預設開啟熱補償介面
                    btn_Thermal_Click(null, null);
                    break;
            }
            if(!string.IsNullOrWhiteSpace(tem)) tb_Loading.Text += tem + "\r\n";
            tb_Load_ProgressRate.Text = "讀取進度 ： " + tem_step + " %";
            Load_Step++;
            is_Load = false;
        }
        #endregion
        #endregion
        #region 按鈕方法
        #region panel設定
        private void btn_Thermal_Click(object sender, EventArgs e){
            panel_Dissable();
            panel_Thermal.Visible = true;
            btn_Thermal_Axial_Click((object)btn_Thermal_01, null);
        }
        //磨耗偵測
        private void btn_ToolWear_Click(object sender, EventArgs e){
            panel_Dissable();
            panel_ToolWear.Visible = true;
            //學習按鈕啟動
            btn_Learn.Enabled = true;
            btn_Learn.BackgroundImage = ToolWear.Properties.Resources.menubtn_learn_default;
            //預設選擇第一個按鈕
            if(pre_ToolWear == null)
                btn_ToolWear_Choose((object)btn_ToolWear_01, null);
            else
                btn_ToolWear_Choose((object)pre_ToolWear, null);
        }
        private void btn_BackHome(object sender, EventArgs e){
            panel_Home.Visible = true;
            panel_Thermal.Visible = false;
            panel_ThermalSetting.Visible = false;
            panel_Compensate.Visible = false;
            panel_ToolWear.Visible = false;
            panel_ToolWearSetting.Visible = false;
            panel_Learn.Visible = false;
            panel_Threshold.Visible = false;
            panel_setting.Visible = false;
        }
        private void btn_ThermalSetting_Back_Click(object sender, EventArgs e){
            panel_ThermalSetting.Visible = false;
            panel_Thermal.Visible = true;
        }
        private void btn_Threshold_Back_Click(object sender, EventArgs e){
            panel_ToolWear.Visible = true;
            panel_Threshold.Visible = false;
            btn_Learn.BackgroundImage = ToolWear.Properties.Resources.menubtn_learn_default;
        }
        //磨耗偵測 > 選擇工件 > 回上一頁
        private void btn_SelectParts_Back_Click(object sender,EventArgs e){
            panel_ToolWear.Visible = true;
            panel_SelectParts.Visible = false;
        }
        //磨耗偵測 > 選擇工件
        private void pb_ToolWear_Click(object sender,EventArgs e){
            panel_ToolWear.Visible = false;
            panel_SelectParts.Visible = true;
            lb_SelectParts_Page.Text = "1";
            SelectParts_LoadData();
        }
        //磨耗偵測 > 選擇工件 > 新增工件
        private void btn_SelectParts_Add_Click(object sender,EventArgs e){
            panel_Dissable();
            panel_AddParts.Visible = true;
        }
        private void btn_ToolWear_Setting_Click(object sender, EventArgs e){
            panel_ToolWearSetting.Visible = true;
            panel_ToolWear.Visible = false;
            if(pre_ToolWearSetting == null)
                btn_ToolWearSetting_Choose((object)btn_ToolWearSetting_01, null);
            else
                btn_ToolWearSetting_Choose((object)pre_ToolWearSetting, null);
        }
        //磨耗設定 > 熱補償設定
        private void btn_ThermalSetting_Click(object sender, EventArgs e){
            panel_ThermalSetting.Visible = true;
            panel_Compensate.Visible = true;
            panel_Thermal.Visible = false;
            if(pre_Compensate == null)
                btn_Compensate_Choose((object)btn_Compensate_01, null);
            else
                btn_Compensate_Choose((object)pre_Compensate, null);
        }
        private void btn_ToolWearSetting_Back_Click(object sender, EventArgs e){
            panel_ToolWearSetting.Visible = false;
            panel_ToolWear.Visible = true;
            btn_ToolWear_Click(null, null);
        }
        private void btn_ToolWearSetting_Learn_Click(object sender, EventArgs e){
            //panel_ToolWearSetting.Visible = false;
            //panel_Learn.Visible = true;
        }
        private void btn_ViewModule_Back_Click(object sender, EventArgs e){
            panel_ToolWearSetting.Visible = true;
            panel_ViewModule.Visible = false;
        }
        //主選單 > 刀庫
        private void btn_ATCsetting_Click(object sender, EventArgs e){
            panel_Dissable();
            panel_ATCsetting.Visible = true;
            btn_ATCSetting_Choose((object)btn_ATCsetting_01, null);
        }
        //主選單 > 設定
        private void btn_setting_Click(object sender, EventArgs e){
            panel_Dissable();
            panel_setting.Visible = true;
        }
        //主選單 > 關機
        private void btn_shutdown_Click(object sender, EventArgs e){
            DialogResult dialogResult = MessageBox.Show("請先確認所有設定皆已儲存，否則將造成新設定遺失。", "關機警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            try{
                //啟動本地程序並執行命令
                Process.Start("Shutdown.exe", " -s -t 0");
            }
            catch (Exception ex){
                MessageBox.Show(ex.Message);
            }
            //this.Close();
        }
        //主選單 > 磨耗偵測 > 學習模式
        private void btn_Learn_Click(object sender, EventArgs e){
            //目前在偵測模式
            if (panel_ToolWear.Visible == true){
                if (lb_ToolWear_Parts.Text.Equals("(未選擇)")){
                    MessageBox.Show("尚未選擇工件，無法切換學習模式。\n請點選右方工件預覽圖或是文字，進入頁面選取此次偵測的工件。", "未選擇工件", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                if (runningTask != null){
                    MessageBox.Show("請先停止所有軸向的磨耗偵測。\n在學習模式中禁止同時偵測磨耗資訊，以免發生不可測意外。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                lb_Learn_WorkName.Text = lb_ToolWear_Parts.Text;
                pb_Learn.BackgroundImage = pb_ToolWear.BackgroundImage;
                panel_Dissable();
                panel_Learn.Visible = true;
                btn_Learn.BackgroundImage = ToolWear.Properties.Resources.wd_l_learn_selected;
                btn_Learn.Enabled = true;
                Button[] btn_Learn_ = new Button[20] { btn_Learn_01, btn_Learn_02, btn_Learn_03,
                            btn_Learn_04,btn_Learn_05,btn_Learn_06,btn_Learn_07,btn_Learn_08,
                            btn_Learn_09,btn_Learn_10,btn_Learn_11,btn_Learn_12,btn_Learn_13,
                            btn_Learn_14,btn_Learn_15,btn_Learn_16,btn_Learn_17,btn_Learn_18,
                            btn_Learn_19,btn_Learn_20};
                //預設選擇現在磨耗偵測選到的軸向
                btn_Learn_Choose((object)btn_Learn_[now_ToolWear], null);
            }
            //目前在學習模式
            else if (panel_Learn.Visible == true){
                panel_Dissable();
                panel_ToolWear.Visible = true;
                btn_Learn.BackgroundImage = ToolWear.Properties.Resources.menubtn_learn_default;
                btn_Learn.Enabled = true;
                Button[] btn_ToolWear = new Button[20] { btn_ToolWear_01, btn_ToolWear_02, btn_ToolWear_03,
                    btn_ToolWear_04,btn_ToolWear_05,btn_ToolWear_06,btn_ToolWear_07,btn_ToolWear_08,
                    btn_ToolWear_09,btn_ToolWear_10,btn_ToolWear_11,btn_ToolWear_12,btn_ToolWear_13,
                    btn_ToolWear_14,btn_ToolWear_15,btn_ToolWear_16,btn_ToolWear_17,btn_ToolWear_18,
                    btn_ToolWear_19,btn_ToolWear_20};
                btn_ToolWear_Choose((object)btn_ToolWear[now_learn], null);
            }
        }
        #endregion
        #region 各項功能按鈕
        #region 磨耗偵測
        //暫存模型資料
        List<string> Module_FFT = new List<string>();
        //開始偵測
        //目前啟動的軸向編號(只能單軸所以只設一個變數)
        int now_Match = 0;
        //磨耗偵測目前只能單軸
        private void btn_ToolWear_Start_Click(object sender, EventArgs e){
            if (lb_ToolWear_Parts.Text.Equals("(未選擇)")){
                MessageBox.Show("尚未選擇工件，無法進行磨耗偵測。\n請點選下方工件預覽圖或是文字，進入頁面選取此次偵測的工件。", "未選擇工件", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            Module_FFT.Clear();
            chart_FFT.Series[0].Points.Clear();
            //檢查data內是否已有此工件的學習模型
            //查詢目錄
            string[] dirs = Directory.GetFiles(path + @"data\FFT\");/*目錄(含路徑)的陣列*/
            List<string> tem_path = new List<string>();
            foreach (string s in dirs){
                //ex L-abc01-1_2500.cp
                string file = Path.GetFileNameWithoutExtension(s).Split('_')[0];
                string remove_rate = file.Split('-')[0] + "-" + file.Split('-')[1];
                if (remove_rate.Equals("L-" + lb_ToolWear_Parts.Text + pre_ToolWear.Name.Split('_')[2]))
                    tem_path.Add(Path.GetFileNameWithoutExtension(s));
            }
            if(tem_path.Count == 0){
                //如果長度為0就是找不到檔案，也就是沒有學習過
                MessageBox.Show("對不起，" + lb_ToolWear_Parts.Text + " 此軸向並未找到學習模型，\n請點選左方功能表「學習模式」進行模型建構。" +
                    "\n\nbtn_ToolWear_Start_Click\n\n","尚未建構模型", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            //判斷輸入裝置然後給予頻率
            double rate = 0, sample = 0;
            if (physicalChannelComboBox.Text.Split('-')[0].Equals("LNC")){
                rate = 1000;
                sample = 100;
            }
            else{
                rate = rateNumeric_base;
                sample = samplesPerChannelNumeric_base;
            }

            StreamReader sr = new StreamReader(path + @"data\FFT\" + tem_path[0] + ".cp");
            while (!sr.EndOfStream)
                Module_FFT.Add(sr.ReadLine());
            sr.Close();
            sr.Dispose();
            double hz = rate / sample;
            for (int i = 0; i < Module_FFT.Count; i++){
                //只畫到2000hz
                if (hz * (i + 1) >= 2000) break;
                chart_FFT.Series[0].Points.AddXY(hz * (i + 1), Module_FFT[i]);
            }
            btn_ToolWear_Start.Enabled = false;
            btn_ToolWear_Stop.Enabled = true;
            chart_ToolWear.Series[0].Points.Clear();
            //修改開始與停止按鈕
            btn_ToolWear_Start.BackgroundImage = ToolWear.Properties.Resources.tc_btn_ply;
            btn_ToolWear_Stop.BackgroundImage = ToolWear.Properties.Resources.btn_stop_selected;
            //修改偵測軸向的文字顏色
            pre_ToolWear.ForeColor = Color.FromArgb(255, 187, 0);
            //修改執行階段
            ToolWear_bool[now_ToolWear] = true;
            now_Match = now_ToolWear;

            //初始化Match檔案
            tem_path.Clear();
            foreach (string s in dirs) { 
                //ex L-abc01-1_2500.cp
                string file = Path.GetFileNameWithoutExtension(s).Split('_')[0];
                string remove_rate = file.Split('-')[0] + "-" + file.Split('-')[1];
                if (remove_rate.Equals("M-" + lb_ToolWear_Parts.Text + pre_ToolWear.Name.Split('_')[2]))
                    tem_path.Add(Path.GetFileNameWithoutExtension(s));
            }
            foreach (string s in tem_path){
                string FileName = path + @"\data\FFT\" + s + ".cp";
                //查詢該刀具的資料檔是否存在
                if (File.Exists(FileName)){
                    StreamWriter sw_FFT = new StreamWriter(FileName);
                    sw_FFT.WriteLine("0");
                    sw_FFT.Close();
                    sw_FFT.Dispose();
                }
            }
            //Log推播訊息
            Write_Log("系統","已啟動磨耗偵測 ： " + lb_ToolWear_Parts.Text + "/" + pre_ToolWear.Text);

            //判斷訊號輸入
            //寶元
            if(physicalChannelComboBox.Text.Split('-')[0].Equals("LNC")){
                LNC_Connect();
                short rc = 0;
                rc = CLNCc.lnc_svi_enable(gNid, 1);
                dt_LNC = new DataTable();
                dt_LNC.Columns.Add("Z");
                FFT_Reset(1000);
                timer_LNC.Enabled = true;
            }
            else DAQInitialize("Match");
        }
        //停止偵測
        private void btn_ToolWear_Stop_Click(object sender, EventArgs e){
            if (runningTask != null) TaskStop();
            if (timer_LNC.Enabled == true){
                timer_LNC.Enabled = false;
                short rc = 0;
                rc =  CLNCc.lnc_svi_enable(gNid, 0);
                rc =  CLNCc.lnc_disconnect(gNid);
            }
            btn_ToolWear_Start.Enabled = true;
            btn_ToolWear_Stop.Enabled = false;
            //修改開始與停止按鈕
            btn_ToolWear_Start.BackgroundImage = ToolWear.Properties.Resources.btn_start_selected;
            btn_ToolWear_Stop.BackgroundImage = ToolWear.Properties.Resources.tc_btn_stop;
            //修改偵測軸向的文字顏色
            pre_ToolWear.ForeColor = Color.White;
            //修改執行階段
            ToolWear_bool[now_ToolWear] = false;
            //Log推播訊息
            Write_Log("系統", "已關閉磨耗偵測 ： " + lb_ToolWear_Parts.Text + "/" + pre_ToolWear.Text);
        }
        //FFT和原始數據折線圖轉換
        private void btn_ToolWear_Change_Click(object sender, EventArgs e){
            if (lb_ToolWear_ChartStatus.Text.Equals("刀具頻率")){
                chart_ToolWear.Visible = true;
                chart_FFT.Visible = false;
                chart_Blade.Visible = false;
                lb_ToolWear_BladeAve.Visible = false;
                lb_ToolWear_ChartStatus.Text = "原始數據";
            }
            else if(lb_ToolWear_ChartStatus.Text.Equals("原始數據")){
                chart_ToolWear.Visible = false;
                chart_FFT.Visible = true;
                chart_Blade.Visible = false;
                lb_ToolWear_BladeAve.Visible = false;
                lb_ToolWear_ChartStatus.Text = "傅立葉數據";
            }
            else if (lb_ToolWear_ChartStatus.Text.Equals("傅立葉數據")){
                chart_ToolWear.Visible = false;
                chart_FFT.Visible = false;
                chart_Blade.Visible = true;
                lb_ToolWear_BladeAve.Visible = true;
                lb_ToolWear_ChartStatus.Text = "刀具頻率";
            }
        }
        //顯示臨界值
        private void btn_ToolWear_Threshold_Click(object sender,EventArgs e){
            if (lb_ToolWear_Parts.Text.Equals("(未選擇)")){
                MessageBox.Show("尚未選擇工件，無法查詢臨界值。\n請點選下方工件預覽圖或是文字，進入頁面選取查詢工件。", "未選擇工件", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            panel_ToolWear.Visible = false;
            panel_Threshold.Visible = true;
            Threshold_Load();
        }
        //磨耗偵測 > 設定 > DAQ訊號重新整理
        private void btn_ToolWearSetting_Research_Click(object sender,EventArgs e){
            DAQPhysicalChannels();
            LNC_Scan();
            btn_ToolWearSetting_Choose(pre_ToolWearSetting, null);
        }
        //暫存此軸向轉速警戒值
        List<string> ToolWear_Alern = new List<string>();
        //警戒圖暫存變數
        int chart_warring_count = 0;    //要將現在的警戒圖形畫到哪一個chart上
        //磨耗偵測 > 判斷是否超出警戒值(顯示Log)
        private void ToolWear_Log(DataTable dt, double sample, double rate){
            string Blade_FileName = "";
            ToolWear_Alern.Clear();
            if (machine_connect == false){
                //如果未連接機台，使用預設2500轉
                try{
                    Blade_FileName = string.Format("{0}{1}-{2}_{3}", lb_ToolWear_Parts.Text, (now_Match + 1).ToString("00"),
                        ATC_num, 2500);
                    StreamReader sr_learn = new StreamReader(string.Format(@"{0}\data\FFT\LS-{1}.cp", path, Blade_FileName));
                    while (!sr_learn.EndOfStream)
                        ToolWear_Alern.Add(sr_learn.ReadLine());
                    sr_learn.Close();
                    sr_learn.Dispose();
                }
                catch(Exception ex) {
                    MessageBox.Show("查詢不到臨界值資料。\n" + ex.ToString(), "查詢失敗", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    return;
                }
                Tool_rate = 2500;
                Tool_Blade = 4;
                //刀具刃數與頻率計算公式
                double Blade_Hz = Tool_rate / 60 * Tool_Blade;
                int Blade_Hz_Mag = 1;   //頻率倍率(取1~5)
                double sum = 0;         //當前儲存點位總和
                int count = 0;          //儲存點位數量
                double Hz_min = 0, Hz_max = 0;  //暫存該頻率倍率中的最大最小值
                double hz = rate / sample;
                List<string> Blade_Module = new List<string>();

                try{
                    StreamReader sr_learn = new StreamReader(string.Format(@"{0}\data\FFT\M-{1}.cp", path, Blade_FileName));
                    while (!sr_learn.EndOfStream)
                        Blade_Module.Add(sr_learn.ReadLine());
                    sr_learn.Close();
                    sr_learn.Dispose();
                }
                catch (Exception ex){
                    MessageBox.Show("讀取Learn檔時發生錯誤。\n\nToolWear_Log\n\n" + ex.ToString(), "讀取錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                Button[] btn_ToolWear = new Button[20] { btn_ToolWear_01, btn_ToolWear_02, btn_ToolWear_03,
                            btn_ToolWear_04,btn_ToolWear_05,btn_ToolWear_06,btn_ToolWear_07,btn_ToolWear_08,
                            btn_ToolWear_09,btn_ToolWear_10,btn_ToolWear_11,btn_ToolWear_12,btn_ToolWear_13,
                            btn_ToolWear_14,btn_ToolWear_15,btn_ToolWear_16,btn_ToolWear_17,btn_ToolWear_18,
                            btn_ToolWear_19,btn_ToolWear_20};
                for (int i = 0; i < Blade_Module.Count; i++){
                    double tem = 0;
                    //上下各取10% range
                    Hz_min = Blade_Hz_Mag * Blade_Hz * 0.9f;
                    Hz_max = Blade_Hz_Mag * Blade_Hz * 1.1f;
                    if ((i + 1) * hz > Hz_min && (i + 1) * hz < Hz_max){
                        tem = double.Parse(Blade_Module[i]);//暫存值
                        if (tem >= 0)
                            sum += tem;
                        count++;
                    }
                    else if ((i + 1) * hz > Hz_max){
                        //頻率已大於刀刃刃數頻率，將倍率提升
                        if (((sum / count) > double.Parse(ToolWear_Alern[Blade_Hz_Mag - 1])) && !ToolWear_Alern[Blade_Hz_Mag - 1].Equals("0")){
                            Write_Log("警告", string.Format("{0}軸 {1}hz~{2}hz 震動幅度超過警戒值，當前:{3}(警戒值:{4})。", btn_ToolWear[now_Match].Text, Hz_min.ToString("0.####"), Hz_max.ToString("0.####"), (sum / count).ToString("0.00##"), ToolWear_Alern[Blade_Hz_Mag - 1]));
                            List<string> tem_datatable = new List<string>();
                            for (int j = 0; j < sample; j++)
                                tem_datatable.Add(dt.Rows[j][0].ToString());
                            System.Windows.Forms.DataVisualization.Charting.Chart[] chart = new System.Windows.Forms.DataVisualization.Charting.Chart[2]
                            {chart_warring_1,chart_warring_2 };
                            Label[] lb_chart = new Label[2] { lb_ToolWear_warring_1, lb_ToolWear_warring_2 };
                            chart[chart_warring_count].Series[0].Points.Clear();
                            for (int j = 0;j < tem_datatable.Count;j++)
                                chart[chart_warring_count].Series[0].Points.AddXY(j+1, tem_datatable[j]);
                            //註記折線圖標題
                            lb_chart[chart_warring_count].Text = DateTime.Now.ToString("yyyy/MM/dd HH:mm:ss");
                            chart_warring_count++;
                            if (chart_warring_count > 1) chart_warring_count = 0;   //兩張圖
                            

                            //存放warring檔案
                            //先檢查有沒有資料夾
                            bool dir_bool = Directory.Exists(path + @"\data\Warring\" + DateTime.Now.ToString("yyyyMMdd"));
                            if(dir_bool == false) Directory.CreateDirectory(path + @"\data\Warring\" + DateTime.Now.ToString("yyyyMMdd"));
                            //寫入新的warring檔
                            StreamWriter sw = new StreamWriter(string.Format(@"{0}\data\Warring\{1}\{2}-{3}",
                                path, DateTime.Now.ToString("yyyyMMdd"), DateTime.Now.ToString("HHmmss"), Blade_FileName));
                            for(int j = 0;j < tem_datatable.Count; j++)
                                sw.WriteLine(tem_datatable[j]);
                            sw.Close();
                            sw.Dispose();
                            
                            //重置當前FFT判斷值
                            StreamWriter sw_match = new StreamWriter(string.Format(@"{0}\data\FFT\M-{1}.cp", path, Blade_FileName));
                            sw_match.WriteLine("-99");
                            sw_match.Close();
                            sw_match.Dispose();
                            List_FFT_Max.Clear();
                            for (int j = 0; j < sample / 2; j++)
                                List_FFT_Max.Add("-99");
                            
                        }
                        if (Blade_Hz_Mag == 1)
                            lb_ToolWear_BladeAve.Text = (sum / count).ToString();
                        Blade_Hz_Mag++;
                        count = 0;
                        sum = 0;
                    }
                    if (Blade_Hz_Mag > 5) break;   //頻率倍率取樣數
                }
            }
            else{
                //如果已連接機台
            }
        }
        #endregion
        #region 學習模式
        //判斷是否正處於學習模式
        bool On_Learn = false;
        //存放現在學習的軸向
        string Learn_Axial = "";
        //模型學習開始
        private void btn_Learn_Start_Click(object sender, EventArgs e){
            DialogResult dialogResult = MessageBox.Show("這將改寫您原先的模型數據，請問要繼續嗎？\n(第一次學習請忽略此訊息)", "警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            btn_Learn_Start.Enabled = false;
            btn_Learn_OK.Enabled = true;
            btn_Learn_Start.BackgroundImage = ToolWear.Properties.Resources.tc_btn_ply;
            btn_Learn_OK.BackgroundImage = ToolWear.Properties.Resources.btn_stop_selected;
            Learn_Axial = int.Parse(pre_learn.Name.Split('_')[2]).ToString("00");
            On_Learn = true;
            StreamWriter sw = new StreamWriter(path + @"\data\module.cp");
            sw.WriteLine();
            sw.Close();
            sw.Dispose();
            //清空原先Match檔案資料
            try{
                //查詢目錄
                string[] dirs = Directory.GetFiles(path + @"data\FFT");/*目錄(含路徑)的陣列*/
                List<string> tem_path = new List<string>();
                foreach (string s in dirs){
                    //ex L-abc01-1_2500.cp
                    string file = Path.GetFileNameWithoutExtension(s).Split('_')[0];
                    string remove_rate = file.Split('-')[0] + "-" + file.Split('-')[1];
                    if (remove_rate.Equals("L-" + lb_Learn_WorkName.Text + (now_learn + 1).ToString("00")))
                        tem_path.Add(Path.GetFileNameWithoutExtension(s));
                    else if (remove_rate.Equals("LS-" + lb_Learn_WorkName.Text + (now_learn + 1).ToString("00")))
                        tem_path.Add(Path.GetFileNameWithoutExtension(s));
                }
                foreach (string s in tem_path) { 
                    string FileName = path + @"\data\FFT\" + s + ".cp";
                    //查詢該刀具的資料檔是否存在
                    if (File.Exists(FileName))
                        File.Delete(FileName);  //刪檔案
                }
            }
            catch (Exception ex){
                MessageBox.Show("在清除原先資料檔時發生錯誤。\n\nbtn_Learn_Start_Click\n\nError code:\n" + ex.ToString());
                return;
            }

            //判斷訊號輸入
            //寶元
            if (physicalChannelComboBox.Text.Split('-')[0].Equals("LNC")){
                LNC_Connect();
                short rc = 0;
                rc = CLNCc.lnc_svi_enable(gNid, 1);
                dt_LNC = new DataTable();
                dt_LNC.Columns.Add("Z");
                FFT_Reset(1000);
                timer_LNC.Enabled = true;
            }
            else DAQInitialize("Learn");
        }
        //模型學習完成
        private void btn_Learn_OK_Click(object sender, EventArgs e){
            if (runningTask != null) TaskStop();
            if (timer_LNC.Enabled == true){
                timer_LNC.Enabled = false;
                CLNCc.lnc_svi_enable(gNid, 0);
                CLNCc.lnc_disconnect(gNid);
            }
            btn_Learn_Start.BackgroundImage = ToolWear.Properties.Resources.btn_start_selected;
            btn_Learn_OK.BackgroundImage = ToolWear.Properties.Resources.tc_btn_stop;
            btn_Learn_Start.Enabled = true;
            btn_Learn_OK.Enabled = false;
            panel_Threshold.Visible = true;
            panel_Learn.Visible = false;
            On_Learn = false;
            chart_Learn.Series[0].Points.Clear();
            //讀取臨界值
            Threshold_Load();
        }
        //模型學習取消
        private void btn_Learn_Cancel_Click(object sender, EventArgs e){
            if (runningTask != null) TaskStop();
            btn_Learn_Start.Enabled = true;
            btn_Learn_OK.Enabled = false;
            panel_ToolWear.Visible = true;
            panel_Learn.Visible = false;
            btn_Learn.Enabled = true;
            btn_Learn.BackgroundImage = ToolWear.Properties.Resources.menubtn_learn_default;
        }
        #endregion
        #region 臨界值設定
        //臨界值設定 > 讀取資料
        private void Threshold_Load(){
            List<string> Blade_Name = new List<string>();
            Blade_Name.Add("預設");
            try{
                StreamReader sr = new StreamReader(path + @"\data\ATC.cp");
                while(!sr.EndOfStream)
                    Blade_Name.Add(sr.ReadLine().Split(',')[1]);
                sr.Close();
                sr.Dispose();
            }
            catch (Exception ex){
                MessageBox.Show("在讀取刀庫資料時發生錯誤。\n\nThreshold_Load\n\nError code:\n" + ex.ToString());
            }
            TextBox[] tb_Threshold = new TextBox[14] { tb_Threshold_01 , tb_Threshold_02 , tb_Threshold_03 , tb_Threshold_04 ,
                                             tb_Threshold_05,tb_Threshold_06,tb_Threshold_07,tb_Threshold_08,tb_Threshold_09,
                                             tb_Threshold_10,tb_Threshold_11,tb_Threshold_12,tb_Threshold_13,tb_Threshold_14};
            //清空TextBox資料
            for (int i = 0; i < tb_Threshold.Length; i++) tb_Threshold[i].Text = "";
            //存放現在寫到哪個TextBox了
            int tb_count = 0;
            try{
                //查詢目錄
                string[] dirs = Directory.GetFiles(path + @"data\FFT");/*目錄(含路徑)的陣列*/
                List<string> tem_path = new List<string>();
                foreach (string s in dirs){
                    //ex L-abc01-1_2500-set.cp
                    string file = Path.GetFileNameWithoutExtension(s).Split('_')[0];
                    string remove_rate = file.Split('-')[0] + "-" + file.Split('-')[1];
                    if (remove_rate.Equals("L-" + lb_ToolWear_Parts.Text + pre_ToolWear.Name.Split('_')[2]))
                        tem_path.Add(Path.GetFileNameWithoutExtension(s));
                }
                foreach (string s in tem_path){
                    string FileName = path + @"\data\FFT\" + s + ".cp";
                    string Blade = s.Split('-')[2].Split('_')[0];
                    //查詢該刀具的資料檔是否存在
                    if (File.Exists(FileName)){
                        tb_Threshold[tb_count].Text = "T" + Blade + " : " + Blade_Name[int.Parse(Blade)] + " " + s.Split('_')[1];
                        tb_count++;
                    }
                }
                //表示沒有資料
                if (tb_count == 0){
                    tb_Threshold[0].Text = "沒有學習資料";
                    tb_Threshold[1].Text = "無法設定臨界值";
                }
            }
            catch (Exception ex){
                MessageBox.Show("在讀取比對資料檔時發生錯誤。\n\nThreshold_Load\n\nError code:\n" + ex.ToString());
            }
            Threshold_LoadBlade((object)tb_Threshold_01, null);
        }
        //暫存點選的刀號檔案名稱
        string Blade_FileName = "";
        //轉速
        int Tool_rate = 0;
        //刃數
        int Tool_Blade = 4;
        //暫存上次點選到的刀號TextBox
        TextBox pre_Blade = null;
        //臨界值設定 > 點選不同刀號
        private void Threshold_LoadBlade(object sender,EventArgs e){
            pre_Blade = (TextBox)sender;
            if (pre_Blade.Text.Equals("")) return;
            //判斷裝置給予頻率
            double rate = 0, sample = 0;
            if (physicalChannelComboBox.Text.Split('-')[0].Equals("LNC")){
                rate = 1000;
                sample = 100;
            }
            else{
                rate = rateNumeric_base;
                sample = samplesPerChannelNumeric_base;
            }
            double hz = rate / sample;
            List<string> Blade_Module = new List<string>();
            try{
                Blade_FileName = string.Format("{0}{1}-{2}_{3}",lb_ToolWear_Parts.Text, pre_ToolWear.Name.Split('_')[2],
                    pre_Blade.Text.Split(' ')[0].Split('T')[1], pre_Blade.Text.Split(' ')[3].Split(' ')[0]);
                StreamReader sr_learn = new StreamReader(string.Format(@"{0}\data\FFT\L-{1}.cp", path, Blade_FileName));
                while (!sr_learn.EndOfStream)
                    Blade_Module.Add(sr_learn.ReadLine());
                sr_learn.Close();
                sr_learn.Dispose();
            }
            catch (Exception ex){
                MessageBox.Show("讀取Learn檔時發生錯誤。\n\nThreshold_LoadBlade\n\n" + ex.ToString(), "讀取錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            chart_Threshold.Series[0].Points.Clear();
            //T0 : abc 5000
            //取得轉速
            Tool_rate = int.Parse(pre_Blade.Text.Split(' ')[3].Split(' ')[0]);
            lb_Threshold_rate.Text = string.Format("轉速 : {0} RPM", Tool_rate);
            lb_Threshold_ATC.Text = string.Format("刀具 ： {0}", pre_Blade.Text.Split(' ')[2].Split(' ')[0]);
            StreamReader sr = new StreamReader(path + @"data\ATC.cp");
            string s = pre_Blade.Text.Split(' ')[0].Split('T')[1];
            //取得刃數
            Tool_Blade = 4;
            for (int i = 0; i < int.Parse(pre_Blade.Text.Split(' ')[0].Split('T')[1]); i++){
                Tool_Blade = int.Parse(sr.ReadLine().Split(',')[2]);
                lb_Threshold_Blade.Text = string.Format("刃數 ： {0}", Tool_Blade);
            }
            sr.Close();
            sr.Dispose();
            //for (int i = 0; i < Blade_Module.Count; i++)
            //    chart_Threshold.Series[0].Points.AddXY((i + 1) * hz, Blade_Module[i]);
            //讀取該頻段刀子設定檔
            TextBox[] tb_Threshold_set = new TextBox[5] { tb_Threshold_set01, tb_Threshold_set02, tb_Threshold_set03,
                                                          tb_Threshold_set04, tb_Threshold_set05};
            try{
                StreamReader sr_set = new StreamReader(string.Format(@"{0}data\FFT\LS-{1}.cp", path, Blade_FileName));
                int sr_count = 0;
                while (!sr_set.EndOfStream){
                    tb_Threshold_set[sr_count].Text = sr_set.ReadLine();
                    sr_count++;
                }
                sr_set.Close();
                sr_set.Dispose();
            }
            catch{
                //會進到例外事件表示沒有設定檔，生成一個
                StreamWriter sw_set = new StreamWriter(string.Format(@"{0}data\FFT\LS-{1}.cp", path, Blade_FileName));
                for (int i = 1; i <= 5; i++)
                    sw_set.WriteLine("0");
                sw_set.Close();
                sw_set.Dispose();
                //重新讀取
                Threshold_LoadBlade((object)pre_Blade, null);
                return;
            }

            //刀具刃數與頻率計算公式
            double Blade_Hz = Tool_rate / 60 * Tool_Blade;
            int Blade_Hz_Mag = 1;   //頻率倍率(取1~5)
            double sum = 0;         //當前儲存點位總和
            int count = 0;          //儲存點位數量
            double Hz_min = 0, Hz_max = 0;  //暫存該頻率倍率中的最大最小值
            Label[] lb_Threshold_sethz = new Label[5] { lb_Threshold_sethz01 , lb_Threshold_sethz02 , lb_Threshold_sethz03 ,
                                                      lb_Threshold_sethz04 , lb_Threshold_sethz05};
            Label[] lb_Threshold_setavg = new Label[5] { lb_Threshold_setavg01 , lb_Threshold_setavg02 , lb_Threshold_setavg03 ,
                                                      lb_Threshold_setavg04 , lb_Threshold_setavg05};
            for(int i = 0; i < lb_Threshold_sethz.Length; i++){
                lb_Threshold_sethz[i].Text = "";
                lb_Threshold_setavg[i].Text = "";
            }
            for (int i = 0; i < Blade_Module.Count; i++){
                double tem = 0;
                //上下各取10% range
                Hz_min = Blade_Hz_Mag * Blade_Hz * 0.9f;
                Hz_max = Blade_Hz_Mag * Blade_Hz * 1.1f;
                chart_Threshold.Series[Blade_Hz_Mag + 1].Points.Clear();
                chart_Threshold.Series[Blade_Hz_Mag + 1].Points.AddXY(Hz_min * 0.9f, tb_Threshold_set[Blade_Hz_Mag - 1].Text);
                chart_Threshold.Series[Blade_Hz_Mag + 1].Points.AddXY(Hz_max * 1.1f, tb_Threshold_set[Blade_Hz_Mag - 1].Text);
                if ((i + 1) * hz > Hz_min && (i + 1) * hz < Hz_max){
                    tem = double.Parse(Blade_Module[i]);//暫存值
                    if (tem >= 0)
                        sum += tem;
                    count++;
                }
                else if ((i + 1) * hz > Hz_max){
                    //先顯示數據在Lable上
                    lb_Threshold_sethz[Blade_Hz_Mag - 1].Text = string.Format("{0} hz ~ {1} hz", Hz_min.ToString("#0"), Hz_max.ToString("#0"));
                    lb_Threshold_setavg[Blade_Hz_Mag - 1].Text = string.Format("| {0}", (sum / count).ToString("0.0000"));

                    //頻率已大於刀刃刃數頻率，將倍率提升
                    Blade_Hz_Mag++;
                    count = 0;
                    sum = 0;
                }
                chart_Threshold.Series[0].Points.AddXY((i + 1) * hz, tem);
                if (Blade_Hz_Mag > 5) break;   //頻率倍率取樣數
            }
        }
        //臨界值設定 > 儲存
        private void btn_Threshold_save_Click(object sender,EventArgs e){
            TextBox[] tb_Threshold_set = new TextBox[5] { tb_Threshold_set01, tb_Threshold_set02, tb_Threshold_set03,
                                                          tb_Threshold_set04, tb_Threshold_set05};
            //先判斷輸入框是否合法
            for(int i = 0; i < tb_Threshold_set.Length; i++){
                if (string.IsNullOrWhiteSpace(tb_Threshold_set[i].Text)){
                    MessageBox.Show("有一個臨界值設定為空，請重新確認後再儲存。","儲存失敗",MessageBoxButtons.OK,MessageBoxIcon.Warning);
                    return;
                }
                try{
                    double tem = double.Parse(tb_Threshold_set[i].Text);
                }
                catch {
                    MessageBox.Show(string.Format("{0}\n輸入框文字訊息不合法，請確認是否為數字。", tb_Threshold_set[i].Text), "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
            }
            //改寫設定檔
            try{
                StreamWriter sw_set = new StreamWriter(string.Format(@"{0}data\FFT\LS-{1}.cp", path, Blade_FileName));
                for(int i = 0; i < 5; i++)
                    sw_set.WriteLine(tb_Threshold_set[i].Text);
                sw_set.Close();
                sw_set.Dispose();
            }
            catch(Exception ex) {
                MessageBox.Show(string.Format("改寫設定檔時發生錯誤。\nError code:\n{0}", ex.ToString()), "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            MessageBox.Show("儲存完畢", "儲存成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
            Threshold_LoadBlade((object)pre_Blade, null);
        }
        //臨界值設定 > 刪除
        private void btn_Threshold_delete_Click(object sender,EventArgs e){
            DialogResult dialogResult = MessageBox.Show("確定要清除臨界值資料嗎？", "刪除警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            TextBox[] tb_Threshold_set = new TextBox[5] { tb_Threshold_set01, tb_Threshold_set02, tb_Threshold_set03,
                                                          tb_Threshold_set04, tb_Threshold_set05};
            try{
                StreamWriter sw_set = new StreamWriter(string.Format(@"{0}data\FFT\LS-{1}.cp", path, Blade_FileName));
                for (int i = 0; i < 5; i++)
                    sw_set.WriteLine("0");
                sw_set.Close();
                sw_set.Dispose();
            }
            catch (Exception ex){
                MessageBox.Show(string.Format("改寫設定檔時發生錯誤。\nError code:\n{0}", ex.ToString()), "刪除失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            Threshold_LoadBlade((object)pre_Blade, null);
            MessageBox.Show("清除完畢。", "刪除成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }
        #endregion
        #region 主畫面設定
        //主畫面 > 設定 > 重新連線
        private void btn_setting_Reconnection_Click(object sender,EventArgs e){
            lb_setting_Reconnection.Text = "正在準備重新連接控制器，這可能需要花費一段時間。";
            lb_setting_Reconnection.ForeColor = Color.White;
            Thread TD_Reconnection = new Thread(setting_Reconnection_Thread);
            TD_Reconnection.Start();
        }
        //主畫面 > 設定 > 重新連線執行緒
        delegate void SettingReconnectionDelegate();
        private void setting_Reconnection_Thread(){
            if (this.InvokeRequired){
                SettingReconnectionDelegate SLD = new SettingReconnectionDelegate(setting_Reconnection_Thread);
                this.Invoke(SLD);
            }
            else{
                long ret = Mitsubishi_Initialization();
                if (ret != 0){
                    lb_setting_Reconnection.Text = "控制器連線失敗。\n請確定控制器廠牌與IP設定無誤，並確認實體線路是否通暢。\n Error Code : " + ret.ToString();
                    lb_setting_Reconnection.ForeColor = Color.Red;
                    machine_connect = false;
                }
                else{
                    lb_setting_Reconnection.Text = "已取得連線資訊，位於 " + tb_setting_ip.Text + "。";
                    machine_connect = true;
                    StreamWriter sw = new StreamWriter(path + @"\data\setting.cp");
                    sw.WriteLine(string.Format("{0},{1},{2}", cb_setting_brand.Text, cb_setting_model.Text, tb_setting_ip.Text));
                    sw.Close();
                    sw.Dispose();
                }
            }  
        }
        //主畫面 > 設定 > 存檔
        private void btn_setting_save_Click(object sender, EventArgs e){
            DialogResult dialogResult = MessageBox.Show("請先確認所選控制器廠牌與型號及IP是否正確。", "存檔", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;
            StreamWriter sw = new StreamWriter(path + @"\data\setting.cp");
            sw.WriteLine(string.Format("{0},{1},{2}", cb_setting_brand.Text, cb_setting_model.Text, tb_setting_ip.Text));
            sw.Close();
            sw.Dispose();
        }
        //主畫面 > 設定 > 刪除
        private void btn_setting_delete_Click(object sender,EventArgs e){
            DialogResult dialogResult = MessageBox.Show("確定要清除設定檔內資料嗎？", "刪除", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            StreamWriter sw = new StreamWriter(path + @"\data\setting.cp");
            sw.WriteLine("brand,model,192.168.1.1");
            sw.Close();
            sw.Dispose();
            //重新讀取
            setting_load(true);
        }
        /// <summary>
        /// 主畫面 > 設定 > 重新讀取設定檔
        /// </summary>
        /// <param name="OnRemove">是否在移除模式下</param>
        private void setting_load(bool OnRemove){
            //主畫面 > 設定
            StreamReader sr_setting = new StreamReader(path + @"\data\setting.cp");
            string set = sr_setting.ReadLine();
            //搜尋廠牌
            for (int i = 0; i < cb_setting_brand.Items.Count; i++){
                cb_setting_brand.SelectedIndex = i;
                if (cb_setting_brand.Text.Equals(set.Split(',')[0])) break;
                //當搜尋到最後一筆廠牌資料都沒有搜尋到時(因為如果有搜尋到就已經break了)
                if (i == cb_setting_brand.Items.Count - 1){
                    cb_setting_brand.SelectedIndex = 0;
                    if(OnRemove == false)
                        MessageBox.Show("設定檔錯誤。\n查無廠牌！\n請確認設定檔資料是否正確，或是前往設定頁面重新選擇資料並儲存。", "設定檔錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            //搜尋型號
            for (int i = 0; i < cb_setting_model.Items.Count; i++){
                cb_setting_model.SelectedIndex = i;
                if (cb_setting_model.Text.Equals(set.Split(',')[1])) break;
                //當搜尋到最後一筆廠牌資料都沒有搜尋到時(因為如果有搜尋到就已經break了)
                if (i == cb_setting_model.Items.Count - 1){
                    cb_setting_model.SelectedIndex = 0;
                    if (OnRemove == false)
                        MessageBox.Show("設定檔錯誤。\n查無型號！\n請確認設定檔資料是否正確，或是前往設定頁面重新選擇資料並儲存。", "設定檔錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            //讀取設定檔ip
            tb_setting_ip.Text = set.Split(',')[2];
            sr_setting.Close();
            sr_setting.Dispose();
        }
        #endregion
        #region 模型預覽
        //模型預覽
        private void btn_ToolWearSetting_ViewModule_Click(object sender, EventArgs e){
            panel_ToolWearSetting.Visible = false;
            panel_ViewModule.Visible = true;
            chart_ViewModule.Legends.Clear();
            chart_ViewModule.Series[0].Points.Clear();
            chart_ViewModule.Series[1].Points.AddXY(1, 1);
            chart_ViewModule.Series[2].Points.AddXY(1, -1);
            #region 讀取樣本原始資料
            StreamReader sr = new StreamReader(path + @"\data\module.cp");
            int count = 1;
            //double per_number = 0f;
            //bool Cutting_bool = false;
            while (!sr.EndOfStream){
                string tem_read = sr.ReadLine();
                count++;
                if (string.IsNullOrWhiteSpace(tem_read)) continue;
                if (count % rateNumeric_base == 0)
                    chart_ViewModule.Series[0].Points.AddXY((double)count / rateNumeric_base, tem_read);

                #region 偵測切削進入點
                //偵測切削進入點
                //if (Cutting_bool == false)
                //{
                //    if ((Math.Abs(tem_read_double) - Math.Abs(per_number)) > 1)
                //        Cutting_bool = true;
                //    per_number = tem_read_double;
                //    if (Cutting_bool != true) continue;
                //}
                #endregion
            }
            sr.Close();
            sr.Dispose();
            #endregion
            //讀取FFT最大值
            #region 讀取FFT上限
            chart_ViewFFT.Legends.Clear();
            for (int i = 0; i < chart_ViewFFT.Series.Count; i++)
                chart_ViewFFT.Series[i].Points.Clear();
            double hz = rateNumeric_base / samplesPerChannelNumeric_base;
            string[] file_name = new string[] {"FFT_Max(new-1)", "FFT_Max(new-2)", "FFT_Max(new-3)", "FFT_Max(new-4)", "FFT_Max(new-5)",
                "FFT_Max(crash-1)","FFT_Max(crash-2)","FFT_Max(crash-3)","FFT_Max(crash-4)","FFT_Max(crash-5)" };
            for(int i = 0; i < file_name.Length; i++){
                StreamReader sr_FFTmax = new StreamReader(path + @"\data\" + file_name[i] + ".cp");
                int FFT_count = 1;
                while (!sr_FFTmax.EndOfStream){
                    chart_ViewFFT.Series[i].Points.AddXY(FFT_count * hz, sr_FFTmax.ReadLine());
                    FFT_count++;
                }
                sr_FFTmax.Close();
                sr_FFTmax.Dispose();
            }
            #endregion
        }
        //重置縮放
        private void btn_ViewModule_ChartReset_Click(object sender, EventArgs e){
            //chart_Blade.ChartAreas[0].AxisX.ScaleView.ZoomReset(0);
            chart_ViewModule.ChartAreas[0].AxisX.ScaleView.ZoomReset(0);
            chart_ViewFFT.ChartAreas[0].AxisX.ScaleView.ZoomReset(0);
            chart_ViewFFT.ChartAreas[0].AxisY.ScaleView.ZoomReset(0);
        }
        //波形圖切換
        private void btn_ViewChartChange_Click(object sender, EventArgs e){
            if(chart_ViewModule.Visible == true){
                chart_ViewFFT.Visible = true;
                chart_ViewModule.Visible = false;
                //chart_Blade.Visible = false;
            }
            else
            {
                chart_ViewFFT.Visible = false;
                chart_ViewModule.Visible = true;
                //chart_Blade.Visible = false;
            }
        }
        #endregion
        #region 刃數比對
        //刃數比對
        private void Blade_Comparison(double sample, double rate){
            double hz = rate / sample;
            //讀取Module的暫存FFT變數 ： Module_FFT
            List<string> Blade_Module = Module_FFT;
            List<string> Blade_Match = new List<string>();
            try{
                StreamReader sr_match = new StreamReader(path + @"\data\FFT\M-" + lb_ToolWear_Parts.Text + (now_Match + 1).ToString("00") + "-" + ATC_Status + "_" + (int)ATC_RPM + ".cp");
                while (!sr_match.EndOfStream)
                    Blade_Match.Add(sr_match.ReadLine());
                sr_match.Close();
                sr_match.Dispose();
            }
            catch(Exception ex) {
                MessageBox.Show("讀取Match檔時發生錯誤。\n\nBlade_Comparison\n\n" + ex.ToString(),"讀取錯誤",MessageBoxButtons.OK,MessageBoxIcon.Error);
                return;
            }
            chart_Blade.Series[0].Points.Clear();
            //取得主軸轉數
            int Tool_rate = 0;
            if (machine_connect == false) Tool_rate = 2500; //如果主軸轉數為0則使用預設轉數
            else Tool_rate = int.Parse(lb_ToolWear_FeedSpeed.Text.Split(' ')[0]);
            //取得刀具刃數
            StreamReader sr_ATC = new StreamReader(path + @"\data\ATC.cp");
            int Tool_Blade = 0;     //刀具刃數
            for (int i = 0; i <= now_Match; i++){
                //讀取範例 1,test,4
                //編號,名稱,刃數
                string tem = sr_ATC.ReadLine();
                if (i != now_Match) continue;
                try {
                    Tool_Blade = int.Parse(tem.Split(',')[2]);
                }
                catch {
                    //如果進到例外表示該刀具的刃數沒有設定，那就使用預設值
                    Tool_Blade = 4;
                }
            }
            //刀具刃數與頻率計算公式
            double Blade_Hz = Tool_rate / 60 * Tool_Blade;  
            int Blade_Hz_Mag = 1;   //頻率倍率(取1~5)
            double sum = 0;         //當前儲存點位總和
            int count = 0;          //儲存點位數量
            double Hz_min = 0, Hz_max = 0;  //暫存該頻率倍率中的最大最小值
            for (int i = 0; i < Blade_Match.Count; i++){
                double tem = 0;
                //上下各取10% range
                Hz_min = Blade_Hz_Mag * Blade_Hz * 0.9f;
                Hz_max = Blade_Hz_Mag * Blade_Hz * 1.1f;
                if ((i + 1) * hz > Hz_min && (i + 1) * hz < Hz_max){
                    tem = double.Parse(Blade_Match[i]) - double.Parse(Blade_Module[i]); //暫存相差值
                    if (tem >= 0){
                        sum += tem;
                        count++;
                    }
                }
                else if ((i + 1) * hz > Hz_max){
                    Blade_Hz_Mag++; //若頻率已大於刀刃刃數頻率，將倍率提升
                }
                //只顯示正數
                if(tem > 0)
                    chart_Blade.Series[0].Points.AddXY((i + 1) * hz, tem);
                else
                    chart_Blade.Series[0].Points.AddXY((i + 1) * hz, 0);
                if (Blade_Hz_Mag > 5) break;   //頻率倍率取樣數
            }
        }
        #endregion
        #region 熱補償
        //現在選擇的熱補償軸向代號
        int now_Thermal = 0;
        //暫存剛剛點選的熱補償軸向按鈕
        Button pre_Thermal = null;
        //幾個軸向正在運行
        int Thermal_single = 0;
        //是否正在選取尚未執行的軸向
        bool Thermal_SelectAnother = false;
        //熱補償 > 按下軸向按鈕
        private void btn_Thermal_Axial_Click(object sender, EventArgs e) {
            //先重置上次選到的按鈕
            if (pre_Thermal != null){
                pre_Thermal.BackgroundImage = ToolWear.Properties.Resources.tc_btn_axiabtn;
            }
            pre_Thermal = (Button)sender;
            pre_Thermal.BackgroundImage = ToolWear.Properties.Resources.tc_btn_axiabtn_selected;
            now_Thermal = int.Parse(((Button)sender).Name.Split('_')[2]) - 1;
            //判斷目前的軸向是否正在偵測
            if(((Button)sender).ForeColor != Color.White){
                btn_Thermal_start.Enabled = false;
                btn_Thermal_stop.Enabled = true;
                btn_Thermal_start.BackgroundImage = ToolWear.Properties.Resources.tc_btn_ply;
                btn_Thermal_stop.BackgroundImage = ToolWear.Properties.Resources.btn_stop_selected;
                btn_Thermal_stop.Focus();
            }
            else{
                btn_Thermal_start.Enabled = true;
                btn_Thermal_stop.Enabled = false;
                btn_Thermal_start.BackgroundImage = ToolWear.Properties.Resources.btn_start_selected;
                btn_Thermal_stop.BackgroundImage = ToolWear.Properties.Resources.tc_btn_stop;
                btn_Thermal_start.Focus();
            }
            //判斷是否有其他軸向正在啟動
            if(Thermal_single > 0 && Thermal_bool[now_Thermal] != true){
                //表示有其他軸向正在啟動，且不是目前選到的這一軸(代表這是第2個或以上選取的軸向)
                panel_Thermal_single.Visible = false;
                panel_Thermal_Mutile.Visible = true;
                Thermal_SelectAnother = true;
                //如果是點同一個按鈕才清空
                if (lb_Thermal_M2_Now.Text.Equals(pre_Thermal.Text)){
                    chart_Thermal_M2.Series[0].Points.Clear();
                    chart_Thermal_M2.Series[1].Points.Clear();
                    for (int i = 1; i <= 30; i++)
                        chart_Thermal_M2.Series[1].Points.AddXY(i, 25);
                }
            }
            else if(Thermal_single > 1){
                panel_Thermal_single.Visible = false;
                panel_Thermal_Mutile.Visible = true;
                Thermal_SelectAnother = false;
            }
            else{
                panel_Thermal_single.Visible = true;
                panel_Thermal_Mutile.Visible = false;
                Thermal_SelectAnother = false;
                if(Thermal_single == 0){
                    chart_Thermal.Series[0].Points.Clear();
                    chart_Thermal.Series[1].Points.Clear();
                    chart_Thermal_M1.Series[0].Points.Clear();
                    chart_Thermal_M1.Series[1].Points.Clear();
                    for (int i = 1; i <= 30; i++){
                        chart_Thermal.Series[1].Points.AddXY(i, 25);
                        chart_Thermal_M1.Series[1].Points.AddXY(i, 25);
                    }
                }
            }
            //更改折線圖顯示名稱
            if(Thermal_single == 0) lb_Thermal_Now.Text = pre_Thermal.Text;
            else if(Thermal_single % 2 == 1) lb_Thermal_M2_Now.Text = pre_Thermal.Text;
        }
        //熱補償 > 取得此軸向的補償資料(待)
        private void Thermal_GetCompensate(int axial){
            //取得該軸向的次序
            //StreamReader sr_get = new StreamReader(path + @"\data\compensate.cp");
            //List<string> tem_read = new List<string>();
            //while (!sr_get.EndOfStream){
            //    string tem = sr_get.ReadLine();
            //    if (tem.Split(',')[0].Equals(now_Thermal.ToString()))
            //        tem_read.Add(tem);
            //}
        }
        //熱補償 > 開始
        private void btn_Thermal_start_Click(object sender, EventArgs e){
            string axial = "";  //軸向
            string ip = "";     //此軸向ip
            string channel = "";
            //先檢查此軸向設定檔是否完整
            StreamReader sr_set = new StreamReader(path + @"\data\thermal.cp");
            try{
                for (int i = 0; i <= now_Thermal; i++){
                    string tem = sr_set.ReadLine();
                    if (i == now_Thermal){
                        axial = tem.Split(',')[0];
                        ip = tem.Split(',')[1];
                        channel = tem.Split(',')[2];
                    }
                }
            }
            catch(Exception ex){
                MessageBox.Show("此軸向設定檔不完全，請至設定頁面重新設定。\n\nbtn_Thermal_start_Click\n\n" + ex.ToString(), "設定檔錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
                sr_set.Close();
                sr_set.Dispose();
                return;
            }
            sr_set.Close();
            sr_set.Dispose();

            //取得熱補償資料
            Thermal_GetCompensate(now_Thermal);

            //開始偵測
            pre_Thermal.ForeColor = Color.FromArgb(255, 187, 0);
            btn_Thermal_start.Enabled = false;
            btn_Thermal_stop.Enabled = true;
            btn_Thermal_start.BackgroundImage = ToolWear.Properties.Resources.tc_btn_ply;
            btn_Thermal_stop.BackgroundImage = ToolWear.Properties.Resources.btn_stop_selected;
            if(Thermal_single == 0) lb_Thermal_Now.Text = pre_Thermal.Text;

            //清除原先折線圖資訊
            if (Thermal_single == 0){
                chart_Thermal.Series[0].Points.Clear();
                chart_Thermal.Series[1].Points.Clear();
                chart_Thermal_M1.Series[0].Points.Clear();
                chart_Thermal_M1.Series[1].Points.Clear();
                for (int i = 1; i <= 30; i++)
                {
                    chart_Thermal.Series[1].Points.AddXY(i, 25);
                    chart_Thermal_M1.Series[1].Points.AddXY(i, 25);
                }
            }
            else if (Thermal_single == 1){ 
                chart_Thermal_M2.Series[0].Points.Clear();
                chart_Thermal_M2.Series[1].Points.Clear();
                for (int i = 1; i <= 30; i++)
                {
                    chart_Thermal_M2.Series[1].Points.AddXY(i, 25);
                }
            }

            //重置初始資料
            Thermal_count[now_Thermal] = 0;

            //清除原先暫存溫度DATA資料
            StreamWriter sw_axial = new StreamWriter(path + @"\data\Temperature\Axial" + now_Thermal.ToString("00") + ".cp");
            sw_axial.Write("");
            sw_axial.Close();
            sw_axial.Dispose();

            //假資料
            Thermal_bool[now_Thermal] = true;
            timer_temperature.Enabled = true;

            //軸向啟動
            Thermal_single++;

            //Log推播
            Write_Log("系統", "已啟動熱補償偵測 ： " + pre_Thermal.Text + " 軸。");

            //重新設定頁數為最後一頁
            lb_Thermal_page.Text = (((Thermal_single - 1) / 2) + 1).ToString();
            
            //清除第二個折線圖標題因更改頁數而異常出現的問題
            if (Thermal_single % 2 == 1)
                lb_Thermal_M2_Now.Text = "";
        }
        //熱補償 > 停止
        private void btn_Thermal_stop_Click(object sender, EventArgs e){
            pre_Thermal.ForeColor = Color.White;
            btn_Thermal_start.Enabled = true;
            btn_Thermal_stop.Enabled = false;
            btn_Thermal_start.BackgroundImage = ToolWear.Properties.Resources.btn_start_selected;
            btn_Thermal_stop.BackgroundImage = ToolWear.Properties.Resources.tc_btn_stop;
            Thermal_bool[now_Thermal] = false;
            Thermal_single--;
            //當都已經沒有任何軸向在啟動的時候
            if(Thermal_single == 0)
                timer_temperature.Enabled = false;
            else if(Thermal_single > 0)
                Thermal_SelectAnother = true;
            //Log推播
            Write_Log("系統", "已關閉熱補償偵測 ： " + pre_Thermal.Text + " 軸。");
            //重新設定頁數為最後一頁
            lb_Thermal_page.Text = (((Thermal_single - 1) / 2) + 1).ToString();
            //重新整理頁面
            btn_Thermal_Axial_Click((object)pre_Thermal, null);
        }
        //熱補償 > 折線圖上一頁
        private void btn_Thermal_up_Click(object sender,EventArgs e){
            if (lb_Thermal_page.Text.Equals("1")){
                MessageBox.Show("頁面切換失敗，已經在第一頁。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            else{
                lb_Thermal_page.Text = (int.Parse(lb_Thermal_page.Text) - 1).ToString();
                Thread TD_ChartData = new Thread(Thermal_ChartData);
                TD_ChartData.Start();
            }
        }
        //熱補償 > 折線圖下一頁
        private void btn_Thermal_down_Click(object sender,EventArgs e){
            if(Thermal_single > int.Parse(lb_Thermal_page.Text) * 2){
                lb_Thermal_page.Text = (int.Parse(lb_Thermal_page.Text) + 1).ToString();
                Thread TD_ChartData = new Thread(Thermal_ChartData);
                TD_ChartData.Start();
            }
            else{
                MessageBox.Show("沒有更多的偵測圖，已在最後一頁。","操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
        }
        //熱補償 > 顯示折線圖
        delegate void ChartDataDelegate();
        private void Thermal_ChartData(){
            if (this.InvokeRequired){
                ChartDataDelegate CDD = new ChartDataDelegate(Thermal_ChartData);
                this.Invoke(CDD);
            }
            else{
                //暫存畫了幾張圖
                int chart_count = 0;
                //暫存當前頁數
                int int_page = int.Parse(lb_Thermal_page.Text);
                System.Windows.Forms.DataVisualization.Charting.Chart[] chart = new System.Windows.Forms.DataVisualization.Charting.Chart[2]
                { chart_Thermal_M1,chart_Thermal_M2};
                Label[] chart_Title = new Label[2] { lb_Thermal_M1_Now, lb_Thermal_M2_Now };
                Button[] btn_Thermal = new Button[20] { btn_Thermal_01, btn_Thermal_02, btn_Thermal_03,
                                       btn_Thermal_04,btn_Thermal_05,btn_Thermal_06,btn_Thermal_07,btn_Thermal_08,
                                       btn_Thermal_09,btn_Thermal_10,btn_Thermal_11,btn_Thermal_12,btn_Thermal_13,
                                       btn_Thermal_14,btn_Thermal_15,btn_Thermal_16,btn_Thermal_17,btn_Thermal_18,
                                       btn_Thermal_19,btn_Thermal_20};
                for (int i = 0; i < 20; i++){
                    if (Thermal_bool[i] == false) continue;
                    if(chart_count < (int_page - 1) * 2 ){
                        chart_count++;
                        continue;
                    }
                    List<string> tem_read = new List<string>();
                    try{
                        StreamReader sr_axial = new StreamReader(path + @"\data\Temperature\Axial" + i.ToString("00") + ".cp");
                        while (!sr_axial.EndOfStream) tem_read.Add(sr_axial.ReadLine());
                        sr_axial.Close();
                        sr_axial.Dispose();
                    }
                    catch {}
                    chart[chart_count % 2].Series[0].Points.Clear();
                    chart[chart_count % 2].Series[1].Points.Clear();
                    //清除換頁時第二個折線圖異常顯示問題
                    if(chart_count % 2 != 1){
                        chart[1].Series[0].Points.Clear();
                        if ((int_page * 2) - 1 > chart_count && Thermal_SelectAnother == false)
                            chart_Title[1].Text = "";
                    }
                    if (chart_count == 0){
                        chart_Thermal.Series[0].Points.Clear();
                        chart_Thermal.Series[1].Points.Clear();
                        //只剩一個時把第二張折線圖的線刪掉
                        chart[chart_count + 1].Series[0].Points.Clear();
                    }
                    for (int j = 0; j < tem_read.Count; j++){
                        //如果資料檔內還沒存放超過30個數字，表示不用推移折線圖，直接加入最新點位即可
                        //if (tem_read.Count < 30) j = tem_read.Count - 1;
                        int tem_count = int.Parse(tem_read[j].Split(',')[0]) + 1;
                        chart[chart_count % 2].Series[0].Points.AddXY(tem_count, tem_read[j].Split(',')[1]);
                        if (chart_count == 0)
                            chart_Thermal.Series[0].Points.AddXY(tem_count, tem_read[j].Split(',')[1]);
                    }
                    for (int j = 0; j < 30; j++){
                        if(tem_read.Count >= 30){
                            int tem_count = int.Parse(tem_read[j].Split(',')[0]) + 1;
                            chart[chart_count % 2].Series[1].Points.AddXY(tem_count, 25);
                            chart_Thermal.Series[1].Points.AddXY(tem_count, 25);
                        }
                        else{
                            chart[chart_count % 2].Series[1].Points.AddXY(j + 1, 25);
                            chart_Thermal.Series[1].Points.AddXY(j + 1, 25);
                        }
                    }
                    if (chart_count == 0) lb_Thermal_Now.Text = btn_Thermal[i].Text;
                    chart_Title[chart_count % 2].Text = btn_Thermal[i].Text;
                    chart_count++;
                    //目前暫時只能存兩個折線圖檔
                    if (chart_count >= 2 * int_page) break;
                }
            }
        }
        /// <summary>
        /// 判定是否產生Log訊息
        /// </summary>
        /// <param name="temperature">溫度</param>
        /// <param name="WriteWhere">發生事故的物件名稱</param>
        private void Thermal_Log(float temperature, string WriteObject){
            if (temperature > 25.85f) Write_Log("緊急", WriteObject + "軸目前溫度已上升至 " + temperature + "℃");
            else if (temperature > 25.7f) Write_Log("警告", WriteObject + "軸目前溫度已上升至 " + temperature + "℃");
        }
        //====假資料專用變數====
        bool[] Thermal_bool = new bool[20]; //該軸向是否開啟
        int[] Thermal_count = new int[20];
        float[] Thermal_temperature = new float[20];
        //List<string> tem_Thermal_chartData = new List<string>();
        //====假資料專用變數====
        //熱補償 > 產生假資料
        delegate void FakeDataDelegate();
        private void Thermal_FakeData(){
            if (this.InvokeRequired){
                FakeDataDelegate FDD = new FakeDataDelegate(Thermal_FakeData);
                this.Invoke(FDD);
            }
            else{
                //Thermal_single = 0 : 沒有任何啟動
                //Thermal_single = 1 : 啟動單軸
                //Thermal_single > 1 : 啟動好幾軸
                for (int i = 0; i < 20; i++){
                    if (Thermal_bool[i] == false) continue;
                    Thermal_count[i]++;
                    Random ran = new Random(Guid.NewGuid().GetHashCode());
                    Thermal_temperature[i] = float.Parse((25 + ((float)ran.Next(-100, 100) * 0.01f)).ToString("00.00"));

                    Button[] btn_Thermal = new Button[20] { btn_Thermal_01, btn_Thermal_02, btn_Thermal_03,
                                       btn_Thermal_04,btn_Thermal_05,btn_Thermal_06,btn_Thermal_07,btn_Thermal_08,
                                       btn_Thermal_09,btn_Thermal_10,btn_Thermal_11,btn_Thermal_12,btn_Thermal_13,
                                       btn_Thermal_14,btn_Thermal_15,btn_Thermal_16,btn_Thermal_17,btn_Thermal_18,
                                       btn_Thermal_19,btn_Thermal_20};
                    //寫log
                    Thermal_Log(Thermal_temperature[i], btn_Thermal[i].Text);

                    List<string> tem_read = new List<string>();
                    try{
                        StreamReader sr_axial = new StreamReader(path + @"\data\Temperature\Axial" + i.ToString("00") + ".cp");
                        while (!sr_axial.EndOfStream) tem_read.Add(sr_axial.ReadLine());
                        sr_axial.Close();
                        sr_axial.Dispose();
                    }
                    catch { }

                    ////顯示折線圖(單軸)
                    if (tem_read.Count >= 30) 
                        tem_read.RemoveAt(0);

                    tem_read.Add(Thermal_temperature[i].ToString());
                    StreamWriter sw_axial = new StreamWriter(path + @"\data\Temperature\Axial" + i.ToString("00") + ".cp");
                    for (int j = 0; j < tem_read.Count; j++){
                        if (tem_read.Count >= 30)
                            //判斷是不是新加入的值
                            if (j == tem_read.Count - 1)
                                sw_axial.WriteLine(Thermal_count[i] + "," + Thermal_temperature[i].ToString());
                            else
                                sw_axial.WriteLine((Thermal_count[i] - (30 - j)).ToString() + "," + tem_read[j].Split(',')[1]);
                        else{
                            //判斷是不是新加入的值
                            if (j == tem_read.Count - 1)
                                sw_axial.WriteLine(j + "," + Thermal_temperature[i].ToString());
                            else
                                sw_axial.WriteLine(j + "," + tem_read[j].Split(',')[1]);
                        }
                    }
                    sw_axial.Close();
                    sw_axial.Dispose();
                    //break;
                }
                //是否只有一個訊號在運行且是否點選正在運行的訊號
                if (Thermal_single == 1 && Thermal_SelectAnother == false){
                    panel_Thermal_single.Visible = true;
                    panel_Thermal_Mutile.Visible = false;
                }
                else if (Thermal_single == 1 && Thermal_SelectAnother == true){
                    panel_Thermal_single.Visible = false;
                    panel_Thermal_Mutile.Visible = true;
                }
                //呼叫繪圖程式
                Thermal_ChartData();
            }
        }
        #endregion
        #region 選擇工件/新增工件
        //磨耗偵測 > 選擇工件 > 讀取資料
        private void SelectParts_LoadData(){
            Panel[] panel_Parts = new Panel[8] { panel_SelectParts_01, panel_SelectParts_02, panel_SelectParts_03, panel_SelectParts_04,
                                                 panel_SelectParts_05, panel_SelectParts_06, panel_SelectParts_07, panel_SelectParts_08 };
            Panel[] panel_Parts_Add = new Panel[8] { panel_SelectParts_01Add, panel_SelectParts_02Add, panel_SelectParts_03Add, panel_SelectParts_04Add,
                                                 panel_SelectParts_05Add, panel_SelectParts_06Add, panel_SelectParts_07Add, panel_SelectParts_08Add };
            Label[] lb_Parts = new Label[8] { lb_SelectParts_01, lb_SelectParts_02, lb_SelectParts_03, lb_SelectParts_04,
                                              lb_SelectParts_05, lb_SelectParts_06, lb_SelectParts_07, lb_SelectParts_08 };
            PictureBox[] pb_Parts = new PictureBox[8] { pb_SelectParts_01, pb_SelectParts_02, pb_SelectParts_03, pb_SelectParts_04,
                                                        pb_SelectParts_05, pb_SelectParts_06, pb_SelectParts_07, pb_SelectParts_08};
            StreamReader sr = new StreamReader(path + @"\data\parts.cp");
            //先隱藏全部選項和新增panel
            for (int i = 0; i < panel_Parts.Length; i++){
                panel_Parts[i].Visible = false;
                panel_Parts_Add[i].Visible = false;
            }
            int read_count = 0;
            while (!sr.EndOfStream){
                //tem讀取範例：名稱,C:\Users\user\Desktop\Campro\ToolWear\ToolWear\bin\Debug\data\Image\IMG_3494.JPG
                string tem = sr.ReadLine();
                try{
                    if(read_count >= (int.Parse(lb_SelectParts_Page.Text) - 1) * 8 && read_count < int.Parse(lb_SelectParts_Page.Text) * 8){
                        panel_Parts[read_count % 8].Visible = true;
                        lb_Parts[read_count % 8].Text = tem.Split(',')[0];
                        if (!tem.Split(',')[1].Equals("null"))
                            pb_Parts[read_count % 8].BackgroundImage = Image.FromFile(tem.Split(',')[1]);
                        else
                            pb_Parts[read_count % 8].BackgroundImage = ToolWear.Properties.Resources.wd_img_blank;
                    }
                    else if (read_count >= (int.Parse(lb_SelectParts_Page.Text) + 1) * 8) break;
                    read_count++;
                }
                catch(Exception ex){
                    MessageBox.Show("讀取工件資料時出現不可測意外。\n可能是設定檔或是圖片檔遺失，請重新檢查。\n\nSelectParts_LoadData\n\n" + ex.ToString(), "讀取失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    break;
                }
            }
            sr.Close();
            sr.Dispose();
            //判斷是否此頁面還有空間塞入 + 號
            for(int i = 0;i< panel_Parts.Length; i++){
                //如果panel的visible是false的話表示因為沒有資料所以不讀取，那就將該panel置換成新增工件
                if(panel_Parts[i].Visible == false){
                    panel_Parts[i].Visible = true;
                    panel_Parts_Add[i].Visible = true;
                    panel_Parts_Add[i].BringToFront();
                    break;
                }
            }
        }
        //磨耗偵測 > 選擇工件 > 工件上一頁
        private void btn_SelectParts_up_Click(object sender,EventArgs e){
            if (lb_SelectParts_Page.Text.Equals("1")){
                MessageBox.Show("沒有辦法移至上一頁，已在首頁。", "頁面切換失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            lb_SelectParts_Page.Text = (int.Parse(lb_SelectParts_Page.Text) - 1).ToString();
            SelectParts_LoadData();
        }
        //磨耗偵測 > 選擇工件 > 工件下一頁
        private void btn_SelectParts_down_Click(object sender,EventArgs e){
            StreamReader sr = new StreamReader(path + @"\data\parts.cp");
            int sr_count = 0;
            while (!sr.EndOfStream){
                sr.ReadLine();
                sr_count++;
            }
            if(sr_count > int.Parse(lb_SelectParts_Page.Text) * 8){
                lb_SelectParts_Page.Text = (int.Parse(lb_SelectParts_Page.Text) + 1).ToString();
                SelectParts_LoadData();
            }
            else{
                MessageBox.Show("沒有更多的工件，已在最後一頁！", "頁面切換失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            sr.Close();
            sr.Dispose();
        }
        //磨耗偵測 > 選擇工件 > 移除工件
        private void btn_SelectParts_remove_Click(object sender,EventArgs e){
            Button btn_Select = (Button)sender;
            Label[] lb_SelectParts = new Label[8] { lb_SelectParts_01 , lb_SelectParts_02 , lb_SelectParts_03 , lb_SelectParts_04 ,
                                                    lb_SelectParts_05 , lb_SelectParts_06 , lb_SelectParts_07 , lb_SelectParts_08};
            //因為btn_Select.Name會得到btn_SelectParts_remove??，所以在切除底線後再對remove??進行切割取得數字
            int Select_count = int.Parse(btn_Select.Name.Split('_')[2].Split('e')[2]);
            string Parts_Name = lb_SelectParts[Select_count - 1].Text;
            string Delete_Path = "";
            DialogResult dialogResult = MessageBox.Show("您即將刪除 " + Parts_Name + "此項工件。\n此操作將不可復原，請檢查後再按下確定鍵。", "刪除警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            //暫存讀取的字串資料
            List<string> tem_Read = new List<string>();
            StreamReader sr = new StreamReader(path + @"\data\parts.cp");
            while (!sr.EndOfStream){
                string tem = sr.ReadLine();
                //如果資料檔內的工件名稱 = 本次要刪除的名稱 > 不暫存此資料(意即等等要重新改寫cp檔的時候會忽略之)
                if (!tem.Split(',')[0].Equals(Parts_Name)){
                    tem_Read.Add(tem);
                    //暫存圖片檔路徑
                    Delete_Path = tem.Split(',')[1];
                }
            }
            sr.Close();
            sr.Close();
            StreamWriter sw = new StreamWriter(path + @"\data\parts.cp");
            for(int i = 0; i < tem_Read.Count; i++)
                    sw.WriteLine(tem_Read[i]);
            sw.Close();
            sw.Dispose();
            //初始化該項目的pictureBox和TextBox，避免不必要的例外事件發生
            PictureBox[] pb_SelectParts = new PictureBox[8] { pb_SelectParts_01, pb_SelectParts_02, pb_SelectParts_03, pb_SelectParts_04,
                                                              pb_SelectParts_05, pb_SelectParts_06, pb_SelectParts_07, pb_SelectParts_08};
            lb_SelectParts[Select_count - 1].Text = "工件A";
            pb_SelectParts[Select_count - 1].BackgroundImage = ToolWear.Properties.Resources.wd_img_blank;
            //重新整理頁面
            pb_ToolWear_Click(null, null);
            //MessageBox.Show("工件刪除成功！", "刪除訊息", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }
        //磨耗偵測 > 選擇工件 > select按鈕
        private void btn_SelectParts(object sender,EventArgs e){
            Button btn_Select = (Button)sender;
            Label[] lb_SelectParts = new Label[8] { lb_SelectParts_01 , lb_SelectParts_02 , lb_SelectParts_03 , lb_SelectParts_04 ,
                                                    lb_SelectParts_05 , lb_SelectParts_06 , lb_SelectParts_07 , lb_SelectParts_08};
            PictureBox[] pb_SelectParts = new PictureBox[8] { pb_SelectParts_01, pb_SelectParts_02, pb_SelectParts_03, pb_SelectParts_04,
                                                              pb_SelectParts_05, pb_SelectParts_06, pb_SelectParts_07, pb_SelectParts_08};
            int Select_count = int.Parse(btn_Select.Name.Split('_')[2]);
            DialogResult dialogResult = MessageBox.Show("確定要選擇 " + lb_SelectParts[Select_count - 1].Text + " 這項工件嗎？", "選擇工件", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;
            //修改磨耗偵測的工件名稱和圖片
            lb_ToolWear_Parts.Text = lb_SelectParts[Select_count - 1].Text;
            pb_ToolWear.BackgroundImage = pb_SelectParts[Select_count - 1].BackgroundImage;
            panel_SelectParts.Visible = false;
            panel_ToolWear.Visible = true;
        }
        //磨耗偵測 > 選擇工件 > 新增工件 > 取消新增
        private void btn_AddParts_delete_Click(object sender, EventArgs e){
            DialogResult dialogResult = MessageBox.Show("確定要放棄此次新增嗎？", "放棄新增", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            tb_AddParts_Name.Text = "";
            tb_AddParts_Path.Text = "";
            panel_Dissable();
            panel_SelectParts.Visible = true;
            btn_Learn.BackgroundImage = ToolWear.Properties.Resources.menubtn_learn_default;
            btn_Learn.Enabled = true;
        }
        //磨耗偵測 > 選擇工件 > 新增工件 > 搜尋
        private void btn_AddParts_Path_Click(object sender, EventArgs e){
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Title = "選擇工件圖片";
            dialog.InitialDirectory = @"C:\";
            dialog.Filter = "圖片檔案(*.jpg,*.gif,*.bmp)|*.jpg;*.gif;*.bmp";
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                tb_AddParts_Path.Text = dialog.FileName;
                path_AddFile_name = dialog.SafeFileName;
                pb_AddParts.BackgroundImage = Image.FromFile(dialog.FileName);
            }
        }
        //選擇的檔案名稱
        private string path_AddFile_name = "";
        //磨耗偵測 > 選擇工件 > 新增工件 > 儲存
        private void btn_AddParts_save_Click(object sender, EventArgs e){
            if (string.IsNullOrWhiteSpace(tb_AddParts_Name.Text) || string.IsNullOrEmpty(tb_AddParts_Name.Text)){
                MessageBox.Show("請輸入工件名稱！", "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            if (string.IsNullOrWhiteSpace(tb_AddParts_Path.Text)){
                DialogResult dialogResult1 = MessageBox.Show("您尚未選擇工件圖片來源\n確定不要加入圖片嗎？", "圖片未選取", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
                if (dialogResult1 == DialogResult.Cancel) return;
            }
            //檢查是否有同樣名稱的工件
            StreamReader sr = new StreamReader(path + @"\data\parts.cp");
            while (!sr.EndOfStream){
                string tem = sr.ReadLine();
                if (tem.Split(',')[0].Equals(tb_AddParts_Name.Text)){
                    MessageBox.Show("工件名稱重複，請重新輸入。", "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    sr.Close();
                    sr.Dispose();
                    return;
                }
            }
            sr.Close();
            sr.Dispose();
            DialogResult dialogResult = MessageBox.Show("確定要新增此工件嗎？", "確認訊息", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;

            try
            {
                FileStream File_module = File.Open(path + @"\data\parts.cp", FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
                StreamWriter sw = new StreamWriter(File_module);
                //有選圖片的話
                if (!string.IsNullOrWhiteSpace(tb_AddParts_Path.Text)){
                    sw.WriteLine(tb_AddParts_Name.Text + "," + (path + @"data\Image\" + path_AddFile_name));
                    File.Copy(tb_AddParts_Path.Text, path + @"\data\Image\" + path_AddFile_name);
                }
                //沒選圖片的話
                else
                    sw.WriteLine(tb_AddParts_Name.Text + ",null");
                sw.Close();
                sw.Dispose();
                MessageBox.Show(tb_AddParts_Name.Text + "\n已儲存成功。", "儲存成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
                tb_AddParts_Name.Text = "";
                tb_AddParts_Path.Text = "";
                panel_AddParts.Visible = false;
                btn_Learn.BackgroundImage = ToolWear.Properties.Resources.menubtn_learn_default;
                btn_Learn.Enabled = true;
                pb_ToolWear_Click(null, null);
            }
            catch(Exception ex){
                MessageBox.Show("在儲存時發生不可測意外。\n\nThis problem is from btn_AddParts_save.\n\n"+ ex.ToString(), "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        #endregion
        #endregion
        #region 20顆按鈕事件
        #region 磨耗偵測
        //磨耗偵測
        //現在點選到的按鈕
        int now_ToolWear = 0;
        //上一個點到的button
        Button pre_ToolWear = null;
        //存放該軸向是否正處於磨耗偵測狀態下
        bool[] ToolWear_bool = new bool[20];
        private void btn_ToolWear_Choose(object sender,EventArgs e){
            //目前只能單軸偵測
            for(int i = 0; i < 20; i++){
                if(ToolWear_bool[i] == true){
                    MessageBox.Show("Beta階段只允許單軸偵測，請先關閉當前正在偵測的軸向再點選其他按鈕。", "嘗試選取多軸向", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
            }
            //先重置上次選到的按鈕
            if (pre_ToolWear != null){
                pre_ToolWear.BackgroundImage = ToolWear.Properties.Resources.tc_btn_axiabtn;
            }
            pre_ToolWear = (Button)sender;
            pre_ToolWear.BackgroundImage = ToolWear.Properties.Resources.tc_btn_axiabtn_selected;
            now_ToolWear = int.Parse(((Button)sender).Name.Split('_')[2]) - 1;
            //背景處理選擇設定介面的該軸向
            Button[] btn_ToolWearSetting = new Button[20] { btn_ToolWearSetting_01, btn_ToolWearSetting_02, btn_ToolWearSetting_03,
            btn_ToolWearSetting_04,btn_ToolWearSetting_05,btn_ToolWearSetting_06,btn_ToolWearSetting_07,btn_ToolWearSetting_08,
            btn_ToolWearSetting_09,btn_ToolWearSetting_10,btn_ToolWearSetting_11,btn_ToolWearSetting_12,btn_ToolWearSetting_13,
            btn_ToolWearSetting_14,btn_ToolWearSetting_15,btn_ToolWearSetting_16,btn_ToolWearSetting_17,btn_ToolWearSetting_18,
            btn_ToolWearSetting_19,btn_ToolWearSetting_20};
            btn_ToolWearSetting_Choose((object)btn_ToolWearSetting[now_ToolWear], null);
            //轉移焦點
            btn_ToolWear_Start.Focus();
            //判斷是否選擇的軸向已經在偵測狀態中
            if(ToolWear_bool[now_ToolWear] == true){
                btn_ToolWear_Start.BackgroundImage = ToolWear.Properties.Resources.tc_btn_ply;
                btn_ToolWear_Stop.BackgroundImage = ToolWear.Properties.Resources.btn_stop_selected;
                btn_ToolWear_Start.Enabled = false;
                btn_ToolWear_Stop.Enabled = true;
            }
            else{
                btn_ToolWear_Start.BackgroundImage = ToolWear.Properties.Resources.btn_start_selected;
                btn_ToolWear_Stop.BackgroundImage = ToolWear.Properties.Resources.tc_btn_stop;
                btn_ToolWear_Start.Enabled = true;
                btn_ToolWear_Stop.Enabled = false;
            }
        }
        #endregion
        #region 學習模式
        //學習模式
        //現在點到的按鈕
        int now_learn = 0;
        //上一個點到的button
        Button pre_learn = null;
        private void btn_Learn_Choose(object sender, EventArgs e){
            //如果正在學習中，不允許切換數據
            if (On_Learn == true){
                MessageBox.Show("目前正處於學習階段，不允許切換軸向。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            if(runningTask != null){
                MessageBox.Show("請先停止所有軸向的磨耗偵測。\n在學習模式中禁止同時偵測磨耗資訊，以免發生不可測意外。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            //先重置上次選到的按鈕
            if (pre_learn != null){
                pre_learn.BackgroundImage = ToolWear.Properties.Resources.tc_btn_axiabtn;
            }
            pre_learn = (Button)sender;
            pre_learn.BackgroundImage = ToolWear.Properties.Resources.tc_btn_axiabtn_selected;
            now_learn = int.Parse(((Button)sender).Name.Split('_')[2]) - 1;
            //背景處理選擇設定介面的該軸向
            Button[] btn_ToolWearSetting = new Button[20] { btn_ToolWearSetting_01, btn_ToolWearSetting_02, btn_ToolWearSetting_03,
            btn_ToolWearSetting_04,btn_ToolWearSetting_05,btn_ToolWearSetting_06,btn_ToolWearSetting_07,btn_ToolWearSetting_08,
            btn_ToolWearSetting_09,btn_ToolWearSetting_10,btn_ToolWearSetting_11,btn_ToolWearSetting_12,btn_ToolWearSetting_13,
            btn_ToolWearSetting_14,btn_ToolWearSetting_15,btn_ToolWearSetting_16,btn_ToolWearSetting_17,btn_ToolWearSetting_18,
            btn_ToolWearSetting_19,btn_ToolWearSetting_20};
            btn_ToolWearSetting_Choose((object)btn_ToolWearSetting[now_learn], null);
            //轉移焦點
            btn_Learn_Start.Focus();
        }
        #endregion
        #region 軸向設定
        //軸向設定
        //現在要更改的設定檔
        int now_ToolWearSetting = 0;
        //上一個點到的button
        Button pre_ToolWearSetting = null;
        private void btn_ToolWearSetting_Choose(object sender, EventArgs e) {
            Button btn = (Button)sender;
            //將上一個點到的button文字顏色改回白色
            if (pre_ToolWearSetting != null)
                pre_ToolWearSetting.ForeColor = Color.White;
            //設定上一個點的button為現在的button
            pre_ToolWearSetting = btn;
            //設定現在的button文字顏色為橘色
            btn.ForeColor = Color.FromArgb(255, 187, 0);
            //取得button的ID末位，01~20
            string ID = btn.Name.Split('_')[2];
            now_ToolWearSetting = int.Parse(ID) - 1;
            StreamReader sr_axial = new StreamReader(path + @"\data\axial.cp");
            try{
                for (int i = 0; i < int.Parse(ID); i++){
                    //初始化下拉選單
                    cb_ToolWearSetting_accelerometer.SelectedIndex = 0;
                    cb_ToolWearSetting_Axial.SelectedIndex = 0;
                    physicalChannelComboBox.SelectedIndex = 0;
                    //ex. tem = "X,0,0,0" or tem = "Y,1,2,0"
                    string tem = sr_axial.ReadLine();
                    if (i == int.Parse(ID) - 1){
                        tb_ToolWearSetting_name.Text = tem.Split(',')[0];
                        int Accelerometer = int.Parse(tem.Split(',')[1]);
                        cb_ToolWearSetting_accelerometer.SelectedIndex = Accelerometer;
                        int Axial = int.Parse(tem.Split(',')[2]);
                        cb_ToolWearSetting_Axial.SelectedIndex = Axial;
                        string tem_Channel = tem.Split(',')[3];
                        for(int j = 0; j < physicalChannelComboBox.Items.Count; j++){
                            physicalChannelComboBox.SelectedIndex = j;
                            if (physicalChannelComboBox.Text.Equals(tem_Channel)){
                                physicalChannelComboBox.SelectedIndex = j;
                                break;
                            }
                            //如果j已搜尋到最後都找不到匹配的輸入(代表原先設定的訊號不見了)
                            if(j == physicalChannelComboBox.Items.Count - 1){
                                physicalChannelComboBox.SelectedIndex = 0;
                                MessageBox.Show("搜尋不到此軸向原先設定的訊號輸入，請確認輸入訊號接頭是否脫落。\n重新連接設備並使用重新整理按鈕搜尋訊號輸入。" +
                                    "\n若依然找不到訊號輸入，請重新選擇並儲存。", "找不到訊號輸入", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            }
                        }
                        //int Channel = int.Parse(tem.Split(',')[3]);
                        //physicalChannelComboBox.SelectedIndex = Channel;
                    }
                }
            }
            catch {

            }
            sr_axial.Close();
            sr_axial.Dispose();
        }
        //軸向設定 > 儲存
        private void btn_ToolWearSetting_save_Click(object sender, EventArgs e){
            DialogResult dialogResult = MessageBox.Show("確定儲存？", "存檔訊息", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;
            string tem_s = tb_ToolWearSetting_name.Text + "," + cb_ToolWearSetting_accelerometer.SelectedIndex +
               "," + cb_ToolWearSetting_Axial.SelectedIndex + "," + physicalChannelComboBox.Text;
            try{
                ToolWearSetting_SW(tem_s);
                MessageBox.Show("儲存成功！", "", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch(Exception ex) {
                MessageBox.Show("儲存失敗。\n\nbtn_ToolWearSetting_save_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //軸向設定 > 刪除
        private void btn_ToolWearSetting_delete_Click(object sender, EventArgs e){
            DialogResult dialogResult = MessageBox.Show("確定要刪除此軸向之設定資料嗎？", "刪除警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            string tem_s = tb_ToolWearSetting_name.Text;
            try{
                ToolWearSetting_SW(tem_s);
                MessageBox.Show("刪除成功！", "", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex){
                MessageBox.Show("刪除失敗。\n\nbtn_ToolWearSetting_delete_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //軸向設定 > 讀檔+寫檔
        private void ToolWearSetting_SW(string s){
            StreamReader sr_axial = new StreamReader(path + @"\data\axial.cp");
            List<string> tem_read = new List<string>();
            while (!sr_axial.EndOfStream) tem_read.Add(sr_axial.ReadLine());
            sr_axial.Close();
            sr_axial.Dispose();
            //更改現在的條目
            tem_read[now_ToolWearSetting] = s;
            StreamWriter sw_axial = new StreamWriter(path + @"\data\axial.cp");
            for (int i = 0; i < tem_read.Count; i++)
                sw_axial.WriteLine(tem_read[i]);
            sw_axial.Close();
            sw_axial.Dispose();
            //儲存完後執行初始化方法，重新載入文字
            Initialization();
            btn_ToolWearSetting_Choose((object)pre_ToolWearSetting, null);
        }
        #endregion
        #region 熱補償設定
        //熱補償設定
        //現在要更改的設定檔
        int now_Compensate = 0;
        //上一個點到的button
        Button pre_Compensate = null;
        //紀錄溫升補償
        List<string> compensate_data = new List<string>();
        private void btn_Compensate_Choose(object sender, EventArgs e){
            //宣告溫升補償顯示TextBox欄位
            TextBox[] tb_Compensate = new TextBox[7] { tb_Compensate_01 , tb_Compensate_02 , tb_Compensate_03 ,
            tb_Compensate_04,tb_Compensate_05,tb_Compensate_06,tb_Compensate_07};
            StreamReader sr_axial = new StreamReader(path + @"\data\compensate.cp");
            //清空TextBox的Text資料
            for (int i = 0; i < tb_Compensate.Length; i++)
                tb_Compensate[i].Text = "";
            //重置TextBox選取資料
            tb_Compensate_Clear();
            //清除溫升補償資料
            compensate_data.Clear();
            Button btn = (Button)sender;
            //將上一個點到的button文字顏色改回白色
            if (pre_Compensate != null)
                pre_Compensate.ForeColor = Color.White;
            //設定上一個點的button為現在的button
            pre_Compensate = btn;
            //設定現在的button文字顏色為橘色
            btn.ForeColor = Color.FromArgb(255, 187, 0);
            //取得button的ID末位，01~20
            string ID = btn.Name.Split('_')[2];
            now_Compensate = int.Parse(ID) - 1;
            //讀取溫升補償檔案
            while (!sr_axial.EndOfStream){
                //ex tem = 1,25.0,1.00
                //編號(0~19),溫度,補償
                string tem = sr_axial.ReadLine();
                compensate_data.Add(tem);   //新增資料進暫存變數
                int number = int.Parse(tem.Split(',')[0]);
                if(number == now_Compensate){
                    string temperature = tem.Split(',')[1];
                    string compensate = tem.Split(',')[2];
                    //將資料寫入TextBox內
                    for(int i = 0; i < tb_Compensate.Length; i++){
                        if (tb_Compensate[i].Text == ""){
                            tb_Compensate[i].Text = "    " + pre_Compensate.Text + " 軸 , " + temperature + " ℃ , " + compensate + " mm";
                            break;
                        }
                    }
                }
            }
            sr_axial.Close();
            sr_axial.Dispose();

            //IP和輸入讀取
            StreamReader sr_set = new StreamReader(path + @"\data\thermal.cp");
            try{
                for (int i = 0; i <= now_Compensate; i++){
                    string tem = sr_set.ReadLine();
                    if (i == now_Compensate){
                        tb_Compensate_ip.Text = tem.Split(',')[1];
                        //tb_Compensate_Channel.Text = tem.Split(',')[2];
                        for(int j = 0; j < cb_Compensate_Channel.Items.Count; j++){
                            cb_Compensate_Channel.SelectedIndex = j;
                            if (cb_Compensate_Channel.Text.Equals(tem.Split(',')[2]))
                                break;
                            //當搜尋完所有選項後都沒有發現符合的文字(代表設定檔被修改過)
                            if(j == cb_Compensate_Channel.Items.Count - 1){
                                cb_Compensate_Channel.SelectedIndex = 0;
                                MessageBox.Show("輸入訊號設定檔錯誤，請重新設定！", "設定檔錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            }
                        }
                    }
                }
            }
            catch{
                tb_Compensate_ip.Text = "";
                cb_Compensate_Channel.SelectedIndex = 0;
            }
            sr_set.Close();
            sr_set.Dispose();

            //重置頁碼
            //e == null表示是使用程式指令方法進入此function，所以要將頁碼回歸原本的地方
            //e != null表示是由使用者觸發Click事件才進入
            int tem_page = int.Parse(lb_Compensate_page.Text);
            lb_Compensate_page.Text = "1";
            if (e == null){
                for (int i = 0; i < tem_page - 1; i++)
                    btn_Compensate_down_Click(null, null);
            }
        }
        //IP和輸入 > 存檔
        private void btn_CompensateSet_save_Click(object sender, EventArgs e){
            DialogResult dialogResult = MessageBox.Show("確定儲存？", "存檔訊息", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;
            string tem = pre_Compensate.Text + "," + tb_Compensate_ip.Text + "," + cb_Compensate_Channel.Text;
            try{
                RW_CompensateSet(tem);
                MessageBox.Show("IP與訊號輸入設定完成！", "儲存成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch(Exception ex) {
                MessageBox.Show("儲存失敗。\n\nbtn_CompensateSet_save_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //IP和輸入 > 刪除
        private void btn_CompensateSet_delete_Click(object sender, EventArgs e){
            DialogResult dialogResult = MessageBox.Show("確定要刪除此軸向之設定資料嗎？", "刪除警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            string tem = ((Button)pre_Compensate).Text + ", , ";
            try{
                RW_CompensateSet(tem);
                MessageBox.Show("IP與訊號輸入刪除成功！");
            }
            catch (Exception ex){
                MessageBox.Show("刪除失敗。\n\nbtn_CompensateSet_delete_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //IP和輸入 > 讀檔+寫檔
        private void RW_CompensateSet(string s){
            StreamReader sr_set = new StreamReader(path + @"\data\thermal.cp");
            List<string> tem_read = new List<string>();
            while (!sr_set.EndOfStream) tem_read.Add(sr_set.ReadLine());
            sr_set.Close();
            sr_set.Dispose();
            //更改現在的條目
            tem_read[now_Compensate] = s;
            StreamWriter sw_set = new StreamWriter(path + @"\data\thermal.cp");
            for (int i = 0; i < tem_read.Count; i++)
                sw_set.WriteLine(tem_read[i]);
            sw_set.Close();
            sw_set.Dispose();
            //儲存完後執行初始化方法，重新載入文字
            Initialization();
            btn_Compensate_Choose((object)pre_Compensate, null);
        }
        //溫補 > 選取
        //紀錄現在選擇的TextBox次序
        int tb_Compensate_Select = -1;
        //紀錄上一個點選的TextBox
        TextBox pre_Compensate_tb;
        private void tb_Compensate_Click(object sender,EventArgs e){
            TextBox tb_Compensate = ((TextBox)sender);
            if (pre_Compensate_tb != null)
                pre_Compensate_tb.BackColor = Color.WhiteSmoke;
            tb_Compensate.BackColor = Color.CadetBlue;
            pre_Compensate_tb = tb_Compensate;
            //如果選擇的TextBox是空的那就顯示預設值
            if (tb_Compensate.Text.Equals("")){
                tb_Compensate_Select = -1;
                numeric_Temperature.Value = 25.0M;
                numeric_Compensate.Value = 1.00M;
            }
            else{
                tb_Compensate_Select = int.Parse(tb_Compensate.Name.Split('_')[2]);
                numeric_Temperature.Value = decimal.Parse(tb_Compensate.Text.Split(',')[1].Split(' ')[1]);
                numeric_Compensate.Value = decimal.Parse(tb_Compensate.Text.Split(',')[2].Split(' ')[1]);
            }
        }
        //清除溫補選取
        private void tb_Compensate_Clear(){
            tb_Compensate_Select = -1;
            numeric_Temperature.Value = 25.0M;
            numeric_Compensate.Value = 1.00M;
            if (pre_Compensate_tb != null){
                pre_Compensate_tb.BackColor = Color.WhiteSmoke;
                pre_Compensate_tb = null;
            }
        }
        //溫補 > 上一頁
        private void btn_Compensate_up_Click(object sender, EventArgs e){
            if (!lb_Compensate_page.Text.Equals("1")){
                //宣告溫升補償顯示TextBox欄位
                TextBox[] tb_Compensate = new TextBox[7] { tb_Compensate_01 , tb_Compensate_02 , tb_Compensate_03 ,
                tb_Compensate_04,tb_Compensate_05,tb_Compensate_06,tb_Compensate_07};
                //先暫存陣列內此按鈕的補償資料
                List<string> now_Data = new List<string>();
                for (int i = 0; i < compensate_data.Count; i++){
                    if (int.Parse(compensate_data[i].Split(',')[0]) == now_Compensate)
                        now_Data.Add(compensate_data[i]);
                }
                for(int i = 0; i < tb_Compensate.Length; i++){
                    string tem = now_Data[((int.Parse(lb_Compensate_page.Text) - 2) * tb_Compensate.Length) + i];
                    int number = int.Parse(tem.Split(',')[0]);
                    string temperature = tem.Split(',')[1];
                    string compensate = tem.Split(',')[2];
                    tb_Compensate[i].Text = "    " + pre_Compensate.Text + " 軸 , " + temperature + " ℃ , " + compensate + " mm";
                }
                lb_Compensate_page.Text = (int.Parse(lb_Compensate_page.Text) - 1).ToString();
                tb_Compensate_Clear();
            }
            else MessageBox.Show("已經在第一頁了！");
        }
        //溫補 > 下一頁
        private void btn_Compensate_down_Click(object sender, EventArgs e){
            //宣告溫升補償顯示TextBox欄位
            TextBox[] tb_Compensate = new TextBox[7] { tb_Compensate_01 , tb_Compensate_02 , tb_Compensate_03 ,
            tb_Compensate_04,tb_Compensate_05,tb_Compensate_06,tb_Compensate_07};
            //先判斷暫存陣列內有幾個此按鈕的補償資料
            List<string> now_Data = new List<string>();
            for(int i = 0;i< compensate_data.Count; i++){
                if (int.Parse(compensate_data[i].Split(',')[0]) == now_Compensate)
                    now_Data.Add(compensate_data[i]);
            }
            //當暫存數量大於第N頁 * 7個TextBox 的時候才可以按下一頁
            if (now_Data.Count > int.Parse(lb_Compensate_page.Text) * tb_Compensate.Length){
                for (int i = 0; i < tb_Compensate.Length; i++){
                    //判斷是否現在讀取的項次小於總共暫存數量
                    if (now_Data.Count > (int.Parse(lb_Compensate_page.Text) * tb_Compensate.Length) + i){
                        string tem = now_Data[(int.Parse(lb_Compensate_page.Text) * tb_Compensate.Length) + i];
                        int number = int.Parse(tem.Split(',')[0]);
                        string temperature = tem.Split(',')[1];
                        string compensate = tem.Split(',')[2];
                        tb_Compensate[i].Text = "    " + pre_Compensate.Text + " 軸 , " + temperature + " ℃ , " + compensate + " mm";
                    }
                    else tb_Compensate[i].Text = "";
                }
                lb_Compensate_page.Text = (int.Parse(lb_Compensate_page.Text) + 1).ToString();
                tb_Compensate_Clear();
            }
            else MessageBox.Show("已經在最末頁了！");
        }
        //溫補 > 新增
        private void btn_CompensateAdd_Click(object sender, EventArgs e){
            //取得button後面編號
            string tem = (int.Parse(pre_Compensate.Name.Split('_')[2]) - 1).ToString() + "," + 
                numeric_Temperature.Value + "," + numeric_Compensate.Value;
            try{
                FileStream File_module = File.Open(path + @"\data\compensate.cp", FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
                StreamWriter sw = new StreamWriter(File_module);
                sw.WriteLine(tem);
                sw.Close();
                sw.Dispose();
                //儲存完後執行初始化方法，重新載入文字
                Initialization();
                btn_Compensate_Choose((object)pre_Compensate, null);
            }
            catch(Exception ex) {
                MessageBox.Show("發生不可測意外。\n\nbtn_CompensateAdd_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //溫補 > 儲存
        private void btn_CompensateSave_Click(object sender, EventArgs e){
            if (tb_Compensate_Select == -1){
                string output = "";
                if (pre_Compensate_tb.Text.Equals(""))
                    output = "您正準備存取尚未擁有初始值的項目，\n請使用 + 符號新增資料。";
                else
                    output = "尚未選擇要儲存的項目，請點選下方空格。";
                    MessageBox.Show(output,"儲存失敗",MessageBoxButtons.OK,MessageBoxIcon.Error);
                return;
            }
            DialogResult dialogResult = MessageBox.Show("確定儲存？", "存檔訊息", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;
            //取得button後面編號
            string tem = (int.Parse(pre_Compensate.Name.Split('_')[2]) - 1).ToString() + "," +
                numeric_Temperature.Value + "," + numeric_Compensate.Value;
            try{
                RW_Compensate(tem,false);
            }
            catch (Exception ex){
                MessageBox.Show("發生不可測意外。\n\nbtn_CompensateSave_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //溫補 > 移除
        private void btn_CompensateRemove_Click(object sender, EventArgs e){
            if (tb_Compensate_Select == -1){
                string output = "";
                if (pre_Compensate_tb.Text.Equals(""))
                    output = "您正準備刪除尚未擁有初始值的項目。";
                else
                    output = "尚未選擇要刪除的項目，請點選下方空格。";
                MessageBox.Show(output, "刪除失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            DialogResult dialogResult = MessageBox.Show("確定刪除？\n注意！此動作不可復原，請確認後再繼續。", "刪除訊息", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            //取得button後面編號
            string tem = "";
            try{
                RW_Compensate(tem, true);
            }
            catch (Exception ex){
                MessageBox.Show("發生不可測意外。\n\nbtn_CompensateRemove_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        /// <summary>
        /// 溫補 > 讀檔寫檔
        /// </summary>
        /// <param name="s">要修改的字串</param>
        /// <param name="remove">是否為移除模式</param>
        private void RW_Compensate(string s,bool remove){
            StreamReader sr_set = new StreamReader(path + @"\data\compensate.cp");
            List<string> tem_read = new List<string>();
            while (!sr_set.EndOfStream) tem_read.Add(sr_set.ReadLine());
            sr_set.Close();
            sr_set.Dispose();
            //宣告溫升補償顯示TextBox欄位
            TextBox[] tb_Compensate = new TextBox[7] { tb_Compensate_01 , tb_Compensate_02 , tb_Compensate_03 ,
                        tb_Compensate_04,tb_Compensate_05,tb_Compensate_06,tb_Compensate_07};
            //更改現在的條目
            //查詢當前頁面要修改的項次是從幾號開始
            int count = 0;
            for(int i = 0; i < tem_read.Count; i++){
                //查詢是不是此軸向的資料
                if (int.Parse(tem_read[i].Split(',')[0]) == now_Compensate){
                    //判斷是否已查詢到要修改的項次資料
                    if (count + tb_Compensate_Select > (int.Parse(lb_Compensate_page.Text) - 1) * tb_Compensate.Length){
                        if (count % tb_Compensate.Length == tb_Compensate_Select - 1){
                            //判斷是否位於移除模式
                            if(remove == false)
                                tem_read[i] = (int.Parse(pre_Compensate.Name.Split('_')[2]) - 1).ToString() + "," +
                                        numeric_Temperature.Value + "," + numeric_Compensate.Value;
                            else
                                tem_read.RemoveAt(i);
                            break;
                        }
                        else
                            count++;    //表示還沒查到該項次，將計數器+1
                    }
                    else
                        count++;    //表示還沒查到該頁次，將計數器+1
                }
                    
            }
            //tem_read[now_Compensate] = s;
            StreamWriter sw_set = new StreamWriter(path + @"\data\compensate.cp");
            for (int i = 0; i < tem_read.Count; i++)
                sw_set.WriteLine(tem_read[i]);
            sw_set.Close();
            sw_set.Dispose();
            //儲存完後執行初始化方法，重新載入文字
            Initialization();
            btn_Compensate_Choose((object)pre_Compensate, null);
        }
        #endregion
        #region 刀庫設定
        //刀庫設定
        //現在要更改的設定檔
        int now_ATCSetting = 0;
        //上一個點到的button
        Button pre_ATCSetting = null;
        private void btn_ATCSetting_Choose(object sender, EventArgs e){
            Button btn = (Button)sender;
            //將上一個點到的button文字顏色改回白色
            if (pre_ATCSetting != null)
                pre_ATCSetting.ForeColor = Color.White;
            //設定上一個點的button為現在的button
            pre_ATCSetting = btn;
            //設定現在的button文字顏色為橘色
            btn.ForeColor = Color.FromArgb(255, 187, 0); ;
            //取得button的ID末位，01~20
            string ID = btn.Name.Split('_')[2];
            now_ATCSetting = int.Parse(ID) - 1;
            StreamReader sr_ATC = new StreamReader(path + @"\data\ATC.cp");
            try{
                for (int i = 0; i < int.Parse(ID); i++){
                    //初始化輸入框
                    tb_ATCsetting_Name.Text = "";
                    numeric_ATCsetting_Blade.Value = 4;
                    //ex. tem = "1,test,6" or tem = "2,,"
                    string tem = sr_ATC.ReadLine();
                    if (i == int.Parse(ID) - 1){
                        tb_ATCsetting_Name.Text = tem.Split(',')[1];
                        numeric_ATCsetting_Blade.Value = decimal.Parse(tem.Split(',')[2]);
                    }
                }
            }
            catch{
            }
            sr_ATC.Close();
            sr_ATC.Dispose();
        }
        //刀庫設定 > 存檔
        private void btn_ATCsetting_save_Click(object sender, EventArgs e){
            DialogResult dialogResult = MessageBox.Show("確定儲存？", "存檔訊息", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;
            string tem = pre_ATCSetting.Text + "," + tb_ATCsetting_Name.Text + "," + numeric_ATCsetting_Blade.Value;
            try{
                RW_TCsetting(tem);
                MessageBox.Show("刀具名稱與刃數存檔成功！");
            }
            catch (Exception ex){
                MessageBox.Show("發生不可測意外。\n\nbtn_ATCsetting_save_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //刀庫設定 > 刪除
        private void btn_ATCsetting_delete_Click(object sender, EventArgs e){
            DialogResult dialogResult = MessageBox.Show("確定要刪除此刀具之設定資料嗎？", "刪除警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            string tem = ((Button)pre_ATCSetting).Text + ",,";
            try{
                RW_TCsetting(tem);
                MessageBox.Show("刀具名稱與刃數刪除成功！");
            }
            catch (Exception ex){
                MessageBox.Show("發生不可測意外。\n\nbtn_ATCsetting_delete_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //刀庫設定 > 讀檔+寫檔
        private void RW_TCsetting(string s){
            StreamReader sr_set = new StreamReader(path + @"\data\ATC.cp");
            List<string> tem_read = new List<string>();
            while (!sr_set.EndOfStream) tem_read.Add(sr_set.ReadLine());
            sr_set.Close();
            sr_set.Dispose();
            //更改現在的條目
            tem_read[now_ATCSetting] = s;
            StreamWriter sw_set = new StreamWriter(path + @"\data\ATC.cp");
            for (int i = 0; i < tem_read.Count; i++)
                sw_set.WriteLine(tem_read[i]);
            sw_set.Close();
            sw_set.Dispose();
            //儲存完後執行初始化方法，重新載入文字
            Initialization();
            btn_ATCSetting_Choose((object)pre_ATCSetting, null);
        }
        #endregion
        #endregion
        #region 下拉選單事件
        //選擇加速規
        private void cb_ToolWearSetting_accelerometer_SelectedIndexChanged(object sender, EventArgs e){
            cb_ToolWearSetting_Axial.Items.Clear();
            if (cb_ToolWearSetting_accelerometer.SelectedIndex == 0)
                cb_ToolWearSetting_Axial.Items.Add("未選擇");
            if (cb_ToolWearSetting_accelerometer.SelectedIndex == 1)
                cb_ToolWearSetting_Axial.Items.Add("單向");
            else if (cb_ToolWearSetting_accelerometer.SelectedIndex == 2){
                cb_ToolWearSetting_Axial.Items.Add("X軸");
                cb_ToolWearSetting_Axial.Items.Add("Y軸");
                cb_ToolWearSetting_Axial.Items.Add("Z軸");
            }
        }
        //主選單 > 設定 > 選擇CNC廠牌
        private void cb_setting_brand_SelectedIndexChanged(object sender, EventArgs e){
            cb_setting_model.Items.Clear();
            cb_setting_model.Items.Add("選擇型號");
            switch (cb_setting_brand.Text){
                case "Mitsubishi":
                    cb_setting_model.Items.Add("M800");
                    break;
            }
        }
        #endregion
        #region 文字變更事件
        //暫存刀號
        int ATC_num = 0;
        private void lb_ToolWear_Tool_TextChanged(object sender, EventArgs e){
            try{
                ATC_num = int.Parse(((Label)sender).Text);
                StreamReader sr = new StreamReader(path + @"\data\ATC.cp");
                for (int i = 0; i < ATC_num; i++){
                    string tem = sr.ReadLine();
                    if (i != ATC_num - 1) continue;
                    ((Label)sender).Text = tem.Split(',')[1];
                    lb_ToolWear_Blade.Text = tem.Split(',')[2];
                }
                sr.Close();
                sr.Dispose();
            }
            catch(Exception ex){
                MessageBox.Show("讀取刀庫設定檔時發生錯誤。\n\nError code : \n" + ex.ToString());
            }
        }
        private void lb_Learn_Tool_TextChanged(object sender, EventArgs e){
            try{
                int ATC_num = int.Parse(((Label)sender).Text);
                StreamReader sr = new StreamReader(path + @"\data\ATC.cp");
                for (int i = 0; i < ATC_num; i++){
                    string tem = sr.ReadLine();
                    if (i != ATC_num - 1) continue;
                    ((Label)sender).Text = tem.Split(',')[1];
                    lb_Learn_Blade.Text = tem.Split(',')[2];
                }
                sr.Close();
                sr.Dispose();
            }
            catch (Exception ex){
                MessageBox.Show("讀取刀庫設定檔時發生錯誤。\n\nError code : \n" + ex.ToString());
            }
        }
        #endregion
        #endregion
        #region Timer事件
        private void timer_temperature_Tick(object sender, EventArgs e){
            Thread TD_FakeData = new Thread(Thermal_FakeData);
            TD_FakeData.Start();
        }

        private void timer_LNC_Tick(object sender, EventArgs e){
            LNC_GetData();
        }
        #endregion
        #region DAQ資料讀取
        private NationalInstruments.DAQmx.Task runningTask;
        private NationalInstruments.DAQmx.Task myTask;
        private AIAccelerometerSensitivityUnits sensitivityUnits;
        private AITerminalConfiguration terminalConfiguration;
        private AIExcitationSource excitationSource;
        private AICoupling inputCoupling;
        private DataTable dataTable = null;
        private DataColumn[] dataColumn = null;
        private AnalogMultiChannelReader analogInReader;
        private AsyncCallback analogCallback;
        private AnalogWaveform<double>[] data;
        private string DAQ_Now = "";    //紀錄現在資料擷取是用在何處
        private double samplesPerChannelNumeric_base = 2000;  //取樣數(基準)
        private double rateNumeric_base = 10000;  //頻率(基準)
        private double samplesPerChannelNumeric = 2000;  //取樣數
        private double rateNumeric = 10000;  //頻率
        private int Chart_max = 4000;   //波形圖樣本數
        private int average = 1;        //幾個取樣數顯示成一個點位(必須可整除取樣數)
        private double minimumValueNumeric = -5, maximumValueNumeric = 5, sensitivityNumeric = 10.01, excitationValueNumeric = 0.002;
        private void DAQPhysicalChannels(){
            physicalChannelComboBox.Items.Clear();
            physicalChannelComboBox.Items.Add("請選擇訊號輸入");
            //DAQ實體訊號輸入端點讀取
            dataTable = new DataTable();
            physicalChannelComboBox.Items.AddRange(DaqSystem.Local.GetPhysicalChannels(PhysicalChannelTypes.AI, PhysicalChannelAccess.External));
            if (physicalChannelComboBox.Items.Count > 0)
                physicalChannelComboBox.SelectedIndex = 0;
        }
        /// <summary>
        /// DAQ參數初始化
        /// </summary>
        /// <param name="DAQ">輸入目前擷取到的資料要使用的地方</param>
        private void DAQInitialize(string DAQ){
            if (runningTask == null){
                try{
                    //Match_Bool = false;
                    //DialogResult dialogResult = MessageBox.Show("此舉動將會清空原先已存在之模型設定檔\n(第一次建立模型請無視此訊息)", "警告", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
                    //if (dialogResult == DialogResult.No) return;
                    ////清空modu設定檔
                    //StreamWriter sw = new StreamWriter(path + @"\data\module.cp");
                    //sw.WriteLine();
                    //sw.Close();le
                    //參數設定
                    FFT_Reset((int)samplesPerChannelNumeric_base);    //重置傅立葉轉換最大最小值
                    DAQ_Now = DAQ;  //紀錄現在資料擷取要用的區域
                    samplesPerChannelNumeric = samplesPerChannelNumeric_base + 1; //取樣數偏移
                    rateNumeric = rateNumeric_base + 1;  //頻率偏移
                    //Module_Start = DateTime.Now;    //取得現在時間
                    //TASK設定
                    sensitivityUnits = AIAccelerometerSensitivityUnits.MillivoltsPerG;
                    terminalConfiguration = AITerminalConfiguration.Pseudodifferential;
                    excitationSource = AIExcitationSource.Internal;
                    inputCoupling = AICoupling.AC;
                    // Create a new task
                    myTask = new NationalInstruments.DAQmx.Task();
                    AIChannel aiChannel;
                    // Create a virtual channel
                    aiChannel = myTask.AIChannels.CreateAccelerometerChannel(physicalChannelComboBox.Text, "",
                        terminalConfiguration, Convert.ToDouble(minimumValueNumeric), Convert.ToDouble(maximumValueNumeric),
                        Convert.ToDouble(sensitivityNumeric), sensitivityUnits, excitationSource,
                        Convert.ToDouble(excitationValueNumeric), AIAccelerationUnits.G);
                    // Setup the input coupling
                    aiChannel.Coupling = inputCoupling;
                    // Configure the timing parameters
                    myTask.Timing.ConfigureSampleClock("", Convert.ToDouble(rateNumeric),
                        SampleClockActiveEdge.Rising, SampleQuantityMode.ContinuousSamples, (int)samplesPerChannelNumeric);
                    // Verify the Task
                    myTask.Control(TaskAction.Verify);
                    //Prepare the table for Data
                    InitializeDataTable(myTask.AIChannels, ref dataTable);

                    runningTask = myTask;
                    analogInReader = new AnalogMultiChannelReader(myTask.Stream);
                    analogCallback = new AsyncCallback(AnalogInCallback);

                    // Use SynchronizeCallbacks to specify that the object 
                    // marshals callbacks across threads appropriately.
                    analogInReader.SynchronizeCallbacks = true;
                    analogInReader.BeginReadWaveform(Convert.ToInt32(samplesPerChannelNumeric), analogCallback, myTask);

                    //if (Match_Bool == false)
                    //{
                    //    //取樣頻率偵測timer
                    //    timer_F.Enabled = true;
                    //    //設定
                    //    physicalChannelComboBox.Enabled = false;
                    //    btn_ModuleCreate.Text = "停止";
                    //    btn_ModuleCreate.BackColor = Color.Red;
                    //}
                }
                catch (DaqException exception)
                {
                    // Display Errors
                    if(exception.Error == -200431 || exception.Error == -200220){
                        MessageBox.Show("無法初始化選取的訊號輸入，請確認設定檔內的訊號輸入是否正確，\n或是檢查是否有讀取到原先所設置的訊號。", "偵測啟動失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        btn_ToolWear_Stop_Click(null, null);
                    }
                    else
                    {
                        MessageBox.Show(exception.Message);
                        TaskStop();
                        //嘗試自我修復
                        DAQInitialize(DAQ_Now);
                    }
                }
            }
        }
        /// <summary>
        /// 中斷資料擷取
        /// </summary>
        private void TaskStop(){
            // Dispose of the task
            runningTask = null;
            myTask.Dispose();
        }
        public void InitializeDataTable(AIChannelCollection channelCollection, ref DataTable data){
            int numOfChannels = channelCollection.Count;
            data.Rows.Clear();
            data.Columns.Clear();
            dataColumn = new DataColumn[numOfChannels];
            int numOfRows = (int)samplesPerChannelNumeric;
            for (int currentChannelIndex = 0; currentChannelIndex < numOfChannels; currentChannelIndex++){
                dataColumn[currentChannelIndex] = new DataColumn();
                dataColumn[currentChannelIndex].DataType = typeof(double);
                dataColumn[currentChannelIndex].ColumnName = channelCollection[currentChannelIndex].PhysicalName;
            }
            data.Columns.AddRange(dataColumn);
            for (int currentDataIndex = 0; currentDataIndex < numOfRows; currentDataIndex++){
                object[] rowArr = new object[numOfChannels];
                data.Rows.Add(rowArr);
            }
        }
        private void AnalogInCallback(IAsyncResult ar){
            try{
                if (runningTask != null && runningTask == ar.AsyncState){
                    // Read the available data from the channels
                    data = analogInReader.EndReadWaveform(ar);

                    // Plot your data here
                    dataToDataTable(data, ref dataTable);

                    analogInReader.BeginMemoryOptimizedReadWaveform(Convert.ToInt32(samplesPerChannelNumeric),
                        analogCallback, myTask, data);
                }
            }
            catch (DaqException exception)
            {
                // Display Errors
                MessageBox.Show(exception.Message);
                TaskStop();
                //if (Match_Bool == false)
                //{
                //    timer_F.Enabled = false;
                //    //自我修復
                //    btn_ModuleCreate.Text = "開始建置模型";
                //    btn_ModuleCreate.BackColor = Color.MidnightBlue;
                //    btn_ModuleCreate_Click(null, null);
                //}
            }
        }
        private List<string> tem_DT = new List<string>();
        private List<string> tem_Match_DT = new List<string>();
        //private int Match_count = 1;
        //private double range = 3; //可接受範圍 (倍率)
        //private int match_1 = 0;    //於可接受範圍內的點位數量
        //private int match_Read1 = 0; //比對數值讀取到的筆數
        private void dataToDataTable(AnalogWaveform<double>[] sourceArray, ref DataTable dataTable){
            // Iterate over channels
            int currentLineIndex = 0;
            foreach (AnalogWaveform<double> waveform in sourceArray){
                for (int sample = 0; sample < waveform.Samples.Count; ++sample){
                    if (sample == (int)samplesPerChannelNumeric - 1)
                        break;
                    dataTable.Rows[sample][currentLineIndex] = waveform.Samples[sample].Value;
                }
                currentLineIndex++;
            }
            //偵測模式下執行
            if (DAQ_Now.Equals("Match")){
                #region 偵測模式
                if (tem_Match_DT.Count > Chart_max - 1) tem_Match_DT.RemoveRange(0, ((int)samplesPerChannelNumeric - 1) / average);
                try { chart_ToolWear.Series[0].Points.Clear(); }
                catch { }
                for (int i = 0; i < (int)samplesPerChannelNumeric - 1; i++){
                    tem_Match_DT.Add(dataTable.Rows[i][0].ToString());
                }
                for (int i = 0; i < tem_Match_DT.Count; i++){
                    chart_ToolWear.Series[0].Points.AddXY(i + 1, tem_Match_DT[i]);
                }
                FFT(DAQ_Now, dataTable,(int)samplesPerChannelNumeric_base, (int)rateNumeric_base);
                #endregion
            }
            //模型建置狀態下執行
            else if (DAQ_Now.Equals("Learn")){
                #region 模型建置程式
                try{
                    FileStream File_module = File.Open(path + @"\data\module.cp", FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
                    StreamWriter sw = new StreamWriter(File_module);
                    if (tem_DT.Count > Chart_max - 1) tem_DT.RemoveRange(0, ((int)samplesPerChannelNumeric - 1) / average);
                    chart_Learn.Series[0].Points.Clear();
                    for (int i = 0; i < (int)samplesPerChannelNumeric - 1; i++){
                        try{
                            tem_DT.Add(dataTable.Rows[i][0].ToString());
                        }
                        catch { }
                    }
                    for (int i = 0; i < tem_DT.Count; i++){
                        chart_Learn.Series[0].Points.AddXY(i + 1, tem_DT[i]);
                        sw.WriteLine(tem_DT[i]);
                    }
                    sw.Close();
                    sw.Dispose();
                    File_module.Dispose();
                    FFT(DAQ_Now, dataTable, (int)samplesPerChannelNumeric_base, (int)rateNumeric_base);
                }
                catch { }
                #endregion
            }
        }
        #endregion
        #region 傅立葉變換
        private List<string> List_FFT_Max = new List<string>();
        //private int FFT_Length = 2000;
        private void FFT_Reset(int sample){
            List_FFT_Max.Clear();
            for (int i = 0; i < sample / 2; i++){
                List_FFT_Max.Add("-99");
            }
            if(FFT_TemPoint.Columns.Count == 0)FFT_TemPoint.Columns.Add("Z");
        }
        private DataTable FFT_TemPoint = new DataTable();
        /// <summary>
        /// 傅立葉轉換
        /// </summary>
        private void FFT(string mode,DataTable dt,double sample, double rate){
            //
            // Simple example to compute a forward 1D real 1024 point FFT
            //
            
            try{
                chart_FFT.Series[3].Points.Clear();
                chart_LearnFFT.Series[0].Points.Clear();
            }
            catch (Exception ex){
                MessageBox.Show("發生不可測意外。\n\nFFT\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            //double[] fund = Generate.Sinusoidal((int)samplesPerChannelNumeric_base, (int)rateNumeric_base, 60, 10, 0);
            Complex[] samples = new Complex[(int)sample];
            for (int i = 0; i < sample; i++)
                samples[i] = new Complex(double.Parse(dt.Rows[i][0].ToString()), 0);
            Fourier.Forward(samples, FourierOptions.NoScaling);
            //判斷轉速(如果機台未連線，設為預設2500)
            if (machine_connect == false)
                ATC_RPM = 2500;
            //判斷模式
            string tem_path = "";
            if (mode.Equals("Learn")) tem_path = path + @"\data\FFT\L-" + lb_Learn_WorkName.Text + Learn_Axial + "-" + ATC_Status + "_" + (int)ATC_RPM + ".cp";
            else if (mode.Equals("Match")){
                for (int i = 0; i < ToolWear_bool.Length; i++)
                    if (ToolWear_bool[i] == true)
                        tem_path = path + @"\data\FFT\M-" + lb_ToolWear_Parts.Text + (i + 1).ToString("00") + "-" + ATC_Status + "_" + (int)ATC_RPM + ".cp";
            }
            //先讀取目前刀具的最大值檔案
            try{
                StreamReader sr = new StreamReader(tem_path);
                int count = 0;
                //sr.ReadLine();  //先將第一行設定檔讀出來
                while (!sr.EndOfStream){
                    List_FFT_Max[count] = sr.ReadLine();
                    count++;
                }
                sr.Close();
                sr.Dispose();
            }
            catch {
                //如果進到catch就表示目前沒有此刀具的檔案
            }
            for (int i = 0; i < sample / 2; i++){
                double mag = (4.0 / sample) * (Math.Abs(Math.Sqrt(Math.Pow(samples[i].Real, 2) +
                    Math.Pow(samples[i].Imaginary, 2))));
                double hz = rate / sample;
                //if (mag < 0.5) mag *= 0.2f;
                //在2000hz以下才畫圖
                if(hz * (i + 1) < 2000){
                    if (mode.Equals("Match")) chart_FFT.Series[3].Points.AddXY(hz * (i + 1), mag);
                    else if (mode.Equals("Learn")) chart_LearnFFT.Series[0].Points.AddXY(hz * (i + 1), mag);
                    //chart_FFT.Series[3].Points.AddXY(i + 1, fftresult.DataBlock.Data[i] / 100);
                }
                //找尋最大值
                if (mag > double.Parse(List_FFT_Max[i]))
                    List_FFT_Max[i] = mag.ToString();
            }
            //寫檔
            StreamWriter sw_Max = new StreamWriter(tem_path);
            for (int i = 0; i < List_FFT_Max.Count; i++){
                if(!List_FFT_Max[i].Equals("-99"))
                    sw_Max.WriteLine(List_FFT_Max[i]);
            }
            sw_Max.Close();
            sw_Max.Dispose();
            
            //在偵測模式下才進行判斷
            if (mode.Equals("Match")){
                //刃數比對
                Blade_Comparison(sample, rate);

                //警戒值判斷
                ToolWear_Log(dt, sample, rate);

            }
        }
        #endregion
        #region 寶元資料讀取
        //暫存LNC資料
        List<string> LNC_Data = new List<string>();

        //寶元用變數
        ushort gNid;
        private Queue<TDData> dataQueue = new Queue<TDData>(1000);
        struct TDData{
            public short x;
            public short y;
            public short z;
        };
        //搜尋裝置
        private void LNC_Scan(){
            ushort i = 0;
            short rc = 0;
            int existCnt = 0;
            gNid = 0;

            byte commSts = 0, sensorSTS = 0;
            int watchdogCnt = 0;
            //取得連線狀態
            rc = CLNCc.lnc_get_status(gNid, ref commSts, ref sensorSTS, ref watchdogCnt);
            if(commSts != 3){
                StringBuilder name = new StringBuilder(16);
                StringBuilder ip = new StringBuilder(16);

                rc = CLNCc.lnc_get_controller_cnt(ref existCnt);

                rc = CLNCc.lnc_get_controller_info(i, name, ip);

                if (name.Length != 0){
                    string s_ip = ip.ToString();
                    //連線裝置
                    CLNCc.lnc_connect(gNid, s_ip, 0);

                    //先歸零感測器
                    rc = 0;
                    rc = CLNCc.lnc_svi_set_zero(gNid);

                    //加入channel
                    physicalChannelComboBox.Items.Add("LNC-" + name.ToString());
                }
            }
        }
        //LNC連結
        private void LNC_Connect(){
            ushort i = 0;
            short rc = 0;
            int existCnt = 0;
            gNid = 0;

            byte commSts = 0, sensorSTS = 0;
            int watchdogCnt = 0;
            //取得連線狀態
            rc = CLNCc.lnc_get_status(gNid, ref commSts, ref sensorSTS, ref watchdogCnt);
            if (commSts != 3){
                StringBuilder name = new StringBuilder(16);
                StringBuilder ip = new StringBuilder(16);

                rc = CLNCc.lnc_get_controller_cnt(ref existCnt);

                rc = CLNCc.lnc_get_controller_info(i, name, ip);

                if (name.Length != 0){
                    string s_ip = ip.ToString();
                    //連線裝置
                    CLNCc.lnc_connect(gNid, s_ip, 0);

                    //先歸零感測器
                    rc = 0;
                    rc = CLNCc.lnc_svi_set_zero(gNid);
                }
            }
        }
        //暫存LNC資料
        DataTable dt_LNC = new DataTable();
        //取得LNC資料
        private void LNC_GetData(){
            ushort i = 0;
            short rc = 0;
            byte commSts = 0, sensorSTS = 0;
            int watchdogCnt = 0;
            //取得連線狀態
            rc = CLNCc.lnc_get_status(gNid, ref commSts, ref sensorSTS, ref watchdogCnt);
            //當狀態=3時(連線中)才執行取值程式
            if (commSts == 3){
                //截取資料
                uint TDLength = 0, numTD = 0;

                rc = CLNCc.lnc_svi_get_td_data_length(gNid, ref TDLength);
                if (TDLength != 0){
                    //如果存值>1000筆資料，重置Datatable
                    if(dt_LNC.Rows.Count >= 1000){
                        dt_LNC = new DataTable();
                        dt_LNC.Columns.Add("Z");
                    }

                    //txtTDLen.Text = TDLength.ToString();
                    short[] parrTDData = new short[TDLength];

                    rc = CLNCc.lnc_svi_get_td_data(gNid, TDLength, ref parrTDData[0], ref numTD);

                    //TDData td;
                    if (LNC_Data.Count >= Chart_max)
                        LNC_Data.RemoveRange(0, 500);
                    for (i = 0; i < numTD; i += 3){
                        //if (dataQueue.Count > 1000)
                        //  dataQueue.Dequeue();

                        //td.x = parrTDData[i];
                        //td.y = parrTDData[i + 1];
                        //td.z = parrTDData[i + 2];
                        dt_LNC.Rows.Add(parrTDData[i].ToString());
                        LNC_Data.Add(parrTDData[i].ToString());
                        
                        //dataQueue.Enqueue(td);
                    }
                    chart_ToolWear.Series[0].Points.Clear();
                    for (i = 0; i < LNC_Data.Count; i++)
                        chart_ToolWear.Series[0].Points.AddXY((i + 1), LNC_Data[i]);
                    //chart_ToolWear.Series[0].Points.AddXY((i + 1), dataQueue.ElementAt(i).x);

                    if (dt_LNC.Rows.Count >= 1000)
                        FFT("Match", dt_LNC, 100, 1000);
                }
                //else
                //{
                //    //將sensor接收重新打開
                //    rc = CLNCc.lnc_svi_enable(gNid, 0);
                //    rc = CLNCc.lnc_svi_enable(gNid, 1);

                //}

                //float max = 0;
                //int maxFq = 0;
                //float[] arrFDData;
                //int fdLength = 0;

                //fdLength = CLNCc.LNC_FD_DATA_LENGTH_1D66K;

                //arrFDData = new float[fdLength];

                //rc = CLNCc.lnc_svi_get_fd_data(gNid, ref arrFDData[0]);

                //if (rc == CLNCc.LNC_ERR_NO_ERROR)
                //{
                //    chart_FFT.Series[0].Points.Clear();

                //    for (i = 0; i < fdLength; i++)
                //    {
                //        if (arrFDData[i] > max)
                //        {
                //            max = arrFDData[i];
                //            maxFq = i + 1;
                //        }
                //        chart_FFT.Series[0].Points.AddXY((i + 1), arrFDData[i]);
                //    }
                //}
            }
        }
        #endregion
        #region 螢幕截圖
        /// <summary>
        /// 螢幕截圖
        /// </summary>
        private void PrintScreen(){
            Bitmap myImage = new Bitmap(this.Width, this.Height);
            Graphics g = Graphics.FromImage(myImage);
            g.CopyFromScreen(new Point(this.Location.X, this.Location.Y), new Point(0, 0), new Size(this.Width, this.Height));
            IntPtr dc1 = g.GetHdc();
            g.ReleaseHdc(dc1);
            myImage.Save(path + @"\screen1.jpg");
        }
        #endregion
        #region 控制器讀取
        #region 三菱
        long lRet;
        DispEZNcCommunication EZNcCom = new DispEZNcCommunication();
        /// <summary>
        /// 三菱控制器初始化
        /// </summary>
        private long Mitsubishi_Initialization(){
            int lSystemType = 9;
            int lMachine = 1;
            int lTimeOut = 100;
            lRet = EZNcCom.SetTCPIPProtocol(tb_setting_ip.Text, 683);
            lRet = EZNcCom.Open2(lSystemType, lMachine, lTimeOut, "EZNC_LOCALHOST");
            if (lRet == 0)
                machine_connect = true;
            else
                machine_connect = false;
            return lRet;
        }
        //暫存刀具編號
        private int ATC_Status = 0;
        /// <summary>
        /// 三菱控制器 > 取得自動換刀裝置目前使用刀號
        /// </summary>
        /// <returns>目前刀號</returns>
        private int Mitsubishi_GetATCStatus(){
            if (machine_connect == false) return -1;
            int ATC_NUM = 0;
            if (lRet == 0){
                //取得目前使用刀號
                lRet = EZNcCom.ATC_GetMGNReady(0, out ATC_NUM);
                if (lRet == 0)
                    return ATC_NUM;
                else
                    CatchLog(1001, lRet.ToString());
            }
            lRet = EZNcCom.Close();
            EZNcCom = null;
            return 0;
        }
        /// <summary>
        /// 三菱控制器 > 取得機台狀態
        /// </summary>
        /// <returns>目前狀態</returns>
        private string Mitsubishi_GetRunStatus(){
            if (machine_connect == false) return "NotConnect";
            string[] s_status = new string[3] { "Run", "Start", "Alarm" };
            int status = 0;
            if(lRet == 0){
                lRet = EZNcCom.Status_GetRunStatus(2, out status);
                if (lRet == 0)
                    return s_status[status];
                else
                    CatchLog(1002, lRet.ToString());
            }
            lRet = EZNcCom.Close();
            EZNcCom = null;
            return "";
        }
        //暫存轉速
        double ATC_RPM = 0;
        /// <summary>
        /// 取得目前轉速
        /// </summary>
        /// <returns>轉速(RPM)</returns>
        private double Mitsubishi_GetFeedSpeed(){
            if (machine_connect == false) return -1;
            int lFeedType = 0;
            double pdSpeed = 0;
            if(lRet == 0){
                lRet = EZNcCom.Position_GetFeedSpeed(lFeedType, out pdSpeed);
                if (lRet == 0)
                    return pdSpeed;
                else
                    CatchLog(1003, lRet.ToString());
            }
            lRet = EZNcCom.Close();
            EZNcCom = null;
            return 0;
        }
        #endregion
        #endregion
        #region 例外事件
        private void CatchLog(int code,string detail){
            string catch_log = "";
            switch (code){
                case 1000:
                    catch_log = "CNC機台連線失敗";
                    break;
                case 1001:
                    catch_log = "取得刀號失敗";
                    break;
                case 1002:
                    catch_log = "取得機台狀態失敗";
                    break;
                case 1003:
                    catch_log = "取得進給率失敗";
                    break;
            }
            MessageBox.Show(catch_log + "\n錯誤代碼：" + code + "\n資訊：" + detail);
        }
        #endregion
        #region Log事件表
        //寫入新的Log
        private void Write_Log(string Title, string Detial){
            FileStream File_module = File.Open(path + @"\data\Log\" + DateTime.Now.ToString("yyyyMMdd") + ".cp", FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
            StreamWriter sw = new StreamWriter(File_module);
            sw.WriteLine(DateTime.Now.ToString("HH:mm:ss") + "-" + Title + "," + Detial);
            sw.Close();
            sw.Dispose();
            Read_Log(DateTime.Now.ToString("yyyyMMdd"));
        }
        //讀取帶入日期的Log事件表
        private List<string> Read_Log(string date){
            List<string> tem_read = new List<string>();
            try{
                StreamReader sr_log = new StreamReader(path + @"\data\Log\" + date + ".cp");
                while (!sr_log.EndOfStream){
                    tem_read.Add(sr_log.ReadLine());
                }
                sr_log.Close();
                sr_log.Dispose();
            }
            catch {
                //會產生例外表示沒有檔案，直接生成一個
                StreamWriter sw = new StreamWriter(path + @"\data\Log\" + DateTime.Now.ToString("yyyyMMdd") + ".cp");
                sw.Write("");
                sw.Close();
                sw.Dispose();
            }
            //顯示LOG資料
            try{
                TextBox[] TB_LogTitle = new TextBox[4] { tb_logTitle_01 , tb_logTitle_02 , tb_logTitle_03 , tb_logTitle_04 };
                TextBox[] TB_LogDetial = new TextBox[4] { tb_logDetail_01 , tb_logDetail_02 , tb_logDetail_03 , tb_logDetail_04 };
                //讀取資料範例 18:29:36-警告,溫度上升至40度
                //如果LOG超過4筆，取最後4筆
                if (tem_read.Count >= 4){
                    for(int i = tem_read.Count - 1; i >= 0; i--){
                        if (i == tem_read.Count - 5) break; //表示已經讀取完四筆最新LOG訊息
                        TB_LogTitle[tem_read.Count - i - 1].Text = tem_read[i].Split('-')[1].Split(',')[0];
                        TB_LogDetial[tem_read.Count - i - 1].Text = "  " + tem_read[i].Split('-')[0] + "  " + tem_read[i].Split('-')[1].Split(',')[1];
                    }
                }
                else{
                    for(int i = 0; i < tem_read.Count; i++){
                        TB_LogTitle[tem_read.Count - i - 1].Text = tem_read[i].Split('-')[1].Split(',')[0];
                        TB_LogDetial[tem_read.Count - i - 1].Text = "  " + tem_read[i].Split('-')[0] + "  " + tem_read[i].Split('-')[1].Split(',')[1];
                    }
                }
            }
            catch {
                MessageBox.Show("Log顯示錯誤", "顯示錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            return tem_read;
        }
        //視窗底部Log TextBox事件
        private void tb_logTitle_TextChanged(object sender, EventArgs e){
            //暫存現在文字被修改的TextBox
            TextBox ThisTB = ((TextBox)sender);
            //取得此TextBox的ID是多少
            int TB_ID = int.Parse(ThisTB.Name.Split('_')[2]);
            TextBox[] TB_Detial = new TextBox[4] { tb_logDetail_01, tb_logDetail_02, tb_logDetail_03, tb_logDetail_04 };
            //暫存跟隨此Title的Detail TextBox是哪一個
            TextBox DetialTB = TB_Detial[TB_ID - 1];
            switch (ThisTB.Text){
                case "緊急":
                    ThisTB.ForeColor = Color.White;
                    DetialTB.ForeColor = Color.White;
                    ThisTB.BackColor = Color.FromArgb(227, 70, 70);
                    DetialTB.BackColor = Color.FromArgb(227, 70, 70);
                    break;
                case "警告":
                    ThisTB.ForeColor = Color.Black;
                    DetialTB.ForeColor = Color.Black;
                    ThisTB.BackColor = Color.FromArgb(255, 187, 0);
                    DetialTB.BackColor = Color.FromArgb(255, 187, 0);
                    break;
                case "系統":
                    ThisTB.ForeColor = Color.Black;
                    DetialTB.ForeColor = Color.Black;
                    ThisTB.BackColor = Color.White;
                    DetialTB.BackColor = Color.White;
                    break;
                default:
                    ThisTB.ForeColor = Color.White;
                    DetialTB.ForeColor = Color.White;
                    ThisTB.BackColor = Color.FromArgb(15, 60, 96);
                    DetialTB.BackColor = Color.FromArgb(15, 60, 96);
                    break;
            }
        }
        #endregion
        #region 螢幕鍵盤
        //顯示屏幕鍵盤
        public void ShowInputPanel(){
            try{
                Process[] proc = Process.GetProcessesByName("TabTip");
                if (proc.Length > 0)
                    proc[0].Kill(); //關閉執行中的螢幕鍵盤，以防無法開啟
                dynamic file = "C:\\Program Files\\Common Files\\microsoft shared\\ink\\TabTip.exe";
                if (!System.IO.File.Exists(file))
                    return;
                Process.Start(file);
            }
            catch (Exception ex){
                MessageBox.Show("無法開啟螢幕鍵盤。", "鍵盤無法啟用", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //關閉屏幕鍵盤
        public void CloseInputPanel(){
            Process[] proc = Process.GetProcessesByName("TabTip");
            if (proc.Length > 0)
                proc[0].Kill(); //關閉執行中的螢幕鍵盤，以防無法開啟
        }
        //顯示鍵盤觸發方法
        private void ShowInputPanel_Click(object sender,EventArgs e){
            ShowInputPanel();
        }
        //關閉鍵盤觸發方法
        private void CloseInputPanel_Click(object sender, EventArgs e){
            CloseInputPanel();
        }
        #endregion
    }
}
