//
// Created by Mayank Parasar on 2020-03-14.
//

// print all the permulation ofo the the array using backtracking

#include <iostream>
#include <string>

using namespace std;

void print_permutation_string(string str, int strt, int end) {

    if( strt == end - 1) {
        cout << str << endl;
    }
    else {

        for(int ii = strt; ii < end; ii++) {

            swap(str[strt], str[ii]);
            print_permutation_string(str, strt+1, end);
            // swap back
            swap(str[ii], str[strt]);
        }

    }

}

void print_permutation_arry(int arr[], int strt, int end, int size) {

    if( strt == end - 1) {
        for(int i=0; i < size; i++)
            cout << arr[i];
        cout << endl;
    }
    else {

        for(int ii = strt; ii < end; ii++) {

            swap(arr[strt], arr[ii]);
            print_permutation_arry(arr, strt+1, end, size);
            // swap back
            swap(arr[ii], arr[strt]);
        }

    }

}

int main() {
    string str = "abc";
    cout << "String permutation: " << endl;
    print_permutation_string(str, 0, (int)str.length());
    cout << endl;
    int arr[4] = {1, 2, 3, 4};
    cout << "Numeral permutation: " << endl;

    print_permutation_arry(arr, 0, 4, 4);
    return 0;
}