// identification
// Programmer: Hongseok Jang
// Programmer's ID: 156004

#include <iostream>
#include <array>
#include <map>
#include <string>
#include <fstream>
using namespace std;

#include <cstring> // strtok
#include <cstdlib> // atoi

struct Term
{
  string term;
  string termN;
  bool operator<(const Term& ref){return termN < ref.termN;}
  Term(string term = "", string termN = ""):term(term), termN(termN){}
};

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n\n";

  char* token;
  char buf[1000];
  array<string, 10000> alreadySeen; // for duplicate check
  map<string, Term> container;

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
    const int sectionN = atoi(section.c_str()); // Make section integer
    string termN(term.begin() + term.find('2'), term.end());
    
    if (term[1] == 'p')
      termN += '1';
    else if (term[1] == 'u')
      termN += '2';
    else
      termN += '3';

    if (alreadySeen[sectionN].find(term) == string::npos)
      alreadySeen[sectionN] += term;
    else
      continue;

    Term newTerm(term, termN);

    if (container[course].termN < termN)
      container[course] = newTerm;
  }
  fin.close();
  
  while (true)
  {
    cout << "Enter a course name [ex.COMSC-210][X to quit]: ";
    cin.getline(buf, 1000);
    if (buf[0] == 'X' || buf[0] == 'x')
      break;
    if (container.find(buf) != container.end())
      cout << buf << " was last offered in " << container[buf].term << endl << endl;
    else
      cout << buf << " could not be found as far back as the year 2000\n\n";
  }
}
