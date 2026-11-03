namespace WindowsFormsApp2
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.gpSize = new System.Windows.Forms.GroupBox();
            this.radioBtnLarge = new System.Windows.Forms.RadioButton();
            this.radioBtnMeduim = new System.Windows.Forms.RadioButton();
            this.radioBtnSmall = new System.Windows.Forms.RadioButton();
            this.gpCrustType = new System.Windows.Forms.GroupBox();
            this.radioBtnThinkCrust = new System.Windows.Forms.RadioButton();
            this.radioBtnThinCrust = new System.Windows.Forms.RadioButton();
            this.gpWhereToEat = new System.Windows.Forms.GroupBox();
            this.radioBtnTakOut = new System.Windows.Forms.RadioButton();
            this.radioBtnEatIn = new System.Windows.Forms.RadioButton();
            this.gpToppings = new System.Windows.Forms.GroupBox();
            this.ChkBoxGreenPeppers = new System.Windows.Forms.CheckBox();
            this.ChkBoxOlives = new System.Windows.Forms.CheckBox();
            this.ChkBoxOnion = new System.Windows.Forms.CheckBox();
            this.ChkBoxTomatoes = new System.Windows.Forms.CheckBox();
            this.ChkBoxMushrooms = new System.Windows.Forms.CheckBox();
            this.ChkBoxExtraChees = new System.Windows.Forms.CheckBox();
            this.label2 = new System.Windows.Forms.Label();
            this.gpBoxOrderSummary = new System.Windows.Forms.GroupBox();
            this.labelWhereToEat = new System.Windows.Forms.Label();
            this.labelCrustType = new System.Windows.Forms.Label();
            this.labelToppings = new System.Windows.Forms.Label();
            this.labelSize = new System.Windows.Forms.Label();
            this.labelPrice = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.btnOrderPizza = new System.Windows.Forms.Button();
            this.btnResetForm = new System.Windows.Forms.Button();
            this.gpSize.SuspendLayout();
            this.gpCrustType.SuspendLayout();
            this.gpWhereToEat.SuspendLayout();
            this.gpToppings.SuspendLayout();
            this.gpBoxOrderSummary.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Elephant", 30F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Red;
            this.label1.Location = new System.Drawing.Point(147, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(460, 64);
            this.label1.TabIndex = 13;
            this.label1.Text = "Make Your Pizza";
            // 
            // gpSize
            // 
            this.gpSize.Controls.Add(this.radioBtnLarge);
            this.gpSize.Controls.Add(this.radioBtnMeduim);
            this.gpSize.Controls.Add(this.radioBtnSmall);
            this.gpSize.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gpSize.Location = new System.Drawing.Point(13, 112);
            this.gpSize.Name = "gpSize";
            this.gpSize.Size = new System.Drawing.Size(148, 186);
            this.gpSize.TabIndex = 14;
            this.gpSize.TabStop = false;
            this.gpSize.Text = "Size";
            // 
            // radioBtnLarge
            // 
            this.radioBtnLarge.AutoSize = true;
            this.radioBtnLarge.Location = new System.Drawing.Point(5, 120);
            this.radioBtnLarge.Name = "radioBtnLarge";
            this.radioBtnLarge.Size = new System.Drawing.Size(73, 24);
            this.radioBtnLarge.TabIndex = 2;
            this.radioBtnLarge.TabStop = true;
            this.radioBtnLarge.Text = "Large";
            this.radioBtnLarge.UseVisualStyleBackColor = true;
            this.radioBtnLarge.CheckedChanged += new System.EventHandler(this.radioBtnLarge_CheckedChanged);
            // 
            // radioBtnMeduim
            // 
            this.radioBtnMeduim.AutoSize = true;
            this.radioBtnMeduim.Location = new System.Drawing.Point(6, 81);
            this.radioBtnMeduim.Name = "radioBtnMeduim";
            this.radioBtnMeduim.Size = new System.Drawing.Size(89, 24);
            this.radioBtnMeduim.TabIndex = 1;
            this.radioBtnMeduim.TabStop = true;
            this.radioBtnMeduim.Text = "Meduim";
            this.radioBtnMeduim.UseVisualStyleBackColor = true;
            this.radioBtnMeduim.CheckedChanged += new System.EventHandler(this.radioBtnMeduim_CheckedChanged);
            // 
            // radioBtnSmall
            // 
            this.radioBtnSmall.AutoSize = true;
            this.radioBtnSmall.Location = new System.Drawing.Point(6, 38);
            this.radioBtnSmall.Name = "radioBtnSmall";
            this.radioBtnSmall.Size = new System.Drawing.Size(72, 24);
            this.radioBtnSmall.TabIndex = 0;
            this.radioBtnSmall.TabStop = true;
            this.radioBtnSmall.Text = "Small";
            this.radioBtnSmall.UseVisualStyleBackColor = true;
            this.radioBtnSmall.CheckedChanged += new System.EventHandler(this.radioBtnSmall_CheckedChanged);
            // 
            // gpCrustType
            // 
            this.gpCrustType.Controls.Add(this.radioBtnThinkCrust);
            this.gpCrustType.Controls.Add(this.radioBtnThinCrust);
            this.gpCrustType.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gpCrustType.Location = new System.Drawing.Point(12, 327);
            this.gpCrustType.Name = "gpCrustType";
            this.gpCrustType.Size = new System.Drawing.Size(148, 152);
            this.gpCrustType.TabIndex = 15;
            this.gpCrustType.TabStop = false;
            this.gpCrustType.Text = "Crust Type";
            // 
            // radioBtnThinkCrust
            // 
            this.radioBtnThinkCrust.AutoSize = true;
            this.radioBtnThinkCrust.Location = new System.Drawing.Point(6, 81);
            this.radioBtnThinkCrust.Name = "radioBtnThinkCrust";
            this.radioBtnThinkCrust.Size = new System.Drawing.Size(116, 24);
            this.radioBtnThinkCrust.TabIndex = 1;
            this.radioBtnThinkCrust.TabStop = true;
            this.radioBtnThinkCrust.Text = "Think Crust";
            this.radioBtnThinkCrust.UseVisualStyleBackColor = true;
            this.radioBtnThinkCrust.CheckedChanged += new System.EventHandler(this.radioBtnThinkCrust_CheckedChanged);
            // 
            // radioBtnThinCrust
            // 
            this.radioBtnThinCrust.AutoSize = true;
            this.radioBtnThinCrust.Location = new System.Drawing.Point(6, 38);
            this.radioBtnThinCrust.Name = "radioBtnThinCrust";
            this.radioBtnThinCrust.Size = new System.Drawing.Size(108, 24);
            this.radioBtnThinCrust.TabIndex = 0;
            this.radioBtnThinCrust.TabStop = true;
            this.radioBtnThinCrust.Text = "Thin Crust";
            this.radioBtnThinCrust.UseVisualStyleBackColor = true;
            this.radioBtnThinCrust.CheckedChanged += new System.EventHandler(this.radioBtnThinCrust_CheckedChanged);
            // 
            // gpWhereToEat
            // 
            this.gpWhereToEat.Controls.Add(this.radioBtnTakOut);
            this.gpWhereToEat.Controls.Add(this.radioBtnEatIn);
            this.gpWhereToEat.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gpWhereToEat.Location = new System.Drawing.Point(237, 365);
            this.gpWhereToEat.Name = "gpWhereToEat";
            this.gpWhereToEat.Size = new System.Drawing.Size(307, 88);
            this.gpWhereToEat.TabIndex = 16;
            this.gpWhereToEat.TabStop = false;
            this.gpWhereToEat.Text = "Where To Eat";
            // 
            // radioBtnTakOut
            // 
            this.radioBtnTakOut.AutoSize = true;
            this.radioBtnTakOut.Location = new System.Drawing.Point(129, 38);
            this.radioBtnTakOut.Name = "radioBtnTakOut";
            this.radioBtnTakOut.Size = new System.Drawing.Size(98, 24);
            this.radioBtnTakOut.TabIndex = 1;
            this.radioBtnTakOut.TabStop = true;
            this.radioBtnTakOut.Text = "Take Out";
            this.radioBtnTakOut.UseVisualStyleBackColor = true;
            this.radioBtnTakOut.CheckedChanged += new System.EventHandler(this.radioBtnTakOut_CheckedChanged);
            // 
            // radioBtnEatIn
            // 
            this.radioBtnEatIn.AutoSize = true;
            this.radioBtnEatIn.Location = new System.Drawing.Point(6, 38);
            this.radioBtnEatIn.Name = "radioBtnEatIn";
            this.radioBtnEatIn.Size = new System.Drawing.Size(73, 24);
            this.radioBtnEatIn.TabIndex = 0;
            this.radioBtnEatIn.TabStop = true;
            this.radioBtnEatIn.Text = "Eat In";
            this.radioBtnEatIn.UseVisualStyleBackColor = true;
            this.radioBtnEatIn.CheckedChanged += new System.EventHandler(this.radioBtnEatIn_CheckedChanged);
            // 
            // gpToppings
            // 
            this.gpToppings.Controls.Add(this.ChkBoxGreenPeppers);
            this.gpToppings.Controls.Add(this.ChkBoxOlives);
            this.gpToppings.Controls.Add(this.ChkBoxOnion);
            this.gpToppings.Controls.Add(this.ChkBoxTomatoes);
            this.gpToppings.Controls.Add(this.ChkBoxMushrooms);
            this.gpToppings.Controls.Add(this.ChkBoxExtraChees);
            this.gpToppings.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gpToppings.Location = new System.Drawing.Point(237, 112);
            this.gpToppings.Name = "gpToppings";
            this.gpToppings.Size = new System.Drawing.Size(307, 186);
            this.gpToppings.TabIndex = 17;
            this.gpToppings.TabStop = false;
            this.gpToppings.Text = "Toppings";
            // 
            // ChkBoxGreenPeppers
            // 
            this.ChkBoxGreenPeppers.AutoSize = true;
            this.ChkBoxGreenPeppers.Location = new System.Drawing.Point(155, 120);
            this.ChkBoxGreenPeppers.Name = "ChkBoxGreenPeppers";
            this.ChkBoxGreenPeppers.Size = new System.Drawing.Size(144, 24);
            this.ChkBoxGreenPeppers.TabIndex = 5;
            this.ChkBoxGreenPeppers.Text = "Green Peppers";
            this.ChkBoxGreenPeppers.UseVisualStyleBackColor = true;
            this.ChkBoxGreenPeppers.CheckedChanged += new System.EventHandler(this.ChkBoxGreenPeppers_CheckedChanged);
            // 
            // ChkBoxOlives
            // 
            this.ChkBoxOlives.AutoSize = true;
            this.ChkBoxOlives.Location = new System.Drawing.Point(155, 81);
            this.ChkBoxOlives.Name = "ChkBoxOlives";
            this.ChkBoxOlives.Size = new System.Drawing.Size(78, 24);
            this.ChkBoxOlives.TabIndex = 4;
            this.ChkBoxOlives.Text = "Olives";
            this.ChkBoxOlives.UseVisualStyleBackColor = true;
            this.ChkBoxOlives.CheckedChanged += new System.EventHandler(this.ChkBoxOlives_CheckedChanged);
            // 
            // ChkBoxOnion
            // 
            this.ChkBoxOnion.AutoSize = true;
            this.ChkBoxOnion.Location = new System.Drawing.Point(155, 46);
            this.ChkBoxOnion.Name = "ChkBoxOnion";
            this.ChkBoxOnion.Size = new System.Drawing.Size(75, 24);
            this.ChkBoxOnion.TabIndex = 3;
            this.ChkBoxOnion.Text = "Onion";
            this.ChkBoxOnion.UseVisualStyleBackColor = true;
            this.ChkBoxOnion.CheckedChanged += new System.EventHandler(this.ChkBoxOnion_CheckedChanged);
            // 
            // ChkBoxTomatoes
            // 
            this.ChkBoxTomatoes.AutoSize = true;
            this.ChkBoxTomatoes.Location = new System.Drawing.Point(19, 121);
            this.ChkBoxTomatoes.Name = "ChkBoxTomatoes";
            this.ChkBoxTomatoes.Size = new System.Drawing.Size(105, 24);
            this.ChkBoxTomatoes.TabIndex = 2;
            this.ChkBoxTomatoes.Text = "Tomatoes";
            this.ChkBoxTomatoes.UseVisualStyleBackColor = true;
            this.ChkBoxTomatoes.CheckedChanged += new System.EventHandler(this.ChkBoxTomatoes_CheckedChanged);
            // 
            // ChkBoxMushrooms
            // 
            this.ChkBoxMushrooms.AutoSize = true;
            this.ChkBoxMushrooms.Location = new System.Drawing.Point(19, 82);
            this.ChkBoxMushrooms.Name = "ChkBoxMushrooms";
            this.ChkBoxMushrooms.Size = new System.Drawing.Size(119, 24);
            this.ChkBoxMushrooms.TabIndex = 1;
            this.ChkBoxMushrooms.Text = "Mushrooms";
            this.ChkBoxMushrooms.UseVisualStyleBackColor = true;
            this.ChkBoxMushrooms.CheckedChanged += new System.EventHandler(this.ChkBoxMushrooms_CheckedChanged);
            // 
            // ChkBoxExtraChees
            // 
            this.ChkBoxExtraChees.AutoSize = true;
            this.ChkBoxExtraChees.Location = new System.Drawing.Point(19, 46);
            this.ChkBoxExtraChees.Name = "ChkBoxExtraChees";
            this.ChkBoxExtraChees.Size = new System.Drawing.Size(123, 24);
            this.ChkBoxExtraChees.TabIndex = 0;
            this.ChkBoxExtraChees.Text = "Extra Chees";
            this.ChkBoxExtraChees.UseVisualStyleBackColor = true;
            this.ChkBoxExtraChees.CheckedChanged += new System.EventHandler(this.ChkBoxExtraChees_CheckedChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(17, 38);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 20);
            this.label2.TabIndex = 5;
            this.label2.Text = "Size:";
            // 
            // gpBoxOrderSummary
            // 
            this.gpBoxOrderSummary.Controls.Add(this.labelWhereToEat);
            this.gpBoxOrderSummary.Controls.Add(this.labelCrustType);
            this.gpBoxOrderSummary.Controls.Add(this.labelToppings);
            this.gpBoxOrderSummary.Controls.Add(this.labelSize);
            this.gpBoxOrderSummary.Controls.Add(this.labelPrice);
            this.gpBoxOrderSummary.Controls.Add(this.label6);
            this.gpBoxOrderSummary.Controls.Add(this.label5);
            this.gpBoxOrderSummary.Controls.Add(this.label4);
            this.gpBoxOrderSummary.Controls.Add(this.label3);
            this.gpBoxOrderSummary.Controls.Add(this.label2);
            this.gpBoxOrderSummary.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gpBoxOrderSummary.Location = new System.Drawing.Point(604, 112);
            this.gpBoxOrderSummary.Name = "gpBoxOrderSummary";
            this.gpBoxOrderSummary.Size = new System.Drawing.Size(249, 449);
            this.gpBoxOrderSummary.TabIndex = 18;
            this.gpBoxOrderSummary.TabStop = false;
            this.gpBoxOrderSummary.Text = "Order Summary";
            // 
            // labelWhereToEat
            // 
            this.labelWhereToEat.AutoSize = true;
            this.labelWhereToEat.Location = new System.Drawing.Point(84, 291);
            this.labelWhereToEat.Name = "labelWhereToEat";
            this.labelWhereToEat.Size = new System.Drawing.Size(24, 20);
            this.labelWhereToEat.TabIndex = 15;
            this.labelWhereToEat.Text = "   ";
            // 
            // labelCrustType
            // 
            this.labelCrustType.AutoSize = true;
            this.labelCrustType.Location = new System.Drawing.Point(136, 215);
            this.labelCrustType.Name = "labelCrustType";
            this.labelCrustType.Size = new System.Drawing.Size(24, 20);
            this.labelCrustType.TabIndex = 14;
            this.labelCrustType.Text = "   ";
            // 
            // labelToppings
            // 
            this.labelToppings.AutoSize = true;
            this.labelToppings.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelToppings.Location = new System.Drawing.Point(17, 121);
            this.labelToppings.Name = "labelToppings";
            this.labelToppings.Size = new System.Drawing.Size(86, 16);
            this.labelToppings.TabIndex = 13;
            this.labelToppings.Text = "No Toppings";
            // 
            // labelSize
            // 
            this.labelSize.AutoSize = true;
            this.labelSize.Location = new System.Drawing.Point(76, 42);
            this.labelSize.Name = "labelSize";
            this.labelSize.Size = new System.Drawing.Size(24, 20);
            this.labelSize.TabIndex = 12;
            this.labelSize.Text = "   ";
            // 
            // labelPrice
            // 
            this.labelPrice.AutoSize = true;
            this.labelPrice.Font = new System.Drawing.Font("Felix Titling", 24F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelPrice.ForeColor = System.Drawing.Color.Green;
            this.labelPrice.Location = new System.Drawing.Point(132, 352);
            this.labelPrice.Name = "labelPrice";
            this.labelPrice.Size = new System.Drawing.Size(41, 47);
            this.labelPrice.TabIndex = 11;
            this.labelPrice.Text = "$";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(17, 330);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(107, 20);
            this.label6.TabIndex = 10;
            this.label6.Text = "Total Price:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(17, 257);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(130, 20);
            this.label5.TabIndex = 9;
            this.label5.Text = "Where To Eat:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(17, 215);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(113, 20);
            this.label4.TabIndex = 8;
            this.label4.Text = "Crust Type: ";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(17, 81);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(91, 20);
            this.label3.TabIndex = 7;
            this.label3.Text = "Toppings:";
            // 
            // btnOrderPizza
            // 
            this.btnOrderPizza.Location = new System.Drawing.Point(245, 491);
            this.btnOrderPizza.Name = "btnOrderPizza";
            this.btnOrderPizza.Size = new System.Drawing.Size(116, 38);
            this.btnOrderPizza.TabIndex = 19;
            this.btnOrderPizza.Text = "Order Pizza";
            this.btnOrderPizza.UseVisualStyleBackColor = true;
            this.btnOrderPizza.Click += new System.EventHandler(this.btnOrderPizza_Click);
            // 
            // btnResetForm
            // 
            this.btnResetForm.Location = new System.Drawing.Point(408, 491);
            this.btnResetForm.Name = "btnResetForm";
            this.btnResetForm.Size = new System.Drawing.Size(116, 38);
            this.btnResetForm.TabIndex = 20;
            this.btnResetForm.Text = "Reset Form";
            this.btnResetForm.UseVisualStyleBackColor = true;
            this.btnResetForm.Click += new System.EventHandler(this.btnResetForm_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(900, 573);
            this.Controls.Add(this.btnResetForm);
            this.Controls.Add(this.btnOrderPizza);
            this.Controls.Add(this.gpBoxOrderSummary);
            this.Controls.Add(this.gpToppings);
            this.Controls.Add(this.gpWhereToEat);
            this.Controls.Add(this.gpCrustType);
            this.Controls.Add(this.gpSize);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.gpSize.ResumeLayout(false);
            this.gpSize.PerformLayout();
            this.gpCrustType.ResumeLayout(false);
            this.gpCrustType.PerformLayout();
            this.gpWhereToEat.ResumeLayout(false);
            this.gpWhereToEat.PerformLayout();
            this.gpToppings.ResumeLayout(false);
            this.gpToppings.PerformLayout();
            this.gpBoxOrderSummary.ResumeLayout(false);
            this.gpBoxOrderSummary.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox gpSize;
        private System.Windows.Forms.RadioButton radioBtnLarge;
        private System.Windows.Forms.RadioButton radioBtnMeduim;
        private System.Windows.Forms.RadioButton radioBtnSmall;
        private System.Windows.Forms.GroupBox gpCrustType;
        private System.Windows.Forms.RadioButton radioBtnThinkCrust;
        private System.Windows.Forms.RadioButton radioBtnThinCrust;
        private System.Windows.Forms.GroupBox gpWhereToEat;
        private System.Windows.Forms.RadioButton radioBtnTakOut;
        private System.Windows.Forms.RadioButton radioBtnEatIn;
        private System.Windows.Forms.GroupBox gpToppings;
        private System.Windows.Forms.CheckBox ChkBoxGreenPeppers;
        private System.Windows.Forms.CheckBox ChkBoxOlives;
        private System.Windows.Forms.CheckBox ChkBoxOnion;
        private System.Windows.Forms.CheckBox ChkBoxTomatoes;
        private System.Windows.Forms.CheckBox ChkBoxMushrooms;
        private System.Windows.Forms.CheckBox ChkBoxExtraChees;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.GroupBox gpBoxOrderSummary;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label labelPrice;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label labelSize;
        private System.Windows.Forms.Label labelCrustType;
        private System.Windows.Forms.Label labelToppings;
        private System.Windows.Forms.Label labelWhereToEat;
        private System.Windows.Forms.Button btnOrderPizza;
        private System.Windows.Forms.Button btnResetForm;
    }
}

