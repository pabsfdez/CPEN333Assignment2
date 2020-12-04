#include "Home.h"
#include "Student.h"
#include "Database.h"

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
	cout << "\nWhat would you like to do?\n" << "1. Rank disciplines\n2. View available courses\n3. View financial summary\n\n";
	cin >> input;

	while (input != '1' && input != '2' && input != '3') {
		cout << "Please select a valid option by entering a number from 1 to 3\n";
		cin >> input;
	}

	if (input == '1') {
		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending request for available disciplines to DisciplineManager\n";

		selectRankDisciplines();
	}

	else if (input == '2') {
		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending request for available courses to CourseManager\n";

		selectViewCourses();
	}

	else if (input == '3') {
		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending request for financial summary from Student\n";

		selectViewFinancialSummary();
	}



}

void Home::selectRankDisciplines()
{
	disMan->getAvailableDisciplines(this);
}

void Home::selectViewCourses()
{
	courseMan->getAvailableCourses(this);
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

void Home::selectViewFinancialSummary()
{
	student->getFinancialSummary(this);
}

void Home::sendFinancialSummary(int balance)
{
	displayFinancialSummary(balance);
}

void Home::displayFinancialSummary(int balance)
{
	cout << "\nYour current UBC account balance is: $" << to_string(balance);


	cout << "\n\nEnter 1 to pay off balance. Enter 0 to return to home screen.\n";
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

		displayPaymentPage();

	}
}


void Home::displayPaymentPage()
{
	int pay;
	int cc;
	cout << "\n\nEnter the amount you would like to pay\n";
	cin >> pay;
	cout << "\n\nEnter your credit card number\n";
	cin >> cc;

	student->changeFinancialBalance(pay);
	cout << "\n\nYour payment was successful.\n";

	displayStudentOptions();
}


////////////////////////////////////////////////////////////////////////////
//						Professor										  //
////////////////////////////////////////////////////////////////////////////
void Home::sendProfessorInfo(Professor* P)
{
	cout << "\n--Home has received account: " << P->getName() << " from Login" << "\n";

	professor = P;
	displayProfessortOptions();
}

void Home::displayProfessortOptions()
{
	cout << "\n--Home displaying options for user of account type Professor";

	char input;
	cout << "\n___________________________________________________________________\n";
	cout << "\nWhat would you like to do?\n" << "1. Submit Grade\n2. Report Misconduct\n3. Assign Student to Discipline\n\n";
	cin >> input;

	while (input != '1' && input != '2' && input != '3') {
		cout << "Please select a valid option by entering a number from 1 to 3\n";
		cin >> input;
	}

	if (input == '1') {
		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending request to submit grades to Home\n";

		selectSubmitGrades();
	}

	else if (input == '2') {
		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending request to report misconduct to Home\n";

		selectReportMisconduct();
	}

	else if (input == '3') {
		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending request to assign discipline to Home\n";

		selectAssignDiscipline();
	}
}

void Home::selectSubmitGrades()
{
	cout << "\nSelect Student to submit grade:\n";

	DB->getListOfStudents(this);

	for (int i = 0; i < 3; i++)
	{
		cout << to_string(i + 1) << ". " << listOfStudents[i]->getName() << "\n";
	}
	int stu;
	cout << "\nSelect student to submit grade\n\n";
	cin >> stu;

	while (stu != 1 && stu != 2 && stu != 3) {
		cout << "Please select a valid option by entering a number from 1 to 3\n";
		cin >> stu;
	}

	
	cout << "\n___________________________________________________________________\n";
	displayStudentProfileGrade(stu);

	
}


void Home::sendListOfStudents(Student** list) 
{
	listOfStudents = list;
}

void Home::displayStudentProfileGrade(int stuIndex)
{
	int input;
	cout << "Enter grade for " << listOfStudents[stuIndex-1]->getName() << "\n";
	cout << "Grade: ";
	cin >> input;

	listOfStudents[stuIndex-1]->setGrade(input, 0);
}

void Home::selectReportMisconduct()
{
	cout << "\nSelect Student to report misconduct:\n";

	DB->getListOfStudents(this);

	for (int i = 0; i < 3; i++)
	{
		cout << to_string(i + 1) << ". " << listOfStudents[i]->getName() << "\n";
	}
	int stu;
	cin >> stu;

	while (stu != 1 && stu != 2 && stu != 3) {
		cout << "Please select a valid option by entering a number from 1 to 3\n";
		cin >> stu;
	}


	cout << "\n___________________________________________________________________\n";
	displayStudentProfileMisconduct(stu);
}

void Home::displayStudentProfileMisconduct(int stuIndex)
{
	int input;
	cout << "Report academic misconduct incident for " << listOfStudents[stuIndex - 1]->getName() << "?\n";
	cout << "Enter 1 for yes. Enter 0 for no.\n";
	cin >> input;
	while (input != 0 && input != 1) {
		cout << "Enter 1 for yes. Enter 0 for no.\n";
		cin >> input;
	}

	if (input == 1)
	{
		listOfStudents[stuIndex - 1]->incrementCheatingStrikes();
		cout << "Incident reported\n";
		displayProfessortOptions();
	}
	else if (input == 0)
	{
		displayProfessortOptions();
	}
}

void Home::selectAssignDiscipline()
{
	cout << "\nSelect Student to assign Discipline:\n";

	DB->getListOfStudents(this);

	for (int i = 0; i < 3; i++)
	{
		cout << to_string(i + 1) << ". " << listOfStudents[i]->getName() << "\n";
	}
	int stu;
	cin >> stu;

	while (stu != 1 && stu != 2 && stu != 3) {
		cout << "Please select a valid option by entering a number from 1 to 3\n";
		cin >> stu;
	}


	cout << "\n___________________________________________________________________\n";
	displayStudentProfileDiscipline(stu);
}

void Home::displayStudentProfileDiscipline(int stuIndex)
{
	//Display Disciplines


	int input;
	cout << "Assign discipline for " << listOfStudents[stuIndex - 1]->getName() << "\n";
	char mech[50] = "Mechanical";
	char elec[50] = "Electrical";
	char cpen[50] = "Computer";

	cout << "\n1. Mechanical\n2. Electrical\n3. Computer\n";

	cin >> input;
	while (input != 1 && input != 2 && input !=3) {
		cout << "Enter 1, 2 or 3.\n";
		cin >> input;
	}

	if (input == 1)
	{
		listOfStudents[stuIndex - 1]->setDiscipline(mech);
		cout << listOfStudents[stuIndex-1]->getName() << " assigned to Mechanical\n";
	}
	else if (input == 2)
	{
		listOfStudents[stuIndex-1]->setDiscipline(elec);
		cout << listOfStudents[stuIndex-1]->getName() << " assigned to Electrical\n";

	}
	else if (input == 3)
	{
		listOfStudents[stuIndex-1]->setDiscipline(cpen);
		cout << listOfStudents[stuIndex-1]->getName() << " assigned to Computer\n";

	}
	displayProfessortOptions();
}


////////////////////////////////////////////////////////////////////////////
//						Dean											  //
////////////////////////////////////////////////////////////////////////////

void Home::sendDeanInfo(Dean* D)
{
	cout << "\n--Home has received account: " << D->getName() << " from Login" << "\n";

	dean = D;
	displayDeanOptions();
}

void Home::displayDeanOptions()
{
	cout << "\n--Home displaying options for user of account type Professor";

	char input;
	cout << "\n___________________________________________________________________\n";
	cout << "\nWhat would you like to do?\n" << "1. Suspend Student\n\n";
	cin >> input;

	while (input != '1') {
		cout << "Please select a valid option by entering a number from 1 to 1\n";
		cin >> input;
	}

	if (input == '1') {
		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending request to submit grades to Home\n";

		selectSuspendStudent();
	}
}



void Home::selectSuspendStudent()
{
	cout << "\nSelect Student to suspend:\n";

	DB->getListOfStudents(this);

	for (int i = 0; i < 3; i++)
	{
		cout << to_string(i + 1) << ". " << listOfStudents[i]->getName() << "\n";
	}
	int stu;
	cin >> stu;

	while (stu != 1 && stu != 2 && stu != 3) {
		cout << "Please select a valid option by entering a number from 1 to 3\n";
		cin >> stu;
	}


	cout << "\n___________________________________________________________________\n";
	displayStudentProfileSuspend(stu);
}


void Home::displayStudentProfileSuspend(int stuIndex)
{
	int input;
	cout << "Suspend " << listOfStudents[stuIndex - 1]->getName() << "?\n";
	cout << "Enter 1 for yes. Enter 0 for no.\n";
	cin >> input;
	while (input != 0 && input != 1) {
		cout << "Enter 1 for yes. Enter 0 for no.\n";
		cin >> input;
	}

	if (input == 1)
	{

		if (listOfStudents[stuIndex - 1]->getSuspensionStatus() == true)
		{
			cout << listOfStudents[stuIndex - 1]->getName() << " is already suspended.\n";
		}
		else
		{
			listOfStudents[stuIndex - 1]->setSuspensionStatus(true);
			cout << listOfStudents[stuIndex - 1]->getName() << " has been suspended and can no longer register in courses.\n";
		}

		displayDeanOptions();
	}
	else if (input == 0)
	{
		displayDeanOptions();
	}
}