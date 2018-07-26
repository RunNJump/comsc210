// identification
// Programmer: Hongseok Jang
// Programmer's ID: 156004

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
using namespace std;

#include <cstring> // strtok

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n\n";

  char* token;
  char buf[1000];
  char found = false;
  map<string, set<string> > container;
  
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
    
    container[term + '-' + section].insert(course);
  }
  fin.close();
  
  map<string, set<string> >::iterator i;
  for (i = container.begin(); i != container.end(); i++)
    if (i->second.size() != 1)
    {
      found = true;
      cout << "There are " << i->second.size() << " different courses assigned as " << i->first << endl;
    }

  if (!found)
    cout << "There are no invalid courses that have same term and same section\n";
}
