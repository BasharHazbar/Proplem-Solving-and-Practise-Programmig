using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Resources;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace myFirstWinFormProject
{
    public partial class ImageExercise : Form
    {
        public ImageExercise()
        {
            InitializeComponent();
        }

        private void ImageExercise_Load(object sender, EventArgs e)
        {
/*            lbTitle.Text = "Boy";
            pictureBox1.Image = Image.FromFile(@"D:\DATA C\Downloads\Boy.png");*/
        }

        private void rbBoy_CheckedChanged(object sender, EventArgs e)
        {
/*            lbTitle.Text = ((RadioButton)sender).Text;
            pictureBox1.Image = Image.FromFile(@"D:\DATA C\Downloads\Boy.png");*/
        }

        private void rbGirl_CheckedChanged_1(object sender, EventArgs e)
        {
/*            lbTitle.Text = ((RadioButton)sender).Text;
            pictureBox1.Image = Image.FromFile(@"D:\DATA C\Downloads\Girl.jpg");*/
        }

        private void rbBook_CheckedChanged_1(object sender, EventArgs e)
        {

/*            lbTitle.Text = ((RadioButton)sender).Text;
            pictureBox1.Image = Image.FromFile(@"D:\DATA C\Downloads\Book.png");*/
        }

        private void rbPen_CheckedChanged_1(object sender, EventArgs e)
        {
/*            lbTitle.Text = ((RadioButton)sender).Text;
            pictureBox1.Image = Image.FromFile(@"D:\DATA C\Downloads\Pen.png");*/
        }

        private void showDrawForm_Click(object sender, EventArgs e)
        {
            Drawcs drawcs = new Drawcs();   

            drawcs.ShowDialog();    
        }
    }
}
