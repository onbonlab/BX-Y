using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace Ysdk_CSharp
{
    public partial class Client : Form
    {
        public Client()
        {
            InitializeComponent();
        }

        private void btn_SearchCards_Click(object sender, EventArgs e)
        {
            Variable.BroadCastlist.Clear();
            cmb_barcode.Items.Clear();
            txt_IP.Text = "";
            IntPtr UDPSearchSecondData = Marshal.AllocHGlobal(1024 * 38);
            int data_count = 0;

            int err = LedYNetSdk.search_card(UDPSearchSecondData, ref data_count);
            byte[] datas = new byte[1024 * 38];
            Marshal.Copy(UDPSearchSecondData, datas, 0, 1024 * 38);
            for (int i = 0; i < data_count; i++)
            {
                IntPtr dec = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(LedYNetSdk.BroadCast2)));
                Marshal.Copy(datas, Marshal.SizeOf(typeof(LedYNetSdk.BroadCast2)) * i, dec, Marshal.SizeOf(typeof(LedYNetSdk.BroadCast2)));
                LedYNetSdk.BroadCast2 bc = (LedYNetSdk.BroadCast2)Marshal.PtrToStructure(dec, typeof(LedYNetSdk.BroadCast2));
                Variable.BroadCastlist.Add(bc);
                Marshal.FreeHGlobal(dec);
                string pid = System.Text.Encoding.Unicode.GetString(bc.pid).Split('\0')[0].Replace("&#x0;", "").Replace("쳌", "");
                string barcode = System.Text.Encoding.Unicode.GetString(bc.barcode).Split('\0')[0].Replace("&#x0;", "").Replace("쳌", "");
                cmb_barcode.Items.Add(barcode);
                if (string.IsNullOrEmpty(pid) || bc.port < 0 || bc.port > 65535 || bc.screen_type < 0 || bc.screen_type > 65535 || pid.Length != 32)
                {
                    continue;
                }
            }
            if (cmb_barcode.Items.Count > 0)
            {
                cmb_barcode.SelectedIndex = 0;
                btn_onoff.Enabled = true;
                btn_firmware.Enabled = true;
                btn_checktime.Enabled = true;
                btn_volumn.Enabled = true;
                btn_bright.Enabled = true;
                btn_DArea.Enabled = true;
                btn_program.Enabled = true;
                btn_Screen.Enabled = true;
                btn_capture.Enabled = true;
            }
            else
            {
                btn_onoff.Enabled = false;
                btn_firmware.Enabled = false;
                btn_checktime.Enabled = false;
                btn_volumn.Enabled = false;
                btn_bright.Enabled = false;
                btn_DArea.Enabled = false;
                btn_program.Enabled = false;
                btn_Screen.Enabled = false;
                btn_capture.Enabled = false;
            }
        }

        private void cmb_barcode_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = cmb_barcode.SelectedIndex;
            if (index != -1)
            {
                txt_IP.Text = System.Text.Encoding.Unicode.GetString(Variable.BroadCastlist[index].source_ip).Split('\0')[0].Replace("&#x0;", "").Replace("쳌", "");
                Variable.p_index = index;
                Variable.p_ip = Encoding.ASCII.GetBytes(txt_IP.Text);
                Variable.p_port = (ushort)Variable.BroadCastlist[index].port;
                Variable.p_width = Variable.BroadCastlist[index].screen_w;
                Variable.p_height = Variable.BroadCastlist[index].screen_h;
                Variable.p_screen_type = Variable.BroadCastlist[index].screen_type;
                Variable.p_brigtness = Variable.BroadCastlist[index].screen_brigtness;
                Variable.p_brigtness_mode = Variable.BroadCastlist[index].screen_brigtness_mode;
            }
        }
        //开关机
        private void btn_onoff_Click(object sender, EventArgs e)
        {
            OnOff F_OnOff = new OnOff();
            F_OnOff.ShowDialog();
        }
        //节目
        private void btn_program_Click(object sender, EventArgs e)
        {
            ProgramList F_ProgramList = new ProgramList();
            F_ProgramList.ShowDialog();
        }

        private void btn_DArea_Click(object sender, EventArgs e)
        {
            DynamicList F_DynamicList = new DynamicList();
            F_DynamicList.ShowDialog();
        }

        private void btn_checktime_Click(object sender, EventArgs e)
        {
            int err = LedYNetSdk.check_time(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str);
            if (err == 0) { MessageBox.Show("校时成功"); }
            else { MessageBox.Show("校时失败："+err); }
        }

        private void btn_firmware_Click(object sender, EventArgs e)
        {
            FirmWarea F_FirmWarea = new FirmWarea();
            F_FirmWarea.ShowDialog();
        }

        private void btn_volumn_Click(object sender, EventArgs e)
        {
            int err = LedYNetSdk.set_screen_volumn(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, (int)num_volume.Value);
        }

        private void btn_bright_Click(object sender, EventArgs e)
        {
            Bright F_Bright = new Bright();
            F_Bright.ShowDialog();
        }

        private void btn_capture_Click(object sender, EventArgs e)
        {
            Capture F_Capture = new Capture();
            F_Capture.ShowDialog();
        }

        private void btn_Screen_Click(object sender, EventArgs e)
        {
            Screen F_Screen = new Screen();
            F_Screen.ShowDialog();
        }
    }
}
