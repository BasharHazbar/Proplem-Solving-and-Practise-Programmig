using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Send_Data_To_Form2
{
    public partial class Form2 : Form
    {
        private int ID;
        private string personName;
        public Form2(int iD)
        {
            InitializeComponent();
            this.ID = iD;
        }

 
        public Form2(int iD, string personName)
        {
            InitializeComponent();
            this.ID = iD;
            this.personName = personName;
        }
        private void Form2_Load(object sender, EventArgs e)
        {
            label2.Text = ID.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1 frm = new Form1(int.Parse(textBox1.Text));

            frm.ShowDialog();
        }
    }
}
