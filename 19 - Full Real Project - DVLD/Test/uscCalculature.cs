using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test
{
    public partial class uscCalculature : UserControl
    {
        public uscCalculature()
        {
            InitializeComponent();
        }

        public float Result
        {
            get
            {
                return (float)Convert.ToDouble(label2.Text);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label2.Text = (Convert.ToInt32(textBox1.Text) + Convert.ToInt32(textBox2.Text)).ToString();
        }

    }
}
