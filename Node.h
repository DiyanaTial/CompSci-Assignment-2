#pragma once

// template
template<typename T>
class Node{
public:
    T data;
    Node* next;

    Node(const T& value);
};

template<typename T>
Node<T>::Node(const T& value) : data(value), next(nullptr){}