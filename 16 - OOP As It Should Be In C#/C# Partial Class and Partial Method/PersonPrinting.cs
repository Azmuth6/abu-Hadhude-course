public partial class Person
{
    partial void PrintAge()
    {
        Console.WriteLine("Current age: {0}", Age);
    }
}