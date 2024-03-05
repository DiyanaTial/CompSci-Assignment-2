#include "SinglyLinked.h"

#include "Node.h"
#include <iostream>
using namespace std;

//default constructor
template <typename T>
SinglyLinked<T>::SinglyLinked():head(nullptr), tail(nullptr), num_items(0){}

//destructor
template<typename T>
SinglyLinked<T>::~SinglyLinked(){
    Node<T>* current = head;
    while (current != nullptr){
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

//push_front function
template<typename T>
void SinglyLinked<T>::push_front(const T& item){
    Node<T>* newNode = new Node<T>(item);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr){
        tail = head;
    }
    num_items++;
}

//push_back function
template<typename T>
void SinglyLinked<T>::push_back(const T& item){
    Node<T>* newNode = new Node<T>(item);
    if (tail == nullptr){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
    num_items++;
}

//pop_front function
template<typename T>
void SinglyLinked<T>::pop_front(){
    if (head == nullptr){
        return;
    }
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr){
        tail = nullptr;
    }
    null_items--;
}

//pop_back function
template<typename T>
void SinglyLinked<T>::pop_back(){
    if (tail == nullptr){
        return;
    }
    if (head == tail){
        delete head;
        head = tail = nullptr;
        num_items--;
        return;
    }
    Node<T>* current = head;
    while (current->next != tail){
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
    num_items--;
}

//front function
template<typename T>
T SinglyLinked<T>::front(){
    // empty list error handling
    if (head == nullptr){
        throw out_of_range("List is empty");
    }
    // return just data from head
    return head->data;
}

//back function get last value 
template<typename T>
T SinglyLinked<T>::back(){
    // empty list error handling
    if (tail == nullptr){
        throw out_of_range("List is empty");
    }
    //return tail 
    return tail->data;
}

// empty function
template<typename T>
bool SinglyLinked<T>::empty(){
    return nun_items = 0;
}

//insert item function
template<typename T>
void SinglyLinked<T>::insert(int index, const T& item){
    if (index == 0){
        push_front(item);
    }
    else if (index >= num_items){
        push_back(item);
    }
    else{
        Node<T>* current = head;
        for (size_t i = 0; i < index - 1; ++i){
            current = current->next;
        }
        Node<T>* newNode = new Node<T> (item);
        newNode->next = current->next;
        current->next = newNode;
        num_items++;
    }
}

// Remove the item at the specified index function
template<typename T>
bool SinglyLinked<T>::remove(int index) {
    if (index >= num_items) {
        return false;
    }

    if (index == 0) {
        pop_front();
    } else {
        Node<T>* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node<T>* temp = current->next;
        current->next = temp->next;
        delete temp;
        num_items--;
    }
    return true;
}

// find function
template<typename T>
int SinglyLinked<T>::find(const T& item) {
    size_t index = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;
}