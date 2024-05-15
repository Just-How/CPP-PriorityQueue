#include <iostream>
#include "door.h"
using namespace std;

void door::priority(string data, int d)
{
  node* tmp = new node;
  tmp->d = d;
  tmp->data = data;
  tmp->next = nullptr;
  if(head == nullptr)
  {
    head = tmp;
    return;
  }
  node* cur = head;
  node* prev = nullptr;
  if(tmp->d < cur->d)
  {
    tmp->next = head;
    head = tmp;
    return;
  }
  while(cur!=nullptr && tmp->d > cur->d)
  {
    prev = cur;
    cur=cur->next;
  }
  prev->next = tmp;
  tmp->next = cur;
};

void door::deleteDoor()
{
  if(head != nullptr)
  {
    node* tmp = head;
    head = head->next;
    delete tmp;
  if(head == nullptr)
    tail = nullptr;
  }
};

void door::checkLock(bool& isOpen)
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
      deleteDoor();
  }
};
