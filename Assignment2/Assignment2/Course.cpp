#include "Course.h"
#include "Home.h"
#include "Student.h"

// store course info that was hardcoded when course was created by CourseManager
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
	cout << "\n--Course sending course info to Home\n\n";

	home->sendCourseInformation(myInfo, this);
}

// home calls this function when a student tries to register in course
void Course::sendRegistrationInfo(Student* S, Home* home)
{
	// check student's eligibility to register course
	cout << "\n--Course checking student's eligibility to register\n";

	if (S->getSuspensionStatus() == true) // if student currently suspended
	{
		cout << "\n--Course sending registration error message to Home\n";
		char suspendMsg[50] = "Student currently suspended";
		home->sendUnableToRegisterCourseError(suspendMsg);
	}
	else if (S->getYearLevel() < myInfo.yearLevel) // if student year level does not meet minimum for this course
	{
		cout << "\n--Course sending registration error message to Home\n";
		char yearLevelMsg[100] = "Student has not reached minimum year level for this course";
		home->sendUnableToRegisterCourseError(yearLevelMsg);
	}
	else if (myInfo.numEnrolledStudents == myInfo.numMaxStudentsAllowed) // if course already full
	{
		cout << "\n--Course sending registration error message to Home\n";
		char courseFull[50] = "Course already full";
		home->sendUnableToRegisterCourseError(courseFull);
	}
	else
	{
		// update student's registered courses
		cout << "\n--Course sending updated registration info to Student\n";
		S->updateRegisteredCourses(this, S->getNumberRegisteredCourses());
		S->incrementNumberOfRegisteredCourses();

		// subtract course price from student's financial summary
		cout << "\n--Course sending updated financial info to Student\n";
		S->changeFinancialBalance(-1*myInfo.coursePrice);

		// update this course's info to reflect new registration
		cout << "\n--Course updating its registration info\n";
		myInfo.numEnrolledStudents++;

		// send success message to home
		cout << "\n--Course sending registration confirmation to Home\n";
		home->sendRegisterConfirmationMsg();
	}
}
