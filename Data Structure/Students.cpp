#include <iostream>

using namespace std;
    struct StudentRecord{ //Creating a Struct for Student Record
        int student_number;
        char grade;

        int* student_number_pointer = &student_number; //Creating pointer to store the memory address of STUDENT_ONE.student_number
        char* student_grade_pointer = &grade;   //Creating pointer to store the memory address of STUDENT_ONE.grade
    
        void record(int _student_number,int _grade){
            //Altering the value of the goods using its pointers
            *student_number_pointer = _student_number; // using pointer, assigning a new value for the specific memory adress(STUDENT_ONE.student_number)
            *student_grade_pointer = _grade; // using pointer, assigning a new value for the specific memory adresss (STUDENT_ONE.grade)
        }   

        void Details(){
            cout<<"Details of students as follows:\n";
            cout<<"Student Number: "<<student_number<<endl; // now the value of the memory address is now altered 
            cout<<"Grade: "<<grade<<endl; // now the value of the memory address is now altered 
        }
    };

int main(){
    StudentRecord STUDENT_ONE; // Creating instance of StudentRecord as STUDENT_ONE

    int student_number_val;  char student_grade_val; // Declaring variables to store the values the input of Student Number and Student Grade

    cout<<"Input Student number: ";cin>>student_number_val;// Inputing the Student Number Value
    cout<<"Input Student grade: ";cin>>student_grade_val;// Inputing the Student Grade Value

    STUDENT_ONE.record(student_number_val,student_grade_val); // Assigning Values to the records

    STUDENT_ONE.Details(); // Displaying the Details
 
}