using System;
using System.Data;
using System.Data.SqlClient;

namespace HR_Project_DataAccess_layer
{
    public class clsDataAccsess
    {

        public static string connectionDbInfo = " Server=.;Database=HR_Database;User Id=sa;Password=sa123456 ";

        static public bool findEmployeeById(int ID, ref string firstName, ref string lastName,
            ref string gendor, ref DateTime dateOfBirth, ref int countryID, ref int departmentID,
             ref DateTime hireDate, ref DateTime exiteDate, ref string monthlySalary, ref string bonusPrec)
        {
            bool isFind = false;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Employees where ID = @ID ";

            SqlCommand cmd = new SqlCommand (query,connection);

            cmd.Parameters.AddWithValue("@ID", ID);

           try
            {
                connection.Open (); 

                SqlDataReader reader = cmd.ExecuteReader ();
                while (reader.Read())
                {
                    isFind = true;
                    firstName = (string)reader["FirstName"];
                    lastName = (string)reader["LastName"];
                    gendor = (string)reader["Gendor"];
                    dateOfBirth = (DateTime)reader["DateOfBirth"];
                    Console.WriteLine(dateOfBirth);
                    hireDate = (DateTime)reader["HireDate"];
                    if (reader["ExitDate"] != DBNull.Value)
                    {
                        dateOfBirth = (DateTime)reader["ExitDate"];
                    }

                    countryID = (int)reader["CountryID"];

                    departmentID = (int)reader["DepartmentID"];

                    monthlySalary = reader["MonthlySalary"].ToString();

                    bonusPrec =  reader["BonusPerc"].ToString();

                }
                reader.Close ();

            }
            catch (Exception ex)
            {
                Console.WriteLine("hallo");
            }
            finally
            {
                connection.Close();
            }

            return isFind;
        }

        static public bool updateEmployee(int ID, string firstName, string lastName, string gendor, DateTime dateOfBirth, int countryID, int departmentID,
             DateTime hireDate, DateTime exitDate, string monthlySalary, string bouncePrec)
        {
            int rowEffect = 0;

            SqlConnection connection = new SqlConnection(connectionDbInfo);
            string query = @"
                            UPDATE [dbo].[Employees]
                               SET [FirstName] = @FirstName
                                  ,[LastName] = @LastName
                                  ,[Gendor] = @Gendor
                                  ,[DateOfBirth] = @DateOfBirth
                                  ,[CountryID] = @CountryID
                                  ,[DepartmentID] = @DepartmentID
                                  ,[HireDate] = @HireDate
                                  ,[ExitDate] = @ExitDate
                                  ,[MonthlySalary] = @MonthlySalary
                                  ,[BonusPerc] = @BonusPerc
                             WHERE ID = @ID
                        ";

            SqlCommand com =  new SqlCommand (query,connection);

            com.Parameters.AddWithValue("@ID",ID);
            com.Parameters.AddWithValue("@FirstName", firstName);
            com.Parameters.AddWithValue("@LastName", lastName);
            com.Parameters.AddWithValue("@Gendor", gendor);
            com.Parameters.AddWithValue("@DateOfBirth", dateOfBirth);
            com.Parameters.AddWithValue("@CountryID", countryID);
            com.Parameters.AddWithValue("@DepartmentID", departmentID);
            com.Parameters.AddWithValue("@HireDate", hireDate);
            com.Parameters.AddWithValue("@ExitDate", exitDate);
            com.Parameters.AddWithValue("@MonthlySalary", Convert.ToDouble(monthlySalary));
            com.Parameters.AddWithValue("@BonusPerc", bouncePrec);

            try
            {
                connection.Open();
                rowEffect = com.ExecuteNonQuery();
                
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                connection.Close();
            }

            return rowEffect > 0;
        }


        static public bool addNewEmployee(string firstName, string lastName, string gendor, DateTime dateOfBirth, int countryID, int departmentID,
     DateTime hireDate, DateTime exitDate, string monthlySalary, string bouncePrec)
        {
            int ID = -1;

            SqlConnection connection = new SqlConnection(connectionDbInfo);
            string query = @"
                            INSERT INTO [dbo].[Employees]
                               ([FirstName]
                               ,[LastName]
                               ,[Gendor]
                               ,[DateOfBirth]
                               ,[CountryID]
                               ,[DepartmentID]
                               ,[HireDate]
                               ,[ExitDate]
                               ,[MonthlySalary]
                               ,[BonusPerc])
                         VALUES
                               (@FirstName,@LastName,@Gendor,@DateOfBirth,@CountryID,@DepartmentID
                                ,@HireDate,@ExitDate,@MonthlySalary,@BonusPerc); 
                                   
                        ";

            SqlCommand com = new SqlCommand(query, connection);

            com.Parameters.AddWithValue("@ID", ID);
            com.Parameters.AddWithValue("@FirstName", firstName);
            com.Parameters.AddWithValue("@LastName", lastName);
            com.Parameters.AddWithValue("@Gendor", gendor);
            com.Parameters.AddWithValue("@DateOfBirth", dateOfBirth);
            com.Parameters.AddWithValue("@CountryID", countryID);
            com.Parameters.AddWithValue("@DepartmentID", departmentID);
            com.Parameters.AddWithValue("@HireDate", hireDate);
            com.Parameters.AddWithValue("@ExitDate", exitDate);
            com.Parameters.AddWithValue("@MonthlySalary", Convert.ToDouble(monthlySalary));
            com.Parameters.AddWithValue("@BonusPerc", Convert.ToDouble(bouncePrec));

            try
            {
                connection.Open();
               ID = Convert.ToInt32(com.ExecuteScalar());

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                connection.Close();
            }

            return ID != -1;
        }


        static public bool isExist(int ID)
        {
            int isFound = 0;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select found = 1 from Employees where ID = @ID ";

            SqlCommand cmd = new SqlCommand(query, connection);

            cmd.Parameters.AddWithValue("@ID", ID);

            try
            {
                connection.Open();

               isFound =  Convert.ToInt32(cmd.ExecuteScalar());

               //Console.WriteLine("isFound = " + isFound);

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                connection.Close();
            }

            return isFound == 1;
        }

        static public bool deleteEmployee(int ID)
        {
            int rowEffect = 0;
            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " delete from Employees where ID =  @ID ";

            SqlCommand com = new SqlCommand(query,connection);

            com.Parameters.AddWithValue("ID",ID);

            try
            { 
                connection.Open();

               rowEffect = com.ExecuteNonQuery();
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.Message);

            }
            finally
            {
                connection.Close();
            }
            return rowEffect > 0;
        }

        static public DataTable getListEmployees()
        {
            DataTable dt = new DataTable();

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = @" 
                            select em.ID, FirstName + ' ' +  LastName as FullName,
                            Gendor = 
                            case 
                            when Gendor = 'M' then 'Male'
                            when Gendor = 'F' then 'Female'
                            else 'Unknown'
                            end
                            , DATEDIFF(year,em.DateOfBirth,getDATE()) as Age,
                            em.MonthlySalary,em.BonusPerc,
                            d.Name as Department, c.Name as Country 
                            from Employees em
                            join Departments d on d.ID = em.DepartmentID
                            join Countries c on c.ID = em.CountryID
                            order by FullName asc ";

            SqlCommand com = new SqlCommand(query, connection);

            try
            {
                connection.Open();
                SqlDataReader reader = com.ExecuteReader();

                if (reader.HasRows)
                {
                    dt.Load(reader);
                }


            }
            catch(Exception ex) {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                connection.Close();
            }

            return dt;
        }


        static public bool findCountry( int ID, ref string CountryName)
        {
            bool isFind = false;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Countries where ID = @ID ";

            SqlCommand cmd = new SqlCommand(query, connection);

            cmd.Parameters.AddWithValue("@ID", ID);

            try
            {
                connection.Open();

                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    isFind = true;
                    CountryName = (string) reader["Name"];


                }
                reader.Close();

            }
            catch (Exception ex)
            {
            }
            finally
            {
                connection.Close();
            }

            return isFind;
        }


        static public bool findCountry(string CountryName, ref int ID)
        {
            bool isFind = false;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Countries where Name = @CountryName ";

            SqlCommand cmd = new SqlCommand(query, connection);

            cmd.Parameters.AddWithValue("@CountryName", CountryName);

            try
            {
                connection.Open();

                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    isFind = true;
                    ID = (int)reader["ID"];


                }
                reader.Close();

            }
            catch (Exception ex)
            {
            }
            finally
            {
                connection.Close();
            }

            return isFind;
        }

        static public DataTable getLisCountries()
        {
            DataTable dt = new DataTable();

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select ID,Name as CountryName from Countries; ";

            SqlCommand com = new SqlCommand(query, connection);

            try
            {
                connection.Open();
                SqlDataReader reader = com.ExecuteReader();

                if (reader.HasRows)
                {
                    dt.Load(reader);
                }


            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                connection.Close();
            }

            return dt;
        }


        static public DataTable getListDepartments()
        {
            DataTable dt = new DataTable();

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select ID,Name as DepartmentName from Departments; ";

            SqlCommand com = new SqlCommand(query, connection);

            try
            {
                connection.Open();
                SqlDataReader reader = com.ExecuteReader();

                if (reader.HasRows)
                {
                    dt.Load(reader);
                }


            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                connection.Close();
            }

            return dt;
        }

        static public bool findDepartment(int ID, ref string DepartmentName)
        {
            bool isFind = false;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Departments where ID = @ID ";

            SqlCommand cmd = new SqlCommand(query, connection);

            cmd.Parameters.AddWithValue("@ID", ID);

            try
            {
                connection.Open();

                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    isFind = true;
                    DepartmentName = (string)reader["Name"];


                }
                reader.Close();

            }
            catch (Exception ex)
            {
            }
            finally
            {
                connection.Close();
            }

            return isFind;
        }


        static public bool findDepartment(string DepartmentName, ref int ID)
        {
            bool isFind = false;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Departments where Name = @DepartmentName ";

            SqlCommand cmd = new SqlCommand(query, connection);

            cmd.Parameters.AddWithValue("@DepartmentName", DepartmentName);

            try
            {
                connection.Open();

                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    isFind = true;
                    ID = (int)reader["ID"];


                }
                reader.Close();

            }
            catch (Exception ex)
            {
            }
            finally
            {
                connection.Close();
            }

            return isFind;
        }


    }
}
