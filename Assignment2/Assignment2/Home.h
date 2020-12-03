#pragma once
#ifndef __Home__
#define __Home__
#include "..\rt.h"
#include "DisciplineManager.h"
#include "CourseManager.h"

using namespace std;

class Login;
class Student;

class Home
{
private:
	int accountType;
	Discipline** availableDisciplines;
	Course** availableCourses;
	courseInfo courseInformation;
	Student* student;
	Course* course;

public:
	Home();
	Login* LG;
	DisciplineManager* disMan;
	CourseManager* courseMan;

	void sendStudentInfo(Student* S);
	void displayStudentOptions(); 
	void selectRankDisciplines();
	void sendAvailableDisciplines(Discipline** availDisciplines);
	void displayDisciplines();
	void sendDisciplineRankings();
	void sendAvailableCourses(Course** availCourses);
	void displayAvailableCourses();
	void sendCourseInformation(courseInfo courseInf, Course* C);
	void displayCourseInformation();
	void sendUnableToRegisterCourseError(char* msg);
	void sendRegisterConfirmationMsg();

	void logout();
};

#endif

