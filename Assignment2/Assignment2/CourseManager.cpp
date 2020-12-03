#include "CourseManager.h"
#include "Home.h"

CourseManager::CourseManager()
{


}

void CourseManager::getAvailableCourses(Home* home) {

	cout << "\nCourseManager sending array of available courses to Home\n";
	home->sendAvailableCourses(courses);
}


