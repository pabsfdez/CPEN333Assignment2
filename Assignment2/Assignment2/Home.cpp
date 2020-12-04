#include "Home.h"
#include "Student.h"
#include "Database.h"

Home::Home()
{
}

// Login calls this function when the user who signed in is a Student
void Home::sendStudentInfo(Student* S)
{

	student = S;
	displayStudentOptions();
}

// if the user is type Student, this function displays the options for a student
void Home::displayStudentOptions()
{

	cout << "\n--Home displaying options for user of account type Student";

	char input;
	cout << "\n___________________________________________________________________\n";
	cout << "\nWhat would you like to do?\n" << "1. Rank disciplines\n2. View available courses\n3. View financial summary\n\n";
	cin >> input;

	// ensure valid selection input
	while (input != '1' && input != '2' && input != '3') {
		cout << "Please select a valid option by entering a number from 1 to 3\n";
		cin >> input;
	}

	if (input == '1') { // Student selected to rank disciplines
		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending request for available disciplines to DisciplineManager\n";

		selectRankDisciplines();
	}

	else if (input == '2') { // Student selected to view courses
		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending request for available courses to CourseManager\n";

		selectViewCourses();
	}

	else if (input == '3') { // Student selected to view financial summary
		cout << "\n___________________________________________________________________\n";

		selectViewFinancialSummary();
	}



}

// function gets called when student selects "rank disciplines"
// Home requests list of disciplines from DisciplineManager
void Home::selectRankDisciplines()
{
	cout << "\n--Home sending request for available disciplines from DisciplineManager\n";

	disMan->getAvailableDisciplines(this);
}


// function gets called when student selects "view courses"
// Home requests list of available courses from CourseManager
void Home::selectViewCourses()
{
	cout << "\n--Home sending request for available courses from CourseManager\n";

	courseMan->getAvailableCourses(this);
}


// DisciplineManager calls this function to store available disciplines in Home
void Home::sendAvailableDisciplines(Discipline** availDisciplines)
{

	availableDisciplines = availDisciplines;
	cout << "\n--Home sending request to display disciplines to Home\n";

	displayDisciplines();
}

// Home displays available disciplines for ranking to Student
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

// Student enters their rankings for each discipline
void Home::sendDisciplineRankings()
{
	int rankings[3]; // array to store rankings
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

		if (rankings[i] > maxRanking) // make sure ranking is within bounds
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
			while (j >= 0) // make sure they haven't used that ranking number already
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

	cout << "\n--Home sending discipline rankings to Student\n";
	student->setDisciplineRanking(0, rankings[0]);
	student->setDisciplineRanking(1, rankings[1]);
	student->setDisciplineRanking(2, rankings[2]);

	displayStudentOptions();
}

// CourseManager calls this function to store available courses in Home
void Home::sendAvailableCourses(Course** availCourses)
{
	cout << "\n--Home received available courses from CourseManager\n";

	availableCourses = availCourses;

	cout << "\n--Home sending request to display available courses to Home\n";
	displayAvailableCourses();
}

// Home displays available courses to register to Student
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

	// ensure valid input
	while (input < 48 || input > courseMan->numAvailableCourses + 48) { // 48 needed because input is a char
		cout << "\nPlease select a valid option\n";
		cin >> input;
	}
	if (input == '0') {
		displayStudentOptions();
	}
	else
	{
		// request information on selected course
		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending request for course info to Course\n\n";
		availableCourses[input - 49]->getCourseInformation(this);

		cout << "\n--Home sending request to display course info to Home\n\n";

		cout << "\n___________________________________________________________________\n";

		displayCourseInformation();


	}

}

// Course calls this function to store its information in Home
void Home::sendCourseInformation(courseInfo courseInf, Course* C) {
	courseInformation = courseInf;
	course = C;
}

// Home displays course info to Student
void Home::displayCourseInformation()
{
	cout << "\nCourse name: " << courseInformation.courseName << "\nNumber of seats: " << to_string(courseInformation.numMaxStudentsAllowed) << "\nNumber enrolled: "
		<< to_string(courseInformation.numEnrolledStudents) << "\nDiscipline: " << courseInformation.disciplineBelongsTo << "\n";


	cout << "\n\nEnter 1 to register course. Enter 0 to return to home page.\n";

	char input;
	cin >> input;

	// ensure valid input
	while (input != '1' && input != '0') {
		cout << "\nPlease select a valid option\n";
		cin >> input;
	}
	if (input == '0') {
		cout << "\n--Home sending request to display student options to Home\n";

		displayStudentOptions();
	}
	else if (input == '1') // student has selected to register course
	{
		cout << "\n___________________________________________________________________\n";

		cout << "\n--Home sending registration info to course\n";
		course->sendRegistrationInfo(student, this); // Home sends Student info to course; course will check that Student is able to register

	}
}

// Course calls this function if the student is ineligible to register course
void Home::sendUnableToRegisterCourseError(char* msg)
{
	cout << "\n\nUnable to register course due to: " << msg << "\nPress enter to return to home screen\n";
	getchar();
	getchar();
	cout << "\n___________________________________________________________________\n";

	cout << "\n--Home sending request to display student options to Home\n";

	displayStudentOptions();
}

// Course calls this function if the student has successfully registered
void Home::sendRegisterConfirmationMsg()
{
	cout << "\n--Home displaying confirmation message\n";

	cout << "\n___________________________________________________________________\n";
	cout << "\n\nSuccessfully registered in course\n";
	cout << "\n___________________________________________________________________\n";

	cout << "\n--Home sending request to display student options to Home\n";

	displayStudentOptions();

}

// function gets called when student selects "view financial summary"
// Home requests student's financial summary from Student
void Home::selectViewFinancialSummary()
{
	cout << "\n--Home sending request to get financial info to Student\n";

	student->getFinancialSummary(this);
}

// Student calls this function to store its financial summary in Home
void Home::sendFinancialSummary(int balance)
{
	cout << "\n--Home sending request to display financial summary to Home\n";
	cout << "\n___________________________________________________________________\n";

	displayFinancialSummary(balance);
}

// Home displays financial summary to Student
void Home::displayFinancialSummary(int balance)
{
	cout << "\nYour current UBC account balance is: $" << to_string(balance);


	cout << "\n\nEnter 1 to pay off balance. Enter 0 to return to home screen.\n";
	char input;
	cin >> input;

	// ensure valid input
	while (input < 48 || input > courseMan->numAvailableCourses + 48) {
		cout << "\nPlease select a valid option\n";
		cin >> input;
	}
	if (input == '0') {
		cout << "\n___________________________________________________________________\n";

		cout << "\n--Home sending request to display student options to Home\n";
		cout << "\n___________________________________________________________________\n";

		displayStudentOptions();
	}
	else
	{
		cout << "\n___________________________________________________________________\n";

		cout << "\n--Home sending request to display payment page to Home\n";
		cout << "\n___________________________________________________________________\n";

		displayPaymentPage();

	}
}

// Home displays payment page to Student
void Home::displayPaymentPage()
{
	int pay;
	int cc;
	cout << "\n\nEnter the amount you would like to pay\n";
	cin >> pay;
	cout << "\n\nEnter your credit card number\n";
	cin >> cc;

	cout << "\n___________________________________________________________________\n";
	cout << "\n--Home sending updated financial info to Student\n";

	// Home updates Student's financial info to reflect the amount they've paid
	student->changeFinancialBalance(pay);
	cout << "\n___________________________________________________________________\n";

	cout << "\n\nYour payment was successful.\n";
	cout << "\n___________________________________________________________________\n";

	cout << "\n--Home sending request to display student options to Home\n";

	displayStudentOptions();
}


////////////////////////////////////////////////////////////////////////////
//						Professor										  //
////////////////////////////////////////////////////////////////////////////

// Login calls this function when the user who signed in is a Prof
void Home::sendProfessorInfo(Professor* P)
{
	cout << "\n--Home has received account: " << P->getName() << " from Login" << "\n";

	professor = P;
	displayProfessortOptions();
}

// Home displays the options available for a Prof
void Home::displayProfessortOptions()
{
	cout << "\n--Home displaying options for user of account type Professor";

	char input;
	cout << "\n___________________________________________________________________\n";
	cout << "\nWhat would you like to do?\n" << "1. Submit Grade\n2. Report Misconduct\n3. Assign Student to Discipline\n\n";
	cin >> input;

	// ensure valid input
	while (input != '1' && input != '2' && input != '3') {
		cout << "Please select a valid option by entering a number from 1 to 3\n";
		cin >> input;
	}

	if (input == '1') {
		cout << "\n___________________________________________________________________\n";

		selectSubmitGrades();
	}

	else if (input == '2') {
		cout << "\n___________________________________________________________________\n";

		selectReportMisconduct();
	}

	else if (input == '3') {
		cout << "\n___________________________________________________________________\n";

		selectAssignDiscipline();
	}
}

// function gets called when Prof  selects "submit grades"
void Home::selectSubmitGrades()
{
	cout << "\n--Home sending request for list of students to Database\n";

	// Home requests list of students from Database
	DB->getListOfStudents(this);
	cout << "\n___________________________________________________________________\n";

	// Home asks Prof which student to submit grade for
	cout << "\nSelect Student to submit grade:\n";

	for (int i = 0; i < 3; i++)
	{
		cout << to_string(i + 1) << ". " << listOfStudents[i]->getName() << "\n";
	}
	int stu;
	cout << "\nSelect student to submit grade\n\n";
	cin >> stu;

	// ensure valid input
	while (stu != 1 && stu != 2 && stu != 3) {
		cout << "Please select a valid option by entering a number from 1 to 3\n";
		cin >> stu;
	}

	
	cout << "\n___________________________________________________________________\n";

	cout << "\n--Home sending request to display enter grade message to Home\n";
	cout << "\n___________________________________________________________________\n";

	displayStudentProfileGrade(stu);

	
}

// Database calls this function to send a list of students to Home
void Home::sendListOfStudents(Student** list) 
{
	listOfStudents = list;
}

// Home calls this function when Prof selects a student to enter a grade for
void Home::displayStudentProfileGrade(int stuIndex)
{
	int input;
	cout << "\nEnter grade for " << listOfStudents[stuIndex-1]->getName() << "\n";
	cout << "Grade: ";
	cin >> input;
	cout << "\n___________________________________________________________________\n";

	cout << "\n--Home sending update grade to Student\n";

	// home stores the grade in Student's grade array
	listOfStudents[stuIndex-1]->setGrade(input, 0);

	displayProfessortOptions();
}

// Function gets called when Prof selects "report academic misconduct"
void Home::selectReportMisconduct()
{
	cout << "\n--Home sending request for list of students to Database\n";

	// Home requests list of all students from Database
	DB->getListOfStudents(this);
	cout << "\n___________________________________________________________________\n";

	cout << "\nSelect Student to report misconduct:\n";

	// show list of students to Prof
	for (int i = 0; i < 3; i++)
	{
		cout << to_string(i + 1) << ". " << listOfStudents[i]->getName() << "\n";
	}
	int stu;
	cin >> stu;

	// ensure valid input
	while (stu != 1 && stu != 2 && stu != 3) {
		cout << "Please select a valid option by entering a number from 1 to 3\n";
		cin >> stu;
	}

	cout << "\n___________________________________________________________________\n";

	cout << "\n--Home sending request to display confirmation message to Home\n";

	cout << "\n___________________________________________________________________\n";
	displayStudentProfileMisconduct(stu);
}

// Function gets called when Prof selects a student a student to report for misconduct
void Home::displayStudentProfileMisconduct(int stuIndex)
{
	// Home asks for confirmation to report misconduct
	int input;
	cout << "Report academic misconduct incident for " << listOfStudents[stuIndex - 1]->getName() << "?\n";
	cout << "Enter 1 for yes. Enter 0 for no.\n";
	cin >> input;

	// ensure valid input
	while (input != 0 && input != 1) {
		cout << "Enter 1 for yes. Enter 0 for no.\n";
		cin >> input;
	}

	if (input == 1)
	{
		cout << "Incident reported\n";

		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending update of misconduct to Student\n";

		// Home updates Student's info to reflect misconduct
		listOfStudents[stuIndex - 1]->incrementCheatingStrikes();
		

		displayProfessortOptions();
	}
	else if (input == 0)
	{
		displayProfessortOptions();
	}
}

// Function gets called when Prof selects "Assign discipline"
void Home::selectAssignDiscipline()
{
	cout << "\n--Home sending request for list of students to Database\n";

	// Home requests a list of all students from Database
	DB->getListOfStudents(this);
	cout << "\n--Home sending request to display student list to Home\n";
	cout << "\n___________________________________________________________________\n";

	cout << "\nSelect Student to assign Discipline:\n";

	// display list of students to Prof
	for (int i = 0; i < 3; i++)
	{
		cout << to_string(i + 1) << ". " << listOfStudents[i]->getName() << "\n";
	}
	int stu;
	cin >> stu;

	// ensure valid input
	while (stu != 1 && stu != 2 && stu != 3) {
		cout << "Please select a valid option by entering a number from 1 to 3\n";
		cin >> stu;
	}


	cout << "\n___________________________________________________________________\n";
	displayStudentProfileDiscipline(stu);
}

// Function gets called when Prof selects which student to assign a discipline to
void Home::displayStudentProfileDiscipline(int stuIndex)
{ 
	// Display Disciplines
	cout << "\n--Home sending request available disciplines to DisciplineManager\n";
	cout << "\n___________________________________________________________________\n";


	int input;
	cout << "\nAssign discipline for " << listOfStudents[stuIndex - 1]->getName() << "\n";
	char mech[50] = "Mechanical";
	char elec[50] = "Electrical";
	char cpen[50] = "Computer";

	cout << "\n1. Mechanical\n2. Electrical\n3. Computer\n";

	cin >> input;

	// ensure valid input
	while (input != 1 && input != 2 && input !=3) {
		cout << "Enter 1, 2 or 3.\n";
		cin >> input;
	}

	// update Student's discipline according to which discipline they've selected
	if (input == 1)
	{
		cout << listOfStudents[stuIndex - 1]->getName() << " assigned to Mechanical\n";
		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending update discipline to Student\n";

		listOfStudents[stuIndex - 1]->setDiscipline(mech);

	}
	else if (input == 2)
	{
		cout << listOfStudents[stuIndex - 1]->getName() << " assigned to Electrical\n";
		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending update discipline to Student\n";
		listOfStudents[stuIndex-1]->setDiscipline(elec);


	}
	else if (input == 3)
	{
		cout << listOfStudents[stuIndex - 1]->getName() << " assigned to Computer\n";
		cout << "\n___________________________________________________________________\n";
		cout << "\n--Home sending update discipline to Student\n";
		listOfStudents[stuIndex-1]->setDiscipline(cpen);


	}
	displayProfessortOptions();
}


////////////////////////////////////////////////////////////////////////////
//						Dean											  //
////////////////////////////////////////////////////////////////////////////

// Login calls this function when the user who signed in is the Dean
void Home::sendDeanInfo(Dean* D)
{
	cout << "\n--Home has received account: " << D->getName() << " from Login" << "\n";

	dean = D;
	cout << "\n--Home sending request to display Dean options to Home\n";

	displayDeanOptions();
}

// Home displays options for the Dean
void Home::displayDeanOptions()
{
	cout << "\n--Home displaying options for user of account type Dean\n";

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

		selectSuspendStudent();
	}
}


// Function gets called when Dean selects "suspend student"
void Home::selectSuspendStudent()
{

	cout << "\n--Home sending request for student list to Database\n";

	// Home gets list of all students from Database
	DB->getListOfStudents(this);
	cout << "\n--Home sending request to display list of students to Home\n";
	cout << "\n___________________________________________________________________\n";


	cout << "\nSelect Student to suspend:\n";

	// Home displays all students
	for (int i = 0; i < 3; i++)
	{
		cout << to_string(i + 1) << ". " << listOfStudents[i]->getName() << "\n";
	}
	int stu;
	cin >> stu;

	// ensure valid input
	while (stu != 1 && stu != 2 && stu != 3) {
		cout << "Please select a valid option by entering a number from 1 to 3\n";
		cin >> stu;
	}


	cout << "\n___________________________________________________________________\n";

	cout << "\n--Home sending request to display confirm suspendsion message to Home\n";

	displayStudentProfileSuspend(stu);
}

// Function gets called when Dean has selected which student to suspend
void Home::displayStudentProfileSuspend(int stuIndex)
{
	int input;
	cout << "\n___________________________________________________________________\n";

	cout << "Suspend " << listOfStudents[stuIndex - 1]->getName() << "?\n";
	cout << "Enter 1 for yes. Enter 0 for no.\n";
	cin >> input;

	// ensure valid input
	while (input != 0 && input != 1) {
		cout << "Enter 1 for yes. Enter 0 for no.\n";
		cin >> input;
	}

	if (input == 1)
	{

		if (listOfStudents[stuIndex - 1]->getSuspensionStatus() == true) // if student is already suspended
		{
			cout << listOfStudents[stuIndex - 1]->getName() << " is already suspended.\n";
		}
		else
		{

			cout << listOfStudents[stuIndex - 1]->getName() << " has been suspended and can no longer register in courses.\n";
			cout << "\n___________________________________________________________________\n";

			cout << "\n--Home sending student suspension status to Student\n";

			// update Student info to reflect suspension
			listOfStudents[stuIndex - 1]->setSuspensionStatus(true);
		}

		displayDeanOptions();
	}
	else if (input == 0)
	{
		displayDeanOptions();
	}
}