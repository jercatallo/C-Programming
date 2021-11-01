#include <iostream>
#define size 10
using namespace std;
int temp = 0;

int main() {
    int a[] = {5,4,3,2,1};

    for(int i =0;i<size;i++){
        for(int j =0;j<size-i;j++){
            if(a[j]>a[j+1]){
                temp =a[j];
                a[j] = a[j+1];
                a[j+1] = temp
            }
        }
    }
    for(int j=0;j<size;j++){
        cout<<a[j];
        if( j<size-1){
            cout<<", ";
        }
    }

    return 0;
}
