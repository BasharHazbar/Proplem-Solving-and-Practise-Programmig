using System;
using System.Data;
using HR_Project_DataAccess_layer;

namespace HR_Project_Business_Layer
{
    public class clsHR
    {
       

        public int ID { set; get; }
        public string FirstName { set; get;  }
        public string LastName { set; get; }

        public string Gendor { set; get; }

        public DateTime DateOfBirth { set; get; }

        public int CountryID { set; get; }

        public int DepartmentID { set; get; }

        public DateTime HireDate { set; get; }

        public DateTime ExiteDate { set; get; }

        public string MonthlySalary { set; get; }

        public  string BouncePrec { set; get; }
   


        public clsHR()
        {
            ID = -1;
            this.FirstName = "";
            this.LastName = "";
            this.Gendor = "";
            this.DateOfBirth = DateTime.Now;
            this.CountryID = -1;
            this.DepartmentID = -1;
            this.HireDate = DateTime.Now;
            this.ExiteDate = DateTime.Now;
            this.MonthlySalary = "";
            this.BouncePrec = "";   
        }

        clsHR(string firstName, string lastName, string gander, DateTime dateOfBirth, int countryID, int departmentID, 
             DateTime hireDate, DateTime exiteDate, string monthlySalary, string bouncePrec)
        {
            FirstName = firstName;
            LastName = lastName;
            Gendor = gander;
            DateOfBirth = dateOfBirth;
            CountryID = countryID;
            DepartmentID = departmentID;
            HireDate = hireDate;
            ExiteDate = exiteDate;
            MonthlySalary = monthlySalary;
            BouncePrec = bouncePrec;
        }


        static public clsHR findEmployeeByID(int ID)
        {
        
            string FirstName = "";
            string LastName = "";
            string Gender = "";
            DateTime DateOfBirth = DateTime.Now;
            int CountryID = -1;
            int DepartmentID = -1;
            DateTime HireDate = DateTime.Now;
            DateTime ExiteDate = DateTime.Now;
            string MonthlySalary = "";
            string BouncePrec = "";

            if (clsDataAccsess.findEmployeeById(ID, ref FirstName,  ref LastName, 
                ref Gender,ref DateOfBirth, ref CountryID, ref DepartmentID, ref HireDate, ref ExiteDate,
                ref MonthlySalary, ref BouncePrec))
            {
                return new clsHR(FirstName,LastName,Gender,DateOfBirth,CountryID,
                    DepartmentID,HireDate,ExiteDate,MonthlySalary,BouncePrec);
            }
            else { return null; }
        }

        bool updateEmployee()
        {
            return clsDataAccsess.updateEmployee(ID, FirstName,LastName,Gendor,DateOfBirth
                ,CountryID,DepartmentID,HireDate,ExiteDate,MonthlySalary,BouncePrec);

        }

        bool addNewEmployee()
        {
            return clsDataAccsess.addNewEmployee(FirstName,LastName,Gendor,DateOfBirth,
                CountryID,DepartmentID,HireDate,ExiteDate,MonthlySalary, BouncePrec);
        }


        public bool save()
        {
           if (ID != - 1)
            {
               if (updateEmployee())
                {
                    return true;
                }  
               else
                {
                    return false;
                }
            }
           else
            {
                return addNewEmployee();
            }
        }

        static public bool isExist(int ID)
        {
            return clsDataAccsess.isExist(ID);
                
        }


        static public bool deleteEmployee(int ID)
        {
            return clsDataAccsess.deleteEmployee(ID);
        }



        static public DataTable getListEmployees()
        {
            return clsDataAccsess.getListEmployees();
        }

    }


    public class clsCountries
    {
        public int _ID { get; set; }
        public string _CountryName { get; set; }

        clsCountries(int ID,string CountryName)
        {
            this._ID = ID;
            this._CountryName = CountryName;
        }

        static public clsCountries findCountry(int ID)
        {
            string CountryName = "";

            if (clsDataAccsess.findCountry(ID,ref CountryName))
            {
                return new clsCountries(ID,CountryName);
            }
            else
            {
                return null;
            }

        }

        static public clsCountries findCountry(string CountryName)
        {
             int ID = -1;

            if (clsDataAccsess.findCountry(CountryName, ref ID))
            {
                return new clsCountries(ID, CountryName);
            }
            else
            {
                return null;
            }

        }

        static public DataTable getLisCountries()
        {
            return clsDataAccsess.getLisCountries();
        }





    }
    public class clsDepartMents
    {
        public int _ID { get; set; }
        public string _DepartmentName { get; set; }

        clsDepartMents(int ID, string DepartmentName)
        {
            this._ID = ID;
            this._DepartmentName = DepartmentName;
        }

        static public clsDepartMents findDepartment(int ID)
        {
            string DepartmentName = "";

            if (clsDataAccsess.findDepartment(ID, ref DepartmentName))
            {
                return new clsDepartMents(ID, DepartmentName);
            }
            else
            {
                return null;
            }

        }


        static public clsDepartMents findDepartment(string DepartmentName)
        {
            int ID = -1;

            if (clsDataAccsess.findDepartment(DepartmentName, ref ID))
            {
                return new clsDepartMents(ID, DepartmentName);
            }
            else
            {
                return null;
            }

        }

        static public DataTable getListDepartments()
        {
            return clsDataAccsess.getListDepartments();
        }


    }
}
