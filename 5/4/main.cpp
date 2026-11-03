#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

bool isPerfectNumber(int Number)
{
    int Sum = 0; // Initialize the sum of divisors to 0.

    // Loop from 1 to Number - 1 to find all proper divisors.
    for (int i = 1; i < Number; i++)
    {
        // If i divides Number evenly, it is a divisor.
        if (Number % i == 0)
            Sum += i; // Add the divisor to the sum.
    }

    // Compare the sum of divisors to the original number.
    // Return true if they are equal (the number is perfect), or false if they are not.
    return Number == Sum;
}


// Function: PrintPerfectNumbersFrom1ToN
// Purpose: Prints all perfect numbers between 1 and a given upper limit (inclusive).
// Parameter: Number - the upper limit for checking perfect numbers.
void PrintPerfectNumbersFrom1ToN(int Number)
{
    // Loop through each number from 1 to the given upper limit.
    for (int i = 1; i <= Number; i++)
    {
        // Check if the current number is a perfect number.
        if (isPerfectNumber(i))
        {
            // If it is perfect, output the number.
            cout << i << endl;
        }
    }
}

// Main function: Entry point of the program.
int main()
{
    // Call ReadPositiveNumber with a prompt message to obtain a positive number from the user.
    // Then pass that number to PrintPerfectNumbersFrom1ToN to print all perfect numbers within the range.
    PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number?"));

    return 0;  // Return 0 to indicate successful execution.
}


