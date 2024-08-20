using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Expose_Event_with_Parameter_in_User_Control
{
    public partial class Calculator : UserControl
    {
        public Calculator()
        {
            InitializeComponent();
        }

        public event Action<int> OnCalculated;

        protected virtual void Calculated(int Result)
        {
            Action<int> Calculated = OnCalculated;

            if (Calculated != null)
            {
                Calculated(Result);
            }
        }

        private void btnCalc_Click(object sender, EventArgs e)
        {
            lbResult.Text = (int.Parse(txtNumber1.Text) + int.Parse(txtNumber2.Text)).ToString();
            if (OnCalculated != null)
            {
                Calculated(int.Parse(lbResult.Text));
            }
        }

        private void txtNumber1_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }

        private void txtNumber2_KeyPress(object sender, KeyPressEventArgs e)
        {
            e.Handled = !char.IsDigit(e.KeyChar) && !char.IsControl(e.KeyChar);
        }

        
    }
}
