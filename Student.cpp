#include "Student.h"
#include <sstream>
#include <iostream>
#include <stdio.h>

Student::Student(std::string fn, std::string ln, int gy, Major m) {
  _grad_year = gy;
  _first_name = fn;
  _last_name = ln;
  _major = m;
}

Student::~Student() {}


float Student::getGpa() {
	int i = 0;
	float gpasum = 0;
	while(i < _grades.size())
	{
		gpasum = gpasum + _grades.at(i);
		i++;
	}
	float gpa = gpasum / _grades.size();
	return gpa;
}

void Student::addGrade(float grade) {
	_grades.push_back(grade);
}
  
std::string Student::majorString(Major m) {
	std::string maj;
	switch(m){
		case Major::EE: 
			maj = "EE";
			return maj;
		case Major::ME: 
			maj = "ME";
			return maj; 
		case Major::CE: 
			maj = "CE";
			return maj; 
		case Major::CHE: 
			maj = "CHE";
			return maj;
		case Major::BSE: 
			maj= "BSE";
			return maj;
		case Major::ART: 
			maj = "ART";
			return maj;
		case Major::ARCH: 
			maj = "ARCH";
			return maj;
	}
	
	
}

void Student::printInfo() {
	std::stringstream ss;
	ss << _last_name << ", " << _first_name;
	std::cout << ss.str() << std::endl;
	std::stringstream ss1;
	ss1 << majorString(_major) << " " << std::to_string(_grad_year);
	std::cout << ss1.str() << std::endl;
	printf("GPA: %.2f\n", getGpa());
}