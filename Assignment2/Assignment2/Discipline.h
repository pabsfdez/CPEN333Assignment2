#pragma once
#ifndef __Discipline__
#define __Discipline__

using namespace std;

class Discipline
{
private:
	int numEnrolledStudents;
	int numMaxStudentsAllowed;
	char* disciplineName;


public:
	Discipline(int numEnrolled, int numMax, char* name);
	Discipline();
	char* getName();
	void setNumEnrolledStudents(int num);
	void setNumMaxStudentsAllowed(int num);
	void setDisciplineName(char* name);
	
};

#endif


