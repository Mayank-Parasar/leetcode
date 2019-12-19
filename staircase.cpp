//
// Created by Mayank Parasar on 2019-12-18.
//

/*
 * You are given a positive integer N which represents the number of steps in a staircase.
 * You can either climb 1 or 2 steps at a time. Write a function that returns the number of
 * unique ways to climb the stairs.
 *
 * */
// NOTE: this is a classic example of dynamic programming question...
// solve it using tabulation

#include <iostream>
#include <vector>

using namespace std;


vector<int> ways(1000, -1); // assuming we will not climb more than 1000 stairs

int staircase(int n) {
    if(n < 0)
        return 0;

    if(n == 0) // we have successfully completed the staircase
        return 1;

    // if already calculated and stored in the vector then use it
    if(ways[n] != -1)
        return ways[n];

    // return and store it in the vector
    return (ways[n] = staircase(n-1) + staircase(n-2));
}

int main() {

    cout << staircase(5);

    return 0;
}