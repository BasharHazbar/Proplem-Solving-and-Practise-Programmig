using System;
using System.Data;
using HR_Project_Business_Layer;


namespace HR_presentation_layer
{
    internal class Program
    {

        static public void findEmployeeById(int ID)
        {
            clsHR employee = clsHR.findEmployeeByID(ID);
            if (employee != null)
            {
                Console.WriteLine(employee.FirstName);
                Console.WriteLine(employee.LastName);
                Console.WriteLine(employee.HireDate);
                Console.WriteLine(employee.ExiteDate);
                Console.WriteLine(employee.BouncePrec);
                Console.WriteLine(employee.Gendar);
                Console.WriteLine(employee.MonthlySalary);

            }

        }

        static public void isExsit(int ID)
        {
            if (clsHR.isExist(ID))
            {
                Console.WriteLine("thanks found");
            }
        }

        static public void updateEmployee(int ID)
        {
            if (clsHR.isExist(ID))
            {
                
                clsHR updateEmployee = new clsHR();
                updateEmployee.ID = ID;
                updateEmployee.FirstName = "Braaa";
                updateEmployee.LastName = "Khaled";
                updateEmployee.Gendar = "M";
                updateEmployee.DateOfBirth = new DateTime(1982,3,3);
                updateEmployee.CountryID = 2;
                updateEmployee.DepartmentID = 3;
                updateEmployee.HireDate = new DateTime(1965,3,3);
                updateEmployee.ExiteDate = new DateTime(1985,4,4);
                updateEmployee.MonthlySalary = "5000.5";

               if (updateEmployee.save())
                {
                    Console.WriteLine("it is aready update");
                }



            }
        }

        static public void addNewEmployee()
        {
            clsHR updateEmployee = new clsHR();
            updateEmployee.FirstName = "ali";
            updateEmployee.LastName = "saleh";
            updateEmployee.Gendar = "M";
            updateEmployee.DateOfBirth = new DateTime(1984, 3, 3);
            updateEmployee.CountryID = 2;
            updateEmployee.DepartmentID = 3;
            updateEmployee.HireDate = new DateTime(1967, 3, 3);
            updateEmployee.ExiteDate = new DateTime(1985, 4, 4);
            updateEmployee.MonthlySalary = "5000";

            if (updateEmployee.save())
            {
                Console.WriteLine("it is aready insert");
            }

        }
        static public void deleteEmployee(int ID)
        {
            if (clsHR.deleteEmployee(ID))
            {
                Console.WriteLine(" it is aready delete");
            }
        }

        static public void gitListEmployee()
        {
            DataTable dt = clsHR.getListEmployees();

            foreach (DataRow row in dt.Rows)
            {
                Console.WriteLine($" full name :- {row["FullName"]}   gendor :- {row["Gendor"]}   age :-  {row["Age"]}" +
                    $"  Month salary :- {row["MonthlySalary"]}  bonus perc :-  {row["BonusPerc"]}  department :-  {row["Department"]}  " +
                    $" country :- {row["Country"]}");

                Console.WriteLine();

            }
        }
        static void Main(string[] args)
        {
            //findEmployeeById(1286);
            //updateEmployee(285);
            //addNewEmployee();

            //deleteEmployee(1286);

            gitListEmployee(); 




        }
    }
}
