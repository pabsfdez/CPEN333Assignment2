#include "Login.h"

Login::Login(Database* DataB)
{
	DB = DataB;
}

Login::Login() {

}

void Login::sendLoginInfo(char* user, char* pass) {
	username = user;
	password = pass;
	printf("Login sending username and password to Database\n");
	DB->sendLoginInfo(username, password);
}

