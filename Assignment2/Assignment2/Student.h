#pragma once
#ifndef __Student__
#define __Student__

using namespace std;

struct studentInfo {
	char* username;
	char* password;
	char* name;
	char* studentID;
};

class Student
{
private:
	struct studentInfo myInfo;


public:
	Student(char* user, char* pass, char* Name, char* stuID);
	studentInfo getStudentInfo();




};

#endif





