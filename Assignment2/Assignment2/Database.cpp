#include "Login.h"

Database::Database()
{

}

void Database::sendLoginInfo(char* user, char* pass) {
	username = user;
	password = pass;
	//printf("Database received username and password: %s %s\n", *username, *password);
	cout << "\n--Database received username and password: " << username << " " << password << "\n";

	authenticateLoginInfo();
}

void Database::authenticateLoginInfo() {
	cout << "\n--Database has authenticated username: " << username << " with password: " << password << "\n";


	cout << "\n--Database sending account: " << stu1->getName() << " to Login" << "\n";

	LG->sendStudentInfo(stu1);
}
