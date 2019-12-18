//
// Created by Mayank Parasar on 2019-12-18.
//

/*
 * You are given a 2D array of characters, and a target string.
 * Return whether or not the word target word exists in the matrix. Unlike a standard word search,
 * the word must be either going left-to-right, or top-to-bottom in the matrix.
 * matrix = [
  ['F', 'A', 'C', 'I'],
  ['O', 'B', 'Q', 'P'],
  ['A', 'N', 'O', 'B'],
  ['M', 'A', 'S', 'S']]
print word_search(matrix, 'FOAM')
# True
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool match(vector<char>& word1, vector<char>& word2) {
    if(word1 == word2) {
        return true;
    }
    else {
        return false;
    }
}

bool word_search(vector<vector<char>>& mat, vector<char>& word) {
    bool found = false;
    // scan from left to right
    for(int row=0; row < mat.size(); row++) { // row-iterator
        for(int col=0; col <= (mat[row].size() - word.size()); col++ ) { // column iterator within that row
            vector<char>::iterator wrd1 = mat[row].begin() + col;
            vector<char> word1(wrd1, wrd1+word.size());
            if(match(word1, word))
                return true;
            else
                continue;
        }
    }
    // scan from top to down
    bool col_out_of_bound = false;
    for(int col = 0; !(col_out_of_bound); col++) {
        col_out_of_bound = true;
        for(int row=0; row <= (mat.size()-word.size()); row++) {
            if(col < mat[row].size()) {
                col_out_of_bound = false;
                // vector<char>::iterator itr1 = mat[row].begin() + col;
                // vector<char>::iterator itr2 = mat[row+word.size()-1].begin() + col;
                // form
                // vector<char> word1(itr1, itr2);
                // form your own vector here
                vector<char> word1;
                for(int rr = row; rr < row + word.size(); ++rr) {
                    word1.push_back(mat[rr][col]);
                }
                if(match(word1, word))
                    return true; // short circuit path
                else
                    continue;
            }
        }
    }
    return (found);
}

int main() {
    vector<vector<char>> matrix =  {
            {'F', 'A', 'A', 'M'},
            {'O', 'B', 'Q', 'P'},
            {'A', 'N', 'O', 'B'},
            {'M', 'A', 'S', 'S'}};

    for(int i=0; i<matrix.size(); ++i) {
        for(int k =0; k <matrix[i].size(); ++k) {
            cout << matrix[i][k] << " ";
        }
        cout << endl;
    }

    vector<char> word_ = {'F', 'O', 'A', 'M'};

    cout << (word_search(matrix, word_) ? "True" : "False") << endl;
    return 0;
}
