using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;

namespace Insert_Data_to_DB
{
    internal class Program
    {
        static string connectionDbInfo = "Server=.;Database=ContactsDB;User Id=sa;Password=sa123456";

 /*       public struct stContect
        {
            public string FirstName { get; set; }
            public string LastName { get; set; }
            public string Email { get; set; }
            public string Password { get; set; }
            public string Phone { get; set; }
            public string Address { get; set; }
            public int CountryID { get; set; }
        }*/

        static void deleteRecord(int ContactID)
        {
            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " delete from Contacts where ContactID = @ContactID ";

            SqlCommand com = new SqlCommand(query, connection);

            com.Parameters.AddWithValue("@ContactID", ContactID);

            try
            {
                connection.Open();

                if (com.ExecuteNonQuery() > 0)
                {
                    Console.WriteLine("Record delete successfuly ");
                }
                else
                {
                    Console.WriteLine("Record delete faild");
                }

                connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

        }

        static void deleteRecordByInStatement(String ContactID)
        {
            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " delete from Contacts where ContactID in ( " + ContactID + " ) ";

            SqlCommand com = new SqlCommand(query, connection);

            try
            {
                connection.Open();

                if (com.ExecuteNonQuery() > 0)
                {
                    Console.WriteLine("Record delete successfuly ");
                }
                else
                {
                    Console.WriteLine("Record delete faild");
                }

                connection.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

        }

        /*        static void addNewContentWithReturnID(stContect contect)
                {
                    SqlConnection connection = new SqlConnection(connectionDbInfo);

                    string query = @"INSERT INTO [dbo].[Contacts]
                                        ([FirstName]
                                       ,[LastName]
                                       ,[Email]
                                       ,[Phone]
                                       ,[Address]
                                       ,[CountryID])
                                     VALUES
                                           (@FirstName
                                           ,@LastName
                                           ,@Email
                                           ,@Phone
                                           ,@Address
                                           ,@CountryID
                                            );
                                            select SCOPE_IDENTITY();
                                     ";

                    SqlCommand com = new SqlCommand(query, connection);
                    com.Parameters.AddWithValue("@FirstName", contect.FirstName);
                    com.Parameters.AddWithValue("@LastName", contect.LastName);
                    com.Parameters.AddWithValue("@Email", contect.Email);
                    com.Parameters.AddWithValue("@Phone", contect.Phone);
                    com.Parameters.AddWithValue("@Address", contect.Address);
                    com.Parameters.AddWithValue("@CountryID", contect.CountryID);

                    try
                    {
                        connection.Open();

                        object response = com.ExecuteScalar();

                        if (response != null)
                        {
                            Console.WriteLine("the identity number  (id) is ===> " + response.ToString());

                        }
                        connection.Close();
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine(ex.Message);
                    }

                }*/


        static void Main(string[] args)
        {
            /*         stContect contact = new stContect
                     {
                         FirstName = "mohammed",
                         LastName = "salehh",
                         Email = "ali.mohammed@gmail.com",
                         Phone = "12345y77645",
                         Address = "taiz",
                         CountryID = 5,

                     };*/


            deleteRecordByInStatement("7,8,9");
        }
    }
}
