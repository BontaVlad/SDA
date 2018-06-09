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
public:
  Node *head, *tail;
  List()
  {
    head=NULL;
    tail=NULL;
  }
  void createNode(Entry* value);
  void insertFirst(Entry* value);
  Node* deleteFirst();
  Node* deleteElement(Entry* element);
  Node* getElement(string email);
  void sort();
  int count();
};

