#include <iostream>

using namespace std;

int main()
{
    int s ; cin >> s ;
    for ( int i=0 ;i<=s ;i++)
    {
        for (int j = s;j>=i ;j--)
        {
            cout << j << " " ;
        }
        cout << endl ;

    }
    return 0;
}

/*                     ده علشا نعمل مثلث مقلوب انت الي محدد حجمو
    int s ; cin >> s ;
    for ( int i=0 ;i<=s ;i++)
    {
        for (int j = s;j>=i ;j--)
        {
            cout << j << " " ;
        }
        cout << endl ;

*/



/*

    for ( int i=1 ;i<=10 ;i++)
    {
        for (int j = 10;j>=i ;j--)
        {
            cout << j << "   " ;
        }
        cout << endl ;
    }
*/

                     //another
/*
    for (int i = 1 ; i < 7 ; ++i)
    {
        for(int j = 0 ; j < i ; ++j)
      {
            cout << char(65 + j) <<"  ";
      }
        cout << endl ;
    }
*/
