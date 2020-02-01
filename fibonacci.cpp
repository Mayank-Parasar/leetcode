//
// Created by Mayank Parasar on 2020-02-01.
//

/*
 * The Fibonacci sequence is the integer sequence defined by the recurrence relation:
 * F(n) = F(n-1) + F(n-2), where F(0) = 0 and F(1) = 1. In other words, the nth Fibonacci number
 * is the sum of the prior two Fibonacci numbers. Below are the first few values of the sequence:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144...

Given a number n, print the n-th Fibonacci Number.
Examples:
Input: n = 3
Output: 2

Input: n = 7
Output: 13
 */

#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int term) {
    if(term == 0 || term == 1)
        return term;
    else
        return (fibonacci(term - 2) + fibonacci(term - 1));
}

// fibonacci using memoization
vector<int> f_array(100, -1);

int f(int n) {
    if(f_array[n] != -1)
        return f_array[n];
    else if(n == 0 | n== 1){
        return f_array[n];
    }
    else{
        return (f_array[n] = f(n-1) + f(n-2));
    }

}

int main() {
    cout << fibonacci(7);
    int n = 7;
    cout << endl;
    f_array[0] = 0;
    f_array[1] = 1;
    cout << f(7);
    return 0;
}