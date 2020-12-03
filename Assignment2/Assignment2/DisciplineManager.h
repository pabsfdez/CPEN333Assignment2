#pragma once
#ifndef __DisciplineManager__
#define __DisciplineManager__
#include "Discipline.h"


using namespace std;

class Home;

class DisciplineManager
{
private:

	char mech[50] = "Mechanical";
	char elec[50] = "Electrical";
	char cpen[50] = "Computer";
	Discipline* Mechanical = new Discipline(500, 600, mech);
	Discipline* Electrical = new Discipline(700, 800, elec);
	Discipline* Computer = new Discipline(300, 400, cpen);

	Discipline* disciplines[3] = { Mechanical, Electrical, Computer };



public:
	DisciplineManager();
	void getAvailableDisciplines(Home* home);
};

#endif


