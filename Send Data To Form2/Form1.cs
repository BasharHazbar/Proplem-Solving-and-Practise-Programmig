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
    public partial class Form1 : Form
    {
        private int _ID;
        public Form1()
        {
            InitializeComponent();
        }


        public Form1(int ID)
        {
            InitializeComponent();
            this._ID = ID;
        }


        private void button1_Click(object sender, EventArgs e)
        {
            Form2 frm = new Form2(int.Parse(textBox1.Text));
            frm.ShowDialog();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            lbValue1.Text = _ID.ToString();
        }
    }
}
