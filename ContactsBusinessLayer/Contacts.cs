using System;
using System.Data;
using ContactDataAccessLayer;

namespace ContactsBusinessLayer
{
    public class clsContacts
    {
        enum enMode { emptyMode = 0, addNewMode = 1, updateMode = 2 };
        public int ContactID { get; set; }
        public string firstName { get; set; }
        public string lastName { get; set; }
        public string email { get; set; }
        public string phone { get; set; }
        public string address { get; set; }
        public DateTime dateOfBirth { get; set; }
        public int countryID { get; set; }
        public string imagePath { get; set; }

        private enMode mode;

        public clsContacts() {
             ContactID = -1;
             firstName = "";
             lastName = "";
             email = "";
             phone = "";
             address = "";
             dateOfBirth = DateTime.Now;
             countryID = -1;
             imagePath = "";
            mode = enMode.addNewMode;
            
        }

        private clsContacts(int id,string firstName, string lastName, string email, string phone, string address,
            DateTime dateOfBirth, int countryID, string imagePath
            ) 
        { 
            this.ContactID = id;   
            this.firstName = firstName; 
            this.lastName = lastName;
            this.email = email;
            this.phone = phone;
            this.address = address;
            this.dateOfBirth = dateOfBirth;
            this.countryID = countryID;
            this.imagePath = imagePath;
            mode = enMode.updateMode;
        }

        private bool _addNewContant()
        {
            this.ContactID = clsDataAccess.addNewContent(this.firstName, this.lastName, this.email, this.phone,
                this.address, this.dateOfBirth, this.countryID,this.imagePath);

            return this.ContactID != -1;
        }

        private bool _updateContatc() {
            return clsDataAccess.updateContatc(this.ContactID, this.firstName, this.lastName, this.email, this.phone,
                this.address, this.dateOfBirth, this.countryID, this.imagePath);
        }

        public static clsContacts find(int id)
        {
             string firstName = "";
             string lastName = "";
             string email  =  "";
             string phone  = "";
             string address = "";
             DateTime dateOfBirth = DateTime.Now;
             int countryID = -1;
             string imagePath = "";

            if (clsDataAccess.find(id, ref firstName, ref lastName, ref email, ref phone, ref address,
                ref dateOfBirth, ref countryID, ref imagePath))
                return new clsContacts(id,firstName,lastName,email,phone,address,dateOfBirth,countryID,imagePath);
            else 
                return null;

        }

 



        public bool save()
        {
            switch (mode)
            {
                case enMode.addNewMode:
                   if (_addNewContant())
                    {
                        mode = enMode.updateMode;
                        return true;
                    }
                   else
                    {
                        return false;
                    }
                case enMode.updateMode:
                    return _updateContatc();

                default:
                    return false;
            }
        }

        public static bool delete(int ContatcID)
        {
            return clsDataAccess.delete(ContatcID);
        }

        public static DataTable getAllContacts()
        {
            return clsDataAccess.getAllContacts();
        }

        public static bool isExsit(int id)
        {
            return clsDataAccess.isExsit(id);
        }
    }

    public class clsContries {
    
        public int CountryID { get; set; }

        public string CountryName { get; set; }
        public string Code { get; set; }

        public string PhoneCode { get; set; }



        clsContries(int CountryID, string CountryName, string Code, string PhoneCode )
        {
            this.CountryID = CountryID;
            this.CountryName = CountryName;
            this.Code = Code;
            this.PhoneCode = PhoneCode;
        }


        public static clsContries FindCountry(int CountryID)
        {
            string CountryName = "";
            string Code = "";
            string PhoneCode = "";

            if (clsDataAccess.FindCountry(CountryID, ref CountryName, ref Code, ref PhoneCode))
                return new clsContries(CountryID,CountryName,Code,PhoneCode);

            else
                return null;

        }

        public static clsContries FindCountryByName(string CountryName)
        {
            string Code = "";
            string PhoneCode = "";
            int CountryID = -1;

            if (clsDataAccess.FindCountryByName(CountryName, ref CountryID, ref Code, ref PhoneCode))
                return new clsContries(CountryID, CountryName, Code, PhoneCode);

            else
                return null;

        }


        public static DataTable getAllContries()
        {
            return clsDataAccess.getAllContries();
        }




    }

}
