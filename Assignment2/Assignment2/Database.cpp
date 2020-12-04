#include "Login.h"

Database::Database()
{

}

// login calls this function to send the user entered username and password to database
void Database::sendLoginInfo(char* user, char* pass) {
	username = user;
	password = pass;
	cout << "\n--Database received username and password: " << username << " " << password << "\n";

	authenticateLoginInfo();
}

// hardcode the authentication of username and password
void Database::authenticateLoginInfo() {

	// check student1
	int flag = 1;
	for (int i = 0; i <= 7; i++)
	{
		if (username[i] != username1[i])
		{
			flag = 0;
		}
	}
	for (int i = 0; i <= 8; i++)
	{
		if (password[i] != password1[i])
		{
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << "\n--Database has authenticated username: " << username << " with password: " << password << "\n";
		cout << "\n--Database sending account: " << stu1->getName() << " to Login" << "\n";
		LG->sendStudentInfo(stu1);

	}

	// check student2
flag = 1;
	for (int i = 0; i <= 7; i++)
	{
		if (username[i] != username2[i])
		{
			flag = 0;
		}
	}
	for (int i = 0; i <= 8; i++)
	{
		if (password[i] != password2[i])
		{
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << "\n--Database has authenticated username: " << username << " with password: " << password << "\n";
		cout << "\n--Database sending account: " << stu2->getName() << " to Login" << "\n";
		LG->sendStudentInfo(stu2);

	}



	// check student3
	flag = 1;
	for (int i = 0; i <=7; i++)
	{
		if (username[i] != username3[i])
		{
			flag = 0;
		}
	}
	for (int i = 0; i <= 8; i++)
	{
		if (password[i] != password3[i])
		{
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << "\n--Database has authenticated username: " << username << " with password: " << password << "\n";
		cout << "\n--Database sending account: " << stu3->getName() << " to Login" << "\n";
		LG->sendStudentInfo(stu3);

	}



	// check prof1
	flag = 1;
	for (int i = 0; i <= 4; i++)
	{
		if (username[i] != username4[i])
		{
			flag = 0;
		}
	}
	for (int i = 0; i <= 8; i++)
	{
		if (password[i] != password4[i])
		{
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << "\n--Database has authenticated username: " << username << " with password: " << password << "\n";
		cout << "\n--Database sending account: " << prof1->getName() << " to Login" << "\n";
		LG->sendProfessorInfo(prof1);

	}


	// check dean
	flag = 1;
	for (int i = 0; i <= 3; i++)
	{
		if (username[i] != username5[i])
		{
			flag = 0;
		}
	}
	for (int i = 0; i <= 8; i++)
	{
		if (password[i] != password5[i])
		{
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << "\n--Database has authenticated username: " << username << " with password: " << password << "\n";
		cout << "\n--Database sending account: " << dean->getName() << " to Login" << "\n";
		LG->sendDeanInfo(dean);

	}

	cout << "Incorrect username/password combination\n";

}

// Home calls this function when it needs a list of all students
void Database::getListOfStudents(Home* home)
{
	cout << "\n--Database sending list of students to Home\n";

	home->sendListOfStudents(students);
}