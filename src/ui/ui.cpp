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
    cout << "8\"\"\"\"8                        8\"\"\"\"8                           "<< endl;
    cout << "8      eeee eeeee eeeee  eeee 8    8   eeeee eeeee eeeee  eeeee"<< endl;
    cout << "8eeeee 8  8 8  88 8   8  8    8eeee8ee 8  88 8   8 8   8  8   8"<< endl;
    cout << "    88 8e   8   8 8eee8e 8eee 88     8 8   8 8eee8 8eee8e 8e  8"<< endl;
    cout << "e   88 88   8   8 88   8 88   88     8 8   8 88  8 88   8 88  8"<< endl;
    cout << "8eee88 88e8 8eee8 88   8 88ee 88eeeee8 8eee8 88  8 88   8 88ee8"<< endl;
    cout <<"================================================================" << endl;

}

void Ui::showMenu() {
  char cmd;
  do {
    showHeader();
    cout << "Main menu:\n";
    cout << "1. Add a new entry\n";
    cout << "2. Remove an entry\n";
    cout << "3. View all entries\n";
    cout << "4. Search for an entry\n";
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
       << "Adding an entry\n"
       <<"----------------\n";

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Enter the score of the entry: ";
  std::getline(std::cin, score);

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Enter the name of the entry: ";
  std::getline(std::cin, name);

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Enter the email of the entry: ";
  std::getline(std::cin, email);

  auto entry = new Entry(std::stoi(score), name, email);
  repo->addEntry(*entry);
  cout << "Entry added";
  cout << "\n\n";
  return;
}

void handleRemoveEntry(){
  cout << "\n\n"
       << "Removing an entry\n"
       <<"----------------\n";
  cout << "\n\n";
  return;
}


void Ui::handleListEntries(){
  cout << "\n\n"
       << "Listing entries\n"
       <<"----------------\n";
  auto entries = repo->listEntries();

  cout << setw(7) << "Sl. No:" << setw(15) << "Name" << setw(15) << "Email" << endl << endl;
  std::for_each(entries.begin(), entries.end(), [](const auto &e) {
                                                  // cout << e.score;
                                                  // cout << e.name;
                                                  // cout << e.email;
        cout << setw(7) << e.score << setw(15) << e.name << setw(15) << e.email << endl;
  });
  // cout << setw(7) << 1 << setw(15) << "January" << setw(15) << "Abhilash" << endl;
  // cout << setw(7) << 2 << setw(15) << "Februaury" << setw(15) << "Anandan" << endl;
  // cout << setw(7) << 3 << setw(15) << "March" << setw(15) << "Abhilash" << endl;
  // cout << setw(7) << 4 << setw(15) << "April" << setw(15) << "Anandan" << endl;
  cout << "\n\n";
  return;
}


void handleSearchEntry(){
  cout << "\n\n"
       << "Searching for an entry\n"
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
