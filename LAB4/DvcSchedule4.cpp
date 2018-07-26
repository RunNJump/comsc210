// identification
// Programmer: Hongseok Jang
// Programmer's ID: 156004

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

#include <cstring> // strtok

#include "DynamicArray.h"

struct subject
{
  int sectionCounter;
  string subjectCode;
};

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n\n";
  
  DynamicArray<string> compareArray;
  DynamicArray<subject> subjectArray;
  bool found = false;
  bool isDuplicate = false;
  int lineCounter = 0;
  int validCounter = 0;
  int subjectCounter = 0;
  int duplicateCounter = 0;
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");           // open file stream
  if (!fin.good()) throw "I/O error";  

  // read the input file
  while (fin.good())
  {
    found = false;
    isDuplicate = false;

    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue; // skip blank lines
    
    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
  
    // Checking duplicate
    for(int i = 0; i < validCounter; i++)
    {
      if(compareArray[i] == term + section)
      {
        duplicateCounter++;
        isDuplicate = true;
        break;
      }
    }

    if(isDuplicate)
    {
      lineCounter++;
      continue;
    }
    
    compareArray[validCounter++] = term + section;
    
    // Listing subject
    for(int i = 0; i < subjectCounter; i++)
    {
      if(subjectArray[i].subjectCode == subjectCode)
      {
        (subjectArray[i].sectionCounter)++;
        found = true;
        break;
      }
    }
    
    if(!found)
    {
      subjectArray[subjectCounter].subjectCode = subjectCode;
      subjectArray[subjectCounter++].sectionCounter = 1;
    }

    // Progress bar
    cout << fixed << setprecision(1);
    cout << "\rProgressing " << (lineCounter++)/ 74410.0 * 100 << '%';
    cout.flush();
  }
  fin.close();

  // Alphabetic order
  for (int i = 0; i < subjectCounter; i++)
    for (int j = i + 1; j < subjectCounter; j++)
      if (subjectArray[j].subjectCode < subjectArray[i].subjectCode)
        swap(subjectArray[i], subjectArray[j]);
  
  // Display output
  cout << "\n\n----- DVC Schedule -----\n\n";
  for(int i = 0; i < subjectCounter; i++)
    cout << subjectArray[i].subjectCode << ", " << tab << subjectArray[i].sectionCounter << tab << "sections\n";

  cout << "\nThe number of lines: " << lineCounter << endl;
  cout << "The number of valid lines: " << validCounter << endl;
  cout << "The number of duplicate lines: " << duplicateCounter << endl;
  cout << "The number of subject: " << subjectCounter << endl;
}
