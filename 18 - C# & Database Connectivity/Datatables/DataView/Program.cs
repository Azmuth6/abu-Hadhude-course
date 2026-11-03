using System.Data;
using System.Linq;

namespace DataView2
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
            EmployeesDataTable.Rows.Add(1, "Mohammed     ", "Jordan", 5000, DateTime.Now);
            EmployeesDataTable.Rows.Add(2, "Ali Maher    ", "KSA   ", 525.5, DateTime.Now);
            EmployeesDataTable.Rows.Add(3, "Lina Kamal   ", "Jordan", 730.5, DateTime.Now);
            EmployeesDataTable.Rows.Add(4, "Fadi JAmeel  ", "Egypt", 800, DateTime.Now);
            EmployeesDataTable.Rows.Add(5, "Omar Mahmoud ", "Lebanon", 7000, DateTime.Now);





            Console.WriteLine("\nEmployees List:\n");

            foreach (DataRow RecordRow in EmployeesDataTable.Rows)
            {
                Console.WriteLine("ID: {0}\t Name : {1} \t Country: {2} \t Salary: {3} Date: {4} \t ",
                RecordRow["ID"], RecordRow["Name"], RecordRow["Country"], RecordRow["Salary"],
                RecordRow["Date"]);

            }

            DataView EmployeesDataView1 = EmployeesDataTable.DefaultView;
            
            Console.WriteLine("\nEmployees List from data view: \n");
            for (int i = 0; i < EmployeesDataView1.Count; i++)
            
            {
                Console.WriteLine("{0}, {1} , {2} , {3}", EmployeesDataView1[i][0], EmployeesDataView1[i][1],
                EmployeesDataView1[i][2], EmployeesDataView1[i][3]);
            }


            Console.WriteLine("\nEmployees List from data view after sorting by Name in ascending order:\n");
            EmployeesDataView1.Sort = "Name ASC";

            for (int i = 0; i < EmployeesDataView1.Count; i++)
            {
                Console.WriteLine("{0}, {1} , {2} , {3}", EmployeesDataView1[i][0], EmployeesDataView1[i][1],
                EmployeesDataView1[i][2], EmployeesDataView1[i][3]);
            }

            // Now Filter.

            EmployeesDataView1.RowFilter = "Country='Jordan' or Country='Egypt'";
            
            // Display all records in the view.
            
            Console.WriteLine("\nEmployees List from data view after filtering \"Jordan or Egypt\":\n");
            for (int i = 0; i < EmployeesDataView1.Count; i++)
            {
                  Console.WriteLine("{0}, {1} , {2} , {3}", EmployeesDataView1[i][0], EmployeesDataView1[i][1],
                  EmployeesDataView1[i][2], EmployeesDataView1[i][3]);
            }

           
        }

    }
}   
