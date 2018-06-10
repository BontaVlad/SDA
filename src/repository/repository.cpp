#include <string>
#include <iostream>

#include "entry.h"
#include "repository.h"

Repository::Repository(HashTable* ht) {
  this->entries = ht;
}
// Repository::~Repository() {}
int Repository::compareTo(Entry first, Entry second) {return true;};
bool Repository::isFull() {return false;};
int Repository::length() {
  return this->entries->count();
};
Entry Repository::retrive(string name) {};

bool Repository::insert(Entry* entry)
{
  entries->add(entry);
  return true;
}

void Repository::remove(string email)
{
  entries->remove(email);
}

HashTableIterator* Repository::list()
{
  HashTableIterator* iter = new HashTableIterator(entries);
  iter->next();
  return iter;
}
