#pragma once
#include"Student.h"
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<sstream>
using namespace std;

class Menu
{
public:
	Student student;
	vector <Student>studentInfo;
	string input="0";
	bool islogged = false;
	string select ;
	void welcome();
	void LoginA();
	void tabs();
	void Login();
	static Menu& getInstance();
	Menu();
	~Menu();
};

