#include "DisciplineManager.h"

DisciplineManager::DisciplineManager()
{
	char mech[50] = "Mechanical";
	//Mechanical.setDisciplineName(mech);
	//Mechanical.setNumEnrolledStudents(500);
	//Mechanical.setNumMaxStudentsAllowed(600);

}

Discipline** DisciplineManager::getAvailableDisciplines() {
	
	return disciplines;
}
