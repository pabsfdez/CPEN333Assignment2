#include "Course.h"
#include "Home.h"
#include "Student.h"

Course::Course(int numEnrolled, int numMax, char* name, char* discipline, int yL, int price)
{
	myInfo.numEnrolledStudents = numEnrolled;
	myInfo.numMaxStudentsAllowed = numMax;
	myInfo.courseName = name;
	myInfo.disciplineBelongsTo = discipline;
	myInfo.yearLevel = yL;
	myInfo.coursePrice = price;
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

void Course::getCourseInformation(Home* home) 
{
	home->sendCourseInformation(myInfo, this);
}

void Course::sendRegistrationInfo(Student* S, Home* home)
{
	// check student's eligibility to register course
	
	if (S->getSuspensionStatus() == true) 
	{
		char suspendMsg[50] = "Student currently suspended";
		home->sendUnableToRegisterCourseError(suspendMsg);
	}
	else if (S->getYearLevel() < myInfo.yearLevel) 
	{
		char yearLevelMsg[100] = "Student has not reached minimum year level for this course";
		home->sendUnableToRegisterCourseError(yearLevelMsg);
	}
	else if (myInfo.numEnrolledStudents == myInfo.numMaxStudentsAllowed) 
	{
		char courseFull[50] = "Course already full";
		home->sendUnableToRegisterCourseError(courseFull);
	}
	else
	{
		// update student's registered courses
		S->updateRegisteredCourses(this, S->getNumberRegisteredCourses());
		S->incrementNumberOfRegisteredCourses();

		// subtract course price from student's financial summary
		S->changeFinancialBalance(-1*myInfo.coursePrice);

		// update this course's info to reflect new registration
		myInfo.numEnrolledStudents++;

		// send success message to home
		home->sendRegisterConfirmationMsg();
	}
}
