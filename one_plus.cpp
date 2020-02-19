//
// Created by Mayank Parasar on 2020-02-18.
//

/*
 * Given a non-empty array where each element represents a digit of a non-negative integer, add one to the integer.
 * The most significant digit is at the front of the array and each element in the array contains only one digit.
 * Furthermore, the integer does not have leading zeros, except in the case of the number '0'.

    Example:
    Input: [2,3,4]
    Output: [2,3,5]

    Input: [2,9,9]
    Output: [3,0,0]

 */

#include <iostream>
#include <deque>

using namespace std;


deque<int> plus_one(deque<int> num) {

    // start from the end
//    for(int ii = num.size()-1; ii>= 0; ii--) {
//
//    }
    int ii = num.size() - 1;
    int carry = 1;
    int msb = 0;
    while(carry == 1) {
        if (ii == -1) {
            msb = 1;
            carry = 0; // next iteration not needed.
        }
        else if(num[ii] == 9) {
            num[ii] = 0;
            carry = 1;

            ii--; // need to do next iteration

        }
        else if(num[ii] < 9 ) {
            num[ii] = num[ii] + 1;
            carry = 0; // next iteration not needed
        }
    }

    if (msb == 1) {
        num.push_front(msb);
    }

    return num;
}

int main() {

    deque<int> num = {2, 9, 9};
    deque<int> num3 = {2, 3, 4};
    deque<int> num2 = {9, 9, 9};

    deque<int>result = plus_one(num3);

    for(auto i : result)
        cout << i << " ";


    return 0;
}