//  This is the main file of the function which runs a test of our objects and
//  methods using pre-selected parameters and guesses. The output of the secret
//  code and the guess is displayed.
//  Also includes a second portion that allows a user to create a new code based
//  on any numerical parameters and allows them to place a guess and see the
//  accuracy of their guess. Displays the new secret code as it is for testing
//  and demonstration purposes.
//
//  Adam Bechtold & Patrick Buzza

#include <iostream>
#include "mastermind.h"

using namespace std;

int main(){
    
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
    
    master.playGame();
    
    return 0;
    
}
