 //  main.cpp
 //  DraftMasterMind
 //
 //  Created by Adam Bechtold on 1/22/17.
 //  Copyright © 2017 Adam Bechtold. All rights reserved.
 //
 #include <iostream>
 #include "code.h"
 #include "d_random.h"
using namespace std;

 void main(){
 
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
 cout << "\nresponse format: [correct digit in correct posistion, correct digit in wrong position]\n" << endl;
 cout << "guess:       (5, 0, 3, 2, 6) -> ";
 cout << "[" << myCode.checkCorrect(guessOne) << "," << myCode.checkIncorrect(guessOne) << "]" << endl;
 cout << "guess:       (2, 1, 2, 2, 2) -> ";
 cout << "[" << myCode.checkCorrect(guessTwo) << "," << myCode.checkIncorrect(guessTwo) << "]" << endl;
 cout << "guess:       (1, 3, 3, 4, 5) -> ";
 cout << "[" << myCode.checkCorrect(guessThree) << "," << myCode.checkIncorrect(guessThree) << "]" << endl;
    
 cout << endl;

 
 
 
 //Playing a new game
 int range, digits;  //initialize the variables taken in from the users to construct our code class
 cout<<"Welcome to Mastermind, the scintillating game to test your reasoning skills! \n How many digits would like to have in your code?";
 cin>>digits;
 cout<<"What would you like your range of numbers to be?";
 cin>>range;
 code mastercode(digits, range);
 vector<int> guess(digits);
 for (int i=0; i<digits;i++){
  	cout<<"Please input your guess for value "<<i<<"\n";
  	cin>>guess(i);
 }
 int numcorrect = mastercode.checkCorrect(guess);
 int numincorrect = mastercode.checkIncorrect(guess);
 cout<<"There were "<<numcorrect<<" correct numbers in their correct location, and "<<numincorrect<<" numbers in their incorrect location. \n";
/*
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
*/
};
