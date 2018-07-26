// identification
// Programmer: Hongseok Jang
// Programmer's ID: 156004

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

#include <cstring> // strtok
#include <cstdlib> // atoi

#include "StaticArray.h"
#include "DynamicArray.h"
#include "AssociativeArray.h"

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n\n";
  
  StaticArray<string, 10000> alreadySeen;
  StaticArray<bool, 10000> inUse;
  AssociativeArray<string, AssociativeArray<string, int> > subjectArray;
  DynamicArray<string> subjectCopy;

  int subjectCounter = 0;
  int lineCounter = 0;
  int duplicateCounter = 0;
  char* token;
  char buf[1000];
  
  for (int i = 0; i < 10000; i++)
    inUse[i] = false;
  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  
  // read the input file
  while (fin.good())
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
    const int sectionN = atoi(section.c_str()); // Make section integer
    

    if (inUse[sectionN])
    {
      if(alreadySeen[sectionN].find(term) != string::npos)
      {
        duplicateCounter++;
        lineCounter++;
        continue;
      }
      else
        alreadySeen[sectionN] += term;
    }
    else
    {
      inUse[sectionN] = true;
      alreadySeen[sectionN] = term;
    }
    
    if (subjectArray.containsKey(subjectCode))
    {
      if (subjectArray[subjectCode].containsKey(course))
        subjectArray[subjectCode][course]++;
      else
        subjectArray[subjectCode][course] = 1;
    }
    else
    {
      subjectArray[subjectCode][course] = 1;
      subjectCounter++;
    }
    lineCounter++;
  }
  fin.close();
  
  int i = 0;
  for(queue<string> q = subjectArray.keys(); !q.empty(); q.pop(), i++)
    subjectCopy[i] = q.front();

  // Alphabetic order
  for (int i = 0; i < subjectArray.size(); i++)
    for (int j = i + 1; j < subjectArray.size(); j++)
      if (subjectCopy[j] < subjectCopy[i])
        swap(subjectCopy[i], subjectCopy[j]);
  
  // Display output
  cout << "----- DVC Schedule -----\n\n";
  for (int i = 0; i < subjectArray.size(); i++)
  {
    cout << subjectCopy[i] << ", " << subjectArray[subjectCopy[i]].size() << " course(s)\n";
    for(queue<string> q = subjectArray[subjectCopy[i]].keys(); !q.empty(); q.pop())
      cout << "  " << q.front() << ", " << subjectArray[subjectCopy[i]][q.front()] << " section(s)\n";
  }

  cout << "\nThe number of lines: " << lineCounter << endl;
  cout << "The number of duplicate lines: " << duplicateCounter << endl;
  cout << "The number of subject: " << subjectCounter << endl;
}
