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
    this->keys->sort();
    this->values[index] = new List();
    this->values[index]->insertFirst(value);
    this->values[index]->sort();
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
    if (this->values[index]->count() == 0) {
      this->keys->deleteElement(elem);
    }
  }
}

int HashTable::count() {
  int num = 0;
  Node *curr;
  int index;
  for (curr = keys->head; curr != NULL; curr = curr->next) {
    index = this->hash(curr->data->email);
    num = num + this->values[index]->count();
  }
  return num;
}

HashTableIterator::HashTableIterator(HashTable *ht) {
  this->ht = ht;
  currentKey = ht->keys->head;
  current = NULL;
}

bool HashTableIterator::valid() {
  if (this->currentKey == NULL) {
    return false;
  }
  if (this->current == NULL) {
    // cout << "current is NULL" << endl;
    return false;
  }
  if (this->currentKey->next == NULL) {
    // cout << "currentKey->next is NULL" << endl;
    return false;
  }
  if (this->current == NULL) {
    // cout << "current is NULL" << endl;
    return false;
  }
  return true;
}

Node* HashTableIterator::next() {
  if (this->currentKey == NULL) {
    if (this->ht->keys->head == NULL) {
      return NULL;
    }
    this->currentKey = ht->keys->head;
    auto index = this->ht->hash(currentKey->data->email);
    this->current = this->ht->values[index]->head;
    return this->current;
  }
  if (this->current == NULL) {
    auto index = this->ht->hash(currentKey->data->email);
    this->current = this->ht->values[index]->head;
    return this->current;
  }
  if (this->current->next == NULL) {
    if (this->currentKey->next != NULL) {
      this->currentKey = this->currentKey->next;
      auto index = this->ht->hash(currentKey->data->email);
      this->current = this->ht->values[index]->head;
    } else {
      return NULL;
    }
  } else {
    this->current = this->current->next;
  }
  return this->current;
}

Node *HashTableIterator::getCurrent() {
  return this->current;
}
