namespace Constructor_and_Destructor
{
    class clsPerson
    {
        public int ID { get; set; }
        public string Name { get; set; }

        public int Age { get; set; }

        public  clsPerson()
        {
            ID = -1;
            Name = "Unknown";
            Age = 0;
        }

        public clsPerson (int ID , string Name, int Age)
        {
            this.ID = ID;
            this.Name = Name;
            this.Age = Age;
        }

        ~clsPerson()
        {
            Console.WriteLine("Destructor called for " + Name);
        }
    }

    static class Settings
    {
        public static int DayNumber
        {
            get
            {
                return DateTime.Today.Day;
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
        //this is a static constructor will be called once during the program
        static Settings()
        {
            ProjectPath = @"C:\MyProjects\";
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {

         // You cannot create an object here because class is static
        // Settings Obj1 = new Settings();

        //
        // Read the static properties.
        //
        Console.WriteLine(Settings.DayNumber);
        Console.WriteLine(Settings.DayName);
        //
        // Change the value of the static bool property.
        //
        
        Console.WriteLine(Settings.ProjectPath);

        }
    }
}
