using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace frmDateTimePicker
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            label1.Text = dateTimePicker1.Value.ToString("MMMM dd, yyyy - dddd") + Environment.NewLine;
            label1.Text += dateTimePicker1.Value.ToString("dd/MM/yyyy") + Environment.NewLine;      

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void monthCalendar1_DateChanged(object sender, DateRangeEventArgs e)
        {
            label2.Text = "Start : " + monthCalendar1.SelectionStart.ToString() + Environment.NewLine;
            label2.Text += "End   : " + monthCalendar1.SelectionEnd.ToString() + Environment.NewLine;

            label2.Text +=monthCalendar1.SelectionRange.ToString() + Environment.NewLine;

        }
    }
}
