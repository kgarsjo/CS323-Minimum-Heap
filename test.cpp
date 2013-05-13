#include "Heap.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>

void insertTest(int numTests) {
	srand( time(NULL) );
	bool result = true;
	
	cout << setw(4);
	cout << "###################################\n"
		 << "\tINSERT TESTS:\n"
		 << "###################################\n"
		 << endl;
		 
	for (int i = 0; i < numTests; i++) {
		Heap<int*> h;
	
		int sizeInputs = rand() % 5 + 6;
		for (int j = 0; j < sizeInputs; j++) {
			int* r = new int( rand() % 100 + 1 );
			h.insert(r);
			//h.printHeap();
			//cout << endl;
		}
		
		result = h.testHeapProperty();
		if (!result) {
			cout << "ERROR in case " << (i+1) << endl;
			h.printHeap();
			break;
		}
	}
	if (result) {
		cout << "::: ALL TESTS PASSED :::" << endl;
	}
	cout << endl <<endl;
	cout << setw(0);
}


void extractTest(int numTests) {
	srand( time(NULL) );
	bool result = true;
	
	cout << setw(4);
	cout << "###################################\n"
		 << "\tEXTRACT TESTS\n"
		 << "###################################\n"
		 << endl;
	
	for (int i = 0; i < numTests && result; i++) {
		Heap<int*> h;
		cout << setw(8);
		
		int sizeInputs = rand() % 10 + 1;
		for (int j = 0; j < sizeInputs; j++) {
			int* r = new int( rand() % 100 + 1 );
			h.insert(r);
		}
		
		for (int j = 0; j < sizeInputs; j++) {
			h.extractMin();
			result = h.testHeapProperty();
			
			if (!result) {
				cout << "ERROR in case " << (i+1) << endl;
				h.printHeap();
				break;
			}
		}
		
	}
	cout << setw(4);
	
	if (result) {
		cout << "::: ALL TESTS PASSED :::" << endl;
	}
	cout << endl << endl;
	cout << setw(0);
}


void priorityQueueTest(int numTests) {
	cout << "###################################\n"
		 << "\tPriority Queue Tests\n"
		 << "###################################\n"
		 << endl;
		 
	bool result = true;
		 
	for (int i = 0; i < numTests; i++) {
		 
		Heap<int*> h;
		 
		int sizeInputs = rand() % 10 + 1;
		int* heapsort = new int[sizeInputs];
	
		for (int j = 0; j < sizeInputs; j++) {
			int* r = new int( rand() % 100 + 1 );
			h.insert(r);
		}
		
		for (int j = 0; j < sizeInputs; j++) {
			heapsort[j] = *(h.extractMin());
		}
		
		for (int j = 1; j < sizeInputs; j++) {
			result = heapsort[j] >= heapsort[j-1];
		}
		
		if (!result) {
			cout << "ERROR in case " << (i+1) << endl;
			h.printHeap();
			break;
		}
	}
	
	if (result) {
		cout << "::: ALL TESTS PASSED :::" << endl;
	}
	cout << endl << endl;
}

	
int main() {
	Heap<int> h;
	insertTest(10000);
	extractTest(10000);
	priorityQueueTest(10000);

	return 0;
}
