// identification
// Programmer: Hongseok Jang
// Programmer's ID: 156004

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include "StaticArray.h"

struct SectionsForTerm
{
  string term;
  int numberOfSectionsSeen;
  StaticArray<int, 3000> seenSectionNumbers;
};

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n\n";
  
  srand(time(0)); rand(); // seed the random number generator (in case you need it)

  // programmer customizations
  int n = 8000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n)";

  cout.setf(ios::fixed);
  cout.precision(4);
  double elapsedSecondsNorm = 0;
  double expectedSeconds = 0;
  
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    // do something where n is the "size" of the problem
    for (int rep = 0; rep < 10; rep++)
    {
      char* token;
      char buf[1000];
      int termCounter = 0;
      bool termFound = false;
      bool sectionFound = false;
      StaticArray<string, 200> subjectArray;
      StaticArray<SectionsForTerm, 200> alreadySeen;

      ifstream fin;
      fin.open("dvc-schedule.txt");
      if (!fin.good()) throw "I/O error";
      
      for(int j = 0; j < n; j++)
      {
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());
        if (buf[0] == 0) continue; // skip blank lines
        
        // parse the line
        const string term(token = strtok(buf, "\t"));
        const string section(token = strtok(0, "\t"));
        const string course((token = strtok(0, "\t")) ? token : "");
        const string instructor((token = strtok(0, "\t")) ? token : "");
        const string whenWhere((token = strtok(0, "\t")) ? token : "");
        if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
        const string subjectCode(course.begin(), course.begin() + course.find('-'));
        const int sectionN = atoi(section.c_str());
        
        int i;
        for (i = 0; i < termCounter; i++)
        {
          if (alreadySeen[i].term == term)
          {
            (alreadySeen[i].numberOfSectionsSeen)++;
            termFound = true;
            break;
          }
        }
        
        if (termFound)
        {
          for (int j = 0; j < alreadySeen[i].numberOfSectionsSeen; j++)
          {
            if (alreadySeen[i].seenSectionNumbers[j] == sectionN)
            {
              sectionFound = true;
              break;
            }
          }
          
          if (sectionFound)
            continue;
          
          else
          {
            alreadySeen[i].seenSectionNumbers[alreadySeen[i].numberOfSectionsSeen] = sectionN;
          }
        }
        
        else
        {
          alreadySeen[termCounter].term = term;
          alreadySeen[termCounter].seenSectionNumbers[0] = sectionN;
          alreadySeen[termCounter].numberOfSectionsSeen = 1;
        }
      }
      fin.close();
    }
    clock_t endTime = clock(); 

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
