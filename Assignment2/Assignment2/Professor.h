#pragma once
#ifndef __Professor__
#define __Professor__
#include "Course.h"
#include "User.h"
using namespace std;

struct professorInfo {
	char* discipline;
	Course* courses[7];
	int numberOfCourses;
};

class Professor : public User
{
private:
	professorInfo myInfo;

public:
	Professor(char* dis, Course* course, int numCourses, char* user, char* pass, char* Name, char* userID);
	professorInfo getProfessorInfo();

};

#endif
