#include <cstdlib>
#include <vector>
#include "code.h"
#include "d_random.h"

void main(){
	int range, digits;
	cout<<"Welcome to Mastermind, the scintillating game to test your reasoning skills! \n How many digits would like to have in your code?";
	cin>>digits;
	cout<<"What would you like your range of numbers to be?";
	cin>>range;
	code mastercode(digits, range);
	vector<int> guess(digits);
	for (int i=0; i<digits;i++){
		cout<<"Please input your guess for value "<<i<<"\n;
		cin>>guess(i);
	} 
	int numcorrect = mastercode.checkCorrect(guess);
};
