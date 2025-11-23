//
//  main.cpp
//  AOngomefen_Pr2.cpp
//
//  Created by Andrea 👾 on 10/10/23.
//
/*
 * Class: CMSC140 CRN
 * Instructor:
 * Project<4>
 * Description: (Give a brief description for Project)
 * Due Date:
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Andrea Ongomefen
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    double temp;
    double distance;
    double weight;
    int choice;
    string country;
    
    cout << "Enter a Country Name: " << endl;
    getline(cin, country);
    
    cout << "Converter Toolkit" << endl;
    cout << "------------------" << endl;
    cout << "1. Temperature Converter" << endl;
    cout << "2. Distance Converter" << endl;
    cout << "3. Weight Converter" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter Your Choice (1-4): " << endl;
        
    cin >> choice;
    
    if (choice > 0 && choice <= 4 ) {
        
        switch (choice) {
                
            case 1: // temperature conversion and message
                cout << "please enter temperature in Celsius (such as 24): " << endl;
                cin >> temp;
                temp = 1.8 * temp + 32;
                
                cout << "it is " << setprecision(0) << fixed << temp << " in Fahrenheit\n";
                    break;
            
            case 2: // distance conversion and message
                cout << "please enter distance in Kilometers: " << endl;
                cin >> distance;
                
                if (distance > 0){
                    distance = distance * .6;
                    cout << "it is " << setprecision(2) << fixed << distance << " in Miles\n";
                }
                else {
                    cout << "!!! Program does not convert negative distance !!!" << endl;
                }
                    break;
            
            case 3: // weight conversion and message
                cout << "please enter weight in Kilograms: " << endl;
                cin >> weight;
                
                if (weight > 0) {
                    weight = weight * 2.2;
                    cout << "it is " << setprecision(1) << fixed << weight << " in Pounds\n";
                }
                else {
                    cout << "!!! Program does not convert negative weight !!!" << endl;
                }
                    break;
            
            case 4:
                cout << "You quit :(" << endl;
            
            default:
                break;
        }
    }
    else {
        cout << "your input is not valid" << endl;
    } // if input is not 1-4
   
    cout << country << " sounds fun!\n";
    
    cout << "" << endl;
    cout << "Thank You for testing my program !!\n";
    cout << "PROGRAMMER: Andrea Ongomefen\n";
    cout << "CMCS140 Common Project 2\n";
    cout << "Due Date: 9/15/2023\n";
    
    return 0;
}
