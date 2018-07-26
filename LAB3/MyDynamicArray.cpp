// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#include <iostream>
using namespace std;

#include <cstdlib> //atof, atoi

#include "DynamicArray.h"

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n\n";
  
  int index;
  double value;
  int count = 0;
  char userInput[10];
  DynamicArray<double> storage;
  DynamicArray<bool> tracker;
  
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
    value = atof(userInput);
    storage[index] = value;
    tracker[index] = true;
  }

  tracker[-1] = false; // make dummy false
  
  const DynamicArray<bool>& constTracker = tracker;
  for (int i = 0; i < constTracker.capacity(); i++)
    if (constTracker[i] == true)
      count++;
  cout << "\nYou stored this many values: " << count << "\n";
  cout << "The index-value pairs are: \n";
  for (int i = 0; i < constTracker.capacity(); i++)
    if (constTracker[i] == true)
      cout << "  " << i << " -> " << storage[i] << endl;
  cout << endl;
  
  while (true)
  {
    cout << "Input an index for me to look up [Q to quit]: ";
    cin >> userInput;
    if (userInput[0] == 'q' || userInput[0] == 'Q')
      break;
    index = atoi(userInput);
    if (constTracker[index] == true)
      cout << "Found it -- the value stored at " << index << " is " << storage[index] << endl;
    else
      cout << "Sorry, but there is no value stored at index " << userInput << endl;
  }
}
