#include <iostream>
using namespace std;
struct Person{
    string firstName, lastName, time;
    int price;
    Person() = default;
    Person(string firstName, string lastName, string time, int price){
        this->firstName = firstName;
        this->lastName = lastName;
        this->time = time;
        this->price = price;
    }
};
class Node{
    public:
    int key;
    Person data;
    Node* next;

    Node() = default;

    Node(int k, Person d){
        key= k;
        data = d;
    }
};

//Linked List
class LinkedList{
    public:
        Node* head;

    LinkedList(){
        head=NULL;
    }
    LinkedList(Node *n){
        head=n;
    }

    //1. Check if the node exist if the key is match with the int k
    Node* nodeExist(int k){
        Node* temp = NULL;
        Node* ptr = head;

        while(ptr != NULL){
            //Check if the pointer that points to the heads is equal to the k
             if(ptr->key==k){
                 temp=ptr;
             }
             //While will loop again with new node address
             ptr =ptr->next;
        }
        return temp;
    }
    //2. Append a node to the list: add node to the end
    void appendNode(Node *n){
        if(nodeExist(n->key) != NULL){
            cout << "=======================================================================\n";
            cout << "====================== Seat Number already occupied!  =================\n";
            cout << "=======================================================================\n\n";
        }else{
            if(head==NULL){
                head = n;
            cout << "=======================================================================\n";
            cout << "====================== Sucessfully Reserved A Seat! ===================\n";
            cout << "=======================================================================\n\n";
            }else{
            
            Node* ptr = head;
             while(ptr->next != NULL){
             //While will loop again with new node address
             ptr = ptr->next;
            }
            ptr->next = n;
            cout << "=======================================================================\n";
            cout << "====================== Sucessfully Reserved A Seat! ===================\n";
            cout << "=======================================================================\n\n";
            }
        }
    }
    //3. Prepend Node - attach a node at the start
    void prependNode(Node* n){  
        if(nodeExist(n->key) != NULL){
            cout << "=======================================================================\n";
            cout << "====================== Seat Number already occupied!  =================\n";
            cout << "=======================================================================\n\n";

        }else{
            n->next=head;
            head = n;
            cout << "=======================================================================\n";
            cout << "====================== Sucessfully Reserved A Seat! ===================\n";
            cout << "=======================================================================\n\n";
        }
    }

    // //5. Delete node by unique key
    Node* deleteNodeByKey(int k){
        Node* removedNode = NULL;
        Node* tempHead = NULL;
        if(head == NULL){
            cout << "=======================================================================\n";
            cout << "=============== Reservation is currently empty cannot delete! =========\n";
            cout << "=======================================================================\n\n";
        }else if(head != NULL){
            if(head->key==k){
                //Temp head for storing the the node that will be removed
                tempHead = head;
                //Unlinking the node
                head = head->next;
                cout << "=======================================================================\n";
                cout << "=============== Successfully Moved a Person to Watching! =============\n";
                cout << "=======================================================================\n\n";
                //Removing the next of the temphead
                tempHead->next = NULL;
                removedNode = tempHead;
            }else{
                Node* temp =NULL;
                Node* prevptr = head;
                Node* currentptr = head->next;
                while(currentptr !=NULL){
                    if(currentptr->key==k){
                        temp=currentptr;
                        currentptr=NULL;
                    }else{
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if(temp!=NULL){
                    //Temp head for storing the the node that will be removed
                    tempHead = prevptr->next;
                    //Unlinking the node
                    prevptr->next=temp->next;
                    cout << "=======================================================================\n";
                    cout << "=============== Successfully Moved a Person to Watching! =============\n";
                    cout << "=======================================================================\n\n";
        
                     //Removing the next of the temphead
                    tempHead->next = NULL;
                    removedNode = tempHead;
                  
                }else{
                    cout << "=======================================================================\n";
                    cout << "=============== Reservation Seat Information Doesn't Exists! ==========\n";
                    cout << "=======================================================================\n\n";
                }
            }
        }
          return removedNode;
    }
    // //6. update node
    void updateNodeByKey(int k, Person d){
        Node* ptr = nodeExist(k);

        if(ptr!=NULL){
            ptr->data=d;
            cout << "=======================================================================\n";
            cout << "========== Reservation Seat Information Updated Successfully ==========\n";
            cout << "=======================================================================\n\n";
       
        }else{
        cout << "=======================================================================\n";
        cout << "=============== Reservation Seat Information Doesn't Exists! ==========\n";
        cout << "=======================================================================\n\n";
        }
    }

    // //7. printing list
    void printList(){
        if(head==NULL){
            cout << "=======================================================================\n";
            cout << "================= Currently There is no Reserved Seats ================\n";
            cout << "=======================================================================\n\n";
        }else{
            cout << "=======================================================================\n";
            cout << "======================= List of Reserved Seats ========================\n";
            cout << "=======================================================================\n\n";
            Node* temp = head;
            while(temp!=NULL){
                cout<<"=======================================================================\n";
                cout<<"Seat Number: "<<temp->key<<"\nPerson Details: "<<" First Name: "<<temp->data.firstName<<", Last Name: "<<temp->data.firstName<<", Time Rerserved: "<<temp->data.time<<", Price: "<<temp->data.price<<endl;
                cout<<"=======================================================================\n\n";
                temp = temp->next;
            }
        }
    }
};

//Linked List using Stack
class LinkedListStack{
    public:
        Node* head;

    LinkedListStack(){
        head=NULL;
    }
    LinkedListStack(Node *n){
        head=n;
    }

    //1. Check if the node exist if the key is match with the int k
    Node* nodeExist(int k){
        Node* temp = NULL;
        Node* ptr = head;

        while(ptr != NULL){
            //Check if the pointer that points to the heads is equal to the k
             if(ptr->key==k){
                 temp=ptr;
             }
             //While will loop again with new node address
             ptr =ptr->next;
        }
        return temp;
    }
    //2. Append a node to the list: add node to the end
    void push(Node *n){
       
            if(head==NULL){
                head = n;
            
            }else{
            
            Node* ptr = head;
             while(ptr->next != NULL){
             //While will loop again with new node address
             ptr = ptr->next;
            }
            ptr->next = n;

            }
        
    }
   
  
    //3. Delete node by unique key
    void pop(){
        Node* prevPointer = NULL;
        Node* ptr = head;

        if(head !=NULL){
            while(ptr->next != NULL){
            prevPointer= ptr;
            ptr = ptr->next;
            }

        prevPointer->next = NULL;
        cout<<"Removed a person from watched List";
        }
        cout << "=======================================================================\n";
        cout << "=========There are no people who watched, cannot remove item! =========\n";
        cout << "=======================================================================\n\n";
    }

    //4. printing list
     void printList(){
        if(head==NULL){
            cout << "=======================================================================\n";
            cout << "================ Currently There is no People Watched =================\n";
            cout << "=======================================================================\n\n";
        }else{
            cout << "=======================================================================\n";
            cout << "===================== List of People Watched ========================\n";
            cout << "=======================================================================\n\n";
            Node* temp = head;
            while(temp!=NULL){
                
               cout<<"=======================================================================\n";
                cout<<"Seat Number: "<<temp->key<<"\nPerson Details: "<<" First Name: "<<temp->data.firstName<<", Last Name: "<<temp->data.firstName<<", Time Rerserved: "<<temp->data.time<<", Price: "<<temp->data.price<<endl;
                cout<<"=======================================================================\n\n";
                temp = temp->next;
            }
        }
    }

    //5. Top
    void top(){
        Node* temp = head;

        if(temp->next != NULL){
            temp = temp->next->next;
        }
        cout<<"The top key of the stack is: "<<temp->key<<" and The top data of the stack is";
    }
};

//LinkedList using Queue
class LinkedListQueue{
    public:
        Node* head;

    LinkedListQueue(){
        head=NULL;
    }
    LinkedListQueue(Node *n){
        head=n;
    }

    //1. Check if the node exist if the key is match with the int k
    Node* nodeExist(int k){
        Node* temp = NULL;
        Node* ptr = head;

        while(ptr != NULL){
            //Check if the pointer that points to the heads is equal to the k
             if(ptr->key==k){
                 temp=ptr;
             }
             //While will loop again with new node address
             ptr =ptr->next;
        }
        return temp;
    }

    //2. Append a node to the list: add node to the end
    void enqueue(Node *n){
            //If there is no current head set the n as head
            if(head==NULL){
                head = n;
            }else{
            
            Node* ptr = head;
             while(ptr->next != NULL){
             //While will loop again with new node address
             ptr = ptr->next;
            }
            //Adding the new node to the last
            ptr->next = n;
            }
   
    }
  
    //3. Delete node by unique key
    Node* dequeue(){
        if(head != NULL){
        Node* ptr = head;
        Node* ptrTemp = ptr;
        head = ptr->next;
    
        ptrTemp->next = NULL;
        cout << "=======================================================================\n";
        cout << "=========Successfully Moved a Person from Watching to Watched =========\n";
        cout << "=======================================================================\n\n";
        return ptrTemp;
        }
        cout << "=======================================================================\n";
        cout << "============= There are no watchers, cannot remove item ===============\n";
        cout << "=======================================================================\n\n";
        return NULL;
    }

    //4. printing list
      void printList(){
        if(head==NULL){
             cout << "=======================================================================\n";
            cout << "===================== Currently There is no watching ==================\n";
            cout << "=======================================================================\n\n";
        }else{
            cout << "=======================================================================\n";
            cout << "===================== List of Already Watching ========================\n";
            cout << "=======================================================================\n\n";
            Node* temp = head;
            while(temp!=NULL){
                
               cout<<"=======================================================================\n";
                cout<<"Seat Number: "<<temp->key<<"\nPerson Details: "<<" First Name: "<<temp->data.firstName<<", Last Name: "<<temp->data.firstName<<", Time Rerserved: "<<temp->data.time<<", Price: "<<temp->data.price<<endl;
                cout<<"=======================================================================\n\n";
                temp = temp->next;
            }
        }
    }

    //5.FRONT
    void front(){
        cout<<"The Front key of the queue is: "<<head->key<<"and The Front data of the queue is: ";
    }

    //6.REAR
    void rear(){
        Node* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        cout<<"The rear key of the queue is: "<<ptr->key<<"and The Front data of the queue is: ";
    }
};

void Header(){
    cout << "=======================================================================\n";
    cout << "======================= Movie Reservation System ======================\n";
    cout << "=======================================================================\n\n";
}

int main(){

  LinkedList MovieSeats;
  LinkedListQueue Watching;
  LinkedListStack Watched;

  int key1, k1, data1, line, age, price, option;
  string firstName, lastName, time;

  do {
    cout << "\nThis is the Movie Reservation System. Select an Option to continue. Enter 0 to exit." << endl;
    cout << "1. Reserve a Seat in the End of the List" << endl;
    cout << "2. Reserve a Seat in the Start of the List" << endl;
    cout << "3. Update a Reservation Seat Information in the List" << endl;
    cout << "4. Remove a Person to Reservation and move to Watching" << endl;
    cout << "5. Remove a Person to Watching and move to People who Watched" << endl;
    cout << "6. Display Seats Reserved" << endl;
    cout << "7. Display Watchings" << endl;
    cout << "8. Display List of People who watched" << endl;
    cout << "9. Clear Screen" << endl << endl;
 

    cout << "Enter Option: ";
    cin >> option;
    Node * n1 = new Node();
    //Node n1;
     

    if(option == 1 || option == 2 || option == 3){
        system("CLS");
        Header();
        cout << "Enter Information about the Reservation: \n";
        cin.ignore();
        cout << "First Name: "; getline(cin, firstName);
        cout << "Last Name: "; getline(cin, lastName);
        cout << "Time Reserved: "; getline(cin, time);
        cin.clear();
        cout << "Price: "; cin >> price;
        cout << "Enter The Seat Number Reservation: ";
        cin >> key1;
    }

    Person cust(firstName, lastName, time, price);

    switch (option) {
    case 0:
      break;
    case 1:
      n1 -> key = key1;
      n1 -> data = cust;
      MovieSeats.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;
 
    case 2:
      n1 -> key = key1;
      n1 -> data = cust;
      MovieSeats.prependNode(n1);
      break;
    case 3:
      cout << "Enter The Seat Number Reservation to be Updated" << endl;
      cin >> key1;
      MovieSeats.updateNodeByKey(key1, cust);
      break;
    case 4:
    Header();
    cout << "Enter The Seat Number Reservation that will be moved to Watching: ";
    cin >> k1;    
    Watching.enqueue(MovieSeats.deleteNodeByKey(k1));
      break;
    case 5:   
    Watched.push(Watching.dequeue());
      break;
    case 6:
      MovieSeats.printList();
      break;
    case 7:
      Watching.printList();
    break;
    case 8:
      Watched.printList();
    break;
    case 9:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option price " << endl;
    }
 
  } while (option != 0);


    return 0;
}