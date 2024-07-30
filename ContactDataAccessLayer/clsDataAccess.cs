using System;
using System.Data;
using System.Data.SqlClient;
using System.Net;

namespace ContactDataAccessLayer
{
    public class clsDataAccess
    {
        public static string connectionDbInfo = "Server=.;Database=ContactsDB;User Id=sa;Password=sa123456";

        public static bool find(int ContactID, ref string firstName, ref string lastName, ref string email,
            ref string phone, ref string address,ref DateTime dateOfBirth,ref int CountryID, ref string imagePath

            )
        {
            bool isFind = false;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Contacts where ContactID = @ContactID ";

            SqlCommand cmd = new SqlCommand(query, connection);

            cmd.Parameters.AddWithValue("@ContactID", ContactID);

            try
            {
                connection.Open();
                SqlDataReader reader = cmd.ExecuteReader();

                while (reader.Read())
                {
                    isFind = true;

                     firstName = (string)reader["FirstName"];
                     lastName = (string)reader["LastName"];
                     email = (string)reader["Email"];
                     phone = (string)reader["Phone"];
                     address = (string)reader["Address"];
                     dateOfBirth = (DateTime) reader["DateOfBirth"];
                     
                    if (reader["ImagePath"] != DBNull.Value)
                    {
                        imagePath = (string)reader["ImagePath"];
                    }

                    CountryID = (int)reader["CountryID"];
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

        public static int addNewContent(string firstName, string lastName, string email,
            string phone, string address, DateTime dateOfBirth, int CountryID, string imagePath)
        {
            int  id = -1;
            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = @"INSERT INTO [dbo].[Contacts]
                                ([FirstName]
                               ,[LastName]
                               ,[Email]
                               ,[Phone]
                               ,[Address]
                               ,[DateOfBirth]
                               ,[CountryID]
                               ,[ImagePath]

                                )
                             VALUES
                                   (@FirstName
                                   ,@LastName
                                   ,@Email
                                   ,@Phone
                                   ,@Address
                                   ,@DateOfBirth
                                   ,@CountryID
                                   ,@ImagePath
                                    );
                                    select SCOPE_IDENTITY();
                             ";

            SqlCommand com = new SqlCommand(query, connection);
            com.Parameters.AddWithValue("@FirstName",firstName);
            com.Parameters.AddWithValue("@LastName", lastName);
            com.Parameters.AddWithValue("@Email", email);
            com.Parameters.AddWithValue("@Phone", phone);
            com.Parameters.AddWithValue("@Address",address );
            com.Parameters.AddWithValue("@DateOfBirth", dateOfBirth);
            com.Parameters.AddWithValue("@CountryID",CountryID );

            if (imagePath != "")
            {
                com.Parameters.AddWithValue("@ImagePath", imagePath);
            }
            else
            {
                com.Parameters.AddWithValue("@ImagePath", DBNull.Value);
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

        public static bool updateContatc(int ContactID, string firstName, string lastName, string email,
            string phone, string address, DateTime dateOfBirth, int CountryID, string imagePath

    )
        {
            int rowsAffected = 0;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

          string query = @"
                            UPDATE [dbo].[Contacts]
                                SET [FirstName] = @FirstName,
                                    [LastName] = @LastName,
                                    [Email] = @Email,
                                    [Phone] = @Phone,
                                    [Address] = @Address,
                                    [DateOfBirth] = @DateOfBirth,
                                    [CountryID] = @CountryID,
                                    [ImagePath] = @ImagePath
                                WHERE ContactID = @ContactID;
                            ";

            SqlCommand com = new SqlCommand(query, connection);

            com.Parameters.AddWithValue("@ContactID", ContactID);
            com.Parameters.AddWithValue("@FirstName", firstName);
            com.Parameters.AddWithValue("@LastName", lastName);
            com.Parameters.AddWithValue("@Email", email);
            com.Parameters.AddWithValue("@Phone", phone);
            com.Parameters.AddWithValue("@Address", address);
            com.Parameters.AddWithValue("@DateOfBirth", dateOfBirth);
            com.Parameters.AddWithValue("@CountryID", CountryID);
           

            if (imagePath != "")
            {
                com.Parameters.AddWithValue("@ImagePath", imagePath);
            }
            else
            {
                com.Parameters.AddWithValue("@ImagePath", DBNull.Value);
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

        public static bool delete(int ContatcID)
        {
            int rowsAffected = 0;
            string query = " delete from Contacts where ContactID = @ContactID;";
            SqlConnection connection = new SqlConnection(connectionDbInfo);

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@ContactID",ContatcID);

            try
            {

                connection.Open();

                rowsAffected = command.ExecuteNonQuery();
                Console.WriteLine("test");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);  
            }
            finally
            {
                connection.Close() ;
            }
            return rowsAffected > 0;
        }

        public static DataTable getAllContacts()
        {
                DataTable dt = new DataTable();

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string guery = @" select ContactID,FirstName + ' ' + LastName as FullName, Email,
                                Phone,Address, DateOfBirth, ImagePath, CountryName, Code, PhoneCode from Contacts ct
                                join Countries Cr on cr.CountryID = ct.CountryID; ";

            SqlCommand com = new SqlCommand(guery, connection);

            try
            {
                connection.Open();

                SqlDataReader reader = com.ExecuteReader();

                dt.Load(reader);


            }
            catch (Exception ex) { 
            
            }
            finally
            {
                connection.Close();
            }
            return dt;
        }

        public static bool isExsit(int ContactID)
      {
            bool isExsit = false;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = "select found = 1 from Contacts where ContactID = @ContactID;";

            SqlCommand command = new SqlCommand(query, connection);

            command.Parameters.AddWithValue("@ContactID",ContactID);

            try
            {
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();
                

                if (reader.HasRows)
                {
                    isExsit = true;
                }

            }

            catch (Exception ex) {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                connection.Close();
            }
            return isExsit;
      }




        public static bool FindCountry(int CountryID, ref string CountryName, ref string Code, ref string PhoneCode)
        {
            DataTable dt = new DataTable();

            bool isFind = false;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string guery = " select * from Countries where CountryID = @CountryID ";

            SqlCommand com = new SqlCommand(guery, connection);

            com.Parameters.AddWithValue("@CountryID", CountryID);

            try
            {
                connection.Open();



                SqlDataReader reader = com.ExecuteReader();

                while (reader.Read())
                {
                    isFind = true;
                    CountryName = (string) reader["CountryName"];

                    if (reader["Code"] != DBNull.Value)
                    {
                        Code = (string)reader["Code"];
                    }

                    if (reader["PhoneCode"] != DBNull.Value)
                    {
                        PhoneCode = (string)reader["PhoneCode"];
                    }
                }


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

        public static bool FindCountryByName(string CountryName, ref int  CountryID, ref string Code, ref string PhoneCode)
        {
            DataTable dt = new DataTable();

            bool isFind = false;

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string guery = " select * from Countries where CountryName = @CountryName ";

            SqlCommand com = new SqlCommand(guery, connection);

            com.Parameters.AddWithValue("@CountryName", CountryName);

            try
            {
                connection.Open();



                SqlDataReader reader = com.ExecuteReader();

                while (reader.Read())
                {
                    isFind = true;
                    CountryID = (int) reader["CountryID"];

                    if (reader["Code"] != DBNull.Value)
                    {
                        Code = (string)reader["Code"];
                    }

                    if (reader["PhoneCode"] != DBNull.Value)
                    {
                        PhoneCode = (string)reader["PhoneCode"];
                    }
                }


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

        public static DataTable getAllContries()
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

    }
}
