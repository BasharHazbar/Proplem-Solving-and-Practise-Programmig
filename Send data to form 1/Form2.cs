using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Send_data_to_form_1
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        public delegate void dataBackEventHandler(object sender, int PersonID);

        public event dataBackEventHandler DataBack;

        private void sendDataBack_Click(object sender, EventArgs e)
        {
            int personID = int.Parse(textBox1.Text);

            DataBack?.Invoke(this, personID);

            this.Close();

        }
    }
}
