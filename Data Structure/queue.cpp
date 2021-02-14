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

class SinglyLinkedList{
    public:
        Node* head;

    SinglyLinkedList(){
        head=NULL;
    }
    SinglyLinkedList(Node *n){
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
    //3. Prepend Node - attach a node at the start
    void prependNode(Node* n){  
        if(nodeExist(n->key) != NULL){
            cout<<"Node already exists with key value: "<<n->key<<". Append another node with different key value"<<endl;
        }else{
            n->next=head;
            head = n;
            cout<<"Node Prepended"<<endl;
        }
    }
    //4. Insert a Node after a particular node in the list
    void insertNodeAfter(int k, Node *n){
        Node* ptr = nodeExist(k);

        if(ptr==NULL){
             cout<<"No Node Exists"<<endl;
        }else{
             if(nodeExist(n->key) != NULL){
            cout<<"Node already exists with key value: "<<n->key<<". Append another node with different key value"<<endl;
            }else{
                n->next = ptr->next;
                ptr->next=n;
                cout<<"Node Inserted"<<endl;
            }
        }
    }
    //5. Delete node by unique key
    void dequeue(int k){
        if(head == NULL){
            cout<<"Singly Linked List already Empty. Can't delete"<<endl;

        }else if(head != NULL){
            if(head->key==k){
                head = head->next;
                cout<<"Node Unlinked with keys value: "<<k<<endl;
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
                    prevptr->next=temp->next;
                    cout<<"Node UNLINKED with keys value: "<<k<<endl;
                }else{
                    cout<<"Node Doesn't exist with key value: "<<k<<endl;
                }
            }
        }
    }
    //6. update node
    void updateNodeByKey(int k, int d){
        Node* ptr = nodeExist(k);

        if(ptr!=NULL){
            ptr->data=d;
            cout<<"Node Data Updated Successfully"<<endl;
        }else{
            cout<<"Node Doesn't exist with key value: "<<k<<endl;
        }
    }

    //7. printing list
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
    void enqueue(Node *n){
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
    //3. Prepend Node - attach a node at the start
    void prependNode(Node* n){  
        if(nodeExist(n->key) != NULL){
            cout<<"Node already exists with key value: "<<n->key<<". Append another node with different key value"<<endl;
        }else{
            n->next=head;
            head = n;
            cout<<"Node Prepended"<<endl;
        }
    }
    //4. Insert a Node after a particular node in the list
    void insertNodeAfter(int k, Node *n){
        Node* ptr = nodeExist(k);

        if(ptr==NULL){
             cout<<"No Node Exists"<<endl;
        }else{
             if(nodeExist(n->key) != NULL){
            cout<<"Node already exists with key value: "<<n->key<<". Append another node with different key value"<<endl;
            }else{
                n->next = ptr->next;
                ptr->next=n;
                cout<<"Node Inserted"<<endl;
            }
        }
    }
    //5. Delete node by unique key
    void dequeue(int k){
        if(head == NULL){
            cout<<"Singly Linked List already Empty. Can't delete"<<endl;

        }else if(head != NULL){
            if(head->key==k){
                head = head->next;
                cout<<"Node Unlinked with keys value: "<<k<<endl;
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
                    prevptr->next=temp->next;
                    cout<<"Node UNLINKED with keys value: "<<k<<endl;
                }else{
                    cout<<"Node Doesn't exist with key value: "<<k<<endl;
                }
            }
        }
    }
    //6. update node
    void updateNodeByKey(int k, int d){
        Node* ptr = nodeExist(k);

        if(ptr!=NULL){
            ptr->data=d;
            cout<<"Node Data Updated Successfully"<<endl;
        }else{
            cout<<"Node Doesn't exist with key value: "<<k<<endl;
        }
    }

    //7. printing list
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
};

class SinglyLinkedListQueue{
    public:
        Node* head;

    SinglyLinkedListQueue(){
        head=NULL;
    }
    SinglyLinkedListQueue(Node *n){
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
    void dequeue(){
        Node* ptr = head;
        head = ptr->next;

        cout<<"Node enqueue";
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

    //5.FRONT
    void front(){
        cout<<"The Front key of the queue is: "<<head->key<<"and The Front data of the queue is: "<<head->data;
    }

    //6.REAR
    void rear(){
        Node* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        cout<<"The rear key of the queue is: "<<ptr->key<<"and The Front data of the queue is: "<<ptr->data;
    }
};

int main(){

  SinglyLinkedListQueue s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. enqueue()" << endl;
    cout << "2. dequeue()" << endl;
    cout << "3. print()" << endl;
    cout << "4. rear()" << endl;
    cout << "5. front()" << endl;
    cout << "6. Clear Screen" << endl << endl;
 
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
      s.enqueue(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;
    case 2:
      s.dequeue();
    break;
    case 3:
      s.printList();
      break;
        case 4:
      s.rear();
      break;
        case 5:
      s.front();
      break;
    case 6:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);


    return 0;
}



