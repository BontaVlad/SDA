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
  int *next;
public:
  HashTable();
  // ~HashTable();
  int hash(string word);
  void add(Entry* value);
  void remove(string key);
  Entry* get(string key);
  int count();
};

// class HashTableIterator
// {
//   friend class HashTableIterator;
// public:
//   HashTable* ht;
//   int current;
//   Node* currentNode;
//   HashTableIterator(HashTable* ht)
//   {
//     this->ht = ht;
//     currentNode = NULL;
//     current = 0;
//   }

//   bool valid()
//   {
//     return this->current <= M;
//   }

//   Entry* next()
//   {
//     if (!valid()) {return NULL;}
//     if (currentNode == NULL) {
//       cout << "node is null" << endl;
//       while(ht->keys[this->current] == "")
//         {
//           cout << current << endl;
//           this->current++;
//         }
//       currentNode = ht->values[this->current]->head;
//     }
//     else if (currentNode->next == NULL){
//       cout << "node->next is null" << endl;
//       while(ht->keys[this->current] == "")
//         {
//           this->current++;
//         }
//       currentNode = ht->values[this->current]->head;
//     }
//     else {
//       cout << "node->next is not null" << endl;
//       currentNode = currentNode->next;
//     }
//     return currentNode->data;
//   }
// };
