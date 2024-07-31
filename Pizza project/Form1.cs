using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Pizza_project
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void rbSmall_CheckedChanged(object sender, EventArgs e)
        {
            upadeSize();
        }

        private void rbMedium_CheckedChanged(object sender, EventArgs e)
        {
            upadeSize();
        }

        private void rbLarg_CheckedChanged(object sender, EventArgs e)
        {
            upadeSize();
        }

        private void rbThinCrust_CheckedChanged(object sender, EventArgs e)
        {
            updateCrustType();
        }

        private void rbThinkCrust_CheckedChanged(object sender, EventArgs e)
        {
            updateCrustType();
        }

        private void cbExtraChess_CheckedChanged(object sender, EventArgs e)
        {
            updateToppings();
        }

        private void chMashrooms_CheckedChanged(object sender, EventArgs e)
        {
            updateToppings();
        }

        private void chTomatos_CheckedChanged(object sender, EventArgs e)
        {
            updateToppings();
        }

        private void cbOnion_CheckedChanged(object sender, EventArgs e)
        {
            updateToppings();
        }

        private void cbOlives_CheckedChanged(object sender, EventArgs e)
        {
            updateToppings();
        }

        private void cbGreenPapers_CheckedChanged(object sender, EventArgs e)
        {
            updateToppings();
        }

        private void rbEatIn_CheckedChanged(object sender, EventArgs e)
        {
            lbResultWhereToEat.Text = "Eat In";
        }

        private void rbTakeOut_CheckedChanged(object sender, EventArgs e)
        {
            lbResultWhereToEat.Text = "Take Out";
        }

        private void btOrderPizza_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Confirm Order", "Confirm", MessageBoxButtons.OKCancel, MessageBoxIcon.Question,MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                btOrderPizza.Enabled = false;
                gbSize.Enabled = false;
                gbToppings.Enabled = false;
                gbCrustType.Enabled = false;
                gbWhereToEat.Enabled = false;
                MessageBox.Show("Confirm Order Successfly", "Massage", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }

           
        }

        private void btResetForm_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Confirm Order", "Confirm", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                resetForm();
                MessageBox.Show("Reset Order Successfly", "Massage", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }

        }

        void upadeSize()
        {
            updatePrice();

            if (rbSmall.Checked)
            {
                lbResultSize.Text = "Small";
                return;
            }
            else if (rbMedium.Checked)
            {
                lbResultSize.Text = "Meduim";
                return;
            }
            else if (rbLarg.Checked) 
            {
                lbResultSize.Text = "Large";
                return;
            }
        }

        void updateCrustType()
        {
            updatePrice();
            if (rbThinCrust.Checked)
            {
                lbResultCrustType.Text = "Thin Crust";
                return;
            }
            else if (rbThinCrust.Checked)
            {
                lbResultCrustType.Text = "ThinK Crust";
                return;
            }
        }

        void updateToppings()
        {
            updatePrice();
            string strToppings = "";

            if (cbExtraChess.Checked)
            {
                strToppings += "Extra Chess";

              
            }
            if (cbOnion.Checked)
            {
                strToppings += ",Onion";

            }
            if (cbMashrooms.Checked)
            {
                strToppings += ",Mashroom";

            }
            if (cbOlives.Checked)
            {
                strToppings += ",Olives";


            }
            if (cbTomatos.Checked)
            {
                strToppings += ",Tomattos";
                
            }
            if (cbGreenPapers.Checked)
            {
                strToppings += ",Green Papers";
                
            }

            if (strToppings.StartsWith(","))
            {
                strToppings = strToppings.Substring(1, strToppings.Length - 1).Trim();
            }

            if (strToppings == "")
            {
                strToppings = "No Toppings";
            }

            lbResultTopingType.Text = strToppings;

            
        }

        float getSelectedSizePrice()
        {
            if (rbSmall.Checked)
            {
                return Convert.ToSingle(rbSmall.Tag);
            }
            else if (rbMedium.Checked)
            {
                return Convert.ToSingle(rbMedium.Tag);
            }
            else if (rbLarg.Checked);
            {
                return Convert.ToSingle(rbLarg.Tag);
            }
        }

        float calculateToppingsPrice()
        {
            float totalTopping = 0;

            if (cbExtraChess.Checked)
            {
                totalTopping += Convert.ToSingle(cbExtraChess.Tag);
            }
            if (cbOnion.Checked)
            {
                totalTopping += Convert.ToSingle(cbOnion.Tag);
            }
            if (cbOlives.Checked)
            {
                totalTopping += Convert.ToSingle(cbOlives.Tag);
            }
            if(cbTomatos.Checked)
            {
                totalTopping += Convert.ToSingle(cbTomatos.Tag);
            }
            if (cbMashrooms.Checked)
            {
                totalTopping += Convert.ToSingle(cbMashrooms.Tag);
            }
            if (cbGreenPapers.Checked)
            {
                totalTopping += Convert.ToSingle(cbGreenPapers.Tag);
            }

            return totalTopping;
           
        }

        float getSelectedCrustTypePrice()
        {
            if (rbThinCrust.Checked)
            {
                return Convert.ToSingle(rbThinCrust.Tag);
            }
            else if (rbThinkCrust.Checked) 
            {
                return Convert.ToSingle(rbThinkCrust.Tag);
            }
            else
            {
                return 0;
            }
        }

        float calculateTotalPrice()
        {
            return getSelectedSizePrice() + calculateToppingsPrice() + getSelectedCrustTypePrice(); 
        }

        void updatePrice()
        {
            lbPrice.Text = "$" + calculateTotalPrice().ToString();
        }

        void resetForm()
        {
            
            gbSize.Enabled = true;
            gbToppings.Enabled = true;
            gbCrustType.Enabled = true;
            gbWhereToEat.Enabled = true;

            cbExtraChess.Checked = false;    
            cbMashrooms.Checked = false;
            cbGreenPapers.Checked = false;   
            cbOlives.Checked = false;
            cbTomatos.Checked = false;
            cbOnion.Checked = false;


            rbSmall.Checked = false;

            rbMedium.Checked = true;

            rbLarg.Checked = false;

            rbThinCrust.Checked = true;
            rbThinkCrust.Checked = false;

            rbEatIn.Checked = true;
            rbTakeOut.Checked = false;

            btOrderPizza.Enabled = true;

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            resetForm();
        }
    }
}
