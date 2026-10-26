#include <iostream>
#include <string>
using namespace std;
#include "student.h"

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, const int numDays[], DegreeProgram degreeProgram) {
    setStudentID(studentID);
    setFirstName(firstName);
    setLastName(lastName);
    setEmailAddress(emailAddress);
    setAge(age);
    setNumDays(numDays);
    setDegreeProgram(degreeProgram);
}

string Student::getStudentID() const {
    return studentID;
}
string Student::getFirstName() const {
    return firstName;
}
string Student::getLastName() const {
    return lastName;
}
string Student::getEmailAddress() const {
    return emailAddress;
}
int Student::getAge() const {
    return age;
}
const int* Student::getNumDays() const {
    return numDays;
}
DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
    this->age = age;
}
void Student::setNumDays(const int numDays[]) {
    for (int i=0; i<3; i++) {
        this->numDays = numDays;
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

void Student::print() const {
    static const string degreeNames[] = {"Security", "Network","Software"};
    cout << studentID << "\t"
    << "First Name: " << firstName << "\t"
    << "Last Name: " << lastName << "\t"
    << "Email: " << emailAddress << "\t"
    << "Age: " << age << "\t"
    << "daysInCourse: {" << numDays[0] << ", " <<numDays[1] << ", " << numDays[2] << "} "
    << "Degree Program: " <<  degreeNames[degreeProgram] << endl;
}


