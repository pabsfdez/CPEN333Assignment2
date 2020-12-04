#include "CourseManager.h"
#include "Home.h"

CourseManager::CourseManager()
{


}

// this function called by Home to get the list of all available courses
void CourseManager::getAvailableCourses(Home* home) {

	cout << "\n--CourseManager sending array of available courses to Home\n";
	home->sendAvailableCourses(courses);
}


