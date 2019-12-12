//
// Created by Mayank Parasar on 2019-12-12.
//


#include <iostream>
#include <string>
#include <vector>
using namespace std;


int num_valleys(int len, string& s) {
    int num_valleys = 0;
//    vector<int> num_zeros;
//    vector<char> sense;
    int altitude = 0;
    char sense_1 = '-';
    for(auto i: s ) {

        if(altitude > 0) {
            sense_1 = 'U';
        }
        else if(altitude < 0) {
            sense_1 = 'D';
        }
        // update altitude
        if (i == 'U') {
            altitude++;
        }
        else if (i == 'D') {
            altitude--;
        }

        if(altitude == 0) {
            if(sense_1 == 'D')
                num_valleys++;
        }

    }

    return num_valleys;
}

int main () {
    vector<int> a = {10,20,20,10,10,30,50,10,20};
    vector<int> b = {10, 10, 10, 10, 10};

    string s1 = "UDDDUDUU";
    string s2 = "DDUUUUDD";

    cout << num_valleys(s1.length(), s1);
    cout << endl;
    cout << num_valleys(s2.length(), s2);
    return 0;
}