// identification
// Programmer: Hongseok Jang
// Programmer's ID: 156004

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include <cassert>
#include <cstdlib>
#include <cmath>
#include <ctime>

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n\n";
  
  srand(time(0)); rand(); // seed the random number generator (in case you need it)

  // programmer customizations go here
  int n = 2000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n squared)";
  
  cout.setf(ios::fixed);
  cout.precision(4);
  double elapsedSecondsNorm = 0;
  double expectedSeconds = 0;

  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    double* a = new double[n];
    for (int i = 0; i < n; i++)
      a[i] = rand();
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    // do something where n is the "size" of the problem
    bool inOrder = true;
    for (int i = 0; i< n; i++)
      for(int j = i + 1 ; j < n; j++)
        if (a[i] > a[j])
          swap(a[i],a[j]);
    clock_t endTime = clock(); 

    // validation block -- assure that process worked if applicable
    for (int i = 1; i < n; i++) 
      assert (a[i - 1] <= a[i]);
    
    // cleanup if applicable
    delete[] a;

    // compute timing results
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double factor = pow(2.0, double(cycle));
    if (cycle == 0)
      elapsedSecondsNorm = elapsedSeconds;
    else if (bigOh == "O(n)")
      expectedSeconds = factor * elapsedSecondsNorm;
    else if (bigOh == "O(n log n)")
      expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm;
    else if (bigOh == "O(n squared)")
      expectedSeconds = factor * factor * elapsedSecondsNorm;

    // reporting block
    cout << elapsedSeconds;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedSeconds << ')';
    cout << " for n=" << n << endl;
  }
}
