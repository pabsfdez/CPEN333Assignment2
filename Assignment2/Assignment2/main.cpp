#include "Login.h"
#include "Database.h"
#include "Student.h"
#include <iostream>
using namespace std;


int main(void) {

	
	//Login *LW = new Login();
	//Database* DB;
	//DB = new Database(LW);


	//char user[50];
	//char password[50];

	//cout << "Enter username\n";
	//cin >> user;
	//cout << "Enter password\n";
	//cin >> password;

	//printf("Press enter to send user and pass\n");
	//getchar();

	//LW->sendLoginInfo(user, password);
	
	char user[50] = "Joe123";
	char pass[50] = "asdf";
	char name[50] = "Joe";
	char ID[50] = "12345";

	Student *stud = new Student(user, pass, name, ID);
	studentInfo info = stud->getStudentInfo();
	cout << "User: " << info.username << "\n";
	cout << "Pass: " << info.password << "\n";
	cout << "Name: " << info.name << "\n";
	cout << "ID: " << info.studentID << "\n";


	return 0;
}