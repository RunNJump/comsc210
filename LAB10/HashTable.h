// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#ifndef HashTable_H
#define HashTable_H
#include <list>
#include <queue>

template <class K, class V, const int CAP>
class HashTable
{
  struct Node
  {
    K key;
    V value;
  };
  list<Node> data[CAP];
  int(*hashCode)(const K&);
  int siz;

  public:
    HashTable(int(*)(const K&) = 0); // main constructor
    V& operator[](const K&); // setter operator
    V operator[](const K&) const; // getter operator
    int size() const {return siz;} // size
    void clear(); // clear
    bool containsKey(const K&) const; // check containing key
    void deleteKey(const K&); // delete element with key
    queue<K> keys() const; // return queue(key)
 };

template <class K, class V, const int CAP>
HashTable<K,V,CAP>::HashTable(int(*hashCode)(const K&))
{
  this->hashCode = hashCode;
  siz = 0;
} // main constructor
      
template<class K, class V, const int CAP>
V& HashTable<K,V,CAP>::operator[](const K& key)
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
    if (it->key == key)
      return it->value;

  Node temp;
  temp.key = key;
  temp.value = V();
  data[index].push_back(temp);
  ++siz;
  return data[index].back().value;
} // square bracket setter

template<class K, class V, const int CAP>
V HashTable<K,V,CAP>::operator[](const K& key) const
{
  int index = hashCode(key) % CAP;
  if(index < 0) index += CAP;
  typename list<Node>::const_iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
    if (it->key == key)
      return it->value;
  V dummy = V();
  return dummy;
} // getter operator

template <class K, class V, const int CAP>
void HashTable<K,V,CAP>::clear()
{
  for (int i = 0; i < CAP; i++)
    data[i].clear();
  siz = 0;
}

template <class K, class V, const int CAP>
bool HashTable<K,V,CAP>::containsKey(const K& key) const
{
  int index = hashCode(key) % CAP;
  if(index < 0) index += CAP;
  typename list<Node>::const_iterator it;
  for(it = data[index].begin(); it != data[index].end(); it++)
    if(it->key == key)
      return true;
  return false;
}

template <class K, class V, const int CAP>
void HashTable<K,V,CAP>::deleteKey(const K& key)
{
  int index = hashCode(key) % CAP;
  if(index < 0) index += CAP;
  typename list<Node>::const_iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
    if (it->key == key)
      break;
  if (it != data[index].end())
  {
    data[index].erase(it);
    --siz;
  }
  return;
}

template <class K, class V, const int CAP>
queue<K> HashTable<K,V,CAP>::keys() const
{
  queue<K> result;
  typename list<Node>::const_iterator it;
  for(int i = 0; i < CAP; i++)
    for(it = data[i].begin(); it != data[i].end(); it++)
      result.push(it->key);
  return result;
}

#endif
