using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WindowsFormsApp1.Properties;

namespace WindowsFormsApp1
{
    public partial class ImageQ : Form
    {
        public ImageQ()
        {
            InitializeComponent();
        }

        private void radioButton1_CheckedChanged_1(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.Boy;
            label1.Text = ((RadioButton)sender).Tag.ToString();
        }

        private void radioButton2_CheckedChanged_1(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.Girl;
            label1.Text = ((RadioButton)sender).Tag.ToString();
        }

        private void radioButton3_CheckedChanged_1(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.Pen;
            label1.Text = ((RadioButton)sender).Tag.ToString();
        }

        private void radioButton4_CheckedChanged_1(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.Book;
            label1.Text = ((RadioButton)sender).Tag.ToString();
        }
    }
}
