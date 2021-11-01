#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// *****Function prototypes****

void displayArray(int randNum[], int elements);
void randomNum(int randNums[], int elements);

int main ()
{

	//declare array
	int numbers[6] = {0};

	//random number generator
	srand(static_cast<int>(time(0)));
	
	randomNum(numbers, 6);

	displayArray(numbers, 6);
		
system("pause");
return 0;
}
//****Functions****
void randomNum(int randNums[], int elements)
{
    for (int i = 0; i < elements; i++)
    {
        bool same;
        do
        {
            same = false;
            randNums[i] = rand() % 6 + 1;
            // Check if the newly generated number is a duplicate:
            for (int check = 0; check < i; check++)
            {
                if (randNums[i] == randNums[check])
                {
                    same = true;
                    break;
                }
            }
        } while (same);
    }
}

void displayArray(int randNum[], int elements)
{
	for (int sub = 0; sub < elements; sub ++)
	{
		cout << "Your lottery numbers are: " << randNum[sub] << endl;
	}
}