//
// Created by Mayank Parasar on 2020-05-19.
//

/*
 *  y[n] = sum_m ( h(m) * x[n-m] ) ;   // m=0:M-1, n = 0:N-1
        Write a C++ function, FIRfilter(), defined as below :
          Input :  int14_t  x[N];            // #define N 64
           Filter  : int16_t  h[M];          // #define M 10
          Output :  int16_t  y[N];

 * */


#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> sum_m (vector<int> h, vector<int> x) {
    vector<int> y;
    deque<int> delay_line(0, 3);
//    delay_line(3, 0);
    // convolution
//    int k = 5>>3;
    for(int n = 0; n < x.size(); n++) { // y 'n'
        int sum= 0;
        for (int m = 0; m < h.size(); m++) { // h 'm'
            if(n - m < 0) {
                delay_line[n-m+3];
            }
            else {
                sum += h[m]*x[n-m]; // valid input
                delay_line.push_back(x[n-m]);
            }
        }
        cout << sum << endl;
        y.push_back(sum);
    }

    return y;
}

int main() {
    // m = 3
    vector<int> h = {1, 2, 1};
    vector<int> x = {1, 2, 3, 4, 5, 4, 3, 2, 1, 0};

    sum_m(h,x);

    return 0;
}