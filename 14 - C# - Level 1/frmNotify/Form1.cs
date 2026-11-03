using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace frmNotify
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            notifyIcon1.Icon = SystemIcons.Application;
            notifyIcon1.BalloonTipIcon = ToolTipIcon.Info;
            notifyIcon1.BalloonTipTitle = "Notification Title";
            notifyIcon1.BalloonTipText = "This is the notification text.";
            notifyIcon1.ShowBalloonTip(1000);
        }

        private void notifyIcon1_MouseClick(object sender, MouseEventArgs e)
        {
            MessageBox.Show("You double-clicked the notification icon.", " ", MessageBoxButtons.OKCancel);
        }

        private void notifyIcon1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("You click the notification icon.", " ", MessageBoxButtons.OKCancel);
        }
    }
}