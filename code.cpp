//
//  code.cpp
//  DraftMasterMind
//
//  Created by Adam Bechtold on 1/22/17.
//  Copyright © 2017 Adam Bechtold. All rights reserved.
//


#include <stdlib.h>
//

#include <stdio.h>
#include <vector>
#include "code.h"
#include "d_random.h"

Code::Code(int n, int m) {
    this->n = n; //code length
    this->m = m; //range of digits
    
    this->secretCode = generateCode();
}

//generate random code -- it's SECRET
vector<long> Code::generateCode() {
    vector<long> code;
    
    randomNumber num = randomNumber(10);
    
    for(int i = 0; i < this->n; i++) {
                //int num = rand() % this->m;
        long number = num.random(10);
        code.push_back(number);
    }
    
    //tell the secret code - SPILL THE BEANS
    cout << "secret code: [";
    for (auto i = code.begin(); i != code.end(); ++i)
        std::cout << *i << ", ";
    
    cout << "]" << endl;
    
    return code;
}

//return the number of digits that are in the correct posistion
int Code::checkCorrect(vector<long> guess) {
    int correct = 0;
    
    //count the number of digits that are in the same position in the guess and the secret code
    for(int i = 0; i < this-> n; i++) {
        if (this->secretCode[i] == guess[i]) {
            correct++;
        }
    }
    
    return correct;
}

//number of digits in the guess that are also in the code but in the incorrect position
int Code::checkIncorrect(vector<long> guess) {
    int incorrect = 0;
    vector<int> checked;
    
    for (int i = 0; i < this->n; i++) {
        //check if digit has already been checked
        std::vector<int>::iterator it;
        it = std::find(checked.begin(), checked.end(), this->secretCode[i]);
        
        if (it != checked.end()) { //item is not in the checked list
            for (int j = 0; j < this->n; j++) {
                if (this->secretCode[i] == guess[i]) {
                    incorrect++;
                }
            }
        }
    }
    
    return incorrect;
}
