#pragma once
#ifndef __Home__
#define __Home__
#include "..\rt.h"
#include "DisciplineManager.h"
#include "CourseManager.h"
#include "Professor.h"
#include "Dean.h"


using namespace std;

class Login;
class Student;
class Database;

class Home
{
private:
	int accountType;
	Discipline** availableDisciplines;
	Course** availableCourses;
	courseInfo courseInformation;
	Student* student;
	Course* course;
	Professor* professor;
	Student** listOfStudents;
	Dean* dean;

public:
	Home();
	Login* LG;
	Database* DB;
	DisciplineManager* disMan;
	CourseManager* courseMan;

	// Student use cases
	void sendStudentInfo(Student* S);
	void displayStudentOptions(); 
	void selectRankDisciplines();
	void sendAvailableDisciplines(Discipline** availDisciplines);
	void displayDisciplines();
	void sendDisciplineRankings();
	void selectViewCourses();
	void sendAvailableCourses(Course** availCourses);
	void displayAvailableCourses();
	void sendCourseInformation(courseInfo courseInf, Course* C);
	void displayCourseInformation();
	void sendUnableToRegisterCourseError(char* msg);
	void sendRegisterConfirmationMsg();
	void selectViewFinancialSummary();
	void sendFinancialSummary(int balance);
	void displayFinancialSummary(int balance);
	void displayPaymentPage();
	void sendListOfStudents(Student** list);
	void displayStudentProfileGrade(int stuIndex);
	void displayStudentProfileMisconduct(int stuIndex);

	// Professor use cases
	void displayProfessortOptions();
	void selectSubmitGrades();
	void sendProfessorInfo(Professor* P);
	void selectReportMisconduct();
	void selectAssignDiscipline();
	void displayStudentProfileDiscipline(int stu);


	// Dean use cases
	void displayDeanOptions();
	void sendDeanInfo(Dean *D);
	void selectSuspendStudent();
	void displayStudentProfileSuspend(int stuIndex);


	void logout();
};

#endif

