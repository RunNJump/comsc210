// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "DynamicArray.h"
#include "DynamicArray.h"

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n";
  
  // Testing int
  cout << "\nTesting DynamicArray<int>\n";
  DynamicArray<int> a;
  
  // Testing DynamicArray<int>::capacity()
  cout << "\nTesting DynamicArray<int>::capacity()\n";
  cout << "EXPECTED: 2\n";
  cout << "ACTUAL: " << a.capacity() << endl;
  assert(2  == a.capacity());
  
  // Testing capacity change
  a.capacity(10);
  cout << "\nTesting DynamicArray<int>::capacity(int)\n";
  cout << "EXPECTED: 10\n";
  cout << "ACTUAL: " << a.capacity() << endl;
  assert(10  == a.capacity());

  // Testing DynamicArray<int>::operator[] setter
  a[0] = 25463; // lower end of the range
  a[7] = 7654321; // middle of the range
  a[99] = 16644; // upper end of the range
  a[-1000] = 123123; // out of the range
  cout << "\nTesting DynamicArray<int>::operator[] setter\n";
  cout << "EXPECTED: 25463 for a[0]\n";
  cout << "ACTUAL: " << a[0] << endl;
  assert(25463 == a[0]);
  cout << "EXPECTED: 7654321 for a[7]\n";
  cout << "ACTUAL: " << a[7] << endl;
  assert(7654321 == a[7]);
  cout << "EXPECTED: 16644 for a[99]\n";
  cout << "ACTUAL: " << a[99] << endl;
  assert(16644 == a[99]);
  cout << "EXPECTED: 123123 for a[-1000]\n";
  cout << "ACTUAL: " << a[-1000] << endl;
  assert(123123 == a[-1000]);
  cout << "EXPECTED: 0 for a[101]\n";
  cout << "Actual: " << a[101] << "\n";
  assert(0 == a[101]);
  
  // Testing DynamicArray<int>:operator[] getter
  cout << "\nTesting DynamicArray<int>::operator[] getter\n";
  const DynamicArray<int> b = a;
  for (int i = 0; i < 100; i++)
    assert(a[i] == b[i]);

  // Testing Const object
  cout << "\nTesting Const object\n";
  const DynamicArray<int> c;
  assert(c.capacity());
  assert(c[0] == c[0]);

  // Testing object copy
  cout << "\nTesting object copy\n";
  DynamicArray<int> d = a;
  assert(a.capacity() == d.capacity());
  for (int i = 0; i < d.capacity(); i++)
    assert(a[i] == d[i]);

  // Testing object assignment
  cout << "\nTesting object assignment\n";
  DynamicArray<int> e; e = a;
  assert(a.capacity() == e.capacity());
  for (int i = 0; i < 10; i++)
    assert(a[i] == e[i]); 

  // Testing string
  cout << "\nTesting DynamicArray<string>\n";
  DynamicArray<string> f;
  
  // Testing DynamicArray<string>::capacity()
  cout << "\nTesting DynamicArray<string>::capacity()\n";
  cout << "EXPECTED: 2\n";
  cout << "ACTUAL: " << f.capacity() << endl;
  assert(2 == f.capacity());
    
  // Testing capacity change
  f.capacity(10);
  cout << "\nTesting DynamicArray<string>::capacity(int)\n";
  cout << "EXPECTED: 10\n";
  cout << "ACTUAL: " << f.capacity() << endl;
  assert(10  == f.capacity());

  // Testing DynamicArray<string>::operator[] setter
  f[0] = "abc"; // lower end of the range
  f[7] = "tv"; // middle of the range
  f[99] = "utue"; // upper end of the range
  f[-1000] = "pegg"; // out of the range
  cout << "\nTesting DynamicArray<string>::operator[] setter\n";
  cout << "EXPECTED: abc for f[0]\n";
  cout << "ACTUAL: " << f[0] << endl;
  assert("abc" == f[0]);
  cout << "EXPECTED: tv for f[7]\n";
  cout << "ACTUAL: " << f[7] << endl;
  assert("tv" == f[7]);
  cout << "EXPECTED: utue for f[99]\n";
  cout << "ACTUAL: " << f[99] << endl;
  assert("utue" == f[99]);
  cout << "EXPECTED: pegg for f[-1000]\n";
  cout << "ACTUAL: " << f[-1000] << endl;
  assert("pegg" == f[-1000]);
  cout << "EXPECTED: (empty) for f[101]\n";
  cout << "Actual: " << f[101] << "\n";
  assert("" == f[101]);
  
  // Testing DynamicArray<string>:operator[] getter
  cout << "\nTesting DynamicArray<string>::operator[] getter\n";
  const DynamicArray<string> h = f;
  for (int i = 0; i < 100; i++)
    assert(h[i] == f[i]);
  
  // Testing Const object
  cout << "\nTesting Const object\n";
  const DynamicArray<string> i;
  assert(i.capacity( ));
  assert(i[0] == i[0]);

  // Testing object copy
  cout << "\nTesting object copy\n";
  DynamicArray<string> j = f;
  assert(f.capacity() == j.capacity());
  for (int i = 0; i < j.capacity(); i++)
    assert(f[i] == j[i]);

  // Testing object assignment
  cout << "\nTesting object assignment\n";
  DynamicArray<string> k; k = f;
  assert(f.capacity() == k.capacity());
  for (int i = 0; i < 10; i++)
    assert(f[i] == k[i]); 
}
