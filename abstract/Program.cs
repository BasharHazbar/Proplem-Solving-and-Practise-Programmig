using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public abstract class  clsPerson
{
    public int Id { get; set; }
    public string Name { get; set; }
    public int Age { get; set; }

    public abstract void sayHallo();

}

public class clsUser : clsPerson
{
    public bool isAdmin { get; set; } = false;


    public string isAdminStr { get; set; }
    public override void sayHallo()
    {
        Console.WriteLine($"hi bro {this.isAdminStr}");
    }

} 
namespace @abstract
{

    internal class Program
    {
        static void Main(string[] args)
        {
            clsUser user = new clsUser();

            user.Id = 1;
            user.Name= "Test";
            user.Age = 30;
            user.isAdmin = false;
            user.isAdminStr = user.isAdmin ? "ADMIN" : "USER";

            user.sayHallo();
        }
    }
}
