#include "Student.h"

Student::Student(char* dis, int strikes, Course* course, int numCourses, float *Grades, 
				 float balance, char* user, char* pass, char* Name, char* userID)
{
	myInfo.discipline = dis;
	myInfo.cheatingStrikes = strikes;
	myInfo.courses[numCourses] = course;
	myInfo.numberOfCourses = numCourses;
	myInfo.grades = Grades;
	myInfo.financialBalance = balance;
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

void Student::setCourse(Course* Course, int courseIndex)
{
	myInfo.courses[courseIndex] = Course;
}

void Student::setNumberOfCourses(int numCourses)
{
	myInfo.numberOfCourses = numCourses;
}

void Student::setGrade(int grade, int gradeIndex)
{
	myInfo.grades[gradeIndex] = grade;
}

void Student::setFinancialBalance(double balance)
{
	myInfo.financialBalance = balance;
}



 studentInfo Student::getStudentInfo()
{
	return myInfo;

}