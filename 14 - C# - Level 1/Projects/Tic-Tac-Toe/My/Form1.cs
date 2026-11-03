using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace My
{
    public partial class Form1 : Form
    {
        int count = 0;

        string Player()
        {
            if (count % 2 == 0)
                 return "X";
            else
                 return "O";
        }
        string DoInBoxs(PictureBox box)
        {

            if (box.Tag != null && ((string)box.Tag == "X" || (string)box.Tag == "O"))
            {
                MessageBox.Show("This Box is already taken , Choose another one");
                return "";
            }

            string PlayerSymbol = Player();

            if (PlayerSymbol == "X")
            {
                box.Image = Properties.Resources.xMark;
                box.Tag = "X";
            }
        else
            {
                box.Image = Properties.Resources.oMark;
                box.Tag = "O";
            }


            count++;
            return PlayerSymbol;
        }

        void UpdateTurnLabel()
        {
            if (Player() == "X")
                label3.Text = "Player 1";
            else
                label3.Text = "Player 2";
        }

        string GetBox(PictureBox box)
        {
            if (box.Tag != null)
        return (string)box.Tag;

            return ""; 
        }


        string CheckWinner()
        {
            string b1 = GetBox(pictureBox1);
            string b2 = GetBox(pictureBox2);
            string b3 = GetBox(pictureBox3);
            string b4 = GetBox(pictureBox4);
            string b5 = GetBox(pictureBox5);
            string b6 = GetBox(pictureBox6);
            string b7 = GetBox(pictureBox7);
            string b8 = GetBox(pictureBox8);
            string b9 = GetBox(pictureBox9);

            // الصفوف
            if (b1 != "" && b1 == b2 && b2 == b3) return b1;
            if (b4 != "" && b4 == b5 && b5 == b6) return b4;
            if (b7 != "" && b7 == b8 && b8 == b9) return b7;

            // الأعمدة
            if (b1 != "" && b1 == b4 && b4 == b7) return b1;
            if (b2 != "" && b2 == b5 && b5 == b8) return b2;
            if (b3 != "" && b3 == b6 && b6 == b9) return b3;

            // القطرين
            if (b1 != "" && b1 == b5 && b5 == b9) return b1;
            if (b3 != "" && b3 == b5 && b5 == b7) return b3;

            return "";
        }

        

        enum enWinner
        {
            InProgress = 0, Player1 = 1 , Player2 = 2 , Draw = 3
        }

        enWinner DetermineWinner()
        {
            string winner = CheckWinner();
            if (winner == "X")
                return enWinner.Player1;
            else if (winner == "O")
                return enWinner.Player2;
            else if (count == 9)
                return enWinner.Draw;
            else
                return enWinner.InProgress;
        }

        void AnnounceWinner()
        {
            enWinner result = DetermineWinner();

            if (result == enWinner.InProgress)
                return;

            if (result == enWinner.Player1)
            {
                MessageBox.Show("Player 1 Wins!");
                label4.Text = "Player1";
            }
            else if (result == enWinner.Player2)
            {
                MessageBox.Show("Player 2 Wins!");
                label4.Text = "Player2";
            }
            else if (result == enWinner.Draw)
            {
                MessageBox.Show("It's a Draw!");
                label4.Text = "Draw";
            }


            groupBox1.Enabled = false;
        }
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
          
            Color Black = Color.FromArgb(255, 0, 0, 0);

            Pen pen = new Pen(Black);
            pen.Width = 10;

            pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            e.Graphics.DrawLine(pen, 300, 200, 750, 200);
            e.Graphics.DrawLine(pen, 300, 350, 750, 350);

            e.Graphics.DrawLine(pen, 450, 100, 450, 450);
            e.Graphics.DrawLine(pen, 600, 100, 600, 450);
        }
        private void pictureBox1_Click(object sender, EventArgs e)
        {
            string PlayerSymbol = DoInBoxs((PictureBox)sender);
            UpdateTurnLabel(); AnnounceWinner();
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            string PlayerSymbol = DoInBoxs((PictureBox)sender);
            UpdateTurnLabel(); AnnounceWinner();
        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            string PlayerSymbol = DoInBoxs((PictureBox)sender);
            UpdateTurnLabel(); AnnounceWinner();
        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {
            string PlayerSymbol = DoInBoxs((PictureBox)sender);
            UpdateTurnLabel(); AnnounceWinner();
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            string PlayerSymbol = DoInBoxs((PictureBox)sender);
            UpdateTurnLabel(); AnnounceWinner();
        }

        private void pictureBox6_Click(object sender, EventArgs e)
        {
            string PlayerSymbol = DoInBoxs((PictureBox)sender);
            UpdateTurnLabel(); AnnounceWinner();
        }

        private void pictureBox7_Click(object sender, EventArgs e)
        {
            string PlayerSymbol = DoInBoxs((PictureBox)sender);
            UpdateTurnLabel();
            AnnounceWinner();
        }

        private void pictureBox8_Click(object sender, EventArgs e)
        {
            string PlayerSymbol = DoInBoxs((PictureBox)sender);
            UpdateTurnLabel();
            AnnounceWinner();
        }

        private void pictureBox9_Click(object sender, EventArgs e)
        {
            string PlayerSymbol = DoInBoxs((PictureBox)sender);
            UpdateTurnLabel();
            AnnounceWinner();
        }

        private void btnRestart_Click(object sender, EventArgs e)
        {
            for (int i =0;i < 9;i++)
            {
                PictureBox box = (PictureBox)groupBox1.Controls["pictureBox" + (i + 1).ToString()];
                box.Image = Properties.Resources.QuesMark;
                box.Tag = null;
            }

            count = 0;     
            UpdateTurnLabel();
            groupBox1.Enabled = true;
        }
    }
}
