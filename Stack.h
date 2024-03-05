#pragma once
#include <vector>
using namespace std;

class Stack{
private:
    vector<int> data;
public:
    bool EmptyOrNo();
    void push(int value);
    void pop();
    int top();
    double average();
};