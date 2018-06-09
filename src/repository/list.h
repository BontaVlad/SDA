#pragma once
#include "entry.h"


class Node
{

public:
  Node();
  ~Node();
  Entry *data;
  Node *next;
};

class List
{
private:
  Node *head, *tail;
public:
  List()
  {
    head=NULL;
    tail=NULL;
  }
  void createNode(Entry* value);
  void insertFirst(Entry* value);
  Node* deleteFirst();
  Node* deleteElement(Entry* element);
  void sort();
  int count();
};

