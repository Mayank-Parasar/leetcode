//
// Created by Mayank Parasar on 2020-03-09.
//


//#include<iostream>
//using namespace std;
//
//int main() {
//
//    int *ptr = new int(sizeof(int) * 200);
//
//    for(int ii = 0; ii < 200; ii++) {
//        *(ptr+ii) = (ii);
//    }
//
//    for(int ii = 0; ii < 200; ii++) {
//        cout << *(ptr+ii) << " ";
//    }
//    return 0;
//}

/*
 *   try
  {
    int* myarray= new int[1000];
  }
  catch (exception& e)
  {
    cout << "Standard exception: " << e.what() << endl;
  }*/

#include<iostream>
//#include<new>
using namespace std;

int main() {
    double *ptr;
    try {
        ptr =  (double*) malloc(sizeof(double) * 200);
//        ptr =  new double(sizeof(double) * 5);
    }
    catch(exception& e) {
        cout << "Standard exception: " << e.what() << endl;
    }
    for(int ii = 0; ii < 200; ii++) {
        *(ptr+ii) = (1.25);
        // cout << *(ptr+ii) << endl;
    }

    for(int ii = 0; ii < 200; ii++) {
        cout << *(ptr+ii) << " ";
    }

//    double arr[200];
//    for(int ii = 0; ii < 200; ii++) {
//        arr[ii] = (1.25);
//    }
//
//    for(int ii = 0; ii < 200; ii++) {
//        cout << *(arr+ii) << " ";
//    }

    return 0;
}
