#include "Heap.h"
#include "Node.h"
#include <map>

int main() {
	map<char,int> m;
	map<char,int>::iterator iter;
	Heap<Node*> h;
	
	char c;
	do {
		c = cin.get();
		m[c] = m[c] + 1;
		
	} while (c != '.');
	m.erase('.');
	
	for (iter = m.begin(); iter != m.end(); iter++) {
		char key = iter->first;
		int value = iter->second;
		h.insert(new Node(key, value));
		h.printHeap();
	}
	
	return 0;
}