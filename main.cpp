#include <iostream>
#include <fstream>
#include "door.h"
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char *argv[])
{
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));
  //ifstream input("input3.txt");
  //ofstream output("output3.txt");
  
door pq;
  int priority;
  string line, data = "";
  bool isOpen = false;
  while(getline(input, line))
  {
    if(line.find("the door") != -1                                 && line.find("(") !=-1 && line.find("(") !=-1)
    {
      data = line.substr(0, line.find("(")-1);
      priority = stoi(line.substr(line.find("(")+1,                               line.find(")") - line.find("(") )); 
      if(data.find("close") != -1)
      {
        pq.priority("close", priority);
      }
      else if(data.find("open") != -1)
      {
        pq.priority("open", priority);
      }
      else if(data.find("unlock") != -1){
        pq.priority("unlock", priority);
        
      }   
      else if(data.find("lock") != -1){
        pq.priority("lock", priority);
      }
    }
  }
  pq.checkLock(isOpen);
  if(isOpen==true)
    output << "the door is open ";
  else if(isOpen==false)
  {
    output << "the door is closed ";
  }
}