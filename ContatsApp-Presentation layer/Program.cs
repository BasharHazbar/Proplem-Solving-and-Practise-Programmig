using System;
using System.Data;
using ContactsBusinessLayer;

namespace ContatsApp_Presentation_layer
{
    internal class Program
    {
       
        static void findContact(int id)
        {
            clsContacts contact = clsContacts.find(id);

            if (contact != null)
            {
                Console.WriteLine(contact.firstName);
                Console.WriteLine(contact.lastName);
                Console.WriteLine(contact.email);
                Console.WriteLine(contact.phone);
                Console.WriteLine(contact.address);
                Console.WriteLine(contact.dateOfBirth);
                Console.WriteLine(contact.countryID);
                Console.WriteLine(contact.imagePath);

            }
            else
            {
                Console.WriteLine($"the record with {id} not found ");
            }
        }

        static void addNewContent()
        {
            clsContacts contact = new clsContacts();

            contact.firstName = "bashar";
            contact.lastName = "khaled";
            contact.phone = "88938987324";
            contact.email = "sa@gmail.com";
            contact.address = "makkah";
            contact.dateOfBirth = new DateTime(1999,1,3);
            contact.countryID = 3;
            contact.imagePath = "";

            if (contact.save())
            {
                Console.WriteLine($"the recotd is saved with id: {contact.ContactID}");
            }
            else
            {
                Console.WriteLine("the recotd is not saved");
            }
        }

        static void updateContent(int id)
        {
            clsContacts contact = clsContacts.find(id);
            
            if (contact != null)
            {
                contact.firstName = "ali";
                contact.lastName = "saleh";
                contact.phone = "4358734857";
                contact.email = "saleh@gmail.com";
                contact.address = "makkah";
                contact.dateOfBirth = new DateTime(2000, 1, 3);
                contact.countryID = 3;
                contact.imagePath = "https://static.vecteezy.com/vite/assets/photo-masthead-375-b8ae1548.webp";


                if (contact.save())
                {
                    Console.WriteLine($"the recotd is updated with id: {contact.countryID}");
                }
                else
                {
                    Console.WriteLine("the recotd is not updated");
                }
            }


        }

        static void deleteContent(int id)
        {
            if (clsContacts.isExsit(id))
            {
                if (clsContacts.delete(id))
                {
                    Console.WriteLine("the delete is success");
                }
            }
            else
            {
                Console.WriteLine("Not exsit");
            }
           
        }

        static void listContacts()
        {
            DataTable dataTable = clsContacts.getAllContacts();

            if (dataTable != null)
            {
                foreach (DataRow row in dataTable.Rows)
                {
                    Console.WriteLine($"{row[0]},  {row[1]}  {row[2]}");
                    Console.WriteLine();
                }
                Console.ReadKey();
            }
            else
            {
                Console.WriteLine("empty data");
            }
        }

        static void isExsitContent(int id)
        {
            if (clsContacts.isExsit(id))
            {
                Console.WriteLine($"yes the id = {id} is exsit");
            }
            else
            {
                Console.WriteLine($"yes the id = {id} is not exsit");
            }
        }
        static void Main(string[] args)
        {
            findContact(4);
 //           addNewContent();
   //         updateContent(9);
            deleteContent(10);

            listContacts();

            isExsitContent(100);


        }
    }
}
