// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#ifndef DynamicArray_H
#define DynamicArray_H

#include <algorithm>

template <typename V>
class DynamicArray
{
  int cap;
  V* values;
  V dummy;
  
public:
  ~DynamicArray(){delete[] values;} // destructor
  DynamicArray(int = 2); // main constructor
  DynamicArray(const DynamicArray<V>&); // copy constructor
  DynamicArray<V>& operator=(const DynamicArray<V>&); // assignment operator
  int capacity() const{return cap;}  // capacity getter
  void capacity(int); // auto-sizing function
  V& operator[](int); // setter operator
  V operator[](int) const; // getter operator
};

template <typename V>
DynamicArray<V>::DynamicArray(int cap)
{
  this->cap = cap;
  values = new V[cap];
} // main constructor

template <typename V>
DynamicArray<V>::DynamicArray(const DynamicArray<V>& original)
{
  cap = original.cap;
  values = new V[cap];
  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
} // copy constructor

template <typename V>
DynamicArray<V>& DynamicArray<V>::operator=(const DynamicArray<V>& original)
{
  if (this != &original)
  {
    delete[] values;
    cap = original.cap;
    values = new V[cap];
    for (int i = 0; i < cap; i++)
      values[i] = original.values[i];
  }
  return *this;
} // assignment operator

template <typename V>
void DynamicArray<V>::capacity(int cap)
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
V& DynamicArray<V>::operator[](int index)
{
  if (index < 0)
    return dummy;
  if (index >= cap)
    capacity(2 * index);
  return values[index];
} // setter operator

template <typename V>
V DynamicArray<V>::operator[](int index) const
{
  if (index < 0 || index >= cap)
    return dummy;
  return values[index];
} // getter operator

#endif
