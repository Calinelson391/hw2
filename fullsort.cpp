#ifndef FULLSORT_CPP
#define FULLSORT_CPP

#include <iostream>

struct Node {
    int value;
    Node *next;
};


Node* fullsort(Node* in){
	Node temp;
	temp.next = in;
	if(in->next == NULL){
		return in;
	}
	if(in->value <= in->next->value){ //Must switch pointer if next is in prong place
		in->next = fullsort(in->next);
	}
	if(in->value > in->next->value){
		temp.next = in->next;
		in->next = in->next->next;
		temp.next->next = fullsort(in); 
	}
	return temp.next;
}

#endif

// int main(){ //REMOVE ONCE THIS WORKS FOR SURE! THIS IS FOR TESTING!!!!!!
// 	Node a, b, c, d, e;
// 	a.value = 2;
// 	b.value = 3;
// 	c.value = 1;
// 	d.value = 4;
// 	e.value = 5;
// 	a.next = &b;
// 	b.next = &c;
// 	c.next = &d;
// 	d.next = &e;
// 	e.next = NULL;

// 	fullsort(&a);
// 	std::cout << c.value << " " << c.next->value << " " << c.next->next->value << " " << c.next->next->next->value << " " << c.next->next->next->next->value << std::endl;
// 	return 1;
// }