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
#include "code.h"
using namespace std;

int main(){
    //Start program
    cout << "Welcome to Mastermind, the scintillating game to test your";
    cout << "reasoning skills! \n";
    cout << "Let's start with demonstrating a test! \n\n";
    
    //create test Code object
    Code myCode = Code(5, 10);

    //set up automatic guesses
//  long guessOneArray[] = {5, 0, 3, 2, 6};
//    long guessTwoArray[] = {2, 1, 2, 2, 2};
//    long guessThreeArray[] = {1, 3, 3, 4, 5};
    
        
    long guessOneArray[] = {0, 7, 4, 0, 7};
    long guessTwoArray[] = {7, 4, 0, 7, 0};
    long guessThreeArray[] = {1, 2, 4, 7, 7};
        
    vector<long> guessOne(guessOneArray, guessOneArray + 5);
    vector<long> guessTwo(guessTwoArray, guessTwoArray + 5);
    vector<long> guessThree(guessThreeArray, guessThreeArray + 5);
    
    
    //check correctness
    cout << "\nresponse format: [correct digit in correct position, ";
    cout << "correct digit in wrong position]\n" << endl;
//    cout << "guess:       (5, 0, 3, 2, 6) -> ";
//    cout << "[" << myCode.checkCorrect(guessOne) << ",";
//    cout << myCode.checkIncorrect(guessOne) << "]" << endl;
//    cout << "guess:       (2, 1, 2, 2, 2) -> ";
//    cout << "[" << myCode.checkCorrect(guessTwo) << ",";
//    cout << myCode.checkIncorrect(guessTwo) << "]" << endl;
//    cout << "guess:       (1, 3, 3, 4, 5) -> ";
//    cout << "[" << myCode.checkCorrect(guessThree) << ",";
//    cout << myCode.checkIncorrect(guessThree) << "]" << endl;
    
        
    //for testing using random seed "9"
    //gives secret code 0, 7, 4, 0, 7
    cout << "guess:       (0, 7, 4, 0, 7) -> ";
    cout << "[" << myCode.checkCorrect(guessOne) << ",";
    cout << myCode.checkIncorrect(guessOne) << "]" << endl;
    cout << "guess:       (7, 4, 0, 7, 0) -> ";
    cout << "[" << myCode.checkCorrect(guessTwo) << ",";
    cout << myCode.checkIncorrect(guessTwo) << "]" << endl;
    cout << "guess:       (1, 2, 4, 7, 7) -> ";
    cout << "[" << myCode.checkCorrect(guessThree) << ",";
    cout << myCode.checkIncorrect(guessThree) << "]" << endl;
    
    cout << endl << "testing complete\n\n";
    cout << "Now, time to make a new code and take your own guess!\n\n";

    
    
    //Taking your own guess
    vector<long> guess;  //initializes the guess vector
    long responseNumber;
    int range, digits;  //initialize the variables for user input
    
    //get parameters from user
    cout << "How many digits would like to have in your code: ";
    cin >> digits;
    cout << "What would you like your range of numbers to be: ";
    cin >> range;
    Code mastercode(digits, range);  //instantiate Code object
    
    //get guess from user
    cout << "input your guess numbers: \n";
    for (int i = 0; i < digits; i++)
    {
        cout << ": ";
        cin >> responseNumber;
        guess.push_back(responseNumber); //inserts number into guess vector
    }
    cout << endl;
    
    //print guess performance
    int numCorrect = mastercode.checkCorrect(guess);
    int numIncorrect = mastercode.checkIncorrect(guess);
    
    cout << "Guess accuracy: [" << numCorrect << ", " << numIncorrect << "]\n";
    
    //complete main function operation
    return 0;
}; //end program
