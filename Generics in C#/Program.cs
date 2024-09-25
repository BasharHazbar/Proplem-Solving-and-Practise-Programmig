using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generics_in_C_
{
    public class Program
    {
        public class Utility
        {
            public static T Swap<T>(ref T First, ref T Second)
            {
                T Swapped = First;

                First = Second;

                Second = Swapped;

                return Swapped;
            }
        } 


        public class GenericBox<T>
        {
            private T Content;

            public GenericBox(T Content)
            {
                this.Content = Content;
            }

            public T getContent()
            {
                return this.Content;
            }
        }



        static void Main(string[] args)
        {

            // Usage With Integers

            int Number1= 5; int Number2 = 10;

            Console.WriteLine($"Before Swap:- Number1 = {Number1}  Number2 = {Number2}");

            Utility.Swap<int>(ref Number1, ref Number2);

            Console.WriteLine($"After Swap:- Number1 = {Number1}  Number2 = {Number2}");

            // Usage With string

            string Word1 = "Hallo"; string Word2 = "Word";

            Console.WriteLine($"Before Swap:- Word1 = {Word1}  Word2 = {Word2}");

            Utility.Swap<string>(ref Word1, ref Word2);

            Console.WriteLine($"After Swap:- Word1 = {Word1}  Word2 = {Word2}");



            Console.WriteLine("###############################################################");


            ///// GenericBox
            ///

            /// With Integer
            /// 
            GenericBox<int> GenericBox1 = new GenericBox<int>(530);

            Console.WriteLine("GenericBox1 ===> " + GenericBox1.getContent());


            ////  With String

            GenericBox<string> GenericBox2 = new GenericBox<string>("Hallo Word");

            Console.WriteLine("GenericBox2 ===> " + GenericBox2.getContent());

        }
    }
}
