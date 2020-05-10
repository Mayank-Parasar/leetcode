//
// Created by Mayank Parasar on 2020-05-09.
//

/*
 * Given a number n, find the least number of squares needed to sum up to the number.

Here's an example and some starting code:

def square_sum(n):
  # Fill this in.

print(square_sum(13))
# Min sum is 3^2 + 2^2
# 2
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> square_sum(int num, vector<int>& nums_sq) {

    if (num == 0) {
        return nums_sq;
    }
    for(int ii = 1; ii <= num/2 + 1; ii++) {
        if(num > ii*ii) {
            continue;
        }
        else if(num == ii* ii) {
            nums_sq.push_back(ii);
            return (square_sum((num - ii*ii), nums_sq));
        }
        else {
            nums_sq.push_back(--ii);
            return (square_sum((num - ii*ii), nums_sq));
        }
    }

    return nums_sq;

}

int main() {

    vector<int> result;
    int num = 103;

    result = square_sum(num, result);

//    for(auto i : result)
//        cout << i << " ";

    cout << "Min. sum of squares: " << result.size() << endl;

    return 0;
}