#pragma once
#include "Course.h"
#include "Student.h"
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
using namespace std;

class Admin
{
private:
	string username="Admin";
	string password="Admin123";

public:
	Student student;
	Course courses;
	vector<Course>courseInfo;
	vector<Student>studentInfo;
	string getUsername();
	string getPassword();
	static Admin& getInstance();
	void addCourse();
	void deleteCourse();
	void addStudent();
	Admin();
	~Admin();
};

