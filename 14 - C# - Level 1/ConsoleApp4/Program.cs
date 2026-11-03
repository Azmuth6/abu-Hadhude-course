using System;

namespace ConsoleApp4
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*
                          
            Console.WriteLine("enter name : ");

            string name = Console.ReadLine();

            Console.WriteLine("name : " + name);

            Console.WriteLine("enter number : ");

            int number = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("number : " + number);

            */


            /*
            int a = 6;
            int b = 4;

            a &= b;
            Console.WriteLine(a);

            a |= b;
            Console.WriteLine(a);
            
            a ^= b;
            Console.WriteLine(a);
            
             */

            Console.WriteLine(4 & 6);

            Console.WriteLine(6 | 4);

            Console.WriteLine(6 ^ 4);

            Console.WriteLine(~4);

            Console.WriteLine(8 >> 2);

            Console.WriteLine(8 << 1);



            Console.ReadKey(); 

        }
    }
}
