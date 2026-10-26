#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

static string trim(const string& s) {
    size_t first = s.find_first_not_of(' ');
    if (first == string::npos) return "";
    size_t last = s.find_last_not_of(' ');
    return s.substr(first, last-first +1);
}

Roster::Roster() {
    for (int i=0; i < NUM_STUDENTS; i++) {
        classRosterArray[i] = nullptr;
    }
}

void Roster::parse(const string& row) {
    string fields[9];
    size_t start = 0;

for (int i = 0; i < 8; i++) {
    size_t end = row.find(',', start);
    fields[i] = trim(row.substr(start, end-start));
    start = end+1;
}
fields[8] = trim(row.substr(start));

DegreeProgram degree = SOFTWARE;
if (fields[8] == "SECURITY") degree = SECURITY;
else if (fields[8] == "NETWORK") degree = NETWORK;
else if (fields[8] == "SOFTWARE") degree = SOFTWARE;

add(fields[0], fields[1], fields[2], fields[3], stoi(fields[4]),
    stoi(fields[5]), stoi(fields[6]), stoi(fields[7]), degree);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
                    int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    if (lastIndex + 1 >= NUM_STUDENTS) return;

    int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    lastIndex++;
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
}

void Roster::remove(string studentID) {
    for (int i = 0; i<= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            for (int j = i; j < lastIndex; j++) {
                classRosterArray[j] = classRosterArray[j+1];
            }
            classRosterArray[lastIndex] = nullptr;
            lastIndex--;
            return;
        }
    }
    cout << "Error: Student with ID " << studentID << " was not found." << endl;
}


void Roster::printAll() {
    for (int i = 0; i <= lastIndex; i++) {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            const int* days = classRosterArray[i]->getNumDays();
            double average = (days[0] + days[1] + days[2]) / 3.0;
            cout << "Average days in course for " << studentID << ": " << average << endl;
            return;
        }
    }
    cout << "Error: Student with ID " << studentID << " was not found." << endl;
}

void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; i++) {
        string email = classRosterArray[i]->getEmailAddress();
        bool hasAt = email.find('@') != string::npos;
        bool hasPeriod = email.find('.') != string::npos;
        bool hasSpace = email.find(' ') != string::npos;
        if (!hasAt || !hasPeriod || hasSpace) {
            cout << "Invalid Email: " << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}