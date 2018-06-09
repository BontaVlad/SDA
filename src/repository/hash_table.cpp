#include <math.h>
#include <iostream>

#include "hash_table.h"
#include "list.h"

HashTable::HashTable()
{
  keys = new string[M];
	for (int i = 0; i < M; i++) {
		keys[i] = "";
	}
}

HashTable::~HashTable() {
  delete[] keys;
}

int HashTable::hash(string key)
{
  unsigned int h=0;
  for (int i=0;i<key.length();i++)
    h=h*i+key[i];
  return h%33;
}

void HashTable::add(string key, Entry* value)
{
  auto index = this->hash(key);
  if (this->keys[index] == "") {
    this->keys[index] = key;
    this->values[index] = new List();
    this->values[index]->insertFirst(value);
  } else {
    this->values[index]->insertFirst(value);
  }
}

Entry* HashTable::get(string key)
{
  auto index = this->hash(key);
  if (keys[index] == "") {
    return NULL;
  }
  return this->values[index]->getElement(key)->data;
}


void HashTable::remove(string key)
{
  auto index = this->hash(key);
  // here I should raise some exception
  if (keys[index] == "") {return;}
  auto elem = this->values[index]->getElement(key)->data;
  if (elem != NULL) {
    this->values[index]->deleteElement(elem);
    if (this->values[index]->count() == 0) {
      keys[index] = "";
    }
  }
}

int HashTable::count()
{
  int num = 0;
  for (int i = 0; i < M; i++) {
    if (this->keys[i] != ""){
      num = num + this->values[i]->count();
    }
  }
  return num;
}
