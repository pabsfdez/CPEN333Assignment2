#pragma once
#ifndef __Database__
#define __Database__
#include <string>
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
	Login* LG;
	char* username;
	char* password;

public:
	Database(Login* Log);
	void sendLoginInfo(char* user, char* pass);
	void authenticateLoginInfo();
	void requestListOfStudents();
};

#endif

