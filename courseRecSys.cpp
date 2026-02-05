#include <iostream>
#include <vector>
#include <string>
#include <limits>
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
while (true)
{
    printMainMenu();
    int menuChoice = getIntInRange("Enter choice: ", 1, 2);

    if (menuChoice == 1)
    {
        printInterestMenu();
        int interest = getIntInRange("Choose interest: ", 1, 3);

        printSkillMenu();
        int skill = getIntInRange("Choose skill: ", 1, 3);

        vector<Course> recs = recommendCourses(catalog, interest, skill);

        for (int i = 0; i < recs.size(); i++)
            cout << i + 1 << ". " << recs[i].name << "\n";

        int pick = getIntInRange("Select course: ", 1, recs.size());
        printCourseCard(recs[pick - 1]);
    }
    else
        break;
}



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


void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getIntInRange(const string &prompt, int lo, int hi)
{
    while (true)
    {
        cout << prompt;
        int x;
        if (cin >> x && x >= lo && x <= hi)
        {
            clearInput();
            return x;
        }
        cout << "Invalid input. Try again.\n";
        clearInput();
    }
}

void printInterestMenu()
{
    cout << "\nSelect Interest Area:\n";
    for (int i = 0; i < kInterestAreas.size(); i++)
        cout << i + 1 << ". " << kInterestAreas[i] << "\n";
}

void printSkillMenu()
{
    cout << "\nSelect Skill Level:\n";
    cout << "1. Beginner\n2. Intermediate\n3. Advanced\n";
}

vector<Course> recommendCourses(const vector<Course> &catalog, int interestArea, int skillLevel)
{
    string level = kSkillLevels[skillLevel - 1];
    vector<Course> matches;
	void viewAllCourses(const vector<Course> &catalog)
{
    for (const auto &c : catalog)
    {
        cout << c.name << " (" << c.level << ")\n";
    }
}


    for (const auto &c : catalog)
    {
        if (matches.size() < 3)
{
    for (const auto &c : catalog)
    {
        if (c.interestArea == interestArea && c.level != level)
            matches.push_back(c);
        if (matches.size() == 3)
            break;
    }
}

    }
    return matches;
}


void printCourseCard(const Course &c)
{
    cout << "\nCourse Name: " << c.name
         << "\nDuration: " << c.duration
         << "\nSkill Level: " << c.level
         << "\nPlatform: " << c.platform << "\n";
}
