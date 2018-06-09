#include <string>
#include <iostream>

#include "entry.h"
#include "repository.h"

Repository::Repository() {}
Repository::~Repository() {}
int Repository::compareTo(Entry first, Entry second) {return true;};
bool Repository::isFull() {return false;};
int Repository::length() {return 0;};
Entry Repository::retrive(string name) {};
void Repository::reset() {};
Entry Repository::next(Entry entry) {};

bool Repository::insert(Entry* entry)
{
  entries.add(entry->email, entry);
  return true;
}

void Repository::remove(string email)
{
  entries.remove(email);
}

// std::vector<Entry> Repository::list()
// {
//   return entries;
// }
