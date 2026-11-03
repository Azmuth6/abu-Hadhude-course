#include <iostream>
#include <string>
using namespace std;

string TrimLeft(string S1) {
    for (size_t i = 0; i < S1.length(); i++) {
        if (S1[i] != ' ')
            return S1.substr(i, S1.length() - i); //  علشان مش يرجع ل الاتحذف ف هيكون فاضي بالنسبه  ليه  
    }
    return "";
}

string TrimRight(string S1) {
    for (int i = (int)S1.length() - 1; i >= 0; i--) {
        if (S1[i] != ' ')
            return S1.substr(0, i + 1); //هو طرح 1 ف ضفناه علشان ترجعه 
    }
    return "";
}

string Trim(string S1) {
    return TrimLeft(TrimRight(S1));
}

int main() {
    string S1 = "      Mohammed Abu-Hahdoud      ";

    cout << "\nString     = [" << S1 << "]";
    cout << "\n\nTrim Left  = [" << TrimLeft(S1) << "]";
    cout << "\nTrim Right = [" << TrimRight(S1) << "]";
    cout << "\nTrim       = [" << Trim(S1) << "]";

    system("pause>0");
}
