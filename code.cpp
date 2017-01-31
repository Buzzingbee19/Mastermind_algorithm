
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
    for (int i = 0; i < this->n; i++)
    {
        cout << this->code[i];
        if (i != this->n - 1)//if not the last element, also print spacer
            cout << " ";
    }
    cout << ")";
}

GuessCode::GuessCode(int n, int m, vector<long> code) : Code(n,m)
//constructor modiifcations for GuessCode child class
{
    this->code = code;
}

vector<long> GuessCode::getCode() const
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
    randomNumber num = randomNumber(1234); //instantiates randomNumber object
    
    //create random numbers in desired range and assignes them to code vector
    for (int i = 0; i < this->n; i++)
    {
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
    int incorrect = 0;  //initializes number of incorrectly located digis
    vector<long> modSecret; //modifiable vector to preserve original vectors
    vector<long> modGuess;
    
    //for (int i = this->n - 1; i >= 0; i--)
    for (int i = 0; i < this->n; i++)
    {
        //determines if guess was in correct location.  If not, adds guess and
        //secret to vectors from before to be used later.
        if(this->code[i] != guess.getCode()[i])
        {
            modSecret.push_back(this->code[i]);
            modGuess.push_back(guess.getCode()[i]);
        }
        
    }
    
    //number of remaining digits which weren't equivalent to the secret code
    long guessSize = modGuess.size();
    
    //moves through elements in the guess to see if they are in secret code
    for (long i = guessSize - 1; i >= 0; i--)
    {
        long secretSize = modSecret.size();
        
        for (long j = secretSize - 1; j >= 0; j--)
        {
            //If a guess value is found in the remaining secret code
            //values, it erases each value from respective vectors,
            //and increments the incorrect counter
            if (modGuess[i] == modSecret[j])
            {
                modGuess.erase(modGuess.begin() + i);
                modSecret.erase(modSecret.begin() + j);
                incorrect++;
                break;
            }
        }
    }
    return incorrect; //return number of incorrect
} //end checkIncorrect
