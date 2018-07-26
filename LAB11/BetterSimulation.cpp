// identification
// Programmer: Hongseok Jang
// Programmer's ID: 1560046

#include <iostream>
#include <fstream>
using namespace std;

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#include "Queue.h"
#include "DynamicArray.h"
#include "PriorityQueue.h"

int getRandomNumberOfArrivals(double);

struct customer
{
  char IdTag;
  int arrivalTime;
  int serviceEndTime;
};

struct service
{
  int serverNumber;
  int serviceEnd;
  bool operator<(const service& ref) const {return ref.serviceEnd < serviceEnd;}
};

int main()
{
  // identification
  cout << "Programmer: Hongseok Jang\n";
  cout << "Programmer's ID: 1560046\n";
  cout << "File: " << __FILE__ << "\n";
  
  srand(time(0));

  // read the input values from a text file, one per line, in the order specified above.
  ifstream fin;
  fin.open("simulation.txt");
  if(!fin.good())
    throw "I/O ERROR";
  char input[100];
  for(int i = 0; fin.good(); i++)
    fin.get(input[i]);
  fin.close();

  const int nServer = atoi(strtok(input,"\n"));
  const double avgArrivalRate = atof(strtok(0,"\n"));
  const int lengthMax = atoi(strtok(0,"\n"));
  const int serviceMin = atoi(strtok(0,"\n"));
  const int serviceMax = atoi(strtok(0,"\n"));
  const int closeTime = atoi(strtok(0,"\n"));

  cout << "\nnumber of servers: \t" << nServer;
  cout << "\ncustomer arrival rate: \t" << avgArrivalRate << " per minute, for " << closeTime << " minutes";
  cout << "\nmaximum queue length: \t" << lengthMax;
  cout << "\nminimum service time: \t" << serviceMin << " minutes";
  cout << "\nmaximum service time: \t" << serviceMax << " minutes\n";
  
  // declare and create and assign arrays and queues to be used in the solution
  int nArrive;
  int nQueue = 0;
  Queue<customer> waiting;
  Queue<customer> tracker;
  DynamicArray<customer> workingOn(nServer);
  PriorityQueue<service> eventQueue(nServer);
  
  for(int i = 0; i < nServer; i++)
    workingOn[i].IdTag = ' ';
  
  // the clock time loop
  for (int time = 0;; time++)
  {
    // handle all services scheduled to complete at this clock time
    for (int i = 0; i < nServer; i++)
      if (!eventQueue.empty())
        if (eventQueue.top().serviceEnd == time)
        {
          workingOn[eventQueue.top().serverNumber].IdTag = ' ';
          eventQueue.pop();
        }

    if (time <= closeTime)
    {
      nArrive = getRandomNumberOfArrivals(avgArrivalRate);
      for (int i = 0; i < nArrive; i++)
        if (waiting.size() < lengthMax)
        {
          customer newCustomer;
          newCustomer.arrivalTime = time;
          newCustomer.IdTag = 65 + ((nQueue++) % 26);
          waiting.push(newCustomer);
        }
    }

    // for idle servers, move customer from wait queue and begin service
    for (int i = 0; i < nServer; i++)
      if (workingOn[i].IdTag == ' ' && !waiting.empty())
      {
        workingOn[i] = waiting.front();
        waiting.pop();
        workingOn[i].serviceEndTime = time + serviceMin + rand()%(serviceMax - serviceMin + 1);
        eventQueue.push(service{i, workingOn[i].serviceEndTime});
      }
    
    tracker = waiting;
      
    cout << "\nTime: " << time;
    cout << "\n---------------------------";
    cout << "\nserver now serving wait queue";
    cout << "\n------ ----------- ----------";
    for (int i = 0; i < nServer; i++)
    {
      cout << endl;
      cout.width(3); cout << i;
      cout.width(10); cout << workingOn[i].IdTag;
      if (i == 0)
      {
        cout.width(6); cout << ' ';
        while(!tracker.empty())
        {
          cout << tracker.front().IdTag;
          tracker.pop();
        }
      }
    }
    cout << "\n---------------------------\n";
    
    if (time > closeTime && waiting.empty() && eventQueue.empty())
      break;
    cout << "Press ENTER to continue...";
    cin.get();
  }
  cout << "Done!\n";
}

int getRandomNumberOfArrivals(double averageArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-averageArrivalRate);
  for (double randomValue = (double)rand() / RAND_MAX; 
    (randomValue -= probOfnArrivals) > 0.0; 
    probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
  return arrivals;
}
