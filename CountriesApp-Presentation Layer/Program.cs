using System;
using System.Data;
using Business_layer;


namespace CountriesApp_Presentation_Layer
{
    internal class Program
    {

        static void findContry(int id)
        {
            clsCountries country = clsCountries.find(id);

            if (country != null)
            {
                Console.WriteLine(country.CountryName);
                Console.WriteLine(country.Code);
                Console.WriteLine(country.PhoneCode);
            }
            else
            {
                Console.WriteLine($"the record with {id} not found ");
            }
        }

        static void findContryByName(string countryName)
        {
            clsCountries country = clsCountries.findByName(countryName);

            if (country != null)
            {
                Console.WriteLine($"{country.CountryID}, {country.CountryName}");
            }
            else
            {
                Console.WriteLine($"the record with not found ");
            }
        }

        static void addNewCountry()
        {
            clsCountries country = new clsCountries();  

            country.CountryName = "oman";

            if (country.save())
            {
                Console.WriteLine($"the recotd is saved with id: {country.CountryID}");
            }
            else
            {
                Console.WriteLine("the recotd is not saved");
            }
        }

        static void updateContry(int id)
        {
            clsCountries country = clsCountries.find(id);

            if (country != null)
            {
                //country.CountryName = "Oman";
                country.Code = "967";
                country.PhoneCode = "732";

                if (country.save())
                {
                    Console.WriteLine($"the recotd is updated with id: {country.CountryID}");
                }
                else
                {
                    Console.WriteLine("the recotd is not updated");
                }
            }


        }

        static void deleteContry(int id)
        {
            if (clsCountries.isExsit(id))
            {
                if (clsCountries.delete(id))
                {
                    Console.WriteLine("the delete is success");
                }
            }
            else
            {
                Console.WriteLine("Not exsit");
            }

        }

        static void listContries()
        {
            DataTable dataTable = clsCountries.getAllCountries();

            if (dataTable != null)
            {
                foreach (DataRow row in dataTable.Rows)
                {
                    Console.WriteLine($"{row[0]},  {row[1]}");
                    Console.WriteLine();
                }
                Console.ReadKey();
            }
            else
            {
                Console.WriteLine("empty data");
            }
        }

        static void isExsitContries(int id)
        {
            if (clsCountries.isExsit(id))
            {
                Console.WriteLine($"yes the id = {id} is exsit");
            }
            else
            {
                Console.WriteLine($"yes the id = {id} is not exsit");
            }
        }

        static void isExsitContriesByName(string searchName)
        {
            if (clsCountries.isExsitByName(searchName))
            {
                Console.WriteLine($"yes it is exsit");
            }
            else
            {
                Console.WriteLine($"yes it is not exsit");
            }
        }
        static void Main(string[] args)
        {

            //listContries();

            //findContry(3);

            //addNewCountry();    

            //updateContry(7);


            //deleteContry(3);

            findContryByName("yemen");

            //isExsitContriesByName("yemen");

            updateContry(6);

        }
    }
}
