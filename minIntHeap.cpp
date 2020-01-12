//
// Created by Mayank Parasar on 2020-01-11.
//

/*
 * This contains the implemenation of min-Heap data structure
 * */

#include <iostream>
#include <vector>

using namespace std;

class minIntHeap {
public:
    // minIntHeap(); // default
    // minIntHeap(int=10, int=0); // must declare ctor inside class..

    int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
    int getRightChildIndex(int parentIndex) { return 2 * parentIndex+ 2; }
    int getParentIndex(int childIndex) { return (childIndex - 1)/ 2;}

    bool hasLeftChild(int index) { return getLeftChildIndex(index) < items.size(); }
    bool hasRightChild(int index) { return getRightChildIndex(index) < items.size(); }
    bool hasParent(int index) { return getParentIndex(index) >= 0; }

    int leftChild(int index) { return items[index]; }
    int rightChild(int index) { return items[index]; }
    int parent(int index) { return items[index]; }

    void heapifyUp();
    void heapifyDown();

    int pop();
    void add(int item);
    // void swap(int, int);

    void print();

private:
    // int capacity;
    // int size;
    vector<int> items;
};

// ctor
//minIntHeap::minIntHeap(int cap, int s) {
//    // capacity = cap;
//    // size = s;
//    items.resize(cap);
//}

void
minIntHeap::print() {

    for(auto i : items)
        cout << i << " ";
    cout << endl;
}

int
minIntHeap::pop() {
    int item = items[0];

//    items[0] = items[size - 1];
//    size--;
    items[0] = items.back();
    items.pop_back();

    heapifyDown();
    return item;
}

void
minIntHeap::add(int item) {
    // items[size] = item;
    // size++;
    items.push_back(item);
    heapifyUp();
}

//void
//minIntHeap::swap(int index1, int index2) {
//    swap(items[index1], items[index2]);
//    return;
//}

void
minIntHeap::heapifyUp() {
    int index = items.size() - 1;
    while(hasParent(index) && parent(index) > items[index]) {
        swap(items[getParentIndex(index)], items[index]);
        index = getParentIndex(index);
    }
}

void
minIntHeap::heapifyDown() {
    int index = 0;
    while(hasLeftChild(index)) {
        int smallerChildIndex = getLeftChildIndex(index);
        if(hasRightChild(index) &&
                (rightChild(index) < leftChild(index))) {
            smallerChildIndex = getRightChildIndex(index);
        }

        if(items[index] < items[smallerChildIndex]) {
            break;
        } else {
            swap(index, smallerChildIndex);
        }
        index = smallerChildIndex;
    }
}

int main() {

    minIntHeap heap;

    heap.add(10);
    heap.add(15);
    heap.add(20);
    heap.add(17);
    heap.add(8);

    heap.print();

    return 0;
}