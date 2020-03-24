/*
Given an expression (as a list) in reverse polish notation, evaluate the expression.
Reverse polish notation is where the numbers come before the operand.
Note that there can be the 4 operands '+', '-', '*', '/'. You can also assume the expression will be well formed.

Example
Input: [1, 2, 3, '+', 2, '*', '-']
Output: -9
The equivalent expression of the above reverse polish notation would be (1 - ((2 + 3) * 2)).

*/

#include <iostream>
#include <stack>
#include <deque>

using namespace std;

int evaluate_expression_deque(deque<char> expression_deque) {

    stack<int> result;
    for(deque<char>::iterator it = expression_deque.begin();
        it != expression_deque.end(); it++) {
        if(*it == '+') {
            int a = result.top();
            result.pop();
            int b = result.top();
            result.pop();
            result.push(b + a);
        }
        else if(*it == '-') {
            int a = result.top();
            result.pop();
            int b = result.top();
            result.pop();
            result.push(b - a);
        }
        else if(*it == '*') {
            int a = result.top();
            result.pop();
            int b = result.top();
            result.pop();
            result.push(b * a);
        }
        else {
            result.push(*it - '0');
        }

    }

    return (result.top());
}


int main() {
    deque<char> expression_deque = {'1', '2', '3', '+', '2', '*', '-'};

// 	for(auto i : expression_deque)
// 		cout << i << " ";

// 	cout << endl;

// 	for(deque<char>::iterator it = expression_deque.begin();
// 			it != expression_deque.end(); it++) {
// 		cout << *it << " ";
// 	}

    cout << endl;

    cout << evaluate_expression_deque(expression_deque);

    return 0;
}