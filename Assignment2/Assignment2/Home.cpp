#include "Home.h"
#include "Student.h"

Home::Home()
{


}

void Home::sendStudentInfo(Student* S)
{
	cout << "\n--Home has received account: " << S->getName() << " from Login" << "\n";

	student = S;
	displayStudentOptions();
}

void Home::displayStudentOptions()
{

	cout << "\n--Home displaying options for user of account type Student";

	char input;
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

	displayStudentOptions();
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
		displayStudentOptions();
	}
	else
	{
		availableCourses[input - 49]->getCourseInformation(this);

		displayCourseInformation();


	}

}

void Home::sendCourseInformation(courseInfo courseInf, Course* C) {
	courseInformation = courseInf;
	course = C;
}

void Home::displayCourseInformation()
{
	cout << "\nCourse name: " << courseInformation.courseName << "\nNumber of seats: " << to_string(courseInformation.numMaxStudentsAllowed) << "\nNumber enrolled: "
		<< to_string(courseInformation.numEnrolledStudents) << "\nDiscipline: " << courseInformation.disciplineBelongsTo << "\n";


	cout << "\n\nEnter 1 to register course. Enter 0 to return to home page.\n";

	char input;
	cin >> input;

	while (input != '1' && input != '0') {
		cout << "\nPlease select a valid option\n";
		cin >> input;
	}
	if (input == '0') {
		displayStudentOptions();
	}
	else if (input == '1')
	{
		course->sendRegistrationInfo(student, this);

	}
}


void Home::sendUnableToRegisterCourseError(char* msg)
{
	cout << "\n\nUnable to register course due to: " << msg << "\nPress enter to return to home screen\n";
	getchar();
	getchar();
	cout << "\n___________________________________________________________________\n";

	displayStudentOptions();
}


void Home::sendRegisterConfirmationMsg()
{
	cout << "\n\nSuccessfully registered in course\n";
	cout << "\n___________________________________________________________________\n";

	displayStudentOptions();

}
