using System;

namespace Control_Flow
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*

            int x = 10; int y = 20;

            //if then statement
            if (x == 10 && y <= 20)
            {
                Console.WriteLine("yes x = 10 and y<=20");
            }



            //if then else statement
            if (x == 11)
            {
                Console.WriteLine("yes x = 11 ");
            }
            else
            {
                Console.WriteLine("yes x != 11 ");
            }


            //if else if statement
            int number = 12;

            if (number < 5)
            {
                Console.WriteLine("{0} is less than 5", number);
            }
            else if (number > 5)
            {
                Console.WriteLine("{0} is greater than 5", number);
            }
            else
            {
                Console.WriteLine("{0} is equal to 5");
            }

            */


            /*
            char ch;
            Console.WriteLine("Enter a letter?");
            ch = Convert.ToChar(Console.ReadLine());

            switch (Char.ToLower(ch))
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':

                    Console.WriteLine("Vowel");
                    break;

                default:
                    Console.WriteLine("Not a vowel");
                    break;
            }

            */




            /*
            char op;
            double first, second, result;

            Console.Write("Enter first number: ");
            first = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter second number: ");
            second = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter operator (+, -, *, /): ");
            op = (char)Console.Read();

            switch (op)
            {
                case '+':
                    result = first + second;
                    Console.WriteLine("{0} + {1} = {2}.", first, second, result);
                    break;

                case '-':
                    result = first - second;
                    Console.WriteLine("{0} - {1} = {2}.", first, second, result);
                    break;

                case '*':
                    result = first * second;
                    Console.WriteLine("{0} * {1} = {2}.", first, second, result);
                    break;

                case '/':
                    result = first / second;
                    Console.WriteLine("{0} / {1} = {2}.", first, second, result);
                    break;

                default:
                    Console.WriteLine("Invalid Operator");
                    break;

            }


            */




            /*
              
             
            Console.WriteLine("\nForward Loop:");
            //forward loop
            for (int i = 1; i <= 10; i++)

            {

                Console.WriteLine(i);

            }

            Console.WriteLine("\nBackword Loop:");
            //backword loop
            for (int i = 10; i >= 1; i--)

            {

                Console.WriteLine(i);

            }


            Console.WriteLine("\nNested Loops:");
            //forward loop
            for (int i = 1; i <= 10; i++)

            {

                for (int j = 0; j < 10; j++)

                {

                    Console.WriteLine("i={0} and j={1}", i, j);

                }
                Console.WriteLine("------------------------------------------------  ");
            }
            
            */


            /*
             
            int i = 1;
            while (i <= 5)
            {
                Console.WriteLine("C# while Loop: Iteration {0}", i);
                i++;
            }

            */



            /*

            int i = 1;
            do
            {
                Console.WriteLine("C# while Loop: Iteration {0}", i);
                i++;

            } while (i <= 5);


            */


            /*
            int i = 1;
            do
            {

                Console.WriteLine("C# while Loop: Iteration {0}", i);

                if (i == 3)
                    break;

                i++;

            } while (i <= 5);

            */



            /*
            for (int i = 1; i <= 5; ++i)
            {

                if (i == 3)
                {
                    continue;
                }

                Console.WriteLine(i);
            }
            */


            /*

            //  //int[] Number = new int[3];

            int[] numbers = { 1, 2, 3 };

            //access first element
            Console.WriteLine("Element in first index : " + numbers[0]);

            //access second element
            Console.WriteLine("Element in second index : " + numbers[1]);

            //access third element
            Console.WriteLine("Element in third index : " + numbers[2]);


            //through loop
            Console.WriteLine("\nAccess array using loop:\n");
            for (int i = 0; i < numbers.Length; i++)
            {
                Console.WriteLine("Element in index {0} : {1} ", i, numbers[0]);
            }

            */


            /*
             
            //2D Array.

            int[,] Array_1 = { { 1, 2, 3 }, { 3, 4, 5 } };

            int[,] Array_2 = new int[2, 3] { { 1, 2, 3 }, { 3, 4, 5 } };

            */




            char[] gender = { 'm', 'f', 'm', 'm', 'm', 'f', 'f', 'm', 'm', 'f' };
            int male = 0, female = 0;
            foreach (char g in gender)
            {
                if (g == 'm')
                    male++;
                else if (g == 'f')
                    female++;
            }
            Console.WriteLine("Number of male = {0}", male);
            Console.WriteLine("Number of female = {0}", female);





            Console.ReadKey();

        }
    }
}
