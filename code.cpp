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
    randomNumber num = randomNumber(9); //instantiates randomNumber object
    
    //create random numbers in desired range and assignes them to code vector
    for (int i = 0; i < this->n; i++)
    {
        //int num = rand() % this->m;
        long number = num.random(this->m);
        code.push_back(number);
    }
    
    //print the secret code to the terminal - for testing purpoees
    cout << "secret code: [";

    for (int i = 0; i < code.size(); i++)
    {
        cout << code[i];

        if (i != code.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
    
    //return secret code for allocation to private secretCode field
    return code;
} //end of generateCode function

int Code::checkCorrect(vector<long> guess)
//return the number of digits that are in the correct posistion
{
    int correct = 0;
    
    //count the number of digits that are in the same position in the guess
    // and the secret code
    for (int i = 0; i < this->n; i++)
    {
        if (this->secretCode[i] == guess[i])
            correct++;
    }
    return correct;
} //end of checkCorrect function

int Code::checkIncorrect(vector<long> guess)
//number of digits in the guess in the code but in the incorrect position
{
    int incorrect = 0;
    vector<long> checkedIndices; //tracks which indices of have been processed
    
    //find which indices were covered in checkCorrect
    for (int i = 0; i < this->n; i++)
    {
        if (this->secretCode[i] == guess[i])
            checkedIndices.push_back(i);
    }
    
    //moves through elements in the guess to see if they are in secret code
    for (int i = 0; i < this->n; i++)
    {
        //check it any of secretCode's elements match guess[i]
        // ignore elements in secretCode that have already been counted
        for (int j = 0; j < this->n; j++)
        {
            //ensure that j is not one of the indices that has been checked
            bool found = false;

            for (int a = 0; a < checkedIndices.size(); a++)
            {
                if (j == checkedIndices[a])
                    found = true; //this index was used
            }
            
            //skip j index if it has been used
            if (found)
                continue;
            
            //if same digit found in different indices
            //  add secretCode index to checked vector
            //  increment incorrect variable
            //  break from loop to avoid double counting
            if (guess[i] == this->secretCode[j])
            {
                checkedIndices.push_back(j);
                incorrect++;
                break;
            }
        }
    }
    
    //return number of incorrect
    return incorrect;
} //end checkIncorrect

//end of class Code method definitions
