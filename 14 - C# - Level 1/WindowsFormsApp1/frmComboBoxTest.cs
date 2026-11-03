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
    public partial class frmComboBoxTest : Form
    {
        public frmComboBoxTest()
        {
            InitializeComponent();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string selectedItem = comboBox1.SelectedItem.ToString();
            label1.Text = selectedItem;

            switch (selectedItem)
            {
                case "Book":
                    pictureBox1.Image = Resources.Book;
                    break;
                case "Boy":
                    pictureBox1.Image = Resources.Boy;
                    break;
                case "Girl":
                    pictureBox1.Image = Resources.Girl;
                    break;
                case "Pen":
                    pictureBox1.Image = Resources.Pen;
                    break;

            }

        }

    }
}
