using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MenuStrip
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void jkoip0ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("You clicked jkoip0ToolStripMenuItem");
        }

        private void frm2ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form frm = new frmContextMenu();
            frm.MdiParent = this;
            frm.Show();
        }
    }
}
