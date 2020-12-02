#pragma once
#ifndef __Home__
#define __Home__
#include "..\rt.h"


using namespace std;

class Login;

class Home
{
private:
	int accountType;

public:
	Home();
	Login* LG;
	void sendAccountInfo(int accType); // char* to be replaced by Account object
	void displayUserOptions(); // char* to be replaced by Account object
	void selectRankDisciplines();
	void sendAvailableDisciplines();
	void logout();
};

#endif


