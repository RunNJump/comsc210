// identification
// Programmer: Hongseok Jang
// Programmer's ID: 156004

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Node
{
  string name;
  bool isVisited;
  list<int> neighbors;
};

queue<int> doBreadthFirstSearch(int iOriginNode, vector<Node>& database)
{
  queue<int> searchOrder; // return this queue of indices
  stack<int> toDO;
  for (auto i = database.begin(); i != database.end(); i++)
    i->isVisited = false;
  toDO.push(iOriginNode);

  while (!toDO.empty())
  {
    int top = toDO.top();
    toDO.pop();
    if (!database[top].isVisited)
    {
      database[top].isVisited = true;
      searchOrder.push(top);
      for (auto i = database[top].neighbors.rbegin(); i != database[top].neighbors.rend(); i++)
        if (!database[*i].isVisited)
          toDO.push(*i);
    }
  }
  return searchOrder;
}

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n\n";

  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";  

  // process the input file
  vector<Node> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    fin.ignore(1000, 10); // skip the line with distance
    fin.ignore(1000, 10); // skip the separator

    // add vertices for new cities included in the edge
    int iToNode = -1, iFromNode = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) // not in database yet
    {
      // store the node if it is new
      Node fromNode = {fromCity};
      database.push_back(fromNode);
    }
    iFromNode = i; 

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) // not in vector yet
    {
      // store the node if it is new
      Node toNode = {toCity};
      database.push_back(toNode);
    }
    iToNode = i; 

    // store bi-directional edges
    database[iFromNode].neighbors.push_back(iToNode);
    database[iToNode].neighbors.push_back(iFromNode);
  }
  fin.close();
  cout << "Input file processed\n";

  while (true)
  {
    // get the start city for the search
    string startCity;
    cout << "\nEnter the start city [blank to exit]: ";
    getline(cin, startCity);
    if (startCity.length() == 0) break;

    // find the start city
    int i;
    for (i = 0; i < database.size(); i++)
      if (database[i].name == startCity)
        break;

    if (i == database.size())
    {
        cout << "There is no city in the database.\n\n";
        continue;
    }

    // BFS result by copy-pop
    cout << "DFS";
    for (queue<int> q = doBreadthFirstSearch(i, database); !q.empty(); q.pop())
      cout  << '-'<< database[q.front()].name;
    cout << endl;
  }
  cout << "Done!\n";
}
