#include <iostream>
#include <string>
#include <cmath>

using namespace std;


float ReadCircleCircumference()
{
    float A;
    cout << "Please enter Circle Circumference ? " << endl;
    cin >> A;

    return A;
}
float CircleAreaByCircumference(float A){
    const float PI = 3.141592653589793238;

    float Area = (pow(A, 2)) / (4*PI);

    return Area;
}
void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}
int main()
{
    PrintResult(CircleAreaByCircumference(ReadCircleCircumference()));

    return 0;
}
