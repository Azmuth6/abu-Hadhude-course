using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        int value = 0;  
        public Form1()
        {
            InitializeComponent();
        }



        private void radioBtnSmall_CheckedChanged(object sender, EventArgs e)
        {
            value = 5;
            labelPrice.Text = "$" + value.ToString();
            labelSize.Text = "Small";
        }

        private void radioBtnMeduim_CheckedChanged(object sender, EventArgs e)
        {
            value = 10;
            labelPrice.Text = "$" + value.ToString();
            labelSize.Text = "Medium";
        }

        private void radioBtnLarge_CheckedChanged(object sender, EventArgs e)
        {
            value = 15;
            labelPrice.Text = "$" + value.ToString();
            labelSize.Text = "Large";
        }

        private void radioBtnThinCrust_CheckedChanged(object sender, EventArgs e)
        {
            value += 5;
            labelPrice.Text = "$" + value.ToString();
            labelCrustType.Text = "Thin Crust";
        }


        private void ChkBoxExtraChees_CheckedChanged(object sender, EventArgs e)
        {
            value += 5;
            labelPrice.Text = "$" + value.ToString();
            if (labelToppings.Text == "No Toppings")
                labelToppings.Text = "Extra Cheese";
            else
                labelToppings.Text += " ,Extra Cheese";
        }

        private void ChkBoxMushrooms_CheckedChanged(object sender, EventArgs e)
        {
            value += 5;
            labelPrice.Text = "$" + value.ToString();
            if (labelToppings.Text == "No Toppings")
                labelToppings.Text = "Mushrooms";
            else
                labelToppings.Text += " ,Mushrooms";
        }

        private void ChkBoxOnion_CheckedChanged(object sender, EventArgs e)
        {
            value += 5;
            labelPrice.Text = "$" + value.ToString();
            if (labelToppings.Text == "No Toppings")
                labelToppings.Text = "Onion";
            else
                labelToppings.Text += " ,Onion";
        }

        private void ChkBoxOlives_CheckedChanged(object sender, EventArgs e)
        {
            value += 5;
            labelPrice.Text = "$" + value.ToString();
            if (labelToppings.Text == "No Toppings")
                labelToppings.Text = "Olives";
            else
                labelToppings.Text += " ,Olives";
        }

        private void ChkBoxTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            value += 5;
            labelPrice.Text = "$" + value.ToString();
            if (labelToppings.Text == "No Toppings")
                labelToppings.Text = "Tomatoes";
            else
                labelToppings.Text += " ,Tomatoes";
        }

        private void ChkBoxGreenPeppers_CheckedChanged(object sender, EventArgs e)
        {
            value += 5;
            labelPrice.Text = "$" + value.ToString();
            if (labelToppings.Text == "No Toppings")
                labelToppings.Text = "Green Peppers";
            else
                labelToppings.Text += " ,Green Peppers";
        }

        private void radioBtnEatIn_CheckedChanged(object sender, EventArgs e)
        {
            labelWhereToEat.Text = "Eat In";
        }

        private void radioBtnTakOut_CheckedChanged(object sender, EventArgs e)
        {
            labelWhereToEat.Text = "Take Out";
        }

        private void radioBtnThinkCrust_CheckedChanged(object sender, EventArgs e)
        {
            value += 10;
            labelPrice.Text = "$" + value.ToString();
            labelCrustType.Text = "Think Crust";
        }

        private void btnOrderPizza_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Confirm Order", "Confirm", MessageBoxButtons.OKCancel, MessageBoxIcon.Information) == DialogResult.OK)
            {
                MessageBox.Show("Order Placed Successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);

                gpSize.Enabled = false;
                gpCrustType.Enabled = false;
                gpToppings.Enabled = false;
                gpWhereToEat.Enabled = false;
            }
        }

        private void btnResetForm_Click(object sender, EventArgs e)
        {
            gpSize.Enabled = true;
            gpCrustType.Enabled = true;
            gpToppings.Enabled = true;
            gpWhereToEat.Enabled = true;
        }
    }
}
