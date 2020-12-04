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
	Course* courses[7]; // hardcode 7 as max number of courses that can be taken at once
	int numberOfCourses;
	int grades[7] = {0,0,0,0,0,0,0}; // indices in grades array align with courses array
	int financialBalance;
	int yearLevel;
	int disciplineRankings[3] = { 0,0,0 }; // index 0 is mech ranking, 1 is elec ranking, 2 is cpen ranking
};

class Student : public User
{
private:
	studentInfo myInfo;

public:
	Student(char* dis, int strikes, Course* course, int numCourses, int* Grades,
		int balance, char* user, char* pass, char* Name, char* userID, bool sus, int y);
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
	void setDisciplineRanking(int index, int rank);

	studentInfo getStudentInfo();

};

#endif


