using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccessLayer
{
    public class clsDataAccess
    {
        public static string connectionDbInfo = "Server=.;Database=ContactsDB;User Id=sa;Password=sa123456";

        public static bool find(int CountryID, ref string CountryName, ref string Code, ref string PhoneCode)
        {
            bool isFind = false;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Countries where CountryID = @CountryID ";

            SqlCommand cmd = new SqlCommand(query, connection);

            cmd.Parameters.AddWithValue("@CountryID", CountryID);

            try
            {
                connection.Open();
                SqlDataReader reader = cmd.ExecuteReader();

                while (reader.Read())
                {
                    isFind = true;

                    CountryName = (string)reader["CountryName"];
                    if (reader["Code"] != DBNull.Value)
                    {
                        Code = (string)reader["Code"];
                    }
                    else
                    {
                        Code = "";
                    }


                    if (reader["PhoneCode"] != DBNull.Value)
                    {
                        PhoneCode = (string)reader["PhoneCode"];
                    }
                    else
                    {
                        PhoneCode = "";
                    }

                }

                reader.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                isFind = false;
            }
            finally
            {
                connection.Close();
            }
            return isFind;
        }

        public static bool findByName(string searchName, ref int CountryID, ref string CountryName, ref string Code, ref string PhoneCode)
        {
            bool isFind = false;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Countries where CountryName like '" + searchName + "' ";

            SqlCommand cmd = new SqlCommand(query, connection);

            //cmd.Parameters.AddWithValue("@searchName", searchName);

            try
            {
                connection.Open();
                SqlDataReader reader = cmd.ExecuteReader();

                while (reader.Read())
                {
                    isFind = true;

                    CountryID = (int)reader["CountryID"];
                    CountryName = (string)reader["CountryName"];
                    
                    if (reader["Code"] != DBNull.Value)
                    {
                        Code = (string)reader["Code"];
                    }
                    else
                    {
                        Code = "";
                    }
                    

                    if (reader["PhoneCode"] != DBNull.Value)
                    {
                        PhoneCode = (string)reader["PhoneCode"];
                    }
                    else
                    {
                        PhoneCode = "";
                    }


                }

                reader.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                isFind = false;
            }
            finally
            {
                connection.Close();
            }
            return isFind;
        }

        public static int addNewContry(string CountryName, string Code, string PhoneCode)
        {
            int id = -1;
            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = @"INSERT INTO Countries
                              (CountryName,Code,PhoneCode
                              )
                           VALUES
                                 (@CountryName,@Code,@PhoneCode
                                  );
                                  select SCOPE_IDENTITY();
                           ";

            SqlCommand com = new SqlCommand(query, connection);
            com.Parameters.AddWithValue("@CountryName", CountryName);
            if (Code == "")
            {
                com.Parameters.AddWithValue("@Code", DBNull.Value);
            }
            else
            {
                com.Parameters.AddWithValue("@Code", Code);
            }

            if (PhoneCode == "")
            {
                com.Parameters.AddWithValue("@PhoneCode", PhoneCode);
            }
            else
            {
                com.Parameters.AddWithValue("@PhoneCode", DBNull.Value);
            }

            try
            {
                connection.Open();

                object response = com.ExecuteScalar();

                if (response != null)
                {
                    id = Convert.ToInt32(response);

                }

            }
            catch (Exception ex)
            {
                //Console.WriteLine(ex.Message);
            }
            finally
            {
                connection.Close();
            }

            return id;

        }

        public static bool updateContry(int CountryID, string CountryName , string Code, string PhoneCode

    )
        {
            int rowsAffected = 0;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = @"
                          UPDATE [dbo].[Countries]
                              SET [CountryName] = @CountryName,
                                [Code] = @Code,
                                [PhoneCode] = @PhoneCode
                              WHERE CountryID = @CountryID;
                          ";

            SqlCommand com = new SqlCommand(query, connection);

            com.Parameters.AddWithValue("@CountryID", CountryID);
            com.Parameters.AddWithValue("@CountryName", CountryName);
            if (Code == "")
            {
                com.Parameters.AddWithValue("@Code", DBNull.Value);
            }
            else
            {
                com.Parameters.AddWithValue("@Code", Code);
            }
            
            if (PhoneCode == "")
            {
                com.Parameters.AddWithValue("@PhoneCode", DBNull.Value);
            }
            else
            {
                com.Parameters.AddWithValue("@PhoneCode", PhoneCode);
               
            }

            try
            {
                connection.Open();

                rowsAffected = com.ExecuteNonQuery();




            }
            catch (Exception ex)
            {
                //Console.WriteLine(ex.Message);

            }
            finally
            {
                connection.Close();
            }
            return rowsAffected > 0;
        }

        public static bool delete(int CountryID)
        {
            int rowsAffected = 0;
            string query = " delete from Countries where CountryID = @CountryID;";
            SqlConnection connection = new SqlConnection(connectionDbInfo);

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@CountryID", CountryID);

            try
            {

                connection.Open();

                rowsAffected = command.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);  
            }
            finally
            {
                connection.Close();
            }
            return rowsAffected > 0;
        }

        public static DataTable getAllCountries()
        {
            DataTable dt = new DataTable();

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string guery = " select * from Countries ";

            SqlCommand com = new SqlCommand(guery, connection);

            try
            {
                connection.Open();

                SqlDataReader reader = com.ExecuteReader();

                dt.Load(reader);


            }
            catch (Exception ex)
            {

            }
            finally
            {
                connection.Close();
            }
            return dt;
        }

        public static bool isExsit(int CountryID)
        {
            bool isExsit = false;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = "select found = 1 from Countries where CountryID = @CountryID;";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@CountryID", CountryID);

            try
            {
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();


                if (reader.HasRows)
                {
                    isExsit = true;
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
            return isExsit;
        }

        public static bool isExsitByName(string searchName)
        {
            bool isExsit = false;

            SqlConnection connection = new SqlConnection(connectionDbInfo);


            string query = " select found = 1 from Countries where CountryName like '" + searchName + "' ";

            SqlCommand command = new SqlCommand(query, connection);


            try
            {
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();


                if (reader.HasRows)
                {
                    isExsit = true;
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
            return isExsit;
        }

    }
}
