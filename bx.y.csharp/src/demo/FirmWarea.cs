using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
//using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Collections;

namespace Ysdk_CSharp
{
    public partial class FirmWarea : Form
    {
        public FirmWarea()
        {
            InitializeComponent();
        }


        public void UpdateFileStruct (char[] Da)
        {
            char[] backup = new char[16]; //!< 备用字
            char[] md5 = new char[32];    //!< md5校验值
	        char[] fileName = new char[64]; //!< 被校验的文件名
	        char[] updateVersion = new char[64]; //!< 升级包版本号
	        char[] appVerison = new char[64]; //!< 固件版本号
	        char[] controllerType = new char[64]; //!< 控制器型号
            char[] createdTime = new char[64]; //!< 升级包生成时间

            Array.Copy(Da, 0, backup, 0, 16);
            Array.Copy(Da, 16, md5, 0, 32);
            Array.Copy(Da, 48, fileName, 0, 64);
            Array.Copy(Da, 112, updateVersion, 0, 64);
            Array.Copy(Da, 176, appVerison, 0, 64);
            Array.Copy(Da, 240, controllerType, 0, 64);
            Array.Copy(Da, 304, createdTime, 0, 64);
        }

        private void FirmWarea_Load(object sender, EventArgs e)
        {
            byte[] firmwareversion = new byte[64];
            byte[] app_version = new byte[64];
            byte[] fpga_version = new byte[60];
            int err = LedYNetSdk.get_firmware_version(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, firmwareversion, app_version, fpga_version);
            textBox1.Text = System.Text.Encoding.Unicode.GetString(firmwareversion).Split('\0')[0].Replace("&#x0;", "").Replace("쳌", "");
            textBox2.Text = Encoding.Unicode.GetString(app_version);
            textBox8.Text = Encoding.Unicode.GetString(fpga_version);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int err = LedYNetSdk.update_firmware(Variable.p_ip, Variable.p_port, Variable.p_str, Variable.p_str, textBox3.Text);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog file = new OpenFileDialog();
            file.Multiselect = true; 
            file.Filter = "支持文件|*.bxf";
            if (file.ShowDialog() == DialogResult.OK) 
            {
                textBox3.Text = file.FileName;
            }
        }
    }
}
