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
    public partial class ImgArea : Form
    {
        public LedYSDK.PicArea picArea = new LedYSDK.PicArea();
        public List<LedYSDK.ImgText> pic = new List<LedYSDK.ImgText>();
        public ImgArea()
        {
            InitializeComponent();
            num_X.Maximum = Variable.p_width;
            num_Y.Maximum = Variable.p_height;
            num_width.Maximum = Variable.p_width;
            num_height.Maximum = Variable.p_height;
            num_width.Value = Variable.p_width;
            num_height.Value = Variable.p_height;
            cmb_display_effects.SelectedIndex = 0;
        }

        private void btn_addFile_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.Multiselect = true; 
            openFileDialog1.Filter = "所有支持文件|*.bmp;*.jpg;*.png;*.gif";
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                foreach (string s in openFileDialog1.FileNames)
                {
                    listBox1.Items.Add(s);
                    LedYSDK.ImgText picUnit;
                    picUnit.FileName = s;
                    picUnit.display_effects = 1;
                    picUnit.display_speed = 1;
                    picUnit.stay_time = 1;
                    pic.Add(picUnit);
                }
                listBox1.SelectedIndex = listBox1.Items.Count - 1;
            }
        }

        private void btn_del_Click(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                pic.RemoveAt(index);
                //移出选择的项
                listBox1.Items.Remove(listBox1.SelectedItem);
                if (listBox1.Items.Count > 0) { listBox1.SelectedIndex = listBox1.Items.Count - 1; }
            }
        }

        private void btn_NO_Click(object sender, EventArgs e)
        {
            this.Close();
            this.Dispose();
        }

        private void btn_OK_Click(object sender, EventArgs e)
        {
            if (listBox1.Items.Count > 0)
            {
                picArea.thing = 0;
                picArea.m_x = (int)num_X.Value;
                picArea.m_y = (int)num_Y.Value;
                picArea.m_w = (int)num_width.Value;
                picArea.m_h = (int)num_height.Value;
                picArea.m_Transparent = (int)trackBar1.Value;
                picArea.m_ImgText = pic.ToArray();
                this.Close();
            }
            else { MessageBox.Show("未选中"); }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1 && index < pic.Count)
            {
                LedYSDK.ImgText picUnit = pic[index];
                cmb_display_effects.SelectedIndex = picUnit.display_effects;
                num_display_speed.Value = picUnit.display_speed;
                num_stay_time.Value = picUnit.stay_time;
            }
        }

        private void cmb_display_effects_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1 && index < pic.Count)
            {
                LedYSDK.ImgText picUnit = pic[index];
                picUnit.display_effects = cmb_display_effects.SelectedIndex;
                pic[index] = picUnit;
            }
        }

        private void num_display_speed_ValueChanged(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1 && index < pic.Count)
            {
                LedYSDK.ImgText picUnit = pic[index];
                picUnit.display_speed = (int)num_display_speed.Value;
                pic[index] = picUnit;
            }
        }

        private void num_stay_time_ValueChanged(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1 && index < pic.Count)
            {
                LedYSDK.ImgText picUnit = pic[index];
                picUnit.stay_time = (int)num_stay_time.Value;
                pic[index] = picUnit;
            }
        }
    }
}
