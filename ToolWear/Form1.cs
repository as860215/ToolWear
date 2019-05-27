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
using System.Text;
using LNCcomm;
using System.Linq;
using EasyModbus;
using System.Management;
using System.IO.Compression;
using System.ComponentModel;
using Campro;

namespace ToolWear{
    public partial class Form1 : Form {
        #region 全域參數宣告
        private string path = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase;  //執行檔位置
        private char[] Unlawful = new char[2] { ',', ':' }; //非法字元
        private bool machine_connect = false;   //是否有連線機台
        private string machine_type = "";   //機台廠牌
        private Alarm_Mode Alarm = 0;     //發生異警時的處理方式
        #endregion
        #region 列舉定義
        /// <summary>
        /// Alarn設定 > 停止模式定義
        /// </summary>
        private enum Alarm_Mode {
            Flash = 0,
            Delay = 1,
            None = 2,
        }
        #endregion
        #region 初始化
        #region 物件初始化
        public Form1() {
            InitializeComponent();
            Brother_Initialization();
            //將視窗最大化
            //this.WindowState = FormWindowState.Maximized;
            //隱藏工作列
            this.FormBorderStyle = FormBorderStyle.None;
            //強制置頂視窗
            //this.TopMost = true;
        }
        private void Form1_Shown(object sender, EventArgs e) {
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
        private void Setting() {
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
            chart_Current.Legends.Clear();
            chart_Health.Legends.Clear();
            chart_Health_FFT.Legends.Clear();
            chart_Health_Match.Legends.Clear();
            chart_HealthResult_AfterSale.Legends.Clear();
            chart_HealthResult_Factory.Legends.Clear();
            chart_prediction_X.Legends.Clear();
            chart_prediction_Y.Legends.Clear();
            chart_prediction_Z.Legends.Clear();
            chart_AccCur_X.Legends.Clear();
            chart_AccCur_Y.Legends.Clear();
            chart_AccCur_Z.Legends.Clear();
            chart_AccCur_Current.Legends.Clear();
            chart_AE.Legends.Clear();
            //折線圖上下限與x軸最大值預覽
            chart_Learn.Series[1].Points.AddXY(1, Chart_PointMax);
            chart_ToolWear.Series[1].Points.AddXY(1, Chart_PointMax);
            chart_warring_1.Series[1].Points.AddXY(1, Chart_PointMax);
            chart_warring_2.Series[1].Points.AddXY(1, Chart_PointMax);
            //震動偵測折線圖
            for (int i = 0; i < Chart_max; i++) {
                chart_Learn.Series[2].Points.AddXY(i + 1, Chart_PointMin);
                chart_ToolWear.Series[2].Points.AddXY(i + 1, Chart_PointMin);
                chart_Health.Series[2].Points.AddXY(i + 1, Chart_PointMin);
            }
            //警戒折線圖
            for (int i = 0; i < 2000; i++) {
                chart_warring_1.Series[1].Points.AddXY(i + 1, Chart_PointMin);
                chart_warring_2.Series[1].Points.AddXY(i + 1, Chart_PointMin);
            }
            //FFT折線圖
            for (int i = 0; i < 100; i++) {
                chart_FFT.Series[1].Points.AddXY(i + 1, 0.1);
                chart_LearnFFT.Series[1].Points.AddXY(i + 1, 0.1);
                chart_Blade.Series[1].Points.AddXY(i + 1, 0.1);
                chart_Health_FFT.Series[1].Points.AddXY(i + 1, 0.1);
                chart_Health_Match.Series[1].Points.AddXY(i + 1, 0.1);
                chart_HealthResult_AfterSale.Series[1].Points.AddXY(i + 1, 0.1);
                chart_HealthResult_Factory.Series[1].Points.AddXY(i + 1, 0.1);
            }
            //溫度折線圖
            for (int i = 1; i <= 30; i++) {
                chart_Thermal.Series[1].Points.AddXY(i, 25);
                chart_Thermal_M1.Series[1].Points.AddXY(i, 25);
                chart_Thermal_M2.Series[1].Points.AddXY(i, 25);
            }

            //電流
            for (int i = 0; i < 200; i++) {
                chart_Current.Series[2].Points.AddXY(i + 1, 0);
            }

            //磨耗偵測(三軸、電流)
            for (int i = 0; i < 2000; i++) {
                chart_AccCur_X.Series[1].Points.AddXY(i + 1, 0);
                chart_AccCur_Y.Series[1].Points.AddXY(i + 1, 0);
                chart_AccCur_Z.Series[1].Points.AddXY(i + 1, 0);
                chart_AccCur_Current.Series[1].Points.AddXY(i + 1, 0);
            }
            //音頻偵測
            for (int i = 0; i < 2000; i++)
                chart_AE.Series[1].Points.AddXY(i + 1, 0);

            //Panel
            panel_Home.Visible = true;
        }
        /// <summary>
        /// 隱藏所有panel(主畫面除外)
        /// </summary>
        private void panel_Dissable() {
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
            panel_Health_Setting.Visible = false;
            panel_Health_Result.Visible = false;
            panel_SelectParts.Visible = false;
            panel_AddParts.Visible = false;
            panel_AlarmSetting.Visible = false;
            panel_prediction.Visible = false;
            panel_AccCur.Visible = false;
            panel_AccCur_setting.Visible = false;
            panel_AE.Visible = false;
            panel_AccCur_parameter.Visible = false;
            //關閉所有主選單副組件
            btn_Learn.Enabled = false;
            btn_ChangeMode.Enabled = false;
            btn_ChangeMode0.Enabled = false;
            btn_ChangeMode2.Enabled = false;
            btn_ChangeMode3.Enabled = false;
            //重置所有主選單副組件顯示圖片
            btn_Learn.BackgroundImage = ToolWear.Properties.Resources.tc_menubtn_blank;
            btn_ChangeMode.BackgroundImage = ToolWear.Properties.Resources.tc_menubtn_blank;
            btn_ChangeMode0.BackgroundImage = ToolWear.Properties.Resources.tc_menubtn_blank;
            btn_ChangeMode2.BackgroundImage = ToolWear.Properties.Resources.tc_menubtn_blank;
            btn_ChangeMode3.BackgroundImage = ToolWear.Properties.Resources.tc_menubtn_blank;
        }
        /// <summary>
        /// 初始化資料
        /// </summary>
        private void Initialization() {
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
                while (!sr_axial.EndOfStream) {
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
            try {
                StreamReader sr_thermal = new StreamReader(path + @"\data\thermal.cp");
                while (!sr_thermal.EndOfStream) {
                    string axial = sr_thermal.ReadLine().Split(',')[0];
                    btn_Compensate[count].Text = axial;
                    btn_Thermal[count].Text = axial;
                    count++;
                }
                sr_thermal.Close();
                sr_thermal.Dispose();
            }
            catch {
                tb_Load_log.Text += "讀取不到熱補償資料。\n";
            }

            //Alarm設定
            try {
                StreamReader sr_AlarmSet = new StreamReader(path + @"\data\alarm_set.cp");
                string tem_s = sr_AlarmSet.ReadLine();
                sr_AlarmSet.Close();
                sr_AlarmSet.Dispose();
                //分割設定檔內容
                //停止模式
                if (tem_s.Split(',')[0].Equals("Flash")) btn_AlarmMode_Flash_Click(null, null);
                else if (tem_s.Split(',')[0].Equals("Delay")) btn_AlarmMode_Delay_Click(null, null);
                else if (tem_s.Split(',')[0].Equals("None")) btn_AlarmMode_None_Click(null, null);
                //廠牌現在只有施耐德

                //讀取ip
                tb_AlarmMethod_IP.Text = tem_s.Split(',')[2];
            }
            catch {
                tb_Load_log.Text += "Alarm設定資料錯誤。\n";
            }

            //主畫面 > 設定
            setting_load(false);

            //讀取今日Log事件表
            Read_Log(DateTime.Now.ToString("yyyyMMdd"));
        }
        /// <summary>
        /// 讀取系統資料
        /// </summary>
        private void System_Load() {
            string tem_s = "";
            try {
                //讀取軟體版本資料
                StreamReader sr_version = new StreamReader(path + @"\data\version.cp");
                string tem_version = sr_version.ReadLine();
                sr_version.Close();
                sr_version.Dispose();
                tem_s += string.Format("軟體版本\r\n{0}\r\n\r\n", tem_version);

                //取得.NET版本
                tem_s += string.Format(".NET版本\r\n{0}\r\n\r\n", Environment.Version.ToString());

                //取得CPU資料
                ManagementClass mc = new ManagementClass("Win32_Processor");
                ManagementObjectCollection moc = mc.GetInstances();
                string CPUName = null;    //CPU名稱
                foreach (ManagementObject mo in moc) {
                    CPUName = mo.Properties["Name"].Value.ToString().Trim();
                    break;
                }
                tem_s += string.Format("CPU\r\n{0}\r\n\r\n", CPUName);

                //取得記憶體資料
                string Memory = null;   //記憶體大小
                ManagementObjectSearcher search = new ManagementObjectSearcher("Select * From Win32_PhysicalMemory");
                UInt64 total = 0;
                foreach (ManagementObject ram in search.Get())
                    total += (UInt64)ram.GetPropertyValue("Capacity");
                Memory = (total / 1048576).ToString();
                tem_s += string.Format("記憶體\r\n{0} MB\r\n\r\n", Memory);

                //取得電腦名稱與IP
                String strHostName = System.Net.Dns.GetHostName();                                     //先讀取本機名稱
                tem_s += string.Format("主機名稱\r\n{0}\r\n\r\n", strHostName);
                System.Net.IPHostEntry iphostentry = System.Net.Dns.GetHostByName(strHostName);   //取得本機的 IpHostEntry 類別實體
                string ip = "";
                foreach (System.Net.IPAddress ipaddress in iphostentry.AddressList) {
                    ip += ipaddress.ToString();
                    break;  //只讀一個IP
                }
                tem_s += string.Format("主機IP\r\n{0}\r\n\r\n", ip);

                tb_setting_System.Text = tem_s;
            }
            catch (Exception ex) {
                MessageBox.Show("讀取系統資料時發生錯誤。\n\nSystem_Load\n\n" + ex.ToString(), "讀取失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        #endregion
        #region 背景讀取
        //讀取階段
        int Load_Step = 0;
        //正在讀取
        bool is_Load = false;
        //讀取程式計時器
        private void timer_load_Tick(object sender, EventArgs e) {
            bar_load.Value = Load_Step;
            void_Loading(Load_Step);
        }
        /// <summary>
        /// 讀取程式
        /// </summary>
        /// <param name="push_in_step">為避免因多執行續造成的變數變化問題，在執行switch之前先暫存其</param>
        private void void_Loading(int push_in_step) {
            int tem_step = push_in_step;
            if (tem_step != Load_Step) return;
            //如果有別的執行續已經進入讀取階段了就return
            if (is_Load == true) return;
            string tem = "";
            is_Load = true;
            switch (tem_step) {
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
                //保留1~2備用
                //保留3~20初始化元件
                case 3:
                    tem = "正在搜尋DAQ訊號輸入...";
                    break;
                case 4:
                    Thread TD_DAQChannel = new Thread(DAQPhysicalChannels);
                    TD_DAQChannel.Start();
                    btn_AccCur_setting_loadChannel(null, null);
                    tem = "DAQ訊號輸入搜尋完畢";
                    break;
                case 5:
                    tem = "正在初始化元件屬性...";
                    break;
                case 6:
                    Initialization();
                    tem = "元件初始化完畢";
                    break;
                case 7:
                    tem = "正在設定元件屬性...";
                    break;
                case 8:
                    Setting();
                    tem = "元件屬性設定完畢";
                    break;
                case 9:
                    tem = "正在掃描LNC訊號...";
                    break;
                case 10:
                    LNC_Scan();
                    tem = "LNC訊號掃描完畢";
                    break;
                //保留20~80測試設備連線
                case 20:
                    tem = "正在測試控制器連線...";
                    break;
                case 25:
                    //測試連線
                    switch (cb_setting_brand.Text) {
                        case "Mitsubishi":
                            long ret = Mitsubishi_Initialization();
                            if (ret != 0)
                                tb_Load_log.Text += "控制器連線失敗。 Error Code : " + ret.ToString();
                            break;
                        case "Brother":
                            string br_ret = Brother_Initialization();
                            if (br_ret.Equals(""))
                                tb_Load_log.Text += "控制器連線失敗。 Error : IP或Port無法連接。";
                            break;
                        case "Fanuc":
                            short fanuc_ret = FANUC_Initialization();
                            if (fanuc_ret == 0)
                                tb_Load_log.Text += "控制器連線失敗。 Error : IP或Port無法連接。";
                            break;
                    }
                    break;
                case 26:
                    tem = "控制器連線測試完畢";
                    break;
                //保留81~94查詢系統
                case 81:
                    tem = "正在讀取系統資料...";
                    break;
                case 82:
                    System_Load();
                    tem = "系統資料讀取完畢";
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
            if (!string.IsNullOrWhiteSpace(tem)) tb_Loading.Text += tem + "\r\n";
            tb_Load_ProgressRate.Text = "讀取進度 ： " + tem_step + " %";
            Load_Step++;
            is_Load = false;
        }
        #endregion
        #endregion
        #region 按鈕方法
        #region panel設定
        private void btn_Thermal_Click(object sender, EventArgs e) {
            panel_Dissable();
            panel_Thermal.Visible = true;
            btn_Thermal_Axial_Click((object)btn_Thermal_01, null);
        }
        //磨耗偵測
        private void btn_ToolWear_Click(object sender, EventArgs e) {
            panel_Dissable();
            panel_ToolWear.Visible = true;
            //學習按鈕啟動
            btn_Learn.Enabled = true;
            btn_Learn.BackgroundImage = ToolWear.Properties.Resources.menubtn_learn_default;
            //震動/電流切換按鈕啟動
            btn_ChangeMode.Enabled = true;
            btn_ChangeMode.BackgroundImage = ToolWear.Properties.Resources.wd_menubtn_current;
            //重置偵測模式(震動/電流)
            lb_ToolWear_Title.Text = "磨耗偵測(電流)";
            btn_ChangeMode_Click(null, null);
            //刀具磨耗預測按鈕啟動
            btn_ChangeMode3.Enabled = true;
            //磨耗偵測(三軸、電流)按鈕啟動
            btn_ChangeMode0.Enabled = true;

            //預設選擇第一個按鈕
            if (pre_ToolWear == null)
                btn_ToolWear_Choose((object)btn_ToolWear_01, null);
            else
                btn_ToolWear_Choose((object)pre_ToolWear, null);
        }
        private void btn_BackHome(object sender, EventArgs e) {
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
        private void btn_ThermalSetting_Back_Click(object sender, EventArgs e) {
            panel_ThermalSetting.Visible = false;
            panel_Thermal.Visible = true;
        }
        private void btn_Threshold_Back_Click(object sender, EventArgs e) {
            panel_ToolWear.Visible = true;
            panel_Threshold.Visible = false;
            btn_Learn.BackgroundImage = ToolWear.Properties.Resources.menubtn_learn_default;
            //開啟模式切換按鈕
            btn_ChangeMode.Enabled = true;
            btn_ChangeMode.BackgroundImage = ToolWear.Properties.Resources.wd_menubtn_current;
        }
        //磨耗偵測 > 選擇工件 > 回上一頁
        private void btn_SelectParts_Back_Click(object sender, EventArgs e) {
            panel_ToolWear.Visible = true;
            panel_SelectParts.Visible = false;
        }
        //磨耗偵測 > 選擇工件
        private void pb_ToolWear_Click(object sender, EventArgs e) {
            panel_ToolWear.Visible = false;
            panel_SelectParts.Visible = true;
            lb_SelectParts_Page.Text = "1";
            SelectParts_LoadData();
        }
        //磨耗偵測 > 選擇工件 > 新增工件
        private void btn_SelectParts_Add_Click(object sender, EventArgs e) {
            panel_Dissable();
            panel_AddParts.Visible = true;
        }
        private void btn_ToolWear_Setting_Click(object sender, EventArgs e) {
            panel_ToolWearSetting.Visible = true;
            panel_ToolWear.Visible = false;
            if (pre_ToolWearSetting == null)
                btn_ToolWearSetting_Choose((object)btn_ToolWearSetting_01, null);
            else
                btn_ToolWearSetting_Choose((object)pre_ToolWearSetting, null);
        }
        //磨耗設定 > 熱補償設定
        private void btn_ThermalSetting_Click(object sender, EventArgs e) {
            panel_ThermalSetting.Visible = true;
            panel_Compensate.Visible = true;
            panel_Thermal.Visible = false;
            if (pre_Compensate == null)
                btn_Compensate_Choose((object)btn_Compensate_01, null);
            else
                btn_Compensate_Choose((object)pre_Compensate, null);
        }
        private void btn_ToolWearSetting_Back_Click(object sender, EventArgs e) {
            panel_ToolWearSetting.Visible = false;
            panel_ToolWear.Visible = true;
            btn_ToolWear_Click(null, null);
        }
        private void btn_ToolWearSetting_Learn_Click(object sender, EventArgs e) {
            //panel_ToolWearSetting.Visible = false;
            //panel_Learn.Visible = true;
        }
        private void btn_ViewModule_Back_Click(object sender, EventArgs e) {
            panel_ToolWearSetting.Visible = true;
            panel_ViewModule.Visible = false;
        }
        //主選單 > 健康診斷
        private void btn_Health_Click(object sender, EventArgs e) {
            panel_Dissable();
            panel_Health.Visible = true;
            panel_Health_Factory.Visible = true;
            panel_Health_AfterSale.Visible = false;
            lb_Health_Title.Text = "健康診斷/出廠檢測";
            btn_ChangeMode3.BackgroundImage = ToolWear.Properties.Resources.menubtn_h_after_sales_inspection;
            btn_ChangeMode3.Enabled = true;
            Health_load();
        }
        //主選單 > 健康診斷 > 設定
        private void btn_Health_Setting_Click(object sender, EventArgs e) {
            panel_Health.Visible = false;
            panel_Health_Setting.Visible = true;
        }
        //主選單 > 健康診斷 > 設定 > 回上一頁
        private void btn_HealthSetting_Back_Click(object sender, EventArgs e) {
            panel_Health_Setting.Visible = false;
            panel_Health.Visible = true;
            //清空折線圖
            chart_Health_Match.Series[0].Points.Clear();
            chart_Health_Match.Series[3].Points.Clear();
            chart_Health_FFT.Series[0].Points.Clear();
            chart_Health.Series[0].Points.Clear();
            btn_Health_Click(null, null);
            //切換成售後檢測模式
            btn_ChangeMode3_Click(null, null);
        }
        //主畫面 > 子按鈕3切換模式
        private void btn_ChangeMode3_Click(object sender, EventArgs e) {
            //健康檢測狀態
            if (panel_Health.Visible == true) {
                //如果在出場檢測
                if (panel_Health_Factory.Visible == true) {
                    panel_Health_Factory.Visible = false;
                    panel_Health_AfterSale.Visible = true;
                    lb_Health_Title.Text = "健康診斷/售後檢測";
                    btn_ChangeMode3.BackgroundImage = ToolWear.Properties.Resources.menubtn_h_factory_inspection;
                }
                //在售後檢測狀態
                else {
                    panel_Health_Factory.Visible = true;
                    panel_Health_AfterSale.Visible = false;
                    lb_Health_Title.Text = "健康診斷/出廠檢測";
                    btn_ChangeMode3.BackgroundImage = ToolWear.Properties.Resources.menubtn_h_after_sales_inspection;
                }
            }
            //刀具磨耗狀態
            else if (panel_ToolWear.Visible == true) {
                panel_Dissable();
                panel_prediction.Visible = true;
                panle_prediction_Load();
            }
        }
        //主選單 > 刀庫
        private void btn_ATCsetting_Click(object sender, EventArgs e) {
            panel_Dissable();
            panel_ATCsetting.Visible = true;
            btn_ATCSetting_Choose((object)btn_ATCsetting_01, null);
        }
        //主選單 > 設定
        private void btn_setting_Click(object sender, EventArgs e) {
            panel_Dissable();
            Bar_setting.Visible = false;
            panel_setting.Visible = true;
        }
        //主選單 > 設定 > Alarm設定
        private void btn_AlarmSet_Click(object sender, EventArgs e) {
            panel_Dissable();
            panel_AlarmSetting.Visible = true;
        }
        //主選單 > 關機
        private void btn_shutdown_Click(object sender, EventArgs e) {
            DialogResult dialogResult = MessageBox.Show("請先確認所有設定皆已儲存，否則將造成新設定遺失。", "關機警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            try {
                //啟動本地程序並執行命令
                Process.Start("Shutdown.exe", " -s -t 0");
            }
            catch (Exception ex) {
                MessageBox.Show(ex.Message);
            }
            //this.Close();
        }
        //主選單 > 磨耗偵測 > 學習模式
        private void btn_Learn_Click(object sender, EventArgs e) {
            //目前在偵測模式
            if (panel_ToolWear.Visible == true) {
                if (lb_ToolWear_Parts.Text.Equals("(未選擇)")) {
                    MessageBox.Show("尚未選擇工件，無法切換學習模式。\n請點選右方工件預覽圖或是文字，進入頁面選取此次偵測的工件。", "未選擇工件", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                if (runningTask != null) {
                    MessageBox.Show("請先停止所有軸向的磨耗偵測。\n在學習模式中禁止同時偵測磨耗資訊，以免發生不可測意外。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                lb_Learn_WorkName.Text = lb_ToolWear_Parts.Text;
                pb_Learn.BackgroundImage = pb_ToolWear.BackgroundImage;
                panel_Dissable();
                panel_Learn.Visible = true;

                //按鈕變更
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
            else if (panel_Learn.Visible == true) {
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
        //主選單 > 磨耗偵測 > 切換模式
        private void btn_ChangeMode_Click(object sender, EventArgs e) {
            //在磨耗偵測狀況下
            if (panel_ToolWear.Visible == true) {
                if (lb_ToolWear_Title.Text.Equals("磨耗偵測(震動)")) {
                    lb_ToolWear_Title.Text = "磨耗偵測(電流)";
                    btn_ChangeMode.BackgroundImage = ToolWear.Properties.Resources.wd_menubtn_vibration;
                    chart_Current.Visible = true;
                    chart_Current.BringToFront();
                }
                else {
                    lb_ToolWear_Title.Text = "磨耗偵測(震動)";
                    btn_ChangeMode.BackgroundImage = ToolWear.Properties.Resources.wd_menubtn_current;
                    chart_Current.Visible = false;
                    chart_Current.SendToBack();
                }
            }
            //在磨耗偵測(三軸、電流)狀態下
            if (panel_AccCur.Visible == true) {
                TaskStop();
                panel_Dissable();
                panel_AE.Visible = true;
            }
        }
        //主選單 > 磨耗偵測 > 切換模式0
        private void btn_ChangeMode0_Click(object sender, EventArgs e) {
            //在磨耗偵測狀態下(開啟三軸、電流)
            if (panel_ToolWear.Visible == true) {
                panel_Dissable();
                panel_AccCur.Visible = true;

                //開啟子功能項
                btn_ChangeMode.Enabled = true;
                btn_ChangeMode.BackgroundImage = ToolWear.Properties.Resources.tc_menubtn_blank;
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
        private void btn_ToolWear_Start_Click(object sender, EventArgs e) {
            if (lb_ToolWear_Parts.Text.Equals("(未選擇)")) {
                MessageBox.Show("尚未選擇工件，無法進行磨耗偵測。\n請點選下方工件預覽圖或是文字，進入頁面選取此次偵測的工件。", "未選擇工件", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            Module_FFT.Clear();
            chart_FFT.Series[0].Points.Clear();
            //檢查data內是否已有此工件的學習模型
            //查詢目錄
            string[] dirs = Directory.GetFiles(path + @"data\FFT\");/*目錄(含路徑)的陣列*/
            List<string> tem_path = new List<string>();
            foreach (string s in dirs) {
                //ex L-abc01-1_2500.cp
                string file = Path.GetFileNameWithoutExtension(s).Split('_')[0];
                string remove_rate = file.Split('-')[0] + "-" + file.Split('-')[1];
                if (remove_rate.Equals("L-" + lb_ToolWear_Parts.Text + pre_ToolWear.Name.Split('_')[2]))
                    tem_path.Add(Path.GetFileNameWithoutExtension(s));
            }
            if (tem_path.Count == 0) {
                //如果長度為0就是找不到檔案，也就是沒有學習過
                MessageBox.Show("對不起，" + lb_ToolWear_Parts.Text + " 此軸向並未找到學習模型，\n請點選左方功能表「學習模式」進行模型建構。" +
                    "\n\nbtn_ToolWear_Start_Click\n\n", "尚未建構模型", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }


            //判斷是否要讀取電流資訊
            if (!string.IsNullOrWhiteSpace(tb_ToolWear_CurrentIP.Text)) {
                Current_Connect();
                if (modbusClient.Connected == true) timer_Current.Enabled = true;
            }
            else {
                DialogResult dialogResult = MessageBox.Show("此軸向並未設定電流IP，繼續操作將不會對電流量進行數據探勘。\n請問要繼續嗎？",
                    "電流尚未設定", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
                if (dialogResult == DialogResult.Cancel) return;
            }

            //判斷輸入裝置然後給予頻率
            double rate = 0, sample = 0;
            if (physicalChannelComboBox.Text.Split('-')[0].Equals("LNC")) {
                rate = 1660;
                sample = 166;
            }
            else {
                rate = rateNumeric_base;
                sample = samplesPerChannelNumeric_base;
            }

            //讀取學習模型FFT資料
            StreamReader sr = new StreamReader(path + @"data\FFT\" + tem_path[0] + ".cp");
            while (!sr.EndOfStream)
                Module_FFT.Add(sr.ReadLine());
            sr.Close();
            sr.Dispose();
            double hz = rate / sample;
            for (int i = 0; i < Module_FFT.Count; i++) {
                //只畫到2000hz
                if (hz * (i + 1) >= 2000) break;
                chart_FFT.Series[0].Points.AddXY(hz * (i + 1), Module_FFT[i]);
            }
            //重置RPM訊息
            LastReload_RPM = 0;

            //修改開始與停止按鈕
            btn_ToolWear_Start.Enabled = false;
            btn_ToolWear_Stop.Enabled = true;
            chart_ToolWear.Series[0].Points.Clear();
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
            foreach (string s in tem_path) {
                string FileName = path + @"\data\FFT\" + s + ".cp";
                //查詢該刀具的資料檔是否存在
                if (File.Exists(FileName)) {
                    StreamWriter sw_FFT = new StreamWriter(FileName);
                    sw_FFT.WriteLine("0");
                    sw_FFT.Close();
                    sw_FFT.Dispose();
                }
            }
            //清空match.cp檔案
            StreamWriter sw_match = new StreamWriter(path + @"data\match.cp");
            sw_match.Write("");
            sw_match.Close();
            sw_match.Dispose();

            //Log推播訊息
            Write_Log("系統", "已啟動磨耗偵測 ： " + lb_ToolWear_Parts.Text + "/" + pre_ToolWear.Text);

            //判斷訊號輸入
            //寶元
            if (physicalChannelComboBox.Text.Split('-')[0].Equals("LNC")) {
                //LNC_Connect();
                short rc = 0;
                rc = CLNCc.lnc_svi_enable(gNid, 1);
                dt_LNC = new DataTable();
                dt_LNC.Columns.Add("Z");
                FFT_Reset(1660);
                timer_LNC.Enabled = true;
            }
            else DAQInitialize("Match");
        }
        //停止偵測
        private void btn_ToolWear_Stop_Click(object sender, EventArgs e) {
            if (runningTask != null) TaskStop();
            if (timer_LNC.Enabled == true) {
                timer_LNC.Enabled = false;
                short rc = 0;
                rc = CLNCc.lnc_svi_enable(gNid, 0);
                //rc =  CLNCc.lnc_disconnect(gNid);
            }
            timer_Current.Enabled = false;

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
        private void btn_ToolWear_Change_Click(object sender, EventArgs e) {
            if (lb_ToolWear_ChartStatus.Text.Equals("刀具頻率")) {
                chart_ToolWear.Visible = true;
                chart_FFT.Visible = false;
                chart_Blade.Visible = false;
                lb_ToolWear_ChartStatus.Text = "原始數據";
            }
            else if (lb_ToolWear_ChartStatus.Text.Equals("原始數據")) {
                chart_ToolWear.Visible = false;
                chart_FFT.Visible = true;
                chart_Blade.Visible = false;
                lb_ToolWear_ChartStatus.Text = "傅立葉數據";
            }
            else if (lb_ToolWear_ChartStatus.Text.Equals("傅立葉數據")) {
                chart_ToolWear.Visible = false;
                chart_FFT.Visible = false;
                chart_Blade.Visible = true;
                lb_ToolWear_ChartStatus.Text = "刀具頻率";
            }
        }
        //顯示臨界值
        private void btn_ToolWear_Threshold_Click(object sender, EventArgs e) {
            if (lb_ToolWear_Parts.Text.Equals("(未選擇)")) {
                MessageBox.Show("尚未選擇工件，無法查詢臨界值。\n請點選下方工件預覽圖或是文字，進入頁面選取查詢工件。", "未選擇工件", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            panel_ToolWear.Visible = false;
            panel_Threshold.Visible = true;
            Threshold_Load();
        }
        //磨耗偵測 > 設定 > DAQ訊號重新整理
        private void btn_ToolWearSetting_Research_Click(object sender, EventArgs e) {
            DAQPhysicalChannels();
            LNC_Scan();
            btn_ToolWearSetting_Choose(pre_ToolWearSetting, null);
        }
        //暫存此軸向轉速警戒值
        List<string> ToolWear_Alern = new List<string>();
        //警戒圖暫存變數
        int chart_warring_count = 0;    //要將現在的警戒圖形畫到哪一個chart上
        //暫存進入警戒時的時間(避免同一秒鐘一直輸出警戒資訊)
        DateTime Warring_Time = new DateTime();
        //磨耗偵測 > 判斷是否超出警戒值(顯示Log)
        private void ToolWear_Log(DataTable dt, double sample, double rate) {
            string Blade_FileName = "";
            ToolWear_Alern.Clear();
            if (machine_connect == false) {
                //如果未連接機台，使用預設2500轉
                try {
                    Blade_FileName = string.Format("{0}{1}-{2}_{3}", lb_ToolWear_Parts.Text, (now_Match + 1).ToString("00"),
                        ATC_num, 2500);
                    //判斷檔案是否存在
                    string tem_path = string.Format(@"{0}\data\FFT\LS-{1}.cp", path, Blade_FileName);
                    //若查不到檔案則使用預設0刀號
                    if (!File.Exists(tem_path))
                        Blade_FileName = string.Format("{0}{1}-{2}_{3}", lb_ToolWear_Parts.Text, (now_Match + 1).ToString("00"),
                            0, 2500);
                    StreamReader sr_learn = new StreamReader(string.Format(@"{0}\data\FFT\LS-{1}.cp", path, Blade_FileName));
                    while (!sr_learn.EndOfStream)
                        ToolWear_Alern.Add(sr_learn.ReadLine());
                    sr_learn.Close();
                    sr_learn.Dispose();
                }
                catch {
                    //查不到預設檔案，隨便選取一項
                    foreach (string s in Directory.GetFiles(path + @"data\FFT")) {
                        string path_s = Path.GetFileNameWithoutExtension(s);
                        if (!path_s.Split('-')[0].Equals("L")) continue;
                        if (path_s.Split('-')[1].Equals(lb_ToolWear_Parts.Text + (now_Match + 1).ToString("00"))) {
                            //ex.LS-xxx00-0_2500
                            //將前方抬頭刪掉
                            Blade_FileName = path_s.Split('-')[1] + "-" + path_s.Split('-')[2];
                            break;
                        }
                    }
                    //Write_Log("警告", "查詢不到臨界值資料。");
                    //return;
                }
                Tool_rate = 2500;
                Tool_Blade = 4;
            }
            else {
                //如果已連接機台
                try {
                    Blade_FileName = string.Format("{0}{1}-{2}_{3}", lb_ToolWear_Parts.Text, (now_Match + 1).ToString("00"),
                        ATC_num, ATC_RPM);
                    //判斷檔案是否存在
                    string tem_path = string.Format(@"{0}\data\FFT\LS-{1}.cp", path, Blade_FileName);
                    //若查不到檔案則使用預設0刀號
                    if (!File.Exists(tem_path))
                        Blade_FileName = string.Format("{0}{1}-{2}_{3}", lb_ToolWear_Parts.Text, (now_Match + 1).ToString("00"),
                            0, ATC_RPM);
                    StreamReader sr_learn = new StreamReader(string.Format(@"{0}\data\FFT\LS-{1}.cp", path, Blade_FileName));
                    while (!sr_learn.EndOfStream)
                        ToolWear_Alern.Add(sr_learn.ReadLine());
                    sr_learn.Close();
                    sr_learn.Dispose();
                }
                catch {
                    //Write_Log("警告", "查詢不到臨界值資料。");
                    return;
                }
                Tool_rate = (int)ATC_RPM;
                Tool_Blade = 4;
            }
            //刀具刃數與頻率計算公式
            double Blade_Hz = Tool_rate / 60 * Tool_Blade;
            int Blade_Hz_Mag = 1;   //頻率倍率(取1~5)
            double sum = 0;         //當前儲存點位總和
            int count = 0;          //儲存點位數量
            double Hz_min = 0, Hz_max = 0;  //暫存該頻率倍率中的最大最小值
            double hz = rate / sample;
            List<string> Blade_Module = new List<string>();

            try {
                StreamReader sr_learn = new StreamReader(string.Format(@"{0}\data\FFT\M-{1}.cp", path, Blade_FileName));
                while (!sr_learn.EndOfStream)
                    Blade_Module.Add(sr_learn.ReadLine());
                sr_learn.Close();
                sr_learn.Dispose();
            }
            catch {
                //查不到預設檔案，隨便選取一項
                foreach (string s in Directory.GetFiles(path + @"data\FFT")) {
                    string path_s = Path.GetFileNameWithoutExtension(s);
                    if (!path_s.Split('-')[0].Equals("M")) continue;
                    if (path_s.Split('-')[1].Equals(lb_ToolWear_Parts.Text + (now_Match + 1).ToString("00"))) {
                        //ex.LS-xxx00-0_2500
                        //將前方抬頭刪掉
                        Blade_FileName = path_s.Split('-')[1] + "-" + path_s.Split('-')[2];
                        break;
                    }
                }
            }
            Button[] btn_ToolWear = new Button[20] { btn_ToolWear_01, btn_ToolWear_02, btn_ToolWear_03,
                       btn_ToolWear_04,btn_ToolWear_05,btn_ToolWear_06,btn_ToolWear_07,btn_ToolWear_08,
                       btn_ToolWear_09,btn_ToolWear_10,btn_ToolWear_11,btn_ToolWear_12,btn_ToolWear_13,
                       btn_ToolWear_14,btn_ToolWear_15,btn_ToolWear_16,btn_ToolWear_17,btn_ToolWear_18,
                       btn_ToolWear_19,btn_ToolWear_20};
            for (int i = 0; i < Blade_Module.Count; i++) {
                double tem = 0;
                //上下各取10% range
                Hz_min = Blade_Hz_Mag * Blade_Hz * 0.9f;
                Hz_max = Blade_Hz_Mag * Blade_Hz * 1.1f;
                if ((i + 1) * hz > Hz_min && (i + 1) * hz < Hz_max) {
                    tem = double.Parse(Blade_Module[i]);//暫存值
                    if (tem >= 0)
                        sum += tem;
                    count++;
                }
                else if ((i + 1) * hz > Hz_max) {
                    //頻率已大於刀刃刃數頻率，將倍率提升
                    if (((sum / count) > double.Parse(ToolWear_Alern[Blade_Hz_Mag - 1])) && !ToolWear_Alern[Blade_Hz_Mag - 1].Equals("0")) {
                        //先檢查同一秒鐘有沒有觸發過預警
                        if (Warring_Time.ToString("HHmmss").Equals(DateTime.Now.ToString("HHmmss"))) return;

                        //存取現在寫入LOG檔的時間，避免同一秒重複讀寫
                        Warring_Time = DateTime.Now;

                        Write_Log("警告", string.Format("{0}軸 {1}hz~{2}hz 震動幅度超過警戒值，當前:{3}(警戒值:{4})。", btn_ToolWear[now_Match].Text, Hz_min.ToString("0.####"), Hz_max.ToString("0.####"), (sum / count).ToString("0.00##"), ToolWear_Alern[Blade_Hz_Mag - 1]));
                        List<string> tem_datatable = new List<string>();
                        for (int j = 0; j < sample; j++)
                            tem_datatable.Add(dt.Rows[j][0].ToString());
                        System.Windows.Forms.DataVisualization.Charting.Chart[] chart = new System.Windows.Forms.DataVisualization.Charting.Chart[2]
                        {chart_warring_1,chart_warring_2 };
                        Label[] lb_chart = new Label[2] { lb_ToolWear_warring_1, lb_ToolWear_warring_2 };
                        chart[chart_warring_count].Series[0].Points.Clear();
                        chart[chart_warring_count].Series[1].Points.Clear();
                        for (int j = 0; j < tem_datatable.Count; j++)
                            chart[chart_warring_count].Series[0].Points.AddXY(j + 1, tem_datatable[j]);
                        //註記折線圖標題
                        lb_chart[chart_warring_count].Text = DateTime.Now.ToString("yyyy/MM/dd HH:mm:ss");
                        chart_warring_count++;
                        if (chart_warring_count > 1) chart_warring_count = 0;   //兩張圖


                        //存放warring檔案
                        //先檢查有沒有資料夾
                        bool dir_bool = Directory.Exists(path + @"\data\Warring\" + DateTime.Now.ToString("yyyyMMdd"));
                        if (dir_bool == false) Directory.CreateDirectory(path + @"\data\Warring\" + DateTime.Now.ToString("yyyyMMdd"));
                        //寫入新的warring檔
                        StreamWriter sw = new StreamWriter(string.Format(@"{0}\data\Warring\{1}\{2}-{3}",
                            path, DateTime.Now.ToString("yyyyMMdd"), DateTime.Now.ToString("HHmmss"), Blade_FileName));
                        for (int j = 0; j < tem_datatable.Count; j++)
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
                    Blade_Hz_Mag++;
                    count = 0;
                    sum = 0;
                }
                if (Blade_Hz_Mag > 5) break;   //頻率倍率取樣數
            }
        }
        #endregion
        #region 學習模式
        //判斷是否正處於學習模式
        bool On_Learn = false;
        //存放現在學習的軸向
        string Learn_Axial = "";
        //模型學習開始
        private void btn_Learn_Start_Click(object sender, EventArgs e) {
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
            try {
                //查詢目錄
                string[] dirs = Directory.GetFiles(path + @"data\FFT");/*目錄(含路徑)的陣列*/
                List<string> tem_path = new List<string>();
                foreach (string s in dirs) {
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
            catch (Exception ex) {
                MessageBox.Show("在清除原先資料檔時發生錯誤。\n\nbtn_Learn_Start_Click\n\nError code:\n" + ex.ToString());
                return;
            }

            //判斷訊號輸入
            //寶元
            if (physicalChannelComboBox.Text.Split('-')[0].Equals("LNC")) {
                //LNC_Connect();
                short rc = 0;
                rc = CLNCc.lnc_svi_enable(gNid, 1);
                dt_LNC = new DataTable();
                dt_LNC.Columns.Add("Z");
                FFT_Reset(1660);
                timer_LNC.Enabled = true;
            }
            else DAQInitialize("Learn");
        }
        //模型學習完成
        private void btn_Learn_OK_Click(object sender, EventArgs e) {
            if (runningTask != null) TaskStop();
            if (timer_LNC.Enabled == true) {
                timer_LNC.Enabled = false;
                CLNCc.lnc_svi_enable(gNid, 0);
                CLNCc.lnc_disconnect(gNid);
            }
            btn_Learn_Start.BackgroundImage = ToolWear.Properties.Resources.btn_start_selected;
            btn_Learn_OK.BackgroundImage = ToolWear.Properties.Resources.tc_btn_stop;
            btn_Learn_Start.Enabled = true;
            btn_Learn_OK.Enabled = false;
            On_Learn = false;

            //如果sender == null，表示非按下按鈕後進入function，為例外事件所進入，因此不顯示臨界值
            if (sender == null) return;

            panel_Threshold.Visible = true;
            panel_Learn.Visible = false;
            chart_Learn.Series[0].Points.Clear();

            //同步化磨耗偵測與學習模式選取的軸向
            Button[] btn_ToolWear = new Button[20] { btn_ToolWear_01, btn_ToolWear_02, btn_ToolWear_03,
            btn_ToolWear_04,btn_ToolWear_05,btn_ToolWear_06,btn_ToolWear_07,btn_ToolWear_08,
            btn_ToolWear_09,btn_ToolWear_10,btn_ToolWear_11,btn_ToolWear_12,btn_ToolWear_13,
            btn_ToolWear_14,btn_ToolWear_15,btn_ToolWear_16,btn_ToolWear_17,btn_ToolWear_18,
            btn_ToolWear_19,btn_ToolWear_20};

            btn_ToolWear_Choose((object)btn_ToolWear[now_learn], null);

            //讀取臨界值
            Threshold_Load();
        }
        //模型學習取消
        private void btn_Learn_Cancel_Click(object sender, EventArgs e) {
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
        private void Threshold_Load() {
            List<string> Blade_Name = new List<string>();
            Blade_Name.Add("預設");
            try {
                StreamReader sr = new StreamReader(path + @"\data\ATC.cp");
                while (!sr.EndOfStream)
                    Blade_Name.Add(sr.ReadLine().Split(',')[1]);
                sr.Close();
                sr.Dispose();
            }
            catch (Exception ex) {
                MessageBox.Show("在讀取刀庫資料時發生錯誤。\n\nThreshold_Load\n\nError code:\n" + ex.ToString());
            }
            TextBox[] tb_Threshold = new TextBox[14] { tb_Threshold_01 , tb_Threshold_02 , tb_Threshold_03 , tb_Threshold_04 ,
                                             tb_Threshold_05,tb_Threshold_06,tb_Threshold_07,tb_Threshold_08,tb_Threshold_09,
                                             tb_Threshold_10,tb_Threshold_11,tb_Threshold_12,tb_Threshold_13,tb_Threshold_14};
            //清空TextBox資料
            for (int i = 0; i < tb_Threshold.Length; i++) tb_Threshold[i].Text = "";
            //存放現在寫到哪個TextBox了
            int tb_count = 0;
            try {
                //查詢目錄
                string[] dirs = Directory.GetFiles(path + @"data\FFT");/*目錄(含路徑)的陣列*/
                List<string> tem_path = new List<string>();
                //先將該工件的所有臨界值資料取出
                foreach (string s in dirs) {
                    //ex L-abc01-1_2500-set.cp
                    string file = Path.GetFileNameWithoutExtension(s).Split('_')[0];
                    string remove_rate = file.Split('-')[0] + "-" + file.Split('-')[1];
                    if (remove_rate.Equals("L-" + lb_ToolWear_Parts.Text + pre_ToolWear.Name.Split('_')[2]))
                        tem_path.Add(Path.GetFileNameWithoutExtension(s));
                }
                //填入TextBox
                int tem_pathCount = 0;  //暫存讀取目錄計數器
                foreach (string s in tem_path) {
                    tem_pathCount++;
                    if (tem_pathCount <= (int.Parse(lb_Threshold_page.Text) - 1) * 14) continue;    //如果還沒有讀到該頁數的設定檔則略過
                    else if (tem_pathCount > int.Parse(lb_Threshold_page.Text) * 14) break;
                    string FileName = path + @"\data\FFT\" + s + ".cp";
                    string Blade = s.Split('-')[2].Split('_')[0];
                    //查詢該刀具的資料檔是否存在
                    if (File.Exists(FileName)) {
                        tb_Threshold[tb_count].Text = "T" + Blade + " : " + Blade_Name[int.Parse(Blade)] + " " + s.Split('_')[1];
                        tb_count++;
                    }
                }
                //表示沒有資料
                if (tb_count == 0) {
                    tb_Threshold[0].Text = "沒有學習資料";
                    tb_Threshold[1].Text = "無法設定臨界值";
                }
            }
            catch (Exception ex) {
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
        private void Threshold_LoadBlade(object sender, EventArgs e) {
            //修改TextBox顏色
            if (pre_Blade != null) pre_Blade.BackColor = Color.WhiteSmoke;
            ((TextBox)sender).BackColor = Color.CadetBlue;
            pre_Blade = (TextBox)sender;
            if (pre_Blade.Text.Equals("")) return;
            //判斷裝置給予頻率
            double rate = 0, sample = 0;
            if (physicalChannelComboBox.Text.Split('-')[0].Equals("LNC")) {
                rate = 1660;
                sample = 166;
            }
            else {
                rate = rateNumeric_base;
                sample = samplesPerChannelNumeric_base;
            }
            double hz = rate / sample;
            List<string> Blade_Module = new List<string>();
            try {
                Blade_FileName = string.Format("{0}{1}-{2}_{3}", lb_ToolWear_Parts.Text, pre_ToolWear.Name.Split('_')[2],
                    pre_Blade.Text.Split(' ')[0].Split('T')[1], pre_Blade.Text.Split(' ')[3].Split(' ')[0]);
                StreamReader sr_learn = new StreamReader(string.Format(@"{0}\data\FFT\L-{1}.cp", path, Blade_FileName));
                while (!sr_learn.EndOfStream)
                    Blade_Module.Add(sr_learn.ReadLine());
                sr_learn.Close();
                sr_learn.Dispose();
            }
            catch (Exception ex) {
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
            for (int i = 0; i < int.Parse(pre_Blade.Text.Split(' ')[0].Split('T')[1]); i++) {
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
            try {
                StreamReader sr_set = new StreamReader(string.Format(@"{0}data\FFT\LS-{1}.cp", path, Blade_FileName));
                int sr_count = 0;
                while (!sr_set.EndOfStream) {
                    tb_Threshold_set[sr_count].Text = sr_set.ReadLine();
                    sr_count++;
                }
                sr_set.Close();
                sr_set.Dispose();
            }
            catch {
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
            for (int i = 0; i < lb_Threshold_sethz.Length; i++) {
                lb_Threshold_sethz[i].Text = "";
                lb_Threshold_setavg[i].Text = "";
            }
            for (int i = 0; i < Blade_Module.Count; i++) {
                double tem = 0;
                //上下各取10% range
                Hz_min = Blade_Hz_Mag * Blade_Hz * 0.9f;
                Hz_max = Blade_Hz_Mag * Blade_Hz * 1.1f;
                chart_Threshold.Series[Blade_Hz_Mag + 1].Points.Clear();
                //將臨界值畫在倍頻的頻段上方
                //chart_Threshold.Series[Blade_Hz_Mag + 1].Points.AddXY(Hz_min * 0.9f, tb_Threshold_set[Blade_Hz_Mag - 1].Text);
                //chart_Threshold.Series[Blade_Hz_Mag + 1].Points.AddXY(Hz_max * 1.1f, tb_Threshold_set[Blade_Hz_Mag - 1].Text);
                //將臨界值畫滿整個折線圖
                chart_Threshold.Series[Blade_Hz_Mag + 1].Points.AddXY(0, tb_Threshold_set[Blade_Hz_Mag - 1].Text);
                chart_Threshold.Series[Blade_Hz_Mag + 1].Points.AddXY(Blade_Hz * 5 * 1.1f, tb_Threshold_set[Blade_Hz_Mag - 1].Text);
                if ((i + 1) * hz > Hz_min && (i + 1) * hz < Hz_max) {
                    tem = double.Parse(Blade_Module[i]);//暫存值
                    if (tem >= 0)
                        sum += tem;
                    count++;
                }
                else if ((i + 1) * hz > Hz_max) {
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
        private void btn_Threshold_save_Click(object sender, EventArgs e) {
            TextBox[] tb_Threshold_set = new TextBox[5] { tb_Threshold_set01, tb_Threshold_set02, tb_Threshold_set03,
                                                          tb_Threshold_set04, tb_Threshold_set05};
            //先判斷輸入框是否合法
            for (int i = 0; i < tb_Threshold_set.Length; i++) {
                if (string.IsNullOrWhiteSpace(tb_Threshold_set[i].Text)) {
                    MessageBox.Show("有一個臨界值設定為空，請重新確認後再儲存。", "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                try {
                    double tem = double.Parse(tb_Threshold_set[i].Text);
                }
                catch {
                    MessageBox.Show(string.Format("{0}\n輸入框文字訊息不合法，請確認是否為數字。", tb_Threshold_set[i].Text), "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
            }
            //改寫設定檔
            try {
                StreamWriter sw_set = new StreamWriter(string.Format(@"{0}data\FFT\LS-{1}.cp", path, Blade_FileName));
                for (int i = 0; i < 5; i++)
                    sw_set.WriteLine(tb_Threshold_set[i].Text);
                sw_set.Close();
                sw_set.Dispose();
            }
            catch (Exception ex) {
                MessageBox.Show(string.Format("改寫設定檔時發生錯誤。\nError code:\n{0}", ex.ToString()), "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            MessageBox.Show("儲存完畢", "儲存成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
            Threshold_LoadBlade((object)pre_Blade, null);
        }
        //臨界值設定 > 刪除
        private void btn_Threshold_delete_Click(object sender, EventArgs e) {
            DialogResult dialogResult = MessageBox.Show("確定要清除臨界值資料嗎？", "刪除警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            TextBox[] tb_Threshold_set = new TextBox[5] { tb_Threshold_set01, tb_Threshold_set02, tb_Threshold_set03,
                                                          tb_Threshold_set04, tb_Threshold_set05};
            try {
                StreamWriter sw_set = new StreamWriter(string.Format(@"{0}data\FFT\LS-{1}.cp", path, Blade_FileName));
                for (int i = 0; i < 5; i++)
                    sw_set.WriteLine("0");
                sw_set.Close();
                sw_set.Dispose();
            }
            catch (Exception ex) {
                MessageBox.Show(string.Format("改寫設定檔時發生錯誤。\nError code:\n{0}", ex.ToString()), "刪除失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            Threshold_LoadBlade((object)pre_Blade, null);
            MessageBox.Show("清除完畢。", "刪除成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }
        //臨界值設定 > 上一頁
        private void btn_Threshold_Up_Click(object sender, EventArgs e) {
            if (lb_Threshold_page.Text.Equals("1")) {
                MessageBox.Show("已經在第一頁了。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            lb_Threshold_page.Text = (int.Parse(lb_Threshold_page.Text) - 1).ToString();
            Threshold_Load();
        }
        //臨界值設定 > 下一頁
        private void btn_Threshold_Down_Click(object sender, EventArgs e) {
            //查詢目錄
            string[] dirs = Directory.GetFiles(path + @"data\FFT");/*目錄(含路徑)的陣列*/
            int path_count = 0; //計算有幾個檔案
            //先將該工件的所有臨界值資料取出
            foreach (string s in dirs) {
                //ex L-abc01-1_2500-set.cp
                string file = Path.GetFileNameWithoutExtension(s).Split('_')[0];
                string remove_rate = file.Split('-')[0] + "-" + file.Split('-')[1];
                if (remove_rate.Equals("L-" + lb_ToolWear_Parts.Text + pre_ToolWear.Name.Split('_')[2]))
                    path_count++;
            }
            if (path_count > int.Parse(lb_Threshold_page.Text) * 14) {
                lb_Threshold_page.Text = (int.Parse(lb_Threshold_page.Text) + 1).ToString();
                Threshold_Load();
            }
            else
                MessageBox.Show("已經在最後一頁。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
        }
        #endregion
        #region 主畫面設定
        //主畫面 > 設定 > 重新連線
        private void btn_setting_Reconnection_Click(object sender, EventArgs e) {
            if (EZNcCom != null) EZNcCom.Close();
            EZNcCom = new DispEZNcCommunication();
            lb_setting_Reconnection.Text = "正在準備重新連接控制器，這可能需要花費一段時間。";
            lb_setting_Reconnection.ForeColor = Color.White;
            Thread TD_Reconnection = new Thread(setting_Reconnection_Thread);
            TD_Reconnection.Start();
        }
        //主畫面 > 設定 > 重新連線執行緒
        delegate void SettingReconnectionDelegate();
        private void setting_Reconnection_Thread() {
            if (this.InvokeRequired) {
                SettingReconnectionDelegate SLD = new SettingReconnectionDelegate(setting_Reconnection_Thread);
                this.Invoke(SLD);
            }
            else {
                long ret = Mitsubishi_Initialization();
                if (ret != 0) {
                    lb_setting_Reconnection.Text = "控制器連線失敗。\n請確定控制器廠牌與IP設定無誤，並確認實體線路是否通暢。\n Error Code : " + ret.ToString();
                    lb_setting_Reconnection.ForeColor = Color.Red;
                    machine_connect = false;
                }
                else {
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
        private void btn_setting_save_Click(object sender, EventArgs e) {
            DialogResult dialogResult = MessageBox.Show("請先確認所選控制器廠牌與型號及IP是否正確。", "存檔", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;
            StreamWriter sw = new StreamWriter(path + @"\data\setting.cp");
            sw.WriteLine(string.Format("{0},{1},{2}", cb_setting_brand.Text, cb_setting_model.Text, tb_setting_ip.Text));
            sw.Close();
            sw.Dispose();
            MessageBox.Show("存檔成功。", "存檔", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }
        //主畫面 > 設定 > 刪除
        private void btn_setting_delete_Click(object sender, EventArgs e) {
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
        private void setting_load(bool OnRemove) {
            //主畫面 > 設定
            StreamReader sr_setting = new StreamReader(path + @"\data\setting.cp");
            string set = sr_setting.ReadLine();
            //搜尋廠牌
            for (int i = 0; i < cb_setting_brand.Items.Count; i++) {
                cb_setting_brand.SelectedIndex = i;
                if (cb_setting_brand.Text.Equals(set.Split(',')[0])) break;
                //當搜尋到最後一筆廠牌資料都沒有搜尋到時(因為如果有搜尋到就已經break了)
                if (i == cb_setting_brand.Items.Count - 1) {
                    cb_setting_brand.SelectedIndex = 0;
                    if (OnRemove == false)
                        MessageBox.Show("設定檔錯誤。\n查無廠牌！\n請確認設定檔資料是否正確，或是前往設定頁面重新選擇資料並儲存。", "設定檔錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            //搜尋型號
            for (int i = 0; i < cb_setting_model.Items.Count; i++) {
                cb_setting_model.SelectedIndex = i;
                if (cb_setting_model.Text.Equals(set.Split(',')[1])) break;
                //當搜尋到最後一筆廠牌資料都沒有搜尋到時(因為如果有搜尋到就已經break了)
                if (i == cb_setting_model.Items.Count - 1) {
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
        #region Alarm設定
        //設定 > Alarm設定 > 停止模式 > 瞬間
        private void btn_AlarmMode_Flash_Click(object sender, EventArgs e) {
            Alarm = Alarm_Mode.Flash;
        }
        //設定 > Alarm設定 > 停止模式 > 作業後停止
        private void btn_AlarmMode_Delay_Click(object sender, EventArgs e) {
            Alarm = Alarm_Mode.Delay;
        }
        //設定 > Alarm設定 > 停止模式 > 不處理
        private void btn_AlarmMode_None_Click(object sender, EventArgs e) {
            Alarm = Alarm_Mode.None;
        }
        //設定 > Alarm設定 > 上一頁
        private void btn_AlarmSetting_Back_Click(object sender, EventArgs e) {
            panel_Dissable();
            panel_setting.Visible = true;
        }
        //設定 > Alarm設定 > 儲存
        private void panel_AlarmSetting_save_Click(object sender, EventArgs e) {
            if (string.IsNullOrEmpty(tb_AlarmMethod_IP.Text)) {
                MessageBox.Show("IP位址不可為空。", "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            DialogResult dialogResult = MessageBox.Show("確定要儲存嗎？", "確認儲存", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;
            string write_s = "";    //暫存要寫入的文字
            if (Alarm == Alarm_Mode.Flash) write_s += "Flash";
            else if (Alarm == Alarm_Mode.Delay) write_s += "Delay";
            else if (Alarm == Alarm_Mode.None) write_s += "None";

            //目前只有施耐德
            write_s += ",Schneider";

            //IP
            write_s += "," + tb_AlarmMethod_IP.Text;

            StreamWriter sw = new StreamWriter(path + @"\data\alarm_set.cp");
            sw.WriteLine(write_s);
            sw.Close();
            sw.Dispose();
        }

        #endregion
        #region 模型預覽
        //模型預覽
        private void btn_ToolWearSetting_ViewModule_Click(object sender, EventArgs e) {
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
            while (!sr.EndOfStream) {
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
            for (int i = 0; i < file_name.Length; i++) {
                StreamReader sr_FFTmax = new StreamReader(path + @"\data\" + file_name[i] + ".cp");
                int FFT_count = 1;
                while (!sr_FFTmax.EndOfStream) {
                    chart_ViewFFT.Series[i].Points.AddXY(FFT_count * hz, sr_FFTmax.ReadLine());
                    FFT_count++;
                }
                sr_FFTmax.Close();
                sr_FFTmax.Dispose();
            }
            #endregion
        }
        //重置縮放
        private void btn_ViewModule_ChartReset_Click(object sender, EventArgs e) {
            //chart_Blade.ChartAreas[0].AxisX.ScaleView.ZoomReset(0);
            chart_ViewModule.ChartAreas[0].AxisX.ScaleView.ZoomReset(0);
            chart_ViewFFT.ChartAreas[0].AxisX.ScaleView.ZoomReset(0);
            chart_ViewFFT.ChartAreas[0].AxisY.ScaleView.ZoomReset(0);
        }
        //波形圖切換
        private void btn_ViewChartChange_Click(object sender, EventArgs e) {
            if (chart_ViewModule.Visible == true) {
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
        private void Blade_Comparison(double sample, double rate) {
            double hz = rate / sample;
            //讀取Module的暫存FFT變數 ： Module_FFT
            List<string> Blade_Module = Module_FFT;
            List<string> Blade_Match = new List<string>();
            string tem_path = "";
            try {
                //判斷檔案是否存在
                tem_path = path + @"\data\FFT\M-" + lb_ToolWear_Parts.Text + (now_Match + 1).ToString("00") + "-" + ATC_num + "_" + (int)ATC_RPM + ".cp";
                //若沒有存在則使用預設0刀號
                if (!File.Exists(tem_path)) tem_path = path + @"\data\FFT\M-" + lb_ToolWear_Parts.Text + (now_Match + 1).ToString("00") + "-" + "0" + "_" + (int)ATC_RPM + ".cp";
                if (!File.Exists(tem_path)) {
                    //查不到預設檔案，隨便選取一項
                    foreach (string s in Directory.GetFiles(path + @"data\FFT")) {
                        string path_s = Path.GetFileNameWithoutExtension(s);
                        if (!path_s.Split('-')[0].Equals("M")) continue;
                        if (path_s.Split('-')[1].Equals(lb_ToolWear_Parts.Text + (now_Match + 1).ToString("00"))) {
                            //ex.LS-xxx00-0_2500
                            //將前方抬頭刪掉
                            tem_path = path + @"\data\FFT\M-" + path_s.Split('-')[1] + "-" + path_s.Split('-')[2] + ".cp";
                            break;
                        }
                    }
                }
                StreamReader sr_match = new StreamReader(tem_path);
                while (!sr_match.EndOfStream)
                    Blade_Match.Add(sr_match.ReadLine());
                sr_match.Close();
                sr_match.Dispose();
            }
            catch (Exception ex) {

                MessageBox.Show("讀取Match檔時發生錯誤。\n\nBlade_Comparison\n\n" + ex.ToString(), "讀取錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            chart_Blade.Series[0].Points.Clear();
            //取得主軸轉數
            int Tool_rate = 2500;
            if (machine_connect == false || int.Parse(lb_ToolWear_FeedSpeed.Text.Split(' ')[0]) == 0)
                Tool_rate = 2500; //如果主軸轉數為0則使用預設轉數
            else Tool_rate = int.Parse(lb_ToolWear_FeedSpeed.Text.Split(' ')[0]);
            //取得刀具刃數
            StreamReader sr_ATC = new StreamReader(path + @"\data\ATC.cp");
            int Tool_Blade = 4;     //刀具刃數
            for (int i = 0; i <= now_Match; i++) {
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
            for (int i = 0; i < Blade_Match.Count; i++) {
                double tem = 0;
                //上下各取10% range
                Hz_min = Blade_Hz_Mag * Blade_Hz * 0.9f;
                Hz_max = Blade_Hz_Mag * Blade_Hz * 1.1f;
                if ((i + 1) * hz > Hz_min && (i + 1) * hz < Hz_max) {
                    tem = double.Parse(Blade_Match[i]) - double.Parse(Blade_Module[i]); //暫存相差值
                    if (tem >= 0) {
                        sum += tem;
                        count++;
                    }
                }
                else if ((i + 1) * hz > Hz_max) {
                    Blade_Hz_Mag++; //若頻率已大於刀刃刃數頻率，將倍率提升
                }
                //只顯示正數
                if (tem > 0)
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
            if (pre_Thermal != null) {
                pre_Thermal.BackgroundImage = ToolWear.Properties.Resources.tc_btn_axiabtn;
            }
            pre_Thermal = (Button)sender;
            pre_Thermal.BackgroundImage = ToolWear.Properties.Resources.tc_btn_axiabtn_selected;
            now_Thermal = int.Parse(((Button)sender).Name.Split('_')[2]) - 1;
            //判斷目前的軸向是否正在偵測
            if (((Button)sender).ForeColor != Color.White) {
                btn_Thermal_start.Enabled = false;
                btn_Thermal_stop.Enabled = true;
                btn_Thermal_start.BackgroundImage = ToolWear.Properties.Resources.tc_btn_ply;
                btn_Thermal_stop.BackgroundImage = ToolWear.Properties.Resources.btn_stop_selected;
                btn_Thermal_stop.Focus();
            }
            else {
                btn_Thermal_start.Enabled = true;
                btn_Thermal_stop.Enabled = false;
                btn_Thermal_start.BackgroundImage = ToolWear.Properties.Resources.btn_start_selected;
                btn_Thermal_stop.BackgroundImage = ToolWear.Properties.Resources.tc_btn_stop;
                btn_Thermal_start.Focus();
            }
            //判斷是否有其他軸向正在啟動
            if (Thermal_single > 0 && Thermal_bool[now_Thermal] != true) {
                //表示有其他軸向正在啟動，且不是目前選到的這一軸(代表這是第2個或以上選取的軸向)
                panel_Thermal_single.Visible = false;
                panel_Thermal_Mutile.Visible = true;
                Thermal_SelectAnother = true;
                //如果是點同一個按鈕才清空
                if (lb_Thermal_M2_Now.Text.Equals(pre_Thermal.Text)) {
                    chart_Thermal_M2.Series[0].Points.Clear();
                    chart_Thermal_M2.Series[1].Points.Clear();
                    for (int i = 1; i <= 30; i++)
                        chart_Thermal_M2.Series[1].Points.AddXY(i, 25);
                }
            }
            else if (Thermal_single > 1) {
                panel_Thermal_single.Visible = false;
                panel_Thermal_Mutile.Visible = true;
                Thermal_SelectAnother = false;
            }
            else {
                panel_Thermal_single.Visible = true;
                panel_Thermal_Mutile.Visible = false;
                Thermal_SelectAnother = false;
                if (Thermal_single == 0) {
                    chart_Thermal.Series[0].Points.Clear();
                    chart_Thermal.Series[1].Points.Clear();
                    chart_Thermal_M1.Series[0].Points.Clear();
                    chart_Thermal_M1.Series[1].Points.Clear();
                    for (int i = 1; i <= 30; i++) {
                        chart_Thermal.Series[1].Points.AddXY(i, 25);
                        chart_Thermal_M1.Series[1].Points.AddXY(i, 25);
                    }
                }
            }
            //更改折線圖顯示名稱
            if (Thermal_single == 0) lb_Thermal_Now.Text = pre_Thermal.Text;
            else if (Thermal_single % 2 == 1) lb_Thermal_M2_Now.Text = pre_Thermal.Text;
        }
        //熱補償 > 開始
        private void btn_Thermal_start_Click(object sender, EventArgs e) {
            string axial = "";  //軸向
            string ip = "";     //此軸向ip
            string channel = "";
            //先檢查此軸向設定檔是否完整
            StreamReader sr_set = new StreamReader(path + @"\data\thermal.cp");
            try {
                for (int i = 0; i <= now_Thermal; i++) {
                    string tem = sr_set.ReadLine();
                    if (i == now_Thermal) {
                        axial = tem.Split(',')[0];
                        ip = tem.Split(',')[1];
                        channel = tem.Split(',')[2];
                    }
                }
            }
            catch (Exception ex) {
                MessageBox.Show("此軸向設定檔不完全，請至設定頁面重新設定。\n\nbtn_Thermal_start_Click\n\n" + ex.ToString(), "設定檔錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
                sr_set.Close();
                sr_set.Dispose();
                return;
            }
            sr_set.Close();
            sr_set.Dispose();

            //開始偵測
            pre_Thermal.ForeColor = Color.FromArgb(255, 187, 0);
            btn_Thermal_start.Enabled = false;
            btn_Thermal_stop.Enabled = true;
            btn_Thermal_start.BackgroundImage = ToolWear.Properties.Resources.tc_btn_ply;
            btn_Thermal_stop.BackgroundImage = ToolWear.Properties.Resources.btn_stop_selected;
            if (Thermal_single == 0) lb_Thermal_Now.Text = pre_Thermal.Text;

            //清除原先折線圖資訊
            if (Thermal_single == 0) {
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
            else if (Thermal_single == 1) {
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
        private void btn_Thermal_stop_Click(object sender, EventArgs e) {
            pre_Thermal.ForeColor = Color.White;
            btn_Thermal_start.Enabled = true;
            btn_Thermal_stop.Enabled = false;
            btn_Thermal_start.BackgroundImage = ToolWear.Properties.Resources.btn_start_selected;
            btn_Thermal_stop.BackgroundImage = ToolWear.Properties.Resources.tc_btn_stop;
            Thermal_bool[now_Thermal] = false;
            Thermal_single--;
            //當都已經沒有任何軸向在啟動的時候
            if (Thermal_single == 0)
                timer_temperature.Enabled = false;
            else if (Thermal_single > 0)
                Thermal_SelectAnother = true;
            //Log推播
            Write_Log("系統", "已關閉熱補償偵測 ： " + pre_Thermal.Text + " 軸。");
            //重新設定頁數為最後一頁
            lb_Thermal_page.Text = (((Thermal_single - 1) / 2) + 1).ToString();
            //重新整理頁面
            btn_Thermal_Axial_Click((object)pre_Thermal, null);
        }
        //熱補償 > 折線圖上一頁
        private void btn_Thermal_up_Click(object sender, EventArgs e) {
            if (lb_Thermal_page.Text.Equals("1")) {
                MessageBox.Show("頁面切換失敗，已經在第一頁。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            else {
                lb_Thermal_page.Text = (int.Parse(lb_Thermal_page.Text) - 1).ToString();
                Thread TD_ChartData = new Thread(Thermal_ChartData);
                TD_ChartData.Start();
            }
        }
        //熱補償 > 折線圖下一頁
        private void btn_Thermal_down_Click(object sender, EventArgs e) {
            if (Thermal_single > int.Parse(lb_Thermal_page.Text) * 2) {
                lb_Thermal_page.Text = (int.Parse(lb_Thermal_page.Text) + 1).ToString();
                Thread TD_ChartData = new Thread(Thermal_ChartData);
                TD_ChartData.Start();
            }
            else {
                MessageBox.Show("沒有更多的偵測圖，已在最後一頁。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
        }
        //熱補償 > 顯示折線圖
        delegate void ChartDataDelegate();
        private void Thermal_ChartData() {
            if (this.InvokeRequired) {
                ChartDataDelegate CDD = new ChartDataDelegate(Thermal_ChartData);
                this.Invoke(CDD);
            }
            else {
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
                for (int i = 0; i < 20; i++) {
                    if (Thermal_bool[i] == false) continue;
                    if (chart_count < (int_page - 1) * 2) {
                        chart_count++;
                        continue;
                    }
                    List<string> tem_read = new List<string>();
                    try {
                        StreamReader sr_axial = new StreamReader(path + @"\data\Temperature\Axial" + i.ToString("00") + ".cp");
                        while (!sr_axial.EndOfStream) tem_read.Add(sr_axial.ReadLine());
                        sr_axial.Close();
                        sr_axial.Dispose();
                    }
                    catch { }
                    chart[chart_count % 2].Series[0].Points.Clear();
                    chart[chart_count % 2].Series[1].Points.Clear();
                    //清除換頁時第二個折線圖異常顯示問題
                    if (chart_count % 2 != 1) {
                        chart[1].Series[0].Points.Clear();
                        if ((int_page * 2) - 1 > chart_count && Thermal_SelectAnother == false)
                            chart_Title[1].Text = "";
                    }
                    if (chart_count == 0) {
                        chart_Thermal.Series[0].Points.Clear();
                        chart_Thermal.Series[1].Points.Clear();
                        //只剩一個時把第二張折線圖的線刪掉
                        chart[chart_count + 1].Series[0].Points.Clear();
                    }
                    for (int j = 0; j < tem_read.Count; j++) {
                        //如果資料檔內還沒存放超過30個數字，表示不用推移折線圖，直接加入最新點位即可
                        //if (tem_read.Count < 30) j = tem_read.Count - 1;
                        int tem_count = int.Parse(tem_read[j].Split(',')[0]) + 1;
                        chart[chart_count % 2].Series[0].Points.AddXY(tem_count, tem_read[j].Split(',')[1]);
                        if (chart_count == 0)
                            chart_Thermal.Series[0].Points.AddXY(tem_count, tem_read[j].Split(',')[1]);
                    }
                    for (int j = 0; j < 30; j++) {
                        if (tem_read.Count >= 30) {
                            int tem_count = int.Parse(tem_read[j].Split(',')[0]) + 1;
                            chart[chart_count % 2].Series[1].Points.AddXY(tem_count, 25);
                            chart_Thermal.Series[1].Points.AddXY(tem_count, 25);
                        }
                        else {
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
        /// <param name="axial">軸向</param>
        /// <param name="temperature">溫度</param>
        /// <param name="WriteWhere">發生事故的物件名稱</param>
        private void Thermal_Log(int axial, float temperature, string WriteObject) {
            //讀取熱補償資料
            StreamReader sr_compensate = new StreamReader(path + @"\data\compensate.cp");
            List<string> tem_compensate = new List<string>();
            while (!sr_compensate.EndOfStream) {
                string s = sr_compensate.ReadLine();
                //紀錄該軸向的補償資訊
                if (s.Split(',')[0].Equals(axial.ToString()))
                    tem_compensate.Add(s);
            }
            sr_compensate.Close();
            sr_compensate.Dispose();

            //如果tem_compensate的長度為0，表示沒有補償資料，直接return
            if (tem_compensate.Count == 0) return;

            //排序資料
            Compensate_Sort(ref tem_compensate, 0, tem_compensate.Count - 1);

            //檢查警告數值
            //從最大值開始判斷
            for (int i = tem_compensate.Count - 1; i >= 0; i--) {
                //若temperature小於陣列數值，表示未達該補償溫度，繼續往溫度低的資料判斷
                if (temperature < float.Parse(tem_compensate[i].Split(',')[1])) continue;
                else {
                    Write_Log("警告", string.Format("{0}軸溫度已上升至{1}℃，補償值{2}mm",
                        WriteObject, temperature, tem_compensate[i].Split(',')[2]));
                    break;
                }
            }
        }
        //熱補償專用排序(因為其為字串且需要一次更動兩個參數)
        private void Compensate_Sort(ref List<string> numbers, int left, int right) {
            if (left < right) {
                double middle = double.Parse(numbers[(left + right) / 2].Split(',')[1]);
                int i = left - 1;
                int j = right + 1;
                while (true) {
                    while (double.Parse(numbers[++i].Split(',')[1]) < middle) ;
                    while (double.Parse(numbers[--j].Split(',')[1]) > middle) ;
                    if (i >= j)
                        break;
                    //交換
                    string number = numbers[i];
                    numbers[i] = numbers[j];
                    numbers[j] = number;
                }
                Compensate_Sort(ref numbers, left, i - 1);
                Compensate_Sort(ref numbers, j + 1, right);
            }
        }
        //====假資料專用變數====
        bool[] Thermal_bool = new bool[20]; //該軸向是否開啟
        int[] Thermal_count = new int[20];
        float[] Thermal_temperature = new float[20];
        //====假資料專用變數====
        //熱補償 > 產生假資料
        delegate void FakeDataDelegate();
        private void Thermal_FakeData() {
            if (this.InvokeRequired) {
                FakeDataDelegate FDD = new FakeDataDelegate(Thermal_FakeData);
                this.Invoke(FDD);
            }
            else {
                //Thermal_single = 0 : 沒有任何啟動
                //Thermal_single = 1 : 啟動單軸
                //Thermal_single > 1 : 啟動好幾軸
                for (int i = 0; i < 20; i++) {
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
                    Thermal_Log(i, Thermal_temperature[i], btn_Thermal[i].Text);

                    List<string> tem_read = new List<string>();
                    try {
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
                    for (int j = 0; j < tem_read.Count; j++) {
                        if (tem_read.Count >= 30)
                            //判斷是不是新加入的值
                            if (j == tem_read.Count - 1)
                                sw_axial.WriteLine(Thermal_count[i] + "," + Thermal_temperature[i].ToString());
                            else
                                sw_axial.WriteLine((Thermal_count[i] - (30 - j)).ToString() + "," + tem_read[j].Split(',')[1]);
                        else {
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
                if (Thermal_single == 1 && Thermal_SelectAnother == false) {
                    panel_Thermal_single.Visible = true;
                    panel_Thermal_Mutile.Visible = false;
                }
                else if (Thermal_single == 1 && Thermal_SelectAnother == true) {
                    panel_Thermal_single.Visible = false;
                    panel_Thermal_Mutile.Visible = true;
                }
                //呼叫繪圖程式
                Thermal_ChartData();
            }
        }
        #endregion
        #region 健康診斷
        //健康診斷 > 讀取資料
        private void Health_load() {
            //先重整頻道
            Health_ChannelLoad(null, null);
            try {
                StreamReader sr = new StreamReader(path + @"data\health.cp");
                string tem = sr.ReadLine();
                //檢查廠牌資料
                for (int i = 0; i < cb_HealthSetting_Machine.Items.Count; i++) {
                    cb_HealthSetting_Machine.SelectedIndex = i;
                    if (tem.Split(',')[0].Equals(cb_HealthSetting_Machine.Text)) break;
                    //如果搜尋到最後都沒查到符合的
                    if (i == cb_HealthSetting_Machine.Items.Count - 1) {
                        cb_HealthSetting_Machine.SelectedIndex = 0;
                    }
                }
                //檢查訊號輸入
                for (int i = 0; i < cb_HealthSetting_Channel.Items.Count; i++) {
                    cb_HealthSetting_Channel.SelectedIndex = i;
                    if (tem.Split(',')[1].Equals(cb_HealthSetting_Channel.Text)) break;
                    //如果搜尋到最後都沒查到符合的
                    if (i == cb_HealthSetting_Channel.Items.Count - 1) {
                        cb_HealthSetting_Channel.SelectedIndex = 0;
                    }
                }
                //帶入數值
                numeric_HealthSetting_Range.Value = decimal.Parse(tem.Split(',')[2]);

                sr.Close();
                sr.Dispose();
            }
            catch (Exception ex) {
                MessageBox.Show("讀取健康診斷資料失敗。\n\nHealth_load\n\n" + ex.ToString(), "讀取失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            lb_Health_Machine.Text = cb_HealthSetting_Machine.Text;
        }
        //健康診斷 > 設定 > 頻道讀取
        private void Health_ChannelLoad(object sender, EventArgs e) {
            cb_HealthSetting_Channel.Items.Clear();
            cb_HealthSetting_Channel.Items.Add("請選擇訊號輸入");
            //DAQ實體訊號輸入端點讀取
            dataTable = new DataTable();
            try {
                cb_HealthSetting_Channel.Items.AddRange(DaqSystem.Local.GetPhysicalChannels(PhysicalChannelTypes.AI, PhysicalChannelAccess.External));
                if (cb_HealthSetting_Channel.Items.Count > 0)
                    cb_HealthSetting_Channel.SelectedIndex = 0;
            }
            catch { }
            //如果是按按鈕觸發的(sender != null)，重新讀取資料
            if (sender != null) Health_load();
        }
        //健康診斷 > 設定 > 存檔
        private void HealthSetting_save(object sender, EventArgs e) {
            DialogResult dialogResult = MessageBox.Show("繼續操作將會覆蓋您之前的設定檔，\n請問要繼續嗎？", "存檔", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;
            try {
                StreamWriter sw = new StreamWriter(path + @"data\health.cp");
                sw.WriteLine(string.Format("{0},{1},{2}", cb_HealthSetting_Machine.Text, cb_HealthSetting_Channel.Text, numeric_HealthSetting_Range.Value));
                sw.Close();
                sw.Dispose();
            }
            catch (Exception ex) {
                MessageBox.Show("在存檔時發生不可測意外。\n\nHealthSetting_save\n\n" + ex.ToString(), "存檔失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //健康診斷 > 設定 > 刪除
        private void HealthSetting_delete(object sender, EventArgs e) {
            DialogResult dialogResult = MessageBox.Show("繼續操作將會刪除您的設定檔，\n請問要繼續嗎？", "刪除警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            try {
                StreamWriter sw = new StreamWriter(path + @"data\health.cp");
                sw.WriteLine(",,0");
                sw.Close();
                sw.Dispose();
            }
            catch (Exception ex) {
                MessageBox.Show("在刪除設定檔時發生不可測意外。\n\nHealthSetting_delete\n\n" + ex.ToString(), "刪除失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //健康診斷 > 開始
        private void Health_Start(object sender, EventArgs e) {
            //檢查是否有選擇機台型號
            if (string.IsNullOrWhiteSpace(lb_Health_Machine.Text)) {
                MessageBox.Show("請先至設定頁面選擇機台型號後再開始。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            //出廠檢測模式
            if (panel_Health_Factory.Visible == true) {
                DialogResult dialogResult = MessageBox.Show("繼續操作將會覆蓋您原先的設定檔，\n請問要繼續嗎？\n(若是第一次建置請無視此訊息)", "模型重建", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
                if (dialogResult == DialogResult.Cancel) return;

                //重置設定檔
                StreamWriter sw = new StreamWriter(path + @"data\Health\Factory_" + lb_Health_Machine.Text + ".cp");
                sw.WriteLine("-99");
                sw.Close();
                sw.Dispose();

                //重置最大值參數
                tem_Factory_Max.Clear();
                for (int i = 0; i < samplesPerChannelNumeric_base / 2; i++)
                    tem_Factory_Max.Add("-99");

                DAQ_Now = "Factory";  //出場檢測
            }
            //售後檢測模式
            else {
                //重置最大值參數
                tem_AfterSale_Max.Clear();
                for (int i = 0; i < samplesPerChannelNumeric_base / 2; i++)
                    tem_AfterSale_Max.Add("-99");

                //讀取出場檢測資料檔
                try {
                    StreamReader sr = new StreamReader(path + @"data\Health\Factory_" + lb_Health_Machine.Text + ".cp");
                    tem_Factory_Max.Clear();
                    while (!sr.EndOfStream)
                        tem_Factory_Max.Add(sr.ReadLine());
                    sr.Close();
                    sr.Dispose();
                }
                catch {
                    //會進到catch表示沒有學習模型
                    MessageBox.Show("此機器型號沒有出廠資料檔，請先使用出廠檢測取得基準\n資料後再進行售後檢測。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                //重置設定檔
                StreamWriter sw = new StreamWriter(path + @"data\Health\AfterSale_" + lb_Health_Machine.Text + ".cp");
                sw.WriteLine("-99");
                sw.Close();
                sw.Dispose();

                //將出場檢測資料繪至折線圖
                chart_Health_Match.Series[3].Points.Clear();
                double hz = (double)rateNumeric_base / (double)samplesPerChannelNumeric_base;
                for (int i = 0; i < tem_Factory_Max.Count; i++)
                    chart_Health_Match.Series[3].Points.AddXY((i + 1) * hz, tem_Factory_Max[i]);

                DAQ_Now = "AfterSale"; //售後檢測
            }

            //按鈕變更
            btn_Health_Start.Enabled = false;
            btn_Health_Stop.Enabled = true;
            btn_Health_Start.BackgroundImage = ToolWear.Properties.Resources.tc_btn_ply;
            btn_Health_Stop.BackgroundImage = ToolWear.Properties.Resources.btn_stop_selected;

            //開啟Task
            if (runningTask == null) {
                try {
                    samplesPerChannelNumeric = samplesPerChannelNumeric_base + 1; //取樣數偏移
                    rateNumeric = rateNumeric_base + 1;  //頻率偏移
                    //TASK設定
                    sensitivityUnits = AIAccelerometerSensitivityUnits.MillivoltsPerG;
                    terminalConfiguration = AITerminalConfiguration.Pseudodifferential;
                    excitationSource = AIExcitationSource.Internal;
                    inputCoupling = AICoupling.AC;
                    // Create a new task
                    myTask = new NationalInstruments.DAQmx.Task();
                    AIChannel aiChannel;
                    // Create a virtual channel
                    aiChannel = myTask.AIChannels.CreateAccelerometerChannel(cb_HealthSetting_Channel.Text, "",
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
                }
                catch (DaqException exception) {
                    // Display Errors
                    if (exception.Error == -200431 || exception.Error == -200220) {
                        MessageBox.Show("無法初始化選取的訊號輸入，請確認設定檔內的訊號輸入是否正確，\n或是檢查是否有讀取到原先所設置的訊號。", "偵測啟動失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        Health_Stop(null, null);
                    }
                    else {
                        TaskStop();
                        //嘗試自我修復
                        DAQInitialize(DAQ_Now);
                    }
                }
            }
        }
        //健康診斷 > 停止
        private void Health_Stop(object sender, EventArgs e) {
            //清空Task
            if (runningTask != null) TaskStop();
            //重置按鈕
            btn_Health_Start.Enabled = true;
            btn_Health_Stop.Enabled = false;
            btn_Health_Start.BackgroundImage = ToolWear.Properties.Resources.btn_start_selected;
            btn_Health_Stop.BackgroundImage = ToolWear.Properties.Resources.tc_btn_stop;

            //如果是程式呼叫表示是從例外事件觸發，直接return
            if (sender == null) return;

            //如果是售後檢測模式
            if (DAQ_Now.Equals("AfterSale")) {
                panel_Dissable();
                panel_Health_Result.Visible = true;
                HealthResult_Load();
            }
        }
        //健康診斷 > 檢測結果讀取與計算
        private void HealthResult_Load() {
            //重置最大值參數(避免超出陣列問題發生)
            tem_Factory_Max.Clear();
            tem_AfterSale_Max.Clear();
            //清空折線圖
            chart_HealthResult_Factory.Series[0].Points.Clear();
            chart_HealthResult_AfterSale.Series[0].Points.Clear();
            chart_HealthResult_Factory.Series[2].Points.Clear();
            chart_HealthResult_AfterSale.Series[2].Points.Clear();
            for (int i = 0; i < (int)(samplesPerChannelNumeric_base / 2); i++) {
                tem_Factory_Max.Add("-99");
                tem_AfterSale_Max.Add("-99");
            }
            double hz = rateNumeric_base / samplesPerChannelNumeric_base;
            //暫存數據最大值(作為折線圖的高點)
            double tem_max = 0;
            //讀取出廠數據
            StreamReader sr_Factory = new StreamReader(path + @"data\Health\Factory_" + lb_Health_Machine.Text + ".cp");
            int sr_Factory_Count = 0;
            while (!sr_Factory.EndOfStream) {
                string tem = sr_Factory.ReadLine();
                tem_Factory_Max[sr_Factory_Count] = tem;
                sr_Factory_Count++;
                chart_HealthResult_Factory.Series[0].Points.AddXY(sr_Factory_Count * hz, tem);
                if (double.Parse(tem) > tem_max)
                    tem_max = double.Parse(tem);
            }
            sr_Factory.Close();
            sr_Factory.Dispose();
            //讀取售後數據
            StreamReader sr_AfterSale = new StreamReader(path + @"data\Health\AfterSale_" + lb_Health_Machine.Text + ".cp");
            int sr_AfterSale_Count = 0;
            while (!sr_AfterSale.EndOfStream) {
                string tem = sr_AfterSale.ReadLine();
                tem_AfterSale_Max[sr_AfterSale_Count] = tem;
                sr_AfterSale_Count++;
                chart_HealthResult_AfterSale.Series[0].Points.AddXY(sr_AfterSale_Count * hz, tem);
                if (double.Parse(tem) > tem_max)
                    tem_max = double.Parse(tem);
            }
            sr_AfterSale.Close();
            sr_AfterSale.Dispose();
            //統一兩個折線圖最大值
            chart_HealthResult_Factory.Series[2].Points.AddXY(sr_Factory_Count * hz, tem_max);
            chart_HealthResult_AfterSale.Series[2].Points.AddXY(sr_Factory_Count * hz, tem_max);
            //讀取設定檔內的可容忍範圍
            StreamReader sr_Health = new StreamReader(path + @"data\health.cp");
            double range = double.Parse(sr_Health.ReadLine().Split(',')[2]) * 0.01;
            sr_Health.Close();
            sr_Health.Dispose();
            //比對圖形
            int pass_count = 0;  //暫存總共有幾筆頻率在設定值內
            for (int i = 0; i < tem_Factory_Max.Count; i++) {
                //在設定值內就將暫存值+1
                if ((double.Parse(tem_AfterSale_Max[i])) < double.Parse(tem_Factory_Max[i]) * (1 + range))
                    pass_count++;
            }
            lb_HealthResult_Result.Text = string.Format("在檢測震幅範圍{0} %之下的合格率為{1} %", range * 100, (double)pass_count / (double)tem_Factory_Max.Count * 100);
            StreamWriter sw_pass = new StreamWriter(path + @"data\Health\Pass_" + lb_Health_Machine.Text + ".cp");
            sw_pass.WriteLine((double)pass_count / (double)tem_Factory_Max.Count * 100);
            sw_pass.Close();
            sw_pass.Dispose();
        }
        #endregion
        #region 刀具磨耗預測
        //暫存訓練模式
        string Prediction_TrainMode = "";
        //自動模式計數器
        int Prediction_AutoMode_Count = 0;
        //讀取刀具磨耗預測設定檔資料
        private void panle_prediction_Load() {
            //讀取設定檔內資料
            cb_prediction_ModelName.Items.Clear();
            foreach (string fname in Directory.GetFileSystemEntries(path + @"model_name\"))
                cb_prediction_ModelName.Items.Add(Path.GetFileNameWithoutExtension(fname));
            cb_prediction_Material.SelectedIndex = 0;
            cb_prediction_Type.SelectedIndex = 0;
            cb_prediction_work.SelectedIndex = 0;
            cb_prediction_ModelName.SelectedIndex = cb_prediction_ModelName.Items.Count - 1;
            cb_prediction_TrainTime.SelectedIndex = 0;

            PB_prediction_ML.Visible = false;
            PB_prediction_SL.Visible = false;
            btn_ChangeMode0.BackgroundImage = ToolWear.Properties.Resources.SE_logo;
        }
        //回上一頁
        private void btn_prediction_back_Click(object sender, EventArgs e) {
            timer_prediction_ML.Enabled = false;
            btn_ToolWear_Click(null, null);
        }
        //使用者自己打字時
        private void cb_prediction_ModelName_TextChanged(object sender, EventArgs e) {
            foreach (string fname in Directory.GetFileSystemEntries(path + @"model_name\")) {
                string file_name = Path.GetFileNameWithoutExtension(fname);
                if (file_name.Equals(cb_prediction_ModelName.Text)) {
                    cb_prediction_Material.Enabled = false;
                    cb_prediction_Type.Enabled = false;
                    cb_prediction_work.Enabled = false;
                    return;
                }
            }
            cb_prediction_Material.Enabled = true;
            cb_prediction_Type.Enabled = true;
            cb_prediction_work.Enabled = true;
        }
        //選擇不同的項目時讀取設定檔內資料
        private void cb_prediction_ModelName_SelectedIndexChanged(object sender, EventArgs e) {
            StreamReader sr = new StreamReader(path + @"model_name\" + cb_prediction_ModelName.Text + ".csv");
            string tem_s = sr.ReadLine();   //格式為 名稱,刀具材質,刀具種類,工件種類
            sr.Close();
            sr.Dispose();

            //自動選擇各項材質

            //刀具材質
            for (int i = 0; i < cb_prediction_Material.Items.Count; i++) {
                cb_prediction_Material.SelectedIndex = i;
                if (cb_prediction_Material.Text.Equals(tem_s.Split(',')[6])) break;

                //防呆，if會成立表示設定檔被更動過
                if (i == cb_prediction_Material.Items.Count - 1)
                    MessageBox.Show("「刀具材質」未讀取到匹配項目，請確定設定檔是否被更動。", "讀取失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }

            //刀具種類
            for (int i = 0; i < cb_prediction_Type.Items.Count; i++) {
                cb_prediction_Type.SelectedIndex = i;
                if (cb_prediction_Type.Text.Equals(tem_s.Split(',')[7])) break;

                //防呆，if會成立表示設定檔被更動過
                if (i == cb_prediction_Type.Items.Count - 1)
                    MessageBox.Show("「刀具種類」未讀取到匹配項目，請確定設定檔是否被更動。", "讀取失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }

            //工件種類
            for (int i = 0; i < cb_prediction_work.Items.Count; i++) {
                cb_prediction_work.SelectedIndex = i;
                if (cb_prediction_work.Text.Equals(tem_s.Split(',')[8])) break;

                //防呆，if會成立表示設定檔被更動過
                if (i == cb_prediction_work.Items.Count - 1)
                    MessageBox.Show("「工件種類」未讀取到匹配項目，請確定設定檔是否被更動。", "讀取失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }
        //刀具磨耗預測 > 開始
        private void btn_prediction_start_Click(object sender, EventArgs e) {
            //首先判斷名稱是否已填寫
            if (string.IsNullOrWhiteSpace(cb_prediction_ModelName.Text)) {
                MessageBox.Show("模型名稱未填寫。", "執行失敗", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            //判斷是否為新檔案
            List<string> file_module = new List<string>();
            foreach (string fname in Directory.GetFileSystemEntries(path + @"model_name\"))
                file_module.Add(Path.GetFileNameWithoutExtension(fname));
            for (int i = 0; i < file_module.Count; i++) {
                if (file_module[i].Equals(cb_prediction_ModelName.Text)) break;
                if (i == file_module.Count - 1) {
                    //將新的模型寫入新檔
                    StreamWriter sw = new StreamWriter(path + @"model_name\" + cb_prediction_ModelName.Text + ".csv");
                    sw.WriteLine("x,y,z,tool_condition,date,time," + cb_prediction_Material.Text + "," +
                        cb_prediction_Type.Text + "," + cb_prediction_work.Text);
                    sw.Close();
                    sw.Dispose();
                    cb_prediction_ModelName.Items.Add(cb_prediction_ModelName.Text);
                }
            }
            //將現在使用的模型名稱寫入file_name.csv
            StreamWriter sw_file_name = new StreamWriter(path + @"file_name\file_name.csv");
            sw_file_name.WriteLine(cb_prediction_ModelName.Text);
            sw_file_name.Close();
            sw_file_name.Dispose();

            btn_prediction_start.Enabled = false;
            btn_prediction_start.BackgroundImage = ToolWear.Properties.Resources.tc_btn_ply;
            btn_prediction_stop.Enabled = true;
            btn_prediction_stop.BackgroundImage = ToolWear.Properties.Resources.btn_stop_selected;

            cb_prediction_ModelName.Enabled = false;
            cb_prediction_Material.Enabled = false;
            cb_prediction_Type.Enabled = false;
            cb_prediction_work.Enabled = false;

            PB_prediction_ML.Visible = false;
            PB_prediction_SL.Visible = false;

            timer_prediction.Enabled = true;
        }
        //刀具磨耗預測 > 停止
        private void btn_prediction_stop_Click(object sender, EventArgs e) {
            timer_prediction.Enabled = false;

            //關閉停止按鈕
            btn_prediction_stop.Enabled = false;
            btn_prediction_stop.BackgroundImage = ToolWear.Properties.Resources.tc_btn_stop;
            btn_prediction_start.Enabled = true;
            btn_prediction_start.BackgroundImage = ToolWear.Properties.Resources.btn_start_selected;

            cb_prediction_ModelName.Enabled = true;

        }
        //刀具磨耗預測 > 自我學習
        private void btn_prediction_self_Click(object sender, EventArgs e) {
            //若是由按鈕觸發而非程式觸發
            if (sender != null){
                //更改訓練模式字串
                Prediction_TrainMode = "手動";
                lb_prediction_TrainMode.Text = Prediction_TrainMode;
            }
            //呼叫exe
            Process.Start(path + @"SE_SL.exe");

            //歸零進度條
            PB_prediction_SL.Value = 0;
            //啟動timer讀取結果
            timer_prediction_SL.Enabled = true;
        }
        //刀具磨耗預測 > 自動訓練選單選取
        private void cb_prediction_TrainTime_SelectedIndexChanged(object sender, EventArgs e){
            if(cb_prediction_TrainTime.SelectedIndex == 0){
                //更改為手動模式
                Prediction_TrainMode = "手動";
                lb_prediction_TrainMode.Text = Prediction_TrainMode;
            }
            else{
                //重置計數器
                Prediction_AutoMode_Count = 0;
                //更改訓練模式字串
                Prediction_TrainMode = "自動";
                lb_prediction_TrainMode.Text = string.Format("{0} ( {1} / {2} )", Prediction_TrainMode,Prediction_AutoMode_Count,cb_prediction_TrainTime.Text.Split('次')[0]) ;

            }
        }
        //刀具磨耗預測 > 手動修改記憶體位置
        private void btn_prediction_test_Click(object sender,EventArgs e){
            if (lb_prediction_status.Text.Equals("0"))
                lb_prediction_status.Text = "8";
            else
                lb_prediction_status.Text = "0";
        }
        #endregion
        #region 磨耗偵測(三軸、電流)
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 回上一頁
        private void btn_AccCur_back_Click(object sender, EventArgs e) {
            panel_Dissable();
            btn_ToolWear_Click(null, null);
            //重置取樣頻率
            samplesPerChannelNumeric_base = 800;
            rateNumeric = 4000;
            TaskStop();
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 設定
        private void btn_AccCur_setting_Click(object sender, EventArgs e) {
            panel_AccCur.Visible = false;
            panel_AccCur_setting.Visible = true;
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 設定 > 回上一頁
        private void btn_AccCur_setting_back_Click(object sender, EventArgs e) {
            panel_AccCur.Visible = true;
            panel_AccCur_setting.Visible = false;
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 設定 > 讀取訊號輸入
        private void btn_AccCur_setting_loadChannel(object sender, EventArgs e) {
            ComboBox[] cb_Channel = new ComboBox[5] { cb_AccCur_setting_ChannelX, cb_AccCur_setting_ChannelY,
            cb_AccCur_setting_ChannelZ,cb_AccCur_setting_ChannelC,cb_AccCur_setting_ChannelAE};
            for (int i = 0; i < cb_Channel.Length; i++)
                cb_Channel[i].Items.Clear();

            List<string> channel = new List<string>();

            channel.Add("請選擇訊號輸入");
            //DAQ實體訊號輸入端點讀取
            channel.AddRange(DaqSystem.Local.GetPhysicalChannels(PhysicalChannelTypes.AI, PhysicalChannelAccess.External));

            for (int i = 0; i < channel.Count; i++)
                for (int j = 0; j < cb_Channel.Length; j++)
                    cb_Channel[j].Items.Add(channel[i]);
            AccCur_setting_load();
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 設定 > 按鈕上
        private void btn_AccCur_setting_Up(object sender,EventArgs e){
            Button[] btn_Channel = new Button[5] {btn_AccCur_X_up, btn_AccCur_Y_up, btn_AccCur_Z_up, btn_AccCur_Cur_up, btn_AccCur_AE_up };
            NumericUpDown[] num_Channel = new NumericUpDown[5] { num_AccCur_X, num_AccCur_Y, num_AccCur_Z, num_AccCur_Cur, num_AccCur_AE };
            Button now_btn = (Button)sender;
            for(int i = 0; i < btn_Channel.Length; i++){
                if(now_btn.Name == btn_Channel[i].Name){
                    if (num_Channel[i].Value < num_Channel[i].Maximum)
                        num_Channel[i].Value += (decimal)0.1;
                }
            }
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 設定 > 按鈕下
        private void btn_AccCur_setting_Down(object sender, EventArgs e){
            Button[] btn_Channel = new Button[5] { btn_AccCur_X_down, btn_AccCur_Y_down, btn_AccCur_Z_down, btn_AccCur_Cur_down, btn_AccCur_AE_down };
            NumericUpDown[] num_Channel = new NumericUpDown[5] { num_AccCur_X, num_AccCur_Y, num_AccCur_Z, num_AccCur_Cur, num_AccCur_AE };
            Button now_btn = (Button)sender;
            for (int i = 0; i < btn_Channel.Length; i++){
                if (now_btn.Name == btn_Channel[i].Name){
                    if (num_Channel[i].Value > num_Channel[i].Minimum)
                        num_Channel[i].Value -= (decimal)0.1;
                }
            }
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 讀取資料
        private void AccCur_setting_load() {
            //暫存頻道資訊
            List<string> Channel = new List<string>();
            ComboBox[] cb_Channel = new ComboBox[5] { cb_AccCur_setting_ChannelX, cb_AccCur_setting_ChannelY,
            cb_AccCur_setting_ChannelZ,cb_AccCur_setting_ChannelC,cb_AccCur_setting_ChannelAE};
            NumericUpDown[] num_Channel = new NumericUpDown[5] { num_AccCur_X, num_AccCur_Y, num_AccCur_Z, num_AccCur_Cur, num_AccCur_AE };
            System.Windows.Forms.DataVisualization.Charting.Chart[] chart_Channel = new System.Windows.Forms.DataVisualization.Charting.Chart[5]
                {chart_AccCur_X,chart_AccCur_Y,chart_AccCur_Z,chart_AccCur_Current,chart_AE };
            //暫存是否有找到符合資料檔的頻道
            bool[] find_Channel = new bool[cb_Channel.Length];
            StreamReader sr = new StreamReader(path + @"\data\AccCur.cp");
            while (!sr.EndOfStream) Channel.Add(sr.ReadLine());
            sr.Close();
            sr.Dispose();

            //選取頻道
            for (int i = 0; i < cb_AccCur_setting_ChannelX.Items.Count; i++) {
                for (int j = 0; j < cb_Channel.Length; j++) {
                    //如果還沒找到該資料檔符合的頻道
                    if (find_Channel[j] == false) {
                        cb_Channel[j].SelectedIndex = i;
                        if (Channel[j].Split(',')[0].Equals(cb_Channel[j].Text)) find_Channel[j] = true;
                    }
                }
            }
            //檢查是否有沒有找到頻道的資料
            for (int i = 0; i < find_Channel.Length; i++) {
                if (find_Channel[i] == false) {
                    //MessageBox.Show("有頻道的資料檔錯誤。", "設定檔錯誤", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    cb_Channel[i].SelectedIndex = 0;
                }
            }
            //載入已設定警戒值
            for (int i = 0; i < num_Channel.Length; i++){
                try{
                    num_Channel[i].Value = decimal.Parse(Channel[i].Split(',')[1]);
                    chart_Channel[i].Series[2].Points.Clear();
                    chart_Channel[i].Series[2].Points.AddXY(0, num_Channel[i].Value);
                    //AE
                    if (i == 4) 
                        chart_Channel[i].Series[2].Points.AddXY(5000, num_Channel[i].Value);
                    else
                        chart_Channel[i].Series[2].Points.AddXY(2000, num_Channel[i].Value);
                }
                catch {
                    num_Channel[i].Value = 0;
                }
            }
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 儲存
        private void btn_AccCur_setting_save_Click(object sender, EventArgs e) {
            DialogResult dialogResult = MessageBox.Show("確定儲存新的訊號輸入嗎？", "儲存", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;

            ComboBox[] cb_Channel = new ComboBox[5] { cb_AccCur_setting_ChannelX, cb_AccCur_setting_ChannelY,
            cb_AccCur_setting_ChannelZ,cb_AccCur_setting_ChannelC,cb_AccCur_setting_ChannelAE};
            NumericUpDown[] num_Channel = new NumericUpDown[5] { num_AccCur_X, num_AccCur_Y, num_AccCur_Z, num_AccCur_Cur, num_AccCur_AE };

            //先檢查有沒有選到一樣的輸入端
            for (int i = 0; i < cb_Channel.Length - 2; i++) {
                for (int j = i + 1; j < cb_Channel.Length; j++) {
                    if (cb_Channel[i].SelectedIndex == cb_Channel[j].SelectedIndex && cb_Channel[i].SelectedIndex != 0) {
                        MessageBox.Show("選擇了相同的訊號輸入，請重新選擇。\n\n" + cb_Channel[i].Text, "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                    }
                }
            }

            StreamWriter sw = new StreamWriter(path + @"\data\AccCur.cp");
            for (int i = 0; i < cb_Channel.Length; i++) {
                string write_s = "";
                //訊號源
                if (cb_Channel[i].SelectedIndex == 0) write_s = "0";
                else write_s = cb_Channel[i].Text;
                //警戒線
                write_s += "," + num_Channel[i].Value;

                sw.WriteLine(write_s);
            }
            sw.Close();
            sw.Dispose();

            MessageBox.Show("儲存成功", "儲存完畢", MessageBoxButtons.OK, MessageBoxIcon.Information);

            AccCur_setting_load();
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 開始
        private void btn_AccCur_start_Click(object sender, EventArgs e) {
            btn_AccCur_start.Enabled = false;
            btn_AccCur_start.BackgroundImage = ToolWear.Properties.Resources.tc_btn_ply;
            btn_AccCur_stop.Enabled = true;
            btn_AccCur_stop.BackgroundImage = ToolWear.Properties.Resources.btn_stop_selected;

            //清空先前的紀錄檔
            string[] Acc_path = new string[4] { @"data\AccCur\X.csv", @"data\AccCur\Y.csv", @"data\AccCur\Z.csv", @"data\AccCur\Cur.csv" };
            for (int i = 0; i < Acc_path.Length; i++){
                StreamWriter sw = new StreamWriter(path + Acc_path[i]);
                sw.Write("");
                sw.Close();
                sw.Dispose();
            }

            DAQInitialize("AccCur");
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 停止
        private void btn_AccCur_stop_Click(object sender, EventArgs e) {
            btn_AccCur_start.Enabled = true;
            btn_AccCur_start.BackgroundImage = ToolWear.Properties.Resources.btn_start_selected;
            btn_AccCur_stop.Enabled = false;
            btn_AccCur_stop.BackgroundImage = ToolWear.Properties.Resources.tc_btn_stop;

            //重置取樣頻率
            samplesPerChannelNumeric_base = 800;
            rateNumeric = 4000;

            TaskStop();
        }
        #region 音頻偵測
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 音頻偵測 > 回上一頁
        private void btn_AE_back_Click(object sender, EventArgs e) {
            TaskStop();
            panel_AccCur.Visible = true;
            panel_AE.Visible = false;

            //重置按鈕
            btn_AE_start.Enabled = true;
            btn_AE_start.BackgroundImage = ToolWear.Properties.Resources.btn_start_selected;
            btn_AE_stop.Enabled = false;
            btn_AE_stop.BackgroundImage = ToolWear.Properties.Resources.tc_btn_stop;

            //開啟子功能項
            btn_ChangeMode.Enabled = true;
            btn_ChangeMode.BackgroundImage = ToolWear.Properties.Resources.tc_menubtn_blank;
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 音頻偵測 > 開始
        private void btn_AE_start_Click(object sender, EventArgs e) {
            btn_AE_start.Enabled = false;
            btn_AE_start.BackgroundImage = ToolWear.Properties.Resources.tc_btn_ply;
            btn_AE_stop.Enabled = true;
            btn_AE_stop.BackgroundImage = ToolWear.Properties.Resources.btn_stop_selected;

            //清空先前的紀錄檔
            StreamWriter sw = new StreamWriter(path + @"data\AccCur\AE.csv");
            sw.Write("");
            sw.Close();
            sw.Dispose();

            DAQInitialize("AE");
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流 > 音頻偵測 > 停止
        private void btn_AE_stop_Click(object sender, EventArgs e) {
            btn_AE_start.Enabled = true;
            btn_AE_start.BackgroundImage = ToolWear.Properties.Resources.btn_start_selected;
            btn_AE_stop.Enabled = false;
            btn_AE_stop.BackgroundImage = ToolWear.Properties.Resources.tc_btn_stop;

            //重置取樣頻率
            samplesPerChannelNumeric_base = 800;
            rateNumeric = 4000;

            TaskStop();
        }
        #endregion
        #region 參數設定
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 參數設定
        private void btn_AccCur_parameter_Click(object sender, EventArgs e){
            panel_AccCur_parameter.Visible = true;
            panel_AccCur_setting.Visible = false;
            AccCur_parameter_Load();
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 參數設定 > 初始化讀取
        private void AccCur_parameter_Load(){
            panel_AccCur_parameter_Add.Visible = false;

            lb_AccCur_parameter_type.Items.Clear();
            lb_AccCur_parameter_workpiece.Items.Clear();
            //讀取工件和砂輪資料檔
            StreamReader sr_workpiece = new StreamReader(path + @"data\AccCur\AccCur_workpiece.cp");
            while (!sr_workpiece.EndOfStream)
                lb_AccCur_parameter_workpiece.Items.Add(sr_workpiece.ReadLine());
            sr_workpiece.Close();
            sr_workpiece.Dispose();
            StreamReader sr_type = new StreamReader(path + @"data\AccCur\AccCur_type.cp");
            while (!sr_type.EndOfStream)
                lb_AccCur_parameter_type.Items.Add(sr_type.ReadLine());
            sr_type.Close();
            sr_type.Dispose();

            if (lb_AccCur_parameter_workpiece.Items.Count > 0)
                lb_AccCur_parameter_workpiece.SelectedIndex = 0;
            if (lb_AccCur_parameter_type.Items.Count > 0)
                lb_AccCur_parameter_type.SelectedIndex = 0;
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 參數設定 > 回上一頁
        private void btn_AccCur_parameter_back_Click(object sender,EventArgs e){
            panel_AccCur_parameter.Visible = false;
            panel_AccCur_setting.Visible = true;
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 參數設定 > 轉動撥桿
        private void tbar_AccCur_parameter_surface_Scroll(object sender, EventArgs e){
            tb_AccCur_parameter_surface.Text = ((float)tbar_AccCur_parameter_surface.Value / 1000).ToString("0.000");
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 參數設定 > 輸入表面精度
        private void tb_AccCur_parameter_surface_TextChanged(object sender, EventArgs e){
            try{
                //先將輸入值轉型，確保不是非法字元
                float tem = float.Parse(tb_AccCur_parameter_surface.Text);
                if((int)(tem * 1000) > tbar_AccCur_parameter_surface.Maximum){
                    MessageBox.Show("超出預設最大值。", "超出索引", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
                tbar_AccCur_parameter_surface.Value = (int)(tem * 1000);
                AccCur_parameter_LoadData();
            }
            catch { }
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 參數設定 > 新增工件材料
        private void btn_AccCur_parameter_workpieceAdd_Click(object sender,EventArgs e){
            panel_AccCur_parameter_Add.Visible = true;
            panel_AccCur_parameter_Add.BringToFront();
            lb_AccCur_parameter_Add.Text = "工件材料";
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 參數設定 > 新增砂輪規格
        private void btn_AccCur_parameter_type_Click(object sender, EventArgs e){
            panel_AccCur_parameter_Add.Visible = true;
            panel_AccCur_parameter_Add.BringToFront();
            lb_AccCur_parameter_Add.Text = "砂輪規格";
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 參數設定 > 新增 > 儲存
        private void btn_AccCur_parameter_Add_Save_Click(object sender,EventArgs e){
            if (string.IsNullOrWhiteSpace(lb_AccCur_parameter_Add.Text)){
                MessageBox.Show("新增內容不得為空。", "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }
            FileStream File_module = File.Open(path + @"\data\AccCur\AccCur_workpiece.cp", FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
            StreamWriter sw = new StreamWriter(File_module);
            sw.WriteLine(tb_AccCur_parameter_Add.Text);
            sw.Close();
            sw.Dispose();

            //重新讀取頁面
            AccCur_parameter_Load();
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 參數設定 > 新增 > 刪除
        private void btn_AccCur_parameter_Add_Delete_Click(object sender, EventArgs e){
            tb_AccCur_parameter_Add.Text = "";
            panel_AccCur_parameter_Add.Visible = false;
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 參數設定 > 工件材料選擇
        private void lb_AccCur_parameter_workpiece_SelectedIndexChanged(object sender, EventArgs e){
            AccCur_parameter_LoadData();
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 參數設定 > 砂輪規格選擇
        private void lb_AccCur_parameter_type_SelectedIndexChanged(object sender, EventArgs e){
            AccCur_parameter_LoadData();
        }
        //磨耗偵測 > 磨耗偵測(三軸、電流) > 參數設定 > 讀取各項加工參數
        private void AccCur_parameter_LoadData(){
            try{
                //精加工資料

                List<string> Read_Data = new List<string>();    //暫存讀取資料
                StreamReader sr = new StreamReader(string.Format(@"{0}\data\AccCur\database\{1}_{2}.csv", path, lb_AccCur_parameter_type.Text, lb_AccCur_parameter_workpiece.Text));
                sr.ReadLine();  //第一行為中文標題欄
                sr.ReadLine();  //第二行為英文標題欄
                while (!sr.EndOfStream)
                    Read_Data.Add(sr.ReadLine());
                sr.Close();
                sr.Dispose();

                //字串說明
                //1:砂輪號數(WA-??) 8:轉數 11:每次下降量 14:實際表面精度

                //找尋最接近使用者輸入的表面精度項目
                float Surface_Max = 0f; //暫存已讀取最大值
                int Surface_Count = 0;  //暫存已讀取最大值在陣列內的次序
                for(int i = 0; i < Read_Data.Count; i++){
                    float Now_Surface = float.Parse(Read_Data[i].Split(',')[14]);
                    //先判斷讀取的值比輸入的值還要小
                    if(Now_Surface < float.Parse(tb_AccCur_parameter_surface.Text)){
                        //判斷是否有比已讀取的最大值還要大
                        if (Now_Surface > Surface_Max){
                            Surface_Count = i;
                            Surface_Max = Now_Surface;
                        }
                    }
                }

                //讀取最大值次序的各項參數
                tb_AccCur_parameter_WheelNumber2.Text = Read_Data[Surface_Count].Split(',')[1].Split('-')[1];
                AccCur_parameter_WheelSpeed2.Text = Read_Data[Surface_Count].Split(',')[8];
                tb_AccCur_parameter_WheelDown2.Text = Read_Data[Surface_Count].Split(',')[11];
                tb_AccCur_parameter_Predict2.Text = Read_Data[Surface_Count].Split(',')[14];
            }
            catch{
            }
        }
        #endregion
        #endregion
        #region 選擇工件/新增工件
        //磨耗偵測 > 選擇工件 > 讀取資料
        private void SelectParts_LoadData() {
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
            for (int i = 0; i < panel_Parts.Length; i++) {
                panel_Parts[i].Visible = false;
                panel_Parts_Add[i].Visible = false;
            }
            int read_count = 0;
            while (!sr.EndOfStream) {
                //tem讀取範例：名稱,C:\Users\user\Desktop\Campro\ToolWear\ToolWear\bin\Debug\data\Image\IMG_3494.JPG
                string tem = sr.ReadLine();
                try {
                    if (read_count >= (int.Parse(lb_SelectParts_Page.Text) - 1) * 8 && read_count < int.Parse(lb_SelectParts_Page.Text) * 8) {
                        panel_Parts[read_count % 8].Visible = true;
                        lb_Parts[read_count % 8].Text = tem.Split(',')[0];
                        if (!tem.Split(',')[1].Equals("null")) {
                            using (var tem_img = Image.FromFile(tem.Split(',')[1])) {
                                Image img = new Bitmap(tem_img);
                                pb_Parts[read_count % 8].BackgroundImage = img;
                            }
                        }
                        else
                            pb_Parts[read_count % 8].BackgroundImage = ToolWear.Properties.Resources.wd_img_blank;
                    }
                    else if (read_count >= (int.Parse(lb_SelectParts_Page.Text) + 1) * 8) break;
                    read_count++;
                }
                catch (Exception ex) {
                    MessageBox.Show("讀取工件資料時出現不可測意外。\n可能是設定檔或是圖片檔遺失，請重新檢查。\n\nSelectParts_LoadData\n\n" + ex.ToString(), "讀取失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    break;
                }
            }
            sr.Close();
            sr.Dispose();
            //判斷是否此頁面還有空間塞入 + 號
            for (int i = 0; i < panel_Parts.Length; i++) {
                //如果panel的visible是false的話表示因為沒有資料所以不讀取，那就將該panel置換成新增工件
                if (panel_Parts[i].Visible == false) {
                    panel_Parts[i].Visible = true;
                    panel_Parts_Add[i].Visible = true;
                    panel_Parts_Add[i].BringToFront();
                    break;
                }
            }
        }
        //磨耗偵測 > 選擇工件 > 工件上一頁
        private void btn_SelectParts_up_Click(object sender, EventArgs e) {
            if (lb_SelectParts_Page.Text.Equals("1")) {
                MessageBox.Show("沒有辦法移至上一頁，已在首頁。", "頁面切換失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            lb_SelectParts_Page.Text = (int.Parse(lb_SelectParts_Page.Text) - 1).ToString();
            SelectParts_LoadData();
        }
        //磨耗偵測 > 選擇工件 > 工件下一頁
        private void btn_SelectParts_down_Click(object sender, EventArgs e) {
            StreamReader sr = new StreamReader(path + @"\data\parts.cp");
            int sr_count = 0;
            while (!sr.EndOfStream) {
                sr.ReadLine();
                sr_count++;
            }
            if (sr_count > int.Parse(lb_SelectParts_Page.Text) * 8) {
                lb_SelectParts_Page.Text = (int.Parse(lb_SelectParts_Page.Text) + 1).ToString();
                SelectParts_LoadData();
            }
            else {
                MessageBox.Show("沒有更多的工件，已在最後一頁！", "頁面切換失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
            sr.Close();
            sr.Dispose();
        }
        //磨耗偵測 > 選擇工件 > 移除工件
        private void btn_SelectParts_remove_Click(object sender, EventArgs e) {
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
            while (!sr.EndOfStream) {
                string tem = sr.ReadLine();
                //如果資料檔內的工件名稱 = 本次要刪除的名稱 > 不暫存此資料(意即等等要重新改寫cp檔的時候會忽略之)
                if (!tem.Split(',')[0].Equals(Parts_Name)) {
                    tem_Read.Add(tem);
                    //暫存圖片檔路徑
                    Delete_Path = tem.Split(',')[1];
                }
            }
            sr.Close();
            sr.Close();
            StreamWriter sw = new StreamWriter(path + @"\data\parts.cp");
            for (int i = 0; i < tem_Read.Count; i++)
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
            //刪除data內圖片檔案
            try {
                File.Delete(path + @"\data\Image\" + Parts_Name);
            }
            catch (Exception ex) {
                MessageBox.Show("刪除data圖片檔案時發生錯誤。\n\nbtn_SelectParts_remove_Click\n\n" + ex.ToString());
            }
        }
        //磨耗偵測 > 選擇工件 > select按鈕
        private void btn_SelectParts(object sender, EventArgs e) {
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
        private void btn_AddParts_delete_Click(object sender, EventArgs e) {
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
        private void btn_AddParts_Path_Click(object sender, EventArgs e) {
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
        private void btn_AddParts_save_Click(object sender, EventArgs e) {
            if (string.IsNullOrWhiteSpace(tb_AddParts_Name.Text) || string.IsNullOrEmpty(tb_AddParts_Name.Text)) {
                MessageBox.Show("請輸入工件名稱！", "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            if (string.IsNullOrWhiteSpace(tb_AddParts_Path.Text)) {
                DialogResult dialogResult1 = MessageBox.Show("您尚未選擇工件圖片來源\n確定不要加入圖片嗎？", "圖片未選取", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
                if (dialogResult1 == DialogResult.Cancel) return;
            }
            //檢查是否有非法字元
            if (Unlawful_Check(tb_AddParts_Name.Text)) return;
            //檢查是否有同樣名稱的工件
            StreamReader sr = new StreamReader(path + @"\data\parts.cp");
            while (!sr.EndOfStream) {
                string tem = sr.ReadLine();
                if (tem.Split(',')[0].Equals(tb_AddParts_Name.Text)) {
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

            try {
                FileStream File_module = File.Open(path + @"\data\parts.cp", FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
                StreamWriter sw = new StreamWriter(File_module);
                //有選圖片的話
                if (!string.IsNullOrWhiteSpace(tb_AddParts_Path.Text)) {
                    sw.WriteLine(tb_AddParts_Name.Text + "," + path + @"data\Image\" + tb_AddParts_Name.Text);
                    File.Copy(tb_AddParts_Path.Text, path + @"\data\Image\" + tb_AddParts_Name.Text);
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
                pb_AddParts.BackgroundImage = ToolWear.Properties.Resources.wdpsn_img_blank;
                pb_ToolWear_Click(null, null);
            }
            catch (Exception ex) {
                MessageBox.Show("在儲存時發生不可測意外。\n\nThis problem is from btn_AddParts_save.\n\n" + ex.ToString(), "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        #endregion
        #region 縮小視窗
        private void FormBorderMode(object sender, EventArgs e) {
            //縮小視窗
            this.WindowState = FormWindowState.Minimized;
        }
        #endregion
        #region 選擇按鈕(Up/Down)
        private void btn_ATCsetting_BladeUp_Click(object sender, EventArgs e) {
            if (numeric_ATCsetting_Blade.Value < numeric_ATCsetting_Blade.Maximum)
                numeric_ATCsetting_Blade.Value += 1;
        }
        private void btn_ATCsetting_BladeDown_Click(object sender, EventArgs e) {
            if (numeric_ATCsetting_Blade.Value > numeric_ATCsetting_Blade.Minimum)
                numeric_ATCsetting_Blade.Value -= 1;
        }
        private void btn_HealthSetting_Up_Click(object sender, EventArgs e) {
            if (numeric_HealthSetting_Range.Value < numeric_HealthSetting_Range.Maximum)
                numeric_HealthSetting_Range.Value += 1;
        }
        private void btn_HealthSetting_Down_Click(object sender, EventArgs e) {
            if (numeric_HealthSetting_Range.Value > numeric_HealthSetting_Range.Minimum)
                numeric_HealthSetting_Range.Value -= 1;
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
        private void btn_ToolWear_Choose(object sender, EventArgs e) {
            //目前只能單軸偵測
            for (int i = 0; i < 20; i++) {
                if (ToolWear_bool[i] == true) {
                    //MessageBox.Show("Beta階段只允許單軸偵測，請先關閉當前正在偵測的軸向再點選其他按鈕。", "嘗試選取多軸向", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    Write_Log("系統", "目前只允許單軸偵測，請先關閉當前正在偵測的軸向再點選其他按鈕。");
                    return;
                }
            }
            //先重置上次選到的按鈕
            if (pre_ToolWear != null) {
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
            if (ToolWear_bool[now_ToolWear] == true) {
                btn_ToolWear_Start.BackgroundImage = ToolWear.Properties.Resources.tc_btn_ply;
                btn_ToolWear_Stop.BackgroundImage = ToolWear.Properties.Resources.btn_stop_selected;
                btn_ToolWear_Start.Enabled = false;
                btn_ToolWear_Stop.Enabled = true;
            }
            else {
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
        private void btn_Learn_Choose(object sender, EventArgs e) {
            //如果正在學習中，不允許切換數據
            if (On_Learn == true) {
                MessageBox.Show("目前正處於學習階段，不允許切換軸向。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            if (runningTask != null) {
                MessageBox.Show("請先停止所有軸向的磨耗偵測。\n在學習模式中禁止同時偵測磨耗資訊，以免發生不可測意外。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            //先重置上次選到的按鈕
            if (pre_learn != null) {
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
            try {
                for (int i = 0; i < int.Parse(ID); i++) {
                    //初始化下拉選單
                    cb_ToolWearSetting_accelerometer.SelectedIndex = 0;
                    cb_ToolWearSetting_Axial.SelectedIndex = 0;
                    physicalChannelComboBox.SelectedIndex = 0;
                    //初始化電流參數
                    tb_ToolWear_CurrentIP.Text = "";
                    cb_ToolWear_CurrentInput.SelectedIndex = 0;
                    //ex. tem = "X,0,0,0" or tem = "Y,1,2,0"
                    string tem = sr_axial.ReadLine();
                    if (i == int.Parse(ID) - 1) {
                        tb_ToolWearSetting_name.Text = tem.Split(',')[0];
                        int Accelerometer = int.Parse(tem.Split(',')[1]);
                        cb_ToolWearSetting_accelerometer.SelectedIndex = Accelerometer;
                        int Axial = int.Parse(tem.Split(',')[2]);
                        cb_ToolWearSetting_Axial.SelectedIndex = Axial;
                        string tem_Channel = tem.Split(',')[3];
                        for (int j = 0; j < physicalChannelComboBox.Items.Count; j++) {
                            physicalChannelComboBox.SelectedIndex = j;
                            if (physicalChannelComboBox.Text.Equals(tem_Channel)) {
                                //physicalChannelComboBox.SelectedIndex = j;
                                break;
                            }
                            //如果j已搜尋到最後都找不到匹配的輸入(代表原先設定的訊號不見了)
                            if (j == physicalChannelComboBox.Items.Count - 1) {
                                physicalChannelComboBox.SelectedIndex = 0;
                                MessageBox.Show("搜尋不到此軸向原先設定的訊號輸入，請確認輸入訊號接頭是否脫落。\n重新連接設備並使用重新整理按鈕搜尋訊號輸入。" +
                                    "\n若依然找不到訊號輸入，請重新選擇並儲存。", "找不到訊號輸入", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            }
                        }
                        string ip = tem.Split(',')[4];
                        tb_ToolWear_CurrentIP.Text = ip;
                        string CurrentChannel = tem.Split(',')[5];
                        for (int j = 0; j < cb_ToolWear_CurrentInput.Items.Count; j++) {
                            cb_ToolWear_CurrentInput.SelectedIndex = j;
                            if (cb_ToolWear_CurrentInput.Text.Equals(CurrentChannel))
                                break;
                            //表示搜尋到最後仍然找不到匹配的輸入
                            if (j == cb_ToolWear_CurrentInput.Items.Count - 1)
                                cb_ToolWear_CurrentInput.SelectedIndex = 0;
                        }
                    }
                }
            }
            catch {

            }
            sr_axial.Close();
            sr_axial.Dispose();
        }
        //軸向設定 > 儲存
        private void btn_ToolWearSetting_save_Click(object sender, EventArgs e) {
            DialogResult dialogResult = MessageBox.Show("確定儲存？", "存檔訊息", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;
            string tem_s = string.Format("{0},{1},{2},{3},{4},{5}", tb_ToolWearSetting_name.Text,
                cb_ToolWearSetting_accelerometer.SelectedIndex, cb_ToolWearSetting_Axial.SelectedIndex, physicalChannelComboBox.Text,
                tb_ToolWear_CurrentIP.Text, cb_ToolWear_CurrentInput.Text);
            try {
                ToolWearSetting_SW(tem_s);
                MessageBox.Show("儲存成功！", "", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex) {
                MessageBox.Show("儲存失敗。\n\nbtn_ToolWearSetting_save_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //軸向設定 > 刪除
        private void btn_ToolWearSetting_delete_Click(object sender, EventArgs e) {
            DialogResult dialogResult = MessageBox.Show("確定要刪除此軸向之設定資料嗎？", "刪除警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            string tem_s = tb_ToolWearSetting_name.Text;
            try {
                ToolWearSetting_SW(tem_s);
                MessageBox.Show("刪除成功！", "", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex) {
                MessageBox.Show("刪除失敗。\n\nbtn_ToolWearSetting_delete_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //軸向設定 > 讀檔+寫檔
        private void ToolWearSetting_SW(string s) {
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
        private void btn_Compensate_Choose(object sender, EventArgs e) {
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
            while (!sr_axial.EndOfStream) {
                //ex tem = 1,25.0,1.00
                //編號(0~19),溫度,補償
                string tem = sr_axial.ReadLine();
                compensate_data.Add(tem);   //新增資料進暫存變數
                int number = int.Parse(tem.Split(',')[0]);
                if (number == now_Compensate) {
                    string temperature = tem.Split(',')[1];
                    string compensate = tem.Split(',')[2];
                    //將資料寫入TextBox內
                    for (int i = 0; i < tb_Compensate.Length; i++) {
                        if (tb_Compensate[i].Text == "") {
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
            try {
                for (int i = 0; i <= now_Compensate; i++) {
                    string tem = sr_set.ReadLine();
                    if (i == now_Compensate) {
                        tb_Compensate_ip.Text = tem.Split(',')[1];
                        //tb_Compensate_Channel.Text = tem.Split(',')[2];
                        for (int j = 0; j < cb_Compensate_Channel.Items.Count; j++) {
                            cb_Compensate_Channel.SelectedIndex = j;
                            if (cb_Compensate_Channel.Text.Equals(tem.Split(',')[2]))
                                break;
                            //當搜尋完所有選項後都沒有發現符合的文字(代表設定檔被修改過)
                            if (j == cb_Compensate_Channel.Items.Count - 1) {
                                cb_Compensate_Channel.SelectedIndex = 0;
                                MessageBox.Show("輸入訊號設定檔錯誤，請重新設定！", "設定檔錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            }
                        }
                    }
                }
            }
            catch {
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
            if (e == null) {
                for (int i = 0; i < tem_page - 1; i++)
                    btn_Compensate_down_Click(null, null);
            }
        }
        //IP和輸入 > 存檔
        private void btn_CompensateSet_save_Click(object sender, EventArgs e) {
            DialogResult dialogResult = MessageBox.Show("確定儲存？", "存檔訊息", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;
            string tem = pre_Compensate.Text + "," + tb_Compensate_ip.Text + "," + cb_Compensate_Channel.Text;
            try {
                RW_CompensateSet(tem);
                MessageBox.Show("IP與訊號輸入設定完成！", "儲存成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex) {
                MessageBox.Show("儲存失敗。\n\nbtn_CompensateSet_save_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //IP和輸入 > 刪除
        private void btn_CompensateSet_delete_Click(object sender, EventArgs e) {
            DialogResult dialogResult = MessageBox.Show("確定要刪除此軸向之設定資料嗎？", "刪除警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            string tem = ((Button)pre_Compensate).Text + ", , ";
            try {
                RW_CompensateSet(tem);
                MessageBox.Show("IP與訊號輸入刪除成功！");
            }
            catch (Exception ex) {
                MessageBox.Show("刪除失敗。\n\nbtn_CompensateSet_delete_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //IP和輸入 > 讀檔+寫檔
        private void RW_CompensateSet(string s) {
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
        private void tb_Compensate_Click(object sender, EventArgs e) {
            TextBox tb_Compensate = ((TextBox)sender);
            if (pre_Compensate_tb != null)
                pre_Compensate_tb.BackColor = Color.WhiteSmoke;
            tb_Compensate.BackColor = Color.CadetBlue;
            pre_Compensate_tb = tb_Compensate;
            //如果選擇的TextBox是空的那就顯示預設值
            if (tb_Compensate.Text.Equals("")) {
                tb_Compensate_Select = -1;
                numeric_Temperature.Value = 25.0M;
                numeric_Compensate.Value = 1.00M;
            }
            else {
                tb_Compensate_Select = int.Parse(tb_Compensate.Name.Split('_')[2]);
                numeric_Temperature.Value = decimal.Parse(tb_Compensate.Text.Split(',')[1].Split(' ')[1]);
                numeric_Compensate.Value = decimal.Parse(tb_Compensate.Text.Split(',')[2].Split(' ')[1]);
            }
        }
        //清除溫補選取
        private void tb_Compensate_Clear() {
            tb_Compensate_Select = -1;
            numeric_Temperature.Value = 25.0M;
            numeric_Compensate.Value = 1.00M;
            if (pre_Compensate_tb != null) {
                pre_Compensate_tb.BackColor = Color.WhiteSmoke;
                pre_Compensate_tb = null;
            }
        }
        //溫補 > 上一頁
        private void btn_Compensate_up_Click(object sender, EventArgs e) {
            if (!lb_Compensate_page.Text.Equals("1")) {
                //宣告溫升補償顯示TextBox欄位
                TextBox[] tb_Compensate = new TextBox[7] { tb_Compensate_01 , tb_Compensate_02 , tb_Compensate_03 ,
                tb_Compensate_04,tb_Compensate_05,tb_Compensate_06,tb_Compensate_07};
                //先暫存陣列內此按鈕的補償資料
                List<string> now_Data = new List<string>();
                for (int i = 0; i < compensate_data.Count; i++) {
                    if (int.Parse(compensate_data[i].Split(',')[0]) == now_Compensate)
                        now_Data.Add(compensate_data[i]);
                }
                for (int i = 0; i < tb_Compensate.Length; i++) {
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
        private void btn_Compensate_down_Click(object sender, EventArgs e) {
            //宣告溫升補償顯示TextBox欄位
            TextBox[] tb_Compensate = new TextBox[7] { tb_Compensate_01 , tb_Compensate_02 , tb_Compensate_03 ,
            tb_Compensate_04,tb_Compensate_05,tb_Compensate_06,tb_Compensate_07};
            //先判斷暫存陣列內有幾個此按鈕的補償資料
            List<string> now_Data = new List<string>();
            for (int i = 0; i < compensate_data.Count; i++) {
                if (int.Parse(compensate_data[i].Split(',')[0]) == now_Compensate)
                    now_Data.Add(compensate_data[i]);
            }
            //當暫存數量大於第N頁 * 7個TextBox 的時候才可以按下一頁
            if (now_Data.Count > int.Parse(lb_Compensate_page.Text) * tb_Compensate.Length) {
                for (int i = 0; i < tb_Compensate.Length; i++) {
                    //判斷是否現在讀取的項次小於總共暫存數量
                    if (now_Data.Count > (int.Parse(lb_Compensate_page.Text) * tb_Compensate.Length) + i) {
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
        //溫補 > 溫度+0.1
        private void numeric_Temperature_Up_Click(object sender, EventArgs e) {
            numeric_Temperature.Value += (decimal)0.1;
        }
        //溫補 > 溫度-0.1
        private void numeric_Temperature_Down_Click(object sender, EventArgs e) {
            numeric_Temperature.Value -= (decimal)0.1;
        }
        //溫補 > 補償值+0.01
        private void numeric_Compensate_Up_Click(object sender, EventArgs e) {
            numeric_Compensate.Value += (decimal)0.01;
        }
        //溫補 > 補償值-0.01
        private void numeric_Compensate_Down_Click(object sender, EventArgs e) {
            numeric_Compensate.Value -= (decimal)0.01;
        }
        //溫補 > 新增
        private void btn_CompensateAdd_Click(object sender, EventArgs e) {
            //取得button後面編號
            string tem = (int.Parse(pre_Compensate.Name.Split('_')[2]) - 1).ToString() + "," +
                numeric_Temperature.Value + "," + numeric_Compensate.Value;
            try {
                FileStream File_module = File.Open(path + @"\data\compensate.cp", FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
                StreamWriter sw = new StreamWriter(File_module);
                sw.WriteLine(tem);
                sw.Close();
                sw.Dispose();
                //儲存完後執行初始化方法，重新載入文字
                Initialization();
                btn_Compensate_Choose((object)pre_Compensate, null);
            }
            catch (Exception ex) {
                MessageBox.Show("發生不可測意外。\n\nbtn_CompensateAdd_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //溫補 > 儲存
        private void btn_CompensateSave_Click(object sender, EventArgs e) {
            if (pre_Compensate_tb == null) {
                MessageBox.Show("尚未選取欲修改的項目，\n若您是要新增一筆資料請點選 + 按鈕。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            if (tb_Compensate_Select == -1) {
                string output = "";
                if (pre_Compensate_tb.Text.Equals(""))
                    output = "您正準備存取尚未擁有初始值的項目，\n請使用 + 符號新增資料。";
                else
                    output = "尚未選擇要儲存的項目，請點選下方空格。";
                MessageBox.Show(output, "儲存失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            DialogResult dialogResult = MessageBox.Show("確定儲存？", "存檔訊息", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;
            //取得button後面編號
            string tem = (int.Parse(pre_Compensate.Name.Split('_')[2]) - 1).ToString() + "," +
                numeric_Temperature.Value + "," + numeric_Compensate.Value;
            try {
                RW_Compensate(tem, false);
            }
            catch (Exception ex) {
                MessageBox.Show("發生不可測意外。\n\nbtn_CompensateSave_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //溫補 > 移除
        private void btn_CompensateRemove_Click(object sender, EventArgs e) {
            if (tb_Compensate_Select == -1) {
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
            try {
                RW_Compensate(tem, true);
            }
            catch (Exception ex) {
                MessageBox.Show("發生不可測意外。\n\nbtn_CompensateRemove_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        /// <summary>
        /// 溫補 > 讀檔寫檔
        /// </summary>
        /// <param name="s">要修改的字串</param>
        /// <param name="remove">是否為移除模式</param>
        private void RW_Compensate(string s, bool remove) {
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
            for (int i = 0; i < tem_read.Count; i++) {
                //查詢是不是此軸向的資料
                if (int.Parse(tem_read[i].Split(',')[0]) == now_Compensate) {
                    //判斷是否已查詢到要修改的項次資料
                    if (count + tb_Compensate_Select > (int.Parse(lb_Compensate_page.Text) - 1) * tb_Compensate.Length) {
                        if (count % tb_Compensate.Length == tb_Compensate_Select - 1) {
                            //判斷是否位於移除模式
                            if (remove == false)
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
        private void btn_ATCSetting_Choose(object sender, EventArgs e) {
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
            try {
                for (int i = 0; i < int.Parse(ID); i++) {
                    //初始化輸入框
                    tb_ATCsetting_Name.Text = "";
                    numeric_ATCsetting_Blade.Value = 4;
                    //ex. tem = "1,test,6" or tem = "2,,"
                    string tem = sr_ATC.ReadLine();
                    if (i == int.Parse(ID) - 1) {
                        tb_ATCsetting_Name.Text = tem.Split(',')[1];
                        numeric_ATCsetting_Blade.Value = decimal.Parse(tem.Split(',')[2]);
                    }
                }
            }
            catch {
            }
            sr_ATC.Close();
            sr_ATC.Dispose();
        }
        //刀庫設定 > 存檔
        private void btn_ATCsetting_save_Click(object sender, EventArgs e) {
            DialogResult dialogResult = MessageBox.Show("確定儲存？", "存檔訊息", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);
            if (dialogResult == DialogResult.Cancel) return;
            string tem = pre_ATCSetting.Text + "," + tb_ATCsetting_Name.Text + "," + numeric_ATCsetting_Blade.Value;
            try {
                RW_TCsetting(tem);
                MessageBox.Show("刀具名稱與刃數存檔成功！", "儲存成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex) {
                MessageBox.Show("發生不可測意外。\n\nbtn_ATCsetting_save_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //刀庫設定 > 刪除
        private void btn_ATCsetting_delete_Click(object sender, EventArgs e) {
            DialogResult dialogResult = MessageBox.Show("確定要刪除此刀具之設定資料嗎？", "刪除警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            string tem = ((Button)pre_ATCSetting).Text + ",,";
            try {
                RW_TCsetting(tem);
                MessageBox.Show("刀具名稱與刃數刪除成功！", "刪除成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex) {
                MessageBox.Show("發生不可測意外。\n\nbtn_ATCsetting_delete_Click\n\n" + ex.ToString(), "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //刀庫設定 > 讀檔+寫檔
        private void RW_TCsetting(string s) {
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
        private void cb_ToolWearSetting_accelerometer_SelectedIndexChanged(object sender, EventArgs e) {
            cb_ToolWearSetting_Axial.Items.Clear();
            if (cb_ToolWearSetting_accelerometer.SelectedIndex == 0)
                cb_ToolWearSetting_Axial.Items.Add("未選擇");
            if (cb_ToolWearSetting_accelerometer.SelectedIndex == 1)
                cb_ToolWearSetting_Axial.Items.Add("單向");
            else if (cb_ToolWearSetting_accelerometer.SelectedIndex == 2) {
                cb_ToolWearSetting_Axial.Items.Add("X軸");
                cb_ToolWearSetting_Axial.Items.Add("Y軸");
                cb_ToolWearSetting_Axial.Items.Add("Z軸");
            }
        }
        //主選單 > 設定 > 選擇CNC廠牌
        private void cb_setting_brand_SelectedIndexChanged(object sender, EventArgs e) {
            cb_setting_model.Items.Clear();
            cb_setting_model.Items.Add("選擇型號");
            switch (cb_setting_brand.Text) {
                case "Mitsubishi":
                    cb_setting_model.Items.Add("M800");
                    break;
                case "Brother":
                    cb_setting_model.Items.Add("S700Z1");
                    break;
                case "Fanuc":
                    cb_setting_model.Items.Add("16i");
                    break;
            }
            cb_setting_model.SelectedIndex = 0;
        }
        #endregion
        #region 文字變更事件
        //暫存刀號
        int ATC_num = 0;
        private void lb_ToolWear_Tool_TextChanged(object sender, EventArgs e) {
            try {
                ATC_num = int.Parse(((Label)sender).Text);
                if (ATC_num > 20) {
                    ATC_num = 0;
                    ((Label)sender).Text = "預設";
                    lb_ToolWear_Blade.Text = "4";
                    return;
                }
            }
            catch {
                //會進到catch表示Text資料過大或有誤，直接return
                return;
            }
            try {
                StreamReader sr = new StreamReader(path + @"\data\ATC.cp");
                for (int i = 0; i < ATC_num; i++) {
                    string tem = sr.ReadLine();
                    if (i != ATC_num - 1) continue;
                    ((Label)sender).Text = tem.Split(',')[1];
                    lb_ToolWear_Blade.Text = tem.Split(',')[2];
                }
                sr.Close();
                sr.Dispose();
            }
            catch (Exception ex) {
                MessageBox.Show("讀取刀庫設定檔時發生錯誤。\n\nError code : \n" + ex.ToString());
            }
        }
        private void lb_Learn_Tool_TextChanged(object sender, EventArgs e) {
            try {
                ATC_num = int.Parse(((Label)sender).Text);
                if (ATC_num > 20) {
                    ((Label)sender).Text = "預設";
                    lb_Learn_Blade.Text = "4";
                    return;
                }
            }
            catch {
                //會進到catch表示Text資料過大或有誤，直接return
                return;
            }
            try {
                int ATC_num = int.Parse(((Label)sender).Text);
                StreamReader sr = new StreamReader(path + @"\data\ATC.cp");
                for (int i = 0; i < ATC_num; i++) {
                    string tem = sr.ReadLine();
                    if (i != ATC_num - 1) continue;
                    ((Label)sender).Text = tem.Split(',')[1];
                    lb_Learn_Blade.Text = tem.Split(',')[2];
                }
                sr.Close();
                sr.Dispose();
            }
            catch (Exception ex) {
                MessageBox.Show("讀取刀庫設定檔時發生錯誤。\n\nError code : \n" + ex.ToString());
            }
        }
        #endregion
        #endregion
        #region Timer事件
        private void timer_temperature_Tick(object sender, EventArgs e) {
            Thread TD_FakeData = new Thread(Thermal_FakeData);
            TD_FakeData.Start();
        }

        private void timer_LNC_Tick(object sender, EventArgs e) {
            LNC_GetData();
        }
        private void timer_Current_Tick(object sender, EventArgs e) {
            //Current_Getdata("33");
            Current_Getdata_Schneider("1");
        }
        //開始執行磨耗預測
        private void timer_Prediction_Tick(object sender, EventArgs e){
            if (lb_prediction_status.Text.Equals("8")){
                //如果已經有偵測在運行了就直接跳過程式
                if (runningTask != null) return;

                //清空Raw_Data.csv
                StreamWriter sw_Raw_Data = new StreamWriter(path + @"Raw_Data.csv");
                sw_Raw_Data.WriteLine("x,y,z");
                sw_Raw_Data.Close();
                sw_Raw_Data.Dispose();

                DAQInitialize("Prediction");
            }
            else{
                if (runningTask == null) return;
                TaskStop();
                //計數器+1
                Prediction_AutoMode_Count++;

                //呼叫exe
                Process.Start(path + @"SE_ML.exe");

                //歸零進度條
                PB_prediction_ML.Value = 0;
                //啟動timer讀取結果
                timer_prediction_ML.Enabled = true;

                //判斷是否為自動模式且已達計數標準
                if (Prediction_TrainMode.Equals("自動") && Prediction_AutoMode_Count % int.Parse(cb_prediction_TrainTime.Text.Split('次')[0]) == 0){
                    lb_prediction_TrainMode.Text = string.Format("{0}({1},{2})", Prediction_TrainMode, Prediction_AutoMode_Count, cb_prediction_TrainTime.Text.Split('次')[0]);
                    Thread.Sleep(300);
                    btn_prediction_self_Click(null, null);
                }
            }
        }
        //機器學習
        private void timer_prediction_ML_Tick(object sender, EventArgs e){
            if (PB_prediction_ML.Value != PB_prediction_ML.Maximum) PB_prediction_ML.Value++;
            PB_prediction_ML.Visible = true;
            //讀取結果txt
            List<string> Read_List = new List<string>();
            StreamReader sr = new StreamReader(path + @"SE_ML_R.txt");
            string time = sr.ReadLine();    //暫存時間(2019-05-15_12_59)
            if (!time.Equals(DateTime.Now.ToString("yyyy-MM-dd_HH_mm"))){
                sr.Close();
                sr.Dispose();
                return;    //表示背景程式還沒跑完
            }

            while (!sr.EndOfStream) Read_List.Add(sr.ReadLine());
            sr.Close();
            sr.Dispose();

            //將結果放到TextBox
            TextBox[] tb_prediction = new TextBox[8] { tb_prediction_Result,tb_prediction_ToolStatus,tb_prediction_Xmax,
                        tb_prediction_Ymax,tb_prediction_Zmax,tb_prediction_Xmin,tb_prediction_Ymin,tb_prediction_Zmin};
            for (int i = 0; i < tb_prediction.Length; i++)
                tb_prediction[i].Text = Read_List[i];

            //執行結束
            timer_prediction_ML.Enabled = false;
            PB_prediction_ML.Value = 100;
        }
        //自我學習
        private void timer_prediction_SL_Tick(object sender, EventArgs e){
            if (PB_prediction_SL.Value != PB_prediction_SL.Maximum) PB_prediction_SL.Value++;
            PB_prediction_SL.Visible = true;
            //讀取結果txt
            StreamReader sr = new StreamReader(path + @"SE_SL_R.txt");
            string time = sr.ReadLine();    //暫存時間(2019-05-15_12_59)
            if (!time.Equals(DateTime.Now.ToString("yyyy-MM-dd_HH_mm"))){
                sr.Close();
                sr.Dispose();
                return;
            }

            string tem_s = sr.ReadLine();
            sr.Close();
            sr.Dispose();

            //將結果放到TextBox
            tb_prediction_Accuracy.Text = tem_s;

            //執行結束
            timer_prediction_SL.Enabled = false;
            PB_prediction_SL.Value = 100;
        }

        //暫存上次讀取的RPM數據
        double LastReload_RPM = 0;
        private void timer_CNC_Tick(object sender,EventArgs e){
            if (machine_type.Equals("Mitsubishi")){
                ATC_RPM = Mitsubishi_GetFeedSpeed();
                ATC_num = Mitsubishi_GetATCStatus();
                lb_prediction_status.Text = Mitsubishi_GetMemoryData("M4992").ToString();
            }
            else if (machine_type.Equals("Brother")){
                ATC_RPM = double.Parse(Brother_GetFeedSpeed());
                ATC_num = int.Parse(Brother_GetATCStatus());
            }
            lb_ToolWear_FeedSpeed.Text = ATC_RPM.ToString() + " RPM";
            lb_Learn_FeedSpeed.Text = ATC_RPM.ToString() + " RPM";
            lb_ToolWear_Tool.Text = ATC_num.ToString();
            lb_Learn_Tool.Text = ATC_num.ToString();

            //以下未測試
            //判斷當處於磨耗偵測模式時才重新讀取FFT圖形
            if (On_Learn == false){
                //查詢是否有軸向正在偵測
                bool On_ToolWear = false;
                for (int i = 0; i < 20; i++){
                    if (ToolWear_bool[i] == true){
                        On_ToolWear = true;
                        break;
                    }
                }
                //沒有軸向正在被偵測
                if (On_ToolWear == false) return;
            }

            //如果轉速和之前一樣不重新讀取
            double reload_RPM = ATC_RPM;
            if (ATC_RPM == 0) reload_RPM = 2500;
            if (reload_RPM == LastReload_RPM) return;

            //判斷輸入裝置然後給予頻率
            double rate = 0, sample = 0;
            if (physicalChannelComboBox.Text.Split('-')[0].Equals("LNC")){
                rate = 1660;
                sample = 166;
            }
            else{
                rate = rateNumeric_base;
                sample = samplesPerChannelNumeric_base;
            }

            //重新讀取磨耗偵測FFT比對圖形
            try{
                StreamReader sr = new StreamReader(path + @"data\FFT\L-" + lb_ToolWear_Parts.Text +
                                                    pre_ToolWear.Name.Split('_')[2] + "-" + ATC_num +
                                                    "_" + reload_RPM + ".cp");
                Module_FFT.Clear();
                chart_FFT.Series[0].Points.Clear();
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
                LastReload_RPM = reload_RPM;
            }
            catch{
                //進到例外表示沒有當前轉速/刀號的學習紀錄檔，可忽略
            }
        }
        private void timer_FakeData_Tick(object sender,EventArgs e){
            machine_connect = true;
            Random ran = new Random();
            ATC_RPM = 1000 + ran.Next(0, 201);
            lb_Learn_FeedSpeed.Text = ATC_RPM + " RPM";
            lb_ToolWear_FeedSpeed.Text = ATC_RPM + " RPM";
            ATC_num = ran.Next(1,6);
            lb_Learn_Tool.Text = ATC_num.ToString();
            lb_ToolWear_Tool.Text = ATC_num.ToString();
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
        private double samplesPerChannelNumeric_base = 800;  //取樣數(基準)
        private double rateNumeric_base = 4000;  //頻率(基準)
        private double samplesPerChannelNumeric = 800;  //取樣數
        private double rateNumeric = 4000;  //頻率
        private int Chart_max = 4000;   //波形圖樣本數
        private double minimumValueNumeric = -5, maximumValueNumeric = 5, sensitivityNumeric = 10.01, excitationValueNumeric = 0.002;
        delegate void DAQChannelDelegate();
        private void DAQPhysicalChannels(){
            if (this.InvokeRequired){
                DAQChannelDelegate DAQD = new DAQChannelDelegate(DAQPhysicalChannels);
                this.Invoke(DAQD);
            }
            else{
                physicalChannelComboBox.Items.Clear();
                physicalChannelComboBox.Items.Add("請選擇訊號輸入");
                //DAQ實體訊號輸入端點讀取
                dataTable = new DataTable();
                try{
                    physicalChannelComboBox.Items.AddRange(DaqSystem.Local.GetPhysicalChannels(PhysicalChannelTypes.AI, PhysicalChannelAccess.External));
                    if (physicalChannelComboBox.Items.Count > 0)
                        physicalChannelComboBox.SelectedIndex = 0;
                }
                catch{
                    tb_Load_log.Text += "DAQ訊號讀取失敗。\n";
                }
            }
            
        }
        /// <summary>
        /// DAQ參數初始化
        /// </summary>
        /// <param name="DAQ">輸入目前擷取到的資料要使用的地方</param>
        private void DAQInitialize(string DAQ){
            if (runningTask == null){
                try{
                    //參數設定
                    if (DAQ.Equals("AccCur")){
                        samplesPerChannelNumeric_base = 2000;
                        rateNumeric = 2000;
                    }
                    else if (DAQ.Equals("AE")){
                        samplesPerChannelNumeric_base = 5000;
                        rateNumeric = 10000;
                    }
                    else
                    {
                        samplesPerChannelNumeric_base = 800;
                        rateNumeric = 4000;
                    }
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
                    //三軸專用
                    if (DAQ.Equals("Prediction")){
                        for(int i = 1; i <= 3; i++){
                            physicalChannelComboBox.SelectedIndex = i;
                            aiChannel = myTask.AIChannels.CreateAccelerometerChannel(physicalChannelComboBox.Text, "",
                                terminalConfiguration, Convert.ToDouble(minimumValueNumeric), Convert.ToDouble(maximumValueNumeric),
                                Convert.ToDouble(sensitivityNumeric), sensitivityUnits, excitationSource,
                                Convert.ToDouble(excitationValueNumeric), AIAccelerationUnits.G);

                            // Setup the input coupling
                            if (i == 3)
                                aiChannel.Coupling = inputCoupling;
                        }
                    }
                    //三軸&電流
                    else if (DAQ.Equals("AccCur")){
                        ComboBox[] cb_Channel = new ComboBox[4] { cb_AccCur_setting_ChannelX, cb_AccCur_setting_ChannelY,
                            cb_AccCur_setting_ChannelZ,cb_AccCur_setting_ChannelC};
                        for (int i = 1; i <= 4; i++){
                            //前三項為加速度
                            if (i <= 3){
                                aiChannel = myTask.AIChannels.CreateAccelerometerChannel(cb_Channel[i - 1].Text, "",
                                    terminalConfiguration, Convert.ToDouble(minimumValueNumeric), Convert.ToDouble(maximumValueNumeric),
                                    Convert.ToDouble(sensitivityNumeric), sensitivityUnits, excitationSource,
                                    Convert.ToDouble(excitationValueNumeric), AIAccelerationUnits.G);
                                aiChannel.Coupling = inputCoupling;
                            }
                            //第四項為電流
                            else if(i == 4){
                                myTask.AIChannels.CreateCurrentChannel(cb_Channel[i - 1].Text, "",
                                    (AITerminalConfiguration)(-1), Convert.ToDouble("0.000"),
                                    Convert.ToDouble("0.020"), AICurrentUnits.Amps);
                            }

                        }
                    }
                    //音頻
                    else if (DAQ.Equals("AE")){
                        myTask.AIChannels.CreateVoltageChannel(cb_AccCur_setting_ChannelAE.Text, "",
                            (AITerminalConfiguration)(-1), Convert.ToDouble("-10"), Convert.ToDouble("10"), AIVoltageUnits.Volts);
                    }
                    //正常情況使用此
                    else{
                        aiChannel = myTask.AIChannels.CreateAccelerometerChannel(physicalChannelComboBox.Text, "",
                            terminalConfiguration, Convert.ToDouble(minimumValueNumeric), Convert.ToDouble(maximumValueNumeric),
                            Convert.ToDouble(sensitivityNumeric), sensitivityUnits, excitationSource,
                            Convert.ToDouble(excitationValueNumeric), AIAccelerationUnits.G);
                        // Setup the input coupling
                        aiChannel.Coupling = inputCoupling;
                    }
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
                    
                }
                catch (DaqException exception)
                {
                    // Display Errors
                    if(exception.Error == -200431 || exception.Error == -200220){
                        MessageBox.Show("無法初始化選取的訊號輸入，請確認設定檔內的訊號輸入是否正確，\n或是檢查是否有讀取到原先所設置的訊號。", "偵測啟動失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        btn_ToolWear_Stop_Click(null, null);
                        btn_Learn_OK_Click(null, null);
                    }
                    else
                    {
                        Write_Log("系統","DAQ正在嘗試自我修復...");
                        //MessageBox.Show(exception.Message);
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
            try { myTask.Dispose(); }
            catch { }
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
            catch{
                // Display Errors
                //MessageBox.Show(exception.Message);
                //Write_Log("系統", "DAQ正在嘗試自我修復。");
                TaskStop();
                //嘗試自我修復
                DAQInitialize(DAQ_Now);
            }
        }
        private List<string> tem_DT = new List<string>();
        private List<string> tem_Match_DT = new List<string>();
        private List<string> tem_Factory_DT = new List<string>();
        private List<string> tem_Factory_Max = new List<string>();
        private List<string> tem_AfterSale_DT = new List<string>();
        private List<string> tem_AfterSale_Max = new List<string>();
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
                if (tem_Match_DT.Count > Chart_max - 1) tem_Match_DT.RemoveRange(0, (int)samplesPerChannelNumeric - 1);
                try { chart_ToolWear.Series[0].Points.Clear(); }
                catch { }
                FileStream File_match = File.Open(path + @"data\match.cp", FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
                StreamWriter sw = new StreamWriter(File_match);
                for (int i = 0; i < (int)samplesPerChannelNumeric - 1; i++){
                    tem_Match_DT.Add(dataTable.Rows[i][0].ToString());
                    sw.WriteLine(dataTable.Rows[i][0].ToString());
                }
                for (int i = 0; i < tem_Match_DT.Count; i++){
                    chart_ToolWear.Series[0].Points.AddXY(i + 1, tem_Match_DT[i]);
                }
                sw.Close();
                sw.Dispose();
                FFT(DAQ_Now, dataTable,(int)samplesPerChannelNumeric_base, (int)rateNumeric_base);
                #endregion
            }
            //模型建置狀態下執行
            else if (DAQ_Now.Equals("Learn")){
                #region 模型建置程式
                try{
                    FileStream File_module = File.Open(path + @"\data\module.cp", FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
                    StreamWriter sw = new StreamWriter(File_module);
                    if (tem_DT.Count > Chart_max - 1) tem_DT.RemoveRange(0, (int)samplesPerChannelNumeric - 1);
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
            else if (DAQ_Now.Equals("Factory")){
                #region 健康診斷/出場檢測
                //繪製折線圖
                if (tem_Factory_DT.Count > Chart_max - 1) tem_Factory_DT.RemoveRange(0, (int)samplesPerChannelNumeric_base);
                try { chart_Health.Series[0].Points.Clear(); }
                catch { }
                for (int i = 0; i < (int)samplesPerChannelNumeric_base; i++){
                    tem_Factory_DT.Add(dataTable.Rows[i][0].ToString());
                }
                for (int i = 0; i < tem_Factory_DT.Count; i++){
                    chart_Health.Series[0].Points.AddXY(i + 1, tem_Factory_DT[i]);
                }
                //讀取最大值檔案
                StreamReader sr = new StreamReader(path + @"data\Health\Factory_" + lb_Health_Machine.Text + ".cp");
                int sr_count = 0;
                while (!sr.EndOfStream){
                    tem_Factory_Max[sr_count] = sr.ReadLine();
                    sr_count++;
                }
                sr.Close();
                sr.Dispose();
                //FFT
                Complex[] samples = new Complex[(int)samplesPerChannelNumeric_base];
                for (int i = 0; i < (int)samplesPerChannelNumeric_base; i++)
                    samples[i] = new Complex(double.Parse(dataTable.Rows[i][0].ToString()), 0);
                try
                { chart_Health_FFT.Series[0].Points.Clear(); }
                catch
                { }
                Fourier.Forward(samples, FourierOptions.NoScaling);
                for (int i = 0; i < (int)samplesPerChannelNumeric_base / 2; i++){
                    double mag = (4.0 / (int)samplesPerChannelNumeric_base) * (Math.Abs(Math.Sqrt(Math.Pow(samples[i].Real, 2)
                        + Math.Pow(samples[i].Imaginary, 2))));
                    double hz = (double)rateNumeric_base / (double)samplesPerChannelNumeric_base;
                    chart_Health_FFT.Series[0].Points.AddXY(hz * (i + 1), mag);
                    //找尋最大值
                    if (mag > double.Parse(tem_Factory_Max[i]))
                        tem_Factory_Max[i] = mag.ToString();
                }
                //寫回最大值檔案
                StreamWriter sw_Max = new StreamWriter(path + @"data\Health\Factory_" + lb_Health_Machine.Text + ".cp");
                for (int i = 0; i < tem_Factory_Max.Count; i++){
                    sw_Max.WriteLine(tem_Factory_Max[i]);
                }
                sw_Max.Close();
                sw_Max.Dispose();
                #endregion
            }
            else if (DAQ_Now.Equals("AfterSale")){
                #region 健康診斷/售後檢測

                //儲存原始震動資料
                if (tem_AfterSale_DT.Count > Chart_max - 1) tem_AfterSale_DT.RemoveRange(0, (int)samplesPerChannelNumeric_base);
                for (int i = 0; i < (int)samplesPerChannelNumeric_base; i++){
                    tem_AfterSale_DT.Add(dataTable.Rows[i][0].ToString());
                }

                //讀取最大值檔案
                StreamReader sr = new StreamReader(path + @"data\Health\AfterSale_" + lb_Health_Machine.Text + ".cp");
                int sr_count = 0;
                while (!sr.EndOfStream){
                    tem_AfterSale_Max[sr_count] = sr.ReadLine();
                    sr_count++;
                }
                sr.Close();
                sr.Dispose();

                //FFT
                Complex[] samples = new Complex[(int)samplesPerChannelNumeric_base];
                for (int i = 0; i < (int)samplesPerChannelNumeric_base; i++)
                    samples[i] = new Complex(double.Parse(dataTable.Rows[i][0].ToString()), 0);
                try
                { chart_Health_Match.Series[0].Points.Clear(); }
                catch
                { }
                Fourier.Forward(samples, FourierOptions.NoScaling);
                for (int i = 0; i < (int)samplesPerChannelNumeric_base / 2; i++){
                    double mag = (4.0 / (int)samplesPerChannelNumeric_base) * (Math.Abs(Math.Sqrt(Math.Pow(samples[i].Real, 2)
                        + Math.Pow(samples[i].Imaginary, 2))));
                    double hz = (double)rateNumeric_base / (double)samplesPerChannelNumeric_base;
                    chart_Health_Match.Series[0].Points.AddXY(hz * (i + 1), mag);
                    //找尋最大值
                    if (mag > double.Parse(tem_AfterSale_Max[i]))
                        tem_AfterSale_Max[i] = mag.ToString();
                }

                //寫回最大值檔案
                StreamWriter sw_Max = new StreamWriter(path + @"data\Health\AfterSale_" + lb_Health_Machine.Text + ".cp");
                for (int i = 0; i < tem_AfterSale_Max.Count; i++){
                    sw_Max.WriteLine(tem_AfterSale_Max[i]);
                }
                sw_Max.Close();
                sw_Max.Dispose();
                #endregion
            }
            else if (DAQ_Now.Equals("Prediction")){
                #region 刀具磨耗預測
                chart_prediction_X.Series[0].Points.Clear();
                chart_prediction_Y.Series[0].Points.Clear();
                chart_prediction_Z.Series[0].Points.Clear();
                FileStream File_module = File.Open(path + @"Raw_Data.csv", FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
                StreamWriter sw = new StreamWriter(File_module);
                for (int i = 0;i< dataTable.Rows.Count; i++){
                    chart_prediction_X.Series[0].Points.AddXY(i, dataTable.Rows[i][0]);
                    chart_prediction_Y.Series[0].Points.AddXY(i, dataTable.Rows[i][1]);
                    chart_prediction_Z.Series[0].Points.AddXY(i, dataTable.Rows[i][2]);
                    if(!string.IsNullOrWhiteSpace(dataTable.Rows[i][0].ToString()))
                        sw.WriteLine(dataTable.Rows[i][0] + "," + dataTable.Rows[i][1] + "," + dataTable.Rows[i][2]);
                }
                sw.Close();
                sw.Dispose();
                #endregion
            }
            else if (DAQ_Now.Equals("AccCur")){
                #region 磨耗偵測(三軸、電流)
                chart_AccCur_X.Series[0].Points.Clear();
                chart_AccCur_Y.Series[0].Points.Clear();
                chart_AccCur_Z.Series[0].Points.Clear();
                chart_AccCur_Current.Series[0].Points.Clear();

                for (int i = 0; i < dataTable.Rows.Count; i++){
                    chart_AccCur_X.Series[0].Points.AddXY(i, dataTable.Rows[i][0]);
                    chart_AccCur_Y.Series[0].Points.AddXY(i, dataTable.Rows[i][1]);
                    chart_AccCur_Z.Series[0].Points.AddXY(i, dataTable.Rows[i][2]);
                    chart_AccCur_Current.Series[0].Points.AddXY(i, dataTable.Rows[i][3]);
                }
                //若有勾選紀錄資料則記錄每一個軸向資料
                if(chb_AccCur_Record.Checked == true){
                    string[] Acc_path = new string[4] { @"data\AccCur\X.csv", @"data\AccCur\Y.csv", @"data\AccCur\Z.csv", @"data\AccCur\Cur.csv" };
                    for(int i = 0; i < Acc_path.Length; i++){
                        FileStream File_module = File.Open(path + Acc_path[i], FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
                        StreamWriter sw = new StreamWriter(File_module);
                        for(int j = 0;j<dataTable.Rows.Count;j++)
                            sw.WriteLine(dataTable.Rows[j][i]);
                        sw.Close();
                        sw.Dispose();
                    }
                }
                #endregion
            }
            else if (DAQ_Now.Equals("AE")){
                #region 音頻
                chart_AE.Series[0].Points.Clear();

                for (int i = 0; i < dataTable.Rows.Count; i++)
                    chart_AE.Series[0].Points.AddXY(i, dataTable.Rows[i][0]);
                //若有勾選紀錄資料則記錄軸向資料
                if (chb_AccCur_Record.Checked == true){
                    FileStream File_module = File.Open(path + @"data\AccCur\AE.csv", FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
                    StreamWriter sw = new StreamWriter(File_module);
                    for (int j = 0; j < dataTable.Rows.Count; j++)
                        sw.WriteLine(dataTable.Rows[j][0]);
                    sw.Close();
                    sw.Dispose();
                }
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
            //判斷轉速(如果機台未連線或為0，設為預設2500)
            if (machine_connect == false || ATC_RPM == 0)
                ATC_RPM = 2500;
            //判斷模式
            string tem_path = "";

            if (mode.Equals("Learn")) {
                //判斷檔案是否存在
                tem_path = path + @"\data\FFT\L-" + lb_Learn_WorkName.Text + Learn_Axial + "-" + ATC_num + "_" + (int)ATC_RPM + ".cp";
                //若沒有存在則使用預設0刀號
                //if (!File.Exists(tem_path))
                //    tem_path = path + @"\data\FFT\L-" + lb_Learn_WorkName.Text + Learn_Axial + "-" + "0" + "_" + (int)ATC_RPM + ".cp";
            }
            else if (mode.Equals("Match")){
                for (int i = 0; i < ToolWear_bool.Length; i++)
                    if (ToolWear_bool[i] == true){
                        //判斷檔案是否存在
                        tem_path = path + @"\data\FFT\M-" + lb_ToolWear_Parts.Text + (i + 1).ToString("00") + "-" + ATC_num + "_" + (int)ATC_RPM + ".cp";
                    }
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
                    //如果存值>1660筆資料，重置Datatable
                    if(dt_LNC.Rows.Count >= 1660){
                        dt_LNC = new DataTable();
                        dt_LNC.Columns.Add("Z");
                    }
                    
                    short[] parrTDData = new short[TDLength];

                    rc = CLNCc.lnc_svi_get_td_data(gNid, TDLength, ref parrTDData[0], ref numTD);
                    
                    while(LNC_Data.Count >= Chart_max){
                        LNC_Data.RemoveRange(0, 500);
                    }
                    for (i = 0;  i < numTD; i += 3){
                        if (i > 3000) break;
                        dt_LNC.Rows.Add(parrTDData[i].ToString());
                        LNC_Data.Add(parrTDData[i].ToString());
                    }
                    //學習模式
                    if(On_Learn == true){
                        chart_Learn.Series[0].Points.Clear();
                        for (i = 0; i < LNC_Data.Count; i++)
                            chart_Learn.Series[0].Points.AddXY((i + 1), LNC_Data[i]);

                        if (dt_LNC.Rows.Count >= 1660)
                            FFT("Learn", dt_LNC, 166, 1660);
                    }
                    //偵測模式
                    else{
                        chart_ToolWear.Series[0].Points.Clear();
                        for (i = 0; i < LNC_Data.Count; i++)
                            chart_ToolWear.Series[0].Points.AddXY((i + 1), LNC_Data[i]);

                        if (dt_LNC.Rows.Count >= 1660)
                            FFT("Match", dt_LNC, 166, 1660);
                    }
                }

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
        #region 電流資料讀取
        //暫存modbus資訊
        private ModbusClient modbusClient;
        //暫存電流輸入訊號
        private string Current_Channel = "";
        //電流 > 連線
        private void Current_Connect(){
            try{
                //取得第幾個軸向
                string ID = pre_ToolWearSetting.Name.Split('_')[2];
                //暫存IP
                string IP = "";
                StreamReader sr = new StreamReader(path + @"\data\axial.cp");
                for(int i = 0; i < int.Parse(ID); i++){
                    string tem = sr.ReadLine();
                    if(i == int.Parse(ID) - 1){
                        IP = tem.Split(',')[4];
                        Current_Channel = tem.Split(',')[5];
                    }
                }
                if (IP.Equals("")){
                    MessageBox.Show("IP錯誤。\n請至設定頁面查詢電流IP是否正確。", "連線失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                modbusClient = new ModbusClient(IP, 502);    //Ip-Address and Port of Modbus-TCP-Server
                modbusClient.Connect();     //Connect to Server
            }
            catch (Exception ex) {
                MessageBox.Show("電流連線失敗。\n請放心，這不會影響您的震動偵測。\n\nCurrent_Connect\n\nError code:\n" + ex.ToString(), "連線失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }
        //電流 > 取得資料(施耐德)
        private void Current_Getdata_Schneider(string address){
            if (modbusClient == null || modbusClient.Connected == false) return;
            try{
                modbusClient.UnitIdentifier = byte.Parse("1");
                int start = int.Parse(address) - 1;
                int[] readHoldingRegisters = modbusClient.ReadHoldingRegisters(start, 1);
                float output = ((float)readHoldingRegisters[0] - 4000) * 9.375f * 0.001f;
                draw_chart(output);
            }
            catch(Exception ex){
                MessageBox.Show("讀取電流資料發生錯誤。\n\nCurrent_Getdata_Schneider\n\n" + ex.ToString(), "讀取失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //電流 > 取得資料(Adam)
        private void Current_Getdata(string address){
            if (modbusClient == null || modbusClient.Connected == false) return;
            try{
                modbusClient.UnitIdentifier = byte.Parse("1");
                int start = int.Parse(address) - 1;
                int[] readHoldingRegisters = modbusClient.ReadHoldingRegisters(start, 2);
                int tem = readHoldingRegisters[0];
                readHoldingRegisters[0] = readHoldingRegisters[1];
                readHoldingRegisters[1] = tem;
                float output = (Show_Data_Float(readHoldingRegisters) - 4) * 9.375f;
                //int output = readHoldingRegisters[0];
                draw_chart(output);
                //Console.Write(output);
            }
            catch (Exception ex){
                MessageBox.Show("讀取電流資料發生錯誤。\n\nCurrent_Getdata\n\n" + ex.ToString(), "讀取失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //暫存電流的值
        List<string> Current_Value = new List<string>();
        //電流折線圖最大值
        int Chart_CurrentMax = 200;
        //電流 > 畫折線圖
        private void draw_chart(float output){
            if (Current_Value.Count > Chart_CurrentMax){
                Current_Value.RemoveAt(0);
                chart_Current.Series[0].Points.Clear();
                for (int i = 0; i < Chart_CurrentMax; i++) chart_Current.Series[0].Points.AddXY(i + 1, Current_Value[i]);
            }
            chart_Current.Series[0].Points.AddXY(Current_Value.Count + 1, output);
            Current_Value.Add(output.ToString());
        }
        //電流 > 資料換算成float
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
        //暫存轉速
        double ATC_RPM = 0;
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
            if (lRet == 0){
                machine_connect = true;
                machine_type = "Mitsubishi";
                //開始擷取CNC資料
                timer_CNC.Enabled = true;
            }
            else
                machine_connect = false;
            return lRet;
        }
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
            //lRet = EZNcCom.Close();
            //EZNcCom = null;
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
            //lRet = EZNcCom.Close();
            //EZNcCom = null;
            return "";
        }
        /// <summary>
        /// 取得目前轉速
        /// </summary>
        /// <returns>轉速(RPM)</returns>
        private int Mitsubishi_GetFeedSpeed(){
            if (machine_connect == false) return -1;
            int lIndex = 2, lspindle = 1, plData = 0;
            string buffer = "";
            if (lRet == 0){
                lRet = EZNcCom.Monitor_GetSpindleMonitor(lIndex, lspindle, out plData, out buffer);
                if (lRet == 0){
                    //補正轉速偏差
                    if (plData % 10 == 9) plData++;
                    else if (plData % 10 == 1) plData--;
                    return plData;
                }
                else
                    CatchLog(1003, lRet.ToString());
            }
            //lRet = EZNcCom.Close();
            //EZNcCom = null;
            return 0;
        }
        /// <summary>
        /// 取得輸入的記憶體位置資料
        /// </summary>
        /// <param name="Address">記憶體位置</param>
        /// <returns>記憶體資料(-1為失敗)</returns>
        private int Mitsubishi_GetMemoryData(string Address){
            if (machine_connect == false) return -1;
            object vValues = null;
            lRet = EZNcCom.Device_ReadBlock(2, Address, 2, out vValues);
            if(lRet == 0){
                int tem_value = ((int[])vValues)[0];
                return tem_value;
            }
            else
                CatchLog(1004, lRet.ToString());
            return -1;
        }
        /// <summary>
        /// 將數值寫入指定的記憶體位置
        /// </summary>
        /// <param name="address">記憶體位置</param>
        /// <param name="value">數值</param>
        /// <returns>是否成功改寫記憶體</returns>
        private bool Mitsubishi_WriteMemoryData(string address,string value){
            if (machine_connect == false) return false;
            object vValue = value;
            lRet = EZNcCom.Device_WriteBlock(2, address, 2, vValue);
            if (lRet == 0)
                return true;
            else
                CatchLog(1005,lRet.ToString());
            return false;
        }
        /// <summary>
        /// 緊急停止
        /// </summary>
        /// <returns>是否成功</returns>
        private bool Mitsubishi_Stop(){
            if (machine_connect == false) return false;
            lRet = EZNcCom.Operation_Stop();
            if (lRet == 0)
                return true;
            else
                CatchLog(1006, lRet.ToString());
            return false;
        }
        /// <summary>
        /// 重置急停
        /// </summary>
        /// <returns>是否成功</returns>
        private bool Mitsubishi_Run(){
            if (machine_connect == false) return false;
            lRet = EZNcCom.Operation_Run();
            if (lRet == 0)
                return true;
            return false;
        }
        /// <summary>
        /// 取得機台Alarm狀態
        /// </summary>
        /// <returns>Alarm訊號</returns>
        private string Mitsubishi_GetAlarm(){
            if (machine_connect == false) return "NotConnect";
            string sBuffer = "";
            lRet = EZNcCom.System_GetAlarm(10, 0,out sBuffer);
            if (lRet == 0)
                return sBuffer;
            else
                CatchLog(1007, lRet.ToString());
            return "";
        }
        /// <summary>
        /// 取得機台指定軸向負載
        /// </summary>
        /// <param name="Axis">軸向(從1開始)</param>
        /// <returns>負載量(%)</returns>
        private string Mitsubishi_GetLoad(int Axis){
            int lAxisNo = Axis;
            int lIndex = 3;
            //軸負載(0%為0，1%為65535，2%為65534，以此類推)
            lRet = EZNcCom.Monitor_GetServoMonitor(lAxisNo, lIndex, out int plData, out string pbstrBuffer);
            if (lRet == 0){
                if(plData != 0)
                    plData = 65536 - plData;
                return plData.ToString();
            }
            else
                CatchLog(1008, lRet.ToString());
            return "";
        }
        #endregion
        #region Brother
        string Bro_lRet = "";
        /// <summary>
        /// Brother控制器初始化
        /// </summary>
        private string Brother_Initialization(){
            Brother br = new Brother(tb_setting_ip.Text, 10000);
            Bro_lRet = br.CNC_Status();    //測試連線
            if (Bro_lRet.Equals(""))
                machine_connect = false;
            else{
                machine_connect = true;
                machine_type = "Brother";
                timer_CNC.Enabled = true;
            }
            return Bro_lRet;
        }
        /// <summary>
        /// Brother控制器 > 取得自動換刀裝置目前使用刀號
        /// </summary>
        /// <returns>目前刀號</returns>
        private string Brother_GetATCStatus(){
            Brother br = new Brother(tb_setting_ip.Text, 10000);
            Bro_lRet = br.ATC_Number();
            if (Bro_lRet.Equals(""))
                CatchLog(1001,Bro_lRet);
            return Bro_lRet;
        }
        /// <summary>
        /// Brother控制器 > 取得機台狀態
        /// </summary>
        /// <returns>目前狀態</returns>
        private string Brother_GetRunStatus(){
            Brother br = new Brother(tb_setting_ip.Text, 10000);
            Bro_lRet = br.CNC_Status();
            if (Bro_lRet.Equals(""))
                CatchLog(1002, Bro_lRet);
            return Bro_lRet;
        }
        /// <summary>
        /// 取得目前轉速
        /// </summary>
        /// <returns>轉速(RPM)</returns>
        private string Brother_GetFeedSpeed(){
            Brother br = new Brother(tb_setting_ip.Text, 10000);
            Bro_lRet = br.Rotating();
            if (Bro_lRet.Equals(""))
                CatchLog(1003, Bro_lRet);
            return Bro_lRet;
        }
        #endregion
        #region 發那科
        short Fanuc_lRet = 0;
        ushort FFlibHndl;
        //String FileName;
        /// <summary>
        /// Fanuc控制器初始化
        /// </summary>
        private short FANUC_Initialization(){
            Fanuc_lRet = Focas1.cnc_allclibhndl3(tb_setting_ip.Text, 8193, 1, out FFlibHndl);
            if (Fanuc_lRet == 0)
                machine_connect = false;
            else{
                machine_connect = true;
                machine_type = "Fanuc";
                timer_CNC.Enabled = true;
            }
            return Fanuc_lRet;
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
                    catch_log = "取得轉速失敗";
                    break;
                case 1004:
                    catch_log = "讀取記憶體位置失敗";
                    break;
                case 1005:
                    catch_log = "改寫記憶體失敗";
                    break;
                case 1006:
                    catch_log = "停止可編成程式失敗";
                    break;
                case 1007:
                    catch_log = "取得Alarm狀態失敗";
                    break;
                case 1008:
                    catch_log = "取得負載資料失敗";
                    break;
                default:
                    catch_log = "錯誤碼未定義";
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
        #region 輸出/載入設定檔
        BackgroundWorker bgw_Profile = null;
        string Export_Path = null;
        //輸出設定檔
        private void Export_Profile(object sender,EventArgs e){
            //檢查是否正在輸出或載入
            if (bgw_Profile != null){
                if(bgw_Profile.IsBusy == true){
                    MessageBox.Show("系統正在處理設定檔，請稍後再試。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
            }
            //確認訊息
            DialogResult dialogResult = MessageBox.Show("您確定要輸出設定檔嗎？\n根據您的設定檔大小將可能耗費不少時間。" +
                "\n並且若您的輸出目錄已有data資料夾，將會覆蓋內部所有相關設定檔。", "輸出設定檔", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;

            //選擇輸出目的地
            FolderBrowserDialog dialog = new FolderBrowserDialog();
            if (dialog.ShowDialog() == DialogResult.OK)
                Export_Path = dialog.SelectedPath;
            else return;
            Bar_setting.Visible = true;
            Bar_setting.Value = 0;
            Export_Profile_LoadFile = 0;
            try{
                bgw_Profile = new BackgroundWorker();
                bgw_Profile.DoWork += new DoWorkEventHandler(Export_Profile_DoWork);
                bgw_Profile.ProgressChanged += new ProgressChangedEventHandler(Profile_ProgressChanged);
                bgw_Profile.WorkerReportsProgress = true;

                bgw_Profile.RunWorkerAsync();
            }
            catch(Exception ex){
                MessageBox.Show("輸出設定檔時發生錯誤。\n\nExport_Profile\n\n" + ex.ToString(), "輸出設定檔失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //輸出設定檔 > 背景執行續 > 開始
        private void Export_Profile_DoWork(object sender,DoWorkEventArgs e){
            //複製設定檔到指定目錄
            try{
                //計算設定檔內有多少檔案數量(進度條用)
                DirectoryInfo dirInfo = new DirectoryInfo(path + @"\data");
                Export_Profile_TotalFile = GetFilesCount(dirInfo);

                DirectoryCopy(path + @"\data", Export_Path + @"\data", true);
                MessageBox.Show("輸出設定檔完畢。", "輸出設定檔成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch(Exception ex){
                MessageBox.Show("輸出設定檔時發生錯誤。\n\nExport_Profile_DoWork\n\n" + ex.ToString(), "輸出設定檔失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally{
                bgw_Profile.CancelAsync();
            }
        }
        //輸出/載入設定檔 > 背景執行續 > 進度
        private void Profile_ProgressChanged(object sender, ProgressChangedEventArgs e){
            Bar_setting.Value = e.ProgressPercentage;
        }
        //載入設定檔
        string Import_Path = null;
        private void Import_Profile(object sender,EventArgs e){
            //檢查是否正在輸出或載入
            if (bgw_Profile != null){
                if(bgw_Profile.IsBusy == true){
                    MessageBox.Show("系統正在處理設定檔，請稍後再試。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                    return;
                }
            }

            //確認訊息
            DialogResult dialogResult = MessageBox.Show("您確定要載入設定檔嗎？\n根據您的設定檔大小將可能耗費不少時間。" +
                "\n並且會完全覆蓋掉您原先的設定檔，\n請問要繼續嗎？", "載入設定檔", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            MessageBox.Show("※※※※※※警告※※※※※※\n\n請務必選擇原先輸出設定檔產生的\ndata 資料夾\n若選擇錯誤將造成設定檔遺失的不可逆狀況。", "警告訊息", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            //選擇輸入來源
            FolderBrowserDialog dialog = new FolderBrowserDialog();
            if (dialog.ShowDialog() == DialogResult.OK)
                Import_Path = dialog.SelectedPath;
            else return;
            if(!Import_Path.Substring(Import_Path.Length - 5, 5).Equals(@"\data")){
                MessageBox.Show("請選擇原先輸出設定檔產生的\ndata\n資料夾以避免程式產生錯誤。", "操作失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            Bar_setting.Visible = true;
            Bar_setting.Value = 0;
            Export_Profile_LoadFile = 0;
            try{
                bgw_Profile = new BackgroundWorker();
                bgw_Profile.DoWork += new DoWorkEventHandler(Import_Profile_DoWork);
                bgw_Profile.ProgressChanged += new ProgressChangedEventHandler(Profile_ProgressChanged);
                bgw_Profile.WorkerReportsProgress = true;

                bgw_Profile.RunWorkerAsync();
            }
            catch (Exception ex){
                MessageBox.Show("載入設定檔時發生錯誤。\n\nImport_Profile\n\n" + ex.ToString(), "載入設定檔失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        //載入設定檔 > 背景執行續 > 開始
        private void Import_Profile_DoWork(object sender, DoWorkEventArgs e){
            try{
                //計算要載入的設定檔內有多少檔案數量(進度條用)
                DirectoryInfo dirInfo = new DirectoryInfo(Import_Path);
                Export_Profile_TotalFile = GetFilesCount(dirInfo);

                //先刪檔案
                File_Delete(path + @"\data");

                DirectoryCopy(Import_Path, path + @"\data" , true);
                MessageBox.Show("載入設定檔完畢。", "載入設定檔成功", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex){
                MessageBox.Show("載入設定檔時發生錯誤。\n\nImport_Profile_DoWork\n\n" + ex.ToString(), "載入設定檔失敗", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally{
                bgw_Profile.CancelAsync();
            }
        }
        /// <summary>
        /// 刪除路徑所有檔案與子目錄
        /// </summary>
        /// <param name="Path">路徑</param>
        private void File_Delete(string Path){
            if (Directory.Exists(Path)){
                try{
                    Directory.Delete(Path, true);
                }
                catch (IOException e){
                    MessageBox.Show("發生不可測意外。\n\nFile_Delete\n\n" + e.ToString(), "刪除檔案失敗", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
            }

        }
        //計算檔案目錄內所有檔案數量
        int Export_Profile_TotalFile = 0;
        private int GetFilesCount(DirectoryInfo dirInfo){
            int totalFile = 0;
            totalFile += dirInfo.GetFiles().Length;
            foreach (DirectoryInfo subdir in dirInfo.GetDirectories())
                totalFile += GetFilesCount(subdir);
            return totalFile;
        }
        //現在已經讀取的檔案數量
        int Export_Profile_LoadFile = 0;
        /// <summary>
        /// 複製檔案
        /// </summary>
        /// <param name="sourceDirName">來源目錄</param>
        /// <param name="destDirName">目標目錄</param>
        /// <param name="copySubDirs">是否複製子目錄</param>
        /// <returns>是否執行成功</returns>
        private bool DirectoryCopy(string sourceDirName, string destDirName, bool copySubDirs){
            //獲取來源目錄的子目錄
            DirectoryInfo dir = new DirectoryInfo(sourceDirName);

            //來源目錄是否存在
            if (!dir.Exists)
                return false;

            DirectoryInfo[] dirs = dir.GetDirectories();
            //如果目標資料夾沒有存在則創建一個
            if (!Directory.Exists(destDirName))
                Directory.CreateDirectory(destDirName);

            //獲取目錄的檔案並複製到新的地方
            FileInfo[] files = dir.GetFiles();
            foreach (FileInfo file in files){
                string temppath = Path.Combine(destDirName, file.Name);
                if (File.Exists(temppath)) File.Delete(temppath);
                file.CopyTo(temppath, false);
                Export_Profile_LoadFile += 100;
                bgw_Profile.ReportProgress((int)(Export_Profile_LoadFile / Export_Profile_TotalFile));
            }

            //子目錄遞迴程式
            if (copySubDirs){
                foreach (DirectoryInfo subdir in dirs){
                    string temppath = Path.Combine(destDirName, subdir.Name);
                    DirectoryCopy(subdir.FullName, temppath, copySubDirs);
                }
            }
            return true;
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
            catch {
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
        #region 檢查非法字元
        /// <summary>
        /// 檢查是否輸入的字串有非法字元存在
        /// </summary>
        /// <param name="s">欲檢查的字串</param>
        /// <returns>若為true則表示含有非法字元；若為false表示不含非法字元</returns>
        private bool Unlawful_Check(string s){
            for (int i = 0; i < Unlawful.Length; i++){
                if(s.Split(Unlawful[i]).Length > 1){
                    MessageBox.Show(string.Format("輸入字串\n{0}\n含有非法字元\n{1}\n請重新輸入。", s, Unlawful[i]), "文字含有非法字元", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return true;
                }
            }
            return false;
        }
        #endregion
        #region 快速排序法
        /// <summary>
        /// 快速排序法
        /// </summary>
        /// <param name="numbers">要進行排序的陣列</param>
        /// <param name="left">排序起點(通常為0，即陣列開頭)</param>
        /// <param name="right">排序終點(通常為陣列大小-1，即陣列最後)</param>
        private void Sort(List<int> numbers, int left, int right){
            if (left < right){
                int middle = numbers[(left + right) / 2];
                int i = left - 1;
                int j = right + 1;
                while (true){
                    while (numbers[++i] < middle) ;
                    while (numbers[--j] > middle) ;
                    if (i >= j)
                        break;
                    Swap(numbers, i, j);
                }
                Sort(numbers, left, i - 1);
                Sort(numbers, j + 1, right);
            }
        }
        private void Swap(List<int> numbers, int i, int j){
            int number = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = number;
        }
        #endregion
    }
}