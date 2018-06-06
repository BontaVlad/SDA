#include <string>

#include "entry.h"
#include "repository.h"

Repository::Repository() {}
Repository::~Repository() {}
void Repository::addEntry(Entry entry)
{
  entries.push_back(entry);
}

void Repository::removeEntry(string name)
{
  entries.erase(entries.begin());
}

std::vector<Entry> Repository::listEntries()
{
  return entries;
}
