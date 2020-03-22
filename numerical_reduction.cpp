//
// Created by Mayank Parasar on 2020-03-20.
//
/*
Code for reducing a numberr to a single digit
175 =  5+7 => 12 => 1+2 = 3 + 1 => 4
9999 = 9+9 =>9 + 9 => 9 =>9+9 = 9
*/

#include <iostream>
#include <vector>

using namespace std;

/* helper function */
vector<int> vectorize (int num) {
    vector<int> result;

    while(num >0) {
        result.push_back(num % 10);
        num = num / 10;
    }

    return result;
}


int reduce(int num) {
    vector<int> result = vectorize(num);
    int sum = 0;
    for(auto i : result) {
        sum += i;
        if(sum > 9) {
            sum = reduce(sum);
        }
    }

    return sum;
}

int main() {

    // vector<int> vec = vectorize(175);

    // for(auto i : vec) {
    // 	cout << i << " ";
    // }
    cout << endl;
    int reduced_sum = reduce(175);
    cout << "result after reducing the number: " << reduced_sum << endl;
    cout << endl;
    reduced_sum = reduce(9999);
    cout << "result after reducing the number: " << reduced_sum << endl;

    cout << endl;
    reduced_sum = reduce(526004760);
    cout << "result after reducing the number: " << reduced_sum << endl;

    cout << endl;
    reduced_sum = reduce(689697);
    cout << "result after reducing the number: " << reduced_sum << endl;

    return 0;
}
