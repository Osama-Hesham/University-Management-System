#include "Admin.h"
#include "Menu.h"
#include "Course.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Admin &admin = Admin::getInstance();
	Menu &menu = Menu::getInstance();

	while (true) {
		if(menu.input=="0")
		menu.welcome();
		if (menu.input == "1") {
			if(!menu.islogged)
				menu.LoginA();
			menu.tabs();	
				if (menu.select == "3") {
					admin.addCourse();
					menu.select = '-1';
				}
				else if (menu.select == "1") {
					admin.addStudent();
					menu.select = '-1';
				}
				else if (menu.select == "4") {
					if (admin.courseInfo.size() == 0) {
						cout << "No Courses Available\n";
					}
					else {
						for (size_t i = 0; i < admin.courseInfo.size(); i++)
						{
							cout << i + 1 << "- ";
							admin.courseInfo[i].getCourseInfo();
						}
					}
					cout << "--------------------------------------------------\n";
				}
				else if (menu.select == "5") {
					admin.deleteCourse();
					cout << "--------------------------------------------------\n";
				}
				else if (menu.select == "2") {
					if (admin.studentInfo.size() == 0) {
						cout << "No Students Available\n";
					}
					else {
						for (size_t i = 0; i < admin.studentInfo.size(); i++)
						{
							cout << i + 1 << "- ";
							admin.studentInfo[i].getInfo();
						}
					}
					cout << "--------------------------------------------------\n";
				}
				else if (menu.select == "0") {
					cout << "Logged Out Successfully---------------------------------------------------------------------------------\n\n";
					cout << "\t\t\t\tWELCOME TO UNIVERSITY MANAGEMENT SYSTEM\n\n";
					menu.islogged = false;
					menu.input = "0";
					continue;
				}			
		}

		else if (menu.input == "2") {
			if (!menu.islogged)
				menu.Login();
			menu.tabs();
			if (menu.select == "1") {
				
				menu.select = '-1';
			}
			else if (menu.select == "2") {
				
				menu.select = '-1';
			}
			else if (menu.select == "3") {
				
			}
			else if (menu.select == "4") {
				
			}
			else if (menu.select == "5") {
				
			}
			else if (menu.select == "0") {
				cout << "Logged Out Successfully---------------------------------------------------------------------------------\n\n";
				cout << "\t\t\t\tWELCOME TO UNIVERSITY MANAGEMENT SYSTEM\n\n";
				menu.islogged = false;
				menu.input = "0";
				continue;
			}
		}
		else {
			cout << "Invalid Input. Try Again\n";
			menu.input="0";
		}
	}
	return 0;
}
