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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void calculator_OnCalculated(int obj)
        {
            MessageBox.Show("The Reslut of Calc is: " + obj);
        }
    }
}
