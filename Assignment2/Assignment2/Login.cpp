#include "Login.h"
#include "../rt.h"


Login::Login(Database* dataB, Home* hm, DisciplineManager* DM, CourseManager* CM) {

	// link Login and Database objects together
	DB = dataB;
	DB->LG = this;

	// link Login and Home objects together
	myHome = hm;
	hm->LG = this;

	// give Home object the pointer to the DisciplineManager object
	myHome->disMan = DM;

	// give Home object the pointer to the CourseManager object
	myHome->courseMan = CM;

	char user[50];
	char pass[50];
	cout << "Enter login information: \n\n";
	cout << "Username: ";
	cin >> user;
	cout << "\nPassword: ";
	cin >> pass;

	sendLoginInfo(user, pass);
}

void Login::sendLoginInfo(char* user, char* pass) {
	username = user;
	password = pass;
	printf("\n--Login sending username and password to Database\n");
	DB->sendLoginInfo(username, password);
}

void Login::sendAccountInfo(int accountType) {
	cout << "\n--Login has received account: " << to_string(accountType) << " from Database" << "\n";
	cout << "\n--Login sending account: " << to_string(accountType) << " to Home" << "\n";

	myHome->sendAccountInfo(accountType);
}


