#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string studentName, rollNo;
    int numCourses;

    cout << "Enter Student Name: ";
    cin >> studentName;  // Single-word name

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    cout << "Enter Number of Courses: ";
    cin >> numCourses;

    string subject[50];
    float grade[50];
    int credit[50];

    float totalGradePoints = 0;
    int totalCredits = 0;

    // Input Course Details
    for(int i = 0; i < numCourses; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Subject Name: ";
        cin >> subject[i];

        cout << "Enter Grade Point: ";
        cin >> grade[i];

        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        totalGradePoints += grade[i] * credit[i];
        totalCredits += credit[i];
    }

    // GPA Calculation
    float semesterGPA = totalGradePoints / totalCredits;

    // Previous Record
    float previousCGPA;
    int previousCredits;

    cout << "\nEnter Previous CGPA: ";
    cin >> previousCGPA;

    cout << "Enter Previous Total Credits: ";
    cin >> previousCredits;

    float overallCGPA =
        ((previousCGPA * previousCredits) + totalGradePoints) /
        (previousCredits + totalCredits);

    // Display Report
    cout << "\n\n========== STUDENT REPORT ==========\n";

    cout << "Student Name : " << studentName << endl;
    cout << "Roll Number  : " << rollNo << endl;

    cout << "\nCourse Details:\n";

    cout << left
         << setw(15) << "Subject"
         << setw(15) << "Grade"
         << setw(15) << "Credits"
         << endl;

    cout << "-------------------------------------\n";

    for(int i = 0; i < numCourses; i++)
    {
        cout << left
             << setw(15) << subject[i]
             << setw(15) << grade[i]
             << setw(15) << credit[i]
             << endl;
    }

    cout << "\nTotal Credits : " << totalCredits << endl;
    cout << "Semester GPA  : " << fixed << setprecision(2)
         << semesterGPA << endl;
    cout << "Overall CGPA  : " << overallCGPA << endl;

    return 0;
}
