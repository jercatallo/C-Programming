//Pointer implementation
#include <iostream>
#include <string>
#include <stack>

using namespace std;

//Struct Declaration
struct Car{
    string plateNumber, carModel, carColor;
    Car(){};
    Car(string plateNumber, string carModel, string carColor){
        this->plateNumber = plateNumber;
        this->carModel = carModel;
        this->carColor = carColor;
    }
};

//Multidimensional Array
string parkSummary[100][3];
int maxArray = 0, maxStack = 5;

//Queue declaration
//Variables
Car queue[5];
int front = -1, rear = -1, mx = 5; 

//Queue Functions
bool isEmpty();
void enqueue(string inp);
Car dequeue();
void display();

//Function declaration
int mainMenu(stack<Car> car);
void enqueueCar();
void admitCar(stack<Car> *carStack);
void carUnparked(stack<Car> *carStack);
void viewRecords();

int main(){
    stack<Car> carStack;
    stack<Car> *ptrCarStack = &carStack;

    int input = 1;
    do{
        system("CLS");
        input = mainMenu(carStack);
        switch(input){
            case 0:
                system("CLS");
                cout << "Here are all the cars parked today: \n\n";
                viewRecords();
                cout << "\n\n -EXITING PROGRAM-";
                return 0;
            case 1:
                enqueueCar();
                break;
            case 2:
                admitCar(ptrCarStack);
                break;
            case 3:
                carUnparked(ptrCarStack);
                break;
            case 4:
                viewRecords();
                break;
            default:
                cout << "Enter a valid command of 1-4. Enter 0 to exit.";
                break;
        }
    }while(input != 0);
}

//Queue Main Body
bool isEmpty(){
    if (rear == -1 && front == -1){
        return true;
    }
    else {
        return false;
    }
};

void enqueue(Car inp){
    if (isEmpty()){
        front++;
    }
    else if (rear == mx-1){
        cout << "Queue overflow.";
        return;
    }
    rear++;
    queue[rear] = inp;
};

Car dequeue(){
    Car temp;
    if (isEmpty()){
        cout << "Queue is empty!";
    }
    else if (front == rear){
        temp = queue[front];
        cout << queue[front].plateNumber << " has been dequeued. \n";
        front = -1;
        rear = -1;
    }
    else if (front < mx) {
        temp = queue[front];
        cout << queue[front].plateNumber << " has been dequeued. \n";
        front++;
    }
    return temp;
};

void display(){
    if (isEmpty()){
        cout << "There are no cars in queue.";
    }
    else {
        cout << "\n\tThe Queue order is: \n";
        for (int x = front; x <= rear; x++){
            cout << "\tPlate No. " << queue[x].plateNumber << "\n";
        }
    }
};

//Function Main Body
int mainMenu(stack<Car> car){
    string input;
    int menu;
    cout << "Welcome to Samsan Parking";
    cout << "\n\nCurrently queued: "; display();
    if (car.empty()){
        cout << "\n\nThere are currently no cars parked.";
    }
    else{
        cout << "\nNumber of currently parked: " << car.size();
        cout << "\nNext car to unpark: " << (car.top()).plateNumber;
    }
    cout << "\n\nMenu:\n1. Enqueue Cars\n2. Admit Cars\n3. Remove record from parking\n4. View all cars parked this session.\n";
    cout << "\n[Input 0 to end the program.]";
    cout << "\n\nInput: "; cin >> input;

    if (isdigit(input[0]) == false){ menu = 5; }
    else {menu = stoi(input);}

    return menu;
};

void enqueueCar(){
    system("CLS");
    if (rear == mx-1){
        cout << "QUEUE IS FULL.\n";
        system("PAUSE");
    }
    else {
        string plateNumber, carModel, carColor;
        cout << "Input plate number: "; cin >> plateNumber;
        cout << "Input car model: "; cin >> carModel;
        cout << "Input car color: "; cin >> carColor;
        Car newCar(plateNumber, carModel, carColor);
        enqueue(newCar);
    }
};

void admitCar(stack<Car> *carStack){
    if (isEmpty()){
        system("CLS");
        cout << "There are no queued cars.\n";
        system("PAUSE");
    }
    else if ((*carStack).size() != maxStack){
        (*carStack).push(dequeue());
    }
    else {
        system("CLS");
        cout << "\n[PARKING SLOTS ARE FULL]\n";
        system("PAUSE");
    }
};

void carUnparked(stack<Car> *carStack){
    if ((*carStack).empty()){
        system("CLS");
        cout << "There are no parked cars.\n";
        system("PAUSE");
    }
    else {
        parkSummary[maxArray][0] = ((*carStack).top()).plateNumber;
        parkSummary[maxArray][1] = ((*carStack).top()).carModel;
        parkSummary[maxArray][2] = ((*carStack).top()).carColor;
        maxArray++;
        (*carStack).pop();
    }
};

void viewRecords(){
    system("CLS");
    if (maxArray == 0) {
        cout << "THERE IS NO CURRENTLY RECORDED DATA.\n";
    }
    else {
        cout << "Plate Number\t" << "Car Model\t" << "Car Color\n";
        for(int x = 0; x < maxArray; x++){
            for (int y = 0; y < 3; y++){
                cout << parkSummary[x][y] << "\t\t";
            }
            cout << endl;
        }
    }

    system("PAUSE");
};