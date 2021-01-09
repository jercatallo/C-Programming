// 1. Struct declaration         ----- Line  11
// 2. Pointers                   ----- Lines 78-81; 161
// 3. 2D Array declaration       ----- Line  88
// 4. Stack                      ----- Lines 118; 175-189
// 5. Queue                      ----- Lines 18-83; 92-165

#include<iostream>
#include<stack>
using namespace std;

struct Customer{
	string name, product;
	int quantity, price, total=0, sort;
};

stack<int> totalCustomers;

class Queue{
	public:
		int front, rear, queue[100], invalidInputs;
		Queue(){
			front = -1;
			rear = -1;
			for(int i=0;i<100;i++){
				queue[i] = 0;
			}
		}
		
		bool isEmpty(){
			if(front == -1 && rear == -1)
				return true;
			else
				return false;
		}
		
		bool isFull(){
			if(rear == 100)
				return true;
			else
				return false;
		}
		
		void enqueue(int val){
			if(isFull()){
				cout << "Queue is FULL\n\n";
				return;
			}
			else if(isEmpty()){
				rear = 0; front = 0;
				queue[rear] = val;
			}
			else{
				rear++;
				queue[rear] = val;
			}
		}
		
		int dequeue(){
			int x;
			if(isEmpty()){
				cout << "Queue is EMPTY\n\n";
				return 0;
			}
			else{
				x = queue[front];
				queue[front] = 0;
				front++;
				return x;
			}
		}
		
		int count(){
			if (front >= 0){
				return (rear-front+1);
			}
		}
		
		void invalid(int* x){
			cout << "Invalid Input.\nEnter proper option number\n";
			*x += 1;
		}
		
};

int i=0;
main()
{
	Customer customer[2][100];
	Queue q1;
	int mainLoop, mainIndex, temp=0;
	
	do{
		cout << "\nGroup#4's ONLINE SHOP\n";
		cout << "0) Exit Shop\n";
		cout << "1) Add customer to queue\n";
		cout << "2) Confirm product delivery\n";
		cout << "3) Display all pending orders\n";
		cout << "4) Clear Screen\n";
		cout << "Enter choice: "; cin >> mainLoop; cout << "\n";
		cin.ignore();
		switch(mainLoop){
			case 0:
				break;
			case 1:
				mainIndex = i; temp = mainIndex;
				q1.enqueue(mainIndex);
				cout << "[New Customer(#" << temp+1 << ")]\nCustomer Name: ";
				getline(cin, customer[0][i].name); customer[1][i].name = customer[0][i].name;
				cout << "Product of choice: ";
				getline(cin, customer[0][i].product); customer[1][i].product = customer[0][i].product;
				cout << "Price: ";
				cin >> customer[0][i].price; customer[1][i].price = customer[0][i].price;
				cout << "Quantity: ";
				cin >> customer[0][i].quantity; customer[1][i].quantity = customer[0][i].quantity;
				customer[0][i].total = customer[0][i].price * customer[0][i].quantity;
				cout << "Total: " << customer[0][i].total << "\n"; 
				customer[1][i].total = customer[0][i].total;
				totalCustomers.push(i+1);
				i++;
				break;
			case 2:
				if(((q1.front-1)==q1.rear) || q1.isEmpty()){
					cout << "No pending deliveries.\n";
					break;
				}
				else{
					cout << "Customer#" << q1.dequeue()+1 << "'s item has been successfuly delivered.\n";
					break;
				}
			case 3:
				if(!q1.isEmpty()){
					cout << "Pending orders: " << q1.count() << endl;
					if(q1.count() != 0){
						cout << "Customer#\t|Name\t\t|Item\t\t\t|Price\t\t|Quanity\t|Total\n";
						cout << "===============================================================================================\n";
						for (int i=q1.front; i<=q1.rear; i++){
							if (customer[0][i].name.length()<=6){
								cout << q1.queue[i]+1 << "\t\t|" << customer[0][i].name << "\t\t|" << customer[0][i].product;
							}
							else{
								cout << q1.queue[i]+1 << "\t\t|" << customer[0][i].name << "\t|" << customer[0][i].product;	
							}
							if (customer[0][i].product.length()<=6){
								cout << "\t\t\t|" << customer[0][i].price <<  "\t\t|" << customer[0][i].quantity << "\t\t|" << customer[0][i].total << "\n";
							}
							else{
								cout << "\t\t|" << customer[0][i].price <<  "\t\t|" << customer[0][i].quantity << "\t\t|" << customer[0][i].total << "\n";
							}
						}
					}	
				}
				else{
					cout << "No pending deliveries.\n";
					break;
				}
				break;
			case 4:
				system("cls");
				break;
			default:
				q1.invalid(&q1.invalidInputs);
				break;
		}
	
	}while(mainLoop!=0);
	
	cout << "Shop closed.\nTotal no. of customers: " << totalCustomers.size();
	cout << "\tTotal no. of invalid inputs: " << q1.invalidInputs;
	
	if(totalCustomers.size() != 0){
		cout << "\n\nList of all customers & their orders (Descending):\n";
		cout << "Customer#\t|Name\t\t|Item\t\t\t|Price\t\t|Quanity\t|Total\n";
		cout << "===============================================================================================\n";
	}
	while(!totalCustomers.empty()){
		if (customer[1][totalCustomers.size()-1].name.length()<=6){
			cout << totalCustomers.size() << "\t\t|" << customer[1][totalCustomers.size()-1].name << "\t\t|" << customer[1][totalCustomers.size()-1].product;
		}
		else{
			cout << totalCustomers.size() << "\t\t|" << customer[1][totalCustomers.size()-1].name << "\t|" << customer[1][totalCustomers.size()-1].product;	
		}
		if (customer[1][totalCustomers.size()-1].product.length()<=6){
			cout << "\t\t\t|" << customer[1][totalCustomers.size()-1].price <<  "\t\t|" << customer[1][totalCustomers.size()-1].quantity << "\t\t|" << customer[1][totalCustomers.size()-1].total << "\n";
		}
		else{
			cout << "\t\t|" << customer[1][totalCustomers.size()-1].price <<  "\t\t|" << customer[1][totalCustomers.size()-1].quantity << "\t\t|" << customer[1][totalCustomers.size()-1].total << "\n";
		}
		totalCustomers.pop();
	}

	return 0;
}


// We hope you're doing just fine po by the time you're checking this ma'am ^_^
// Thank you po for your time!!!
// Take care & God bless po :)
