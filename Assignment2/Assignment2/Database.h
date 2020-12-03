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

//	Student* stu1 = new Student(username1, password1, )


	char* username;
	char* password;

public:
	Database(Login* Log);
	Database();
	Login* LG;

	void sendLoginInfo(char* user, char* pass);
	void authenticateLoginInfo();
	void requestListOfStudents();

};

#endif



