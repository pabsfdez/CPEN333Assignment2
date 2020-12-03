#include "Home.h"

Home::Home()
{


}

void Home::sendAccountInfo(int accType)
{
	accountType = accType;
	cout << "\nHome has received account: " << to_string(accountType) << " from Login" << "\n";

	displayUserOptions();
}

void Home::displayUserOptions() 
{
	char input;
	if (accountType == 1) { // to be replaced by proper check for Student user
		cout << "\n___________________________________________________________________\n";
		cout << "What would you like to do?\n" << "1. Rank disciplines\n";
		cin >> input;
	
		while (input != '1') {
			cout << "Please select a valid option by enter a number from 1 to 1\n";
			cin >> input;
		}
	
		if (input == '1') {
			cout << "\n___________________________________________________________________\n";
			cout << "\nSending request for available disciplines to DisciplineManager\n";

			disMan->getAvailableDisciplines(this);
			
		}

	}

	
}

void Home::sendAvailableDisciplines(Discipline** availDisciplines)
{
	cout << "\Home received available disciplines from DisciplineManager\n";

	availableDisciplines = availDisciplines;

	displayDisciplines();
}

void Home::displayDisciplines() 
{
	cout << "\n___________________________________________________________________\n";
	cout << "\nThe available disciplines to select are \n\n";

	int j = sizeof(availableDisciplines) / sizeof(availableDisciplines[0]);
	for (int i = 0; i < j; i++)
	{
		cout << availableDisciplines[i]->getName() << "\n";
	}

}