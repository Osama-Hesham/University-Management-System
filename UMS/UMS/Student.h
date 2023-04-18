#pragma once
#include"Course.h"
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
using namespace std;

class Student
{
private:
	string ID;
	string password=" ";
	string name;
	Course courses;
	vector<Course>courseInfo;
	float GPA=0;
	float Fees=0;
public:
	string getName();
	string getID();
	string getPassword();
	void setName(string name);
	void setID(string ID);
	void setPassword(string password);
	float calcGPA();
	float calcFees();
	void getInfo();
	Student();
	~Student();

};

