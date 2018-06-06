#pragma once
#include <string>

#include "../repository/repository.h"


class Ui
{
public:
  Repository *repo;
  Ui(Repository *repo);
  ~Ui();

  void showMenu();

  void executeMenu(char cmd);
  void handleAddingEntry();
  void handleListEntries();
};
