#include <iostream>

using namespace std;

int main (){
    int arr [3][2] = {{-1,-2},{0,1},{2}};
    
    for (int i=0; i <= 2; i++){
        for (int j = 0; j <= 1; j++){
            cout << "Test" << "[" << i << "]" << "[" << j << "]" << " = ";
            cout << arr[i][j] << endl;
        }
    }
    
}