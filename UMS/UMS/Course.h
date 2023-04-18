#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<memory>
#include<map>
#include<fstream>
using namespace std;

class Course
{
public:
	string name;
	char hours;
	void getCourseInfo();
	Course();
	~Course();
};

