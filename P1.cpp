#include <iostream>
using namespace std;
int board_rows = 5;
int board_columns = 9;
int zombie_count = 1;

void GameSettings();
void MainMenu();
void CustomizedSettings();
void CustomBoardRows();
void BoardRowsError();
void CustomBoardColumns();
void BoardColumnsError();
void CustomZombieCount();
void ZombieCountError();
void TimeDelay(int a);

// This is to delay the time in an organized manner after users exit the game.
// It leaves them enough time to view the output before the program ends.
void TimeDelay(int a)
{
    int add;
    int time;
    int i;

    time = a * 100000000000;

    for (i = 0; i < time ; i++)
    {
        add *= i;
        add ++;
        add ++;
    }
}

// This is when user enters an invalid input for the amount of zombies.
void ZombieCountError()
{
    cout << "                                    " << endl;
            cout << "                                    " << endl;
            cout << "----------------------------------------------------------" << endl;
            cout << "*****NOTE: Please Enter Numbers Between 1 And 10 Only*****" << endl;
            cout << "----------------------------------------------------------" << endl;
            cout << "                                    " << endl;
            cout << "                                    " << endl;

            cin.clear();
            cin.ignore(219, '\n');
            CustomZombieCount();
}

// This is where users set their desired amount of zombies.
void CustomZombieCount()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "Enter New Amount Of Zombies(*NOTE: Maximum 10 zombies): ";
    cin >> zombie_count;

    if (zombie_count > 10)
    {
        ZombieCountError();
    }
    else if (zombie_count < 1)
    {
        ZombieCountError();
    }
    else
    {
        cout << "Updated Amount Of Zombies: " << zombie_count << endl;
        CustomizedSettings();
    }
}

// This is when user enters an invalid input for the amount of board columns.
void BoardColumnsError()
{
    cout << "                                    " << endl;
            cout << "                                    " << endl;
            cout << "--------------------------------------------------------------" << endl;
            cout << "*****NOTE: Please Enter Odd Numbers Between 3 And 19 Only*****" << endl;
            cout << "--------------------------------------------------------------" << endl;
            cout << "                                    " << endl;
            cout << "                                    " << endl;

            cin.clear();
            cin.ignore(219, '\n');
            CustomBoardColumns();
}

// This is where users set their desired amount of board columns.
void CustomBoardColumns()
{
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Enter New Amount Of Board Columns(*NOTE: Odd numbers between 3 and 19 only): ";
    cin >> board_columns;

    if (board_columns > 19)
    {
        BoardColumnsError();
    }
    else if (board_columns < 3)
    {
        BoardColumnsError();
    }
    else if (board_columns % 2 != 0)
    {
        cout << "Updated Amount Of Board Columns: " << board_columns << endl;
        CustomizedSettings();
    }
    else
    {
        BoardColumnsError();
    }
}

// This is when user enters an invalid input for the amount of board rows.
void BoardRowsError()
{
    cout << "                                    " << endl;
            cout << "                                    " << endl;
            cout << "--------------------------------------------------------------" << endl;
            cout << "*****NOTE: Please Enter Odd Numbers Between 3 And 19 Only*****" << endl;
            cout << "--------------------------------------------------------------" << endl;
            cout << "                                    " << endl;
            cout << "                                    " << endl;

            cin.clear();
            cin.ignore(219, '\n');
            CustomBoardRows();
}

// This is where users set their desired amount of board rows.
void CustomBoardRows()
{
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Enter New Amount Of Board Rows(*NOTE: Odd numbers between 3 and 19 only): ";
    cin >> board_rows;

    if (board_rows > 19)
    {
        BoardRowsError();
    }
    else if (board_rows < 3)
    {
        BoardRowsError();
    }
    else if (board_rows % 2 != 0)
    {
        cout << "Updated Amount Of Board Rows: " << board_rows << endl;
        CustomizedSettings();
    }
    else
    {
        BoardRowsError();
    }
}

// This is where users can choose which setting they would like to change.
void CustomizedSettings()
{
    int options;
    {
        cout << "-----------------------" << endl;
        cout << "1. Change Board Rows" << endl;
        cout << "2. Change Board Columns" << endl;
        cout << "3. Change Zombie Count" << endl;
        cout << "4. Back" << endl;
        cout << " " << endl;

        cout << "Enter a number: ";
        cin >> options;

        if (options == 1)
        {
            CustomBoardRows();
        }
        else if (options == 2)
        {
            CustomBoardColumns();
        }
        else if (options == 3)
        {
            CustomZombieCount();
        }
        else if (options == 4)
        {
            GameSettings();
        }
        else
        {
            cout << "                                    " << endl;
            cout << "                                    " << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "*****NOTE: Please Enter Numbers Between 1 And 4 Only*****" << endl;
            cout << "---------------------------------------------------------" << endl;
            cout << "                                    " << endl;
            cout << "                                    " << endl;

            cin.clear();
            cin.ignore(219, '\n');
            return CustomizedSettings();
        }
    }
}

// This is the Main Menu for the game.
void MainMenu()
{
    cout << "---------------------------" << endl;
    cout << "WELCOME TO ALIENS VS ZOMBIES" << endl;
    cout << "---------------------------" << endl;
    cout << "         Main Menu         " << endl;
    cout << "---------------------------" << endl;

    int choice;
    {
        cout << "1. New Game" << endl;
        cout << "2. Load Game" << endl;
        cout << "3. Game Settings" << endl;
        cout << "4. Exit" << endl;
        cout << " " << endl;

        cout << "Enter a number: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "*Shows the board" << endl;
        }
        else if (choice == 2)
        {
            cout << "*Load into saved game" << endl;
        }
        else if (choice == 3)
        {
            GameSettings();
        }
        else if (choice == 4)
        {
            cout << "---------------------" << endl;
            cout << "Thank You For Playing" << endl;
            cout << "---------------------" << endl;
            TimeDelay(5);
        }
        else
        {
            cout << "                                    " << endl;
            cout << "                                    " << endl;
            cout << "----------------------------------------------------------" << endl;
            cout << "*****NOTE: Please Enter a Number Between 1 And 4 Only*****" << endl;
            cout << "----------------------------------------------------------" << endl;
            cout << "                                    " << endl;
            cout << "                                    " << endl;

            cin.clear();
            cin.ignore(219, '\n');
            return MainMenu();
        }
    }
}

// This is the user interface for Game Settings.
void GameSettings()
{

    cout << "---------------------" << endl;
    cout << "Default Game Settings" << endl;
    cout << "---------------------" << endl;
    
    cout << "Board Rows: " << board_rows << endl;
    cout << "Board Columns: " << board_columns << endl;
    cout << "Zombie Count: " << zombie_count << endl;

    cout << " " << endl;
    cout << "-----------------" << endl;
    cout << "     OPTIONS" << endl;
    cout << "-----------------" << endl;
    cout << " " << endl;

    int options;
    {
        cout << "1. Change Default Game Settings" << endl;
        cout << "2. Return To Main Menu" << endl;
        cout << " " << endl;

        cout << "Enter a number: ";
        cin >> options;

        if (options == 1)
        {
            CustomizedSettings();
        }
        else if (options == 2)
        {
            MainMenu();
        }
        else
        {
            cout << "                                    " << endl;
            cout << "                                    " << endl;
            cout << "-------------------------------------------------" << endl;
            cout << "*****NOTE: Please Enter Numbers 1 And 2 Only*****" << endl;
            cout << "-------------------------------------------------" << endl;
            cout << "                                    " << endl;
            cout << "                                    " << endl;

            cin.clear();
            cin.ignore(219, '\n');
            return GameSettings();
        }
    }
}

int main()
{
    MainMenu();

    return 0;
}