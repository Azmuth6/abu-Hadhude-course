using System;
using System.Data;
using Data_Base;

namespace Middle
{
    public class clsMiddle
    {

        public int ID { set; get; }
        public string CountryName { set; get; }

        public enum enMode { AddNew = 0, Update = 1 };
        public enMode Mode = enMode.AddNew;


        public clsMiddle()
        {
            this.ID = -1;
            this.CountryName = "";
            Mode = enMode.AddNew;
        }

        private clsMiddle(int ID, string CountryName)
        {
            this.ID = ID;
            this.CountryName = CountryName;
            Mode = enMode.Update;
        }


        private bool _AddNewCountry()
        {
            //call DataAccess Layer 

            this.ID = clsData_Base.AddNewCountry(this.CountryName);

            return (this.ID != -1);
        }

        private bool _UpdateContact()
        {
            //call DataAccess Layer 

            return clsData_Base.UpdateCountry(this.ID, this.CountryName);

        }

        public static clsMiddle Find(int ID)
        {
            string CountryName = "";

           
            if(clsData_Base.GetCountryInfoByID(ID, ref CountryName))
            {
                return new clsMiddle(ID, CountryName);
            }
            else
                return null;

        }

        public static clsMiddle Find(string CountryName)
        {

            int ID = -1;


            if (clsData_Base.GetCountryInfoByName(CountryName, ref ID))

                return new clsMiddle(ID, CountryName);
            else
                return null;

        }

        public bool Save()
        {


            switch (Mode)
            {
                case enMode.AddNew:
                    if (_AddNewCountry())
                    {

                        Mode = enMode.Update;
                        return true;
                    }
                    else
                    {
                        return false;
                    }

                case enMode.Update:

                    return _UpdateContact();

            }

            return false;
        }


        public static DataTable GetAllCountries()
        {
            return clsData_Base.GetAllCountries();

        }

        public static bool DeleteCountry(int ID)
        {
            return clsData_Base.DeleteCountry(ID);
        }

        public static bool isCountryExist(int ID)
        {
            return clsData_Base.IsCountryExist(ID);
        }

        public static bool isCountryExist(string CountryName)
        {
            return clsData_Base.IsCountryExist(CountryName);
        }




    }
}
