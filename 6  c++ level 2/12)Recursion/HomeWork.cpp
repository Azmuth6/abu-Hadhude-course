#include <iostream>
using namespace std;

void PrintNumbersdowmFromMtoN(int M, int N)
{
    if (M >= N)
    {
        cout << M << endl;
        PrintNumbersdowmFromMtoN(M - 1, N);
    }
}
int printNpowerM(int Base, int Power)
{
   
   return  Power == 0 ?  1 : (Base * printNpowerM(Base, Power - 1));

   //if (Power == 0)
   //    return 1;
   //else
   //    return Base * printNpowerM(Base, Power - 1);
    
}

int main()
{
	cout << "powr -> " << printNpowerM(2, 4);

    return 0;
}
