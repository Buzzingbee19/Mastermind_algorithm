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

    //calls the generateCode function to randomly generate a code of length n.
    this->secretCode = generateCode();
}

vector<long> Code::generateCode()
//generate random code to be stored in the secretCode private field
{
    vector<long> code; //creates empty code vector
    randomNumber num = randomNumber(10); //instantiates randomNumber object 
    
    //creates random numbers in desired range and assignes them to the code vector
    for (int i = 0; i < this->n; i++)
    {
        //int num = rand() % this->m;
        long number = num.random(10);
        code.push_back(number);
    }
    
    //print the secret code to the terminal - for testing purpoees
    cout << "secret code: [";
    for (auto i = code.begin(); i != code.end(); ++i)
        std::cout << *i << ", ";
    cout << "]" << endl;
    
    //return secret code for allocation to private secretCode field
    return code;
} //end of generateCode function

int Code::checkCorrect(vector<long> guess)
//return the number of digits that are in the correct posistion
{
    int correct = 0;
    
    //count the number of digits that are in the same position in the guess and the secret code
    for (int i = 0; i < this-> n; i++)
    {
        if (this->secretCode[i] == guess[i])
            correct++;
    }
    return correct;
}

int Code::checkIncorrect(vector<long> guess)
//number of digits in the guess that are also in the code but in the incorrect position
{
    int incorrect = 0;
    vector<int> checked; //checked vector tracks which elements have been processed
    
    //moves through elements in the guess to see if they are in secret code
    for (int i = 0; i < this->n; i++)
    {
        //check if digit has already been checked
        std::vector<int>::iterator it;
        it = std::find(checked.begin(), checked.end(), this->secretCode[i]);
        
        if (it != checked.end()) //item is not in the checked list
        {
            for (int j = 0; j < this->n; j++)
            {
                if (this->secretCode[i] == guess[i])
                    incorrect++;

            }
        }
    }
    return incorrect;
} //end checkIncorrect
