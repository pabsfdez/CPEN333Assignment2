#include "Student.h"

Student::Student(char* user, char* pass, char* Name, char* stuID)
{
	myInfo.name = Name;
	myInfo.password = pass;
	myInfo.studentID = stuID;
	myInfo.username = user;
}

 studentInfo Student::getStudentInfo()
{
	return myInfo;

}