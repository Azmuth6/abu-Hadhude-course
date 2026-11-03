using System;
using System.Data;
using Middle;

namespace presentation
{
    internal class Presentation
    {
        static void testFindCountryByID(int ID)

        {
            clsMiddle Country1 = clsMiddle.Find(ID);

            if (Country1 != null)
            {
                Console.WriteLine(Country1.CountryName);

            }

            else
            {
                Console.WriteLine("Country [" + ID + "] Not found!");
            }
        }


        static void testFindCountryByName(string CountryName)

        {
            clsMiddle Country1 = clsMiddle.Find(CountryName);

            if (Country1 != null)
            {
                Console.WriteLine("Country [" + CountryName + "] isFound with ID = " + Country1.ID);

            }

            else
            {
                Console.WriteLine("Country [" + CountryName + "] Is Not found!");
            }
        }


        static void testIsCountryExistByID(int ID)

        {

            if (clsMiddle.isCountryExist(ID))

                Console.WriteLine("Yes, Country is there.");

            else
                Console.WriteLine("No, Country Is not there.");

        }

        static void testIsCountryExistByName(string CountryName)

        {

            if (clsMiddle.isCountryExist(CountryName))

                Console.WriteLine("Yes, Country is there.");

            else
                Console.WriteLine("No, Country Is not there.");

        }


        static void testAddNewCountry()


        {
            clsMiddle Country1 = new clsMiddle();

            Country1.CountryName = "Lebanon";


            if (Country1.Save())
            {

                Console.WriteLine("Country Added Successfully with id=" + Country1.ID);
            }

        }

        static void testUpdateCountry(int ID)

        {
            clsMiddle Country1 = clsMiddle.Find(ID);

            if (Country1 != null)
            {
                //update whatever info you want
                Country1.CountryName = "Lebanon2";


                if (Country1.Save())
                {

                    Console.WriteLine("Country updated Successfully ");
                }

            }
            else
            {
                Console.WriteLine("Country is you want to update is Not found!");
            }
        }

        static void testDeleteCountry(int ID)

        {

            if (clsMiddle.isCountryExist(ID))

                if (clsMiddle.DeleteCountry(ID))

                    Console.WriteLine("Country Deleted Successfully.");
                else
                    Console.WriteLine("Failed to delete Country.");

            else
                Console.WriteLine("Failed to delete: The Country with id = " + ID + " is not found");

        }

        static void ListCountries()
        {

            DataTable dataTable = clsMiddle.GetAllCountries();

            Console.WriteLine("Countries Data:");

            foreach (DataRow row in dataTable.Rows)
            {
                Console.WriteLine($"{row["CountryID"]},  {row["CountryName"]}");
            }

        }




        static void Main(string[] args)
        {
            //testFindCountryByName("Egypt");
            ListCountries();
        }
    }
}
