//
// Created by Mayank Parasar on 2019-12-17.
//

/*
 * You are given a 2D array of integers. Print out the clockwise spiral traversal of the matrix.
 *
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int>& clockwise_spiral(vector<vector<int>>& a, vector<int>& clockwise_sprial_1) {

    int i, k = 0, l = 0;

    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
    int m = a.size();
    int n = a[0].size();

    while (k < m && l < n) {
        /* Print the first row from
               the remaining rows */
        for (i = l; i < n; ++i) {
            // cout << a[k][i] << " ";
            clockwise_sprial_1.push_back(a[k][i]);
        }
        k++;

        /* Print the last column
         from the remaining columns */
        for (i = k; i < m; ++i) {
            // cout << a[i][n - 1] << " ";
            clockwise_sprial_1.push_back(a[i][n - 1]);
        }
        n--;

        /* Print the last row from
                the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                // cout << a[m - 1][i] << " ";
                clockwise_sprial_1.push_back(a[m - 1][i]);
            }
            m--;
        }

        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                // cout << a[i][l] << " ";
                clockwise_sprial_1.push_back(a[i][l]);
            }
            l++;
        }
    }

    return(clockwise_sprial_1);
}

int main() {
    // Initializing 2D vector "vect" with
    // values
    vector<vector<int> > vect{ { 1, 2, 3, 10 },
                               { 4, 5, 6, 11 },
                               { 7, 8, 9, 12 } };
    for(int i = 0; i < vect.size(); i++) {
        for(int k = 0; k < vect[i].size(); k++) {
            cout << vect[i][k] <<" ";
        }
        cout << endl;
    }
    vector<int> clockwise_spiral_1;
    clockwise_spiral(vect, clockwise_spiral_1);
    for(auto i: clockwise_spiral_1) {
        cout << i << " ";
    }
    return 0;
}