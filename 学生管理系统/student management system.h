#ifndef STUDENT_MANAGEMENT_SYSTEM_H
#define STUDENT_MANAGEMENT_SYSTEM_H

#include <string>
#include <map>

class Student
{
public:
	Student() {}
	Student(std::string name, int age);

	Student& setName(std::string name);
	Student& setAge(int age);
	void setGPA(std::string subject, double gpa);

	double getAverageGPA()const;
	const std::string& getName() const;
	static bool compareByGPA(const Student& a, const Student& b);
	void displayInfo() const;

private:
	std::string name;
	int age;
	std::map<std::string, double> gpas;
}; 

#endif // STUDENT_MANAGEMENT_SYSTEM_H