//  This is the header file for our code class.  This file defines the
//  functions our main file will use to generate the random code,  compare
//  the guess made by the player, and return the number of guesses that are
//  correct and those that are correct but in the wrong spot.
//
//  Adam Bechtold & Patrick Buzza

#ifndef Code_h
#define Code_h

#include <vector>
using namespace std;

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

class GuessCode: public Code {
public:
    //constructor
    GuessCode(int n, int m, vector<long> code);
    
    //retrieve code vector - only applies to guess codes
    vector<long> getCode() const;
    
};

class SecretCode: public Code {
public:
    SecretCode(int n, int m);
    int checkCorrect(GuessCode guess);
    int checkIncorrect(GuessCode guess);
    
private:
    vector<long> generateCode();
};


#endif //end of header file for code class
