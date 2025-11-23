//
//  main.cpp
//  AOngomefen_Pr2.cpp
//
//  Improved: adds input validation, looped menu, accurate conversion constants,
//  and extraction of conversion logic into small functions.
//
//  Created by Andrea 👾 on 10/10/23.
//  Updated by assistant on 2025-11-23
//
/*
 * Project<4>
 * Description: Simple menu-driven Unit Converter with improved validation and UX.
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Andrea Ongomefen
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <stdexcept>

using namespace std;

constexpr double KM_TO_MI = 0.621371;
constexpr double KG_TO_LB = 2.20462;

double celsiusToFahrenheit(double c) {
    return c * 9.0 / 5.0 + 32.0;
}

double kmToMiles(double km) {
    return km * KM_TO_MI;
}

double kgToPounds(double kg) {
    return kg * KG_TO_LB;
}

// Read a line from stdin and try to parse it as double.
// Returns {true, value} on success, {false, 0.0} on EOF/error.
pair<bool, double> readDouble(const string &prompt) {
    while (true) {
        cout << prompt;
        string line;
        if (!getline(cin, line)) return {false, 0.0}; // EOF or error
        try {
            size_t idx = 0;
            double value = stod(line, &idx);
            // allow trailing whitespace only
            while (idx < line.size() && isspace(static_cast<unsigned char>(line[idx]))) ++idx;
            if (idx != line.size()) throw invalid_argument("trailing characters");
            return {true, value};
        } catch (...) {
            cout << "Invalid number, please try again.\n";
        }
    }
}

int main() {
    string country;
    cout << "Enter a Country Name: ";
    getline(cin, country);

    while (true) {
        cout << "\nConverter Toolkit\n";
        cout << "------------------\n";
        cout << "1. Temperature: Celsius -> Fahrenheit\n";
        cout << "2. Distance: Kilometers -> Miles\n";
        cout << "3. Weight: Kilograms -> Pounds\n";
        cout << "4. Quit\n";
        cout << "Enter Your Choice (1-4): ";

        string choiceLine;
        if (!getline(cin, choiceLine)) break; // EOF

        int choice = 0;
        try {
            size_t idx = 0;
            choice = stoi(choiceLine, &idx);
            while (idx < choiceLine.size() && isspace(static_cast<unsigned char>(choiceLine[idx]))) ++idx;
            if (idx != choiceLine.size()) throw invalid_argument("trailing characters");
        } catch (...) {
            cout << "Invalid menu choice. Please enter a number between 1 and 4.\n";
            continue;
        }

        if (choice < 1 || choice > 4) {
            cout << "Choice out of range. Please enter 1-4.\n";
            continue;
        }

        if (choice == 4) {
            cout << "You quit :(. \n";
            break;
        }

        switch (choice) {
            case 1: {
                auto [ok, tempC] = readDouble("Please enter temperature in Celsius (e.g. 24): ");
                if (!ok) { cout << "Input error. Returning to menu.\n"; break; }
                double f = celsiusToFahrenheit(tempC);
                cout << fixed << setprecision(1);
                cout << tempC << " °C = " << f << " °F\n";
                break;
            }

            case 2: {
                auto [ok, km] = readDouble("Please enter distance in Kilometers: ");
                if (!ok) { cout << "Input error. Returning to menu.\n"; break; }
                if (km < 0) {
                    cout << "!!! Program does not convert negative distance !!!\n";
                } else {
                    double mi = kmToMiles(km);
                    cout << fixed << setprecision(2);
                    cout << km << " km = " << mi << " mi\n";
                }
                break;
            }

            case 3: {
                auto [ok, kg] = readDouble("Please enter weight in Kilograms: ");
                if (!ok) { cout << "Input error. Returning to menu.\n"; break; }
                if (kg < 0) {
                    cout << "!!! Program does not convert negative weight !!!\n";
                } else {
                    double lb = kgToPounds(kg);
                    cout << fixed << setprecision(2);
                    cout << kg << " kg = " << lb << " lb\n";
                }
                break;
            }

            default:
                // unreachable due to validation above
                break;
        }
    }

    cout << "\n" << country << " sounds fun!\n";
    cout << "\nThank You for testing my program !!\n";
    cout << "PROGRAMMER: Andrea Ongomefen\n";
    cout << "CMCS140 Common Project 2\n";
    cout << "Due Date: 9/15/2023\n";

    return 0;
}
