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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            LedYNetSdk.init_sdk();
        }

        private void btn_Client_Click(object sender, EventArgs e)
        {
            Client F_Client = new Client();
            F_Client.ShowDialog();
        }

        private void btn_Server_Click(object sender, EventArgs e)
        {
            Server F_Server = new Server();
            F_Server.ShowDialog();
        }
    }
}
