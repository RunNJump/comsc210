//Programmer: Hongseok Jang
//Programmer's ID: 1560046

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
template <class T>
class LinkedStack
{
private:
  struct Node
  {
    T value;
    Node* next;
  };
  Node* head;
  int siz;
  T dummy;

public:
  LinkedStack();
  LinkedStack(const LinkedStack<T>&);
  LinkedStack<T>& operator=(const LinkedStack<T>&);
  void push(const T&);
  void pop();
  void clear();
  bool empty(){return head?false:true;}
  T& peek(){return head?head->value:dummy;}
  ~LinkedStack();
};

template <class T>
LinkedStack<T>::LinkedStack()
{
  siz = 0;
  head = nullptr;
}

template <class T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& ref)
{
  head = nullptr;
  Node* lastNode = nullptr;
  this->siz = ref.siz;
  for(Node* nodePtr = ref.head; nodePtr; nodePtr = nodePtr->next)
  {
    Node* temp = new Node{nodePtr->value, nullptr};
    if(lastNode)
      lastNode->next = temp;
    else
      head = temp;
    lastNode = temp;
  }
}

template <class T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& ref)
{
  if(this != &ref)
  {
    while(head)
    {
      Node* nodePtr = head->next;
      delete head;
      head = nodePtr;
    }
    Node* lastNode = nullptr;
    for(Node* nodePtr = ref.head; nodePtr; nodePtr= nodePtr->next)
    {
      Node* temp = new Node{nodePtr->value, nullptr};
      if(lastNode)
        lastNode->next = temp;
      else
        head = temp;
      lastNode = temp;
    }
    siz = ref.siz;
  }
  return *this;
}

template <class T>
void LinkedStack<T>::push(const T& value)
{
  Node* newNode = new Node{value, nullptr};
  if(head)
    newNode->next = head;
  head = newNode;
  ++siz;
}

template <class T>
void LinkedStack<T>::pop()
{
  if(head)
  {
    Node* temp = head;
    head = head->next;
    delete temp;
    --siz;
  }
}

template <class T>
void LinkedStack<T>::clear()
{
  while(head)
  {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  siz = 0;
}

template <class T>
LinkedStack<T>::~LinkedStack()
{
  while(head)
  {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}
#endif // LINKEDSTACK_H
