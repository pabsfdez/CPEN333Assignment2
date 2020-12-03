#pragma once
#ifndef __Course__
#define __Course__
#include "Discipline.h"

using namespace std;

class Home;

struct courseInfo {
	int numEnrolledStudents;
	int numMaxStudentsAllowed;
	char* disciplineBelongsTo;
	char* courseName;
};

class Course
{
private:
	courseInfo myInfo;


public:
	Course(int numEnrolled, int numMax, char* courseName, char* discipline);
	Course();
	char* getName();
	char* getDisciplineBelongsTo();
	void setNumEnrolledStudents(int num);
	void setNumMaxStudentsAllowed(int num);
	void setDisciplineBelongsTo(char* discipline);
	void setCourseName(char* name);
	void getCourseInformation(Home* home);

};

#endif


