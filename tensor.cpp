//
// Created by Mayank Parasar on 2020-03-09.
//


/* tensor dim are (10, 4, 5) */
#include <iostream>
#include <vector>


using namespace std;

class tensor {
public:
    ~tensor() {
        cout << endl << "Call to the destructor " << endl;
        delete tensor_;
    }
    void create_tensor(vector<int> size);
    void initialize_tensor(double arr[]);

    void multiply_row_tensor(vector<double> row);
    void print_tensor();

    vector<int> size;
    int total_elem;
    double * tensor_;

};

void
tensor::create_tensor(vector<int> size) {
    int total_size = 1;

    for(auto i : size) {
        total_size *= i;
    }
    total_elem = total_size;
    // allocate memory for the tensor
    // and put it in the member variable tensor
    tensor_ = (double*) malloc(sizeof(double)*total_size);

    return;
}

void
tensor::initialize_tensor(double arr[]) {

    for(int ii=0; ii < total_elem ; ii++) {
        tensor_[ii] = arr[ii];
    }
}

void
tensor::multiply_row_tensor(vector<double> row) {
    int num_mult = 0;
    for(int ii = 0; ii < total_elem; ii += row.size()) {
        for(int jj = 0; jj < row.size(); jj++) {
            tensor_[ii+jj] *= row[jj];
        }
        num_mult++;
    }
    cout << endl << "num multiplications: " << num_mult << endl;
}

void
tensor::print_tensor() {

    for(int ii=0; ii < total_elem ; ii++) {
        cout << tensor_[ii] << " ";
    }
}

int main() {

    tensor * t = new tensor();

    t->size = {10, 4, 5};
    t->create_tensor(t->size);

    // iniitalize tensor
    double arr[t->total_elem];

    for(int ii=0; ii < t->total_elem; ii++) {
        arr[ii] = 1.25;
    }

//    for(int ii=0; ii < t->total_space; ii++) {
//        cout << arr[ii] << " ";
//    }

    t->initialize_tensor(arr);

    t->print_tensor();

    vector<double> row(10, (double)2.0);
    t->multiply_row_tensor(row);
    cout << endl;

    t->print_tensor();

    delete t;


    return 0;
}