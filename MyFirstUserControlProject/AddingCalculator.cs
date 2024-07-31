using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyFirstUserControlProject
{
    public partial class AddingCalculator : UserControl
    {
        public AddingCalculator()
        {
            InitializeComponent();
        }

        
        public float Reslut
        {
            get { return (float)Convert.ToDouble(lbResult.Text); }
        }


        public event Action<int> OnCalculateComplate;

        protected virtual void CalculationComplate(int Result)
        {
           
            if (OnCalculateComplate != null)
            {
                OnCalculateComplate(Result);

            }
        }


        private void button1_Click(object sender, EventArgs e)
        {
            lbResult.Text = (Convert.ToInt64(textBox1.Text) + Convert.ToInt64(textBox2.Text)).ToString();

            if (OnCalculateComplate != null)
            {
                OnCalculateComplate(int.Parse(lbResult.Text));
            }
        }

  
    }
}
