#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Random_Number (int from , int to)
{
    int random = rand() % (to - from +1 ) + from ;
    return random ;

}

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

enGameChoice enterChoice()
{
    short Choice;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enGameChoice)Choice;

}

enWinner determineWinner(enGameChoice userChoice, enGameChoice computerChoice)
{
    if (userChoice == computerChoice)
        return Draw;

    if ((userChoice == Stone && computerChoice == Scissors) ||
        (userChoice == Paper && computerChoice == Stone) ||
        (userChoice == Scissors && computerChoice == Paper))

        return Player1;

    return Computer;
}


void  updateStatistics( enWinner status ,int & NumOfLose, int & NumOfWin, int & NumOfDraw)
{
    if (status == Player1)
        NumOfWin++;
    else if (status == Computer)
        NumOfLose++;
    else if (status == Draw)
        NumOfDraw++;
}

void displayResult(enGameChoice userChoice, enGameChoice computerChoice, enWinner status)
{
    cout << "You chose: ";
    switch (userChoice)
    {
        case Stone: cout << "Rock";
         break;
        case Paper: cout << "Paper";
         break;
        case Scissors: cout << "Scissors";
         break;
    }

    cout << ", Computer chose: ";
    switch (computerChoice)
    {
        case Stone: cout << "Rock";
         break;
        case Paper: cout << "Paper";
         break;
        case Scissors: cout << "Scissors";
         break;
    }

    cout << endl;

    if (status == Player1)
    {
        cout << "You win!" << endl;
        system("color 2f");

    }
    else if (status == Computer)
    {
        cout << "You lose!\a" << endl;
        system("color 4f");
    }
    else
    {
        cout << "It's a draw!" << endl;
        system("Color 6F");
    }

}

void gameSummary(int NumOfLose, int NumOfWin, int NumOfDraw)
{
    cout <<  "  GAME OVER  \n";
    cout << "Game Summary:" << endl;
    cout << "Wins: " << NumOfWin << endl;
    cout << "Losses: " << NumOfLose << endl;
    cout << "Draws: " << NumOfDraw << endl;

    if (NumOfWin > NumOfLose)
        cout << "You are the overall winner!" << endl;
    else if (NumOfWin < NumOfLose)
        cout << "You are the overall loser!" << endl;
    else
        cout << "It's an overall draw!" << endl;
}

void numberOfRounds (int &NumOfLose, int &NumOfWin, int &NumOfDraw)
{
    enWinner status;
    enGameChoice userChoice ,  computerChoice;
    int number ;


    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "You can play multiple rounds." << endl;
    cout << "Enter the number of rounds: ";
    cin >> number;

    short round = 1;
    while (number > 0)
    {
        cout << "\nRound " << round << ": " << endl;

        userChoice = enterChoice();
        computerChoice = (enGameChoice)(Random_Number(1, 3));

        enWinner status = determineWinner(userChoice, computerChoice);

        updateStatistics(status, NumOfLose, NumOfWin, NumOfDraw);

        displayResult(userChoice, computerChoice, status);
        cout << "---------------------------------------------------------\n\n";
        number--;
        round++;
    }

    gameSummary(NumOfLose, NumOfWin, NumOfDraw);

    cout << "Thank you for playing!" << endl;
}


void doPlayAgainLoop()
{
    char playAgain;

    int NumOfLose = 0, NumOfWin = 0, NumOfDraw = 0;
    do
    {
        NumOfLose = 0;
        NumOfWin = 0;
        NumOfDraw = 0;

        numberOfRounds(NumOfLose, NumOfWin, NumOfDraw);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y')
        {
            system("cls");
            system("color 07");
        }
        else
        {
            cout << "Thank you for playing!" << endl;
            system("color 07");
            exit(0);
        }

    } while (playAgain != 'n' && playAgain != 'N');
}

int main()
{
    srand((unsigned) time(NULL));
    doPlayAgainLoop();
    return 0;
}
