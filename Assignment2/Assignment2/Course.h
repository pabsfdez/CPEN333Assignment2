#pragma once
#ifndef __Course__
#define __Course__
#include "Discipline.h"

using namespace std;

class Course
{
private:
	int numEnrolledStudents;
	int numMaxStudentsAllowed;
	char* disciplineBelongsTo;
	char* courseName;


public:
	Course(int numEnrolled, int numMax, char* courseName, char* discipline);
	Course();
	char* getName();
	char* getDisciplineBelongsTo();
	void setNumEnrolledStudents(int num);
	void setNumMaxStudentsAllowed(int num);
	void setDisciplineBelongsTo(char* discipline);
	void setCourseName(char* name);

};

#endif


