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
    minIntHeap(int=10, int=0); // must declare ctor inside class..

    int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
    int getRightChildIndex(int parentIndex) { return 2 * parentIndex+ 2; }
    int getParentIndex(int childIndex) { return (childIndex - 1)/ 2;}

    bool hasLeftChild(int index) { return getLeftChildIndex(index) < size; }
    bool hasRightChild(int index) { return getRightChildIndex(index) < size; }
    bool hasParent(int index) { return getParentIndex(index) >= 0; }

    int leftChild(int index) { return items[index]; }
    int rightChild(int index) { return items[index]; }
    int parent(int index) { return items[index]; }

    void heapifyUp();
    void heapifyDown();

    int pop();
    void add(int item);
    void swap(int, int);

    void print();

private:
    int capacity;
    int size;
    vector<int> items;
};

// ctor
minIntHeap::minIntHeap(int cap, int s) {
    capacity = cap;
    size = s;
    items.resize(cap);
}

void
minIntHeap::print() {

    for(auto i : items)
        cout << i << " ";
    cout << endl;
}

int
minIntHeap::pop() {
    int item = items[0];
    items[0] = items[size - 1];
    size--;

    heapifyDown();
    return item;
}

void
minIntHeap::add(int item) {
    items[size] = item;
    size++;
    heapifyUp();
}

void
minIntHeap::swap(int index1, int index2) {
    swap(items[index1], items[index2]);
    return;
}

void
minIntHeap::heapifyUp() {
    int index = size - 1;
    while(hasParent(index) && parent(index) > items[index]) {
        swap(getParentIndex(index), index);
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

    minIntHeap heap(10, 0);

    heap.add(10);
    heap.add(15);
    heap.add(20);
    heap.add(17);
    heap.add(8);

    heap.print();

    return 0;
}