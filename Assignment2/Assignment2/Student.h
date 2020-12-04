#pragma once
#ifndef __Student__
#define __Student__
#include "Course.h"
#include "User.h"
using namespace std;

struct studentInfo {
	char* discipline;
	int cheatingStrikes;
	bool suspended;
	Course* courses[7];
	int numberOfCourses;
	int grades[7] = {0,0,0,0,0,0,0};
	int financialBalance;
	int yearLevel;
};

class Student : public User
{
private:
	studentInfo myInfo;

public:
	Student(char* dis, int strikes, Course* course, int numCourses, int* Grades,
		int balance, char* user, char* pass, char* Name, char* userID, bool sus, int y);
	//Student();
	void setDiscipline(char* dis);
	void incrementCheatingStrikes();
	void updateRegisteredCourses(Course* Course, int courseIndex);
	void incrementNumberOfRegisteredCourses();
	void setGrade(int grade, int gradeIndex);
	void changeFinancialBalance(double amount);
	bool getSuspensionStatus();
	char* getDiscipline();
	int getYearLevel();
	int getNumberRegisteredCourses();
	void getFinancialSummary(Home* home);
	void setSuspensionStatus(bool sus);

	studentInfo getStudentInfo();

};

#endif


