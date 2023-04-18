#include "Admin.h"

Admin::Admin(){
	fstream myCourses("Courses.txt", ios::in);
	string line;
	while (getline(myCourses, line)) {
		courses.hours = line[0];
		courses.name = line.erase(0,2);
		courseInfo.push_back(courses);
	}
	myCourses.close();

	fstream myStudents("Students.txt", ios::in);
	string line2;
	int cnt = 6;
	while (getline(myStudents, line2)) {
		if (line2.size()!=0) {
			if (cnt % 6 == 0) {
				student.setID(line2);
				cnt--;
			}
			else if (cnt % 5 == 0) {
				student.setName(line2);
				cnt--;
			}
			else if (cnt % 4 == 0) {
				student.setPassword(line2);
				cnt--;
			}
			else if (cnt % 3 == 0) {
				student.calcGPA();
				cnt--;
			}
			else if (cnt % 2 == 0) {
				student.calcFees();
				studentInfo.push_back(student);
				cnt = 6;
			}
		}
		
	}
	myStudents.close();
}
Admin::~Admin() {
	fstream myCourses("Courses.txt", ios::out);
	myCourses << "";
	myCourses.close();
}

string Admin::getUsername() {
	return username;
}

string Admin::getPassword() {
	return password;
}

Admin& Admin::getInstance() {
	static Admin instance;
	return instance;
}

void Admin::addCourse()
{
	fstream myCourses("Courses.txt",ios::app);
	cout << "Insert Credit Hours And Course Name: ";
	string courseName="";
	char courseHours;
	cin >> courseHours;
	getline(cin, courseName);
	if (!isdigit(courseHours)) {
		cout << "Hours should be one digit only. Try Again\n";
		addCourse();
		return void();
	}
	if (courseName == "") {
		cout << "Course name should not be empty. Try Again\n";
		addCourse();
		return void();
	}
	for (int i = 0; i < courseName.size(); i++) {
		if (isdigit(courseName[i])) {
			cout << "Course name should not contain numbers. Try Again\n";
			addCourse();
			return void();
		}
	}
	courses.name = courseName;
	courses.hours = courseHours;
	courseInfo.push_back(courses);
	myCourses<< courseHours << courseName<<"\n";
	myCourses.close();
	
	cout << "Course Added Successfully!\n\n";
}

void Admin::deleteCourse() {
	fstream myCourses("Courses.txt", ios::in);
	string line;
	int del;
	vector<Course>::iterator it;
	if (courseInfo.size() == 0) {
		cout << "No Courses Available\n";
		return void();
	}
	for (size_t i = 0; i < courseInfo.size(); i++)
	{
		cout << i + 1 << "- ";
		courseInfo[i].getCourseInfo();
	}
	cout << "Select a number to delete course: ";
	cin >> del;
	if (del > courseInfo.size() || del==0) {
		cout << "Invalid Number. Try Again\n\n";
		deleteCourse();
		return void();
	}
	it = courseInfo.begin() + del-1;
	while (getline(myCourses, line)) {
		if (line.find(courseInfo[del - 1].name)) {
			fstream myCourses("Courses.txt", ios::out);
			myCourses.close();
			break;
		}
	}
	courseInfo.erase(it);

	fstream newCourses("Courses.txt", ios::app);
	for (it = courseInfo.begin(); it != courseInfo.end(); ++it) {
		newCourses << it->hours << " " << it->name << "\n";
	}
	newCourses.close();

	cout << "Course Deleted Successfully\n";
}

void Admin::addStudent()
{
	vector<Student>::iterator it;
	fstream myStudents("Students.txt", ios::app);
	fstream myStudentsID("StudentsID.txt", ios::app);
	cout << "Insert Student ID and Name: ";
	string ID;
	string name="";
	cin >> ID;
	
	for (int i = 0; i < ID.size(); i++) {
		if (!isdigit(ID[i])) {
			cout << "ID should not contain letters. Try Again\n";
			addStudent();
			return void();
		}
	}
	getline(cin,name);
	if (name == "") {
		cout << "Name should not be empty. Try Again\n";
		addStudent();
		return void();
	}
	for (int i = 0; i < name.size(); i++) {
		if (isdigit(name[i])) {
			cout << "Name should not contain numbers. Try Again\n";
			addStudent();
			return void();
		}
	}
	for (it = studentInfo.begin(); it != studentInfo.end(); it++)
	{
		if (it->getID() == ID) {
			cout << "Student exists already. Try Again\n";
			addStudent();
			return void();
		}
	}
	student.setID(ID);
	student.setName(name);
	myStudentsID << student.getID()<<","<<student.getPassword() << "\n";
	myStudents << student.getID() << "\n" << student.getName().erase(0,1) << "\n" << student.getPassword() << "\n";
	myStudents << student.calcGPA() << "\n" << student.calcFees()<<"\n";
	myStudents.close();
	myStudentsID.close();
	studentInfo.push_back(student);
	cout << "Student Added Successfully!\n\n";
}
