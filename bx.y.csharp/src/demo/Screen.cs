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
    public partial class Screen : Form
    {
        public Screen()
        {
            InitializeComponent();
            byte[] Data = new byte[1024 * 10];
            for (int n = 0; n < 1024; n++) { Data[n] = 0; }
            int err = LedYNetSdk.get_screen_parameters(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, Data);
            IntPtr dec = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(LedYNetSdk.ControllerInfo)));
            Marshal.Copy(Data, Marshal.SizeOf(typeof(LedYNetSdk.ControllerInfo)) * 0, dec, Marshal.SizeOf(typeof(LedYNetSdk.ControllerInfo)));
            LedYNetSdk.ControllerInfo bc = (LedYNetSdk.ControllerInfo)Marshal.PtrToStructure(dec, typeof(LedYNetSdk.ControllerInfo));
            Marshal.FreeHGlobal(dec);
            txt_ScreenW.Text = bc.screen_w.ToString();
            txt_ScreenH.Text = bc.screen_h.ToString();
            switch (bc.screen_type)
            {
                case 8280:
                    cmb_ScreenType.SelectedIndex = 0;
                    break;
                case 8536:
                    cmb_ScreenType.SelectedIndex = 1;
                    break;
                case 8792:
                    cmb_ScreenType.SelectedIndex = 2;
                    break;
                case 9304:
                    cmb_ScreenType.SelectedIndex = 3;
                    break;
                case 9048:
                    cmb_ScreenType.SelectedIndex = 4;
                    break;
                default:
                    break;
            }
        }

        private void btn_Screen_Click(object sender, EventArgs e)
        {
            int w = int.Parse(txt_ScreenW.Text);
            int h = int.Parse(txt_ScreenH.Text);
            int screenrotation = 0;
            switch (cmb_ScreenType.SelectedIndex)
            {
                case 0://BX-Y04
                    {
                        screenrotation = 8280;
                        break;
                    }
                case 1://BX-Y08
                    {
                        screenrotation = 8536;
                        break;
                    }
                case 2://BX-Y2
                    {
                        screenrotation = 8792;
                        if (w > 2048 || h > 2048 || w * h > 614400)
                        {
                            MessageBox.Show("BX-Y2 的宽高超出范围！");
                            return;
                        }
                        break;
                    }
                case 3://BX-Y2L
                    {
                        screenrotation = 9304;
                        if (w > 2048 || h > 2048 || w * h > 196608)
                        {
                            MessageBox.Show("BX-Y2L 的宽高超出范围！");
                            return;
                        }
                        break;
                    }
                case 4://BX-Y3
                    {
                        screenrotation = 9048;
                        if (w > 2048 || h > 2048 || w * h > 1310720)
                        {
                            MessageBox.Show("BX-Y3 的宽高超出范围！");
                            return;
                        }
                        break;
                    }
                default:
                    break;
            }
            int err = LedYNetSdk.set_screen_size(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, w, h, screenrotation);

        }
    }
}
