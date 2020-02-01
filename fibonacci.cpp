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

using namespace std;

int fibonacci(int term) {
    if(term == 0 || term == 1)
        return term;
    else
        return (fibonacci(term - 2) + fibonacci(term - 1));
}

int main() {
    cout << fibonacci(7);
    return 0;
}