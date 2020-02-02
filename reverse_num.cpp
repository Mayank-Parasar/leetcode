//
// Created by Mayank Parasar on 2020-02-01.
//

/*
 * Write a function that reverses the digits a 32-bit signed integer, x.
 * Assume that the environment can only store integers within the 32-bit signed integer range,
 * [-2^31, 2^31 - 1]. The function returns 0 when the reversed integer overflows.

Example:
Input: 123
Output: 321
class Solution:
  def reverse(self, x):
    # Fill this in.

print(Solution().reverse(123))
# 321
print(Solution().reverse(2**31))
 */

#include <iostream>
#include <vector>

using namespace std;

int reverse_num(int num) {

    int rev_num = 0;
    int prev_rev_num = 0;
    bool neg = false;
    if (num < 0) {
        num = 0 - num;
        neg = true;
    }

    while(num > 0) {
        // do the bound check here...

        rev_num = rev_num*10 + num % 10;

        if((rev_num - (num % 10)) / 10 !=
            prev_rev_num) {

            cout << "WARNING OVERFLOW DETECTED!!!" << endl;
            return 0;
        }

        prev_rev_num = rev_num; // storing the this rev. value for next itneration

        num = num / 10;
    }

    if(neg) {
        rev_num = 0 - rev_num;
    }

    return rev_num;
}

int main() {

    cout << reverse_num(-123);
    cout << endl;
    cout << reverse_num(120);
    cout << endl;
    cout << reverse_num(1000000045);
    return 0;
}