#include <iostream>
#include <string>
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
#include <ctime>      // Include ctime for the time() function.
using namespace std;

int Random_Number (int from , int to)
{
    // Generate a random number between 0 and (To - From) using rand(),
    // then add From to shift the range to [From, To]
    int random = rand() % (to - from +1 ) + from ;
    return random ;

}

int main ()
{
     // Seed the random number generator with the current time.
    // This ensures that we get a different sequence of random numbers on each run.
        srand( (unsigned) time (NULL) ) ; 

        cout << Random_Number(1, 10) << endl;
        cout << Random_Number(1, 10) << endl;



}