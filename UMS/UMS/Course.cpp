#include "Course.h"
Course::Course() {}
Course::~Course() {}

void Course::getCourseInfo() {
	cout << "Credit Hours: " << hours<<" Hours" << "\tCourse Name: " << name <<"\n";
}
