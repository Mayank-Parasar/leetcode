//
// Created by Mayank Parasar on 2020-01-31.
//

/*
 * Given a list of numbers of size n, where n is greater than 3,
 * find the maximum and minimum of the list using less than 2 * (n - 1) comparisons.
 * def find_min_max(nums):
  # Fill this in.

print find_min_max([3, 5, 1, 2, 4, 8])
# (1, 8)
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> find_min_max(vector<int>& arr) {
    int num_comparisions = 0;
    int min = arr[0];
    int max = arr[0];

    for(int ii = 0; ii < arr.size(); ii++) {
        if(arr[ii] > max) {
            max = arr[ii];
            num_comparisions++;
        }
        else if(arr[ii] < min) {
            min = arr[ii];
            num_comparisions++;
        }
    }

    cout << num_comparisions;

    vector<int> min_max;
    min_max.push_back(min);
    min_max.push_back(max);

    return min_max;
}

int main() {

    vector<int> arr = {3, 5, 1, 2, 4, 8};

    vector<int> min_max = find_min_max(arr);
    cout << endl;
    cout << "min: " << min_max[0] << endl;
    cout << "max: " << min_max[1] << endl;

    return 0;
}