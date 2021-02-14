#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    int data;
    Node* next;

    Node(){
        key=0;
        data=0;
        next=NULL;
    }

    Node(int k, int d){
        key= k;
        data = d;
    }
};


class SinglyLinkedListStack{
    public:
        Node* head;

    SinglyLinkedListStack(){
        head=NULL;
    }
    SinglyLinkedListStack(Node *n){
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
        if(nodeExist(n->key) != NULL){
            cout<<"Node already exists with key value: "<<n->key<<". Append another node with different key value"<<endl;
        }else{
            if(head==NULL){
                head = n;
                cout<<"Node Appended"<<endl;
            }else{
            
            Node* ptr = head;
             while(ptr->next != NULL){
             //While will loop again with new node address
             ptr = ptr->next;
            }
            ptr->next = n;
            cout<<"Node Appended"<<endl;
            }
        }
    }
   
  
    //3. Delete node by unique key
    void pop(){
        Node* prevPointer = NULL;
        Node* ptr = head;
        while(ptr->next != NULL){
            prevPointer= ptr;
            ptr = ptr->next;
        }

        prevPointer->next = NULL;
        cout<<"Deleted node in the last stack";
    }

    //4. printing list
    void printList(){
        if(head==NULL){
            cout<<"No Nodes in Singly Linked List";
        }else{
            cout<<endl<<"Singly Linked List Values: ";
            Node* temp = head;
            while(temp!=NULL){
                cout<<"("<<temp->key<<","<<temp->data<<") --> ";
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
        cout<<"The top key of the stack is: "<<temp->key<<" and The top data of the stack is"<<temp->data;
    }
};


int main(){

  SinglyLinkedListStack s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. push()" << endl;
    cout << "2. pop()" << endl;
    cout << "3. print()" << endl;
    cout << "4. top()" << endl;
    cout << "5. Clear Screen" << endl << endl;
 
    cin >> option;
    Node * n1 = new Node();
    //Node n1;
 
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.push(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;
    case 2:
      s.pop();
      break;
    case 3:
      s.printList();
      break;
    case 4:
      s.top();
    break;
    case 5:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);


    return 0;
}



