//
// Created by Mayank Parasar on 2020-02-16.
//

/*
 * You are given a string s, and an integer k. Return the length of the longest substring in s that contains
 * at most k distinct characters.

For instance, given the string:
aabcdefff and k = 3, then the longest substring with 3 distinct characters would be defff. The answer should be 5.

 */

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int distinct_chars(deque<char> a) {
    int cnt= 0;
    vector<char> v;
    for(auto i : a) {
        if(find(v.begin(), v.end(), i) != v.end()) { // char is present
            // push the element anyway
            v.push_back(i);
            // don't inc the cnt
        }
        else {  // char is present
            v.push_back(i);
            cnt++;
        }
    }

    return cnt;
}

int longest_substring(string a, int k) {
    deque<char> window;
    vector<int> size; // this contain the number of characters that window has
                        // with 'k' distinct characters
    int curr_distinct_char = 0;
    // scan over the string and populate the window
    for(int ii=0; ii < a.length(); ii++) {
//        if(window.size() < k) {
//            window.push_back(a[ii]);
//
//        }
//        else {

            // at this point distinct char in the deque is less than equal to 'k-1'
            // it is safe to push the element into the window
            window.push_back(a[ii]);

            // loop to check if there are 'k' distinct elements in the window
            while(distinct_chars(window) == k+1) {
                // remove element from the front.
                window.pop_front();
            }

            // log the size of window if there are k distinct char in the deque
            if(distinct_chars(window) == k)
                size.push_back(int(window.size()));

//        }
    }

    // at this point the size is populated with differnt lengths of window containing distinct k elements
    int max = -1;

    for(auto i : size)
        if(i > max)
            max = i;

    return max;
}

int main() {

    string a = "aabcdefff";
    int k = 3;

    string a_ = "aabc";

    deque<char> deque_a;
    for(auto i : a_)
        deque_a.push_back(i);
    
    cout << "distinct characters in the passed string: " << distinct_chars(deque_a);
    cout << endl;
    
    cout << "longest length of substring with k distinct characters: "  << longest_substring(a, k);

    return 0;
}