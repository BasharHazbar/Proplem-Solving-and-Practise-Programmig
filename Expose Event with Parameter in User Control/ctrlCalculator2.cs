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
    public partial class ctrlCalculator2 : UserControl
    {
        public ctrlCalculator2()
        {
            InitializeComponent();
        }

        public class CalculateComplateEvenrArgs : EventArgs
        {
            public int Value1 {  get;  }
            public int Value2 { get;  }
            public int Result { get; }

            public CalculateComplateEvenrArgs(int Value1, int Value2, int Result)
            {
                this.Value1 = Value1;
                this.Value2 = Value2;
                this.Result = Result;
            }
        }

        public event EventHandler<CalculateComplateEvenrArgs> onCalculateComplate;

       /* public void RaisOnCalculateComplate(int Value1, int Value2, int Result)
        {
            onCalculateComplate?.Invoke(this,new CalculateComplateEvenrArgs(Value1,Value2,Result));
        }*/

        private void btnCalc_Click(object sender, EventArgs e)
        {
            int Value1 = Convert.ToInt32(txtNumber1.Text);
            int Value2 = Convert.ToInt32(txtNumber2.Text);

            
            int Result = Value1 + Value2;

            lbResult.Text = Result.ToString();

            if (onCalculateComplate != null)
            {
                //RaisOnCalculateComplate(Value1,Value2,Result);
                //onCalculateComplate(this, new CalculateComplateEvenrArgs(Value1, Value2, Result));
                onCalculateComplate?.Invoke(this, new CalculateComplateEvenrArgs(Value1, Value2, Result));
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
