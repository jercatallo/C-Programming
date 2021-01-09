#include <iostream>
#include <stack>
using namespace std;

int main()
{

    stack<int> stackContainer;
    for (int i = 1; i <= 4; i++)
    {
        stackContainer.push(i);
    }
    int stackSize = stackContainer.size();

    cout << "The top element in stack using TOP(): " << stackContainer.top() << "\nElements in the stack are: ";

    for (int i = 0; i < stackSize; i++)
    {
        cout << stackContainer.top() << " ";
        stackContainer.pop();
    }
}