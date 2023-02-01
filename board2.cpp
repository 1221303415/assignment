#include <iostream>
using namespace std;

void printBoard(int, int);

int main()
{
    int dism_X;
    int dism_Y;
    int map_;
    cout << "Enter your column => ";
    cin >> dism_X;
    cout << " Enter your row => ";
    cin >> dism_Y;
    printBoard(dism_X, dism_Y);

    return 0;

}

void printBoard(int dism_X, int dism_Y)
{
    for (int i = 0; i < dism_Y; ++i)
    {
        cout << " ";
        for (int j = 0; j < dism_X; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        cout << " ";

        for (int j = 0; j < dism_X; ++j)
        {
            cout << "| ";
        }
        cout << "|" << endl;

    }
    
    cout << " ";
    for (int j = 0; j < dism_X; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
}