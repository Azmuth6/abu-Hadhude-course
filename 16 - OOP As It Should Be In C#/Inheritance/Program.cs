using System;

public class clsPerson
{
    
    //properties
    public int ID { get; set; }
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public string Title { get; set; }

    public clsPerson(int ID, string FirstName, string LastName, string Title)
    {
        this.ID = ID;
        this.FirstName = FirstName;
        this.LastName = LastName;
        this.Title = Title;
    }


    //read only property
    public string FullName
    {
        //Get is use for Reading field
        get
        {
            return FirstName + ' ' + LastName;
        }
    }
}


public class clsEmployee : clsPerson
{


    public float Salary { get; set; }
    public string DepartmentName { get; set; }

    public clsEmployee(int ID, string FirstName, string LastName, string Title,
                       float Salary, string DepartmentName)
        : base(ID, FirstName, LastName, Title)
    {
        this.Salary = Salary;
        this.DepartmentName = DepartmentName;
    }
    public void IncreaseSalaryBy(float Amount)
    {
        Salary += Amount;
    }


}


internal class Program
{
    static void Main(string[] args)
    {

        Console.ReadKey();
    }
}

