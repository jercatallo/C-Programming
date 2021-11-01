#include <iostream> 
using namespace std;

int main();
void deleteNode();
void insertNode();
void displayNodes();
 
//Declare LinkedList with struc
struct LinkedList{
    int num;
    LinkedList *next;
};
 
struct LinkedList *head=NULL;

//Create new Node
void insertNode(int n){
    struct LinkedList *newNode=new LinkedList;
    newNode->num=n;
    newNode->next=head;
    head=newNode;
}

 // Delete a Node
void deleteNode(){
    if(head==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    cout<<head->num<<" is removed."<<endl;
    head=head->next;
}

// Read the Nodes
void displayNodes(){
    if(head==NULL){
        cout<<"List is empty!"<<endl;
        return;
    }
    struct LinkedList *temp=head;
    cout<<"\nThe Available nodes are: ";
    while(temp!=NULL){
        cout<<temp->num<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
 

int main(){
     
     for(int i = 1; i<=20;i++){
        
        insertNode(i);
        //Removing odd numbers
         if(i % 2 !=0){
             deleteNode();
         }
     }
    
    displayNodes();

}