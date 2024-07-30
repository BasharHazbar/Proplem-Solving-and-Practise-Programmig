using myFirstWinFormProject.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Versioning;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace myFirstWinFormProject
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1 frm1 = new Form1();

            frm1.Show();  
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form2 frm1 = new Form2();

            frm1.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.person1;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Resources.person2;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = Image.FromFile(@"D:\DATA C\Downloads\person3.jpg");
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            Drawcs dr = new Drawcs();
            dr.ShowDialog();  
        }

        private void button7_Click(object sender, EventArgs e)
        {

        }
    }
}
