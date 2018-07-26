// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#include <iostream>
using namespace std;

#include <cstdlib>
#include <cctype>

#include "Stack.h"

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n";
  
  Stack<double> storage;
  Stack<double> tracker;
  char userInput[100];
  int counter;
  bool isOperator;
  double first, second;

  while (true)
  {
    isOperator = false;
    counter = 0;
    tracker = storage;

    cout << "Enter: ";

    while (!tracker.empty())
    {
      cout << tracker.peek() << ' ';
      tracker.pop();
      counter++;
    }

    cin >> userInput;
    if (userInput[0] == 'Q' || userInput[0] == 'q')
      break;

    if (!isdigit(userInput[0]) && userInput[1] == '\0')
    {
      if (userInput[0] == '+' || userInput[0] == '-' || userInput[0] == '*' || userInput[0] == '/')
       isOperator = true;
      else
        continue;
    }

    if (isOperator)
    {
      if (counter < 2)
        continue;
      else
      {
        second = storage.peek();
        storage.pop();
        first = storage.peek();
        storage.pop();

        if (userInput[0] == '+')
          storage.push(first + second);
        else if (userInput[0] == '-')
          storage.push(first - second);
        else if (userInput[0] == '*')
          storage.push(first * second);
        else if (userInput[0] == '/')
          storage.push(first / second);
      }     
    }
    
    else
      storage.push(atof(userInput));
  }
}
