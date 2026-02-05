#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
    "Business & Management",
    "Medicine",
    "Academia",
    "Law",
    "Architecture",
    "Art & Design",
    "Accounting & Finance"};

static const vector<string> kSkillLevels = {
    "Beginner", "Intermediate", "Advanced"};

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
        cout << "Invalid input. Please enter a number from " << lo << " to " << hi << ".\n";
        clearInput();
    }
}

void printMainMenu()
{
    cout << "\nWelcome to Smart Course Advisor\n\n"
         << "1. Get Course Recommendation\n"
         << "2. View All Available Courses\n"
         << "3. Exit\n\n";
}

void printInterestMenu()
{
    cout << "\nSelect Interest Area:\n";
    for (int i = 0; i < (int)kInterestAreas.size(); i++)
    {
        cout << (i + 1) << ". " << kInterestAreas[i] << "\n";
    }
    cout << "\n";
}

void printSkillMenu()
{
    cout << "\nSelect Skill Level:\n";
    cout << "1. Beginner\n";
    cout << "2. Intermediate\n";
    cout << "3. Advanced\n\n";
}

void printCourseCard(const Course &c)
{
    cout << "\nCourse Name: " << c.name
         << "\nDuration: " << c.duration
         << "\nSkill Level: " << c.level
         << "\nPlatform: " << c.platform
         << "\n";
}

vector<Course> buildCourseCatalog()
{
    vector<Course> courses = {
        // 1) CS & IS
        {"Introduction to Python", "8 weeks", "Beginner", "Coursera", 1},
        {"Web Development Basics", "10 weeks", "Beginner", "Coursera", 1},
        {"Database Fundamentals (SQL)", "6 weeks", "Beginner", "edX", 1},
        {"Object-Oriented Programming in C++", "8 weeks", "Intermediate", "Udemy", 1},
        {"Data Structures & Algorithms", "12 weeks", "Intermediate", "Coursera", 1},
        {"Cloud Fundamentals (AWS/Azure)", "6 weeks", "Intermediate", "LinkedIn Learning", 1},
        {"System Design & Architecture", "8 weeks", "Advanced", "Coursera", 1},
        {"Machine Learning Foundations", "12 weeks", "Advanced", "edX", 1},
        {"Secure Software Engineering", "10 weeks", "Advanced", "Coursera", 1},

        // 2) Engineering & Technology
        {"Engineering Math Refresher", "6 weeks", "Beginner", "Khan Academy", 2},
        {"Electronics Basics", "8 weeks", "Beginner", "Udemy", 2},
        {"CAD Basics (AutoCAD)", "6 weeks", "Beginner", "LinkedIn Learning", 2},
        {"Control Systems Intro", "10 weeks", "Intermediate", "Coursera", 2},
        {"Embedded Systems (ARM)", "8 weeks", "Intermediate", "Udemy", 2},
        {"Python for Engineers", "6 weeks", "Intermediate", "Coursera", 2},
        {"Robotics Fundamentals", "12 weeks", "Advanced", "edX", 2},
        {"IoT Systems Design", "10 weeks", "Advanced", "Coursera", 2},
        {"Advanced CAD & Simulation", "8 weeks", "Advanced", "Udemy", 2},

        // 3) Business & Management
        {"Business Communication Essentials", "4 weeks", "Beginner", "Coursera", 3},
        {"Introduction to Marketing", "6 weeks", "Beginner", "edX", 3},
        {"Excel for Business", "5 weeks", "Beginner", "LinkedIn Learning", 3},
        {"Project Management Basics", "8 weeks", "Intermediate", "Coursera", 3},
        {"Digital Marketing Strategy", "8 weeks", "Intermediate", "Udemy", 3},
        {"Data-Driven Decision Making", "6 weeks", "Intermediate", "Coursera", 3},
        {"Leadership & Change Management", "10 weeks", "Advanced", "edX", 3},
        {"Strategic Management", "10 weeks", "Advanced", "Coursera", 3},
        {"Business Analytics Capstone", "12 weeks", "Advanced", "Coursera", 3},

        // 4) Medicine
        {"Medical Terminology Basics", "6 weeks", "Beginner", "Coursera", 4},
        {"Human Anatomy Intro", "8 weeks", "Beginner", "edX", 4},
        {"Evidence-Based Medicine Basics", "4 weeks", "Beginner", "Coursera", 4},
        {"Clinical Research Methods", "8 weeks", "Intermediate", "Coursera", 4},
        {"Pharmacology Essentials", "10 weeks", "Intermediate", "edX", 4},
        {"Public Health Foundations", "8 weeks", "Intermediate", "Coursera", 4},
        {"Advanced Clinical Reasoning", "10 weeks", "Advanced", "Coursera", 4},
        {"Epidemiology & Biostatistics", "12 weeks", "Advanced", "edX", 4},
        {"Healthcare Quality Improvement", "8 weeks", "Advanced", "Coursera", 4},

        // 5) Academia
        {"Academic Writing Basics", "6 weeks", "Beginner", "Coursera", 5},
        {"Critical Thinking Skills", "4 weeks", "Beginner", "edX", 5},
        {"Study Skills for University", "3 weeks", "Beginner", "Coursera", 5},
        {"Research Methods", "8 weeks", "Intermediate", "Coursera", 5},
        {"Literature Review Workshop", "5 weeks", "Intermediate", "Udemy", 5},
        {"Presentation Skills", "4 weeks", "Intermediate", "LinkedIn Learning", 5},
        {"Thesis Writing Masterclass", "10 weeks", "Advanced", "Udemy", 5},
        {"Quantitative Data Analysis", "12 weeks", "Advanced", "edX", 5},
        {"Publishing in Journals", "6 weeks", "Advanced", "Coursera", 5},

        // 6) Law
        {"Intro to Legal Systems", "6 weeks", "Beginner", "Coursera", 6},
        {"Contract Law Basics", "8 weeks", "Beginner", "edX", 6},
        {"Legal Writing Essentials", "5 weeks", "Beginner", "Udemy", 6},
        {"Tort Law & Negligence", "10 weeks", "Intermediate", "Coursera", 6},
        {"Legal Research Skills", "6 weeks", "Intermediate", "LinkedIn Learning", 6},
        {"Business Law Fundamentals", "8 weeks", "Intermediate", "edX", 6},
        {"Advanced Advocacy Skills", "10 weeks", "Advanced", "Udemy", 6},
        {"International Law", "12 weeks", "Advanced", "Coursera", 6},
        {"Compliance & Risk Management", "8 weeks", "Advanced", "Coursera", 6},

        // 7) Architecture
        {"Architecture Basics", "6 weeks", "Beginner", "Coursera", 7},
        {"Sketching for Architects", "4 weeks", "Beginner", "Udemy", 7},
        {"Intro to Building Materials", "6 weeks", "Beginner", "edX", 7},
        {"Revit Fundamentals", "8 weeks", "Intermediate", "LinkedIn Learning", 7},
        {"Sustainable Design Principles", "8 weeks", "Intermediate", "Coursera", 7},
        {"Architectural Visualization", "6 weeks", "Intermediate", "Udemy", 7},
        {"Urban Design Studio", "12 weeks", "Advanced", "edX", 7},
        {"Advanced BIM Workflows", "10 weeks", "Advanced", "Udemy", 7},
        {"Professional Practice in Architecture", "8 weeks", "Advanced", "Coursera", 7},

        // 8) Art & Design
        {"Design Fundamentals", "4 weeks", "Beginner", "Coursera", 8},
        {"Photoshop Basics", "6 weeks", "Beginner", "Udemy", 8},
        {"Intro to UI/UX", "6 weeks", "Beginner", "Coursera", 8},
        {"Branding & Visual Identity", "8 weeks", "Intermediate", "Coursera", 8},
        {"Figma for UI Design", "6 weeks", "Intermediate", "Udemy", 8},
        {"Typography & Layout", "5 weeks", "Intermediate", "LinkedIn Learning", 8},
        {"UX Research & Testing", "8 weeks", "Advanced", "Coursera", 8},
        {"Design Systems Masterclass", "10 weeks", "Advanced", "Udemy", 8},
        {"Portfolio Capstone", "6 weeks", "Advanced", "Coursera", 8},

        // 9) Accounting & Finance
        {"Accounting Basics", "6 weeks", "Beginner", "Coursera", 9},
        {"Personal Finance 101", "4 weeks", "Beginner", "edX", 9},
        {"Excel for Accounting", "5 weeks", "Beginner", "LinkedIn Learning", 9},
        {"Financial Statement Analysis", "8 weeks", "Intermediate", "Coursera", 9},
        {"Corporate Finance Fundamentals", "8 weeks", "Intermediate", "edX", 9},
        {"Budgeting & Forecasting", "6 weeks", "Intermediate", "Udemy", 9},
        {"Advanced Financial Modeling", "10 weeks", "Advanced", "Udemy", 9},
        {"Investment Analysis", "12 weeks", "Advanced", "Coursera", 9},
        {"Risk & Portfolio Management", "10 weeks", "Advanced", "edX", 9},
    };

    return courses;
}

vector<Course> recommendCourses(const vector<Course> &catalog, int interestArea, int skillLevel /*1..3*/)
{
    string level = kSkillLevels[skillLevel - 1];

    vector<Course> matches;
    for (const auto &c : catalog)
    {
        if (c.interestArea == interestArea && c.level == level)
        {
            matches.push_back(c);
        }
    }

    auto addFromLevel = [&](const string &lvl)
    {
        for (const auto &c : catalog)
        {
            if ((int)matches.size() >= 3)
                break;
            if (c.interestArea == interestArea && c.level == lvl)
            {
                // prevent duplicates by name
                auto it = find_if(matches.begin(), matches.end(),
                                  [&](const Course &x)
                                  { return x.name == c.name; });
                if (it == matches.end())
                    matches.push_back(c);
            }
        }
    };

    if ((int)matches.size() < 3)
    {
        if (skillLevel == 1)
        {
            addFromLevel("Intermediate");
        }
        else if (skillLevel == 2)
        {
            addFromLevel("Beginner");
            addFromLevel("Advanced");
        }
        else
        { // Advanced
            addFromLevel("Intermediate");
        }
    }

    if ((int)matches.size() < 3)
    {
        for (const auto &c : catalog)
        {
            if ((int)matches.size() >= 3)
                break;
            if (c.interestArea == interestArea)
                matches.push_back(c);
        }
    }

    if ((int)matches.size() > 3)
        matches.resize(3);
    return matches;
}

void viewAllCourses(const vector<Course> &catalog)
{
    cout << "\n=== All Available Courses ===\n";
    for (const auto &c : catalog)
    {
        cout << "\n[" << c.interestArea << "] " << kInterestAreas[c.interestArea - 1]
             << "\n- " << c.name
             << "\n  Duration: " << c.duration
             << "\n  Level: " << c.level
             << "\n  Platform: " << c.platform
             << "\n";
    }
    cout << "\n=============================\n";
}

int main()
{
    vector<Course> catalog = buildCourseCatalog();

    while (true)
    {
        printMainMenu();

        int menuChoice = getIntInRange("Enter your choice (1-3): ", 1, 3);

        switch (menuChoice)
        {
        case 1:
        {
            bool done = false;
            while (!done)
            {
                printInterestMenu();
                int interest = getIntInRange("Choose interest area (1-9): ", 1, 9);

                printSkillMenu();
                int skill = getIntInRange("Choose skill level (1-3): ", 1, 3);

                vector<Course> recs = recommendCourses(catalog, interest, skill);

                cout << "\nRecommended Courses [Select A Course Below to Learn More]:\n";
                for (int i = 0; i < (int)recs.size(); i++)
                {
                    cout << (i + 1) << ". " << recs[i].name << "\n";
                }
                cout << "\n";

                int courseChoice = getIntInRange("Select a course (1-3) to view details: ", 1, (int)recs.size());
                printCourseCard(recs[courseChoice - 1]);

                cout << "\nWhat would you like to do next?\n"
                     << "1. Accept these recommendations (Back to main menu)\n"
                     << "2. Retry (Choose interest/skill again)\n\n";

                int next = getIntInRange("Enter choice (1-2): ", 1, 2);
                if (next == 1)
                    done = true;
            }
            break;
        }
        case 2:
        {
            viewAllCourses(catalog);
            break;
        }
        case 3:
        { // Exit
            cout << "\nThanks for using Smart Course Advisor. Bye!\n";
            return 0;
        }
        default:
            break;
        }
    }
}
