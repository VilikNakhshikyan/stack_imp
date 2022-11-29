#include "include/stack.h"
#include <iostream>

int main()
{
    m_stack<int> a;
    a.push(12);
    a.push(21);
    std::cout << a.size() << std::endl;
    a.pop();
    std::cout << a.top() << std::endl;
    m_stack<int> b = a;
    std::cout << (a == b) << std::endl;
    a.pop();
    std::cout << a.empty() << std::endl;
    a.top();// size == 0 //Segmentation fault (core dumped)
}
