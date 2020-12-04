#include "Login.h"
#include "Database.h"
#include "Student.h"
#include "DisciplineManager.h"
#include "CourseManager.h"
#include "Home.h"
#include <iostream>
using namespace std;


int main(void) {


	Database* DB = new Database(); // setup single Database object
	Home* myHome = new Home();  // setup single Home object
	DisciplineManager* disMan = new DisciplineManager(); // setup single DisciplineManager object
	CourseManager* courseMan = new CourseManager(); // setup single CourseManager object
	Login* LW = new Login(DB, myHome, disMan, courseMan); // setup single Login object, which links the other objects to each other



	return 0;
}