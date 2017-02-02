// Project 1b
// Adam Bechtold and Patrick Buzza
//
// Main file for the Mastermind game.
//
// Greets the user and allows them to customize the game parameters.
// Based on this input, a Mastermind object is modified or used with its
// default settings. The game is then played through the playGame() method
// of the Mastermind object.

#include <iostream>
#include "mastermind.h"

using namespace std;

int main(){

    //declare mastermind object here to establish scope
    //  can be overwritten later if user chooses to
    Mastermind master = Mastermind();

    //greet player
    cout << "Welcome to Mastermind, the scintillating game to test your";
    cout << "reasoning skills! \n";

    //get paramters from user
    cout << "Would you like to enter your own code parameters? (y/n) ";
    char x;
    cin >> x;

    //if they place parameters
    //TODO
    if (x == 'y') {
        int n;
        int m;

        //take parameter from user
        cout << "\nHow many digits long should your code be: ";
        cin >> n;
        cout << "\nWhat do you want the your range of digits to be: ";
        cin >> m;

        //create new mastermind object with new paramters
        Mastermind newMaster = Mastermind(n, m);

        //pass value back to original Mastermind object - to maintain scope
        master = newMaster;
    }

    //start playing the game
    master.playGame();

    return 0;
} // end of the main file
