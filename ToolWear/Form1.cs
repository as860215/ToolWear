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

namespace ToolWear{
    public partial class Form1 : Form{
        private string path = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase;  //執行檔位置
        public Form1(){
            InitializeComponent();
        }
        private void Form1_Shown(object sender, EventArgs e){
            //初始化設定
            DAQPhysicalChannels();
            Initialization();
            Setting();
        }
        #region 初始化程式
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
            chart_LeartFFT.Legends.Clear();
            chart_Thermal_M1.Legends.Clear();
            chart_Thermal_M2.Legends.Clear();
            //折線圖上下限與x軸最大值預覽
            //chart_FFT.Series[2].Points.AddXY(1, -0.5);
            chart_Learn.Series[1].Points.AddXY(1, Chart_PointMax);
            chart_Threshold.Series[1].Points.AddXY(1, Chart_PointMax);
            chart_ToolWear.Series[1].Points.AddXY(1, Chart_PointMax);
            //震動偵測折線圖
            for (int i = 0; i < Chart_max; i++){
                chart_Learn.Series[2].Points.AddXY(i + 1, Chart_PointMin);
                chart_Threshold.Series[2].Points.AddXY(i + 1, Chart_PointMin);
                chart_ToolWear.Series[2].Points.AddXY(i + 1, Chart_PointMin);
            }
            //FFT折線圖
            for (int i = 0; i < 100; i++)
            {
                chart_FFT.Series[1].Points.AddXY(i + 1, 0.1);
                chart_LeartFFT.Series[1].Points.AddXY(i + 1, 0.1);
            }
            //溫度折線圖
            for (int i = 1; i <= 30; i++){
                chart_Thermal.Series[1].Points.AddXY(i, 25);
                chart_Thermal_M1.Series[1].Points.AddXY(i, 25);
                chart_Thermal_M2.Series[1].Points.AddXY(i, 25);
            }

            //Panel
            panel_Home.Visible = true;
            //預設開啟熱補償介面
            btn_Thermal_Click(null,null);
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
            StreamReader sr_axial = new StreamReader(path + @"\data\axial.cp");
            int count = 0;
            while (!sr_axial.EndOfStream){
                string axial = sr_axial.ReadLine().Split(',')[0];
                btn_ToolWearSetting[count].Text = axial;
                btn_ToolWear[count].Text = axial;
                btn_Learn[count].Text = axial;
                count++;
            }
            sr_axial.Close();
            sr_axial.Dispose();
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
            StreamReader sr_thermal = new StreamReader(path + @"\data\thermal.cp");
            count = 0;
            while (!sr_thermal.EndOfStream){
                string axial = sr_thermal.ReadLine().Split(',')[0];
                btn_Compensate[count].Text = axial;
                btn_Thermal[count].Text = axial;
                count++;
            }
            sr_thermal.Close();
            sr_thermal.Dispose();

            //主畫面 > 設定
            StreamReader sr_setting = new StreamReader(path + @"\data\setting.cp");
            string set = sr_setting.ReadLine();
            //搜尋廠牌
            for(int i = 0; i < cb_setting_brand.Items.Count; i++){
                cb_setting_brand.SelectedIndex = i;
                if (cb_setting_brand.Text.Equals(set.Split(',')[0])) break;
                //當搜尋到最後一筆廠牌資料都沒有搜尋到時(因為如果有搜尋到就已經break了)
                if(i == cb_setting_brand.Items.Count - 1){
                    cb_setting_brand.SelectedIndex = 0;
                    MessageBox.Show("設定檔錯誤。\n查無廠牌！\n請確認設定檔資料是否正確，或是前往設定頁面重新選擇資料並儲存。","設定檔錯誤",MessageBoxButtons.OK,MessageBoxIcon.Error);
                }
            }
            //搜尋型號
            for(int i = 0; i < cb_setting_model.Items.Count; i++){
                cb_setting_model.SelectedIndex = i;
                if (cb_setting_model.Text.Equals(set.Split(',')[1])) break;
                //當搜尋到最後一筆廠牌資料都沒有搜尋到時(因為如果有搜尋到就已經break了)
                if (i == cb_setting_model.Items.Count - 1){
                    cb_setting_model.SelectedIndex = 0;
                    MessageBox.Show("設定檔錯誤。\n查無型號！\n請確認設定檔資料是否正確，或是前往設定頁面重新選擇資料並儲存。", "設定檔錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            //讀取設定檔ip
            tb_setting_ip.Text = set.Split(',')[2];
            sr_setting.Close();
            sr_setting.Dispose();
        }
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
            //if (string.IsNullOrEmpty(cb_ToolWearSetting_WorkName.Text)){
            //    lb_ToolWear_Status.Text = "目前工件：(尚未選取)";
            //    btn_ToolWear_Start.Enabled = false;
            //    btn_ToolWear_Change.Enabled = false;
            //}
            //else{
            //    lb_ToolWear_Status.Text = "目前工件：" + cb_ToolWearSetting_WorkName.Text;
            //    btn_ToolWear_Start.Enabled = true;
            //    btn_ToolWear_Change.Enabled = true;
            //}
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
            panel_ToolWearSetting.Visible = true;
            panel_Threshold.Visible = false;
        }
        private void btn_ToolWear_Setting_Click(object sender, EventArgs e){
            panel_ToolWearSetting.Visible = true;
            panel_ToolWear.Visible = false;
            btn_ToolWearSetting_Choose((object)btn_ToolWearSetting_01, null);
            //cb_ToolWearSetting_WorkName.Items.Clear();
            //讀取設定檔
            //StreamReader sr = new StreamReader(path + @"\data\workname.cp");
            //while (!sr.EndOfStream){
            //    cb_ToolWearSetting_WorkName.Items.Add(sr.ReadLine());
            //}
            //sr.Close();
            //sr.Dispose();
            //if (cb_ToolWearSetting_WorkName.Items.Count > 0)
            //    cb_ToolWearSetting_WorkName.SelectedIndex = 0;
        }
        private void btn_ThermalSetting_Click(object sender, EventArgs e){
            panel_ThermalSetting.Visible = true;
            panel_Compensate.Visible = true;
            panel_Thermal.Visible = false;
            btn_Compensate_Choose((object)btn_Compensate_01, null);
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
            DialogResult dialogResult = MessageBox.Show("請先確認所有設定皆已儲存，否則將造成新設定遺失。", "關閉訊息", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            this.Close();
        }
        //主選單 > 磨耗偵測 > 學習模式
        private void btn_Learn_Click(object sender, EventArgs e){
            panel_Dissable();
            panel_Learn.Visible = true;
            btn_Learn.BackgroundImage = ToolWear.Properties.Resources.wd_l_learn_selected;
        }
        #endregion
        #region 各項功能按鈕
        //FFT和原始數據折線圖轉換
        private bool ToolWearChange_FFT = false;    //紀錄現在折線圖顯示何者圖形
        private void btn_ToolWear_Change_Click(object sender, EventArgs e){
            if (ToolWearChange_FFT == false){
                chart_FFT.Visible = true;
                chart_ToolWear.Visible = false;
                ToolWearChange_FFT = true;
            }
            else{
                chart_FFT.Visible = false;
                chart_ToolWear.Visible = true;
                ToolWearChange_FFT = false;
            }
        }
        //開始偵測
        private void btn_ToolWear_Start_Click(object sender, EventArgs e){
            btn_ToolWear_Start.Enabled = false;
            btn_ToolWear_Stop.Enabled = true;
            chart_ToolWear.Series[0].Points.Clear();
            //timer1.Enabled = true;
            DAQInitialize("Match");
            
        }
        //停止偵測
        private void btn_ToolWear_Stop_Click(object sender, EventArgs e){
            TaskStop();
            btn_ToolWear_Start.Enabled = true;
            btn_ToolWear_Stop.Enabled = false;
        }
        //模型學習開始
        private void btn_Learn_Start_Click(object sender, EventArgs e){
            btn_Learn_Start.Enabled = false;
            btn_Learn_OK.Enabled = true;
            StreamWriter sw = new StreamWriter(path + @"\data\module.cp");
            sw.WriteLine();
            sw.Close();
            sw.Dispose();
            DAQInitialize("Learn");
        }
        //模型學習完成
        private void btn_Learn_OK_Click(object sender, EventArgs e){
            TaskStop();
            btn_Learn_Start.Enabled = true;
            btn_Learn_OK.Enabled = false;
            panel_ToolWearSetting.Visible = true;
            panel_Learn.Visible = false;
            chart_Learn.Series[0].Points.Clear();
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
        //新增工件
        private void btn_ToolWearSetting_Add_Click(object sender, EventArgs e){
            //if (string.IsNullOrEmpty(tb_ToolWearSetting_Add.Text)){
            //    MessageBox.Show("請輸入新工件的名稱！", "輸入格式錯誤", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            //    return;
            //}
            //FileStream File_module = File.Open(path + @"\data\workname.cp", FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
            //StreamWriter sw = new StreamWriter(File_module);
            //sw.WriteLine(tb_ToolWearSetting_Add.Text);
            //sw.Close();
            //sw.Dispose();

            //MessageBox.Show("儲存成功。","",MessageBoxButtons.OK,MessageBoxIcon.Information);
            //tb_ToolWearSetting_Add.Text = "";
            //btn_ToolWear_Setting_Click(null, null);
            //cb_ToolWearSetting_WorkName.SelectedIndex = cb_ToolWearSetting_WorkName.Items.Count - 1;
        }
        //重置縮放
        private void btn_ViewModule_ChartReset_Click(object sender, EventArgs e){
            chart_Blade.ChartAreas[0].AxisX.ScaleView.ZoomReset(0);
            chart_ViewModule.ChartAreas[0].AxisX.ScaleView.ZoomReset(0);
            chart_ViewFFT.ChartAreas[0].AxisX.ScaleView.ZoomReset(0);
            chart_ViewFFT.ChartAreas[0].AxisY.ScaleView.ZoomReset(0);
        }
        //波形圖切換
        private void btn_ViewChartChange_Click(object sender, EventArgs e){
            if(chart_ViewModule.Visible == true){
                chart_ViewFFT.Visible = true;
                chart_ViewModule.Visible = false;
                chart_Blade.Visible = false;
            }
            else
            {
                chart_ViewFFT.Visible = false;
                chart_ViewModule.Visible = true;
                chart_Blade.Visible = false;
            }
        }
        //刃數比對
        private void btn_Blade_Click(object sender, EventArgs e){
            chart_Blade.Visible = true;
            chart_Blade.Legends.Clear();
            chart_Blade.Series[0].Points.Clear();
            double hz = rateNumeric_base / samplesPerChannelNumeric_base;
            List<string> Blade_new = new List<string>();
            List<string> Blade_crash = new List<string>();
            StreamReader sr_new = new StreamReader(path + @"\data\FFT_Max(new-1).cp");
            while (!sr_new.EndOfStream){
                Blade_new.Add(sr_new.ReadLine());
            }
            sr_new.Close();
            sr_new.Dispose();
            StreamReader sr_crash = new StreamReader(path + @"\data\FFT_Max(new-3).cp");
            while (!sr_crash.EndOfStream){
                Blade_crash.Add(sr_crash.ReadLine());
            }
            sr_crash.Close();
            sr_crash.Dispose();
            int Tool_rate = 2500;   //主軸轉數
            int Tool_Blade = 4;     //刀具刃數
            double Blade_Hz = Tool_rate / 60 * Tool_Blade;  //刀具刃數與頻率計算公式
            int Blade_Hz_Mag = 1;   //頻率倍率(取1~5)
            double sum = 0;         //當前儲存點位總和
            int count = 0;          //儲存點位數量
            for(int i = 0; i < Blade_new.Count; i++){
                double tem = 0;
                if ((i + 1) * hz > Blade_Hz_Mag * Blade_Hz * 0.9f && (i + 1) * hz < Blade_Hz_Mag * Blade_Hz * 1.1f){
                    //上下各取10% range
                    tem = double.Parse(Blade_crash[i]) - double.Parse(Blade_new[i]); //暫存相差值
                    if (tem >= 0){
                        sum += tem;
                        count++;
                    }
                }
                else if ((i + 1) * hz > Blade_Hz_Mag * Blade_Hz * 1.1f) Blade_Hz_Mag++; //若頻率已大於刀刃刃數頻率，將倍率提升
                //FileStream File_module = File.Open(path + @"\data\FFT\new1.cp", FileMode.Append, FileAccess.Write, FileShare.ReadWrite);
                //StreamWriter sw = new StreamWriter(File_module);
                //sw.WriteLine(tem);
                //sw.Close();
                //sw.Dispose();
                chart_Blade.Series[0].Points.AddXY((i + 1) * hz, tem);
                if (Blade_Hz_Mag > 5) break;   //頻率倍率取樣數
            }
            label5.Text = (sum / count).ToString();
        }
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
            catch{
                MessageBox.Show("此軸向設定檔不完全，請至設定頁面重新設定。", "設定檔錯誤", MessageBoxButtons.OK, MessageBoxIcon.Error);
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
        }
        //熱補償 > 顯示折線圖
        //delegate void ChartDataDelegate();
        //private void Thermal_ChartData(){
        //    if (this.InvokeRequired){
        //        ChartDataDelegate CDD = new ChartDataDelegate(Thermal_ChartData);
        //        this.Invoke(CDD);
        //    }
        //    else{

        //    }
        //}
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
                //if (single == 1){
                if (Thermal_single == 1 && Thermal_SelectAnother == false){
                    panel_Thermal_single.Visible = true;
                    panel_Thermal_Mutile.Visible = false;
                    lb_Thermal_M1_Now.Text = lb_Thermal_Now.Text;
                }
                else if(Thermal_single == 1 && Thermal_SelectAnother == true){
                    panel_Thermal_single.Visible = false;
                    panel_Thermal_Mutile.Visible = true;
                    lb_Thermal_M2_Now.Text = pre_Thermal.Text;
                }
                for (int i = 0; i < 20; i++){
                    if (Thermal_bool[i] == false) continue;
                    Thermal_count[i]++;
                    Random ran = new Random(Guid.NewGuid().GetHashCode());
                    Thermal_temperature[i] = float.Parse((25 + ((float)ran.Next(-100, 100) * 0.01f)).ToString("00.00"));
                    List<string> tem_read = new List<string>();
                    try{
                        StreamReader sr_axial = new StreamReader(path + @"\data\Temperature\Axial" + i.ToString("00") + ".cp");
                        while (!sr_axial.EndOfStream) tem_read.Add(sr_axial.ReadLine());
                        sr_axial.Close();
                        sr_axial.Dispose();
                    }
                    catch{}
                    //顯示折線圖(單軸)
                    if (tem_read.Count >= 30){
                        tem_read.RemoveAt(0);
                        chart_Thermal.Series[0].Points.Clear();
                        chart_Thermal.Series[1].Points.Clear();
                        chart_Thermal_M1.Series[0].Points.Clear();
                        chart_Thermal_M1.Series[1].Points.Clear();
                        //tem_read 讀取範例 : 10,25.93
                        for (int j = 0; j < tem_read.Count; j++){
                            int tem_count = int.Parse(tem_read[j].Split(',')[0]);
                            chart_Thermal.Series[0].Points.AddXY(tem_count, tem_read[j].Split(',')[1]);
                            chart_Thermal.Series[1].Points.AddXY(tem_count, 25);
                            chart_Thermal_M1.Series[0].Points.AddXY(tem_count, tem_read[j].Split(',')[1]);
                            chart_Thermal_M1.Series[1].Points.AddXY(tem_count, 25);
                        }
                    }
                    chart_Thermal.Series[0].Points.AddXY(Thermal_count[i], Thermal_temperature[i]);
                    chart_Thermal_M1.Series[0].Points.AddXY(Thermal_count[i], Thermal_temperature[i]);
                    //tem_Thermal_chartData.Add(Thermal_temperature[i].ToString());

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
                    break;
                }
                //雙軸啟動
                if (Thermal_single > 1){
                    int num_count = 0;
                    for (int i = 0; i < 20; i++){
                        if (Thermal_bool[i] == true)
                            num_count++;
                        //搜尋到第二軸的時候
                        if(num_count == 2){
                            Thermal_count[i]++;
                            Random ran = new Random(Guid.NewGuid().GetHashCode());
                            Thermal_temperature[i] = float.Parse((25 + ((float)ran.Next(-100, 100) * 0.01f)).ToString("00.00"));
                            List<string> tem_read = new List<string>();
                            try{
                                StreamReader sr_axial = new StreamReader(path + @"\data\Temperature\Axial" + i.ToString("00") + ".cp");
                                while (!sr_axial.EndOfStream) tem_read.Add(sr_axial.ReadLine());
                                sr_axial.Close();
                                sr_axial.Dispose();
                            }
                            catch { }
                            //顯示折線圖(第二軸)
                            if (tem_read.Count >= 30){
                                tem_read.RemoveAt(0);
                                chart_Thermal_M2.Series[0].Points.Clear();
                                chart_Thermal_M2.Series[1].Points.Clear();
                                //tem_read 讀取範例 : 10,25.93
                                for (int j = 0; j < tem_read.Count; j++){
                                    int tem_count = int.Parse(tem_read[j].Split(',')[0]);
                                    chart_Thermal_M2.Series[0].Points.AddXY(tem_count, tem_read[j].Split(',')[1]);
                                    chart_Thermal_M2.Series[1].Points.AddXY(tem_count, 25);
                                }
                            }
                            chart_Thermal_M2.Series[0].Points.AddXY(Thermal_count[i], Thermal_temperature[i]);

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
                            break;
                        }
                    }
                }
                //}
            }
        }
        #endregion
        #endregion
        #region 20顆按鈕事件
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
                        int Channel = int.Parse(tem.Split(',')[3]);
                        physicalChannelComboBox.SelectedIndex = Channel;
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
               "," + cb_ToolWearSetting_Axial.SelectedIndex + "," + physicalChannelComboBox.SelectedIndex;
            try{
                ToolWearSetting_SW(tem_s);
                MessageBox.Show("儲存成功！");
            }
            catch { }
        }
        //軸向設定 > 刪除
        private void btn_ToolWearSetting_delete_Click(object sender, EventArgs e){
            DialogResult dialogResult = MessageBox.Show("確定要刪除此軸向之設定資料嗎？", "刪除警告", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
            if (dialogResult == DialogResult.Cancel) return;
            string tem_s = tb_ToolWearSetting_name.Text;
            try{
                ToolWearSetting_SW(tem_s);
                MessageBox.Show("刪除成功！");
            }
            catch { }
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
                MessageBox.Show("IP與訊號輸入設定完成！");
            }
            catch { }
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
            catch { }
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
            catch { }
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
            catch { }
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
            try
            {
                RW_Compensate(tem, true);
            }
            catch { }
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
            catch{}
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
            catch { }
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
            catch { }
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
        #endregion
        #region Timer事件
        private void timer_temperature_Tick(object sender, EventArgs e){
            Thread TD_FakeData = new Thread(Thermal_FakeData);
            TD_FakeData.Start();
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
                    FFT_Reset();    //重置傅立葉轉換最大最小值
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
                    MessageBox.Show(exception.Message);
                    TaskStop();
                    //自我修復
                    DAQInitialize(DAQ_Now);
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
        private int Match_count = 1;
        private double range = 3; //可接受範圍 (倍率)
        private int match_1 = 0;    //於可接受範圍內的點位數量
        private int match_Read1 = 0; //比對數值讀取到的筆數
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
                FFT(DAQ_Now);
                //if (Match_Bool == true)
                //{
                //    double sum = 0; //暫存目前存取數值
                //    int avg = 0;    //暫存該此總共存取幾個點位
                //    if (Match_count > Chart_max)
                //    {
                //        try
                //        {
                //            string s = Module_Data[Chart_max + (int)samplesPerChannelNumeric - 2];
                //        }
                //        catch
                //        {
                //            //模型比對已結束
                //            TaskStop();
                //            return;
                //        }
                //        chart_Match.Series[0].Points.Clear();
                //        Module_Data.RemoveRange(0, (int)samplesPerChannelNumeric - 1);
                //        for (int i = 0; i < Chart_max; i++)
                //        {
                //            chart_Match.Series[0].Points.AddXY(i + 1, Module_Data[i]);
                //        }
                //        Match_count = 1;
                //        chart_Match.Series[1].Points.Clear();
                //        tem_Match_DT.RemoveRange(0, (int)samplesPerChannelNumeric - 1);
                //        for (int i = 0; i < tem_Match_DT.Count; i++)
                //        {
                //            chart_Match.Series[1].Points.AddXY(Match_count, tem_Match_DT[i]);
                //            Match_count++;
                //        }
                //    }
                //    for (int i = 0; i < (int)samplesPerChannelNumeric - 1; i++)
                //    {
                //        try
                //        {
                //            sum += double.Parse(dataTable.Rows[i][0].ToString());
                //            avg++;
                //        }
                //        catch { }
                //        if ((i + 1) % average == 0)
                //        {
                //            tem_Match_DT.Add(sum.ToString());
                //            chart_Match.Series[1].Points.AddXY(Match_count, sum.ToString());
                //            sum = 0;
                //            avg = 0;
                //            Match_count++;
                //        }
                //    }
                //    match_1 = 0;
                //    match_Read1 = tem_Match_DT.Count;
                //    for (int i = 0; i < tem_Match_DT.Count; i++)
                //    {
                //        double tem_abs = Math.Abs(double.Parse(Module_Data[i]) - double.Parse(tem_Match_DT[i]));
                //        if (tem_abs < double.Parse(tem_Match_DT[i]) * range && tem_abs > -(double.Parse(tem_Match_DT[i]) * range))
                //            match_1++;
                //    }
                //    lb_log1.Text = (((double)match_1 / (double)match_Read1) * 100) + " %";
                //    return;
                //}
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
                    FFT(DAQ_Now);
                }
                catch { }
                #endregion
            }
        }
        #endregion
        #region 傅立葉變換
        private List<string> List_FFT_Max = new List<string>();
        private int FFT_Length = 2000;
        private void FFT_Reset(){
            if (List_FFT_Max.Count != 0) return;
            for (int i = 0; i < samplesPerChannelNumeric_base / 2; i++){
                List_FFT_Max.Add("-99");
            }
            if(FFT_TemPoint.Columns.Count == 0)FFT_TemPoint.Columns.Add("Z");
        }
        private DataTable FFT_TemPoint = new DataTable();
        /// <summary>
        /// 傅立葉轉換
        /// </summary>
        private void FFT(string mode){
            //
            // Simple example to compute a forward 1D real 1024 point FFT
            //

            //直接進行FFT轉換
            dataTable.Rows.RemoveAt(dataTable.Rows.Count - 1);
            var data = new DoubleVector(dataTable);
            dataTable.Rows.Add();

            // Compute the FFT
            // This will create a complex conjugate symmetric packed result.
            //var fft100 = new DoubleForward1DFFT(FFT_Length);
            //DoubleVector fftresult = fft100.FFT(data);
            try{
                chart_FFT.Series[0].Points.Clear();
                chart_LeartFFT.Series[0].Points.Clear();
            }
            catch {
                return;
            }

            //double[] fund = Generate.Sinusoidal((int)samplesPerChannelNumeric_base, (int)rateNumeric_base, 60, 10, 0);
            Complex[] samples = new Complex[(int)samplesPerChannelNumeric_base];
            for (int i = 0; i < samplesPerChannelNumeric_base; i++)
                samples[i] = new Complex(double.Parse(dataTable.Rows[i][0].ToString()), 0);
            Fourier.Forward(samples, FourierOptions.NoScaling);
            for (int i = 0; i < samplesPerChannelNumeric_base / 2; i++){
                double mag = (4.0 / samplesPerChannelNumeric_base) * (Math.Abs(Math.Sqrt(Math.Pow(samples[i].Real, 2) +
                    Math.Pow(samples[i].Imaginary, 2))));
                double hz = rateNumeric_base / samplesPerChannelNumeric_base;
                //if (mag < 0.5) mag *= 0.2f;
                if (mode.Equals("Match")) chart_FFT.Series[0].Points.AddXY(hz * (i + 1), mag);
                else if (mode.Equals("Learn")) chart_LeartFFT.Series[0].Points.AddXY(hz * (i + 1), mag);
                //chart_FFT.Series[0].Points.AddXY(i + 1, fftresult.DataBlock.Data[i] / 100);
                //找尋最大值
                if (mag > double.Parse(List_FFT_Max[i]))
                    List_FFT_Max[i] = mag.ToString();
            }
            //寫檔
            StreamWriter sw_Max = new StreamWriter(path + @"\data\FFT_Max.cp");
            for(int i = 0;i<List_FFT_Max.Count;i++) sw_Max.WriteLine(List_FFT_Max[i]);
            sw_Max.Close();
            sw_Max.Dispose();
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
        private void Mitsubishi_Initialization(){
            int lSystemType = 9;
            int lMachine = 1;
            int lTimeOut = 100;
            lRet = EZNcCom.SetTCPIPProtocol(tb_setting_ip.Text, 683);
            lRet = EZNcCom.Open2(lSystemType, lMachine, lTimeOut, "EZNC_LOCALHOST");
            if(lRet != 0){
                CatchLog(1000, lRet.ToString());
            }
        }
        /// <summary>
        /// 三菱控制器 > 取得自動換刀裝置目前使用刀號
        /// </summary>
        /// <returns>目前刀號</returns>
        private int Mitsubishi_GetATCStatus(){
            Mitsubishi_Initialization();
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
            Mitsubishi_Initialization();
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
        private double Mitsubishi_GetFeedSpeed(){
            Mitsubishi_Initialization();
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
        private void Write_Log(string Title, string Detial){

        }
        private void Read_Log(){

        }
        #endregion
    }
}
