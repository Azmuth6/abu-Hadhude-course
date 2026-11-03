#include <iostream>
#include <cstdlib>
#include <ctime>    
using namespace std;

enum enGameChoice {Stone =1 , Paper = 2, Scissors = 3};

enum enWinner {Player1 = 1, Computer = 2, Draw = 3};

struct stRoundInfo 
{
    short RoundNumber =0 ;
    enGameChoice Player1Choice ;
    enGameChoice computerChoice ;
    enWinner winner ;
    string winnerName ;
};

struct stGameResults 
{
    short GameRounds =0 ;
    short Player1WinTimes = 0;   
    short ComputerWinTimes = 0;  
    short DrawTimes = 0;
    enWinner GameWinner ;
    string WinnerName = "";   

} ;


int RandomNumber (int From , int To )
{
    return rand() % (To - From +1 ) + From ;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3) ;
}

enWinner WhoWinTheRound (stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.computerChoice)
        return Draw ;

    switch (RoundInfo.Player1Choice)
    {
        case enGameChoice::Paper :
        return ( RoundInfo.computerChoice == Scissors ) ? enWinner::Computer : enWinner::Player1 ;
        case enGameChoice::Stone :
        return ( RoundInfo.computerChoice == Paper ) ? enWinner::Computer : enWinner::Player1 ;
        case enGameChoice::Scissors :
        return ( RoundInfo.computerChoice == Stone ) ? enWinner::Computer : enWinner::Player1 ;
    }

}


enWinner WhoWinTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
        return Player1 ;
    else if (Player1WinTimes < ComputerWinTimes)
        return Computer ;

    else 
        return Draw ;

}


string ChoiceName (enGameChoice Choice)
{
    string arrayGameChoice [3] = {"Stone" ,"Paper" , "Scissors"} ;
    return arrayGameChoice [Choice -1] ;
}

string WinnerName (enWinner win)
{
    string arrayGameWin [3] = {"player" , "computer" , "Draw"} ;
    return arrayGameWin [win -1] ;

}

enGameChoice playerChoice ()
{
    short choice ;

    do 
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> choice;
    }while (choice <  1 || choice > 3  ) ;

    return (enGameChoice) choice ;

}

void PrintResult (stRoundInfo RoundInfo  )
{
    cout << "\n____________ Round [" << RoundInfo.RoundNumber <<"\n\n" ;
    cout << "Player1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.computerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.winnerName<< "]\n";
    cout << "_________________________________________\n" << endl;

}
stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = playerChoice();
        RoundInfo.computerChoice = GetComputerChoice();
        RoundInfo.winner = WhoWinTheRound(RoundInfo);
        RoundInfo.winnerName = WinnerName(RoundInfo.winner);

        if (RoundInfo.winner == enWinner::Player1)
            Player1WinTimes++;
        else if (RoundInfo.winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintResult(RoundInfo);
    }

    return { HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes,
         WhoWinTheGame(Player1WinTimes, ComputerWinTimes), WinnerName(WhoWinTheGame(Player1WinTimes, ComputerWinTimes)) };
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        system("cls"); 
        stGameResults GameResults = PlayGame(3);
        cout << "\nGame Over! Winner: " << GameResults.WinnerName << endl;

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL)); 
    StartGame();  
    return 0;  
}