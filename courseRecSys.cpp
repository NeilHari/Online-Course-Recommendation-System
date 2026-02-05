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
    return 0;
}
