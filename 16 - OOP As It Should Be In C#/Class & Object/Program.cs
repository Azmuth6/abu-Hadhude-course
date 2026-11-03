namespace Class___Object
{
    class clsPerson
    {

        public string FirstName;
        public string LastName;

        public string FullName()
        {
            return FirstName + ' ' + LastName;
        }

    }

    class clsA
    {
        public int x1 = 10;
        private int x2 = 20;
        protected int x3 = 30;

        public int fun1()
        {
            return 100;
        }

        private int fun2()
        {
            return 200;
        }

        protected int fun3()
        {
            return 300;
        }
    }

    class clsB : clsA
    {
        public int fun4()
        {
            //x1 is public and x3 is protected in the base class so you can access them.
            //You cannot access any private members of the base class.
            return x1 + x3;
        }

    }

    class clsA2
    {
        public int x1;
        //x2 is shared for all object because it's on the class level
        public static int x2;


        public int Method1()
        {
            //not static methods can always access the static members
            return x1 + x2;
        }

        public static int Method2()
        {
            //static methods cannot access non-static memebers because there is no object
            //static methods are called at the class level.
            //return clsA.x1 + x2;
            return x2;
        }
    }




    internal class Program
    {
        //static void Main(string[] args)
        //{
        //    //Create object from class
        //    clsPerson Person1 = new clsPerson();


        //    Console.WriteLine("Accessing Object 1 (Person1):");
        //    Person1.FirstName = "Mohammed";
        //    Person1.LastName = "Abu-Hadhoud";
        //    Console.WriteLine(Person1.FullName());


        //    //Create another object from class
        //    clsPerson Person2 = new clsPerson();
        //    Console.WriteLine("\nAccessing Object 2 (Person2):");
        //    Person2.FirstName = "Ali";
        //    Person2.LastName = "Maher";
        //    Console.WriteLine(Person2.FullName());

        //    Console.ReadKey();

        //}


        //static void Main(string[] args)
        //{
        //    //Create object from class
        //    clsA A = new clsA();

        //    //all public members are accessable and internal 
        //    Console.WriteLine("All public members are accessable");
        //    Console.WriteLine("x1={0}", A.x1);
        //    Console.WriteLine("result of fun1={0}", A.fun1());

        //    //you cannot access private members in the folling line.
        //    //Console.WriteLine("x2={0}", A.x2);

        //    //you cannot access protected members in the folling line.
        //    // Console.WriteLine("x3={0}", A.x3);

        //    //you cannot access private members in the folling line.
        //    // Console.WriteLine("result of fun2={0}", A.fun2());

        //    //you cannot access protected members in the folling line.
        //    // Console.WriteLine("result of fun3={0}", A.fun3());

        //    clsB B = new clsB();
        //    Console.WriteLine("\nObjects from class B expose all public members from the base class");
        //    Console.WriteLine("x1={0}", B.x1);
        //    Console.WriteLine("result of fun1={0}", B.fun1());

        //    //you cannot access private members in the folling line.
        //    //Console.WriteLine("x2={0}", B.x2);
        //    // Console.WriteLine("result of fun1={0}", B.fun2());

        //    //you cannot access protected members in the folling line.
        //    // Console.WriteLine("x3={0}", B.x3);
        //    //Console.WriteLine("result of fun3={0}", B.fun3());

        //    Console.ReadKey();
        //}




        static void Main(string[] args)
        {
            //Create an object of Employee class.
            clsA2 objA1 = new clsA2();
            clsA2 objA2 = new clsA2();


            objA1.x1 = 7;
            objA2.x1 = 10;
            //x2 is shared for all object because it's on the class level, you can access it 
            //using the class name.
            clsA2.x2 = 100;


            Console.WriteLine("objA1.x1:={0}", objA1.x1);
            Console.WriteLine("objA2.x1:={0}", objA2.x1);
            Console.WriteLine("objA1.method1 results:={0}", objA1.Method1());
            Console.WriteLine("objA2.method1 results:={0}", objA2.Method1());


            //Method 2 cannot be accessed through object, only through the class itself.
            //  Console.WriteLine(objA1.Method2());
            Console.WriteLine("static method2 results:={0}", clsA2.Method2());

            Console.WriteLine("static x2:={0}", clsA2.x2);
            Console.ReadLine();
        }


    }
}