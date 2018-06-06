#pragma once

#include <vector>

#include "entry.h"


class Repository
{
public:
  Repository();
  ~Repository();
  void addEntry(Entry entry);
  void removeEntry(string name);
  std::vector<Entry> listEntries();
private:
  std::vector<Entry> entries = {};
};
