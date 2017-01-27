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
    SecretCode testSecret = SecretCode(5, 10);
    
    //set up automatic guesses
    long guessOneArray[] = {5, 0, 3, 2, 6};
    long guessTwoArray[] = {2, 1, 2, 2, 2};
    long guessThreeArray[] = {1, 3, 3, 4, 5};
    vector<long> guessVOne(guessOneArray, guessOneArray + 5);
    vector<long> guessVTwo(guessTwoArray, guessTwoArray + 5);
    vector<long> guessVThree(guessThreeArray, guessThreeArray + 5);
    GuessCode guessCodeOne = GuessCode(5,10,guessVOne);
    GuessCode guessCodeTwo = GuessCode(5,10,guessVTwo);
    GuessCode guessCodeThree = GuessCode(5,10,guessVThree);
    
    //check correctness
    cout << "\nresponse format: [correct digit in correct position, ";
    cout << "correct digit in wrong position]\n" << endl;

    //for testing using random seed "9"
    cout << "secret code: ";
    testSecret.printCode();
    cout << endl << endl;

    cout << "guess:        ";
    guessCodeOne.printCode();
    cout << " -> " << "[" << testSecret.checkCorrect(guessCodeOne) << ",";
    cout << testSecret.checkIncorrect(guessCodeOne) << "]" << endl;

    cout << "guess:        ";
    guessCodeTwo.printCode();
    cout << " -> " << "[" << testSecret.checkCorrect(guessCodeTwo) << ",";
    cout << testSecret.checkIncorrect(guessCodeTwo) << "]" << endl;
    
    cout << "guess:        ";
    guessCodeThree.printCode();
    cout << " -> " << "[" << testSecret.checkCorrect(guessCodeThree) << ",";
    cout << testSecret.checkIncorrect(guessCodeThree) << "]" << endl;

    cout << endl << "testing complete\n\n";
    cout << "Now, time to make a new code and take your own guess!\n\n";

    //Taking your own guess
    long responseNumber;
    int range, length;  //initialize the variables for user input

    //get parameters from user
    cout << "How many digits would like to have in your code: ";
    cin >> length;
    cout << "What is the range of numbers you wish to have in your code: ";
    cin >> range;
    cout << endl;

    //create a new secret code
    SecretCode yourSecret = SecretCode(length, range);

    cout << "This is your secret code: ";
    yourSecret.printCode();
    cout << "\nTest our code with a guess!\n";

    //get guess from user
    cout << "input your guess numbers: \n";
    vector<long> input;
    for (int i = 0; i < length; i++)
    {
        cout << ": ";
        cin >> responseNumber;
        input.push_back(responseNumber); //inserts number into guess vector
    }
    cout << endl;

    GuessCode yourGuess = GuessCode(length, range, input);

    //print guess performance
    int numCorrect = yourSecret.checkCorrect(yourGuess);
    int numIncorrect = yourSecret.checkIncorrect(yourGuess);

    //print results of checks in simple format
    cout << "secret code: ";
    yourSecret.printCode();
    cout << "\nguess code:  ";
    yourGuess.printCode();

    cout << "\nGuess accuracy: [" << numCorrect << ", " << numIncorrect << "]\n";

    //complete main function operation
    return 0;
}; //end program
