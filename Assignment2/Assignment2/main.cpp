#include "Login.h"
#include "Database.h"
#include "Student.h"
#include "DisciplineManager.h"
#include "CourseManager.h"
#include "Home.h"
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
	
	//char user[50] = "Joe123";
	//char pass[50] = "asdf";
	//char name[50] = "Joe";
	//char ID[50] = "12345";

	//Student *stud = new Student(user, pass, name, ID);
	//studentInfo info = stud->getStudentInfo();
	//cout << "User: " << info.username << "\n";
	//cout << "Pass: " << info.password << "\n";
	//cout << "Name: " << info.name << "\n";
	//cout << "ID: " << info.studentID << "\n";
	//char* name;
	//DisciplineManager* man = new DisciplineManager();

	////Discipline* dis = man->disciplines[0];
	//Discipline** dis = man->getAvailableDisciplines();

	//printf("%s\n", dis[0]->getName());
	//printf("%s\n", dis[1]->getName());
	//printf("%s\n", dis[2]->getName());

	//CourseManager* courseMan = new CourseManager();
	//Course** courseList = courseMan->getAvailableCourses();
	//printf("%s: %s\n", courseList[0]->getName(), courseList[0]->getDisciplineBelongsTo());
	//printf("%s: %s\n", courseList[1]->getName(), courseList[1]->getDisciplineBelongsTo());
	//printf("%s: %s\n", courseList[2]->getName(), courseList[2]->getDisciplineBelongsTo());

	Database* DB = new Database();
	Home* myHome = new Home(); // myHome cuisine combo
	DisciplineManager* disMan = new DisciplineManager();
	Login *LW = new Login(DB, myHome, disMan);



	return 0;
}