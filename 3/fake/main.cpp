/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string fullname, s1, s2;
    cout << "Enter your full name: \n";
    cin.ignore(1,'\n') ;
    getline(cin, fullname);
    cout << "Enter two words: " << endl;
    cin >> s1 >> s2;

    cout << "\n******************************\n";
    cout << "Length of full name: " << fullname.length() << endl;
    cout << "Concatenated words: " << s1 + s2 << endl;

    return 0;
}
*/

                               //   another code


/*
#include <iostream>

using namespace std ;
void fun (int &num1 , int &num2 )
{
    int temp = num1 ;
    num1 = num2 ;
    num2 = temp ;
    cout << num1 << "  " << num2 ;
}
int main ()
{
    int num1 , num2 ;
     cout << "enter f \n" ;
     cin >> num1 ;
     cout << "enter s \n" ;
     cin >> num2 ;

     fun(num1,num2);

    cout << " in main fun " << num1 << "   " << num2 ;


    return 0;


}
*/

/*
#include <iostream>

using namespace std ;
void readar(int x[3])
{
    cout << "enter f : " ;
    cin >> x[0];
    cout << "enter s : " ;
    cin >> x[1];
    cout << "enter t : " ;
    cin >> x[2];
}

void print_avr (int x [3])
{
    cout << "avr of three number : " << (x[0]+x[1]+x[2])/3 ;
}

int main ()
{
    int x[3];
    readar(x) ;
    print_avr (x);


    return 0 ;
}
*/


#include <iostream>
#include <string>

using namespace std;

struct strInfo
{
    string FirstName;
    string LastName;
    int Age;
    string Phone;
};

void ReadInfo(strInfo& Info)
{


    cout << "Please enter FirstName?\n";
    cin >> Info.FirstName;


    cout << "Please enter LastName?\n";
    cin >> Info.LastName;


    cout << "Please enter Age?\n";
    cin >> Info.Age;


    cout << "Please enter Phone?\n";
    cin >> Info.Phone;


}

void PrintInfo(strInfo Info)
{


    cout << "\n**********************************\n";


    cout << "FirstName: " << Info.FirstName << endl;
    cout << "LastName: " << Info.LastName << endl;
    cout << "Age: " << Info.Age << endl;
    cout << "Phone: " << Info.Phone << endl;


    cout << "\n**********************************\n";


}

void ReadPersonsInfo(strInfo Persons[2])
{
   ReadInfo(Persons[0]);
   ReadInfo(Persons[1]);
}

void PrintPersonsInfo(strInfo Persons[2])
{



    PrintInfo(Persons[0]);
    PrintInfo(Persons[1]);


}

int main()
{


    strInfo Persons[2];
    ReadPersonsInfo(Persons);
    PrintPersonsInfo(Persons);

    return 0;
}











