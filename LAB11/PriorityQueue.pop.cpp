// identification
// Programmer: Hongseok Jang
// Programmer's ID: 156004

#include <iostream>
using namespace std;

#include <cassert>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include "PriorityQueue.h"

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n\n";
  
  srand(time(0)); // seed the random number generator

  // programmer customizations
  int n = 1000000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  const int oneN = n / 100;

  cout.setf(ios::fixed);
  cout.precision(4);
  double elapsedSecondsNorm = 0;
  
  for (int cycle = 0; cycle < 4; cycle++, n *= 2)
  {
    PriorityQueue<int> pQueue;
    for (int i = 0; i < n; i++)
      pQueue.push(rand());
    // assert
    assert(pQueue.size() == n);
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    // do something where n is the "size" of the problem
    for(int rep = 0; rep < oneN; rep++)
      pQueue.pop();

    clock_t endTime = clock(); 

    for(int i = pQueue.top(); !pQueue.empty(); i = pQueue.top())
    {
      pQueue.pop();
      assert(pQueue.top() <= i);
    }

    // compute timing results
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double factor = pow(2.0, double(cycle));
    if (cycle == 0)
      elapsedSecondsNorm = elapsedSeconds;
    double expectedSecondsLog = log(double(n)) / log(n/factor) * elapsedSecondsNorm;

    // reporting block
    cout << elapsedSeconds;
    if (cycle == 0) cout << " (expected)";
    else cout << " (expected " << elapsedSecondsNorm << " to " << expectedSecondsLog << ')';
    cout << " for n = " << n << endl;
  }
}
