#include "Login.h"

Database::Database(Login* Log)
{
	LG = Log;
	LG->DB = this;
}

Database::Database()
{

}

void Database::sendLoginInfo(char* user, char* pass) {
	username = user;
	password = pass;
	//printf("Database received username and password: %s %s\n", *username, *password);
	cout << "\nDatabase received username and password: " << username << " " << password <<"\n";

	authenticateLoginInfo();
}

void Database::authenticateLoginInfo() {
	cout << "\nDatabase has authenticated username: " << username << " with password: " << password << "\n";
	
	int accountType = 1; // account type 1 means student
	
	cout << "\nDatabase sending account: " << to_string(accountType) << " to Login" << "\n";

	LG->sendAccountInfo(accountType);
}