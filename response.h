//
// Created by Patrick on 1/26/17.
//

#ifndef MASTERMIND_ALGORITHM_RESPONSE_H
#define MASTERMIND_ALGORITHM_RESPONSE_H

#include <vector>
using namespace std;
template <typename T>

class Response
{
public:
    Response (vector<int> input);
    T operator<< (T y);  //operator overloading to make a print statement
    bool operator== (vector <int> compare);

private:
    void getguessvals(vector<T> x);
    void setguessvals(int set, int index);
    vector <int> guess();
    int guesssize;
    int guessvals[];
};

#endif //MASTERMIND_ALGORITHM_RESPONSE_H
