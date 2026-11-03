using System;


class Program
{
    static void Main()
    {
        ////the code of MyClass is separated in 2 files class1.cs and class2.cs
        //MyClass obj = new MyClass();
        //obj.Method1();
        //obj.Method2();

        //---

        //the code of Person Class is separated in 2 files Person1.cs and PersonPrinting.cs
        Person person1 = new Person();
        person1.Age = 25;
        person1.Birthday(); // Output: "Current age: 26"

        Console.ReadKey();

    }
}
