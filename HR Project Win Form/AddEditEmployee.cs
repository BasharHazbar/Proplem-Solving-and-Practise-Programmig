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
    public partial class AddEditEmployee : Form
    {
        enum enMode { addNewEmployee = 0, updateEmployee = 1 }

        private enMode _mode;
        private int _EmployeeID;

        private clsHR _HR;

        public AddEditEmployee(int EmployeeID)
        {
            InitializeComponent();

            this._EmployeeID = EmployeeID;  

            if (EmployeeID == -1)
            {
                _mode = enMode.addNewEmployee;
            }
            else
            {
                _mode = enMode.updateEmployee;
            }
        }

        private void _FillComboBoxCountries()
        {
            DataTable dt = clsCountries.getLisCountries();

            foreach (DataRow row in dt.Rows)
            {
                cbCountries.Items.Add(row["CountryName"]);
            }
        }

        private void _FillComboBoxDepartMents()
        {
            DataTable dt = clsDepartMents.getListDepartments();

            foreach (DataRow row in dt.Rows)
            {
                cbDepartments.Items.Add(row["DepartmentName"]);
            }
        }

        void loadData()
        {
            _FillComboBoxCountries();

            _FillComboBoxDepartMents();

            if (_mode == enMode.addNewEmployee)
            {
                lbMode.Text = "Add New Employee";
                _HR = new clsHR();
                return;
            }

            _HR = clsHR.findEmployeeByID(_EmployeeID);
            lbMode.Text = "Edit Employee " + _EmployeeID;
            _mode = enMode.updateEmployee;
            lbEmployeeID.Text = _EmployeeID.ToString();
            tbFirstName.Text = _HR.FirstName;
            tbLastName.Text = _HR.LastName;
            tbGendor.Text = _HR.Gendor;
            dtpDateOfBirth.Value = _HR.DateOfBirth;

            MessageBox.Show(_HR.DateOfBirth.ToString());

            if (_HR.HireDate != null)
            {
                dtpHireDate.Value = _HR.HireDate;
            }

            if (_HR.ExiteDate != null)
            {
                dtpHireDate.Value = _HR.ExiteDate;
            }

            tbMonthSalary.Text = _HR.MonthlySalary;
            tbBonusPerc.Text = _HR.BouncePrec;
           

           cbCountries.SelectedIndex = cbCountries.FindString(clsCountries.findCountry(_HR.CountryID)._CountryName);

        
           cbDepartments.SelectedIndex = cbDepartments.FindString(clsDepartMents.findDepartment(_HR.DepartmentID)._DepartmentName);


        }

        private void AddEditEmployee_Load(object sender, EventArgs e)
        {
            loadData();
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            _HR = new clsHR();
            if (_mode == enMode.updateEmployee)
            {
                _HR.ID = Convert.ToInt16(lbEmployeeID.Text);
            }
            _HR.FirstName = tbFirstName.Text;
            _HR.LastName = tbLastName.Text;
            _HR.Gendor = tbGendor.Text;
            _HR.DateOfBirth = dtpDateOfBirth.Value;
            _HR.HireDate = dtpHireDate.Value;
            _HR.ExiteDate = dtpExiteDate.Value;
            _HR.CountryID = clsCountries.findCountry(cbCountries.Text)._ID;
            _HR.DepartmentID = clsDepartMents.findDepartment(cbDepartments.Text)._ID;
            _HR.MonthlySalary = tbMonthSalary.Text;
            _HR.BouncePrec = tbBonusPerc.Text;

            if (_HR.save())
            {
                MessageBox.Show("the saving is success");
            }
            else
            {
                MessageBox.Show("the saving is not success");
            }

            _mode = enMode.updateEmployee;

        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
           
        }
    }
}
