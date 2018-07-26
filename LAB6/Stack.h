// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#ifndef Stack_H
#define Stack_H

#include <algorithm>

template <typename V>
class Stack
{
  V* values;
  int cap;
  int siz;
  void capacity(int); // auto-sizing function
  
public:
  ~Stack(){delete[] values;} // destructor
  Stack(int = 1); // main constructor
  Stack(const Stack<V>&); // copy constructor
  Stack<V>& operator=(const Stack<V>&); // assignment operator
  void pop() {if (siz > 0) --siz;}
  void clear() {siz = 0;}  
  void push(const V&);
  V& peek();
  bool empty() const {return (siz == 0) ? true : false;}
  int size() const;
};

template <typename V>
Stack<V>::Stack(int cap)
{
  this->cap = cap;
  values = new V[cap];
  siz = 0;
} // main constructor

template <typename V>
Stack<V>::Stack(const Stack<V>& original)
{
  cap = original.cap;
  values = new V[cap];
  siz = original.siz;
  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
} // copy constructor

template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)
{
  if (this != &original)
  {
    delete[] values;
    cap = original.cap;
    values = new V[cap];
    siz = original.siz;
    for (int i = 0; i < cap; i++)
      values[i] = original.values[i];
  }
  return *this;
} // assignment operator

template <typename V>
void Stack<V>::capacity(int cap)
{
  V* temp = new V[cap];
  int limit = min(cap, this->cap);
  for (int i = 0; i < limit; i++)
    temp[i] = values[i];
  for (int i = limit; i < cap; i++)
    temp[i] = V();
  delete [] values;
  values = temp;
  this->cap = cap;
} // auto-sizing function

template <typename V>
void Stack<V>::push(const V& value)
{
  if (siz == cap) capacity(2 * cap); // double the capacity if full
  values[siz] = value;
  ++siz;
}

template <typename V>
V& Stack<V>::peek()
{
  if (siz - 1 < 0)
    return values[0];
  else
    return values[siz - 1];
}

template <typename V>
int Stack<V>::size() const
{
  int size = siz;
  return size;
}

#endif
