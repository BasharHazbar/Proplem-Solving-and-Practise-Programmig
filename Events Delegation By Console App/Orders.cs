using System;

namespace Events_Delegation_By_Console_App
{
    public class OrderEventArgs : EventArgs
    {
        public int OrderID { get; }
        public string ProductName { get; }
        public string ProductCode { get; }

        public OrderEventArgs(int OrderID, string ProductName, string ProductCode)
        {
            this.OrderID = OrderID;
            this.ProductName = ProductName;
            this.ProductCode = ProductCode;
        }

    }

    public class Order
    {
        public EventHandler<OrderEventArgs> OnOrderCreated;

        public void Create(int OrderID, string ProductName, string ProductCode)
        {
            if (OnOrderCreated != null)
            {
                OnOrderCreated(this, new OrderEventArgs(OrderID, ProductName, ProductCode));
            }
        }
    }

    public class EmailService
    {
        public void Subscribe(Order Order)
        {
            Order.OnOrderCreated += HandlNewOrder;
        }

        public void UnSubscribe(Order Order)
        {
            Order.OnOrderCreated -= HandlNewOrder;
        }


        public void HandlNewOrder(object Sender, OrderEventArgs e)
        {
            Console.WriteLine("You have Order the Product with this Information: ");
            Console.WriteLine($"The OrderID {e.OrderID}");
            Console.WriteLine($"The ProductName {e.ProductName}");
            Console.WriteLine($"The ProductCode {e.ProductCode}");
            Console.WriteLine();
        }
    }

    public class SMSService
    {
        public void Subscribe(Order Order)
        {
            Order.OnOrderCreated += HandlNewOrder;
        }

        public void UnSubscribe(Order Order)
        {
            Order.OnOrderCreated -= HandlNewOrder;
        }

        public void HandlNewOrder(object Sender, OrderEventArgs e)
        {
            Console.WriteLine("You Recieved an SMS that you Order the Product with this Information: ");
            Console.WriteLine($"The OrderID {e.OrderID}");
            Console.WriteLine($"The ProductName {e.ProductName}");
            Console.WriteLine($"The ProductCode {e.ProductCode}");
            Console.WriteLine();
        }
    }

    public class ShippingService
    {
        public void Subscribe(Order Order)
        {
            Order.OnOrderCreated += HandlNewOrder;
        }

        public void UnSubscribe(Order Order)
        {
            Order.OnOrderCreated -= HandlNewOrder;
        }

        public void HandlNewOrder(object Sender, OrderEventArgs e)
        {
            Console.WriteLine("We will shipping this order with this Information:- ");
            Console.WriteLine($"The OrderID {e.OrderID}");
            Console.WriteLine($"The ProductName {e.ProductName}");
            Console.WriteLine($"The ProductCode {e.ProductCode}");
            Console.WriteLine();
        }
    }


}
