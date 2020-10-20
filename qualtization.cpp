//
// Created by Mayank Parasar on 2020-05-19.
//

/*
 * Write a function in pseudo-code (C/C++ style) that does fixed-point quantization
double apply_quantization(double input, int w, int f, bool qm, bool om ) {…}
- Assume input/output are all unsigned values;
w is the total number of bits, f is the number of fractional bits;
rm is the rounding mode, 0 for truncation, 1 for round. // LSB
om is the overflow mode, 0 for saturation, 1 for wrap-around. //MSB
You can find definitions of these quantization modes from online sources;
Examples:
apply_quantization(6.7, 3, 1, 0, 0) should return 3.5; 00.0 – 11.1
apply_quantization(6.7, 3, 1, 0, 1) should return 2.5; 6.5-> 1010110.1 = 10.1 -> 2.5
apply_quantization(2.8, 3, 1, 1, 0) should return 3.0; 2.8 -> 10.11…. (2.75) -> 11.0

 6.7 => 110.10...
 1101.01 => 1110 (rotuding)
        => 1101  (truncation)
 1101 > 111 => 111 (saturation)
 1101 =>101 (wrap around)


 * */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double apply_quantization(double input, int w, int f, bool rm, bool om ) {

    double intermediate_ = input * pow(2,f); // input<<f (left shift)

    if(rm == true) {
        intermediate_ = round(intermediate_);
    }
    else {
        intermediate_ = floor(intermediate_);
    }
    // after this step the intermediate is an integer
    // intermediate_ = (int)intermediate_;

    if(om == false) { //
        if(intermediate_ >= pow(2,w))
            intermediate_ = pow(2,w)-1;
    }
    else { // truncation
        intermediate_ = (int)intermediate_ & (int)(pow(2,w) -1); // bitwise AND
    }

    // convert back intermediate into double
    intermediate_ = (double)intermediate_ / pow(2,f); // intermediate>>f (right shift)

    return intermediate_;
}

int main() {

    // cout << apply_quantization(6.7, 3, 1, false, false);
    // cout << apply_quantization(6.7, 3, 1, false, true);
    cout << apply_quantization(2.8, 3, 1, true, false);

    return 0;
}