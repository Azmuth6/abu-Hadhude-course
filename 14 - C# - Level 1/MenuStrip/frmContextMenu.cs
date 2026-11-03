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
    public partial class frmContextMenu : Form
    {
        public frmContextMenu()
        {
            InitializeComponent();
        }

        private void TSMchangeFont_Click(object sender, EventArgs e)
        {
            TextBox tb = contextMenuStrip1.SourceControl as TextBox;
            fontDialog1.ShowColor = true;
            if (fontDialog1.ShowDialog() == DialogResult.OK)
            {
                
                tb.Font = fontDialog1.Font;
                tb.ForeColor = fontDialog1.Color;

            }

        }

        private void TSMchangeColor_Click(object sender, EventArgs e)
        {
            TextBox tb = contextMenuStrip1.SourceControl as TextBox;

            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                tb.BackColor = colorDialog1.Color;
            }
        }
    }
}
