#include <iostream>
#include <fstream>
using namespace std;

struct node
{
  node* next;
  node* prev;
  string data;
  int d;
};

class door
{
private:
  node* head;
  node* tail;
  int length;
public:
  door()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

void deleteDoor();
/*
{
  node* temp;
  if( head !=nullptr)
  {
    temp = head;
    head = head->next;
    delete temp;
    if(head ==nullptr)
    tail = nullptr;
  }
}
*/

void priority(string instr, int data);
/*
{
  node* temp = new node;
  temp->d = data;
  temp->data = instr;
  temp->next = nullptr;
  if(head == nullptr)
  {
    head = temp;
    return;
  }
  node* cur = head;
  node* prev = nullptr;
  if(temp->d < cur->d)
  {
    temp->next = head;
    head = temp;
    return;
  }
  while(cur!=nullptr && temp->d > cur->d)
  {
    prev = cur;
    cur=cur->next;
  }
  prev->next = temp;
  temp->next = cur;
}
*/

void checkLock(bool& isOpen);
/*
{
  bool checkLock_ = false;
  while(head!=nullptr)
  {
    if(checkLock_ == false && (head->data == "open"                                   || head->data =="close" ))
    {
      if(head->data =="open")
        {
          isOpen = true;
        }
      else if(head->data =="close")
        {
          isOpen = false;
        }
    }
    if(head->data == "lock")
    {
      checkLock_ = true;
    }
      else if(head->data =="unlock")
      {
        checkLock_ = false;
      }
      deleteQueue();
      }
    }
*/
};
