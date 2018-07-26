// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#ifndef StacticArray_H
#define StacticArray_H

template <class V, int CAP>
class StaticArray
{
  V values[CAP];
  V dummy;
  
public:
  StaticArray(); // constructor
  int capacity() const{return CAP;}
  V& operator[](int);
  V operator[](int) const;
};

template <class V, int CAP>
StaticArray<V, CAP>::StaticArray()
{
  for (int i = 0; i < CAP; i++)
    values[i] = V();
}

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
