#pragma once
#ifndef __Home__
#define __Home__
#include "..\rt.h"
#include "DisciplineManager.h"
#include "CourseManager.h"

using namespace std;

class Login;

class Home
{
private:
	int accountType;
	Discipline** availableDisciplines;
	Course** availableCourses;
	courseInfo courseInformation;

public:
	Home();
	Login* LG;
	DisciplineManager* disMan;
	CourseManager* courseMan;

	void sendAccountInfo(int accType); // char* to be replaced by Account object
	void displayUserOptions(); // char* to be replaced by Account object
	void selectRankDisciplines();
	void sendAvailableDisciplines(Discipline** availDisciplines);
	void displayDisciplines();
	void sendDisciplineRankings();
	void sendAvailableCourses(Course** availCourses);
	void displayAvailableCourses();
	void sendCourseInformation(courseInfo course);
	void displayCourseInformation();

	void logout();
};

#endif