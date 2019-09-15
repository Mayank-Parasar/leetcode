//
// Created by Mayank Parasar on 2019-09-14.
//

// Function templates

// One function works for all data types. This would work
// even for user defined types if operator '>' is overloaded

#include <iostream>

using namespace std;
////////////////////// Function Templates ////////////////////////
template <typename T>
T myMax(T x, T y) {
    return (x > y) ? x : y;
}

// template function to implement bubble sort.
// We can use this for any data type that supports
// comparision operator < and swap works for it
template <typename T>
void bubbleSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a [j-1])
                swap(a[j], a[j - 1]);
}
////////////////////// Class Template ////////////////////////

template <typename T>
class Array
{
private:
    T * ptr;
    int size;
public:
    Array(T arr[], int s);
    void print ();
};

template <typename T>
Array<T>::Array(T arr[], int s) {
    ptr = new T[s];
    size = s;

    for(int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template <typename T>
void Array<T>::print() {
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}

int main () {
    cout << myMax<int> (3, 7) << endl;   // Call myMax for int
    cout << myMax<double> (3.0, 7.0) << endl;   // call myMax for double
    cout << myMax<char> ('g', 'e') << endl;     // call myMax for char

    int a[5] = {10, 50, 30, 40, 10};
    int n = sizeof(a) / sizeof(a[0]);

    // calls template function
    bubbleSort(a, 5);

    cout << "Sorted array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    int arr[5] = { 1, 2, 3, 4,5};
    Array<int> b (arr, 5);
    b.print();


    return 0;
}