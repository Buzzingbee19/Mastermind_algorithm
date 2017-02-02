// Project 1b
// Adam Bechtold and Patrick Buzza
//
// Header file for the Code class.
//
// Contains the appropriate fields that store information regarding the code
// including the length of the code and the range of digits that the code can
// use.
// Declares the printCode() method that can be used on any kind of
// code object. It is here for testing purposes. Ideally, it would not apply
// secret codes.
//
// Declares two child classes of the Code class: SecretCode and 
// GuessCode.
//
// GuesCode includes:
//  - Constructor with code parameters and specific vector
//  - getCode
//
// SecretCode includes:
//  - checkCorrect
//  - checkIncorrect
//  - generateCode


#ifndef Code_h
#define Code_h

#include <vector>
using namespace std;

//parent class of SecretCode and GuessCode. Declares shared fields and methods
class Code
{
public:
    //constructor
    Code(int n, int m);

    //print out the code field of the Code
    void printCode();

protected:
    int n;
    int m;
    vector<long> code;
};

// GuessCode class used for user generated guesses
class GuessCode: public Code {
public:
    //constructor
    GuessCode(int n, int m, vector<long> code);

    //retrieve code vector - only applies to guess codes
    vector<long> getCode() const;
};

// SecretCode class used for randomly generated secret codes used for gameplay
class SecretCode: public Code {
public:
    SecretCode(int n, int m);
    int checkCorrect(GuessCode guess);
    int checkIncorrect(GuessCode guess);

private:
    vector<long> generateCode();
};


#endif //end of header file for code class
