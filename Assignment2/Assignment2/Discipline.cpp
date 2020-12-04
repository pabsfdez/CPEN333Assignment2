#include "Discipline.h"

Discipline::Discipline(int numEnrolled, int numMax, char* name)
{
	numEnrolledStudents = numEnrolled;
	numMaxStudentsAllowed = numMax;
	disciplineName = name;

}

Discipline::Discipline()
{

}

char* Discipline::getName() 
{
	return disciplineName;
}

void Discipline::setDisciplineName(char* name)
{
	disciplineName = name;
}

void Discipline::setNumEnrolledStudents(int num)
{
	numEnrolledStudents = num;
}

void Discipline::setNumMaxStudentsAllowed(int num)
{
	numMaxStudentsAllowed = num;
}
