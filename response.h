//
//  response.h
//  MastermindFinal
//
//  Created by Adam Bechtold on 1/30/17.
//  Copyright © 2017 Adam Bechtold. All rights reserved.
//

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


#endif /* response_h */
