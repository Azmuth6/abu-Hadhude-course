#include <iostream>
#include <string>
#include <cmath>

using namespace std;


float ReadIsoscelesTringleSides()
{
    float A;
    cout << "Please enter Tingle First Side ? " << endl;
    cin >> A;
     float B;
    cout << "Please enter Tingle secend Side ? " << endl;
    cin >> B;

    return A,B;
}
float CircleAreaByIsoscelesTringleSides(float A , float B){
    const float PI = 3.141592653589793238;

    float Area = (PI * (pow(B , 2) / 4) * ((2*A-B)/(2*A+B)));

    return Area;
}
void PrintResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}
int main()
{
    PrintResult(CircleAreaByIsoscelesTringleSides(ReadIsoscelesTringleSides()));

    return 0;
}
