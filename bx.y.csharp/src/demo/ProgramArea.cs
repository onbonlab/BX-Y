using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Ysdk_CSharp
{
    public partial class ProgramArea : Form
    {
        public LedYSDK.Program S_Program = new LedYSDK.Program();
        List<LedYSDK.PicArea> S_PicArea = new List<LedYSDK.PicArea>();
        public ProgramArea()
        {
            InitializeComponent();
            txt_ScreenW.Text = Variable.p_width.ToString();
            txt_ScreenH.Text = Variable.p_height.ToString();
            switch (Variable.p_screen_type)
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
            radio_play_mode0.Checked = true;
            txt_programName.Text = "program_" + Variable.num_program;
        }

        private void ProgramArea_Load(object sender, EventArgs e)
        {

        }
        //图文
        private void btn_FileArea_Click(object sender, EventArgs e)
        {
            ImgArea P_ImgArea = new ImgArea();
            DialogResult ret = P_ImgArea.ShowDialog();
            if (ret == DialogResult.OK)
            {
                S_PicArea.Add(P_ImgArea.picArea);
                int num = S_PicArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域" + num, "图文" });
            }
        }
        //视频
        private void btn_VideoArea_Click(object sender, EventArgs e)
        {
            VidioArea P_VidioArea = new VidioArea();
            DialogResult ret = P_VidioArea.ShowDialog();
            if (ret == DialogResult.OK)
            {
                S_PicArea.Add(P_VidioArea.picArea);
                int num = S_PicArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域" + num, "视频" });
            }
        }
        //字幕
        private void btn_textArea_Click(object sender, EventArgs e)
        {
            Text P_Text = new Text();
            DialogResult ret = P_Text.ShowDialog();
            if (ret == DialogResult.OK)
            {
                S_PicArea.Add(P_Text.picArea);
                int num = S_PicArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域" + num, "字幕" });
            }
        }
        //时间
        private void btn_TimeArea_Click(object sender, EventArgs e)
        {
            TimeArea P_TimeArea = new TimeArea();
            DialogResult ret = P_TimeArea.ShowDialog();
            if (ret == DialogResult.OK)
            {
                S_PicArea.Add(P_TimeArea.picArea);
                int num = S_PicArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域" + num, "时间" });
            }
        }
        //表盘
        private void btn_ClockArea_Click(object sender, EventArgs e)
        {
            ClockAreas P_ClockAreas = new ClockAreas();
            DialogResult ret = P_ClockAreas.ShowDialog();
            if (ret == DialogResult.OK)
            {
                S_PicArea.Add(P_ClockAreas.picArea);
                int num = S_PicArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域" + num, "表盘" });
            }
        }
        //农历
        private void btn_LunArea_Click(object sender, EventArgs e)
        {
            LunArea P_LunArea = new LunArea();
            DialogResult ret = P_LunArea.ShowDialog();
            if (ret == DialogResult.OK)
            {
                S_PicArea.Add(P_LunArea.picArea);
                int num = S_PicArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域" + num, "农历" });
            }
        }
        //计时
        private void btn_CounterArea_Click(object sender, EventArgs e)
        {
            CounterArea P_CounterArea = new CounterArea();
            DialogResult ret = P_CounterArea.ShowDialog();
            if (ret == DialogResult.OK)
            {
                S_PicArea.Add(P_CounterArea.picArea);
                int num = S_PicArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域" + num, "计时" });
            }
        }
        //删除区域
        private void btn_DelArea_Click(object sender, EventArgs e)
        {
            int index = dataGridView1.CurrentCell.RowIndex;
            if (index != -1)
            {
                S_PicArea.RemoveAt(index);
            }
            //移出选择的项 
            foreach (DataGridViewRow r in dataGridView1.SelectedRows)
            {
                if (!r.IsNewRow)
                {
                    dataGridView1.Rows.Remove(r);
                }
            }
        }

        private void btn_addprogram_Click(object sender, EventArgs e)
        {
            S_Program.ProgramNmae = txt_programName.Text;
            if (radio_play_mode0.Checked)
            {
                S_Program.m_play_mode = 0;
                S_Program.m_play_time = int.Parse(txt_play_time0.Text);
            }
            else
            {
                S_Program.m_play_mode = 1;
                S_Program.m_play_time = int.Parse(txt_play_time1.Text);
            }
            if (checkBox1.Checked)
            {
                S_Program.m_aging_start_time = dateTimePicker1.Text;
                S_Program.m_aging_stop_time = dateTimePicker2.Text;
            }
            else
            {
                S_Program.m_aging_start_time = "";
                S_Program.m_aging_stop_time = "";
            }
            if (checkBox2.Checked)
            {
                S_Program.m_period_ontime = dateTimePicker4.Text;
                S_Program.m_period_offtime = dateTimePicker3.Text;
            }
            else
            {
                S_Program.m_period_ontime = "";
                S_Program.m_period_offtime = "";
            }
            //星期
            #region
            int index;
            bool flag;
            byte BIT = 0;
            if (checkMon.Checked == true)
            {
                index = 1;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 1;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            if (checkTues.Checked == true)
            {
                index = 2;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 2;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            if (checkWed.Checked == true)
            {
                index = 3;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 3;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            if (checkThur.Checked == true)
            {
                index = 4;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 4;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            if (checkFri.Checked == true)
            {
                index = 5;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 5;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            if (checkSat.Checked == true)
            {
                index = 6;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 6;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            if (checkSun.Checked == true)
            {
                index = 7;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 7;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            S_Program.m_play_week = BIT;
            #endregion
            S_Program.m_PicArea = S_PicArea.ToArray();
            this.Close();
        }
        byte set_bit(byte data, int index, bool flag)
        {
            if (index > 8 || index < 1)
                throw new ArgumentOutOfRangeException();
            int v = index < 2 ? index : (2 << (index - 2));
            return flag ? (byte)(data | v) : (byte)(data & ~v);
        }

        private void btn_conse_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
