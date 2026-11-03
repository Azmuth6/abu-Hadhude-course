#include <iostream>
using namespace std;

class clsCalculator
{

private:

    double Result = 0;

    void SetAdd(int num)
    {
        Result += num;
    }

    void SetSubtract(int num)
    {
        Result -= num;
    }

    void SetMultiply(int num)
    {
        Result *= num;
    }

    void SetDivide(int& num)
    {
        if (num == 0) { num = 1; }
        Result /= num;
    }

    void SetClear()
    {
        Result = 0;
    }

public:

    void Add(int num)
    {
        SetAdd(num);
        cout << "Result After Adding " << num << " is: " << Result << endl;
    }

    void Subtract(int num)
    {
        SetSubtract(num);
        cout << "Result After Subtracting " << num << " is: " << Result << endl;
    }

    void Divide(int num)
    {
        SetDivide(num);
        cout << "Result After Dividing " << num << " is: " << Result << endl;
    }

    void Multiply(int num)
    {
        SetMultiply(num);
        cout << "Result After Multiplying " << num << " is: " << Result << endl;
    }

    void Clear()
    {
        SetClear();
        cout << "Result After CLear " << 0 << " is: " << Result << endl;
    }

    void ResultBalance()
    {
        cout << "Result is: " << Result << endl;
    }
};

int main()
{
    clsCalculator Calculator;

    Calculator.Clear();
    Calculator.Add(20);
    Calculator.Add(200);

    Calculator.Multiply(2);

    Calculator.Divide(0);
    Calculator.Clear();

    system("pause>0");

}