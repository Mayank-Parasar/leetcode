//
// Created by Mayank Parasar on 2020-05-09.
//
/*
 * Given two strings which represent non-negative integers,
 * multiply the two numbers and return the product as a string as well.
 * You should assume that the numbers may be sufficiently large such that the built-in integer
 * type will not be able to store the input (Python does have BigNum, but assume it does not exist).

Here's an example and some starter code.

def multiply(str1, str2):
  # Fill this in.

print(multiply("11", "13"))
# 143*/

#include <iostream>
#include <string>

using namespace std;

string string_num_mult(string num1, string num2) {

    int len_1 = num1.length();
    int len_2 = num2.length();

    string final_result(len_1+len_2+1, '0');

    // reverse both nums
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    // use 2 nested for loops to string multiply
    for(int i = 0; i < len_1; i++) { // num1
        for(int j = 0; j < len_2; j++) { // num2
            int tmp = (final_result[i+j] - '0') + (num1[i] - '0') * (num2[j] - '0');

            final_result[i+j] = '0' + tmp % 10;
            final_result[i+j+1] += tmp / 10;

        }
    }
    // remove leading zeros
    for(int i = len_1+len_2; i > 0 && final_result[i] == '0'; i--)
        final_result.pop_back();

    // reverse
    reverse(final_result.begin(), final_result.end());

    return final_result;
}

int main() {

    string num1 = "11";
    string num2 = "13";

    string num3 = "1235421415454545454545454544";
    string num4 = "1714546546546545454544548544544545";

    string result = string_num_mult(num3, num4);

    cout << result;

    return 0;
}