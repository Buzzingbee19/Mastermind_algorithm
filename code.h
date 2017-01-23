//
//  code.h
//  DraftMasterMind
//
//  Created by Adam Bechtold on 1/22/17.
//  Copyright © 2017 Adam Bechtold. All rights reserved.
//

#ifndef code_h
#define code_h

#include <vector>

using namespace std;

class Code {
public:
    //constructor
    Code(int n, int m);
    //number of digits in guess that are in the correct place
    int checkCorrect(vector<long> guess);
    //number of digits in the guess that are also in the code but in the incorrent position
    int checkIncorrent(vector<long> guess);
    
private:
    int n; //code length
    int m; //range of digits
    vector<long> secretCode;
    vector<long> generateCode(); //generates secret code as a vector
};


#endif /* code_h */
