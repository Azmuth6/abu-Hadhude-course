#include <iostream>

using namespace std;

class clsCalculator
{
private:
	float _Result = 0;
	float _LastNumber = 0;
	float _PreviousResult = 0;
	string _LastOperation = "Clear";
	bool _IsZero(int number)
	{
		return (number == 0);
	}


public:

	void Add(float number)
	{
		_LastNumber = number;
		_PreviousResult = _Result;
		_Result += number;
		_LastOperation = "Adding";
	}

	void Subtract(float number)
	{
		_LastNumber = number;
		_PreviousResult = _Result;
		_Result -= number;
		_LastOperation = "Subtracting";
	}

	void Multiply(float number)
	{
		_LastNumber = number;
		_PreviousResult = _Result;
		_Result *= number;
		_LastOperation = "Multiplying";
	}

	void Divide(float number)
	{
		 _LastNumber = number;
		 if (_IsZero(number)) { number = 1; }
		_PreviousResult = _Result;
		_Result /= number;
		_LastOperation = "Dividing";
	}

	float GetFinalResults()
	{ return _Result; }
	
	void Clear() 
	{
		_LastNumber = 0; 
		_PreviousResult = 0;
		_LastOperation = "Clear"; 
		_Result = 0;
	}

	void CancelLastOperation()
	{
		_LastNumber = 0;
		_LastOperation = "Cancelling Last Operation"; 
		_Result = _PreviousResult;
	}
	
	void PrintResult() 
	{
		cout << "Result "; 
		cout << "After " << _LastOperation << " " << _LastNumber << " is: " << _Result << "\n"; 
	}


};


int main()
{
   

}
