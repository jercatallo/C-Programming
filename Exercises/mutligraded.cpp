#include <iostream>
using namespace std;

int main()
{
    int numberOfStudents;
    cout << "How many number of students?";
    cin >> numberOfStudents;

    int student[numberOfStudents][6];

    for (int i = 0; i < numberOfStudents; i++)
    {
        cout << "Enter Graded for student: " << i + 1 << endl;
        for (int j = 0; j < 6; j++)
        {
            cout << "Enter Grades: ";
            cin >> student[i][j];
        }
    }
}