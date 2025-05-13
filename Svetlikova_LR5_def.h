#ifndef SVETLIKOVA_LR_5_6_DEF_H
#define SVETLIKOVA_LR_5_6_DEF_H
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <sstream>
#include <map>
#include <cctype>

using namespace std;
// проверяет чтобы не ввели букву или пустую строку
bool user_input(string input) {
	if (input.empty()) return false;
    for (char c : input) {
        if (isalpha(c)) { // isalpha проверяет, является ли символ буквой
            return false;
        }
    }
	try {
		int number = stold(input);
		// if (number < 0) return false;
	}
	catch (...) 
	{ return false; }
	return true;
}
//для менюшки берем лямбда-функцию, тк она напрямую с вводом взаимодействует
function<void()> enter_number(istream&mystream,int& varLink, const string& label) {
    return [&varLink, label]() {
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);

        while (!user_input(raw_input)) {
            cout << "Некорректный ввод. Пожалуйста, введите положительное целое число: " << label << " = "<<endl;
            getline(cin, raw_input);
        }
        varLink = stoi(raw_input); 
    };
}

function<void()> enter_double(istream&mystream,int& varLink, const string& label) {
    return [&varLink, label]() {
        string raw_input;
        cout << label << " = ";
        getline(cin, raw_input);

        while (!user_input(raw_input)) {
            cout << "Некорректный ввод. Пожалуйста, введите положительное число: " << label << " = "<<endl;
            getline(cin, raw_input);
        }
        varLink = stod(raw_input); 
    };
}

function<void()> enter_string(istream&mystream,string& varLink, string label) {
    return [&varLink, label]() {
		cout << label << " = ";
        getline(cin, varLink);
    };
}



#endif