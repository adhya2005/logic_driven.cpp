#include <iostream>
#include "ucm_utils.h"
using namespace std;

int main() {
    string firstName, lastName, email;
    int age;

    showHeading();
    progess(0);
    cout << "Enter your first name: ";
    getline(cin, firstName);

    showHeading();
    progess(25);
    cout << "Enter your last name: ";
    getline(cin, lastName);
    

    showHeading();
    progess(50);
    cout << "Enter your age: ";
    cin >> age;

    showHeading();
    progess(75);
    cout << "Enter your email: ";
    cin.ignore();
    getline(cin, email);

    showHeading();
    progess(75);
    printCard(firstName, lastName,  email, age);

    return 0;
}