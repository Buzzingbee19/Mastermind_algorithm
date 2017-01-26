//  This is the implementation file for our code class.  This file executes the
//  functions our main file will use to generate the random code,  compare
//  the guess made by the player, and return the number of guesses that are
//  correct and those that are correct but in the wrong spot.
//
//  Adam Bechtold & Patrick Buzza

#include <vector>
#include "code.h"
#include "d_random.h"
using namespace std;

Code::Code(int n, int m)
//constructor for code class
{
    this->n = n; //code length
    this->m = m; //range of digits
}

void Code::printCode()
//print out the object's code
{
    cout << "(";
    for (int i = 0; i < this->n; i++) {
        cout << this->code[i];
        if (i != this->n - 1)
            cout << " ";
    }
    cout << ")";
}

GuessCode::GuessCode(int n, int m, vector<long> code) : Code(n,m)
//constructor modiifcations for GuessCode child class
{
    this->code = code;
}

vector<long> GuessCode::getCode()
//retrieve code vector - only applies to guess codes
{
    return this->code;
}


SecretCode::SecretCode(int n, int m) : Code(n,m)
//constructor modifications for the SecretCode child class
{
    this->code = generateCode();
}

vector<long> SecretCode::generateCode()
//generate random code to be stored in the secretCode private field
{
    vector<long> code; //creates empty code vector
    randomNumber num = randomNumber(1203); //instantiates randomNumber object
    
    //create random numbers in desired range and assignes them to code vector
    for (int i = 0; i < this->n; i++)
    {
        //int num = rand() % this->m;
        long number = num.random(this->m);
        code.push_back(number);
    }

    
    //return secret code for allocation to private secretCode field
    return code;
} //end of generateCode function


int SecretCode::checkCorrect(GuessCode guess)
//return the number of digits that are in the correct posistion
{
    int correct = 0;
    
    //count the number of digits that are in the same position in the guess
    // and the secret code
    for (int i = 0; i < this->n; i++)
    {
        if (this->code[i] == guess.getCode()[i])
            correct++;
    }
    return correct;
} //end of checkCorrect function

int SecretCode::checkIncorrect(GuessCode guess)
//number of digits in the guess in the code but in the incorrect position
{
    int incorrect = 0;
    vector<long> secretIndices; //tracks counted indices in secret code
    vector<long> guessIndices; //tracks counted indices in guess code
    
    //find which indices were covered in checkCorrect
    for (int i = 0; i < this->n; i++) {
        if (this->code[i] == guess.getCode()[i]) {
            secretIndices.push_back(i);
            guessIndices.push_back(i);
        }
    }
    
    //moves through elements in the guess to see if they are in secret code
    for (int i = 0; i < this->n; i++)
    {
        //check if this index has been checking in the guess code
        bool guessChecked = false;
        for(int a = 0; a < guessIndices.size(); a++) {
            if (i == guessIndices[a])
                guessChecked = true;
        }
        
        //if this has been checked, skip this guess index
        if (guessChecked)
            continue;
        
        //check it any of secretCode's elements match guess[i]
        // ignore elements in secretCode that have already been counted
        for (int j = 0; j < this->n; j++)
        {
            //ensure that j is not one of the indices that has been checked
            bool secretChecked = false;
            for (int a = 0; a < secretIndices.size(); a++) {
                if (j == secretIndices[a])
                    secretChecked = true; //this index was used
            }
            
            //skip j index if it has been used
            if (secretChecked)
                continue;
            
            //if same digit found in different indices
            //  add secretCode index to checked vector
            //  increment incorrect variable
            //  break from loop to avoid double counting
            if (guess.getCode()[i] == this->code[j]) {
                secretIndices.push_back(j);
                incorrect++;
                break;
            }
        }
    }
    
    //return number of incorrect
    return incorrect;
} //end checkIncorrect
