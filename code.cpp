//
//  code.cpp
//  This is the implementation file for our code class.  This file excecutes the
//  functions our main file will use to generate the random code,  compare
//  the guess made by the player, and return the number of guesses that are
//  correct and those that are correct but in the wrong spot.
//
//  Created by Adam Bechtold & Patrick Buzza on 1/22/17.
//  Copyright © 2017 Adam Bechtold & Patrick Buzza. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "code.h"
#include "d_random.h"

Code::Code(int n, int m)
{
    this->n = n; //code length
    this->m = m; //range of digits
    //calls the generateCode function to randomly generate a code of length n.
    this->secretCode = generateCode();
}
//generate random code -- it's SECRET
vector<long> Code::generateCode()
{
    vector<long> code;

    for(int i = 0; i < this->n; i++)
    {
        //randomNumber num = randomNumber(this->m);
        int num = rand() % this->m;
        code.push_back(num);
    }

    for (auto i = code.begin(); i != code.end(); ++i)
        std::cout << *i << ' ';

    std::cout << endl;

    return code;
}
//return the number of digits that are in the correct posistion
int Code::checkCorrect(vector<long> guess)
{
    int correct = 0;

    //count the number of digits that are in the same position in the guess and the secret code
    for(int i = 0; i < this-> n; i++)
    {

        if (this->secretCode[i] == guess[i])
            correct++;
    }

    return correct;
}

//number of digits in the guess that are also in the code but in the incorrect position
int Code::checkIncorrect(vector<long> guess) {
    int incorrect = 0;
    vector<int> checked;

    for (int i = 0; i < this->n; i++) {
        //check if digit has already been checked
        std::vector<int>::iterator it;
        it = std::find(checked.begin(), checked.end(), this->secretCode[i]);

        if (it != checked.end()) { //item is not in the checked list
            for (int j = 0; j < this->n; j++) {
                if (this->secretCode[i] == guess[i]) {
                    incorrect++;
                }
            }
        }
    }

    return incorrect;
}
