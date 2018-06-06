#include <iostream>
#include <string>
#include "ui/ui.h"
#include "repository/repository.h"

using namespace std;

int main ()
{
  auto repository = new Repository();
  Ui *ui = new Ui(repository);
  ui->showMenu();
  return 1;
}
