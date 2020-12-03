#pragma once
#ifndef __Student__
#define __Student__
#include "Course.h"
#include "User.h"
using namespace std;

struct studentInfo {
		char* discipline;
		int cheatingStrikes;
		Course* courses[7];
		int numberOfCourses;
		float *grades;
		float financialBalance;
	};

class Student : public User
{
private:
	studentInfo myInfo;

public:
	Student(char* dis, int strikes, Course* course, int numCourses, float* Grades,
		float balance, char* user, char* pass, char* Name, char* userID);
	//Student();
	void setDiscipline(char* dis);
	void setCheatingStrikes(int strikes);
	void setCourse(Course* Course, int courseIndex);
	void setNumberOfCourses(int numCourses);
	void setGrade(int grade, int gradeIndex);
	void setFinancialBalance(double balance);
	studentInfo getStudentInfo();

};

#endif




