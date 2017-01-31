//
//  mastermind.cpp
//  MastermindPartB
//
//  Created by Adam Bechtold on 1/28/17.
//  Copyright © 2017 Adam Bechtold. All rights reserved.
//

#include <vector>

#include "mastermind.h"
#include "response.h"
#include "code.h"

using namespace std;

Mastermind::Mastermind(int n, int m) : secret(5, 10)
//constructor if handed values to modify code type
{
//    SecretCode secret1 = SecretCode(n,m);
//    this->secret = secret1;
    this->secret = SecretCode(n, m);
    this->n = n;
    this->m = m;
}

Mastermind::Mastermind() : secret(5, 10)
//constructor using default values
{
    this->n = 5;
    this->m = 10;
//    SecretCode secret1 = SecretCode(5, 10);
//    this->secret = secret1;
    this->secret = SecretCode(5, 10);
}

void Mastermind::printSecret()
//print the secret code to the screen
{
    cout << "Secret code: ";
    this->secret.printCode();
    cout << endl;
}

GuessCode Mastermind::humanGuess()
//read guess and return GuessCode object
{
    //initialize variables
    vector<long> guess;
    int input;
    
    //get guess from user
    //cout << "input your guess numbers: \n";
    for (int i = 0; i < this->n; i++)
    {
        cout << ": ";
        cin >> input;
        guess.push_back(input); //inserts number into guess vector
    }
    cout << endl;
    
    GuessCode guessCode = GuessCode(this->n, this->m, guess);
    return guessCode;
}

Response Mastermind::getResponse(GuessCode guess)
//given two codes, return response object
{
    int numCorrect = this->secret.checkCorrect(guess);
    int numIncorrect = this->secret.checkIncorrect(guess);
    
    return Response(numCorrect, numIncorrect);
}

bool Mastermind::isSolved(Response r)
//does this response mean the game has been solved?
{
    Response solvedResponse = Response(this->n, 0);
    return (r == solvedResponse);
}

void Mastermind::playGame()
// initialize random code, print it to screen, and play game with user
{
    
    
    //print secret code to screen
    cout << "\nOK. For testing purposes, we'll show you your secret code:\n";
    this->printSecret();
    cout << endl;
    
    //tell user how many attempts they have
    int guessLimit = 10;
    cout << "You have " << guessLimit << " rounds to beat the code.\n\n";
    
    //explain feedback format
    cout << "Remember, the format of your feedback is:\n"
    << "[# completely correct digits, # right digits in the wrong spots]\n";
    
    //take guesses from users
    for (int i = 0; i < guessLimit; i++) {
        //prompt human for guess
        cout << "Input your guess\n";
        
        //take guess
        GuessCode guess = this->humanGuess();
        
        //get response
        Response r = this->getResponse(guess);
        
        //print reposne
        cout << "Accuracy: " << r << endl;
        
        //if this is correct, leave game
        if (this->isSolved(r)) {
            //exit message
            cout << "\n======== WINNER WINNER CHICKEN DINNER!!!! ========\n";
            cout << "\n+++++++++++++++++ YOU DID IT +++++++++++++++++++++\n\n";
            cout << "Congratulations you cracked the code. ";
            cout << "Play again to see if it was more than a fluke!\n\n";
            break;
        }
        
        //if it's not a winner
        else if (i == guessLimit - 1) {
            //exit message
            cout << "\n\nI hate to say it (enter to continue)";
            cin.ignore();
            cin.ignore();
            cout << "- I really do - ";
            cin.ignore();
            cout << "but that was your last guess...\n\n";
            cin.ignore();
            cout << "...bummer...\n\n";
            cin.ignore();
            cout << "Hey, there's always next time...\n\n\n";
            cin.ignore();
            cout << "...until there isn't.....";
            cin.ignore();
            break;
        }
        
        //take the next guess
        cout << "next guess: ";
    }
}
