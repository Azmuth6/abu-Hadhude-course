namespace Calculator_Project
{


    class Calculator
    {
        private double _num = 0;
        private string _LastOperation;
        private double _NumberOfFun;

        public void Add(double n)
        {
            _num += n;
            _LastOperation = "Adding";
            _NumberOfFun = n;
        }

        public void Subtract(double n)
        {
            _num -= n;
            _LastOperation = "Subtracting";
            _NumberOfFun = n;
        }

        public void multiply(double n)
        {
            _num *= n;
            _LastOperation = "Multiplying";
            _NumberOfFun = n;
        }

        public void Divide(double n)
        {
            _LastOperation = "Dividing";
            _NumberOfFun = n;

            if (n == 0)
            {
               n = 1;
            }

            _num /= n;
        }

        public void clear()
        {
            _num = 0;
            _LastOperation = "Clear";
            _NumberOfFun = _num;
        }
            

        public void PrintResult()
        {
            Console.WriteLine("Result After {0} {1} is : {2} ", _LastOperation, _NumberOfFun , _num);
        }


    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Calculator calc = new Calculator();

            calc.Add(10);
            calc.PrintResult();

            calc.Subtract(5);
            calc.PrintResult();

        }
    }
}
