using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nullable_Data_Type
{
    internal class Program
    {
        static void Procedure1(string Name, Nullable<int> Age)
        {
            Console.WriteLine("The Name is:- " + Name);
            Console.WriteLine();

            if (Age.HasValue)
            {
                Console.WriteLine("The Age is:- " + Age);
                Console.WriteLine();
            }
            else
            {
                Console.WriteLine("the Age is Null");
                Console.WriteLine();
            }
        }

        static void Procedure2(string Name, int? Age)
        {
            Console.WriteLine("The Name is:- " + Name);
            Console.WriteLine();
            if (Age.HasValue)
            {
                Console.WriteLine("The Age is:- " + Age);
                Console.WriteLine();
            }
            else
            {
                Console.WriteLine("the Age is Null");
                Console.WriteLine();
            }
        }

        static void Main(string[] args)
        {
           
            int? Number = null;

            if (Number.HasValue)
            {
                Console.WriteLine($" this is the number {Number}");
            }
            else
            {
                Console.WriteLine("it is null");
            }

            int Result = Number ?? 0;

            Console.WriteLine("the Result == " + Result);

            string Result2 =  Number?.ToString();

            Console.WriteLine("the Result2 == " + (Result2 ?? "null"));

            ///////////////////////////////////////////
            ///

            Procedure1("Ali", null);

            Procedure1("Mohammed", 23);

            Procedure2("Bashar",25);

            Procedure2("Saleh", null);
        }
    }
}
