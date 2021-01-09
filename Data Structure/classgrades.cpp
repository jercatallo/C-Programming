#include <iostream>
#include <math.h>
using namespace std;

string student_names[10] = {"Claire", "Cheska", "Shaira", "Adrian", "Aden", "Mark", "Rafael"};
int student_count = 0, Grades[10][10] = {{90, 85, 95, 91}, {95, 80, 85, 89}, {91, 92, 97, 89}, {85, 89, 87, 92}, {87, 92, 86, 93}, {80, 78, 77, 75}, {81, 85, 75, 87}};
float average[10], total_class_average;

int main()
{
	cout << "Student Name\t ENGLISH\t MATHEMATICS\t SCIENCE\t ICT\t AVERAGE\t\n";
	cout << "-----------------------------------------------------------------------------------\n";
	for (int i = 0; i < 7; i++, student_count++)
	{
		cout << student_names[i];
		for (int j = 0; j < 4; j++)
		{
			cout << "\t\t " << Grades[i][j];
			average[i] += Grades[i][j];
		}
		average[i] = average[i] / 4;
		cout << "\t  " << average[i] << endl;
		total_class_average += average[i];
	}
	cout << "\n\nTotal No. of Students: " << student_count;
	cout << "\tTotal Class Average: " << roundf((total_class_average / student_count) * 100) / 100 << "\n\n";
}
