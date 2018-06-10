#pragma once

#include <functional>
#include "hash_table.h"

#include "entry.h"

class Repository
{
public:
  Repository(HashTable* ht);
  /* ~Repository(); */
  int compareTo(Entry first, Entry second);
  bool isFull();
  int length();
  bool insert(Entry* entry);
  Entry retrive(string name);
  void remove(string name);
  void reset();
  Entry next(Entry entry);
  HashTableIterator* list();
private:
  std::function<int(Entry, Entry)> relation;
  HashTable* entries;
  ;
};
