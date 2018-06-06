#include <iostream>
#include <string>
#include "ui/ui.h"

using namespace std;

int main ()
{
  Ui *ui = new Ui();

  ui->showMenu();
  return 1;
}
