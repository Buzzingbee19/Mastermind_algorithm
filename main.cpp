//
//  main.cpp
//  DraftMasterMind
//
//  Created by Adam Bechtold on 1/22/17.
//  Copyright © 2017 Adam Bechtold. All rights reserved.
//

//QUESTIONS
// 1 -> SEE code.cpp
// 2 -> SEE code.h
// 3) naming conventions for classes

#include <iostream>
#include "code.h"



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //start
    Code myCode = Code(5, 10);
    
    //take a guess
    long guessOneArray[] = {5, 0, 3, 2, 6};
    long guessTwoArray[] = {2, 1, 2, 2, 2};
    long guessThreeArray[] = {1, 3, 3, 4, 5};
    vector<long> guessOne(guessOneArray, guessOneArray + 5);
    vector<long> guessTwo(guessTwoArray, guessTwoArray + 5);
    vector<long> guessThree(guessThreeArray, guessThreeArray + 5);
    
    
    //check correctness
    cout << "[" << myCode.checkCorrect(guessOne) << "," << myCode.checkIncorrect(guessOne) << "]" << endl;
    cout << "[" << myCode.checkCorrect(guessTwo) << "," << myCode.checkIncorrect(guessTwo) << "]" << endl;
    cout << "[" << myCode.checkCorrect(guessThree) << "," << myCode.checkIncorrect(guessThree) << "]" << endl;
    
    return 0;
}
