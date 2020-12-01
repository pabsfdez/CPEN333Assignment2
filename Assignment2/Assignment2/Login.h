#pragma once
#include "Database.h"
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

	Login(Database* DataB);
	Login();
	void sendLoginInfo(char* user, char* pass);
	void sendAccountInfo();
};

#endif




