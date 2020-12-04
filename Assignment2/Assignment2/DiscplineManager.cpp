#include "DisciplineManager.h"
#include "Home.h"

DisciplineManager::DisciplineManager()
{

}

// Home calls this function when it needs a list of all available disciplines
void DisciplineManager::getAvailableDisciplines(Home* home) {

	cout << "\n--DisciplineManager sending array of available disciplines to Home\n";
	home->sendAvailableDisciplines(disciplines);
}