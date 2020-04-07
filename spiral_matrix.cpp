//
// Created by Mayank Parasar on 2020-04-06.
//

/*

Given a matrix of m x n elements (m rows, n columns), return all elements of the
 matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Input:
[
  [1,   2,  3],
  [4,   5,  6],
  [7,   8,  9],
  [10,  11, 12]
]
Output: [1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8]

*/
#include <iostream>
#include <vector>

using namespace std;

void spiral_traversal(vector<vector<int>>& mat) {
  int start_row = 0;
  int start_col = 0;
  int end_row = mat.size()-1;
  int end_col = mat[0].size()-1;

  while(start_col <= end_col &&
        start_row <= end_row) {

    for(int ii = start_col; ii <= end_col; ii++) {
      cout << mat[start_row][ii] << " ";
    }

    start_row++;
    for(int ii = start_row; ii <= end_row; ii++) {
      cout << mat[ii][end_col] << " ";
    }

    end_col--;
    if(start_col < end_col &&
        start_row < end_row) {
      for(int ii = end_col; ii >= start_col; ii--) {
        cout << mat[end_row][ii] << " ";
      }

      end_row--;

      for(int ii = end_row; ii >= start_row; ii--) {
        cout << mat[ii][start_col] << " ";
      }

      start_col++;
    }

  }

}

int main() {
    vector<vector<int>> matrix;
    matrix = {{1, 2, 3},
              {4, 5, 6},
              {7, 8, 9}};

    vector<vector<int>> matrix2;
    matrix2 = { {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9,10,11,12}};

    vector<vector<int>> matrix3;
    matrix3 = { {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9},
                {10, 11, 12}};

    for(auto i : matrix3) {
    for(auto k : i) {
      cout << k << "\t";
    }
    cout << endl;
    }

    spiral_traversal(matrix3);
    return 0;
}