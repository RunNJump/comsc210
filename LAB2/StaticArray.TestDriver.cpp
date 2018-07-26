// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "StaticArray.h"
#include "StaticArray.h"

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n";
  
  // Testing int
  cout << "\nTesting StaticArray<int, 100>\n";
  StaticArray<int, 100> a;
  
  // Testing StaticArray<int, 100>::capacity()
  cout << "\nTesting StaticArray<int, 100>::capacity()\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << a.capacity() << endl;
  assert(100 == a.capacity());
  
  // Testing StaticArray<int, 100>::StaticArray
  cout << "\nTesting StaticArray<int, 100>::StaticArray\n";
  for (int i = 0; i < a.capacity(); i++)
    assert(a[i] == int());
  
  // Testing StaticArray<int, 100>::operator[] setter
  a[0] = 25463; // lower end of the range
  a[7] = 7654321; // middle of the range
  a[99] = 16644; // upper end of the range
  a[-1000] = 123123; // out of the range
  cout << "\nTesting StaticArray<int, 100>::operator[] setter\n";
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
  cout << "EXPECTED: 123123 for a[101]\n";
  cout << "Actual: " << a[101] << "\n";
  assert(123123 == a[101]);
  
  // Testing StaticArray<int, 100>:operator[] getter
  cout << "\nTesting StaticArray<int, 100>::operator[] getter\n";
  const StaticArray<int, 100> b = a;
  for (int i = 0; i < 100; i++)
    assert(a[i] == b[i]);
  
  // Testing Const object
  cout << "\nTesting Const object\n";
  const StaticArray<int, 100> c;
  assert(c.capacity( ));
  assert(c[0] == c[0]);
  
  // Testing double
  cout << "\nTesting StaticArray<double, 100>\n";
  StaticArray<double, 100> d;
  
  // Testing StaticArray<double, 100>::capacity()
  cout << "\nTesting StaticArray<double, 100>::capacity()\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << d.capacity() << endl;
  assert(100 == d.capacity());
  
  // Testing StaticArray<double, 100>::StaticArray
  cout << "\nTesting StaticArray<double, 100>::StaticArray\n";
  for (int i = 0; i < d.capacity(); i++)
    assert(d[i] == double());
  
  // Testing StaticArray<double, 100>::operator[] setter
  d[0] = 2.54; // lower end of the range
  d[7] = 7.65; // middle of the range
  d[99] = -1.66; // upper end of the range
  d[-1000] = 123.1; // out of the range
  cout << "\nTesting StaticArray<double, 100>::operator[] setter\n";
  cout << "EXPECTED: 2.54 for d[0]\n";
  cout << "ACTUAL: " << d[0] << endl;
  assert(2.54 == d[0]);
  cout << "EXPECTED: 7.65 for d[7]\n";
  cout << "ACTUAL: " << d[7] << endl;
  assert(7.65 == d[7]);
  cout << "EXPECTED: -1.66 for d[99]\n";
  cout << "ACTUAL: " << d[99] << endl;
  assert(-1.66 == d[99]);
  cout << "EXPECTED: 123.1 for d[-1000]\n";
  cout << "ACTUAL: " << d[-1000] << endl;
  assert(123.1 == d[-1000]);
  cout << "EXPECTED: 123.1 for d[101]\n";
  cout << "Actual: " << d[101] << "\n";
  assert(123.1 == d[101]);
  
  // Testing StaticArray<double, 100>:operator[] getter
  cout << "\nTesting StaticArray<double, 100>::operator[] getter\n";
  const StaticArray<double, 100> e = d;
  for (int i = 0; i < 100; i++)
    assert(d[i] == e[i]);
  
  // Testing Const object
  cout << "\nTesting Const object\n";
  const StaticArray<double, 100> f;
  assert(f.capacity( ));
  assert(f[0] == f[0]);

  // Testing string
  cout << "\nTesting StaticArray<string, 100>\n";
  StaticArray<string, 100> g;
  
  // Testing StaticArray<string, 100>::capacity()
  cout << "\nTesting StaticArray<string, 100>::capacity()\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << g.capacity() << endl;
  assert(100 == g.capacity());
  
  // Testing StaticArray<string, 100>::StaticArray
  cout << "\nTesting StaticArray<string, 100>::StaticArray\n";
  for (int i = 0; i < d.capacity(); i++)
    assert(g[i] == string());
  
  // Testing StaticArray<string, 100>::operator[] setter
  g[0] = "abc"; // lower end of the range
  g[7] = "tv"; // middle of the range
  g[99] = "utue"; // upper end of the range
  g[-1000] = "pegg"; // out of the range
  cout << "\nTesting StaticArray<string, 100>::operator[] setter\n";
  cout << "EXPECTED: abc for g[0]\n";
  cout << "ACTUAL: " << g[0] << endl;
  assert("abc" == g[0]);
  cout << "EXPECTED: tv for g[7]\n";
  cout << "ACTUAL: " << g[7] << endl;
  assert("tv" == g[7]);
  cout << "EXPECTED: utue for g[99]\n";
  cout << "ACTUAL: " << g[99] << endl;
  assert("utue" == g[99]);
  cout << "EXPECTED: pegg for g[-1000]\n";
  cout << "ACTUAL: " << g[-1000] << endl;
  assert("pegg" == g[-1000]);
  cout << "EXPECTED: pegg for g[101]\n";
  cout << "Actual: " << g[101] << "\n";
  assert("pegg" == g[101]);
  
  // Testing StaticArray<string, 100>:operator[] getter
  cout << "\nTesting StaticArray<string, 100>::operator[] getter\n";
  const StaticArray<string, 100> h = g;
  for (int i = 0; i < 100; i++)
    assert(h[i] == g[i]);
  
  // Testing Const object
  cout << "\nTesting Const object\n";
  const StaticArray<string, 100> i;
  assert(i.capacity( ));
  assert(i[0] == i[0]);
}
