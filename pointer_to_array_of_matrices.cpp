//
// Created by Mayank Parasar on 11/9/20.
//

/* Given by user input
 * create multiple matrices
 * with values; of dimension given by user
 * For example:
 * ./leetcode <num-matrix> <dim-of-mat-0> <dim-of-mat-1> <dim-of-mat-2> ...
 * This will print matrices:
 * Matrix-0: <dim-of-mat-0> X <dim-of-mat-0>
 * Matrix-1: <dim-of-mat-1> X <dim-of-mat-1>
 * Matrix-2: <dim-of-mat-2> X <dim-of-mat-2>.. and so on..
 * Example:
 * ./leetcode 3 2 3 5 will produce following output
 * -----------------------------------------------------
    Printing the Matrices..
    Number of Matrices populated: 3
    Printing Matrix: 0
    2 2
    2 2
    Printing Matrix: 1
    3 3 3
    3 3 3
    3 3 3
    Printing Matrix: 2
    5 5 5 5 5
    5 5 5 5 5
    5 5 5 5 5
    5 5 5 5 5
    5 5 5 5 5
* -----------------------------------------------------
 * */

#include <iostream>
#include <vector>

std::vector<std::vector<std::vector<int>>*> mat_ptr;

int main(int argc, char* argv[]) {

    // mat_ptr = new vector<vector<int>>(atoi(argv[1]));
    for(int mat_id = 2; mat_id < argc; mat_id++)
    {
        std::vector<std::vector<int>>* tmp;
        tmp = new std::vector<std::vector<int>> (atoi(argv[mat_id]),
                std::vector<int> (atoi(argv[mat_id]), atoi(argv[mat_id])));

        mat_ptr.push_back(tmp);
    }

    std::cout << "Printing the Matrices.." << std::endl;
    std::cout << "Number of Matrices populated: " << mat_ptr.size() <<
    std::endl;
    for (int mat_id = 0; mat_id < mat_ptr.size(); ++mat_id) {
        std::cout << "Printing Matrix: " << mat_id << std::endl;
        for(auto i : *mat_ptr[mat_id]) {
            for(auto k : i) {
                std::cout << k << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}