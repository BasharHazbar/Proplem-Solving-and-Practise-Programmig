using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reflection_in_C_
{
    internal class Program
    {
        static void Main(string[] args)
        {

            Type type = typeof(string);

            Console.WriteLine("Type Information"); 
            Console.WriteLine("Full Name: " + type.FullName);
            Console.WriteLine("Name: " + type.Name);
            Console.WriteLine("Is Class: " + type.IsClass);
            Console.WriteLine("");

        }
    }
}
