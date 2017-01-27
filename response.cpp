//
// Created by Patrick on 1/26/17.
//

#include <vector>
#include "response.h"
#include <iostream>
using namespace std;

Response::Response (vector<int> input)
{
    vector <int> guess(input);
    this -> guesssize = guess.size();
    int guessvals(guesssize);
    getguessvals(guess);
};

template <typename T>
void Response::getguessvals(vector<T> x)
{
    vector<int> temp(x);

    for (int i = guesssize-1; i >= 0; i--)
    {
        setguessvals(temp.back(), i);
        temp.pop_back();
    }
};
void Response::setguessvals(int set, int index)
{
    guessvals[index]=set;
};

bool Response::operator== (vector <int> compare)
{
    if (guess == compare)
        return 1;
    else
        return 0;
};

template <typename T>
T Response::operator<<(T y)
{
    std::cout<<y;
    return 0;
};
