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

	myHome->DB = dataB;

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

void Login::sendStudentInfo(Student* S) {
	cout << "\n--Login has received account: " << S->getName() << " from Database" << "\n";
	cout << "\n--Login sending account: " << S->getName() << " to Home" << "\n";

	myHome->sendStudentInfo(S);
}

void Login::sendProfessorInfo(Professor* P)
{
	cout << "\n--Login has received account: " << P->getName() << " from Database" << "\n";
	cout << "\n--Login sending account: " << P->getName() << " to Home" << "\n";

	myHome->sendProfessorInfo(P);
}

void Login::sendDeanInfo(Dean* D)
{
	cout << "\n--Login has received account: " << D->getName() << " from Database" << "\n";
	cout << "\n--Login sending account: " << D->getName() << " to Home" << "\n";

	myHome->sendDeanInfo(D);
}
