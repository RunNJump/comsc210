// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "Queue.h"
#include "Queue.h"

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n";
  
  // Testing int
  cout << "\nTesting Queue<int>\n";
  Queue<int> a;
  int head;
  int tail;

  // Testing push()
  cout << "\nTesting push and peek\n";
  a.push(15355);
  a.push(12344);
  a.push(45725);
  head = a.front();
  cout << "EXPECTED: 15355 for head\n";
  cout << "ACTUAL: " << head << endl;
  assert(head == 15355);
  tail = a.back();
  cout << "EXPECTED: 45725 for tail\n";
  cout << "ACTUAL: " << tail << endl;
  assert(tail == 45725);

  // Testing pop()
  cout << "\nTesting pop()\n";
  a.pop();
  head = a.front();
  cout << "EXPECTED: 12344 for head\n";
  cout << "ACTUAL: " << head << endl;
  assert(head == 12344);
  tail = a.back();
  cout << "EXPECTED: 45725 for tail\n";
  cout << "ACTUAL: " << tail << endl;
  assert(tail == 45725);
  
  // Testing size()
  cout << "\nTesting size()\n";
  cout << "EXPECTED: 2 for a.size()\n";
  cout << "ACTUAL: " << a.size() << endl;
  assert(a.size() == 2);
  
  // Testing clear() and empty()
  cout << "\nTesting clear() and empty()\n";
  a.clear();
  cout << "EXPECTED: 1 for a.empty()\n";
  cout << "ACTUAL: " << a.empty() << endl;
  assert(a.empty() == 1);
  a.push(15355);
  a.push(13466);
  a.push(46477);
  cout << "EXPECTED: 0 for a.empty()\n";
  cout << "ACTUAL: " << a.empty() << endl;
  assert(a.empty() == 0);

  // Testing copy constructor
  cout << "\nTesting copy constructor\n";
  Queue<int> b = a;
  head = b.front();
  cout << "EXPECTED: 15355 for head\n";
  cout << "ACTUAL: " << head << endl;
  assert(head == 15355);
  tail = b.back();
  cout << "EXPECTED: 46477 for tail\n";
  cout << "ACTUAL: " << tail << endl;
  assert(tail == 46477);
  
  // Testing assignment operator
  cout << "\nTesting assignment operator\n";
  Queue<int> c;
  c = a;
  head = c.front();
  cout << "EXPECTED: 15355 for head\n";
  cout << "ACTUAL: " << head << endl;
  assert(head == 15355);
  tail = c.back();
  cout << "EXPECTED: 46477 for tail\n";
  cout << "ACTUAL: " << tail << endl;
  assert(tail == 46477);

  // Testing const object
  cout << "\nTesting const object\n";
  const Queue<int> d;
  assert(d.size() == 0);
  assert(d.empty());
  
  // Testing string
  cout << "\nTesting Queue<string>\n";
  Queue<string> e;
  string headS;
  string tailS;

 // Testing push()
  cout << "\nTesting push and peek\n";
  e.push("Hi");
  e.push("Hello");
  e.push("Bye");
  headS = e.front();
  cout << "EXPECTED: Hi for headS\n";
  cout << "ACTUAL: " << headS << endl;
  assert(headS == "Hi");
  tailS = e.back();
  cout << "EXPECTED: Bye for tailS\n";
  cout << "ACTUAL: " << tailS << endl;
  assert(tailS == "Bye");

  // Testing pop()
  cout << "\nTesting pop()\n";
  e.pop();
  headS = e.front();
  cout << "EXPECTED: Hello for headS\n";
  cout << "ACTUAL: " << headS << endl;
  assert(headS == "Hello");
  tailS = e.back();
  cout << "EXPECTED: Bye for tailS\n";
  cout << "ACTUAL: " << tailS << endl;
  assert(tailS == "Bye");
  
  // Testing size()
  cout << "\nTesting size()\n";
  cout << "EXPECTED: 2 for e.size()\n";
  cout << "ACTUAL: " << e.size() << endl;
  assert(e.size() == 2);
  
  // Testing clear() and empty()
  cout << "\nTesting clear() and empty()\n";
  e.clear();
  cout << "EXPECTED: 1 for e.empty()\n";
  cout << "ACTUAL: " << e.empty() << endl;
  assert(e.empty() == 1);
  e.push("Hey");
  e.push("Men");
  e.push("Yo");
  cout << "EXPECTED: 0 for e.empty()\n";
  cout << "ACTUAL: " << e.empty() << endl;
  assert(e.empty() == 0);

  // Testing copy constructor
  cout << "\nTesting copy constructor\n";
  Queue<string> f = e;
  headS = f.front();
  cout << "EXPECTED: Hey for headS\n";
  cout << "ACTUAL: " << headS << endl;
  assert(headS == "Hey");
  tailS = f.back();
  cout << "EXPECTED: Yo for tailS\n";
  cout << "ACTUAL: " << tailS << endl;
  assert(tailS == "Yo");
  
  // Testing assignment operator
  cout << "\nTesting assignment operator\n";
  Queue<string> g;
  g = e;
  headS = g.front();
  cout << "EXPECTED: Hey for headS\n";
  cout << "ACTUAL: " << headS << endl;
  assert(headS == "Hey");
  tailS = g.back();
  cout << "EXPECTED: Yo for tailS\n";
  cout << "ACTUAL: " << tailS << endl;
  assert(tailS == "Yo");

  // Testing const object
  cout << "\nTesting const object\n";
  const Queue<string> h;
  assert(h.size() == 0);
  assert(h.empty());
  }
