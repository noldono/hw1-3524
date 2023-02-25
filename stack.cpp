#include "stack.hpp"

void Stack::push(double num) {
    m_data.push_back(num);
}

void Stack::pop() {
    m_data.pop_back();
}

double Stack::top() {
    return m_data.back();
}

std::size_t Stack::size() {
    return m_data.size();
}