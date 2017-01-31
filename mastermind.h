//
//  mastermind.hpp
//  MastermindPartB
//
//  Created by Adam Bechtold on 1/28/17.
//  Copyright © 2017 Adam Bechtold. All rights reserved.
//

#ifndef mastermind_h
#define mastermind_h

#include "code.h"
#include "response.h"
#include <stdio.h>


class Mastermind {
    
public:
    //constructor for values read from keyboard
    Mastermind(int n, int m);
    
    //constructor using default values
    Mastermind();
    
    //prints secret code
    void printSecret();
    
    //read guess and return GuessCode object
    GuessCode humanGuess();
    
    //given two codes, return Response object
    Response getResponse(GuessCode guess);
    
    //does this response mean the game has been solved?
    bool isSolved(Response r);
    
    //iniitalize random code, print it to screen, and plays game with user
    void playGame();
    
private:
    SecretCode secret;
    int n;
    int m;
};


#endif //end of the mastermind header file
