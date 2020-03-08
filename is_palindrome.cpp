//
// Created by Mayank Parasar on 2020-03-08.
//

/*
Given an integer, check if that integer is a palindrome.
For this problem do not convert the integer to a string to check if it is a palindrome.

import math

def is_palindrome(n):
  # Fill this in.

print is_palindrome(1234321)
# True
print is_palindrome(1234322)
# False*/

#include<iostream>
#include<vector>

using namespace std;

bool is_palindrome(unsigned long int num) {
    vector<int> num_vec;
    // vectorize this number
    while(num > 0) {
        num_vec.push_back(num%10);
        num = num / 10;
    }

    // process this vector
    int ii, kk;
    for(ii = 0, kk = (num_vec.size()-1); ii < kk; ii++, kk--) {
        if(num_vec[ii] == num_vec[kk])
            continue;
        else
            return false;
    }

    return true;
}

int main() {
    unsigned long int a = 1234322;
    cout << boolalpha;

    cout << is_palindrome(a);

    return 0;
}