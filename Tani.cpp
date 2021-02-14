#include <iostream>

using namespace std;

    struct StoreGoods{ //Creating a Struct for StoreGoods

        //List of Integer of Goods
        int candies;
        int chips ;
        int ice_cream;
        int bread;
        int fruits;

        //Initializing Goods Pointers
        int* candies_pointer = &candies;
        int* chips_pointer = &chips;
        int* ice_cream_pointer = &ice_cream;
        int* bread_pointer = &bread;
        int* fruits_pointer = &fruits;


        void Goods(int _candies,int _chips, int _ice_cream, int _bread, int _fruits){
            //Altering the value of the goods using its pointers
            *candies_pointer = _candies;
            *chips_pointer = _chips;
            *ice_cream_pointer = _ice_cream;
            *bread_pointer = _bread;
            *fruits_pointer = _fruits;
        }   

        //Total of the goods
        int TOTAL(){
            //Returning the altered values of the goods
            return (candies + chips + ice_cream + bread + fruits);
        }
    };

int main(){

    StoreGoods MANG_TANI_GOODS;  // Creating instance of StoreGoods as MANG_TANI_GOODS

    int tani_candies;
    int tani_chips;
    int tani_ice_cream;
    int tani_bread;
    int tani_fruits;

    //Entering the goods
    cout<<"Enter Number of Candies: "; cin>>tani_candies;
    cout<<"Enter Number of Chips: "; cin>>tani_chips;
    cout<<"Enter Number of Ice Cream: "; cin>>tani_ice_cream;
    cout<<"Enter Number of Bread: "; cin>>tani_bread;
    cout<<"Enter Number of Fruits: "; cin>>tani_fruits;


    MANG_TANI_GOODS.Goods(tani_candies,tani_chips,tani_ice_cream,tani_bread,tani_fruits);

    cout<<MANG_TANI_GOODS.TOTAL();
   
}