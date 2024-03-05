#include "Stack.h"

bool Stack::EmptyOrNo(){
    return data.empty();
}

void Stack::push(int value){
    data.push_back(value);
}

void Stack::pop(){
    if(!EmptyOrNo()){
        data.pop_back();
    }
}

int Stack::top(){
    if(!EmptyOrNo()){
        return data.back();
    }
    // error handle
    return -1;
}

double Stack::average(){
    int i;
    if(EmptyOrNo()){
        return 0.0;
    }
    double sum = 0.0;
    for (i = 0; i < data.size(); ++i){
        sum += data.at(i);
    }
    return sum / data.size();
}