// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#ifndef Associativearray_H
#define Associativearray_H
#include <queue>

template <class K, class V>
class AssociativeArray
{
  struct Node
  {
    K key;
    V value;
    Node* next;
  };
  Node* firstNode;
  int siz;

  public:
    AssociativeArray(); // main constructor
    V& operator[](const K&); // setter operator
    V operator[](const K&) const; // getter operator
    int size() const {return siz;} // size
    void clear(); // clear
    bool containsKey(const K&) const; // check containing key
    void deleteKey(const K&); // delete element with key
    queue<K> keys() const; // return queue(key)
    ~AssociativeArray(); // destructor
    AssociativeArray(const AssociativeArray<K,V>&); // copy constructor
    AssociativeArray<K,V>& operator=(const AssociativeArray<K,V>&); // assignment operator
 };

template <class K, class V>
AssociativeArray<K,V>::AssociativeArray()
{
  firstNode = 0;
  siz = 0;
} // main constructor

template<class K, class V>
V& AssociativeArray<K,V>::operator[](const K& key)
{
  for(Node* p = firstNode; p; p = p->next)
    if(p->key == key)
      return p->value;
  Node* temp = new Node;
  temp->key = key;
  temp->next = firstNode;
  firstNode = temp;
  ++siz;
  return firstNode->value;
} // square bracket setter

template<class K, class V>
V AssociativeArray<K,V>::operator[](const K& key) const
{
  for(Node* p = firstNode; p; p = p->next)
    if(p->key == key)
      return p->value;
  V dummy;
  return dummy;
} // getter operator

template <class K, class V>
void AssociativeArray<K,V>::clear()
{
  while(firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
  siz = 0;
}

template <class K, class V>
bool AssociativeArray<K,V>::containsKey(const K& key) const
{
  for(Node* p = firstNode; p; p = p->next)
    if(p->key == key)
      return true;
  return false;
}

template <class K, class V>
void AssociativeArray<K,V>::deleteKey(const K& key)
{
  Node* p, *prev;
  for (p = firstNode, prev = 0; p; prev = p, p = p->next)
    if (p->key == key)
      break;
  if (p)
  {
    --siz;
    if (prev) prev->next = p->next;
    else firstNode = p->next;
    delete p;
  }
}

template <class K, class V>
queue<K> AssociativeArray<K,V>::keys() const
{
  queue<K> result;
  for(Node* p = firstNode; p; p = p->next)
    result.push(p->key);
  return result;
}

template <class K, class V>
AssociativeArray<K,V>::~AssociativeArray()
{
  while(firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
}

template<class K, class V>
AssociativeArray<K,V>::AssociativeArray(const AssociativeArray<K,V>& origin)
{
  this->siz = origin.siz;
  firstNode = 0;
  Node* lastNode = 0;
  for(Node* p = origin.firstNode; p; p = p->next)
  {
    Node* temp = new Node{p->key,p->value,0};
    if(lastNode)
      lastNode->next = temp;
    else
      firstNode = temp;
    lastNode = temp;
  }
}

template<class K, class V>
AssociativeArray<K,V>& AssociativeArray<K,V>::operator=(const AssociativeArray<K,V>& origin)
{
  if(this != &origin)
  {
    while(firstNode)
    {
      Node* p = firstNode->next;
      delete firstNode;
      firstNode = p;
    }
    Node* lastNode = 0;
    for(Node* p = origin.firstNode; p; p = p->next)
    {
      Node* temp = new Node{p->key,p->value,0};
      if(lastNode)
        lastNode->next = temp;
      else
        firstNode = temp;
      lastNode = temp;
    }
    this->siz = origin.siz;
  }
  return *this;
}

#endif
