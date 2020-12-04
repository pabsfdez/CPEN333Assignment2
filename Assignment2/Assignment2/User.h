#pragma once
#ifndef __User__
#define __User__

using namespace std;

// generic class that Student, Professor, and Dean inherit
class User {
protected:
	char* username;
	char* password;
	char* name;
	char* ID;

public:
	char* getUsername();
	char* getPassword();
	char* getName();
	char* getID();
	User();
};
#endif // !__User__

