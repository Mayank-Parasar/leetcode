//
// Created by m.parasar on 11/11/2020.
//

#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int>* vec_ptr;
    vector<vector<int>>* mat_ptr;
    vector<vector<int>*>* vec_ptr_ptr;
    // created storage for 10 elements,
    // by default have value '0' using
    // new
    vec_ptr = new vector<int>(10);
    for (int i = 0; i < vec_ptr->size(); ++i) {
        vec_ptr->at(i) = i;
    }

    // print out the vector:
    for(auto i : *vec_ptr)
        cout << i << endl;
    cout << "---------------------------------" << endl;

    // allocate memory to matrix 3x3
    mat_ptr = new std::vector<std::vector<int>>((3), vector<int>(3));
    // assign value to each memory location
    for (int row_id = 0; row_id < mat_ptr->size(); ++row_id) {

        for (int col_id = 0; col_id < mat_ptr->at(row_id).size(); ++col_id) {
            (mat_ptr->at(row_id)).at(col_id) = row_id + col_id;
        }
    }
    for(auto i : *mat_ptr) {
        for(auto k : i) {
            cout << k << " ";
        }
        cout << endl;
    }

    vec_ptr_ptr = new vector<vector<int>*>(3);
    for (int i = 0; i < vec_ptr_ptr->size(); ++i) {
        vec_ptr_ptr->at(i) = new vector<int>(3);
    }
    cout << "---------------------------------" << endl;
    // assigning values to 'vec_ptr_ptr'
    for (int row_id = 0; row_id < vec_ptr_ptr->size(); ++row_id) {
        for (int col_id = 0; col_id < vec_ptr_ptr->at(row_id)->size(); ++col_id) {
            vec_ptr_ptr->at(row_id)->at(col_id) = row_id + col_id;
        }
    }

    for(auto i : *vec_ptr_ptr) {
        for(auto k : *i) {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}
