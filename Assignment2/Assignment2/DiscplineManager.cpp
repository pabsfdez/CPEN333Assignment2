#include "DisciplineManager.h"
#include "Home.h"

DisciplineManager::DisciplineManager()
{

}

void DisciplineManager::getAvailableDisciplines(Home* home) {

	cout << "\nDisciplineManager sending array of available disciplines to Home\n";
	home->sendAvailableDisciplines(disciplines);
}