// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#ifndef PriorityQueue_H
#define PriorityQueue_H

#include <algorithm>

template <typename V>
class PriorityQueue
{
  V* values;
  int siz;
  int cap;
  void capacity(int);

public:
  ~PriorityQueue() {delete[] values;} // destructor
  PriorityQueue(int = 2); // main constructor
  PriorityQueue(const PriorityQueue<V>&); // copy constructor
  PriorityQueue<V>& operator=(const PriorityQueue<V>&); // assignment operator
  void pop();
  void clear() {siz = 0;}  
  void push(const V&);
  bool empty() const {return (siz == 0) ? true : false;}
  int size() const{return siz;}
  const V& top() const{return values[0];}
};

template <typename V>
void PriorityQueue<V>::capacity(int cap)
{
  if(cap == this->cap || cap < 0 )
    return;
  V* temp = new V[cap];
  int limit = (this->cap > cap) ? cap: this->cap;
  for(int i = 0; i < limit; i++)
    temp[i] = values[i];
  delete[] values;
  values = temp;
  this->cap = cap;
}

template <typename V>
PriorityQueue<V>::PriorityQueue(int cap)
{
  this->cap = cap;
  values = new V[cap];
  siz = 0;
} // main constructor

template <typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& original)
{
  this->siz = original.siz;
  this->cap = original.cap;
  values = new V[cap];
  for(int i = 0; i < original.siz; i++)
    this->values[i] = original.values[i];
} // copy constructor

template <typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& original)
{
  if (this != &original)
  {
    this->siz = original.siz;
    this->cap = original.cap;
    delete[] values;
    values = new V[cap];
    for(int i = 0; i < original.siz; i++)
      this->values[i] = original.values[i];
  }
  return *this;
} // assignment operator

template <typename V>
void PriorityQueue<V>::push(const V& value)
{
  if(siz == cap)
    capacity(cap * 2);
  values[siz] = value;
  int index = siz;
  while((index-1)/2 >= 0)
  {
    if(values[(index-1)/2] < values[index])
    {
      swap(values[index], values[(index-1)/2]);
      index = (index-1)/2;
    }
    else
      break;
  }
  siz++;
}

template <typename V>
void PriorityQueue<V>::pop()
{
  int index = 0;
  int left, right;

  if(siz == 0)
    return;

  while(true)
  {
    left = 2 * index + 1;
    right = 2 * index + 2;

    if(left >= siz)
      break;
    if(right < siz)
    {
      if(values[right] < values[left] || (!(values[right]<values[left])&&!(values[left]<values[right])))
      {
        values[index] = values[left];
        index = left;
      }
      else
      {
        values[index] = values[right];
        index = right;
      }
    }
    else
    {
      values[index] = values[left];
      index = left;
    }
  }
  siz--;
  values[index] = values[siz];
  int parent;
  while(true)
  {
    parent = (index-1)/2;
    if(parent < 0)
      break;
    if(values[index] < values[parent] || (!(values[index] < values[parent])&&!(values[parent] < values[index])))
      break;
    swap(values[index], values[parent]);
    index = parent;
  }
}

#endif
