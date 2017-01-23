#ifndef code_h
#define code_h

class code {
	public:
		code(int n, int m);
		int checkCorrect (vector<int> guess); //returns number of correct digits in the correct location
		int checkIncorrect (vector<int> guess); //returns number of correct digits in the incorrect location
	private:
		int n; //specifies number of digits random generator will use to determine secret code
		int m; //specifies range of digits random generator will use to determine secret code
		vector<int> random_code_gen();
};
