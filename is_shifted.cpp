//
// Created by Mayank Parasar on 2020-02-15.
//

/*
You are given two strings, A and B. Return whether A can be shifted some number of times to get B.

Eg. A = abcde, B = cdeab should return true because A can be shifted 3 times to the right to get B. A = abc and B= acb should return false.
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool is_shifted(string stra, string strb) {

    if(stra.length() != strb.length())
        return false;

    int i;

    for(i = 0; i < strb.length(); i++) {
        if(strb[i] == stra[0])
            break;
    }
    // start from 'i' and reconstruct the word
    // then match if it is same as stra.

    int k = 0;
    while(k != stra.length()) {
        if(stra[k] == strb[i]) {
            k++;
            i++;
            // check the loop over here...
            if(i == strb.length())
                i = 0;
        }
        else {
            return false;
        }
    }

    // if control comes here then it should be matched
    return true;


}

int main() {

//    string stra = "abcde";
//    string strb = "cdeab";
    string stra = "abc";
    string strb = "acb";

    cout << boolalpha;
    cout << is_shifted(stra, strb);

    return 0;
}