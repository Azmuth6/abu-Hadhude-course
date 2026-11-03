
using System;

namespace ConsoleApp3
{
    internal class Program
    {

        enum enWeekDays
        {
            Monday,     // 0
            Tuesday,    // 1
            Wednesday,  // 2
            Thursday,   // 3
            Friday,     // 4
            Saturday,   // 5
            Sunday      // 6
        }

        //if you set a value , it will auto number everything after it.
        enum enCategories
        {
            Electronics,    // 0
            Food,           // 1
            Automotive = 6, // 6
            Arts,           // 7
            BeautyCare,     // 8
            Fashion         // 9
        }


        //Enum can have any numarical data type byte, sbyte, short, ushort, int, uint, long, or ulong
        //but not string

        enum enCategories2 : byte
        {
            Electronics = 1,
            Food = 5,
            Automotive = 6,
            Arts = 10,
            BeautyCare = 11,
            Fashion = 15
        }

        struct stStudent
        {
            public string FirstName;
            public string LastName;
        }



        static void Main(string[] args)
        {

            ////Byte

            //byte b1 = 255;
            ////  byte b2 = -128;// compile-time error: Constant value '-128' cannot be converted to a 'byte'
            //sbyte sb1 = -128;
            //sbyte sb2 = 127;
            //Console.WriteLine("\nByte:");
            //Console.WriteLine("Min={0} , Max={1}", Byte.MinValue, Byte.MaxValue);


            //Console.WriteLine("\nSByte:");
            //Console.WriteLine("Min={0} , Max={1}", SByte.MinValue, SByte.MaxValue);

            ////Short
            //short s1 = -32768;
            //short s2 = 32767;
            //// short s3 = 35000;//Compile-time error: Constant value '35000' cannot be converted to a 'short'

            //ushort us1 = 65535;
            ////  ushort us2 = -32000; //Compile-time error: Constant value '-32000' cannot be converted to a 'ushort'

            //Console.WriteLine("\nShort:");
            //Console.WriteLine("Min={0} , Max={1}", Int16.MinValue, Int16.MaxValue);

            //Console.WriteLine("\nUShort:");
            //Console.WriteLine("Min={0} , Max={1}", UInt16.MinValue, UInt16.MaxValue);

            ////int
            //int i = -2147483648;
            //int j = 2147483647;
            ////  int k = 4294967295; //Compile-time error: Cannot implicitly convert type 'uint' to 'int'.

            //uint ui1 = 4294967295;
            //// uint ui2 = -1; //Compile-time error: Constant value '-1' cannot be converted to a 'uint'

            //Console.WriteLine("\nInt:");
            //Console.WriteLine("Min={0} , Max={1}", Int32.MinValue, Int32.MaxValue);

            //Console.WriteLine("\nUInt:");
            //Console.WriteLine("Min={0} , Max={1}", UInt32.MinValue, UInt32.MaxValue);

            ////Long
            //long l1 = -9223372036854775808;
            //long l2 = 9223372036854775807;

            //ulong ul1 = 18223372036854775808ul;
            //ulong ul2 = 18223372036854775808UL;

            //Console.WriteLine("\nLong:");
            //Console.WriteLine("Min={0} , Max={1}", Int64.MinValue, Int64.MaxValue);

            //Console.WriteLine("\nULong:");
            //Console.WriteLine("Min={0} , Max={1}", UInt64.MinValue, UInt64.MaxValue);


            ////Float
            //float f1 = 123456.5F;
            //float f2 = 1.123456f;

            //Console.WriteLine("\nFloat:");
            //Console.WriteLine("Min={0} , Max={1}", float.MinValue, float.MaxValue);


            ////double
            //double d1 = 12345678912345.5d;
            //double d2 = 1.123456789123456d;

            //Console.WriteLine("\nDouble:");
            //Console.WriteLine("Min={0} , Max={1}", double.MinValue, double.MaxValue);



            ////Decimal
            ////The decimal type has more precision and a smaller range
            ////than both float and double,
            ////and so it is appropriate for financial and monetary calculations.
            //decimal d3 = 123456789123456789123456789.5m;
            //decimal d4 = 1.1234567891345679123456789123m;

            //Console.WriteLine("\nDecimal:");
            //Console.WriteLine("Min={0} , Max={1}", decimal.MinValue, decimal.MaxValue);


            ////Scientific Notation
            ////Use e or E to indicate the power of 10 
            ////as exponent part of scientific notation with float, double or decimal.

            //double d = 0.12e2;
            //Console.WriteLine(d);  // 12;

            //float f = 123.45e-2f;
            //Console.WriteLine(f);  // 1.2345

            //decimal m = 1.2e6m;
            //Console.WriteLine(m);// 1200000



            ////hex & Binary
            //int hex = 0x2F;
            //int binary = 0b_0010_1111;

            //Console.WriteLine(hex);
            //Console.WriteLine(binary);











            ////get default value using default(type)
            //int i = default(int); // 0
            //float f = default(float);// 0
            //decimal d = default(decimal);// 0
            //bool b = default(bool);// false
            //char c = default(char);// '\0'

            //// C# 7.1 on wards
            ////get default value using default
            //int i2 = default; // 0
            //float f2 = default;// 0
            //decimal d2 = default;// 0
            //bool b2 = default;// false
            //char c2 = default;// '\0'








            //enWeekDays WeekDays;

            //WeekDays = enWeekDays.Friday;

            //Console.WriteLine(WeekDays);








            ////  Nullable<int> can be assigned any value
            ////  from -2147483648 to 2147483647, or a null value.

            //Nullable<int> i = null;
            //Nullable<int> k = 77;

            //Console.WriteLine(i);
            //Console.WriteLine(k);






            /*


            //you dont specify any type here , automatically will be specified
            var student = new { Id = 20, FirstName = "Mohammed", LastName = "Abu-Hadhoud" };

            Console.WriteLine("\nExample1:\n");
            Console.WriteLine(student.Id); //output: 20
            Console.WriteLine(student.FirstName); //output: Mohammed
            Console.WriteLine(student.LastName); //output: Abu-Hadhoud

            //You can print like this:
            Console.WriteLine(student);


            //anonymous types are read-only
            //you cannot change the values of properties as they are read-only.

            // student.Id = 2;//Error: cannot change value
            // student.FirstName = "Ali";//Error: cannot change value


            //An anonymous type's property can include another anonymous type.
            
            var student2 = new
            {
                Id = 20,
                FirstName = "Mohammed",
                LastName = "Abu-Hadhoud",
                Address = new { Id = 1, City = "Amman", Country = "Jordan" }
            };

            Console.WriteLine("\nExample2:\n");
            Console.WriteLine(student2.Id);
            Console.WriteLine(student2.FirstName);
            Console.WriteLine(student2.LastName);

            Console.WriteLine(student2.Address.Id);
            Console.WriteLine(student2.Address.City);
            Console.WriteLine(student2.Address.Country);
            Console.WriteLine(student2.Address);


            */

            /*
            stStudent Student;
            stStudent Student2 = new stStudent();

            


            Student.FirstName = "Mohammed";
            Student.LastName = "Abu-Hadhoud";


            Console.WriteLine(Student.FirstName);
            Console.WriteLine(Student.LastName);


            Student2.FirstName = "Ali";
            Student2.LastName = "Ahmed";


            Console.WriteLine(Student2.FirstName);
            Console.WriteLine(Student2.LastName);

            */



            /*
            dynamic MyDynamicVar = 100;
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            MyDynamicVar = "Hello World!!";
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            MyDynamicVar = true;
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType());

            MyDynamicVar = DateTime.Now;
            Console.WriteLine("Value: {0}, Type: {1}", MyDynamicVar, MyDynamicVar.GetType()); 
            */


            /*

            //assigns default value 01/01/0001 00:00:00
            DateTime dt1 = new DateTime();

            //assigns year, month, day
            DateTime dt2 = new DateTime(2023, 12, 31);

            //assigns year, month, day, hour, min, seconds
            DateTime dt3 = new DateTime(2023, 12, 31, 5, 10, 20);

            //assigns year, month, day, hour, min, seconds, UTC time zone
            DateTime dt4 = new DateTime(2023, 12, 31, 5, 10, 20, DateTimeKind.Utc);

            Console.WriteLine(dt1);
            Console.WriteLine(dt2);
            Console.WriteLine(dt3);
            Console.WriteLine(dt4);



            DateTime dtNow = new DateTime();
            dtNow = DateTime.Now;

            Console.WriteLine(dtNow);
            
             */




            /*
            //number of 100-nanosecond intervals that have elapsed
            //since January 1, 0001, at 00:00:00.000 in the Gregorian calendar. 

            DateTime dt = new DateTime();
            Console.WriteLine(DateTime.MinValue.Ticks);  //min value of ticks
            Console.WriteLine(DateTime.MaxValue.Ticks); // max value of ticks
            */



            /*
            DateTime currentDateTime = DateTime.Now;  //returns current date and time
            DateTime todaysDate = DateTime.Today; // returns today's date
            DateTime currentDateTimeUTC = DateTime.UtcNow;// returns current UTC date and time
            DateTime maxDateTimeValue = DateTime.MaxValue; // returns max value of DateTime
            DateTime minDateTimeValue = DateTime.MinValue; // returns min value of DateTime

            Console.WriteLine("currentDateTime: " + currentDateTime);
            Console.WriteLine("Today: " + todaysDate);
            Console.WriteLine("currentDateTimeUTC: " + currentDateTimeUTC);
            Console.WriteLine("minDateTimeValue: " + minDateTimeValue);
            Console.WriteLine("maxDateTimeValue: " + maxDateTimeValue);

            */



            /*
            DateTime dt = new DateTime(2023, 2, 21);

            // Hours, Minutes, Seconds
            TimeSpan ts = new TimeSpan(49, 25, 34);
            Console.WriteLine(ts);
            Console.WriteLine(ts.Days);
            Console.WriteLine(ts.Hours);
            Console.WriteLine(ts.Minutes);
            Console.WriteLine(ts.Seconds);

            //this will add time span to the date.
            DateTime newDate = dt.Add(ts);

            Console.WriteLine(newDate);

            */


            /*

            DateTime dt1 = new DateTime(2023, 2, 21);
            DateTime dt2 = new DateTime(2023, 2, 25);
            TimeSpan result = dt2.Subtract(dt1);

            Console.WriteLine(result);

            */


            /*

            DateTime dt1 = new DateTime(2015, 12, 20);
            DateTime dt2 = new DateTime(2016, 12, 31, 5, 10, 20);
            TimeSpan time = new TimeSpan(10, 5, 25, 50);

            Console.WriteLine(dt2 + time); // 1/10/2017 10:36:10 AM
            Console.WriteLine(dt2 - dt1); //377.05:10:20
            Console.WriteLine(dt1 == dt2); //False
            Console.WriteLine(dt1 != dt2); //True
            Console.WriteLine(dt1 > dt2); //False
            Console.WriteLine(dt1 < dt2); //True
            Console.WriteLine(dt1 >= dt2); //False
            Console.WriteLine(dt1 <= dt2);//True

            */




            /*
            string str = "6/12/2023";
            DateTime dt;

            bool isValidDate = DateTime.TryParse(str, out dt);

            if (isValidDate)
                Console.WriteLine(dt);
            else
                Console.WriteLine($"{str} is not a valid date string");

            //invalid string date
            string str2 = "6/65/2023";
            DateTime dt2;

            bool isValidDate2 = DateTime.TryParse(str2, out dt2);

            if (isValidDate2)
                Console.WriteLine(dt2);
            else
                Console.WriteLine($"{str2} is not a valid date string");


            */



            /*

            string S1 = "Mohammed Abu-Hadhoud";

            Console.WriteLine(S1.Length);

            //this will take 5 characters staring position 2
            Console.WriteLine(S1.Substring(2, 5));
            Console.WriteLine(S1.ToLower());
            Console.WriteLine(S1.ToUpper());
            Console.WriteLine(S1[2]);
            Console.WriteLine(S1.Insert(3, "KKKK"));
            Console.WriteLine(S1.Replace("m", "*"));
            Console.WriteLine(S1.IndexOf("m"));
            Console.WriteLine(S1.Contains("m"));
            Console.WriteLine(S1.Contains("x"));
            Console.WriteLine(S1.LastIndexOf("m"));

            string S2 = "Ali,Ahmed,Khalid";

            string[] NamesList = S2.Split(',');

            Console.WriteLine(NamesList[0]);
            Console.WriteLine(NamesList[1]);
            Console.WriteLine(NamesList[2]);

            string S3 = "  Abu-Hadhoud  ";
            Console.WriteLine(S3.Trim());
            Console.WriteLine(S3.TrimStart());
            Console.WriteLine(S3.TrimEnd());



            */




            /*

            //  String Interpolation

            string firstName = "Mohammed";
            string lastName = "Abu-Hadhoud";
            string code = "107";

            //You shold use $ to $ to identify an interpolated string 
            string fullName = $"Mr. {firstName} {lastName}, Code: {code}";

            Console.WriteLine(fullName);


            */



            /*
             
             
            int myInt = 17;
            double myDouble = myInt;       // Automatic casting: int to double

            Console.WriteLine(myInt);      // Outputs 17
            Console.WriteLine(myDouble);   // Outputs 17

             
             */


            /*
            
            double myDouble = 17.58;
            int myInt = (int) myDouble;    // Manual casting: double to int

            Console.WriteLine(myDouble);   // Outputs 17.58
            Console.WriteLine(myInt);      // Outputs 17

             */




            /*
             
            int myInt = 20;
            double myDouble = 7.25;
            bool myBool = true;

            Console.WriteLine(Convert.ToString(myInt));    // convert int to string
            Console.WriteLine(Convert.ToDouble(myInt));    // convert int to double
            Console.WriteLine(Convert.ToInt32(myDouble));  // convert double to int
            Console.WriteLine(Convert.ToString(myBool));   // convert bool to string

             
             */






            Console.WriteLine(enWeekDays.Friday); //output: Friday 
            int day = (int)enWeekDays.Friday; // enum to int conversion
            Console.WriteLine(day); //output: 4 

            var wd = (enWeekDays)5; // int to enum conversion
            Console.WriteLine(wd);//output: Saturday 


















            Console.ReadKey();

        }
    }
}