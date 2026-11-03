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
    public partial class frmMessageBoxForm : Form
    {
        public frmMessageBoxForm()
        {
            InitializeComponent();
        }

        private void btn1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("hi this is message box");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("hi this is message box","this is title");
        }

        private void button2_Click(object sender, EventArgs e)
        {
         if(MessageBox.Show("Are you sure ?", "Confirm",MessageBoxButtons.OKCancel)== DialogResult.OK)
            {
                MessageBox.Show("You pressed OK");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Are you sure ?", "Confirm", MessageBoxButtons.OKCancel,MessageBoxIcon.Question) == DialogResult.OK)
            {
                MessageBox.Show("You pressed OK");
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Are you sure ?", "Confirm", MessageBoxButtons.OKCancel, MessageBoxIcon.Question,MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                MessageBox.Show("You pressed OK");
            }

        }
    }
}