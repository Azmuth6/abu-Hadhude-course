#include <iostream>
#include <map>

using namespace std;

int main ()
{
   map <string,int> StudentGrade;
   
   StudentGrade["Ali"] = 77 ;
   StudentGrade["Ahmed"] = 85;
   StudentGrade["Fadi"] = 95;

   cout << "\nPrinting all map Value.\n\n";

   for (auto & pair : StudentGrade)
   {
        cout << "Student: " << pair.first << ", Grade: " << pair.second << endl;
   }

   string studentName = "Fadi";

   if ((StudentGrade.find(studentName)) != StudentGrade.end())
   {
     cout << studentName << "'s grade: " << StudentGrade[studentName] << endl;
    } else {
        cout << "Grade not found for " << studentName << endl;
    }

    return 0;


}