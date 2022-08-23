x#include "Hex.h"

// I know global functions are not good for OOP, Those are just helps menu in main
// for more smart and short code
/*
    If a fuctnion is longer than 30 line, it could bad design
                                - Yusuf Sinan Akgul :)
*/
void main_helper(vector<Hex> Games, bool select);
int setSelect(vector<Hex> Games);
void checkCinForFail();

int Hex::activeGames = 0;
int Hex::allGames = 0;

int main(void)
{
    vector<Hex> Games; 
    
    cout << "Welcome To The Most Excited Game In The World" << endl
    << "-------->>>>>>>>> HEX <<<<<<<<<--------\n" << endl;
    
    int command;
    string file;

    while(true)
    {
        cout << endl << "Menu: " << endl
        << "1- Start a new game" << endl
        << "2- Load a game from file and play" << endl
        << "3- Select and play an active game" << endl
        << "4- Show marked places count for an active game" << endl 
        << "5- Show marked places count for all active games" << endl
        << "6- Compare two active game " << endl
        << "7- RUN TEST: Load 5 file from directory. (For you to check quickly hocam :) ) " << endl
        << "8- Quit" << endl
        << endl << "Enter Command: ";
        
        cin >> command;
        checkCinForFail();

        if (command == 1)
            Games.push_back(Hex());
        else if (command == 2)
        {
            cout << "Enter file name: ";
            cin >> file;
            Games.push_back(Hex(file));
        }
        else if (command == 3)
        {
            main_helper(Games, true);
            int select = setSelect(Games);
            if (select == -1) continue;

            Games[select].setActive(active);
            Games[select].printTable();
            Games[select].playGame();
        }
        else if (command == 4)
        {
            main_helper(Games, true);
            int select = setSelect(Games);
            if (select == -1) continue;
            
            cout << "Game[" << select <<"]" << " Has " << Hex::countMarked(Games[select]) << " marked place" << endl; 
        }
        else if (command == 5)
        {
            main_helper(Games, false);
            int count = Hex::countMarked(Games);
            cout << "All marked cells for active games -> " << count  << endl;
        }
        else if (command == 6)
        {
            if (Hex::getActiveGames() < 2)
            {
                cout << "Active game count is smaller than two" << endl;
                continue;
            }
            main_helper(Games, true);
            int select = setSelect(Games);
            if (select == -1) continue;
            cout << "Select other game from list to compare: "; 
            int select2 = setSelect(Games);
            if (select2 == -1) continue;


            Games[select].compareMarked(Games[select2]);
        }
        else if (command == 7)
        {
            Games.push_back(Hex("ex0.txt", true));
            Games.push_back(Hex("ex1.txt", true));
            Games.push_back(Hex("ex2.txt", true));
            Games.push_back(Hex("ex3.txt", true));
            Games.push_back(Hex("ex4.txt", true));
        }
        else if (command == 8)
        {
            cout << "Goodbye my friend <3" << endl;
            return 0;
        }
        else
        {
            cout << "invalid " << endl; 
        }
    }
    return 0;
}

void main_helper(vector<Hex> Games, bool select)
{
    cout << "There are " << Hex::getActiveGames() << " active games." << endl << "All Games are:" << endl;
    for (int i = 0; i < Hex::getAllGames(); i++)
    {
        if (Games[i].getStatus() == winner)
            cout << "game[" << i << "]" << " ->>> ENDED with a winner" << endl; 
        else
            cout << "game[" << i << "]" << " -> Still Active" << endl; 
    }
    if (select)
        cout << "Select a game with number: ";
}

int setSelect(vector<Hex> Games)
{
    if (Hex::getActiveGames() == 0)
    {
        cout << "There are no active games" << endl; 
        return -1;
    }
    int select;
    cin >> select;
    checkCinForFail();
    if (select >= Hex::getAllGames() || select < 0) 
    {
        cout << "invalid" << endl;
        return -1;
    }
    else if (Games[select].getStatus() == winner)
    {
        cout << "This game has ended. " << endl;
        return -1;
    }
    
    return select;
}

void checkCinForFail()
{
    if(cin.fail())
    {
        cerr << "Your input is invalid" << endl;
        cin.clear();
        cin.ignore(100,'\n');
    }
}