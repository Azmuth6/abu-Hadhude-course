using System;

namespace ConsoleApp6
{
    internal class Program
    {
        static void PrintName(string name)
        {
            Console.WriteLine("Hello " + name);
        }
        static void PrintMyInfo(string Name, byte Age, string Address = "No Address")
        {
            Console.WriteLine("Name= {0} , Age= {1}, Address= {2}", Name, Age, Address);
        }
        static string GetMyName()
        {
            return "Mohammed-AbuHadhoud";

        }

        static void PrintInfo(string name, int age)
        {
            Console.WriteLine("Name: " + name);
            Console.WriteLine("Age: " + age);
        }


        static int Sum(int Num1, int Num2)

        {
            return Num1 + Num2;
        }

        static int Sum(int Num1, int Num2, int Num3)

        {
            return Num1 + Num2 + Num3;
        }
        static int Sum(int Num1, int Num2, int Num3, int Num4)

        {
            return Num1 + Num2 + Num3 + Num4;
        }



        static void Main(string[] args)
        {

            //PrintInfo("Salah", 20);

            //PrintInfo(age: 20, name: "Salah");



            //Console.WriteLine(Sum(10, 20));
            //Console.WriteLine(Sum(10, 20, 30));
            //Console.WriteLine(Sum(10, 20, 30, 40));

            /*
              
              
            try
            {
                int x = 10;
                int y = 0;
                int result = x / y;   // هنا هيحصل خطأ (division by zero)
                Console.WriteLine(result);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error Happened: " + ex.Message);
            }


            */


            Random rnd = new Random();

            for (int j = 0; j < 4; j++)
            {
                Console.WriteLine(rnd.Next(10, 20));
            }



            Console.ReadKey();

        }

    }
}
