using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace myFirstWinFormProject
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            input_text_2.Text = input_text_1.Text;
        }

        private void button2_MouseHover(object sender, EventArgs e)
        {
            input_text_2.Text = input_text_1.Text;
        }

        private void button2_MouseLeave(object sender, EventArgs e)
        {
            input_text_2.Text = input_text_1.Text;
        }




        private void input_text_1_TextChanged(object sender, EventArgs e)
        {
            input_text_2.Text = input_text_1.Text;
            label1.Text = input_text_1.Text;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            input_text_1.Enabled = false;
            button1.Enabled = false;
            button2.Enabled = false;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            input_text_1.Enabled = true;
            button1.Enabled = true;
            button2.Enabled = true;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            input_text_1.Visible = false;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            input_text_1.Visible = true;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            input_text_1.BackColor = Color.Red;
            input_text_1.ForeColor = Color.White;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            input_text_1.BackColor = Color.White;
            input_text_1.ForeColor = Color.Red;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Green;
            this.Text = input_text_1.Text;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.White;
            this.Text = input_text_1.Text;
        }

        private void label1_Click(object sender, EventArgs e)
        {
            label1.BackColor = Color.Blue;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button11_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
    
}
