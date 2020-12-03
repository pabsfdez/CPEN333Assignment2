#include "Course.h"
#include "Home.h"

Course::Course(int numEnrolled, int numMax, char* name, char* discipline)
{
	myInfo.numEnrolledStudents = numEnrolled;
	myInfo.numMaxStudentsAllowed = numMax;
	myInfo.courseName = name;
	myInfo.disciplineBelongsTo = discipline;

}

Course::Course()
{

}

char* Course::getName()
{
	return myInfo.courseName;
}

void Course::setCourseName(char* name)
{
	myInfo.courseName = name;
}

void Course::setNumEnrolledStudents(int num)
{
	myInfo.numEnrolledStudents = num;
}

void Course::setNumMaxStudentsAllowed(int num)
{
	myInfo.numMaxStudentsAllowed = num;
}

void Course::setDisciplineBelongsTo(char* discipline)
{
	myInfo.disciplineBelongsTo = discipline;
}

char* Course::getDisciplineBelongsTo()
{
	return myInfo.disciplineBelongsTo;
}

void Course::getCourseInformation(Home* home) {
	home->sendCourseInformation(myInfo);
}

