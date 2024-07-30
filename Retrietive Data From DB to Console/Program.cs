using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Data.SqlClient;
using System.ComponentModel;

namespace Retrietive_Data_From_DB_to_Console
{
    internal class Program
    {
        static string connectionDbInfo = "Server=.;Database=ContactsDB;User Id=sa;Password=sa123456";

        static void printAllContacts()
        {
            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Contacts ";

            SqlCommand cmd = new SqlCommand(query, connection);

            try
            {
                connection.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    int contactId = (int)reader["ContactID"];
                    string firstName = (string)reader["firstName"];
                    string lastName = (string)reader["lastName"];
                    string email = (string)reader["email"];
                    string address = (string)reader["address"];
                    int countryId = (int)reader["CountryId"];

                    Console.WriteLine($"Contat Id : {contactId}");
                    Console.WriteLine($"firstName : {firstName}");
                    Console.WriteLine($"lastName  : {lastName}");
                    Console.WriteLine($"email     : {email}");
                    Console.WriteLine($"address   : {address}");
                    Console.WriteLine($"countryId : {countryId}");
                    Console.WriteLine();
                }
                connection.Close();
                reader.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("ERROR " + ex.Message);
            }
        }

        static void printAllContactsWithFirstName(string firstname)
        {
            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Contacts where FirstName = @FirstName ";

            SqlCommand cmd = new SqlCommand(query, connection);


            cmd.Parameters.AddWithValue("@FirstName", firstname);

            try
            {
                connection.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    int contactId    = (int)reader["ContactID"];
                    string firstName = (string)reader["firstName"];
                    string lastName  = (string)reader["lastName"];
                    string email     = (string)reader["email"];
                    string address   = (string)reader["address"];
                    int countryId    = (int)reader["CountryId"];

                    Console.WriteLine($"Contat Id : {contactId}");
                    Console.WriteLine($"firstName : {firstName}");
                    Console.WriteLine($"lastName  : {lastName}");
                    Console.WriteLine($"email     : {email}");
                    Console.WriteLine($"address   : {address}");
                    Console.WriteLine($"countryId : {countryId}");
                    Console.WriteLine();
                }
                connection.Close();
                reader.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("ERROR " + ex.Message);
            }

        }

        static void findByFirstNameAndContactId(string firstName, int countryID)
        {
            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Contacts where FirstName = @FirstName and CountryID = @CountryID ";

            SqlCommand com = new SqlCommand(query, connection);

            com.Parameters.AddWithValue("@FirstName",firstName);

            com.Parameters.AddWithValue("@CountryID", countryID);

            try
            {
                connection.Open();
                SqlDataReader reader = com.ExecuteReader();

                while (reader.Read())
                {
                    int contactId = (int)reader["ContactID"];
                    string firstNamee = (string)reader["firstName"];
                    string lastName = (string)reader["lastName"];
                    string email = (string)reader["email"];
                    string address = (string)reader["address"];
                    int countryId = (int)reader["CountryId"];

                    Console.WriteLine($"Contat Id : {contactId}");
                    Console.WriteLine($"firstName : {firstNamee}");
                    Console.WriteLine($"lastName  : {lastName}");
                    Console.WriteLine($"email     : {email}");
                    Console.WriteLine($"address   : {address}");
                    Console.WriteLine($"countryId : {countryId}");
                    Console.WriteLine();
                }
                connection.Close();
                reader.Close();
            }

            catch(Exception ex)
            {
                Console.WriteLine("ERROR " + ex.Message);
            }
        }



        static void searchContactsStartWith(string startWith)
        {
            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Contacts where FirstName like  '' + @startWith + '%' ";

            SqlCommand com = new SqlCommand(query, connection);
            com.Parameters.AddWithValue("@startWith", startWith);

            try
            {
                connection.Open();
                SqlDataReader reader = com.ExecuteReader();

                while (reader.Read())
                {
                    int contactId = (int)reader["ContactID"];
                    string firstNamee = (string)reader["firstName"];
                    string lastName = (string)reader["lastName"];
                    string email = (string)reader["email"];
                    string address = (string)reader["address"];
                    int countryId = (int)reader["CountryId"];

                    Console.WriteLine($"Contat Id : {contactId}");
                    Console.WriteLine($"firstName : {firstNamee}");
                    Console.WriteLine($"lastName  : {lastName}");
                    Console.WriteLine($"email     : {email}");
                    Console.WriteLine($"address   : {address}");
                    Console.WriteLine($"countryId : {countryId}");
                    Console.WriteLine();
                }
                connection.Close();
                reader.Close();

            }
            catch (Exception ex)
            {
                Console.WriteLine("ERROR " + ex.Message);
            }

        }

        static void searchContactsEndtWith(string endWith)
        {
            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Contacts where FirstName like  '%' + @endWith + '' ";

            SqlCommand com = new SqlCommand(query, connection);
            com.Parameters.AddWithValue("@endWith", endWith);

            try
            {
                connection.Open();
                SqlDataReader reader = com.ExecuteReader();

                while (reader.Read())
                {
                    int contactId = (int)reader["ContactID"];
                    string firstNamee = (string)reader["firstName"];
                    string lastName = (string)reader["lastName"];
                    string email = (string)reader["email"];
                    string address = (string)reader["address"];
                    int countryId = (int)reader["CountryId"];

                    Console.WriteLine($"Contat Id : {contactId}");
                    Console.WriteLine($"firstName : {firstNamee}");
                    Console.WriteLine($"lastName  : {lastName}");
                    Console.WriteLine($"email     : {email}");
                    Console.WriteLine($"address   : {address}");
                    Console.WriteLine($"countryId : {countryId}");
                    Console.WriteLine();
                }
                connection.Close();
                reader.Close();

            }
            catch (Exception ex)
            {
                Console.WriteLine("ERROR " + ex.Message);
            }

        }

        static void searchContactsByContains(string contains)
        {
            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select * from Contacts where FirstName like  '%' + @contains + '%' ";

            SqlCommand com = new SqlCommand(query, connection);
            com.Parameters.AddWithValue("@contains", contains);

            try
            {
                connection.Open();
                SqlDataReader reader = com.ExecuteReader();

                while (reader.Read())
                {
                    int contactId = (int)reader["ContactID"];
                    string firstNamee = (string)reader["firstName"];
                    string lastName = (string)reader["lastName"];
                    string email = (string)reader["email"];
                    string address = (string)reader["address"];
                    int countryId = (int)reader["CountryId"];

                    Console.WriteLine($"Contat Id : {contactId}");
                    Console.WriteLine($"firstName : {firstNamee}");
                    Console.WriteLine($"lastName  : {lastName}");
                    Console.WriteLine($"email     : {email}");
                    Console.WriteLine($"address   : {address}");
                    Console.WriteLine($"countryId : {countryId}");
                    Console.WriteLine();
                }
                connection.Close();
                reader.Close();

            }
            catch (Exception ex)
            {
                Console.WriteLine("ERROR " + ex.Message);
            }

        }


        static string getFirstNameById(int ContactID)
        {
            string firstName = " ";

            SqlConnection connection = new SqlConnection(connectionDbInfo);

            string query = " select  FirstName from Contacts where ContactID = @ContactID ";

            SqlCommand com = new SqlCommand(query, connection);

            com.Parameters.AddWithValue("@ContactID", ContactID);


            try
            {
                connection.Open();

                Object result = com.ExecuteScalar();

                if (result != null ) {
                    firstName = result.ToString();
                }

                connection.Close();

                return firstName;
            }

            catch (Exception ex)
            {
                return ex.Message;
            }

        }

        static void Main(string[] args)
        {
            /*            printAllContacts();*/
            // printAllContactsWithFirstName("John");

            //findByFirstNameAndContactId("Jane",2);

            //searchContactsStartWith("J");

            // searchContactsEndtWith("n");

            //searchContactsByContains("ae");

            Console.WriteLine(getFirstNameById(3));
        }
    }
}
