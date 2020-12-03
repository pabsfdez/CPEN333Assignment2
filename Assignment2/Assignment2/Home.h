#pragma once
#ifndef __Home__
#define __Home__
#include "..\rt.h"
#include "DisciplineManager.h"

using namespace std;

class Login;

class Home
{
private:
	int accountType;
	Discipline** availableDisciplines;

public:
	Home();
	Login* LG;
	DisciplineManager* disMan;

	void sendAccountInfo(int accType); // char* to be replaced by Account object
	void displayUserOptions(); // char* to be replaced by Account object
	void selectRankDisciplines();
	void sendAvailableDisciplines(Discipline** availDisciplines);
	void displayDisciplines();
	void logout();
};

#endif


