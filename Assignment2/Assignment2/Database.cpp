#include "Login.h"

Database::Database(Login* Log)
{
	LG = Log;
	LG->DB = this;
}

void Database::sendLoginInfo(char* user, char* pass) {
	username = user;
	password = pass;
	//printf("Database received username and password: %s %s\n", *username, *password);
	cout << "Database received username and password: " << username << password;
}

void Database::authenticateLoginInfo() {

}