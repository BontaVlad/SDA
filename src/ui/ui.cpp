#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#include "ui.h"
#include "../repository/entry.h"

Ui::Ui(Repository *repo) {
  this->repo = repo;
}

Ui::~Ui() {
  delete(this->repo);
}

void showHeader()
{
    cout <<"================================================================" << endl;
    cout << "8\"\"\"\"8                        8\"\"\"\"8                   " << endl;
    cout << "8      eeee eeeee eeeee  eeee 8    8   eeeee eeeee eeeee  eeeee" << endl;
    cout << "8eeeee 8  8 8  88 8   8  8    8eeee8ee 8  88 8   8 8   8  8   8" << endl;
    cout << "    88 8e   8   8 8eee8e 8eee 88     8 8   8 8eee8 8eee8e 8e  8" << endl;
    cout << "e   88 88   8   8 88   8 88   88     8 8   8 88  8 88   8 88  8" << endl;
    cout << "8eee88 88e8 8eee8 88   8 88ee 88eeeee8 8eee8 88  8 88   8 88ee8" << endl;
    cout <<"================================================================" << endl;

}

void Ui::showMenu() {
  char cmd;
  do {
    showHeader();
    cout << "Main menu:\n";
    cout << "1. Add a new citizen\n";
    cout << "2. Remove an citizen\n";
    cout << "3. View all entries\n";
    cout << "4. Search for an citizen\n";
    cout << "0. Exit\n\n";

    cout << "Please enter comand: ";
    cin >> cmd;

    this->executeMenu(cmd);
    cin.ignore(3, '\n');
  } while (cmd != '0');
}

void Ui::handleAddingEntry(){
  string score;
  string name;
  string email;
  cout << "\n\n"
       << "Adding a new citizen\n"
       <<"---------------------\n";

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Enter the score of the citizen: ";
  std::getline(std::cin, score);

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Enter the name of the citizen: ";
  std::getline(std::cin, name);

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Enter the email of the citizen: ";
  std::getline(std::cin, email);

  auto entry = new Entry(std::stoi(score), name, email);
  repo->insert(*entry);
  cout << "Citizen added";
  cout << "\n\n";
  return;
}

void handleRemoveEntry(){
  string name;
  cout << "\n\n"
       << "Removing an citizen\n"
       <<"----------------\n";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Enter the name of the citizen: ";
  std::getline(std::cin, name);
  cout << "\n\n";
  return;
}

void Ui::handleInsertTestData() {
  auto entry_1 = new Entry(1, "Zhāng Li", "babyboy@yahoo.com");
  auto entry_2 = new Entry(10, "Wang Chu", "i_hate_monday@gmail.com");
  auto entry_4 = new Entry(30, "Lao Liew", "nospam@hotmail.com");
  auto entry_5 = new Entry(20, "Yang Gi", "notworthy@gmail.com");
  auto entry_3 = new Entry(10, "Wu Tang", "serious_sam@gmail.com");
  auto entry_6 = new Entry(999, "Mu Lan", "disney@disney.com");
  auto entry_7 = new Entry(12345, "Zhou Ma", "kill_bill@movie.com");

  repo->insert(*entry_1);
  repo->insert(*entry_2);
  repo->insert(*entry_3);
  repo->insert(*entry_4);
  repo->insert(*entry_5);
  repo->insert(*entry_6);
  repo->insert(*entry_7);
  cout << "Created agents of the goverment" << endl;
}


void Ui::handleListEntries(){
  const int spacing = 30;
  cout << "\n\n"
       << "Listing entries\n"
       <<"----------------\n";
  auto entries = repo->list();

  cout << setw(spacing) << "Sl. No" << setw(spacing) << "Name" << setw(spacing) << "Email" << endl << endl;
  std::for_each(entries.begin(), entries.end(), [](const auto &e) {
        cout << setw(spacing) << e.score << setw(spacing) << e.name << setw(spacing) << e.email << endl;
  });
  cout << "\n\n";
  return;
}


void handleSearchEntry(){
  cout << "\n\n"
       << "Searching for an citizen\n"
       <<"----------------\n";

  cout << "\n\n";
  return;
}

void Ui::executeMenu(char cmd) {
  switch (cmd) {
  case '1': {
    handleAddingEntry();
    break;
  }
  case '2': {
    handleRemoveEntry();
    break;
  }
  case '3': {
    handleListEntries();
    break;
  }
  case '4': {
    handleSearchEntry();
    break;
  }
  case '9': {
    handleInsertTestData();
    break;
  }
  case '0': {
    return;
    break;
  }
  default: {
    cout << "Invalid command! \n\n";
    break;
  }
  }
}
