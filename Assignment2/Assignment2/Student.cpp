#include "Student.h"
#include "Home.h"

Student::Student(char* dis, int strikes, Course* course, int numCourses, int* Grades,
	int balance, char* user, char* pass, char* Name, char* userID, bool sus, int y)
{
	myInfo.discipline = dis;
	myInfo.cheatingStrikes = strikes;
	myInfo.courses[numCourses] = course;
	myInfo.numberOfCourses = numCourses;
	//myInfo.grades[numCourses] = Grades;
	myInfo.financialBalance = balance;
	myInfo.suspended = sus;
	myInfo.yearLevel = y;

	// inherited class attributes
	username = user;
	password = pass;
	name = Name;
	ID = userID;

}



void Student::setDiscipline(char* dis)
{
	myInfo.discipline = dis;
}

void Student::incrementCheatingStrikes()
{
	myInfo.cheatingStrikes++;
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

// Home calls this function to get the Student's financial info
void Student::getFinancialSummary(Home* home)
{
	cout << "\n--Student sending financial info to Home\n";

	home->sendFinancialSummary(myInfo.financialBalance);
}

void Student::setSuspensionStatus(bool sus)
{
	myInfo.suspended = sus;
}

void Student::setDisciplineRanking(int index, int rank)
{
	myInfo.disciplineRankings[index] = rank;
}

