#include <iostream>  
#include <cstdlib>   
#include <ctime>     
using namespace std; 


enum enHardest { easy = 1, medium = 2, Hard = 3, mix = 4 };
enum enWinner { win = 1, lose = 2, Draw = 3 };
enum enMath { addition = 1, subtraction = 2, multiplication = 3, division = 4, mixMath = 5 };

struct stRoundInfo {
    short RoundNumber = 0;
    enHardest PlayerChoiceOfHardest;
    enMath Mathchoice;
    int Number1, Number2;
    int PlayerAnswer;
    int CorrectAnswer;
    enWinner stateLoseWin;
};

struct stGameResults {
    short GameRounds = 0;
    short PlayerWinTimes = 0;
    short PlayerLoseTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
};


int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enWinner WinLoseTheGame(short PlayerWinTimes, short PlayerLoseTimes)
{
    if (PlayerWinTimes > PlayerLoseTimes) return win;
    else if (PlayerLoseTimes > PlayerWinTimes) return lose;
    else return Draw;
}


int PerformMathOperation(int number1, int number2, enMath operation)
{
enMath op = operation;

    switch (op)
    {
    case addition:
        return number1 + number2;
    case subtraction:
        return number1 - number2;
    case multiplication:
        return number1 * number2;
    case division:
        if (number2 != 0) return number1 / number2;
        else return 0;
    default:
        return 0;
    }
}

string ChoiceName(enHardest Choice)
{
    string arrGameChoices[4] = { "Easy", "Medium", "Hard", "Mix" };
    return arrGameChoices[Choice - 1];
}

enMath ReadPlayerMathChoice()
{
    short Choice;
    do
    {
        cout << "\nYour Choice: [1]:Addition, [2]:Subtraction, [3]:Multiplication, [4]:Division, [5]:Mix? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 5);
    return (enMath)Choice;
}

    
string GetMathSymbol(enMath Choice) {
    string arrMathSymbols[4] = { "+", "-", "*", "/" };
    return arrMathSymbols[Choice - 1];
}

enHardest ReadPlayerHardestChoice() {
    short Choice;
    do {
        cout << "\nYour Choice: [1]:Easy, [2]:Medium, [3]:Hard, [4]:Mix? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 4);
    return (enHardest)Choice;
}

short ReadHowManyRounds() {
    short rounds;
    do {
        cout << "\nHow many rounds do you want to play (1-10)? ";
        cin >> rounds;
    } while (rounds < 1 || rounds > 10);
    return rounds;
}

void GenerateNumbers(stRoundInfo& RoundInfo)
{
    switch(RoundInfo.PlayerChoiceOfHardest)
    {
        case easy :
            RoundInfo.Number1 = RandomNumber(1,10) ;
            RoundInfo.Number2 = RandomNumber(1,10) ;
            break;
        case medium :
            RoundInfo.Number1 = RandomNumber(10,50) ;
            RoundInfo.Number2 = RandomNumber(10,50) ;
            break;
        case Hard :
            RoundInfo.Number1 = RandomNumber(50,100) ;
            RoundInfo.Number2 = RandomNumber(50,100) ;
            break;
        case mix :
            RoundInfo.Number1 = RandomNumber(1,100) ;
            RoundInfo.Number2 = RandomNumber(1,100) ;
            break;



    }
}
int ReadPlayerAnswer ()
{
    int answer ;
    cout << "enter your answer : " ;
    cin >> answer ;
    return answer ;
}

void PrintQuestion (stRoundInfo RoundInfo) 
{
    cout << endl << RoundInfo.Number1 ;
    cout<<" " <<GetMathSymbol(RoundInfo.Mathchoice) ;
    cout << " " << RoundInfo.Number2 << " = ?";
}

enWinner CheckAnswer(stRoundInfo& RoundInfo) {
    if (RoundInfo.PlayerAnswer == RoundInfo.CorrectAnswer) {
        cout << "\nCorrect Answer :-)";
        return win;
    } else {
        cout << "\nWrong Answer :-(";
        cout << "\nThe correct answer is: " << RoundInfo.CorrectAnswer;
        return lose;
    }
}

void PrintRoundResults(stRoundInfo RoundInfo) {
    cout << "\n____________Round [" << RoundInfo.RoundNumber << "] ____________";
    cout << "\n\nQuestion: ";
    PrintQuestion(RoundInfo);
    cout << "\nPlayer Answer: " << RoundInfo.PlayerAnswer;
    cout << "\nCorrect Answer: " << RoundInfo.CorrectAnswer;
    cout << "\nRound Result: " << (RoundInfo.stateLoseWin == win ? "You Win" : "You Lose");
    cout << "\n___________________________________\n";
}

stRoundInfo playRound (short RoundNumber , enHardest HardestChoice , enMath MathChoice )
{
    stRoundInfo RoundInfo ;
    RoundInfo.RoundNumber = RoundNumber ;
    RoundInfo.PlayerChoiceOfHardest = HardestChoice ;
    RoundInfo.Mathchoice = MathChoice ;

    if (MathChoice == mixMath) {
        RoundInfo.Mathchoice = (enMath)RandomNumber(1, 4);
    }
    GenerateNumbers(RoundInfo);

    RoundInfo.CorrectAnswer = PerformMathOperation(RoundInfo.Number1 , RoundInfo.Number2 , RoundInfo.Mathchoice) ;
    PrintQuestion(RoundInfo) ;
    
    RoundInfo.PlayerAnswer = ReadPlayerAnswer();  
    RoundInfo.stateLoseWin = CheckAnswer(RoundInfo); 
    
    PrintRoundResults(RoundInfo); 
     
    return RoundInfo ;

}


string GetFinalResultsText(enWinner Winner) {
    string arrWinnerText[3] = { "Player Won", "Player Lose", "Draw" };
    return arrWinnerText[Winner - 1];
}


void PrintGameResults(stGameResults GameResults) {
    cout << "\n\n___________________[Game Results]___________________";
    cout << "\nNumber of Rounds: " << GameResults.GameRounds;
    cout << "\nPlayer Won Times: " << GameResults.PlayerWinTimes;
    cout << "\nPlayer Lost Times: " << GameResults.PlayerLoseTimes;
    cout << "\nFinal Result: " << GetFinalResultsText(GameResults.GameWinner);
    cout << "\n___________________________________________________\n";
}

stGameResults PlayGame() {
    stGameResults GameResults;
    enHardest HardestChoice = ReadPlayerHardestChoice() ;

    enMath mathChoice = ReadPlayerMathChoice();

    GameResults.GameRounds = ReadHowManyRounds() ;

    for (short GameRound = 1; GameRound <= GameResults.GameRounds; GameRound++) {
     cout << "\nRound [" << GameRound << "] begins:\n";

     stRoundInfo RoundInfo = playRound(GameRound, HardestChoice, mathChoice);

     if (RoundInfo.stateLoseWin == win) {
         GameResults.PlayerWinTimes++;
         }
      else {
         GameResults.PlayerLoseTimes++;
        }
    }

     GameResults.GameWinner = WinLoseTheGame(GameResults.PlayerWinTimes, GameResults.PlayerLoseTimes);

    return GameResults;


}

void ResetScreen() {
    system("cls");
}

void StartGame() {
    char PlayAgain = 'Y';

    do {
        ResetScreen();
        stGameResults GameResults = PlayGame();
        PrintGameResults(GameResults);

        cout << "\nDo you want to play again? Y/N? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() {
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}

