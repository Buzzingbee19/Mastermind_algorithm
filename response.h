// Project 1b
// Adam Bechtold and Patrick Buzza
//
// Header file for the Response class.
// Contains the appropriate private fields
// that store the number of correct digits and correct digitis in the incorrect
// position. Also contains declarations of the methods neccessary to use the
// response objects including:
//  - a Constructur
//  - setNumCorrect
//  - setNumIncorrect
//  - getNumCorrect
//  - getNumIncorrect
//  - overloaded operators == and <<

#ifndef response_h
#define response_h

#include <stdio.h>
#include <iostream>

using namespace std;

class Response
{
public:
    //constructor
    Response(int numCorrect, int numIncorrect);

    //sets the numCorrect field of the Response object
    void setNumCorrect(int a);

    //sets the numIncorrect field of the Response object
    void setNumIncorrect(int a);

    //return the numCorrect value of the Response object
    int getNumCorrect();

    //return the numIncorrect value of the Response object
    int getNumIncorrect();


    //overload << operator - to print the response accuracy
    friend ostream& operator<< (ostream& ostr, const Response& r);

    //overload == operator - to compare to Response objects
    friend bool operator == (const Response &lhs, const Response &rhs);

private:
    int numCorrect; //number of digits in the correct position
    int numIncorrect; //number of digits in the incorrect position
};


#endif //end of the Response class header fileß
