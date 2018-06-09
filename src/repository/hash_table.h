#pragma once
#include "list.h"
#define M 1000

class HashTableIterator;

class HashTable
{
  friend class HashTableIterator;
private:
  string *keys;
  List* values[M];
  int *next;
public:
  HashTable();
  ~HashTable();
  int hash(string word);
  void add(string key, Entry* value);
  void remove(string key);
  Entry* get(string key);
  int count();
};

class HashTableIterator
{
  friend class HashTableIterator;
public:
  HashTable* ht;
  int current;
  Node* currentNode;
  HashTableIterator(HashTable* ht)
  {
    this->ht = ht;
    currentNode = NULL;
    current = 0;
  }

  bool valid()
  {
    return this->current <= M;
  }

  Entry* next()
  {
    if (!valid()) {return NULL;}

    if (currentNode == NULL) {
      while(ht->keys[this->current] == "")
        {
          this->current++;
        }
      currentNode = ht->values[this->current]->head;
    }
    else if (currentNode->next == NULL){
      while(ht->keys[this->current] == "")
        {
          this->current++;
        }
      currentNode = ht->values[this->current]->head;
    }
    else {
      currentNode = currentNode->next;
    }
    return currentNode->data;
  }
};
