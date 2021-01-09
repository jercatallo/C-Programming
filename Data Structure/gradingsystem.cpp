#include <iostream>
using namespace std;

int main(){
    string student_name,verdict;
    float programming_grade, filipino_grade,math_grade,english_grade, science_grade,average;

    cout<<"Enter Student Name: ";cin>>student_name;
    cout<<"Enter Programming Grade: ";cin>>programming_grade;
    cout<<"Enter Filipino Grade: ";cin>>filipino_grade;
    cout<<"Enter Math Grade: ";cin>>math_grade;
    cout<<"Enter Science Grade: ";cin>>science_grade;
    cout<<"Enter English Grade: ";cin>>english_grade;

    average = (programming_grade + filipino_grade + math_grade + english_grade + science_grade) / 5;

    if(average <75 && average >= 65){
        verdict = "Failed";
    }else if(average>=75 && average <100){
        verdict = "Passed";
    }

    cout<<"The average grade of "<<student_name<<" "<<average<<" and he/she "<<verdict<<" the semester";

}