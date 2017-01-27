//
// Created by Patrick on 1/27/17.
//

#include "mastermind.h"
#include <vector>
#include <iostream>
#include "code.h"
using namespace std;

Mastermind::Mastermind()
//default constructor used to initialize class if no objects are passed
{
    int n = 5, m=10;
    SecretCode Secret(n, m);
};

Mastermind::Mastermind(int length, int digits)
//constructor used if passed a length and range of digits to be used
{
    this -> n = length;
    this -> m = digits;
    SecretCode Secret(n, m);
};

void Mastermind::humanGuess()
//
{
    vector<long> guess;

    for (int i = 0; i < n; i++)
    {
        long guessvalues;
        cout << "Please input guess for index "<<i;
        cin >> guessvalues;
        guess.push_back(guessvalues);
        GuessCode Guess (n, m, guess);
    }
};

void Mastermind::getResponse()
{
    correct = Secret.checkCorrect(Guess);
    incorrect = Secret.checkCorrect(Guess);
};

void Mastermind::printCode()
{
    Secret.printCode();
};

void Mastermind::isSolved()
{

};

void Mastermind::playGame()
{

};