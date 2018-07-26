// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#include <iostream>
using namespace std;

#include <cstdlib>

#include "SortableArray.h"

struct Node
{
  double value;
  bool inUse;
  Node():value(), inUse(){}
  bool operator<(const Node& original){return value < original.value;}
};

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n";

  int index;
  double value;
  char buf[100];
  SortableArray<Node> container;
  
  // Input
  while (true)
  {
    cout << "Enter the index and value [Q to quit]: ";
    cin >> buf;
    if (buf[0] == 'Q' || buf[0] == 'q')
      break;
    index = atoi(buf);
    cin >> buf;
    if (buf[0] == 'Q' || buf[0] == 'q')
      break;
    value = atof(buf);
    container[index].value = value;
    container[index].inUse = true;
  }
  container[-1].inUse = false;
  
  // set counter
  int counter = 0;
  for (int i = 0; i < container.capacity(); i++)
    if (container[i].inUse)
      counter++;

  cout << "\nThe number of values entered by you: " << counter << endl;

  cout << "Unsorted list: ";
  for (int i = 0; i < container.capacity(); i++)
    if (container[i].inUse)
      cout << i << "=>" << container[i].value << " ";
  cout << "\b\b \n\n";

  cout << "Enter how many values to sort: ";
  cin >> buf;
  container.sort(atoi(buf));

  cout << "Sorted list: ";
  for (int i = 0; i < container.capacity(); i++)
    if (container[i].inUse)
        cout << i << "=>" << container[i].value << " ";
  cout << "\b\b \n\n";
  
  // get user input to display
  while (true)
  {
    cout << "Enter the index to display [Q to quit]: ";
    cin >> buf;
    if (buf[0] == 'Q' || buf[0] == 'q')
      break;
    index = atoi(buf);
    if (container[index].inUse)
      cout << "The value stored at " << index << " is " << container[index].value << endl;
    else
      cout << "I can't find it\n";
  }
}
