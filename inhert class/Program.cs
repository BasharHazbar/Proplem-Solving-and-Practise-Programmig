using System;

public class clsPerson
{

 /*   public clsPerson(int id, string name, int age)
    {
        this.id = id;
        this.name = name;
        this.age = age;
    }*/
    public int id
    {
        get;  set;
    }
    public string name
    {
        get; set;
    }
    public int age
    {
        get; set;
    }

    public virtual void print()
    {
        Console.WriteLine("person");
    }
}

public class clsEmployee : clsPerson
{


/*    public clsEmployee(int id, string name, int age, float salary, string department) : base (id, name, age)

    {
        this.salary = salary;
        this.department = department;

    }*/
    public float salary
    {
        get; set;
    }
    public string department
    {
        get; set;
    }

    public override void print()
    {
        Console.WriteLine("employee");
    }
}

namespace inhert_class
{
    internal class Program
    {
        static void Main(string[] args)
        {
            clsEmployee eEmployee = new clsEmployee();

            eEmployee.print();
        }
    }
}
