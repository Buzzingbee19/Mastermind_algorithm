// Project 1b
// Adam Bechtold and Patrick Buzza
//
// cpp file for the Resposne class.
// Implements the methods declared in the header file response.h including:
//  - a Constructur
//  - setNumCorrect
//  - setNumIncorrect
//  - getNumCorrect
//  - getNumIncorrect
//  - overloaded operators == and <<

#include "response.h"


Response::Response(int numCorrect, int numIncorrect)
//constructor for Response class
{
    this->numCorrect = numCorrect;
    this->numIncorrect = numIncorrect;
}

void Response::setNumCorrect(int a)
//set the numCorrect field of the Response object
{
    this->numCorrect = a;
}

void Response::setNumIncorrect(int a)
//set the numIncorrect field of the Response object
{
    this->numIncorrect = a;
}


int Response::getNumCorrect()
//return the numCorrect field of the Response object
{
    return this->numCorrect;
}


int Response::getNumIncorrect()
//return the numIncorrect field of the Response object
{
    return this->numIncorrect;
}


ostream& operator<< (ostream& ostr, const Response& r)
//operator overload for << in Response objects
{
    ostr << "[" << r.numCorrect << "," << r.numIncorrect << "]";
    return ostr;
}

bool operator == (const Response &lhs, const Response &rhs)
//operator overload for ==
{
    return (lhs.numIncorrect == rhs.numIncorrect && lhs.numCorrect == rhs.numCorrect);
}
