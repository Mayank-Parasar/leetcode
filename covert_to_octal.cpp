//
// Created by Mayank Parasar on 2020-02-03.
//

#include<iostream>
#include<vector>

using namespace std;

vector<int> convert_to_octal(int num) {
    vector<int> octal;
    while(num != 0) {
        int res = num %8;
        octal.push_back(res);
        num = num/8;
    }
    return octal;
}

int main() {
    vector<int> octal_ = convert_to_octal(500);
    for(int ii = octal_.size()-1; ii>=0; ii--) {
        cout << octal_[ii];
    }
    return 0;
}
