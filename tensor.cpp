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

    void print_tensor();

    vector<int> size;
    int total_space;
    double * tensor_;

};

void
tensor::create_tensor(vector<int> size) {
    int total_size = 1;

    for(auto i : size) {
        total_size *= i;
    }
    total_space = total_size;
    // allocate memory for the tensor
    // and put it in the member variable tensor
    tensor_ = (double*) malloc(sizeof(double)*total_size);

    return;
}

void
tensor::initialize_tensor(double arr[]) {

    for(int ii=0; ii < total_space ; ii++) {
        tensor_[ii] = arr[ii];
    }
}

void
tensor::print_tensor() {

    for(int ii=0; ii < total_space ; ii++) {
        cout << tensor_[ii] << " ";
    }
}

int main() {

    tensor * t = new tensor();

    t->size = {10, 4, 5};
    t->create_tensor(t->size);

    // iniitalize tensor
    double arr[t->total_space];

    for(int ii=0; ii < t->total_space; ii++) {
        arr[ii] = 1.25;
    }

//    for(int ii=0; ii < t->total_space; ii++) {
//        cout << arr[ii] << " ";
//    }

    t->initialize_tensor(arr);

    t->print_tensor();


    delete t;


    return 0;
}