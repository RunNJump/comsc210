// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "Stack.h"
#include "Stack.h"

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n";
  
  // Testing int
  cout << "\nTesting Stack<int>\n";
  Stack<int> a;
  int topInt;

  // Testing push and peek
  cout << "\nTesting push and peek\n";
  a.push(15355);
  topInt = a.peek();
  cout << "EXPECTED: 15355 for topInt\n";
  cout << "ACTUAL: " << topInt << endl;
  assert(topInt == 15355);
  a.push(12344);
  topInt = a.peek();
  cout << "EXPECTED: 12344 for topInt\n";
  cout << "ACTUAL: " << topInt << endl;
  assert(topInt == 12344);
  a.push(45725);
  topInt = a.peek();
  cout << "EXPECTED: 45725 for topInt\n";
  cout << "ACTUAL: " << topInt << endl;
  assert(topInt == 45725);

  // Testing pop()
  cout << "\nTesting pop()\n";
  a.pop();
  topInt = a.peek();
  cout << "EXPECTED: 12344 for topInt\n";
  cout << "ACTUAL: " << topInt << endl;
  assert(topInt == 12344);
  a.pop();
  topInt = a.peek();
  cout << "EXPECTED: 15355 for topInt\n";
  cout << "ACTUAL: " << topInt << endl;
  assert(topInt == 15355);
  
  // Testing size()
  cout << "\nTesting size()\n";
  cout << "EXPECTED: 1 for a.size()\n";
  cout << "ACTUAL: " << a.size() << endl;
  assert(a.size() == 1);
  
  // Testing clear() and empty()
  cout << "\nTesting clear() and empty()\n";
  a.clear();
  cout << "EXPECTED: 1 for a.empty()\n";
  cout << "ACTUAL: " << a.empty() << endl;
  assert(a.empty() == 1);
  a.push(15355);
  cout << "EXPECTED: 0 for a.empty()\n";
  cout << "ACTUAL: " << a.empty() << endl;
  assert(a.empty() == 0);

  // Testing copy constructor
  cout << "\nTesting copy constructor\n";
  Stack<int> b = a;
  topInt = b.peek();
  cout << "EXPECTED: 15355 for topInt\n";
  cout << "ACTUAL: " << topInt << endl;
  assert(topInt == 15355);
  b.push(46477);
  topInt = b.peek();
  cout << "EXPECTED: 46477 for topInt\n";
  cout << "ACTUAL: " << topInt << endl;
  assert(topInt == 46477);
  
  // Testing assignment operator
  cout << "\nTesting assignment operator\n";
  Stack<int> c;
  c = a;
  topInt = c.peek();
  cout << "EXPECTED: 15355 for topInt\n";
  cout << "ACTUAL: " << topInt << endl;
  assert(topInt == 15355);
  c.push(46477);
  topInt = c.peek();
  cout << "EXPECTED: 46477 for topInt\n";
  cout << "ACTUAL: " << topInt << endl;
  assert(topInt == 46477);

  // Testing const object
  cout << "\nTesting const object\n";
  const Stack<int> d;
  assert(d.size() == 0);
  assert(d.empty());
  
  // Testing string
  cout << "\nTesting Stack<string>\n";
  Stack<string> e;
  string topS;

  // Testing push and peek
  cout << "\nTesting push and peek\n";
  e.push("Hi");
  topS = e.peek();
  cout << "EXPECTED: Hi for topS\n";
  cout << "ACTUAL: " << topS << endl;
  assert(topS == "Hi");
  e.push("Hello");
  topS = e.peek();
  cout << "EXPECTED: Hello for topS\n";
  cout << "ACTUAL: " << topS << endl;
  assert(topS == "Hello");
  e.push("Bye");
  topS = e.peek();
  cout << "EXPECTED: Bye for topS\n";
  cout << "ACTUAL: " << topS << endl;
  assert(topS == "Bye");

  // Testing pop()
  cout << "\nTesting pop()\n";
  e.pop();
  topS = e.peek();
  cout << "EXPECTED: Hello for topS\n";
  cout << "ACTUAL: " << topS << endl;
  assert(topS == "Hello");
  e.pop();
  topS = e.peek();
  cout << "EXPECTED: Hi for topS\n";
  cout << "ACTUAL: " << topS << endl;
  assert(topS == "Hi");
  
  // Testing size()
  cout << "\nTesting size()\n";
  cout << "EXPECTED: 1 for e.size()\n";
  cout << "ACTUAL: " << e.size() << endl;
  assert(e.size() == 1);
  
  // Testing clear() and empty()
  cout << "\nTesting clear() and empty()\n";
  e.clear();
  cout << "EXPECTED: 1 for e.empty()\n";
  cout << "ACTUAL: " << e.empty() << endl;
  assert(e.empty() == 1);
  e.push("Hi");
  cout << "EXPECTED: 0 for e.empty()\n";
  cout << "ACTUAL: " << e.empty() << endl;
  assert(e.empty() == 0);
  
  // Testing copy constructor
  cout << "\nTesting copy constructor\n";
  Stack<string> f = e;
  topS = f.peek();
  cout << "EXPECTED: Hi for topS\n";
  cout << "ACTUAL: " << topS << endl;
  assert(topS == "Hi");
  f.push("Yo");
  topS = f.peek();
  cout << "EXPECTED: Yo for topS\n";
  cout << "ACTUAL: " << topS << endl;
  assert(topS == "Yo");
  
  // Testing assignment operator
  cout << "\nTesting assignment operator\n";
  Stack<string> g;
  g = e;
  topS = g.peek();
  cout << "EXPECTED: Hi for topS\n";
  cout << "ACTUAL: " << topS << endl;
  assert(topS == "Hi");
  g.push("Yo");
  topS = g.peek();
  cout << "EXPECTED: Yo for topS\n";
  cout << "ACTUAL: " << topS << endl;
  assert(topS == "Yo");  

  // Testing const object
  cout << "\nTesting const object\n";
  const Stack<string> h;
  assert(h.size() == 0);
  assert(h.empty());
}
