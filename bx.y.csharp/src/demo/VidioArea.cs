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
    public partial class VidioArea : Form
    {
        public LedYSDK.PicArea picArea = new LedYSDK.PicArea();
        public List<LedYSDK.Video> pic = new List<LedYSDK.Video>();
        public VidioArea()
        {
            InitializeComponent();
            num_X.Maximum = Variable.p_width;
            num_Y.Maximum = Variable.p_height;
            num_width.Maximum = Variable.p_width;
            num_height.Maximum = Variable.p_height;
            num_width.Value = Variable.p_width;
            num_height.Value = Variable.p_height;
            cmb_volume_mode.SelectedIndex = 0;
            cmb_video_type.SelectedIndex = 0;
            cmb_ratation_mode.SelectedIndex = 0;
            cmb_scale_mode.SelectedIndex = 0;
            cmb_source.SelectedIndex = 0;
        }

        private void btn_addvidio_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.Filter = "所有支持文件|*.mp4";
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                listBox1.Items.Add(openFileDialog1.FileName);
                LedYSDK.Video Video;
                Video.FileName = openFileDialog1.FileName;
                Video.scale_mode = cmb_scale_mode.SelectedIndex;
                Video.volume=trackBar2.Value;
                Video.source=cmb_source.SelectedIndex;
                Video.play_time = (int)num_play_time.Value;
                pic.Add(Video);
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
                picArea.thing = 1;
                picArea.m_x = (int)num_X.Value;
                picArea.m_y = (int)num_Y.Value;
                picArea.m_w = (int)num_width.Value;
                picArea.m_h = (int)num_height.Value;
                picArea.m_Transparent = 0;
                picArea.volume_mode = cmb_volume_mode.SelectedIndex;
                picArea.video_type = cmb_video_type.SelectedIndex;
                picArea.ratation_mode = int.Parse(cmb_ratation_mode.Items[cmb_ratation_mode.SelectedIndex].ToString());
                picArea.m_Video = pic.ToArray();
                this.Close();
            }
            else { MessageBox.Show("未选中"); }
        }

        private void cmb_scale_mode_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1 && index < pic.Count)
            {
                LedYSDK.Video Video = pic[index];
                Video.scale_mode = cmb_scale_mode.SelectedIndex;
                pic[index] = Video;
            }
        }

        private void cmb_source_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1 && index < pic.Count)
            {
                LedYSDK.Video Video = pic[index];
                Video.source = cmb_source.SelectedIndex;
                pic[index] = Video;
            }
        }

        private void num_play_time_ValueChanged(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1 && index < pic.Count)
            {
                LedYSDK.Video Video = pic[index];
                Video.play_time = (int)num_play_time.Value;
                pic[index] = Video;
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1 && index < pic.Count)
            {
                LedYSDK.Video Video = pic[index];
                cmb_scale_mode.SelectedIndex = Video.scale_mode;
                trackBar2.Value = Video.volume;
                cmb_source.SelectedIndex = Video.source;
                num_play_time.Value = Video.play_time;
            }
        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1 && index < pic.Count)
            {
                LedYSDK.Video Video = pic[index];
                Video.volume = trackBar2.Value;
                pic[index] = Video;
            }
        }
    }
}
