using System;
using System.Data;
using System.Linq;


namespace DataTable_Example_1__Create_Offline_Data_Table_and_ListData_
{
    internal class Program
    {
        static void Main(string[] args)
        {

            DataTable EmployeesDataTable = new DataTable();
            EmployeesDataTable.Columns.Add("ID", typeof(int));
            EmployeesDataTable.Columns.Add("Name", typeof(string));
            EmployeesDataTable.Columns.Add("Country", typeof(string));
            EmployeesDataTable.Columns.Add("Salary", typeof(Double));
            EmployeesDataTable.Columns.Add("Date", typeof(DateTime));

            // Make ID column the primary key column.
            DataColumn[] PrimaryKeyColumns = new DataColumn[1];
            PrimaryKeyColumns[0] = EmployeesDataTable.Columns["ID"];
            EmployeesDataTable.PrimaryKey = PrimaryKeyColumns;

            //Add rows
            EmployeesDataTable.Rows.Add(1, "Mohammed ", "Jordan", 5000, DateTime.Now);
            EmployeesDataTable.Rows.Add(2, "Ali Maher", "KSA   ", 525.5, DateTime.Now);
            EmployeesDataTable.Rows.Add(3, "Lina Kamal", "Jordan", 730.5, DateTime.Now);
            EmployeesDataTable.Rows.Add(4, "Fadi JAmeel", "Egypt", 800, DateTime.Now);
            EmployeesDataTable.Rows.Add(5, "Omar Mahmoud", "Lebanon", 7000, DateTime.Now);


            int EmployeesCount = 0;
            double TotalSalaries = 0;
            double AverageSalaries = 0;
            double MinSalary = 0;
            double MaxSalary = 0;

            EmployeesCount  = EmployeesDataTable.Rows.Count;
            TotalSalaries   = Convert.ToDouble(EmployeesDataTable.Compute("SUM(Salary)", string.Empty));
            AverageSalaries = Convert.ToDouble(EmployeesDataTable.Compute("AVG(Salary)", string.Empty));
            MinSalary       = Convert.ToDouble(EmployeesDataTable.Compute("Min(Salary)", string.Empty));
            MaxSalary       = Convert.ToDouble(EmployeesDataTable.Compute("Max(Salary)", string.Empty));


            Console.WriteLine("\nEmployees List:\n");

            foreach(DataRow RecordRow in EmployeesDataTable.Rows)
            {
                Console.WriteLine("ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t ",
                RecordRow["ID"] , RecordRow["Name"] , RecordRow["Country"] , RecordRow["Salary"],
                RecordRow["Date"]); 
            }


            Console.WriteLine("\nCount of Employees = " + EmployeesCount);
            Console.WriteLine("Total Employee Salaries = " + TotalSalaries);
            Console.WriteLine("Average Employee Salaries = " + AverageSalaries);
            Console.WriteLine("Minimum Salary = " + MinSalary);
            Console.WriteLine("Maximum Salary = " + MaxSalary);

            Console.WriteLine("\n=====================================================\n");

            int ResultCount = 0;
            DataRow[] ResultRows;
            
            ResultRows = EmployeesDataTable.Select("Country = 'Jordan'");   

            Console.WriteLine("\nEmployees from Jordan:\n");
            foreach(DataRow ResultRow in ResultRows) {
                Console.WriteLine("ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t ",
                ResultRow["ID"] , ResultRow["Name"] , ResultRow["Country"] , ResultRow["Salary"],
                ResultRow["Date"]);
            }

            ResultCount     = EmployeesDataTable.Rows.Count;
            TotalSalaries   = Convert.ToDouble(EmployeesDataTable.Compute("SUM(Salary)", "Country = 'Jordan'"));
            AverageSalaries = Convert.ToDouble(EmployeesDataTable.Compute("AVG(Salary)", "Country = 'Jordan'"));
            MinSalary       = Convert.ToDouble(EmployeesDataTable.Compute("Min(Salary)", "Country = 'Jordan'"));
            MaxSalary       = Convert.ToDouble(EmployeesDataTable.Compute("Max(Salary)", "Country = 'Jordan'"));



            Console.WriteLine("\nCount of Employees = " + EmployeesCount);
            Console.WriteLine("Total Employee Salaries = " + TotalSalaries);
            Console.WriteLine("Average Employee Salaries = " + AverageSalaries);
            Console.WriteLine("Minimum Salary = " + MinSalary);
            Console.WriteLine("Maximum Salary = " + MaxSalary);

            Console.WriteLine("\n=====================================================\n");

            ResultRows = EmployeesDataTable.Select("Country = 'Jordan' OR Country = 'Egypt'");

            Console.WriteLine("\nEmployees from Jordan OR Egypt:\n");
            foreach (DataRow ResultRow in ResultRows)
            {
                Console.WriteLine("ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t ",
                ResultRow["ID"], ResultRow["Name"], ResultRow["Country"], ResultRow["Salary"],
                ResultRow["Date"]);
            }

            ResultCount = EmployeesDataTable.Rows.Count;
            TotalSalaries   = Convert.ToDouble(EmployeesDataTable.Compute("SUM(Salary)", "Country = 'Jordan' OR Country = 'Egypt'"));
            AverageSalaries = Convert.ToDouble(EmployeesDataTable.Compute("AVG(Salary)", "Country = 'Jordan' OR Country = 'Egypt'"));
            MinSalary       = Convert.ToDouble(EmployeesDataTable.Compute("Min(Salary)", "Country = 'Jordan' OR Country = 'Egypt'"));
            MaxSalary       = Convert.ToDouble(EmployeesDataTable.Compute("Max(Salary)", "Country = 'Jordan' OR Country = 'Egypt'"));



            Console.WriteLine("\nCount of Employees = " + EmployeesCount);
            Console.WriteLine("Total Employee Salaries = " + TotalSalaries);
            Console.WriteLine("Average Employee Salaries = " + AverageSalaries);
            Console.WriteLine("Minimum Salary = " + MinSalary);
            Console.WriteLine("Maximum Salary = " + MaxSalary);

            Console.WriteLine("\n=====================================================\n");


            ResultRows = EmployeesDataTable.Select("ID = 1");

            Console.WriteLine("\nEmployees ID = 1:\n");
            foreach (DataRow ResultRow in ResultRows)
            {
                Console.WriteLine("ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t ",
                ResultRow["ID"], ResultRow["Name"], ResultRow["Country"], ResultRow["Salary"],
                ResultRow["Date"]);
            }

            ResultCount = EmployeesDataTable.Rows.Count;
            TotalSalaries   = Convert.ToDouble(EmployeesDataTable.Compute("SUM(Salary)", "ID = 1"));
            AverageSalaries = Convert.ToDouble(EmployeesDataTable.Compute("AVG(Salary)", "ID = 1"));
            MinSalary       = Convert.ToDouble(EmployeesDataTable.Compute("Min(Salary)", "ID = 1"));
            MaxSalary       = Convert.ToDouble(EmployeesDataTable.Compute("Max(Salary)", "ID = 1"));



            Console.WriteLine("\nCount of Employees = " + EmployeesCount);
            Console.WriteLine("Total Employee Salaries = " + TotalSalaries);
            Console.WriteLine("Average Employee Salaries = " + AverageSalaries);
            Console.WriteLine("Minimum Salary = " + MinSalary);
            Console.WriteLine("Maximum Salary = " + MaxSalary);

            Console.WriteLine("\n=====================================================\n");

            EmployeesDataTable.DefaultView.Sort = "Name ASC";
            EmployeesDataTable = EmployeesDataTable.DefaultView.ToTable();

            Console.WriteLine("\n\nEmployees List Sorted By ID Desc: \n");

            foreach (DataRow ResultRow in EmployeesDataTable.Rows)
            {
                Console.WriteLine("ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t ",
                ResultRow["ID"], ResultRow["Name"], ResultRow["Country"], ResultRow["Salary"],
                ResultRow["Date"]);
            }

            Console.WriteLine("\n=====================================================\n");


            ////Delete Employee with ID=4
            //Console.WriteLine("\n\nEmployees List After Deleting ID = 4 :\n");

            ////First You filter for Employee ID=4
            //DataRow[] Restults = EmployeesDataTable.Select("ID=4");

            //foreach (var RecordRow in Restults)
            //{
            //    RecordRow.Delete(); 
            //}

            //EmployeesDataTable.AcceptChanges(); //Commit Changes to DataTable

            //foreach (DataRow ResultRow in EmployeesDataTable.Rows)
            //{
            //    Console.WriteLine("ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t ",
            //    ResultRow["ID"], ResultRow["Name"], ResultRow["Country"], ResultRow["Salary"],
            //    ResultRow["Date"]);
            //}

            Console.WriteLine("\n=====================================================\n");



            //Delete Employee with ID=4
            Console.WriteLine("\n\nEmployees List After Deleting ID = 4 :\n");

            //First You filter for Employee ID=4
            DataRow[] Restults = EmployeesDataTable.Select("ID=4");

            foreach (var RecordRow in Restults)
            {
                RecordRow["Name"] = "Maha Ahmed" ;
                RecordRow["Salary"] = "900";
            }

            EmployeesDataTable.AcceptChanges(); //Commit Changes to DataTable

            foreach (DataRow ResultRow in EmployeesDataTable.Rows)
            {
                Console.WriteLine("ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t ",
                ResultRow["ID"], ResultRow["Name"], ResultRow["Country"], ResultRow["Salary"],
                ResultRow["Date"]);
            }

            Console.WriteLine("\n=====================================================\n");

            Console.WriteLine("\nEmployees List After Clearing All Data :\n");
            //Clear all Data
            EmployeesDataTable.Clear();

            EmployeesDataTable.AcceptChanges(); //Commit Changes to DataTable

            foreach (DataRow ResultRow in EmployeesDataTable.Rows)
            {
                Console.WriteLine("ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t ",
                ResultRow["ID"], ResultRow["Name"], ResultRow["Country"], ResultRow["Salary"],
                ResultRow["Date"]);
            }

            Console.WriteLine("\n=====================================================\n");


            DataTable EmployeesDataTable2 = new DataTable();

            DataColumn dtColumn;

            dtColumn = new DataColumn();
            dtColumn.DataType = typeof(int);
            dtColumn.ColumnName = "ID";
            dtColumn.AutoIncrement = true;
            dtColumn.AutoIncrementSeed = 100;
            dtColumn.AutoIncrementStep = 1;

            dtColumn.Caption = "Employee ID";
            dtColumn.ReadOnly = true;
            dtColumn.Unique = true;
            EmployeesDataTable2.Columns.Add(dtColumn);


            dtColumn = new DataColumn();
            dtColumn.DataType = typeof(string);
            dtColumn.ColumnName = "Name";
            dtColumn.AutoIncrement = false;
            dtColumn.Caption = "Name";
            dtColumn.ReadOnly = false;
            dtColumn.Unique = false;
            EmployeesDataTable2.Columns.Add(dtColumn);


            dtColumn = new DataColumn();
            dtColumn.DataType = typeof(string);
            dtColumn.ColumnName = "Country";
            dtColumn.AutoIncrement = false;
            dtColumn.Caption = "Country";
            dtColumn.ReadOnly = false;
            dtColumn.Unique = false;
            EmployeesDataTable2.Columns.Add(dtColumn);


            dtColumn = new DataColumn();
            dtColumn.DataType = typeof(Double);
            dtColumn.ColumnName = "Salary";
            dtColumn.AutoIncrement = false;
            dtColumn.Caption = "Salary";
            dtColumn.ReadOnly = false;
            dtColumn.Unique = false;
            EmployeesDataTable2.Columns.Add(dtColumn);



            dtColumn = new DataColumn();
            dtColumn.DataType = typeof(DateTime);
            dtColumn.ColumnName = "Date";
            dtColumn.AutoIncrement = false;
            dtColumn.Caption = "Date";
            dtColumn.ReadOnly = false;
            dtColumn.Unique = false;
            EmployeesDataTable2.Columns.Add(dtColumn);



            // Make ID column the primary key column.
            DataColumn[] PrimaryKeyColumns1 = new DataColumn[1];
            PrimaryKeyColumns1[0] = EmployeesDataTable2.Columns["ID"];
            EmployeesDataTable2.PrimaryKey = PrimaryKeyColumns1;

            //Add rows
            EmployeesDataTable2.Rows.Add(null, "Mohammed ", "Jordan", 5000, DateTime.Now);
            EmployeesDataTable2.Rows.Add(null, "Ali Maher", "KSA   ", 525.5, DateTime.Now);
            EmployeesDataTable2.Rows.Add(null, "Lina Kamal", "Jordan", 730.5, DateTime.Now);
            EmployeesDataTable2.Rows.Add(null, "Fadi JAmeel", "Egypt", 800, DateTime.Now);
            EmployeesDataTable2.Rows.Add(null, "Omar Mahmoud", "Lebanon", 7000, DateTime.Now);

            foreach (DataRow RecordRow in EmployeesDataTable2.Rows)
            {
                Console.WriteLine("ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t ",
                RecordRow["ID"], RecordRow["Name"], RecordRow["Country"], RecordRow["Salary"],
                RecordRow["Date"]);
            }
        }
    }
}
