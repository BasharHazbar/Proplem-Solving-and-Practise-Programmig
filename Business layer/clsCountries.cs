using System;
using System.Data;
using DataAccessLayer;

namespace Business_layer
{
    public class clsCountries
    {
        enum enMode { emptyMode = 0, addNewMode = 1, updateMode = 2 };
        public int CountryID { get; set; }
        public string  CountryName{ get; set; }
        public string Code { get; set; }

        public string PhoneCode { get; set; }

        private enMode mode;

        public clsCountries()
        {
            CountryID = -1;
            CountryName = "";
            Code = "";
            PhoneCode = "";
            mode = enMode.addNewMode;

        }

        private clsCountries(int CountryID, string CountryName, string Code, string PhoneCode
            )
        {
            this.CountryID = CountryID;
            this.CountryName = CountryName;
            this.Code = CountryName;
            this.PhoneCode = PhoneCode;
            this.mode = enMode.updateMode;

        }

        private bool _addNewContry()
        {
            this.CountryID = clsDataAccess.addNewContry(this.CountryName,this.Code,this.PhoneCode);

            return this.CountryID != -1;
        }

        private bool _updateContry()
        {
            return clsDataAccess.updateContry(this.CountryID, this.CountryName,this.Code,this.PhoneCode);
        }

        public static clsCountries find(int CountryID)
        {
            string CountryName = "";
            string Code = "";
            string PhoneCode = "";


            if (clsDataAccess.find(CountryID, ref CountryName,ref Code, ref PhoneCode))
                return new clsCountries(CountryID, CountryName,Code,PhoneCode);
            else
                return null;

        }

        public static clsCountries findByName(string searchName)
        {
            string CountryName = "";
            string Code = "";
            string PhoneCode = "";
            int CountryID = -1;


            if (clsDataAccess.findByName(searchName, ref CountryID, ref CountryName,ref Code,ref PhoneCode))
                return new clsCountries(CountryID, CountryName,Code,PhoneCode);
            else
                return null;

        }

        public bool save()
        {
            switch (mode)
            {
                case enMode.addNewMode:
                    if (_addNewContry())
                    {
                        mode = enMode.updateMode;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                case enMode.updateMode:
                    return _updateContry();

                default:
                    return false;
            }
        }

        public static bool delete(int CountryID)
        {
            return clsDataAccess.delete(CountryID);
        }

        public static DataTable getAllCountries()
        {
            return clsDataAccess.getAllCountries();
        }

        public static bool isExsit(int id)
        {
            return clsDataAccess.isExsit(id);
        }

        public static bool isExsitByName(string CountryName)
        {
            return clsDataAccess.isExsitByName(CountryName);
        }

    }
}
