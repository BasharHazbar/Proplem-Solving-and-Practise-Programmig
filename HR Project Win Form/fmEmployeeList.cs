using HR_Project_Business_Layer;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HR_Project_Win_Form
{
    public partial class fmEmployeeList : Form
    {
        public fmEmployeeList()
        {
            InitializeComponent();
        }

        void _RefreshEmployeeList()
        {
            dgvEmployeeList.DataSource = clsHR.getListEmployees();
        }
        private void fmEmployeeList_Load(object sender, EventArgs e)
        {

            _RefreshEmployeeList();

        }

        private void btnAddNewEmployee_Click(object sender, EventArgs e)
        {
            AddEditEmployee addEditEmployee = new AddEditEmployee(-1);
            addEditEmployee.ShowDialog();
            _RefreshEmployeeList();


        }

        private void editToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AddEditEmployee addEditEmployee = new AddEditEmployee((int)dgvEmployeeList.CurrentRow.Cells[0].Value);
           
            addEditEmployee.ShowDialog();
            _RefreshEmployeeList();
        }

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int EmployeeID = (int)dgvEmployeeList.CurrentRow.Cells[0].Value;

            if (MessageBox.Show("Are you sure to delete the Employee  [ " + EmployeeID + " ]",
                "Confirm", MessageBoxButtons.YesNo, MessageBoxIcon.Exclamation) == DialogResult.Yes)
            {
                if (clsHR.deleteEmployee(EmployeeID))
                {
                    MessageBox.Show("The Employee succssesfly delete", "Succsess", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    _RefreshEmployeeList();
                }
                else
                {
                    MessageBox.Show("The Employee not succssesfly delete", "Faild", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
            }
        }
    }
}
