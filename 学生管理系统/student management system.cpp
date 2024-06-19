#include <iostream>
#include "student management system.h"

Student::Student(std::string name, int age): name(name), age(age){}

Student& Student::setName(std::string name) {
	this->name = name;
	return *this;
}

Student& Student::setAge(int age) {
	this->age = age;
	return *this;
}

void Student::setGPA(std::string subject, double gpa) {
	gpas[subject] = gpa;
}

double Student::getAverageGPA() const {
	if (gpas.empty()) {
		return 0.0;
    }
	double sum = 0.0;
	for (const auto& pair : gpas) {
		sum += pair.second;
	}
	return sum / gpas.size();
}

const std::string& Student::getName() const {
		return name;
}
	
bool Student::compareByGPA(const Student& a, const Student& b) {
	return a.getAverageGPA() > b.getAverageGPA();
}

void Student::displayInfo() const{
	std::cout << "Name: " << name << ", Age: " << age << std::endl;
	std::cout << "GPAs: " << std::endl;
	for (const auto& pair : gpas) {
		std::cout << pair.first << ": " << pair.second << std::endl;
		}
	std::cout << "Average GPA: " << getAverageGPA() << std::endl;
}