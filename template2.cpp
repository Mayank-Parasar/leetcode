//
// Created by Mayank Parasar on 2019-09-15.
//

#include <iostream>
using namespace std;

template<class T, class U>
class A  {
    T x;
    U y;
public:
    A() {   cout<< "constructor Called" << endl; }
};

int main(int argc, char const *argv[]) {
	/* code */
	A<char, char> a;
	A<int, double> b;
	return 0;
}