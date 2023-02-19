// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: T13L 
// Names: HANS MATTHEW | MUHAMMAD AZRAF BIN MOHD AKMAM | SANAN MD SABBIN ISLAM 
// IDs: 1201103273 | 1221303415 | 1211306802
// Emails: 1201103273@student.mmu.edu.my | 1221303415@student.mmu.edu.my | 1211306802@student.mmu.edu.my 
// Phones: +60126183518 | +60129008915 | +60182136056 

// TODO:
// 1. Save or load game file.
// 2. Zombies and objects have not been added to the board. Therefore, no characters are able to attack.
// 3. No character attributes are given such as life, attack, and range. 
// 4. No movement is added to the characters. In addition, no trail is added when the Alien moves.
// 5. The game does not show whose turn is it for.
// 6. The alien is not able to react with any objects since no objects are added.

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

int board_rows = 3;
int board_columns = 5;
int zombie_count = 2;

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
void Printboard(int, int);
void Typecommands();
void Helpcommand();

// This is when users input "help" as their command.
void Helpcommand()
{
    cout << endl;
    cout << "---------------" << endl;
    cout << "Typing Commands" << endl;
    cout << "---------------" << endl;
    cout << endl;
    cout << "1. up    ->  Moves the character 'A' upwards." << endl;
    cout << "2. down  ->  Moves the character 'A' downwards." << endl;
    cout << "3. left  ->  Moves the character 'A' towards the left." << endl;
    cout << "4. right ->  Moves the character 'A' towards the right." << endl;
    cout << "5. arrow ->  Switches the direction of the arrow in the game board." << endl;
    cout << "6. help  ->  Displays the command inputs." << endl;
    cout << "7. save  ->  Saves the current progress of the game." << endl;
    cout << "8. load  ->  Loads the progress of a game." << endl;
    cout << "9. quit  ->  Quits the current progress of the game." << endl;
    cout << endl;
    cout << endl;

    Printboard(board_rows, board_columns);
}

// This is when users type in their command when the board is shown.
void Typecommands()
{
    string command;
    string name;

    cout << endl;
    cout << endl;
    cout << "Enter command(Type help to view typing commands): ";
    cin >> command;

    if (command == "help")
    {
        Helpcommand();
    }
    else if (command == "up")
    {
        cout << "A moves up" << endl;
        Printboard(board_rows, board_columns);
    }
    else if (command == "down")
    {
        cout << "A moves down" << endl;
        Printboard(board_rows, board_columns);
    }
    else if (command == "left")
    {
        cout << "A moves left" << endl;
        Printboard(board_rows, board_columns);
    }
    else if (command == "right")
    {
        cout << "A moves right" << endl;
        Printboard(board_rows, board_columns);
    }
    else if (command == "arrow")
    {
        cout << "Switches direction of arrow" << endl;
        Printboard(board_rows, board_columns);
    }
    else if (command == "save")
    {
        cout << "Saves game" << endl;
        Printboard(board_rows, board_columns);
    }
    else if (command == "load")
    {
        cout << "Loads game" << endl;
        Printboard(board_rows, board_columns);
    }
    else if (command == "quit")
    {
        cout << "Are you sure you would like to quit the game? All unsaved progress will be lost." << endl;
        cout << "Enter (Y/y) to quit or enter (N/n) to go back: ";
        cin >> name;

        if (name == "Y" || name == "y")
        {
            cout << "----------------------" << endl;
            cout << "Returning to Main Menu" << endl;
            cout << "----------------------" << endl;
            TimeDelay(5);
            MainMenu();
        }
        else if (name == "N" || name == "n")
        {
            cout << endl;
            cout << "-----------------------" << endl;
            cout << "Returning to game board" << endl;
            cout << "-----------------------" << endl;
            Printboard(board_rows, board_columns);
        }
        else
        {
            cout << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "Invalid input. Please enter your command again." << endl;
            cout << "-----------------------------------------------" << endl;
            cout << endl;
            return Typecommands();
        }
    }
    else
    {
        cout << endl;
        cout << "---------------------------" << endl;
        cout << "Please enter a valid input." << endl;
        cout << "---------------------------" << endl;
        cout << endl;
        Printboard(board_rows, board_columns);
    }
}

// This is the main game board.
void Printboard(int, int)
{
    // Creating the game board as a vector of vectors.
    vector<vector<char>> gameboard(board_rows, vector<char>(board_columns, ' '));

    // Places the character 'A' at the center of the board.
    int centerofrows = board_rows / 2;
    int centerofcolumns = board_columns / 2;
    gameboard[centerofrows][centerofcolumns] = 'A';

    // Prints out the game board.
    for (int i = 0; i < board_rows; i++)
    {
        // Prints out the border at the top.
        cout << "   ";
        for (int j = 0; j < board_columns; j++)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // Prints out the row numbers on the left
        if (i < 9)
        {
            cout << " " << i + 1 << " ";
        }
        else
        {
            cout << i + 1 << " ";
        }

        // Divides each row into multiple sections for a clearer view.
        // Prints out the characters.
        for (int j = 0; j < board_columns; j++)
        {
            cout << "|" << gameboard[i][j];
        }
        cout << "|" << endl;
    }

    // Prints out the border at the bottom.
    cout << "   ";
    for (int j = 0; j < board_columns; j++)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    // Prints out the column numbers at the bottom.
    cout << "    ";
    if (board_columns == 3)
    {
        cout << "1 2 3";
    }
    else if (board_columns == 5)
    {
        cout << "1 2 3 4 5";
    }
    else if (board_columns == 7)
    {
        cout << "1 2 3 4 5 6 7";
    }
    else if (board_columns == 9)
    {
        cout << "1 2 3 4 5 6 7 8 9";
    }
    else if (board_columns == 11)
    {
        cout << "1 2 3 4 5 6 7 8 9 1 1" << endl;
        cout << "                      0 1";
    }
    else if (board_columns == 13)
    {
        cout << "1 2 3 4 5 6 7 8 9 1 1 1 1" << endl;
        cout << "                      0 1 2 3";
    }
    else if (board_columns == 15)
    {
        cout << "1 2 3 4 5 6 7 8 9 1 1 1 1 1 1" << endl;
        cout << "                      0 1 2 3 4 5";
    }
    else if (board_columns == 17)
    {
        cout << "1 2 3 4 5 6 7 8 9 1 1 1 1 1 1 1 1" << endl;
        cout << "                      0 1 2 3 4 5 6 7";
    }
    else if (board_columns == 19)
    {
        cout << "1 2 3 4 5 6 7 8 9 1 1 1 1 1 1 1 1 1 1" << endl;
        cout << "                      0 1 2 3 4 5 6 7 8 9";
    }
    Typecommands();
}

// This is to delay the time in an organized manner after users exit the game.
// It leaves them enough time to view the output before the program ends.
void TimeDelay(int a)
{
    int add;
    int time;
    int i;

    time = a * 100000000000;

    for (i = 0; i < time; i++)
    {
        add *= i;
        add++;
        add++;
    }
}

// This is when user enters an invalid input for the amount of zombies.
void ZombieCountError()
{
    cout << "                                    " << endl;
    cout << "                                    " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "*****NOTE: Please Enter Numbers Between 1 And 8 Only*****" << endl;
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
    cout << "Enter New Amount Of Zombies(*NOTE: Maximum 8 zombies): ";
    cin >> zombie_count;

    if (zombie_count > 8)
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
            cout << endl;
            Printboard(board_rows, board_columns);
        }
        else if (choice == 2)
        {
            cout << endl;
            Printboard(board_rows, board_columns);
        }
        else if (choice == 3)
        {
            cout << endl;
            GameSettings();
        }
        else if (choice == 4)
        {
            cout << endl;
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