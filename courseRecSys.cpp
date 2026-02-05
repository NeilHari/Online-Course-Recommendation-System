#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Course
{
    string name;
    string duration;
    string level;
    string platform;
    int interestArea;
};

static const vector<string> kInterestAreas = {
    "Computer Science & Information Systems",
    "Engineering & Technology",
    "Business & Management"};

static const vector<string> kSkillLevels = {
    "Beginner", "Intermediate", "Advanced"};

int main()
{
    cout << "Smart Course Advisor\n";
	vector<Course> catalog = buildCourseCatalog();
	int choice;
printMainMenu();
cin >> choice;


    return 0;
}

vector<Course> buildCourseCatalog()
{
    vector<Course> courses = {
        {"Introduction to Python", "8 weeks", "Beginner", "Coursera", 1},
        {"Data Structures", "12 weeks", "Intermediate", "Coursera", 1},
        {"Engineering Math", "6 weeks", "Beginner", "Khan Academy", 2}};
    return courses;
}

void printMainMenu()
{
    cout << "\n1. Get Course Recommendation\n";
    cout << "2. Exit\n";
}
