#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"

class Linked_List {
private:
    unsigned int length; // the number of nodes contained in the list
    Node* head; // a pointer to the first node in the list
    // anything else you need...
public:
    Linked_List();
    ~Linked_List();
    int get_length();
    // note: there is no set_length(unsigned int) (the reasoning should be intuitive)

    void print(); // output a list of all integers contained within the list
    void clear(); // delete the entire list (remove all nodes and reset length to 0)

    void push_front(int); // insert a new value at the front of the list 
    void push_back(int); // insert a new value at the back of the list 
    void insert(int val, unsigned int index); // insert a new value in the list at the specified index 

    void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
    Linked_List merge_sort(Linked_List new_head);
    Linked_List merge(Linked_List h1, Linked_List h2);
    Linked_List merge_sort2(Linked_List new_head);
    Linked_List merge2(Linked_List h1, Linked_List h2);
    // Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
    void sort_descending(); // sort the nodes in descending order

    unsigned int count_prime(); //count and return the number of prime numbers within the list

    // you can add extra member variables or functions as desired

};
#endif