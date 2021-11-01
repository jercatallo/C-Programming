#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> stackContainer;

    int stackSize = stackContainer.size();
    if(stackSize<=0){
        cout<<"List is empty!";
    }

    for (int i = 10; i <= 50; i+=10)
    {
        stackContainer.push(i);
    }
    stackSize = stackContainer.size();

    cout <<'\n';

    for (int i = 0; i < stackSize; i++)
    {
        cout << stackContainer.top() <<" is removed.\n ";
        stackContainer.pop();
    }
}