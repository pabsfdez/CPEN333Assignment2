#pragma once
#ifndef __CourseManager__
#define __CourseManager__
#include "Course.h"

using namespace std;

class CourseManager
{
private:
	// hardcode example list of courses
	char mech[50] = "Mechanical";
	char elec[50] = "Electrical";
	char cpen[50] = "Computer";

	char cpen333name[50] = "System Software Engineering";
	char mech423name[50] = "Mechatronic Product Design";
	char elec201name[50] = "Circuit Analysis I";

	Course* CPEN333 = new Course(120, 120, cpen333name, cpen);
	Course* MECH423 = new Course(33, 35, mech423name, mech);
	Course* ELEC201 = new Course(305, 310, elec201name, elec);
	
	// create array of all available courses
	Course* courses[3] = { CPEN333, MECH423, ELEC201 };



public:
	CourseManager();
	Course** getAvailableCourses();
};

#endif


