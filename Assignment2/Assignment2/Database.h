#pragma once
#ifndef __Database__
#define __Database__
#include <string>
#include "Student.h"
#include "Professor.h"
#include "Dean.h"
using namespace std;

class Login;

//struct studentInfo {
//	char* username;
//	char* password;
//	char* name;
//	char* studentID;
//};

class Database
{
private:
	// hardcode example students and professor into database
	char username1[50] = "student1";
	char password1[50] = "password1";
	char name1[50] = "John Dave";
	char ID1[50] = "11237465";
	char discipline1[50] = "Computer";
	Course* courses1;
	int* grades1;

	char username2[50] = "student2";
	char password2[50] = "password2";
	char name2[50] = "John Paul";
	char ID2[50] = "11234343";
	char discipline2[50] = "Electrical";
	Course* courses2;
	int* grades2;

	char username3[50] = "student3";
	char password3[50] = "password3";
	char name3[50] = "Jane Doe";
	char ID3[50] = "91823634";
	char discipline3[50] = "Mechanical";
	Course* courses3;
	int* grades3;

	Student* stu1 = new Student(discipline1, 0, courses1, 0, grades1,0, username1, password1, name1, ID1, false, 4);
	Student* stu2 = new Student(discipline2, 0, courses2, 0, grades2,0, username2, password2, name2, ID2, false, 3);
	Student* stu3 = new Student(discipline3, 0, courses3, 0, grades3,0, username3, password3, name3, ID3, false, 2);

	Student* students[3] = { stu1, stu2, stu3 };

	char username4[50] = "prof1";
	char password4[50] = "password4";
	char name4[50] = "David Paulson";
	char ID4[50] = "11237465";
	char discipline4[50] = "Computer";
	Course* courses4;

	Professor* prof1 = new Professor(discipline4, courses4, 1, username4, password4, name4, ID4);

	char username5[50] = "dean";
	char password5[50] = "password5";
	char name5[50] = "Paul";
	char ID5[50] = "112374653";

	Dean* dean = new Dean(username5, password5, name5, ID5);
	char* username;
	char* password;

public:
	Database();
	Login* LG;

	void sendLoginInfo(char* user, char* pass);
	void authenticateLoginInfo();
	void getListOfStudents(Home* home);

};

#endif



