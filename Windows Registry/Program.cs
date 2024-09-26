
using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Windows_Registry
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // Writting to Registry

            // string KeyPath = @"HKEY_LOCAL_MACHINE\SOFTWARE\YourNameSoftware";


            string KeyPath = @"HKEY_CURRENT_USER\SOFTWARE\YourNameSoftware";

            string ValueName = "YourValueName";
            string ValueData = "YourValueData";

/*            try
            {
                Registry.SetValue(KeyPath, ValueName, ValueData, RegistryValueKind.String);

                Console.WriteLine($"Value {ValueName} Successfly Written to Database");
            }
            catch (Exception ex)
            {
                Console.WriteLine(@"An Erorr Accured: " + ex.Message);
            }*/



            try
            {
                string Value = Registry.GetValue(KeyPath, ValueName, null) as string;

                if (Value != null) 
                {
                    Console.WriteLine($"The Value is: " + Value);
                }
                else
                {
                    Console.WriteLine($"Value {ValueName} not found in the Registry.");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine(@"An Erorr Accured: " + ex.Message);
            }



        }
    }
}
