#pragma once

// clsString.hpp
// Header-only class for string utilities
// Full version: includes all functions from the original file, corrected and organized.
// Portable: works with MSVC / GCC / Clang.

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

class clsString
{
private:
    string _Value;
    char _Record;
    string _StringToReplace;
    string _sReplaceTo;
    vector<string> _sSplit;

protected:
    // helper: invert case of single char
    static char invertCaseChar(char c)
    {
        return static_cast<char>(isupper(static_cast<unsigned char>(c)) ? tolower(static_cast<unsigned char>(c)) : toupper(static_cast<unsigned char>(c)));
    }

    // update cached split vector
    void UpdateSplit()
    {
        _sSplit = SplitEachWordsInString(_Value, " ");
    }

public:
    // Constructors
    clsString()
        : _Value(""), _Record(' '), _StringToReplace(""), _sReplaceTo(""), _sSplit()
    {
    }

    clsString(const string& Value, char Record = ' ', const string& StringToReplace = "", const string& sReplaceTo = "")
        : _Value(Value), _Record(Record), _StringToReplace(StringToReplace), _sReplaceTo(sReplaceTo)
    {
        UpdateSplit();
    }

    // Setter / Getter for Value
    void SetValue(const string& Value) {
        _Value = Value;
        UpdateSplit();
    }

    string GetValue() const {
        return _Value;
    }

    // optional: allow explicit access to record and replace tokens
    void SetRecord(char R) { _Record = R; }
    char GetRecord() const { return _Record; }

    void SetStringToReplace(const string& s) { _StringToReplace = s; }
    string GetStringToReplace() const { return _StringToReplace; }

    void SetReplaceTo(const string& s) { _sReplaceTo = s; }
    string GetReplaceTo() const { return _sReplaceTo; }

    // -------------------------
    // printFirstLetterOfEachWord
    // -------------------------
    static void printFirstLetterOfEachWord(const string& S1)
    {
        bool isFirstLetter = true;
        for (size_t i = 0; i < S1.length(); ++i)
        {
            if (S1[i] != ' ' && isFirstLetter)
                cout << S1[i] << endl;

            isFirstLetter = (S1[i] == ' ');
        }
    }

    void printFirstLetterOfEachWord()
    {
        printFirstLetterOfEachWord(_Value);
    }

    // -------------------------
    // Upper/Lower first letter of each word
    // -------------------------
    static string UppFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (size_t i = 0; i < S1.length(); ++i)
        {
            if (S1[i] != ' ' && isFirstLetter)
                S1[i] = static_cast<char>(toupper(static_cast<unsigned char>(S1[i])));
            isFirstLetter = (S1[i] == ' ');
        }
        return S1;
    }

    string UppFirstLetterOfEachWord()
    {
        return UppFirstLetterOfEachWord(_Value);
    }

    static string LowFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (size_t i = 0; i < S1.length(); ++i)
        {
            if (S1[i] != ' ' && isFirstLetter)
                S1[i] = static_cast<char>(tolower(static_cast<unsigned char>(S1[i])));
            isFirstLetter = (S1[i] == ' ');
        }
        return S1;
    }

    string LowFirstLetterOfEachWord()
    {
        return LowFirstLetterOfEachWord(_Value);
    }

    // -------------------------
    // Whole string upper/lower
    // -------------------------
    static string LowLettersOfEachWord(string S1)
    {
        for (char& c : S1)
            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        return S1;
    }

    string LowLettersOfEachWord()
    {
        return LowLettersOfEachWord(_Value);
    }

    static string UppLettersOfEachWord(string S1)
    {
        for (char& c : S1)
            c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
        return S1;
    }

    string UppLettersOfEachWord()
    {
        return UppLettersOfEachWord(_Value);
    }

    // invert case whole string
    static string invertCase(string S1)
    {
        for (char& c : S1)
            c = invertCaseChar(c);
        return S1;
    }

    string invertCase()
    {
        return invertCase(_Value);
    }

    // -------------------------
    // Counts
    // -------------------------
    static int CountCapitalLetters(const string& str)
    {
        int count = 0;
        for (unsigned char ch : str)
            if (isupper(ch)) ++count;
        return count;
    }

    int CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    static int CountSmallLetters(const string& str)
    {
        int count = 0;
        for (unsigned char ch : str)
            if (islower(ch)) ++count;
        return count;
    }

    int CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    static int countNumberOfLetters(const string& str, char Record)
    {
        int count = 0;
        for (char c : str)
            if (c == Record) ++count;
        return count;
    }

    int countNumberOfLetters()
    {
        return countNumberOfLetters(_Value, _Record);
    }

    static int countNumberOfAllLetters(const string& str, char Record)
    {
        int count = 0;
        for (char c : str)
            if (static_cast<char>(tolower(static_cast<unsigned char>(c))) == static_cast<char>(tolower(static_cast<unsigned char>(Record))))
                ++count;
        return count;
    }

    int countNumberOfAllLetters()
    {
        return countNumberOfAllLetters(_Value, _Record);
    }

    // -------------------------
    // Vowels
    // -------------------------
    static bool IsVowel(char Ch1)
    {
        char c = static_cast<char>(tolower(static_cast<unsigned char>(Ch1)));
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    bool IsVowel()
    {
        return IsVowel(_Record);
    }

    static int CountVowels(const string& S1)
    {
        int count = 0;
        for (char c : S1)
            if (IsVowel(c)) ++count;
        return count;
    }

    int CountVowels()
    {
        return CountVowels(_Value);
    }

    static void PrintVowels(const string& S1)
    {
        cout << "\nVowels in string are: ";
        for (char c : S1)
            if (IsVowel(c)) cout << c << " ";
        cout << endl;
    }

    void PrintVowels()
    {
        PrintVowels(_Value);
    }

    // -------------------------
    // Print words using string functions
    // -------------------------
    static void PrintWordsInStringWithStringFun(string S1)
    {
        size_t pos = 0;
        const string deline = " ";
        string SWord;

        cout << "\nWords in string are: \n";

        while ((pos = S1.find(deline)) != string::npos)
        {
            SWord = S1.substr(0, pos);

            if (!SWord.empty() && SWord != " ")
                cout << SWord << endl;

            S1.erase(0, pos + deline.length());
        }

        if (!S1.empty() && S1 != " ")
        {
            cout << S1 << endl;
        }
    }

    void PrintWordsInStringWithStringFun()
    {
        PrintWordsInStringWithStringFun(_Value);
    }

    // -------------------------
    // Count words
    // -------------------------
    static int CountEachWordsInString(string S1)
    {
        // Use SplitEachWordsInString for more robustness
        return static_cast<int>(SplitEachWordsInString(S1, " ").size());
    }

    int CountEachWordsInString()
    {
        return CountEachWordsInString(_Value);
    }

    // -------------------------
    // Split
    // -------------------------
    static vector<string> SplitEachWordsInString(string S1, const string& Limit)
    {
        vector<string> sSplit;
        size_t pos = 0;

        if (Limit.empty()) {
            // no splitting possibility -> whole string
            if (!S1.empty()) sSplit.push_back(S1);
            return sSplit;
        }

        while ((pos = S1.find(Limit)) != string::npos)
        {
            string SWord = S1.substr(0, pos);
            if (!SWord.empty())
                sSplit.push_back(SWord);
            S1.erase(0, pos + Limit.length());
        }

        if (!S1.empty())
            sSplit.push_back(S1);

        return sSplit;
    }

    vector<string> SplitEachWordsInString()
    {
        return SplitEachWordsInString(_Value, " ");
    }

    // -------------------------
    // Print vector
    // -------------------------
    static void printVector(const vector<string>& sSplit)
    {
        for (const string& i : sSplit)
            cout << i << endl;
    }

    void printVector()
    {
        printVector(_sSplit);
    }

    // -------------------------
    // Trim functions
    // -------------------------
    static string TrimLeft(const string& S1)
    {
        size_t i = 0;
        while (i < S1.length() && S1[i] == ' ')
            ++i;
        return S1.substr(i);
    }

    string TrimLeft()
    {
        return TrimLeft(_Value);
    }

    static string TrimRight(const string& S1)
    {
        if (S1.empty()) return string();
        size_t i = S1.length();
        // move i to first non-space from right
        while (i > 0 && S1[i - 1] == ' ')
            --i;
        return S1.substr(0, i);
    }

    string TrimRight()
    {
        return TrimRight(_Value);
    }

    static string Trim(const string& S1)
    {
        return TrimLeft(TrimRight(S1));
    }

    string Trim()
    {
        return Trim(_Value);
    }

    static void PrintTrim(const string& S1)
    {
        cout << "\nString     = [" << S1 << "]";
        cout << "\nTrim Left  = [" << TrimLeft(S1) << "]";
        cout << "\nTrim Right = [" << TrimRight(S1) << "]";
        cout << "\nTrim       = [" << Trim(S1) << "]";
    }

    void PrintTrim()
    {
        PrintTrim(_Value);
    }

    // -------------------------
    // Join & Reverse Words
    // -------------------------
    static string JoinString(const vector<string>& vString, const string& Limit)
    {
        if (vString.empty()) return string();
        string S;
        S.reserve(64);
        for (size_t i = 0; i < vString.size(); ++i)
        {
            S += vString[i];
            if (i + 1 < vString.size())
                S += Limit;
        }
        return S;
    }

    string JoinString()
    {
        // default join with " , " like original idea
        return JoinString(_sSplit, " , ");
    }

    static string ReverseWords(const string& S1)
    {
        vector<string> vSplit = SplitEachWordsInString(S1, " ");
        string S2;
        for (auto it = vSplit.rbegin(); it != vSplit.rend(); ++it)
        {
            if (!S2.empty()) S2 += " ";
            S2 += *it;
        }
        return S2;
    }

    string ReverseWords()
    {
        return ReverseWords(_Value);
    }

    // -------------------------
    // Replace methods
    // -------------------------
    static string ReplaceWordInStringUsingBuiltInFunction(string S1, const string& StringToReplace, const string& sReplaceTo)
    {
        if (StringToReplace.empty()) return S1; // avoid infinite loop
        size_t pos = S1.find(StringToReplace, 0);

        while (pos != string::npos)
        {
            S1.replace(pos, StringToReplace.length(), sReplaceTo);
            pos = S1.find(StringToReplace, pos + sReplaceTo.length());
        }

        return S1;
    }

    string ReplaceWordInStringUsingBuiltInFunction()
    {
        return ReplaceWordInStringUsingBuiltInFunction(_Value, _StringToReplace, _sReplaceTo);
    }

    static string ReplaceWordInStringUsingSplit(string S1, const string& StringToReplace, const string& ReplaceTo, bool matchCases = true)
    {
        vector<string> vSplit = SplitEachWordsInString(S1, " ");

        if (matchCases)
        {
            for (string& token : vSplit)
            {
                if (token == StringToReplace) token = ReplaceTo;
            }
        }
        else
        {
            string lowTarget = LowLettersOfEachWord(StringToReplace);
            for (string& token : vSplit)
            {
                if (LowLettersOfEachWord(token) == lowTarget)
                    token = ReplaceTo;
            }
        }

        return JoinString(vSplit, " ");
    }

    string ReplaceWordInStringUsingSplit()
    {
        return ReplaceWordInStringUsingSplit(_Value, _StringToReplace, _sReplaceTo);
    }

    // -------------------------
    // Remove punctuations
    // -------------------------
    static string RemovePunctuations(const string& S1)
    {
        string S2;
        S2.reserve(S1.size());
        for (unsigned char c : S1)
        {
            if (!ispunct(c))
                S2.push_back(static_cast<char>(c));
        }
        return S2;
    }

    string RemovePunctuations()
    {
        return RemovePunctuations(_Value);
    }

    // -------------------------
    // Additional helpers (if wanted)
    // -------------------------
    // You can add more utility wrappers here that operate on _Value
};

