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
    public partial class Drawcs : Form
    {
        public Drawcs()
        {
            InitializeComponent();
        }


        private void Drawcs_Paint(object sender, PaintEventArgs e)
        {
            Color colorPen = Color.FromArgb(87, 3, 3);

             Pen pen = new Pen(colorPen);

             pen.Width = 12;

            //pen.DashStyle = System.Drawing.Drawing2D.DashStyle.Dot;
            pen.StartCap = System.Drawing.Drawing2D.LineCap.Round;
            pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;

            e.Graphics.DrawLine(pen,100,100,100,200);
            e.Graphics.DrawRectangle(pen,200,200,200,300);
            e.Graphics.DrawEllipse(pen,300,300,300,400);
        }

        private void Drawcs_Load(object sender, EventArgs e)
        {

        }
    }
}
