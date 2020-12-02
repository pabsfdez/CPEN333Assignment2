#include "Course.h"

Course::Course(int numEnrolled, int numMax, char* name, char* discipline)
{
	numEnrolledStudents = numEnrolled;
	numMaxStudentsAllowed = numMax;
	courseName = name;
	disciplineBelongsTo = discipline;

}

Course::Course()
{

}

char* Course::getName()
{
	return courseName;
}

void Course::setCourseName(char* name)
{
	courseName = name;
}

void Course::setNumEnrolledStudents(int num)
{
	numEnrolledStudents = num;
}

void Course::setNumMaxStudentsAllowed(int num)
{
	numMaxStudentsAllowed = num;
}

void Course::setDisciplineBelongsTo(char* discipline) 
{
	disciplineBelongsTo = discipline;
}

char* Course::getDisciplineBelongsTo() 
{
	return disciplineBelongsTo;
}
