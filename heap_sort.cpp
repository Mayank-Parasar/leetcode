//
// Created by Mayank Parasar on 2020-01-12.
//

/*This program does the heap sorting using max heap data-structure*/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) : val(x), left(nullptr), right(nullptr)
    {}
};

void populate_tree(Node* node_) {

}

void heapify(vector<int>& arr, int n, int i ) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    // if left child is larget than root
    if(l < n && arr[l] > arr[largest])
        largest = l;

    // if right child is larger
    if(r < n && arr[r] > arr[largest])
        largest = r;

     if (largest != i) {
         swap(arr[i], arr[largest]);

         // Recursively heapify the affected sub-tree
         heapify(arr, n, largest);
     }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    // buid the heap
    for(int i = n / 2 - 1; i >=0; i--)
        heapify(arr, n, i);

    // one by one extract an element from heap
    for (int i = n-1; i >=0; i--) {
        // move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {

    vector<int> arr = {22, 17, 19, 12, 15, 11, 7, 6, 9, 10, 5};

    cout << "unsorted array" << endl;

    for(auto i : arr)
        cout << i << " ";

    cout << endl;

    heapSort(arr);

    cout << "sorted array" << endl;

    for(auto i : arr)
        cout << i << " ";

    return 0;
}