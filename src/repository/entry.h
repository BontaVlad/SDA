#pragma once

#include <string>

using namespace std;

class Entry
{
 public:
  int score;
  string name;
  string email;

  Entry(int score, string name, string email);
  ~Entry();
};
