namespace Properties
{
    class clsEmployee
    {
        private string _Name;
        private int _ID;
        private int _Salary = 50000;

        public int Age { get; set; }


        public int ID
        {
            get { return _ID; }
            set { _ID = value; }
        }

        public string Name
        {
            get { return _Name; }
            set { _Name = value; }
        }

        public int Salary
        {
            get { return _Salary; }
        }

    }


    static class settings
    {
        public static int DayNumber
        {
            get
            {
                return DateTime.Now.DayOfYear;
            }
        }

        public static string DayName
        {
            get
            {
                return DateTime.Today.DayOfWeek.ToString();
            }
        }

        public static string ProjectPath
        {
            get;
            set;
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            clsEmployee emp = new clsEmployee();

            emp.ID = 101;
            emp.Name = "John Doe";

            Console.WriteLine("Employee Id:={0} ,Name:={1} ", emp.ID, emp.Name);

            
        }
    }
}
