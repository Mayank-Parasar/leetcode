//
// Created by Mayank Parasar on 2019-12-17.
//

/*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of
 * the non-zero elements.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> put_all_zero_at_end(vector<int> vect) {
    // vector<int> vec;
    vector<int>::iterator itr;

    int orignal_size = vect.size();
    for(int i = 0; i < vect.size(); i++) {
        if(vect[i] == 0) {
            // erase the element
            itr = vect.begin() + i;
            vect.erase(itr);
        }
    }
    // do the post processing to add '0's at the end of the vector
    int num_zeros = orignal_size - vect.size();
    for(int i = 0; i < num_zeros; i++) {
        vect.push_back(0);
    };
    return(vect);
}

int main() {
    vector<int> vec = {0,1,0,3,12, 0};
    vector<int> vec2 = put_all_zero_at_end(vec);
    for(auto i: vec2)
        cout << i << " ";
    cout << endl;
    return 0;
}