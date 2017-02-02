// Project 1b
// Adam Bechtold and Patrick Buzza
//
// Header file for the Mastermind class.
//
// Contains the appropriate fields that store a SecretCode object that is used
// throughout gameplay as well as its length and the range of digits it can
// hold.  Also contains declarations of the methods neccessary to use the
// Mastermind objects including:
//  - a Constructor with user defined values
//  - a Constructor with default values
//  - printSecret
//  - humanGuess
//  - getResponse
//  - isSolved
//  - playGame

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
    SecretCode secret; //secret code used throughout gameplay
    int n; //length of the SecretCode and the guesses throughout the game
    int m; //the range of numbers than can be in the SecretCode and guesses
};


#endif //end of the Mastermind header file
