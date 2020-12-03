#pragma once
#ifndef __User__
#define __User__

using namespace std;

class User {
protected:
	char* username;
	char* password;
	char* name;
	char* ID;

public:
	//User(char* user, char* pass, char* Name, char* userID);
	char* getUsername();
	char* getPassword();
	char* getName();
	char* getID();
	User();
};
#endif // !__User__

