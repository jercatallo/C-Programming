#include <iostream>
using namespace std;

int main()
{
    int numberOfFruits, customerMoney;
    cout << "How many number of fruits does the customer buy? ";
    cin >> numberOfFruits;
    cout << "Customer Money:  ";
    cin >> customerMoney;

    int customer[numberOfFruits][3];
    int *customerPointer[numberOfFruits][3];
    string fruitNames[numberOfFruits];
    int overallPrice = 0;

    int columnsLength = sizeof customer / sizeof customer[0]; // LengthNumber of fruits
    int rowsLength = sizeof customer[0] / sizeof(int);        // 3 rowsLength(Quantity,Price,Total)

    //Assigning the memory address of the customer Array to the customerPointer varialbe
    {
        for (int i = 0; i < columnsLength; i++)
            for (int j = 0; j < rowsLength; j++)
            {
                customerPointer[i][j] = &customer[i][j];
            }
    }

    for (int i = 0; i < columnsLength; i++)
    {

        cout << endl
             << "Item Number: " << i + 1 << endl;
        cout << "Enter fruit name: ";
        cin >> fruitNames[i];
        for (int j = 0; j < rowsLength; j++)
        {
            int quantity, price, total;
            if (j == 0)
            {
                cout << "Enter Quantity: ";
                cin >> quantity;
                *customerPointer[i][j] = quantity;
            }
            else if (j == 1)
            {
                cout << "Enter Price: ";
                cin >> price;
                *customerPointer[i][j] = price;
            }
            else if (j == 2)
            {
                total = quantity * price;
                *customerPointer[i][j] = total;
                cout << "Total is: " << customer[i][j] << endl;
            }
        }
    }
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Fruit Name "
         << "\t\tQuantity"
         << "\tPrice"
         << "\t\tTotal";
    cout << endl
         << "--------------------------------------------------------------------";
    for (int i = 0; i < columnsLength; i++)
    {
        overallPrice += customer[i][2];
        cout << endl
             << fruitNames[i] << "\t";
        for (int j = 0; j < rowsLength; j++)
        {

            cout << "\t\t" << customer[i][j];
        }
    }
    cout << endl
         << "--------------------------------------------------------------------" << endl;
    cout << endl
         << "Total Number of Fruits: " << numberOfFruits << "\t\t"
         << "Overall Price: " << overallPrice << "\t\tCustomer Change: " << customerMoney - overallPrice << endl;
}