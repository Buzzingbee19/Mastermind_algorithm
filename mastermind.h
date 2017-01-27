//
// Created by Patrick on 1/27/17.
//

#ifndef MASTERMIND_ALGORITHM_MASTERMIND_H
#define MASTERMIND_ALGORITHM_MASTERMIND_H

#include <vector>
#include "code.h"
using namespace std;

class Mastermind
{
public:
    Mastermind ();
    Mastermind(int length, int digits);
    void printCode();

private:
    void humanGuess();
    void getResponse();
    void isSolved();
    void playGame();
    friend SecretCode Secret;
    friend GuessCode Guess;
    int n;
    int m;
    int correct;
    int incorrect;
};


#endif //MASTERMIND_ALGORITHM_MASTERMIND_H
