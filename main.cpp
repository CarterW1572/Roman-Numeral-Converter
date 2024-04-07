#include "Scanner.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    ifstream file(argv[1]);
    string line;
    vector<string> numerals;
    while (getline(file, line)) {
        numerals.push_back(line);
    }
    Scanner scan(numerals);
    vector<int> numbers = scan.numeralsToDecimals();
    cout << "Decimal Conversions:" << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers.at(i) << endl;
    }
    cout << endl;
    vector<string> newNumerals = scan.decimalsToNumerals(numbers);
    cout << "Roman Numeral Conversions:" << endl;
    for (int i = 0; i < newNumerals.size(); i++) {
        cout << newNumerals.at(i) << endl;
    }
    return 0;
}
