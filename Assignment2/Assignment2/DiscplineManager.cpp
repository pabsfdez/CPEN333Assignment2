#include "DisciplineManager.h"
#include "Home.h"

DisciplineManager::DisciplineManager()
{

}

void DisciplineManager::getAvailableDisciplines(Home* home) {
	
	cout << "\n DisciplineManager sending array of available disciplines to Home\n";
	home->sendAvailableDisciplines(disciplines);
}
