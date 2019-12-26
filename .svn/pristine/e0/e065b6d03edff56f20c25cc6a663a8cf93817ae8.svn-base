#ifndef CS2_STACK_HPP_
#define CS2_STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer: Paweena Manotipya
// Updated:    10/2019
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//

#include <new>
#include <cassert>
#include <iostream>

////////////////////////////////////////////////////////////////////////////
// Node       
template<typename T> 
class Node {
public:
    // Node data
    Node<T> * next;
    T val;
    // Constructors    
    Node() { next = 0; }
    Node(const T& v, Node<T> * n) { val = v; next = n; }
    Node(const T& v) { val = v; next = 0; }

};


////////////////////////////////////////////////////////////////////////////
// Stack
template<typename T>
class stack {
public:
                stack       ();
                stack       (const stack<T>&);
                ~stack      ();
    void        swap        (stack<T>&);
    stack<T>&   operator=   (stack<T>);
    bool        empty       () const;
    bool        full        () const;
    T           top         () const;
    T           pop         ();
    void        push        (const T&);
        
    // Additional functions
    int         length      () const;
    bool        operator==  (const stack<T>&) const;
    bool        operator!=  (const stack<T>& rhs) const { return !(*this == rhs); };
    void        print       () const;
private:
    Node<T> *   tos;
};

// Default constructor
template<typename T>
stack<T>::stack() 
{
    tos = nullptr;
}

// Copy constructor
template<typename T>
stack<T>::stack(const stack<T>& actual)
{
    tos = nullptr;    

    if (actual.empty()) {
        tos = nullptr;
    } else {
        Node<T> *ptr = actual.tos;
        Node<T> *temp = new Node<T>(ptr->val);
        tos = temp;
        Node<T> *tail = temp;
        
        while (ptr->next != nullptr) {
            ptr = ptr->next;
            temp = new Node<T>(ptr->val);
            tail->next = temp;
            tail = temp;
        }
    }
}

// Destructor
template<typename T>
stack<T>::~stack()
{
    while (!empty()) {
        Node<T> * temp = tos;
        tos = tos->next;
        delete temp;
    }
}

// Swap stack data
template<typename T>
void stack<T>::swap(stack<T>& rhs)
{
    Node<T> * temp = tos;
    tos = rhs.tos;
    rhs.tos = temp;
}

// Overloading assignment operator
template<typename T>
stack<T>& stack<T>::operator=(stack<T> rhs)
{
    swap(rhs);
    return *this;
}

// Check stack was empty
template<typename T>
bool stack<T>::empty() const
{
    return tos == nullptr;
}

// Check stack was full
template<typename T>
bool stack<T>::full() const
{
    Node<T> *temp = new (std::nothrow) Node<T>();
    if (!temp) return true;
    else delete temp;
    return false;
}

// Top: Get top of the stack
template<typename T>
T stack<T>::top() const
{
    assert(!empty());
    return tos->val;
}

// Pop item out of the stack
template<typename T>
T stack<T>::pop()
{
    assert(!empty());
    T result = top();
    Node<T> * temp = tos;
    tos = tos->next;
    delete temp;
    return result;   
}

// Push item to the stack
template<typename T>
void stack<T>::push(const T& item)
{
    assert(!full());
    Node<T> * temp = new Node<T>(item, tos);
    tos = temp;
}

// Get length of the stack
template<typename T>
int stack<T>::length() const
{
    int len = 0;
    
    Node<T> * tmp = tos;    
    while (tmp != 0) {
        ++len;
        tmp = tmp->next;
    }

   return len;
}

// Overloading equal operator
template<typename T>
bool stack<T>::operator==(const stack<T>& rhs) const
{
   if ( length() != rhs.length()) { return false; }
   
   Node<T>  * right = rhs.tos;
   Node<T>  * left = tos;
   while (left != 0 && right !=  0) {
        if (left->val != right->val)  return false;
        left  = left->next;
        right = right->next;
   } 

   return true;
}

// Print all items in the stack
template<typename T>
void stack<T>::print() const
{
    for (Node<T> * n = tos; n != nullptr; n = n->next) {
        std::cout << n->val << " ";
    }
    std::cout << std::endl;
}

#endif

