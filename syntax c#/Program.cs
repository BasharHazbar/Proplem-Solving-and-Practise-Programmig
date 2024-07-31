
//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

using System;


namespace Main
{
    internal class Program
    {

        static void Main(string[] args)
        {

            try
            {
                int[] myNumbers = { 1, 2, 3 };
                Console.WriteLine(myNumbers[1111]);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);

            }

            Random rnd = new Random();

            for (int j = 0; j < 29; j++)
            {
                Console.WriteLine(rnd.Next(50,100)); // returns random integers >= 10 and < 20
            }

            Console.ReadLine();

        }
    }
}
