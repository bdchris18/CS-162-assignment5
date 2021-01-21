#include <iostream>
#include "linked_list.h"

Linked_List::Linked_List(){
    length = 0;
    head = NULL;
}

Linked_List::~Linked_List(){

}

int Linked_List::get_length(){
    return length;
}

void Linked_List::print(){
    Node* current = head;
    while(current != NULL){
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Linked_List::clear(){
    if(length = 0) return;
    Node* current = head;
    while(current != NULL){
        Node* temp = current->next;
        delete current;
        current = temp;
    }
    length = 0;
    head = NULL;
}

void Linked_List::push_front(int new_val){
    Node* new_node = new Node(new_val);
    Node* current = head;
    head = new_node;
    new_node->next = current;
    length++;
}

void Linked_List::push_back(int new_val){
    Node* new_node = new Node(new_val);
    Node* current = head;
    if(current == NULL){
        head = new_node;
        length++;
        return;
    }
    while(current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
    length++;
}

void Linked_List::insert(int new_val, unsigned int index){
    if(index > length) return;
    if(index == 0){
        push_front(new_val);
        return;
    }
    Node* new_node = new Node(new_val);
    Node* current = head;
    for(int i = 1; i < index; ++i){
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    length++;
}

void Linked_List::sort_ascending(){
    *this = merge_sort(*this);
}

Linked_List Linked_List::merge_sort(Linked_List new_list){
    Node* current = new_list.head;
    if(new_list.length == 0 || new_list.length == 1){
        return new_list;
    }
    if(new_list.length == 2){
        if(new_list.head->next->val < new_list.head->val){
            std::swap(new_list.head->val, new_list.head->next->val);
        }
        return new_list;
    }
    Linked_List l1;
    Linked_List l2;
    Node* new_current = new_list.head;
    for(int i = 0; i < new_list.length/2; ++i){
        l1.push_back(new_current->val);
        new_current = new_current->next;
    }
    for(int i = new_list.length/2; i < new_list.length; ++i){
        l2.push_back(new_current->val);
        new_current = new_current->next;
    }
    Linked_List new_l1;
    Linked_List new_l2;
    new_l1 = merge_sort(l1);
    new_l2 = merge_sort(l2);
    return merge(new_l1, new_l2);
}

Linked_List Linked_List::merge(Linked_List h1, Linked_List h2){
    Node* current1 = h1.head;
    Node* current2 = h2.head;
    Linked_List combined_list;
    while(current1 != NULL && current2 != NULL){
        if(current1->val > current2->val){
            combined_list.push_back(current2->val);
            current2 = current2->next;
        }
        else{
            combined_list.push_back(current1->val);
            current1 = current1->next;
        }
    }
    while(current1 != NULL){
        combined_list.push_back(current1->val);
        current1 = current1->next;
    }
    while(current2 != NULL){
        combined_list.push_back(current2->val);
        current2 = current2->next;
    }
    return combined_list;
}

Linked_List Linked_List::merge_sort2(Linked_List new_list){
    Node* current = new_list.head;
    if(new_list.length == 0 || new_list.length == 1){
        return new_list;
    }
    if(new_list.length == 2){
        if(new_list.head->val < new_list.head->next->val){
            std::swap(new_list.head->val, new_list.head->next->val);
        }
        return new_list;
    }
    Linked_List l1;
    Linked_List l2;
    Node* new_current = new_list.head;
    for(int i = 0; i < new_list.length/2; ++i){
        l1.push_back(new_current->val);
        new_current = new_current->next;
    }
    for(int i = new_list.length/2; i < new_list.length; ++i){
        l2.push_back(new_current->val);
        new_current = new_current->next;
    }
    Linked_List new_l1;
    Linked_List new_l2;
    new_l1 = merge_sort2(l1);
    new_l2 = merge_sort2(l2);
    return merge2(new_l1, new_l2);
}

Linked_List Linked_List::merge2(Linked_List h1, Linked_List h2){
    Node* current1 = h1.head;
    Node* current2 = h2.head;
    Linked_List combined_list;
    while(current1 != NULL && current2 != NULL){
        if(current1->val > current2->val){
            combined_list.push_back(current1->val);
            current1 = current1->next;
        }
        else{
            combined_list.push_back(current2->val);
            current2 = current2->next;
        }
    }
    while(current1 != NULL){
        combined_list.push_back(current1->val);
        current1 = current1->next;
    }
    while(current2 != NULL){
        combined_list.push_back(current2->val);
        current2 = current2->next;
    }
    return combined_list;
}

void Linked_List::sort_descending(){
    *this = merge_sort2(*this);
}

unsigned int Linked_List::count_prime(){
    Node* current = head;
    unsigned int num_primes = 0;
    bool prime = true;
    for (int i = 0; i < length; ++i){
        prime = true;
        for(int j = 2; j <= current->val/2; ++j){
            if(current->val%j == 0){
                prime = false;
                break;
            }
        }
        if(prime && current->val >= 2){
            num_primes++;
        }
        current = current->next;
    }
    return num_primes;
}