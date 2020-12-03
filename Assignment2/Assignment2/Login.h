#pragma once
#include "Database.h"
#include "Home.h";
#include "DisciplineManager.h"

#ifndef __Login__
#define __Login__
#include <string>
#include <iostream>
using namespace std;

class Login
{
private:
	char* username;
	char* password;

public:
	Database* DB;
	Home* myHome;
	Login(Database* dataB, Home* hm, DisciplineManager* DM, CourseManager* CM);
	void sendLoginInfo(char* user, char* pass);
	void sendAccountInfo(int accountType); // replace char* with User object (student, prof, etc)
};

#endif



