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
	cout << "Enter login information: (student1, password1), (student2, password2), (student33 password3), (prof1, password4), (dean, password5): \n\n";
	cout << "Username: ";
	cin >> user;
	cout << "\nPassword: ";
	cin >> pass;

	sendLoginInfo(user, pass);
}

// Function gets called after the user enters their login info
void Login::sendLoginInfo(char* user, char* pass) {
	username = user;
	password = pass;
	cout << "\n___________________________________________________________________\n";
	printf("\n--Login sending username and password to Database\n");

	// forward the login info to Database
	DB->sendLoginInfo(username, password);
}

// Database calls this function if the user is a Student
void Login::sendStudentInfo(Student* S) {
	cout << "\n--Login sending account: " << S->getName() << " to Home" << "\n";

	myHome->sendStudentInfo(S);
}

// Database calls this function if the user is a Prof
void Login::sendProfessorInfo(Professor* P)
{
	cout << "\n--Login sending account: " << P->getName() << " to Home" << "\n";

	myHome->sendProfessorInfo(P);
}

// Database calls this function if the user is the Dean
void Login::sendDeanInfo(Dean* D)
{
	cout << "\n--Login sending account: " << D->getName() << " to Home" << "\n";

	myHome->sendDeanInfo(D);
}
