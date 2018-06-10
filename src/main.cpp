
#include <iostream>
#include <string>
#include "ui/ui.h"
#include "repository/repository.h"
#include "repository/hash_table.h"

using namespace std;

int main ()
{
  HashTable* ht = new HashTable();
  auto repository = new Repository(ht);
  Ui *ui = new Ui(repository);
  ui->showMenu();
  return 1;
}
