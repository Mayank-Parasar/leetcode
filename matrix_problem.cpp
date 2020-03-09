//
// Created by Mayank Parasar on 2020-03-09.
//

/*Simple kernel to add matrix*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

    vector<vector<int>> mat = {{1, 2, 3, 4, 5},
                               {2, 3, 4, 5, 6},
                               {3, 4, 5, 6, 7},
                               {4, 5, 6, 7, 8}};

    for(int ii =0; ii < mat.size(); ii++) {  // loop running through rows
        for(int jj = 0; jj < mat[ii].size(); jj++) { // loop running through cols
            cout << mat[ii][jj] << " ";
        }
        cout << endl;
    }

    // sum the diagonal
    int sum = 0;

    for(int ii =0; ii < mat.size(); ii++) {  // loop running through rows
        for(int jj = 0; jj < mat[ii].size(); jj++) { // loop running through cols
            if(ii == jj)
                sum += mat[ii][jj];
        }
        // cout << endl;
    }
    cout << "sum: " << sum << endl;

    // transpose
    vector<vector<int>> mat_tr;
    int rows = mat.size();
    int cols = mat[0].size();
    // get the stride.
    // for(int rw)
    vector<int> row;
    for(int c = 0; c < cols; c++) {
        for(int r = 0; r < rows; r++) {
            // cout << mat[r][c] << " ";
            row.push_back(mat[r][c]);
        }
        mat_tr.push_back(row);
        row.clear();
        cout << endl;
    }

    for(int ii =0; ii < mat_tr.size(); ii++) {  // loop running through rows
        for(int jj = 0; jj < mat_tr[ii].size(); jj++) { // loop running through cols
            cout << mat[ii][jj] << " ";
        }
        cout << endl;
    }


    return 0;
}