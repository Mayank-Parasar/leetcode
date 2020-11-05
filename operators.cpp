//
// Created by Mayank Parasar on 11/4/20.
//

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

class complex_numbers {
private:
    double r;
    double img;
public:
    complex_numbers(double real = 0.0, double imag = 0.0)
    : r(real), img(imag)
    {}

    double operator()();
    complex_numbers operator*(complex_numbers& c) {
        complex_numbers ret_val(this->r*c.r - this->img*c.img, this->r*c.img + this->img*c.r);
        return (ret_val);
    };

    /* ostream operators are special that ways...
     * They are not associated with a particular class
     * I can define this operator outside the 'complex_number' class*/
    friend ostream &operator<<(ostream &os, const complex_numbers &numbers) {
        os << "r: " << numbers.r << " img: " << numbers.img;
        return os;
    }
};

double complex_numbers::operator()() {
    return (sqrt(r*r + img*img));
}
int main() {
    complex_numbers* comp1 = new complex_numbers(2.0, -1);
    complex_numbers c1(3.0);
    cout << "comp1->operator()(): " << comp1->operator()() << endl;
    cout << "c1.operator()(): " << c1.operator()() << endl;
    cout << c1 << endl;
    cout << *comp1 << endl;
    cout << c1*(*comp1); // this will use operator* and ostream operator
    return 0;
}