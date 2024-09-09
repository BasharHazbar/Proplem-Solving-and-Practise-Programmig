using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Events_Delegation_By_Console_App
{
    public class Program
    {


        /// ======================Multicast Delegate=========================== ///
      
        public delegate void MyCalc(int Number1, int Number2);

        public static MyCalc _Calc;

        public static void Sum(int Number1, int Number2)
        {
            Console.WriteLine("Result Of Sum : " + (Number1 + Number2));
        }

        public static void Substraction(int Number1, int Number2)
        {
            Console.WriteLine("Result Of Substraction : " + (Number1 - Number2));
        }


        /// ======================Func Delegate=========================== ///


        /// Defult Way
        /// 

        delegate int Squere(int Number);

        static int SquereMethod(int Number)
        {
            return Number * Number;
        }


        /// With Func

        static Func<int, int> SquareFunc = SquereMethod2;

        static int SquereMethod2(int Number)
        {
            return Number * Number;
        }



        /// With Func 
        
        static Func<int, int> SquareFuncByLembda = Number => Number * Number;

        
        /// ======================Action Delegate=========================== ///
        /// 

        static Action NoneArg = PrintNoneArg;

        static Action<int> OneArg = PrintOneArg;

        static Action<int,string> TwoArg = PrintTwoArg;

        static void PrintNoneArg()
        {
            Console.WriteLine("NoneArg");
        }
        static void PrintOneArg(int Number1)
        {
            Console.WriteLine("PrintOneArg : " + Number1);
        }

        static void PrintTwoArg(int Number1, string Text)
        {
            Console.WriteLine("PrintTwoArg : " + Number1 + " " + Text);
        }

        static void PrintNumber(int Number1)
        {
            Console.WriteLine("Result Of Substraction : " + Number1);
        }


        /// ======================Predicate Delegate=========================== ///
        ///

        static Predicate<int> IsEvenPredicate = IsEven;

        static bool IsEven(int x)
        {
            return x % 2 == 0;
        }

        
        static void Main(string[] args)
        {
            /*         
             ///========================= TemperatureChanged ==================================///
                      
                       Thermostat Thermostat = new Thermostat();
                        Display display = new Display();

                        display.Subscribe(Thermostat);

                        Thermostat.SetThermostat(20);

                        Thermostat.SetThermostat(30);

                        Thermostat.SetThermostat(40);

                        Thermostat.SetThermostat(100);

                        Thermostat.SetThermostat(100);

                        Thermostat.SetThermostat(100);



        ///=========================News Publisher Subscribers==================================///
                        

                        NewsPublisher publisher = new NewsPublisher();

                        NewsSubscriber subscriber1 = new NewsSubscriber("Ali");

                        subscriber1.Subscribe(publisher);

                        NewsSubscriber subscriber2 = new NewsSubscriber("Saleh");

                        subscriber2.Subscribe(publisher);


                        NewsSubscriber subscriber3 = new NewsSubscriber("Mohammed");

                        subscriber3.Subscribe(publisher);

                        string Title = "A Bonsai Tree: An Autobiography";

                        string Artical = @"In October 1947, author Narendra Luther's family of six packed 
                                        quickly for a special train to Amritsar,";

                        publisher.PublishNews(Title, Artical);


         ///=========================Order Product==================================///


                        Order Order = new Order();


                        EmailService EmailService = new EmailService();

                        EmailService.Subscribe(Order);

                        SMSService SMSService = new SMSService();

                        SMSService.Subscribe(Order);

                        ShippingService ShippingService = new ShippingService();

                        ShippingService.Subscribe(Order);

                        Order.Create(2, "Product1", "uweyru83478q");*/


            /// ======================Logger=========================== ///

            /*
                        Logger LoggerToScreen = new Logger(LoggerImpl.LogToScreen);

                        LoggerToScreen.Log("You Logged to the Screen Now");

                        Logger LoggerToFile = new Logger(LoggerImpl.LogToFile);

                        LoggerToFile.Log("You Logged to the File Now");*/


            /// ======================Multicast Delegate=========================== ///
            /// 

            /*
                        _Calc = Sum;
                        _Calc += Substraction;


                        _Calc?.Invoke(4,2);

                        _Calc(12,23);

                        _Calc -= Substraction;

                        _Calc(13,14);
            */

            /// ======================Func Delegate=========================== ///


            /// Defult Way
            ///
            /*
                        Squere Squere = new Squere(SquereMethod);

                        Console.WriteLine("Defult Way Squere is : " + Squere(50));


                        /// With Func with 

                        Console.WriteLine("Func Way Squere is : " + SquareFunc(50));*/


            /// ======================Action Delegate=========================== ///
            /// 

            /*
                        NoneArg();

                        OneArg(50);

                        TwoArg(50,"Hallo Prince");
            */


            /// ======================Predicate Delegate=========================== ///
            ///

            //  Console.WriteLine("Is Even Number ?  " + IsEvenPredicate(4)); 


            /// ======================Predicate Delegate=========================== ///

            Console.WriteLine("Square Func By Lembda ?  " + SquareFuncByLembda(4));


        }
    }
}
