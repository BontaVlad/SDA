#pragma once
#include "list.h"
#define M 1000
#include <iostream>

class HashTableIterator;

class HashTable
{
  friend class HashTableIterator;
private:
  List *keys;
  List* values[M];
public:
  HashTable();
  // ~HashTable();
  int hash(string word);
  void add(Entry* value);
  void remove(string key);
  Entry* get(string key);
  int count();
};

class HashTableIterator
{
  friend class HashTable;
public:
  HashTableIterator(HashTable* ht);
  HashTable* ht;
  Node* currentKey;
  Node* current;
  Node* next();
  bool valid();
  Node* getCurrent();

};
