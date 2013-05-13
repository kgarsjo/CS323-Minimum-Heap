#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


/* ------------------------------------------------ //
	Priority Queue (Min Heap) Class - Implements 
		a serialized vector binary heap.
// ------------------------------------------------ */
template <class T>
class Heap {

public:
	Heap();		// Default Constructor
	~Heap();	// Destructor

	// Implementation-required Methods
	void insert(T n);		// Inserts an emelement n in the heap
	T extractMin();			// Extracts the min element from the heap
	
	// Support and Extraneous Methods
	void printHeap();			// Prints a heap text representation
	bool testHeapProperty();	// Tests the heap property for all elements
	void relationIntegrity();	// Tests parent/children values

private:
	void minHeapify(int index);	// Forces heap properties after changes
	int getParent(int i);		// Returns the parent of given index
	int getLeftChild(int i);	// Returns the left child of index
	int getRightChild(int i);	// Returns the right child of index
	void resizeArray();			// Resizes the internal array
	

	vector<T> elements;		// Implements the serialzed heap
	T* elem;
	int size;
	int capacity;
};


/* ------------------------------------------------ //
Heap() - Default Constructor
Time Comp: theta(1)
// ------------------------------------------------ */
template <class T>
Heap<T>::Heap() {
	size = 0;
	capacity = 10;
	elem = new T[capacity];
}


/* ------------------------------------------------ //
~Heap() - Destructor
Time Comp: theta(1)
// ------------------------------------------------ */
template <class T>
Heap<T>::~Heap() {

}


/* ------------------------------------------------ //
public void insert(...) - Inserts an element into
	the heap, and maintains the heap properties

Inputs:	T n - Element of template type T to insert

Time Comp: O(lg n)
// ------------------------------------------------ */
template <class T>
void Heap<T>::insert(T n) {
	int index = size;
	int parent = getParent(index);
	elem[size] = n;
	size++;
	
	while ( index > 0 && *elem[parent] > *elem[index] ) {
	
		// Swap index w/ parent
		T temp = elem[index];
		elem[index] = elem[parent];
		elem[parent] = temp;
		
		index = parent;
		parent = getParent(index);
	}
	
	if (size == capacity) {
		resizeArray();
	}
}

template <class T>
T Heap<T>::extractMin() {
	if (size == 0) {
		return NULL;
	}

	size = size - 1;

	T min = elem[0];
	elem[0] = elem[size];
	minHeapify(0);
	
	return min;
}


template <class T>
void Heap<T>::minHeapify(int index) {
	int left = getLeftChild(index);
	int right = getRightChild(index);
	
	// Implicit Case 1: Index is smallest
	int smallest = index;

	// Case 2: Left is valid, and is smallest
	if (left < size) {
		if ( *elem[left] < *elem[index] ) {
			smallest = left;
		}
	}
	
	// Case 3: Right is valid, and is smalest
	if (right < size ) {
		if ( *elem[right] <  *elem[smallest] ) {
			smallest = right;
		}
	}
	
	// Swap index and smallest
	if (smallest != index) {
		T temp = elem[index];
		elem[index] = elem[smallest];
		elem[smallest] = temp;
		minHeapify(smallest);
	}
}


template <class T>
int Heap<T>::getParent(int i) {
	return (i+1)/2 - 1;
}


template <class T>
int Heap<T>::getLeftChild(int i) {
	return 2*i + 1;
}


template <class T>
int Heap<T>::getRightChild(int i) {
	return 2*i + 2;
}


template <class T>
void Heap<T>::resizeArray() {
	T* temp = elem;
	elem = new T[2*capacity];
	for (int i = 0; i < size; i++) {
		elem[i] = temp[i];
	}
}


template <class T>
void Heap<T>::printHeap() {
	cout << "Heap Contents:" << endl;

	for (int i = 0; i < size; i++) {
		cout << i << "-index:[" << *elem[i] << "]" << endl;
	}
	cout << endl;
}


template <class T>
bool Heap<T>::testHeapProperty() {
	bool result = true;
	
	for (int i = 1; i < size && result; i++) {
		int parent = getParent(i);
		result = ( *elem[i] >= *elem[parent] );
		if (!result) {
			cout << "Index " << i << " !>= index " << parent << endl;
		}
	}
	
	return result;
}

template <class T>
void Heap<T>::relationIntegrity() {
	for(int i = 1; i < size; i++) {
		cout << "Index " << i << ":" << endl;
		cout << "\tParent: " << i/2 << endl;
		cout << "\tLeftChild: " << 2*i << endl;
		cout << "\tRightChild: " << 2*i + 1 << endl;
		cout << endl;
	}
}

#endif
