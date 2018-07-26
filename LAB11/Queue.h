// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#ifndef Queue_H
#define Queue_H

template <typename V>
class Queue
{
  struct Node
  {
    V value;
    Node* next;
  };
  Node* head;
  Node* tail;
  int siz;
  V dummy;

public:
  ~Queue(); // destructor
  Queue(); // main constructor
  Queue(const Queue<V>&); // copy constructor
  Queue<V>& operator=(const Queue<V>&); // assignment operator
  void pop();
  void clear();  
  void push(const V&);
  bool empty() const {return head? false : true;}
  int size() const{return siz;}
  V& front(){return head? head->value:dummy;}
  V& back(){return tail? tail->value:dummy;}
};

template <typename V>
Queue<V>::Queue()
{
  head = 0;
  tail = 0;
  siz = 0;
} // main constructor

template <typename V>
Queue<V>::Queue(const Queue<V>& original)
{
  head = 0;
  tail = 0;
  this->siz = original.siz;
  for (Node* p = original.head; p; p = p->next)
  {
    Node* temp = new Node{p->value, 0};
    if(tail)
      tail->next = temp;
    else
      head = temp;
    tail = temp;
  }
} // copy constructor

template <typename V>
Queue<V>& Queue<V>::operator=(const Queue<V>& original)
{
  if (this != &original)
  {
    while (head) 
    { 
      Node* p = head->next; 
      delete head; 
      head = p;
    }
    tail = 0;
    for (Node* p = original.head; p; p = p->next)
    {
      Node* temp = new Node;
      temp->value = p->value;
      temp->next = 0;
      if (tail)
        tail->next = temp;
      else 
        head = temp;
      tail = temp;
    } 
    siz = original.siz;
  }
  return *this;
} // assignment operator

template <typename V>
void Queue<V>::push(const V& value)
{
  Node * p = new Node{value, 0};
  if(tail)
    tail->next = p;
  else
    head = p;
  tail = p;
  siz++;
}

template <typename V>
void Queue<V>::pop()
{
  if(head)
  {
    Node* temp = head->next;
    delete head;
    head = temp;
    if(--siz == 0)
      tail = 0;
  }
}

template <typename V>
void Queue<V>::clear()
{
  while(head)
  {
    Node* p = head->next;
    delete head;
    head = p;
  }
  tail = 0;
  siz = 0;
}

template <typename V>
Queue<V>::~Queue()
{
  while(head)
  {
    Node* p = head->next;
    delete head;
    head = p;
  }
}

#endif
