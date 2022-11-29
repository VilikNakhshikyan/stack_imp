#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <stdexcept>

template <typename T>
class m_stack
{
public:
    m_stack();
    m_stack(const m_stack &);
    m_stack(m_stack &&);
    ~m_stack();

public:
    m_stack &operator=(const m_stack &);
    m_stack &operator=(m_stack &&);
    bool operator==(const m_stack &);

public:
    void push(const T &);
    void pop();
    unsigned int size();
    bool empty();
    T& top();

private:
    unsigned int m_size;
    unsigned int m_capacity;
    T *m_arr_s;
};

template <typename T>
m_stack<T>::m_stack() : m_size{0}, m_capacity{0}, m_arr_s{nullptr} {}

template <typename T>
m_stack<T>::m_stack(const m_stack &other) : m_size{other.m_size}, m_capacity{other.m_capacity}
{
    m_arr_s = new T[m_capacity];
    for (unsigned int i = 0; i < m_size; ++i)
        m_arr_s[i] = other.m_arr_s[i];
}
template <typename T>
m_stack<T>::m_stack(m_stack &&other) : m_size{other.m_size}, m_capacity{other.m_capacity}
{
    m_arr_s = other.m_arr_s;
    other.m_arr_s = nullptr;
}

template <typename T>
m_stack<T>::~m_stack()
{
    delete[] m_arr_s;
    m_arr_s = nullptr;
}

template <typename T>
m_stack<T> &m_stack<T>::operator=(const m_stack &other)
{
    if (this != &other)
    {
        delete[] m_arr_s;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_arr_s = new T[m_capacity];
        for (unsigned int i = 0; i < m_size; ++i)
            m_arr_s[i] = other.m_arr_s[i];
    }
    return *this;
}
template <typename T>
m_stack<T> &m_stack<T>::operator=(m_stack &&other)
{
    if (this != &other)
    {
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_arr_s = other.m_arr_s;
        other.m_arr_s = nullptr;
    }
    return *this;
}

template <typename T>
bool m_stack<T>::operator==(const m_stack &other)
{
    if (this == &other)
        return true;
    if (m_size != other.m_size)
        return false;
    for (unsigned int i = 0; i < m_size; ++i)
        if (m_arr_s[i] != other.m_arr_s[i])
            return false;
    return true;
}

template <typename T>
T& m_stack<T>::top()
{
    if(m_size != 0)
    {
        return m_arr_s[m_size-1];
    }
    else
    {
          throw std::runtime_error("Segmentation fault (core dumped)");  
    }
}

template <typename T>
void m_stack<T>::push(const T &item)
{
    if (m_size == m_capacity)
    {
        m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
        T *temp = new T[m_capacity];
        for (unsigned int i = 0; i < m_size; ++i)
            temp[i] = m_arr_s[i];
        delete[] m_arr_s;
        m_arr_s = temp;
    }
    m_arr_s[m_size] = item;
    ++m_size;
}
template <typename T>
void m_stack<T>::pop()
{
    if (m_size != 0)
        --m_size;
}

template <typename T>
unsigned int m_stack<T>::size()
{
    return m_size;
}

template <typename T>
bool m_stack<T>::empty()
{
    return m_size == 0 ? true : false;
}

#endif //_VECTOR_H_