#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {
    cout << "C867 Scripting and Programming -Applications, C++" << endl;
    cout << "Ashlee Gonzales" << endl;
    cout << "Student ID: 013151855" << endl;
    
    const string studentData[] =

    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",

    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",

    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",

    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",

    "A5,Ashlee,Gonzales,agonz656@wgu.edu,29,30,60,33, SOFTWARE"
    };

    Roster classRoster;
        for (const string& row : studentData) {
            classRoster.parse(row);
        }


    return 0;
}
