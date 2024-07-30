using ContactsBusinessLayer;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics.Contracts;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Contacts_Project
{
    public partial class frAddEditContact : Form
    {


        enum  enMode { AddNew = 0, update = 1 };
        private enMode _mode;

        private int _ContactID;
        private clsContacts _Contacts;

        public frAddEditContact(int ContactID)
        {
            InitializeComponent();

            this._ContactID = ContactID;

         //   MessageBox.Show(ContactID.ToString());
           
            if (ContactID == -1) {
                _mode = enMode.AddNew;
            }
            else
            {
                _mode = enMode.update;
            }
            
        }

        private void _FillCountriesInComboBox()
        {
            DataTable dt = clsContries.getAllContries();

           

            foreach (DataRow row in dt.Rows)
            {
                cbCountries.Items.Add(row["CountryName"]);
            }
        }

        private void _loadData()
        {
            _FillCountriesInComboBox();
            cbCountries.SelectedIndex = 0;

            if (_mode == enMode.AddNew)
            {
                lbMode.Text = "Add New Contact";
                _Contacts = new clsContacts();
                lbRemove.Visible = false;
                return;
            }

            _Contacts = clsContacts.find(_ContactID);

            lbMode.Text = "Edit Contant = " + _ContactID;
            lbIDValue.Text = _ContactID.ToString();
            tbFirstName.Text = _Contacts.firstName;
            tbLastName.Text = _Contacts.lastName;
            tbEmail.Text = _Contacts.email;
            tbPhone.Text = _Contacts.phone;
            tbAdress.Text = _Contacts.address;
            dtBirthDate.Value = _Contacts.dateOfBirth;

            if (_Contacts.imagePath != "")
            {
                pictureBox1.Load(_Contacts.imagePath);
            }
            else
            {
                pictureBox1.ImageLocation = null;
            }

            lbRemove.Visible = _Contacts.imagePath != "";

            cbCountries.SelectedIndex = cbCountries.FindString(clsContries.FindCountry(_Contacts.countryID).CountryName) ;

        }



        private void lbSetImage_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            openFileDialog1.Filter = "Image Files|*.jpg;*.jpeg;*.png;*.gif;*.bmp";
            openFileDialog1.FilterIndex = 1;
            openFileDialog1.RestoreDirectory = true;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                string fileSelect = openFileDialog1.FileName;
                pictureBox1.Load(fileSelect);
                lbRemove.Visible = true;
            }

        }

        private void lbRemove_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            pictureBox1.ImageLocation = null;
            lbRemove.Visible = false;
        }

        private void frAddEditContact_Load(object sender, EventArgs e)
        {
            _loadData();
        }

        private void btSave_Click(object sender, EventArgs e)
        {

           _Contacts.firstName = tbFirstName.Text;
           _Contacts.lastName = tbLastName.Text;
           _Contacts.phone = tbPhone.Text; 
           _Contacts.email = tbEmail.Text;
           _Contacts.dateOfBirth = dtBirthDate.Value;

           _Contacts.countryID = clsContries.FindCountryByName(cbCountries.Text).CountryID;

          _Contacts.address = tbAdress.Text;

          if (pictureBox1.ImageLocation != null)
            {
                _Contacts.imagePath = pictureBox1.ImageLocation;
            }
          else
            {
                _Contacts.imagePath = "";
            }


          if (_Contacts.save())
           {
                MessageBox.Show("the saving is success","Success",MessageBoxButtons.OK,MessageBoxIcon.Information);
                

           }
          else
            {
                MessageBox.Show("the saving is success", "Faild", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }

            _mode = enMode.update;

            lbMode.Text = $"Edit Contact [  {_Contacts.ContactID.ToString() } ";

            lbIDValue.Text = _Contacts.ContactID.ToString();

        }

        private void btClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

    }
}
