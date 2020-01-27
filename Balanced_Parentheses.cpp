//
// Created by Mayank Parasar on 2020-01-26.
//
/*
 * The Balanced Parentheses Problem - Classic Stack Problem ("Valid Parentheses" on Leetcode)
 * */

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>

using namespace std;
stack<char> round_bracket;
stack<char> curly_bracket;
stack<char> square_bracket;

bool balanced_parentheses(string str) {

    for(auto i : str) {
        // cout << i << " ";
        if(i == '[') {
            square_bracket.push(i);
        } else if(i == '{') {
            curly_bracket.push(i);
        } else if(i == '(') {
            round_bracket.push(i);
        }
        // Make sure before poping is size is 0; if yes, then return false right away
        else if(i == ']') {
            if(square_bracket.size() > 0)
                square_bracket.pop();
            else
                return false;
        }
        else if(i == '}') {
            if(curly_bracket.size() > 0)
                curly_bracket.pop();
            else
                return false;
        }
        else if(i == ')') {
            if(round_bracket.size() > 0)
                round_bracket.pop();
            else
                return false;
        }
    }

    // check here the size of stacks; if any of them is greater than 0 then return false
    if( round_bracket.size() == 0 &&
        curly_bracket.size() == 0 &&
        square_bracket.size() == 0 ) {
        return true;
    }
    else {
        return false;
    }


    // return true;

}

int main() {

    string str = "[({()})[]}";
    string str1 = "[{()}]";
    cout << boolalpha;
    cout << balanced_parentheses(str1);

    return 0;
}
