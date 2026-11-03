public partial class Person
{
    public int Age { get; set; }

    partial void PrintAge();

    public void Birthday()
    {
        Age++;
        PrintAge();
    }
}