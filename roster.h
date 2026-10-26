#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

class Roster {
private: static const int NUM_STUDENTS = 5;
    Student* classRosterArray[NUM_STUDENTS];
    int lastIndex = -1;
public:
    Roster();
    ~Roster();
    void parse(const std::string& row);
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
        int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif
