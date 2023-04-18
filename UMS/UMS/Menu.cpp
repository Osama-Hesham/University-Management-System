#include "Menu.h"

Menu::Menu(){ cout << "\t\t\t\tWELCOME TO UNIVERSITY MANAGEMENT SYSTEM\n\n"; }
Menu::~Menu(){}

void Menu::welcome()
{
	cout << "IF YOU ARE AN ADMIN THEN INSERT 1, IF YOU ARE STUDENT THEN INSERT 2: ";
	cin >> input;
}

void Menu::LoginA()
{
	string user;
	string pw;
	cout << "\nPlease Enter The Username: ";
	cin >> user;
	cout << "Please Enter The Password: ";
	cin >> pw;
	if (user != "Admin" || pw != "Admin123") {
		cout << "\nInvalid Username or Password. Try Again\n";
		LoginA();
	}
	else {
		cout << "You have logged in successfully-----------------------------------------\n\n";
		islogged = true;
	}
}
void Menu::Login()
{

	//fstream myStudents("StudentsID.txt", ios::in);
	//string line;
	//string line1;
	//string line2;
	int index = 0;
	bool found = false;
	string id;
	string pw;
	cout << "\nPlease Enter Your ID: ";
	cin >> id;

	//while (getline(myStudents, line)) {
	//	stringstream ss(line);
	//	getline(ss, line1, ',');
	//	if (id == line1) {
	//		found = true;		
	//	}
	//	getline(ss, line2, ',');
	//	if (line2 == " "&&found) {
	//		cout << "Please Enter Your NEW Password: ";
	//		cin >> pw;
	//		line2 = pw;
	//		break;
	//	}
	//}

	//myStudents.close();
	//if (!found) {
	//	cout << "Student does not exist. Try Again\n";
	//	Login();
	//	return void();
	//}
	cout << "Please Enter Your Password: ";
	cin >> pw;

	if (id != "a" || pw != "a") {
		cout << "\nInvalid Username or Password. Try Again\n";
		Login();
	}
	else {
		cout << "You have logged in successfully-----------------------------------------\n\n";
		islogged = true;
	}
}
void Menu::tabs()
{
	if (input == "1") {
		cout << "1- Insert new Student\n";
		cout << "2- View Student Info\n";
		cout << "3- Insert new Course\n";
		cout << "4- View Courses Info\n";
		cout << "5- Delete Course\n";
		cout << "0- Logout\n\n";
		cout << "Insert a number to proceed: ";
		cin >> select;
	}
	else if(input == "2") {
		cout << "1- My Information\n";
		cout << "2- My Courses\n";
		cout << "3- Enroll to Course\n";
		cout << "4- My Grades\n";
		cout << "5- Fees\n";
		cout << "0- Logout\n\n";
		cout << "Insert a number to proceed: ";
		cin >> select;
	}
}
Menu& Menu::getInstance() {
	static Menu instance;
	return instance;
}
