#pragma once

#include <functional>
#include <vector>

#include "entry.h"


class Repository
{
public:
  Repository();
  ~Repository();
  int compareTo(Entry first, Entry second);
  bool isFull();
  int length();
  bool insert(Entry entry);
  Entry retrive(string name);
  void remove(string name);
  void reset();
  Entry next(Entry entry);
  std::vector<Entry> list();
private:
  const int MAX_ITEMS = 100;
  std::function<int(Entry, Entry)> relation;
  std::vector<Entry> entries = {};
};
