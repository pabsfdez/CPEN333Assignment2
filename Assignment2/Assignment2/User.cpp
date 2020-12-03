#include "User.h"

//User::User(char* user, char* pass, char* Name, char* userID)
//{
//	username = user;
//	password = pass;
//	name = Name;
//	ID = userID;
//}

User::User()
{

}

char* User::getUsername()
{
	return username;
}

char* User::getPassword()
{
	return password;
}

char* User::getName()
{
	return name;
}

char* User::getID()
{
	return ID;
}
