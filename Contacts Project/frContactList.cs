using System;
using System.Windows.Forms;
using ContactsBusinessLayer;

namespace Contacts_Project
{
    public partial class frmContactList : Form
    {
        public frmContactList()
        {
            InitializeComponent();
        }

    
        private void _RefreshContactsList()
        {
            DataGridContacts.DataSource = clsContacts.getAllContacts();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            _RefreshContactsList();
        }

        private void btAddNewContact_Click(object sender, EventArgs e)
        {
            frAddEditContact frm = new frAddEditContact(-1);
            frm.ShowDialog();
            _RefreshContactsList();

        }


        private void editToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int ContactID = (int)DataGridContacts.CurrentRow.Cells[0].Value;
            clsContacts _Contacts = clsContacts.find(ContactID);

            if (_Contacts == null)
            {
                MessageBox.Show("This form will be closed because No Contact with ID = " + ContactID);
                return;
            }
            frAddEditContact frm = new frAddEditContact(ContactID);
    
            frm.ShowDialog();

            _RefreshContactsList();
        }

        private void deleteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            int ContactID = (int) DataGridContacts.CurrentRow.Cells[0].Value;

            if (MessageBox.Show("Are you sure to delete the contact  [ " + ContactID + " ]" ,
                "Confirm",MessageBoxButtons.YesNo,MessageBoxIcon.Exclamation) == DialogResult.Yes)
            {
                if (clsContacts.delete(ContactID))
                {
                    MessageBox.Show("The Contact succssesfly delete","Succsess",MessageBoxButtons.OK,MessageBoxIcon.Information);
                    _RefreshContactsList();
                }
                else
                {
                    MessageBox.Show("The Contact not succssesfly delete", "Faild", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
            }
           ;
            
        }

    }
}
