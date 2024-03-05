#pragma once


//template
template<typename T>

class SinglyLinked{
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    SinglyLinked();
    ~SinglyLinked();

    void push_front(const T& item);
    void push_back(const T& item);
    void pop_front();
    void pop_back();
    T front();
    T back();
    bool empty();
    void insert(int index, const T& item);
    bool remove(int index);
    int find(const T& item);
};