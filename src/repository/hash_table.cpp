#include <iostream>
#include <math.h>

#include "hash_table.h"
#include "list.h"

HashTable::HashTable() { this->keys = new List(); }

// HashTable::~HashTable() {
//   delete[] keys;
// }

int HashTable::hash(string key) {
  unsigned int h = 0;
  for (int i = 0; i < key.length(); i++)
    h = h * i + key[i];
  return h % 33;
}

void HashTable::add(Entry *value) {
  auto index = this->hash(value->email);

  if (this->keys->getElement(value->email) == NULL) {
    this->keys->insertFirst(value);
    this->values[index] = new List();
    this->values[index]->insertFirst(value);
  } else {
    this->values[index]->insertFirst(value);
  }
}

Entry *HashTable::get(string key) {
  auto index = this->hash(key);
  return this->values[index]->getElement(key)->data;
}

void HashTable::remove(string key) {
  auto index = this->hash(key);
  // here I should raise some exception
  auto elem = this->values[index]->getElement(key)->data;
  if (elem != NULL) {
    this->values[index]->deleteElement(elem);
    // if (this->values[index]->count() == 0) {
    //   this->keys->deleteElement(elem);
    // }
  }
}

int HashTable::count() {
  int num = 0;
  Node* curr;
  int index;
  for(curr = keys->head; curr != NULL; curr = curr->next) {
    index = this->hash(curr->data->email);
    num = num + this->values[index]->count();
  }
  return num;
}
