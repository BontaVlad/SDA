#pragma once

#include "entry.h"

class HashTableIterator;

class HashTable {
  friend class HashTableIteraror;
private:
  int *keys;
  Entry *values;
  int *next;
  int firstFree;

  int getFirstFree() {
    return firstFree;
  }
};


class HashTableIterator {
  friend class HashTable;
private:
  int current;
  HashTable* table;

public:
  HashTableIterator(HashTable* table) {
    this->current = 0;
    this->table = table;
  }

  // void first() {
  //   current = 0;
  //   while(table->keys[current] == -1) {

  //     }
  // }
};
