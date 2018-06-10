#include "list.h"
#include "entry.h"
#include <iostream>

Node::Node(){};
Node::~Node(){};

void List::createNode(Entry *value) {
  Node *temp = new Node();
  temp->data = value;
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
    tail = temp;
    temp = NULL;
  } else {
    tail->next = temp;
    tail = temp;
  }
}

void List::insertFirst(Entry *value) {
  Node *temp = new Node();
  temp->data = value;
  temp->next = head;
  head = temp;
}

Node *List::deleteFirst() {
  Node *deletedNode = NULL;
  if (this->head != NULL) {
    deletedNode = this->head;
    this->head = head->next;
  }
  return deletedNode;
}

Node *List::deleteElement(Entry *element) {
  Node *curr = this->head;
  Node *prev = NULL;
  while (curr != NULL and curr->data->email != element->email) {
    prev = curr;
    curr = curr->next;
  }
  if (prev == NULL) {
    curr = deleteFirst();
  } else if (curr != NULL) {
    prev->next = curr->next;
    curr->next = NULL;
  }
  return curr;
}

Node *List::getElement(string email) {
  auto *curr = this->head;
  Node *prev;
  while (curr != NULL) {
    if (curr->data->email == email) {
      return curr;
    }
    prev = curr;
    curr = curr->next;
  }
  return NULL;
}

/* Bubble sort the given linked list */
void List::sort() {
  bool swapped;
  Node *current;
  Node *lptr = NULL;
  Entry *tmp = NULL;

  if (this->head == NULL)
    return;

  do {
    swapped = false;
    current = this->head;
    while (current->next != lptr) {
      if (current->data->score == current->next->data->score) {
        swapped = false;
      } else if (current->data->score < current->next->data->score) {
        tmp = current->data;
        current->data = current->next->data;
        current->next->data = tmp;
        swapped = true;
      }
      current = current->next;
    }
    lptr = current;
  } while (swapped);
}

// void List::sort() {
//   Node *curr;
//   Node *prev;
//   for (bool didSwap = true; didSwap;) {
//     didSwap = false;
//     prev = this->head;
//     for (curr = this->head; curr->next != NULL; curr = curr->next) {
//       if (curr->data->score > curr->next->data->score) {
//         cout << "curr bigger" << endl;
//         //   cout << curr->next->data->score << endl;
//         if (this->head == curr) {
//           cout << "head == curr" << endl;
//           this->head = curr->next;
//           curr->next = head->next;
//           this->head->next = curr;
//           prev = head;
//         } else {
//           cout << "head not eq curr" << endl;
//           cout << curr->next << endl;
//           prev->next = curr->next;
//           curr->next = prev->next->next;
//           prev->next->next = curr;
//         }
//         didSwap = true;
//       } else if (head != curr) {
//         prev = prev->next;
//       }
//     }
//   }
// }

int List::count() {
  int num = 0;
  Node *curr;
  for (curr = this->head; curr != NULL; curr = curr->next) {
    num = num + 1;
  }
  return num;
}
