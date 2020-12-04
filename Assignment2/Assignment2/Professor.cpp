#include "Professor.h"

Professor::Professor(char* dis, Course* course, int numCourses, char* user, char* pass, char* Name, char* userID)
{
	myInfo.discipline = dis;
	myInfo.courses[numCourses] = course;
	myInfo.numberOfCourses = numCourses;

	// inherited class attributes
	username = user;
	password = pass;
	name = Name;
	ID = userID;

}

// return struct of Prof's info
professorInfo Professor::getProfessorInfo()
{
	return myInfo;
}

