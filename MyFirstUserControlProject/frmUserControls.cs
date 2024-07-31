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
    public partial class frmUserControls : Form
    {
        public frmUserControls()
        {
            InitializeComponent();
        }



        private void button1_Click(object sender, EventArgs e)

        {
            MessageBox.Show(addingCalculator1.Reslut.ToString());
        }

        private void addingCalculator1_Load(object sender, EventArgs e)
        {

        }

        private void frmUserControls_Load(object sender, EventArgs e)
        {

        }

        private void addingCalculator1_OnCalculateComplate(int obj)
        {
            MessageBox.Show("the Rsult is == " + obj);
        }
    }
}
