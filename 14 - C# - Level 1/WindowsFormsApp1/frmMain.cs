using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void btnShowForm1_Click(object sender, EventArgs e)
        {
            Form frm1 = new Form1();
            frm1.Show();
        }

        private void btnShFormAsDialog_Click(object sender, EventArgs e)
        {
            Form frm1 = new Form1();
            frm1.ShowDialog();

        }

        private void btnMessageBoxForm_Click(object sender, EventArgs e)
        {
            Form frm1 = new frmMessageBoxForm();
            frm1.ShowDialog();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form frm1 = new FrmChkRadioGroup();
            frm1.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form frm1 = new images();
            frm1.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form frm1 = new ImageQ();
            frm1.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form frm1 = new MaskedTextBox();
            frm1.ShowDialog();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Form frm1 = new frmComboBox();
            frm1.ShowDialog();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Form frm1 = new frmComboBoxTest();
            frm1.ShowDialog();

        }

        private void button7_Click(object sender, EventArgs e)
        {
            Form frm1 = new frmLinkLable();
            frm1.ShowDialog();
        }
    }
}
