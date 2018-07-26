// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#ifndef StaticArray_H
#define StaticArray_H

template <class V, int CAP>
class StaticArray
{
  V values[CAP];
  V dummy;
  
public:
  int capacity() const{return CAP;}
  V& operator[](int);
  V operator[](int) const;
};

template <class V, int CAP>
V& StaticArray<V, CAP>::operator[](int index)
{
  if (index < 0 || index >= CAP)
    return dummy;
  return values[index];
}

template <class V, int CAP>
V StaticArray<V, CAP>::operator[](int index) const
{
  if (index < 0 || index >= CAP)
    return dummy;
  return values[index];
}

#endif
