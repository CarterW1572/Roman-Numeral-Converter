#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Scanner {
public:
    Scanner(vector<string> input) : input(input) {
        valid = true;
    }
    ~Scanner() {}

    // Loops through input strings and runs scan function on each one
    vector<int> numeralsToDecimals() {
        for (int i = 0; i < input.size(); i++) {
            output.push_back(scanNumeral(input.at(i)));
        }
        if (valid == false) {
            cout << "Some numerals you input were invalid.\nInvalid numerals are represented by -1." << endl;
        }
        return output;
    }

    // Loops through input decimals and runs scan function on each one
    vector<string> decimalsToNumerals(vector<int> decimals) {
        vector<string> newNumerals;
        for (int i = 0; i < decimals.size(); i++) {
            newNumerals.push_back(scanDecimal(decimals.at(i)));
        }
        return newNumerals;
    }

    // Scans strings and converts them into decimals
    int scanNumeral(string numeral) {
        int sum = 0;
        int max = 2000;
        for (int i = 0; i < numeral.size(); i++) {
            if (i+1 < numeral.size()) {
                if (numeral.at(i) == 'M') {
                    if (max >= 1000) { // checks if M is valid at this piont
                        sum += 1000; // each M adds 1000
                        max = 1000;
                    }
                    else { // if M is invalid, valid is set to false, the sum is -1, and it breaks the loop
                        valid = false;
                        sum = -1;
                        break;
                    }
                }
                else if (numeral.at(i) == 'D') { // the same logic is used for all the other Roman numerals
                    if (max >= 500) {
                        sum += 500;
                        max = 500;
                    }
                    else {
                        valid = false;
                        sum = -1;
                        break;
                    }
                }
                else if (numeral.at(i) == 'C') {
                    if (max >= 100) {
                        if (numeral.at(i + 1) == 'M') {
                            if (max >= 1000) {
                                sum += 900;
                                i++;
                            }
                            else {
                                valid = false;
                                sum = -1;
                                break;
                            }
                        }
                        else if (numeral.at(i + 1) == 'D') {
                            if (max > 500) {
                                sum += 400;
                                i++;
                            }
                            else {
                                valid = false;
                                sum = -1;
                                break;
                            }
                        }
                        else {
                            sum += 100;
                        }
                        max = 100;
                    }
                    else {
                        valid = false;
                        sum = -1;
                        break;
                    }
                }
                else if (numeral.at(i) == 'L') {
                    if (max >= 50) {
                        sum += 50;
                        max = 50;
                    }
                    else {
                        valid = false;
                        sum = -1;
                        break;
                    }
                }
                else if (numeral.at(i) == 'X') {
                    if (max >= 10) {
                        if (numeral.at(i + 1) == 'C') {
                            if (max >= 100) {
                                sum += 90;
                                i++;
                            }
                            else {
                                valid = false;
                                sum = -1;
                                break;
                            }
                        }
                        else if (numeral.at(i + 1) == 'L') {
                            if (max > 50) {
                                sum += 40;
                                i++;
                            }
                            else {
                                valid = false;
                                sum = -1;
                                break;
                            }
                        }
                        else {
                            sum += 10;
                        }
                        max = 10;
                    }
                    else {
                        valid = false;
                        sum = -1;
                        break;
                    }
                }
                else if (numeral.at(i) == 'V') {
                    if (max >= 5) {
                        sum += 5;
                        max = 5;
                    }
                    else {
                        valid = false;
                        sum = -1;
                        break;
                    }
                }
                else if (numeral.at(i) == 'I') {
                    if (numeral.at(i + 1) == 'X') {
                        if (max >= 10) {
                            sum += 9;
                            i++;
                        }
                        else {
                            valid = false;
                            sum = -1;
                            break;
                        }
                    }
                    else if (numeral.at(i + 1) == 'V') {
                        if (max > 5) {
                            sum += 4;
                            i++;
                        }
                        else {
                            valid = false;
                            sum = -1;
                            break;
                        }
                    }
                    else {
                        sum += 1;
                    }
                    max = 1;
                }
                else if (isspace(numeral.at(i))) {
                    break;
                }
                else {
                    valid = false;
                    sum = -1;
                    break;
                }
            }
            else {
                if (numeral.at(i) == 'M') {
                    if (max >= 1000) {
                        sum += 1000;
                    }
                    else {
                        valid = false;
                        sum = -1;
                        break;
                    }
                }
                else if (numeral.at(i) == 'D') {
                    if (max >= 500) {
                        sum += 500;
                    }
                    else {
                        valid = false;
                        sum = -1;
                        break;
                    }
                }
                else if (numeral.at(i) == 'C') {
                    if (max >= 100) {
                        sum += 100;
                    }
                    else {
                        valid = false;
                        sum = -1;
                        break;
                    }
                }
                else if (numeral.at(i) == 'L') {
                    if (max >= 50) {
                        sum += 50;
                    }
                    else {
                        valid = false;
                        sum = -1;
                        break;
                    }
                }
                else if (numeral.at(i) == 'X') {
                    if (max >= 10) {
                        sum += 10;
                    }
                    else {
                        valid = false;
                        sum = -1;
                        break;
                    }
                }
                else if (numeral.at(i) == 'V') {
                    if (max >= 5) {
                        sum += 5;
                    }
                    else {
                        valid = false;
                        sum = -1;
                        break;
                    }
                }
                else if (numeral.at(i) == 'I') {
                    sum += 1;
                }
                else if (isspace(numeral.at(i))){
                    break;
                }
                else {
                    valid = false;
                    sum = -1;
                    break;
                }
            }
        }
        return sum;
    }

    // Scans decimals and converts them into strings
    string scanDecimal(int decimal) {
        string numeral;
        int num;
        if (decimal <= 0) {
            return "INVALID";
        }
        if (decimal >= 1000) {
            num = decimal/1000;
            for (int i = 0; i < num; i++) {
                numeral.append("M");
            }
            decimal -= num*1000;
        }
        if (decimal >= 900) {
            numeral.append("CM");
            decimal -= 900;
        }
        if (decimal >= 500) {
            numeral.append("D");
            decimal -= 500;
        }
        if (decimal >= 100) {
            num = decimal/100;
            if (num <= 3) {
                for (int i = 0; i < num; i++) {
                    numeral.append("C");
                }
            }
            else {
                numeral.append("CD");
            }
            decimal -= num*100;
        }
        if (decimal >= 90) {
            numeral.append("XC");
            decimal -= 90;
        }
        if (decimal >= 50) {
            numeral.append("L");
            decimal -= 50;
        }
        if (decimal >= 10) {
            num = decimal/10;
            if (num <= 3) {
                for (int i = 0; i < num; i++) {
                    numeral.append("X");
                }
            }
            else {
                numeral.append("XL");
            }
            decimal -= num*10;
        }
        if (decimal >= 9) {
            numeral.append("IX");
            decimal -= 9;
        }
        if (decimal >= 5) {
            numeral.append("V");
            decimal -= 5;
        }
        if (decimal >= 1) {
            if (decimal <= 3) {
                for (int i = 0; i < decimal; i++) {
                    numeral.append("I");
                }
            }
            else {
                numeral.append("IV");
            }
            decimal -= decimal;
        }
        return numeral;
    }

private:
    vector<string> input; // input vector of Roman numerals
    vector<int> output; // output of decimals
    bool valid; // if invalid numerals are entered, this is set to true
};