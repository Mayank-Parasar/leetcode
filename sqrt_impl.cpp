//
// Created by Mayank Parasar on 2020-04-20.
//

/*
 * square-root implementation without using sqrt function
 * */

#include <iostream>

using namespace std;

int main() {
    int number = 7;
    float temp, sqrt;

    // store the half of the given number
    sqrt = number / 2;
    temp = 0;
    // Iterate until sqrt is different of temp, that is updated in the loop
    while(sqrt != temp) {
        temp = sqrt;

        sqrt = (number/temp + temp) / 2;
    }

    cout << "The square root of the number: " << number << " is: " << sqrt << endl;

    return 0;
}