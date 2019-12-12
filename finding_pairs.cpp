//
// Created by Mayank Parasar on 2019-12-12.
//

#include <iostream>

#include <vector>
using namespace std;

using namespace std;

int num_pairs(int size, vector<int>& vec) {
    int num_pairs = 0;
    vector<int>::iterator ptr;
    ptr = vec.begin();
    while(ptr != vec.end()) {
        // define another iterator 'ptr2' and loop through the end
        vector<int>::iterator ptr2;
        for( ptr2 = ptr+1; ptr2 < vec.end(); ptr2++) {
            if (*ptr == *ptr2) {
                num_pairs++;
                // remove both of these elements
                if(ptr == vec.end())
                    vec.pop_back();
                else
                    vec.erase(ptr); // when you erase ptr autoomatically points to the next element

                if(ptr2 == vec.end())
                    vec.pop_back();
                else
                    vec.erase(ptr2);

                // reset ptr to point to the next element
                // ptr++;
                // break
                break;
            }
        }
        // if the control comes here that there was no matching element.
        // reset ptr to point to the next element
        if (ptr2 == vec.end()) {
            ptr++;
            if (ptr == vec.end())
                break;
        }
    }

    return num_pairs;
}

int main () {
    vector<int> a = {10,20,20,10,10,30,50,10,20};
    vector<int> b = {10, 10, 10, 10, 10};

    cout << num_pairs(a.size(), a);
    cout << endl;
    cout << num_pairs(b.size(), b);
    return 0;
}