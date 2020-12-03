#include "Home.h"

Home::Home()
{


}

void Home::sendAccountInfo(int accType)
{
	accountType = accType;
	cout << "\n--Home has received account: " << to_string(accountType) << " from Login" << "\n";

	displayUserOptions();
}

void Home::displayUserOptions()
{

	cout << "\n--Home displaying options for user of account type: " << to_string(accountType);

	char input;
	if (accountType == 1) { // to be replaced by proper check for Student user
		cout << "\n___________________________________________________________________\n";
		cout << "\nWhat would you like to do?\n" << "1. Rank disciplines\n" << "2. View available courses\n\n";
		cin >> input;

		while (input != '1' && input != '2') {
			cout << "Please select a valid option by entering a number from 1 to 2\n";
			cin >> input;
		}

		if (input == '1') {
			cout << "\n___________________________________________________________________\n";
			cout << "\n--Home sending request for available disciplines to DisciplineManager\n";

			disMan->getAvailableDisciplines(this);

		}

		if (input == '2') {
			cout << "\n___________________________________________________________________\n";
			cout << "\n--Home sending request for available courses to CourseManager\n";

			courseMan->getAvailableCourses(this);
		}

	}


}

void Home::sendAvailableDisciplines(Discipline** availDisciplines)
{
	cout << "\n--Home received available disciplines from DisciplineManager\n";

	availableDisciplines = availDisciplines;

	displayDisciplines();
}

void Home::displayDisciplines()
{
	cout << "\n___________________________________________________________________\n";
	cout << "\nThe available disciplines to select are \n\n";

	for (int i = 0; i < disMan->numberOfDisciplines; i++)
	{
		cout << availableDisciplines[i]->getName() << "\n";
	}

	sendDisciplineRankings();

}

void Home::sendDisciplineRankings()
{
	int rankings[3];
	char buffer;

	cout << "\nGive each of the following disciplines a ranking from 1 (first) to " << to_string(disMan->numberOfDisciplines) << " (last)\n";

	int i = 0;
	int j;
	int maxRanking = disMan->numberOfDisciplines;
	while (i < maxRanking)
	{
		cout << "\nRanking for " << availableDisciplines[i]->getName() << ": ";
		cin >> buffer;

		rankings[i] = ((int)buffer) - 48;
		j = i - 1;

		if (rankings[i] > maxRanking)
		{
			cout << "\nThe maximum allowable ranking is " << to_string(maxRanking);
			i--;
		}
		else if (rankings[i] < 1)
		{
			cout << "\nThe minimum allowable ranking is 1";
			i--;
		}
		else
		{
			while (j >= 0)
			{
				if (rankings[i] == rankings[j])
				{
					cout << "\nYou've already used that ranking";
					i--;
					break;
				}

				else
				{
					j--;
				}

			}
		}
		i++;
	}

	cout << "\nYour rankings have been received \n\n";
	cout << "\n___________________________________________________________________\n";

	// need to send rankings array to Student object

	displayUserOptions();
}


void Home::sendAvailableCourses(Course** availCourses)
{
	cout << "\n--Home received available courses from CourseManager\n";

	availableCourses = availCourses;

	displayAvailableCourses();
}

void Home::displayAvailableCourses()
{
	cout << "\n___________________________________________________________________\n";
	cout << "\nThe courses available to register are \n\n";

	for (int i = 0; i < courseMan->numAvailableCourses; i++)
	{
		cout << to_string(i + 1) << ". " << availableCourses[i]->getName() << "\n";
	}

	cout << "\n\nEnter a course number to view details, or enter 0 to return to home screen.\n";
	char input;
	cin >> input;

	while (input < 48 || input > courseMan->numAvailableCourses + 48) {
		cout << "\nPlease select a valid option\n";
		cin >> input;
	}
	if (input == '0') {
		displayUserOptions();
	}
	else
	{
		availableCourses[input - 49]->getCourseInformation(this);

		displayCourseInformation();

	}

}

void Home::sendCourseInformation(courseInfo course) {
	courseInformation = course;
}

void Home::displayCourseInformation()
{
	cout << "\nCourse name: " << courseInformation.courseName << "\nNumber of seats: " << to_string(courseInformation.numMaxStudentsAllowed) << "\nNumber enrolled: "
		<< to_string(courseInformation.numEnrolledStudents) << "\nDiscipline: " << courseInformation.disciplineBelongsTo << "\n";
}