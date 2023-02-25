#ifndef STACK_H
#define STACK_H

#include <vector>

class Stack {

public:
    void push(double num);
    void pop();
    double top();
    std::size_t size();
private:
    std::vector<double> m_data;
    
};

#endif