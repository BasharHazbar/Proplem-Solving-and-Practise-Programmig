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
        static void Main(string[] args)
        {
            Thermostat Thermostat = new Thermostat();
            Display display = new Display();

            display.Subscribe(Thermostat);

            Thermostat.SetThermostat(20);

            Thermostat.SetThermostat(30);

            Thermostat.SetThermostat(40);

            Thermostat.SetThermostat(100);

            Thermostat.SetThermostat(100);

            Thermostat.SetThermostat(100);

          


            // News Publisher Subscribers

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


            ///Order Product


            Order Order = new Order();


            EmailService EmailService = new EmailService();

            EmailService.Subscribe(Order);

            SMSService SMSService = new SMSService();

            SMSService.Subscribe(Order);

            ShippingService ShippingService = new ShippingService();

            ShippingService.Subscribe(Order);

            Order.Create(2, "Product1", "uweyru83478q");

        }
    }
}
