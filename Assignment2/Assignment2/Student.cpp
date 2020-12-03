#include "Student.h"
#include "Home.h"

Student::Student(char* dis, int strikes, Course* course, int numCourses, float* Grades,
	int balance, char* user, char* pass, char* Name, char* userID, bool sus, int y)
{
	myInfo.discipline = dis;
	myInfo.cheatingStrikes = strikes;
	myInfo.courses[numCourses] = course;
	myInfo.numberOfCourses = numCourses;
	myInfo.grades = Grades;
	myInfo.financialBalance = balance;
	myInfo.suspended = sus;
	myInfo.yearLevel = y;

	// inherited class attributes
	username = user;
	password = pass;
	name = Name;
	ID = userID;

}

//Student::Student()
//{
//	
//}

void Student::setDiscipline(char* dis)
{
	myInfo.discipline = dis;
}

void Student::setCheatingStrikes(int strikes)
{
	myInfo.cheatingStrikes = strikes;
}

void Student::updateRegisteredCourses(Course* Course, int courseIndex)
{
	myInfo.courses[courseIndex] = Course;
}

void Student::incrementNumberOfRegisteredCourses()
{
	myInfo.numberOfCourses++;
}

void Student::setGrade(int grade, int gradeIndex)
{
	myInfo.grades[gradeIndex] = grade;
}

void Student::changeFinancialBalance(double amount)
{
	myInfo.financialBalance += amount;
}

bool Student::getSuspensionStatus()
{
	return myInfo.suspended;
}

char* Student::getDiscipline()
{
	return myInfo.discipline;
}

int Student::getYearLevel()
{
	return myInfo.yearLevel;
}

studentInfo Student::getStudentInfo()
{
	return myInfo;

}

int Student::getNumberRegisteredCourses()
{
	return myInfo.numberOfCourses;
}

void Student::getFinancialSummary(Home* home)
{
	home->sendFinancialSummary(myInfo.financialBalance);
}
