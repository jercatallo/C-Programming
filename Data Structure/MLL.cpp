/*
1. Linked List
2. Linked List using stacks
3. Linked List using queue
4. Inserting, Adding, Deleting of data in stacks or queue

Linked List - Summary of those who went to the bank
Stacks - Numbering system
Queue - Queue per line of Service
--Services
-Banking
-Encheque
-Create new account

//////////////////////////////////////////////////////////
///////////////////// DUBCHAENG BANK /////////////////////
//////////////////////////////////////////////////////////

Currently Tending:
Deposit         Cheque          Account
2              3               420

Queue:
    Deposit:
        4
    Cheque:
        69
    Account:
        0

Menu:
1. Enqueue Customer     2. Dequeue Deposit      3. Dequeue Cheque
4. Dequeue Accounts     5. View Logs            6. Close Program

*/

#include <iostream>
#include <string>
#include <iomanip>

//Initialization of structs
struct Person{
    std::string firstName, lastName, place;
    int age, number;
    Person() = default;
    Person(std::string firstName, std::string lastName, std::string place, int age, int number){
        this->firstName = firstName;
        this->lastName = lastName;
        this->place = place;
        this->age = age;
        this->number = number;
    }
};

struct Node{
    Person customer;
    int queueNum;
    Node *next = NULL;

    Node() = default;
    Node(Person customer, int queueNum){
        this->customer = customer;
        this->queueNum = queueNum;
    }
};

struct logNode : Node {
    std::string purpose;
    logNode *next = NULL;

    logNode() = default;
};

struct sNode{
    int num;
    sNode *next = NULL;

    sNode() = default;
    sNode(int num){
        this->num = num;
    }
};

//Initialization of linked lists implementation
class LinkedList{
    public:
        logNode *head = NULL, *current = NULL;

        bool isEmpty(){
            if (head == NULL){
                return true;
            }
            return false;
        }

        void addNode(Node *pip, std::string purp){
            logNode *n = new logNode();
            n->customer = pip->customer;
            n->purpose = purp;
            n->queueNum = pip->queueNum;

            if (isEmpty()){
                std::cout << "Pasok Empty\n";
                this->head = n;
                this->current = head;
            }
            else {
                this->current->next = n;
                this->current = current->next;
            }

            system("PAUSE");
        }

        void deleteHead(){
            Node *temp;
            if (isEmpty()){
                std::cout << "List is empty!\n";
                return;
            }
            else if (head->next == NULL){
                temp = head;
                head = NULL;
            }
            else{
                temp = head;
                this->head = head->next;
            }
            free(temp);
        }

        void display(){
            if (isEmpty()){
                std::cout << "List is empty!\n";
                return;
            }
            else {
                current = head;
                std::cout << std::left << std::setw(7) << std::setfill(' ') << "Queue #" << "\t";
                std::cout << std::left << std::setw(15) << std::setfill(' ') << "First Name" << "\t";
                std::cout << std::left << std::setw(15) << std::setfill(' ') << "Last Name" << "\t";
                std::cout << std::left << std::setw(3) << std::setfill(' ') << "Age" << "\t";
                std::cout << std::left << std::setw(15) << std::setfill(' ') << "Place" << "\t";
                std::cout << std::left << std::setw(15) << std::setfill(' ') << "Purpose" << "\n";

                while(current != NULL){ 
                    std::cout << std::left << std::setw(7) << std::setfill(' ') << current->queueNum << "\t";
                    std::cout << std::left << std::setw(15) << std::setfill(' ') << current->customer.firstName << "\t";
                    std::cout << std::left << std::setw(15) << std::setfill(' ') << current->customer.lastName << "\t";
                    std::cout << std::left << std::setw(3) << std::setfill(' ') << current->customer.age << "\t";
                    std::cout << std::left << std::setw(15) << std::setfill(' ') << current->customer.place << "\t";
                    std::cout << std::left << std::setw(15) << std::setfill(' ') << current->purpose << "\n";
                    current = current->next;
                }
                std::cout <<"\n\n\t";
                system("PAUSE");
                return;
            }
        }
};

class LinkedListStack{
    public:
        sNode *top = NULL, *current = NULL;

        bool isEmpty(){
            if (top == NULL){
                return true;
            }
            return false;
        }

        void push(int num){
            sNode *n = new sNode;
            sNode *temp;
            n->num = num;

            if (top == NULL){
                this->top = n;
            }
            else {
                temp = this->top;
                this->top = n;
                this->top->next = temp;
            }
        }

        int pop(){
            int x;
            sNode *temp;
            if (isEmpty()){
                std::cout << "List is empty!\n";
                return -1;
            }
            else if (top->next == NULL){
                x = top->num;
                temp = top;
                top = NULL;
            }
            else{
                x = top->num;
                temp = top;
                this->top = top->next;
            }
            free(temp);
            return x;
        }

        void display(){
            if (isEmpty()){
                std::cout << "List is empty!\n";
                return;
            }
            else {
                current = top;
                while(current != NULL){ 
                    std::cout << current->num << " ";
                    current = current->next;
                }
                return;
            }
        }
};

class LinkedListQueue{
    public:
        Node *first = NULL, *current = NULL, *rear = NULL;

        bool isEmpty(){
            if (first == NULL){
                return true;
            }
            return false;
        }

        void addNode(Person *cust, int num){
            Node *n = new Node;
            n->customer = *cust;
            n->queueNum = num;

            if (rear == NULL){
                this->first = n;
                this->current = first;
                this->rear = n;
            }
            else {
                this->current->next = n;
                this->current = current->next;
            }
        }

        Node *dequeue(){
            Node *temp = NULL;
            if (isEmpty()){
                std::cout << "List is empty!\n";
                return temp;
            }
            else if (first->next == NULL){
                temp = first;
                first = NULL;
            }
            else{
                temp = first;
                this->first = first->next;
            }
            return temp;
        }

        void getFirst(){
            if (isEmpty()){
                std::cout << "None\t\t";
                return;
            }
            else {
                std::cout << this->first->queueNum << "\t\t";
            }
        }

        void display(){
            if (isEmpty()){
                std::cout << "Queue is empty!\n";
                return;
            }
            else {
                current = first->next;
                while(current != NULL){
                    std::cout << " |   " << current->queueNum << "\t";
                    current = current->next;
                }
                return;
            }
        }
};

//Initialization of functions
void startScreen(){
    std::cout << "################################################################\n";
    std::cout << "#                                                              #\n";
    std::cout << "#                           WELCOME                            #\n";
    std::cout << "#                             TO                               #\n";
    std::cout << "#                     DUBCHAENG BANKING                        #\n";
    std::cout << "#                                                              #\n";
    std::cout << "################################################################\n";
}

void header(){
    std::cout << "################################################################\n";
    std::cout << "#                                                              #\n";
    std::cout << "#                     DUBCHAENG BANKING                        #\n";
    std::cout << "#                                                              #\n";
    std::cout << "################################################################\n\n\n";
}

void mainScreen(LinkedListQueue qDeposit, LinkedListQueue qCheque, LinkedListQueue qRegis){
    header();
    std::cout << "Currently Tending: \n";
    std::cout << "Deposit\t\tCheque\t\tNew Account\n";
    qDeposit.getFirst();
    qCheque.getFirst();
    qRegis.getFirst();
    std::cout << "\n\nQueued: \n";
    std::cout << "\tDeposit: \n\t";
    qDeposit.display();
    std::cout << "\n\tCheque: \n\t";
    qCheque.display();
    std::cout << "\n\tNew Account: \n\t";
    qRegis.display();
    std::cout << "\n################################################################\n\n";
    std::cout << "Menu: \n";
    std::cout << "1. Enqueue Customer\t2.Dequeue Deposit\t3.Dequeue Cheque\n";
    std::cout << "4. Dequeue Accounts\t5.View Logs\t\t6.Close Program\n";
}

void stackInit(LinkedListStack *n){
    for(int x = 100; x >= 1; x--){
        n->push(x);
    }
}

void enqueueCustomer(LinkedListQueue *qDeposit,LinkedListQueue *qCheque,LinkedListQueue *qRegister,LinkedListStack *numStack){
    std::string firstName, lastName, place;
    int line, age, number;
    system("CLS");
    header();
    std::cout << "Please enter appropriate details: \n";
    std::cin.ignore();
    std::cout << "\tFirst Name: "; getline(std::cin, firstName);
    std::cout << "\tLast Name: "; getline(std::cin, lastName);
    std::cout << "\tCity: "; getline(std::cin, place);
    std::cin.clear();
    std::cout << "\tAge: "; std::cin >> age;
    std::cout << "\tNumber: "; std::cin >> number;
    Person cust(firstName, lastName, place, age, number);

    
    std::cout << "\n1. Deposit\n2. Cheque\n3. Accounts\n\n";
    do{
        std::cout << "Which line would you like to enqueue?: "; std::cin >> line;
        switch(line){
            case 1:
                qDeposit->addNode(&cust, numStack->pop());
                break;
            case 2:
                qCheque->addNode(&cust, numStack->pop());
                break;
            case 3:
                qRegister->addNode(&cust, numStack->pop());
                break;
            default:
                std::cout << "Please enter a correct number!\n";
        }
    }while(line < 0 || line > 3);
    
    std::cout << cust.lastName << " was queued successfully!\n\t\t";
    system("PAUSE");
}

void dequeueDeposit(LinkedListQueue *qDeposit, LinkedList *summary){
    if (qDeposit->isEmpty()){
        std::cout << "Deposit Queue is empty!";
        return;
    }
    else{
        summary->addNode(qDeposit->dequeue(), "Deposit/Withdraw");
    }
}

void dequeueCheque(LinkedListQueue *qCheque, LinkedList *summary){
    if(qCheque->isEmpty()){
        std::cout << "Cheque queue is empty!";
        return;
    }
    else{
        summary->addNode(qCheque->dequeue(), "Cheque");
    }
}

void dequeueAccounts(LinkedListQueue *qAccount, LinkedList *summary){
    if (qAccount->isEmpty()){
        std::cout << "Account Queue is empty!";
        return;
    }
    else{
        summary->addNode(qAccount->dequeue(), "Manage Account");
    }
}

int main(){
    LinkedListQueue qDeposit, qCheque, qRegister;
    LinkedListStack numStack;
    LinkedList summary;
    int choice;

    stackInit(&numStack);

    startScreen();
    std::cout << "\n\n\t\t";
    system("PAUSE");
    do{
        system("CLS");
        mainScreen(qDeposit, qCheque, qRegister);
        std::cout << "\nWhat do you want to do?: "; std::cin >> choice;
        switch(choice){
            case 1:
                enqueueCustomer(&qDeposit, &qCheque, &qRegister, &numStack);
                break;
            case 2:
                dequeueDeposit(&qDeposit, &summary);
                break;
            case 3:
                dequeueCheque(&qCheque, &summary);
                break;
            case 4:
                dequeueAccounts(&qRegister, &summary);
                break;
            case 5:
                system("CLS");
                summary.display();
                break;
            case 6:
                std::cout << "\n\nEnding Program...\n\n\t";
                system("PAUSE");
                return 0;
            default:
                std::cout << "Please enter a valid input.\n";
        }
    }while(choice != 6);
}