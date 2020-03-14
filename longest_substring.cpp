/*
 * Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
#include <iostream>
#include <vector>
#include <string>


using namespace std;

/*helper function*/
vector<char> stringToVector(string str) {
    vector<char> result;

    for(auto i : str)
        result.push_back(i);

    return result;
}

vector<string> result_substrs;

void scan_vec(vector<int> vec) {
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        cout << *it << endl;
    }
}

int find_char_repeat(string str) {
    // this function finds the repeating char present
    // in the string with the end of the string char...
    // if there is none it returns -1 else the index of the repeated char
    char end_ = str[str.length() - 1];
    for(int ii = 0; ii < str.length() - 1; ii++) {
        if(str[ii] == end_)
            return (ii);
    }

    return (-1);
}

void scan_str(string str) {
    cout << str << endl;
    bool flag = false;
    for(int ii = 0; ii < (int)str.length();) {
        for(int jj = ii+1; jj <= (int)str.length(); jj++) {
            flag = true;
            if(find_char_repeat(str.substr(ii, jj-ii)) == -1) {
                result_substrs.push_back(str.substr(ii, jj-ii));
                // continue;
            }
            else {
                // cout << str.substr(ii, jj-ii) << endl;
                // cout << ii << " " << jj << endl;
                result_substrs.push_back(str.substr(ii, jj-ii-1));
                ii += find_char_repeat(str.substr(ii, jj-ii)) + 1;
                flag = false;
            }
        }
        if(flag)
            ii++;
    }
}



int main() {

    string str1 = "mayank parasar";

    vector<char> vec = stringToVector(str1);

    // for(auto i : vec)
    //   cout << "'"<< i << "'";

//    scan_str("abcabcbb");
    //scan_str("bbbbbbbb");
    scan_str("pwwkew");

    int max = -1;

    for(auto i : result_substrs) {
        if((int)i.length() > max) {
            max =  i.length();
        }
    }

    cout << "Maximum substring length-" << max << endl;


    return 0;
}