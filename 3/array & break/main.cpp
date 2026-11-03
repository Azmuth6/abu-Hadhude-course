#include <iostream>

using namespace std;

int main()
{
    int x[6] ={10,20,30, 40 ,50 ,60} ,search_for =50 ;

    for(int i =0 ; i<6 ; i++)
    {   cout <<"we are at " << i << endl ;
        if (x[i] == search_for )
       {
        cout << search_for << " founded at  " << i << endl;
        break ;
       }
    }

    return 0;
}
