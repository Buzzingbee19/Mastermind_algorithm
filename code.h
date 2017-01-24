//
//  code.h
//  This is the header file for our code class.  This file defintes the
//  functions our main file will use to generate the random code,  compare
//  the guess made by the player, and return the number of guesses that are
//  correct and those that are correct but in the wrong spot.
//
//  Created by Adam Bechtold & Patrick Buzza on 1/22/17.
//  Copyright © 2017 Adam Bechtold & Patrick Buzza. All rights reserved.
//
<<<<<<< HEAD
=======


>>>>>>> origin/master
#ifndef code_h
#define code_h

#include <vector>

using namespace std;

class Code {
public:

    //constructor
    Code(int n, int m);

    //returns number of digits in guess that are in the correct place
    int checkCorrect(vector<long> guess);

    //returns number of digits in the guess that are also in the code but in the
    //incorrect position, given user guess
    int checkIncorrect(vector<long> guess);
    
private:
    int n; //code length
    int m; //range of digits
    vector<long> secretCode; //randomly generated code
    vector<long> generateCode(); //generates secret code as a vector
};

#endif /* code_h */
