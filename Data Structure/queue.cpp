#include <iostream>
#include <queue>
using namespace std;

int main(){
    
    queue<int> queueContainer;

    for(int i =0;i<10;i++){
        cout<<"Enqueuing: "<< i<<"\t";
        queueContainer.push(i);
    }
    cout<<"\n\nSize of queueContainer: "<<queueContainer.size()<<endl;
    cout<<"The Current Back of queueContainer: "<<queueContainer.back()<<endl;
    cout<<"The Current front of queueContainer: "<<queueContainer.front()<<endl;
    cout<<"\n";
    while(!queueContainer.empty()){
           cout<<"Dequeuing: "<<queueContainer.front()<<"\t";
        queueContainer.pop();
    }

    cout<<"\n\nSize of queueContainer: "<<queueContainer.size()<<endl;
        if(queueContainer.front() == true){
            cout<<"The Current front of queueContainer: "<<queueContainer.front()<<endl;
        }else{
            cout<<"queueContainer has no front"<<endl;
        }

        if(queueContainer.back() == true){
          cout<<"The Current Back of queueContainer: "<<queueContainer.back()<<endl;
        }else{
            cout<<"queueContainer has no back"<<endl;
        }
}
