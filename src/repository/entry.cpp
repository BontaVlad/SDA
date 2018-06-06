#include "entry.h"

Entry::Entry(int score, string name, string email) {
  this->score = score;
  this->name = name;
  this->email = email;
}
Entry::~Entry(){}
