#include <iostream>  
#include <cstdlib>   
#include <ctime>     
#include <string>
#include <iomanip>
using namespace std; 

enum enDifficulty { easy = 1, medium = 2, hard = 3, mix = 4 };
enum enWinner { win = 1, lose = 2, draw = 3 };
enum enMath { addition = 1, subtraction = 2, multiplication = 3, division = 4, mixMath = 5 };

struct stRoundInfo {
    short RoundNumber = 0;
    enDifficulty PlayerChoiceOfDifficulty;
    enMath MathChoice;
    int Number1, Number2;
    int PlayerAnswer;
    int CorrectAnswer;
    enWinner RoundResult;
};

struct stGameResults {
    short GameRounds = 0;
    short PlayerWinTimes = 0;
    short PlayerLoseTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
};

int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

enWinner DetermineGameWinner(short PlayerWinTimes, short PlayerLoseTimes) {
    if (PlayerWinTimes > PlayerLoseTimes) return win;
    else if (PlayerLoseTimes > PlayerWinTimes) return lose;
    else return draw;
}

int PerformMathOperation(int number1, int number2, enMath operation) {
    enMath op = operation;
    if (operation == mixMath) {
        op = (enMath)(RandomNumber(1, 4)); // Randomly pick from 1 to 4
    }
    
    switch (op) {
        case addition:
            return number1 + number2;
        case subtraction:
            return number1 - number2;
        case multiplication:
            return number1 * number2;
        case division:
            if (number2 != 0) return number1 / number2;
            else return 0; // This should be handled better
        default:
            return 0;
    }
}

string GetDifficultyName(enDifficulty difficulty) {
    string arrDifficultyNames[4] = { "Easy", "Medium", "Hard", "Mix" };
    return arrDifficultyNames[difficulty - 1];
}

string GetMathSymbol(enMath mathChoice) {
    string arrMathSymbols[4] = { "+", "-", "*", "/" };
    return arrMathSymbols[mathChoice - 1];
}

string GetMathOperationName(enMath mathChoice) {
    string arrMathNames[5] = { "Addition", "Subtraction", "Multiplication", "Division", "Mix" };
    return arrMathNames[mathChoice - 1];
}

enMath ReadPlayerMathChoice() {
    short choice;
    do {
        cout << "\nChoose Math Operation:\n";
        cout << "[1] Addition\n";
        cout << "[2] Subtraction\n";
        cout << "[3] Multiplication\n";
        cout << "[4] Division\n";
        cout << "[5] Mix\n";
        cout << "Your Choice: ";
        cin >> choice;
        
        if (choice < 1 || choice > 5) {
            cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }
    } while (choice < 1 || choice > 5);
    
    return (enMath)choice;
}

enDifficulty ReadPlayerDifficultyChoice() {
    short choice;
    do {
        cout << "\nChoose Difficulty Level:\n";
        cout << "[1] Easy (1-10)\n";
        cout << "[2] Medium (10-50)\n";
        cout << "[3] Hard (50-100)\n";
        cout << "[4] Mix (1-100)\n";
        cout << "Your Choice: ";
        cin >> choice;
        
        if (choice < 1 || choice > 4) {
            cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }
    } while (choice < 1 || choice > 4);
    
    return (enDifficulty)choice;
}

short ReadHowManyRounds() {
    short rounds;
    do {
        cout << "\nHow many rounds do you want to play (1-10)? ";
        cin >> rounds;
        
        if (rounds < 1 || rounds > 10) {
            cout << "Invalid number! Please enter a number between 1 and 10.\n";
        }
    } while (rounds < 1 || rounds > 10);
    
    return rounds;
}

void GenerateNumbers(stRoundInfo& RoundInfo) {
    switch(RoundInfo.PlayerChoiceOfDifficulty) {
        case easy:
            RoundInfo.Number1 = RandomNumber(1, 10);
            RoundInfo.Number2 = RandomNumber(1, 10);
            break;
        case medium:
            RoundInfo.Number1 = RandomNumber(10, 50);
            RoundInfo.Number2 = RandomNumber(10, 50);
            break;
        case hard:
            RoundInfo.Number1 = RandomNumber(50, 100);
            RoundInfo.Number2 = RandomNumber(50, 100);
            break;
        case mix:
            RoundInfo.Number1 = RandomNumber(1, 100);
            RoundInfo.Number2 = RandomNumber(1, 100);
            break;
    }
    
    // For division, ensure we don't divide by zero and result is integer
    if (RoundInfo.MathChoice == division) {
        if (RoundInfo.Number2 == 0) RoundInfo.Number2 = 1;
        // Make sure division results in whole number
        RoundInfo.Number1 = RoundInfo.Number1 * RoundInfo.Number2;
    }
}

int ReadPlayerAnswer() {
    int answer;
    cout << "Enter your answer: ";
    cin >> answer;
    return answer;
}

void PrintQuestion(stRoundInfo RoundInfo) {
    cout << "\n" << RoundInfo.Number1;
    cout << " " << GetMathSymbol(RoundInfo.MathChoice);
    cout << " " << RoundInfo.Number2 << " = ?";
}

enWinner CheckAnswer(stRoundInfo& RoundInfo) {
    if (RoundInfo.PlayerAnswer == RoundInfo.CorrectAnswer) {
        cout << "\nCorrect Answer! Well done! :-)";
        return win;
    } else {
        cout << "\nWrong Answer :-(";
        cout << "\nThe correct answer is: " << RoundInfo.CorrectAnswer;
        return lose;
    }
}

void PrintRoundResults(stRoundInfo RoundInfo) {
    cout << "\n" << string(40, '=');
    cout << "\nRound [" << RoundInfo.RoundNumber << "] Results";
    cout << "\n" << string(40, '=');
    cout << "\nQuestion: ";
    PrintQuestion(RoundInfo);
    cout << "\nYour Answer: " << RoundInfo.PlayerAnswer;
    cout << "\nCorrect Answer: " << RoundInfo.CorrectAnswer;
    cout << "\nResult: " << (RoundInfo.RoundResult == win ? "You Win!" : "You Lose!");
    cout << "\n" << string(40, '=') << "\n";
}

stRoundInfo PlayRound(short RoundNumber, enDifficulty DifficultyChoice, enMath MathChoice) {
    stRoundInfo RoundInfo;
    RoundInfo.RoundNumber = RoundNumber;
    RoundInfo.PlayerChoiceOfDifficulty = DifficultyChoice;
    RoundInfo.MathChoice = MathChoice;

    // Handle mix math choice for individual rounds
    if (MathChoice == mixMath) {
        RoundInfo.MathChoice = (enMath)RandomNumber(1, 4);
    }

    GenerateNumbers(RoundInfo);
    RoundInfo.CorrectAnswer = PerformMathOperation(RoundInfo.Number1, RoundInfo.Number2, RoundInfo.MathChoice);
    
    PrintQuestion(RoundInfo);
    RoundInfo.PlayerAnswer = ReadPlayerAnswer();
    RoundInfo.RoundResult = CheckAnswer(RoundInfo);
    
    PrintRoundResults(RoundInfo);
    
    return RoundInfo;
}

string GetFinalResultsText(enWinner Winner) {
    string arrWinnerText[3] = { "Player Won!", "Player Lost!", "It's a Draw!" };
    return arrWinnerText[Winner - 1];
}

void PrintGameResults(stGameResults GameResults) {
    cout << "\n" << string(50, '=');
    cout << "\n\t\tGAME RESULTS";
    cout << "\n" << string(50, '=');
    cout << "\nNumber of Rounds: " << GameResults.GameRounds;
    cout << "\nPlayer Won: " << GameResults.PlayerWinTimes << " times";
    cout << "\nPlayer Lost: " << GameResults.PlayerLoseTimes << " times";
    cout << "\nWin Rate: " << fixed << setprecision(1) 
          << (float)GameResults.PlayerWinTimes / GameResults.GameRounds * 100 << "%";
    cout << "\nFinal Result: " << GetFinalResultsText(GameResults.GameWinner);
    cout << "\n" << string(50, '=') << "\n";
}

stGameResults PlayGame() {
    stGameResults GameResults;
    
    cout << "\n" << string(50, '=');
    cout << "\n\t\tMATH QUIZ GAME";
    cout << "\n" << string(50, '=');
    
    enDifficulty DifficultyChoice = ReadPlayerDifficultyChoice();
    enMath MathChoice = ReadPlayerMathChoice();
    GameResults.GameRounds = ReadHowManyRounds();
    
    cout << "\nGame Settings:";
    cout << "\nDifficulty: " << GetDifficultyName(DifficultyChoice);
    cout << "\nOperation: " << GetMathOperationName(MathChoice);
    cout << "\nRounds: " << GameResults.GameRounds;
    cout << "\n\nLet's start!\n";

    for (short GameRound = 1; GameRound <= GameResults.GameRounds; GameRound++) {
        cout << "\nRound [" << GameRound << "] begins:\n";
        
        stRoundInfo RoundInfo = PlayRound(GameRound, DifficultyChoice, MathChoice);
        
        if (RoundInfo.RoundResult == win) {
            GameResults.PlayerWinTimes++;
        } else {
            GameResults.PlayerLoseTimes++;
        }
    }

    GameResults.GameWinner = DetermineGameWinner(GameResults.PlayerWinTimes, GameResults.PlayerLoseTimes);
    
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
        
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;
        
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
    
    cout << "\nThank you for playing! Goodbye!\n";
}

int main() {
    srand((unsigned)time(NULL));
    
    StartGame();
    
    return 0;
}