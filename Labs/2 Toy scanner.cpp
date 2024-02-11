#include <iostream>
#include <regex>
#include <string>
/*Siyue You*/
using namespace std;

int main() {
    string token;
    cout << "Enter a token: ";
    cin >> token;

    // Regex to match integer numbers, allowing an optional leading '+' sign
    regex integer_regex("^[+]?[0-9]+$");

    // Extended to match floating-point numbers, allowing optional leading '+', optional decimal part
    regex float_regex("^[+]?[0-9]*\\.?[0-9]+$");

    // Expanded to include a broader range of punctuation characters
    regex punctuation_regex("^[+*(),.;:/-]$");

    // Matching integer numbers
    if (regex_match(token, integer_regex)) {
        cout << "number (integer)" << endl;
    }
    // Matching floating-point numbers
    else if (regex_match(token, float_regex)) {
        cout << "number (floating-point)" << endl;
    }
    // Matching punctuation
    else if (regex_match(token, punctuation_regex)) {
        cout << "punctuation" << endl;
    }
    // Token doesn't match any of the above categories
    else {
        cout << "unknown" << endl;
    }

    return 0;
}

