// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#include <iostream>
using namespace std;

#include <cstdlib> //atoi

class Array
{
  int values[100];
  int dummy;
  
public:
  Array();
  int capacity() const{return 100;}
  int& operator[](int);
  int operator[](int) const;
};

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n\n";
  
  int index;
  int value;
  int count = 0;
  char userInput[10];
  Array storage;
  Array tracker;
  
  while (true)
  {
    cout << "Input an index and a value [Q to quit]: ";
    cin >> userInput;
    if (userInput[0] == 'q' || userInput[0] == 'Q')
      break;
    index = atoi(userInput);
    cin >> userInput;
    if (userInput[0] == 'q' || userInput[0] == 'Q')
      break;
    value = atoi(userInput);
    storage[index] = value;
    tracker[index] = 1;
  }
  
  const Array constTracker = tracker;
  for (int i = 0; i < constTracker.capacity(); i++)
    if (constTracker[i] == 1)
      count++;
  cout << "\nYou stored this many values: " << count << "\n";
  cout << "The index-value pairs are: \n";
  for (int i = 0; i < constTracker.capacity(); i++)
    if (constTracker[i] == 1)
      cout << "  " << i << " -> " << storage[i] << endl;
  cout << endl;
  
  while (true)
  {
    cout << "Input an index for me to look up [Q to quit]: ";
    cin >> userInput;
    if (userInput[0] == 'q' || userInput[0] == 'Q')
      break;
    index = atoi(userInput);
    if (constTracker[index] == 1)
      cout << "Found it -- the value stored at " << index << " is " << storage[index] << endl;
    else
      cout << "I didn't find it" << endl;
  }
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
