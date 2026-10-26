#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"
using namespace std;

class Student {
public:
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, const int numDays[], DegreeProgram degreeProgram);

    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    const int* getNumDays() const;
    DegreeProgram getDegreeProgram() const;

    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setNumDays(const int numDays[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    void print() const;

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numDays[3];
    DegreeProgram degreeProgram;
};

#endif
