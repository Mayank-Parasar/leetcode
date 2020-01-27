//
// Created by Mayank Parasar on 2020-01-23.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7},
                                  {8, 9, 10},
                                  {11, 12, 13, 14, 15}};

    // print the matrix in a row format.

    for(int ii=0; ii < matrix.size(); ii++) {
        cout << "Row: " << ii << "\t";
        for(int kk=0; kk < matrix[ii].size(); kk++) {
            cout << matrix[ii][kk]  << " ";
        }
        cout << endl;
    }

    return 0;
}