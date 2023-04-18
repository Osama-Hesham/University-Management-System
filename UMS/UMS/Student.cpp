#include "Student.h"

Student::Student(){}
Student::~Student(){}

string Student::getName()
{
	return name;
}

string Student::getID()
{
	return ID;
}
string Student::getPassword()
{
	return password;
}
void Student::getInfo()
{
	cout << "Student ID: " << ID << "\t\Student Name: " << name <<"\n";
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::setID(string ID)
{
	this->ID = ID;
}

void Student::setPassword(string password)
{
	this->password = password;
}

float Student::calcGPA()
{
	return GPA;
}

float Student::calcFees()
{
	return Fees;
}

