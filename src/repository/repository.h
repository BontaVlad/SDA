#pragma once

#include <functional>
#include "hash_table.h"

#include "entry.h"

class Iterator;

class Repository
{
  friend class Iterator;
public:
  Repository();
  ~Repository();
  int compareTo(Entry first, Entry second);
  bool isFull();
  int length();
  bool insert(Entry* entry);
  Entry retrive(string name);
  void remove(string name);
  void reset();
  Entry next(Entry entry);
  /* std::vector<Entry> list(); */
private:
  const int MAX_ITEMS = 100;
  std::function<int(Entry, Entry)> relation;
  HashTable entries;
  ;
};


class Iterator
{
  friend class Repository;
 private:
  int current;
  Repository* repo;

  Iterator(Repository* repo)
  {
    this->current = 0;
    this->repo = repo;
  }

	/* bool valid(){ */
	/* 	if(current < M && dict->keys[current] != "") */
	/* 		return true; */
	/* 	return false; */
	/* } */

  /* int getNext() */
  /* { */
  /*   while(repo->items[this->current] == "") */
  /*   { */
  /*       this->current++; */
  /*   } */
  /* } */

  /* void first() { */
  /*   current = 0; */
  /*   while(repo->items[current] == "") */
  /*     { */
  /*       current++; */
  /*     } */
  /* } */

};
