#pragma once
#ifndef __Course__
#define __Course__
#include "Discipline.h"

using namespace std;

class Home;
class Student;

struct courseInfo {
	int numEnrolledStudents;
	int numMaxStudentsAllowed;
	char* disciplineBelongsTo;
	char* courseName;
	int yearLevel;
	int coursePrice;
};

class Course
{
private:
	courseInfo myInfo;
	Home* home;

public:
	Course(int numEnrolled, int numMax, char* courseName, char* discipline, int yL, int price);
	Course();
	char* getName();
	char* getDisciplineBelongsTo();
	void setNumEnrolledStudents(int num);
	void setNumMaxStudentsAllowed(int num);
	void setDisciplineBelongsTo(char* discipline);
	void setCourseName(char* name);
	void getCourseInformation(Home* home);
	void sendRegistrationInfo(Student* S, Home* home);

};

#endif

