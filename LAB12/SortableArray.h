// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#ifndef SortableArray_H
#define SortableArray_H

#include <algorithm>

template <typename V>
class SortableArray
{
  int cap;
  V* values;
  V dummy;
  
public:
  ~SortableArray(){delete[] values;} // destructor
  SortableArray(int = 2); // main constructor
  SortableArray(const SortableArray<V>&); // copy constructor
  SortableArray<V>& operator=(const SortableArray<V>&); // assignment operator
  int capacity() const{return cap;}  // capacity getter
  void capacity(int); // auto-sizing function
  V& operator[](int); // setter operator
  V operator[](int) const; // getter operator
  void sort(int);
};

template <typename V>
SortableArray<V>::SortableArray(int cap)
{
  this->cap = cap;
  values = new V[cap];
} // main constructor

template <typename V>
SortableArray<V>::SortableArray(const SortableArray<V>& original)
{
  cap = original.cap;
  values = new V[cap];
  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
} // copy constructor

template <typename V>
SortableArray<V>& SortableArray<V>::operator=(const SortableArray<V>& original)
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
void SortableArray<V>::capacity(int cap)
{
  if (cap == this->cap || cap < 0)
    return;
  V* temp = new V[cap];
  int limit = min(cap, this->cap);
  for (int i = 0; i < limit; i++)
    temp[i] = values[i];
  delete [] values;
  values = temp;
  this->cap = cap;
} // auto-sizing function

template <typename V>
V& SortableArray<V>::operator[](int index)
{
  if (index < 0)
    return dummy;
  if (index >= cap)
    capacity(2 * index);
  return values[index];
} // setter operator

template <typename V>
V SortableArray<V>::operator[](int index) const
{
  if (index < 0 || index >= cap)
    return dummy;
  return values[index];
} // getter operator

template <class V>
void SortableArray<V>::sort(int n) // Merge Sort
{
  int size = min(n, cap) ;
  V* temp = new V[size];
  for (int delta = 1; delta < size; delta *= 2)
  {
    int index = 0;
    for (int i = 0; i < size; i++) temp[i] = values[i]; 
    for (int i = 0; i < size; i += 2 * delta)
    {
      int left = i;
      int leftMax = min(left + delta, size);
      int right = leftMax;
      int rightMax = min(right + delta, size);       
      while (true)
      {
        if (left == leftMax && right == rightMax) break;
        if (left == leftMax) values[index++] = temp[right++];
        else if (right == rightMax) values[index++] = temp[left++];
        else if (temp[right] < temp[left]) values[index++] = temp[right++];
        else values[index++] = temp[left++];
      }
    }
  }
  delete [] temp;
}

#endif
