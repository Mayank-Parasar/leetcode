//
// Created by Mayank Parasar on 2020-03-25.
//

/*
Given a 32 bit integer, reverse the bits and return that number.

Example:
Input: 1234
# In bits this would be 0000 0000 0000 0000 0000 0100 1101 0010
Output: 1260388352
# Reversed bits is 0100 1011 0010 0000 0000 0000 0000 0000
*/

#include <iostream>
#include <deque>

using namespace std;

deque<int> int_to_binary(int num) {
    deque<int> result;
    // push the remainder from front.
    while(num > 0) {
        result.push_front(num %2);
        num = num / 2;
    }
    // to make the number 32 bit wide pad it with 0s
    for(int ii = result.size(); ii < 32; ii++)
        result.push_front(0);

    return result;
}

deque<int> reverse_bits (const deque<int> num) {
    deque<int> result;
    for(auto i : num) {
        result.push_front(i);
    }

    return result;
}

int binary_to_int(const deque<int> binary_num) {

    int num = 0;
    int k = 31;
    for(auto i : binary_num) {

        // cout << i << endl;
        num = num + (i << k);
        // cout << "num: " << num << endl;
        k--;
    }
    // cout << "k: " << k << endl;
    return num;
}

int main() {
    int num = 1234;
    cout << "Integer number is: " << num << endl;
    deque<int>binary_rep = int_to_binary(num);

    // for(auto i : binary_rep)
    // 	cout << i;

    // cout << endl;
    cout << "reversed binary form of the number is: ";

    deque<int>binary_rev = reverse_bits(binary_rep);

    for(auto i : binary_rev)
        cout << i;
    cout << endl;

    cout << "Integer for the equivalent reversed binary number is: ";
    cout << binary_to_int(binary_rev);


    return 0;
}