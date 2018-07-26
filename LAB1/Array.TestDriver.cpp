// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#include <iostream>
using namespace std;

#include <cassert>

class Array
{
  int values[100];
  int dummy;
  
public:
  Array(); // constructor
  int capacity() const{return 100;}
  int& operator[](int);
  int operator[](int) const;
};

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n";
  
  Array a;
  
  // Testing Array::capacity()
  cout << "\nTesting Array::capacity()\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << a.capacity() << endl;
  assert(100 == a.capacity());
  
  // Testing Array::Array
  cout << "\nTesting Array::Array\n";
  for (int i = 0; i < a.capacity(); i++)
    assert(a[i] == 0);
  
  // Testing Array::operator[] setter
  a[0] = 25463; // lower end of the range
  a[7] = 7654321; // middle of the range
  a[99] = 16644; // upper end of the range
  a[-1000] = 123123; // out of the range
  cout << "\nTesting Array::operator[] setter\n";
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
  
  // Testing Array:operator[] getter
  cout << "\nTesting Array::operator[] getter\n";
  const Array b = a;
  for (int i = 0; i < 100; i++)
    assert(a[i] == b[i]);
  
  // Testing Const object
  cout << "\nTesting Const object\n";
  const Array c;
  assert(c.capacity( ));
  assert(c[0] == c[0]);
}

  Array::Array()
  {
    for (int i = 0; i < 100; i++)
      values[i] = int();
  }
  
  int& Array::operator[](int index)
  {
    if (index < 0 || index >= 100)
      return dummy;
    return values[index];
  }
  
  int Array::operator[](int index) const
  {
    if (index < 0 || index >= 100)
      return - 999;
    return values[index];
  }
