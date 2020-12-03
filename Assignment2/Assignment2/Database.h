#pragma once
#ifndef __Database__
#define __Database__
#include <string>
#include "Student.h"
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

	char username1[50] = "student1";
	char password1[50] = "password1";
	char name1[50] = "John Smith";
	char ID1[50] = "11237465";
	char discipline1[50] = "Computer";
	Course* courses1;
	float* grades1;

	Student* stu1 = new Student(discipline1, 0, courses1, 0, grades1,0, username1, password1, name1, ID1, false, 3);


	char* username;
	char* password;

public:
	Database();
	Login* LG;

	void sendLoginInfo(char* user, char* pass);
	void authenticateLoginInfo();
	void requestListOfStudents();

};

#endif



