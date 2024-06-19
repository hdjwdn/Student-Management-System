#include <iostream>
#include <vector>
#include <algorithm>
#include "student management system.h"

int main() {
	std::vector<Student> students;

	char choice;
	do {
		std::cout << "Press 'a' to add a student, 'c' to calculat average score, 'r' to rank by score, or 'q' to quit.";
		std::cin >> choice;

		switch (choice) {
		case 'a': {
			std::string name, subject;
			int age;
			double gpa;

			std::cout << "Enter the name: ";
			std::cin >> name;
			std::cout << "Enter the age: ";
			std::cin >> age;

			Student newStudent;
			newStudent.setName(name).setAge(age);

			while (true) {
				std::cout << "Enter the subject (or '0' to finish): ";
				std::cin >> subject;
				if (subject == "0") break;

				std::cout << "Enter the GPA: ";
				std::cin >> gpa;

				newStudent.setGPA(subject, gpa);
			}

			students.push_back(newStudent);

			std::cout << "The student " << std::endl;
			newStudent.displayInfo();
			std::cout << "is added." << std::endl;
			break;
		}
		case 'c': {
			double totalAverage = 0.0;
			for (const auto& student : students) {
				totalAverage += student.getAverageGPA();
			}
			if (!students.empty()) {
				totalAverage /= students.size();
			}
			std::cout << "Average GPA of all students: " << totalAverage << std::endl;
			break;
		}
		case 'r': {
			std::sort(students.begin(), students.end(), Student::compareByGPA);
			int rank = 1;
			std::cout << "Studens ranked by GPA: " << std::endl;
			for (const auto& student : students) {
				std::cout << "Rank: " << rank++ << ": " << student.getName() << " - GPA: " << student.getAverageGPA() << std::endl;
			}
			break;
		}
		case 'q':
			std::cout << "Exiting program..." << std::endl;
			break;
		default:
			std::cout << "Invailed choice. Please enter again." << std::endl;
			break;
		}

	} while (choice != 'q');

	return 0;
}