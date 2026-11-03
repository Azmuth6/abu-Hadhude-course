using MyFirstClassLibrary;

namespace TestMyFirstClassLibraryProject
{
    internal class Program
    {
        static void Main(string[] args)
        {
            clsMyMath Me = new clsMyMath();

            Console.WriteLine(Me.Add(5, 3));        // Output: 8
            Console.WriteLine(Me.Subtract(5, 3));   // Output: 2
            Console.WriteLine(Me.Multiply(5, 3));   // Output: 15


        }
    }
}
