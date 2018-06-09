#include "list.h"
#include "entry.h"

Node::Node() {};
Node::~Node() {};

void List::createNode(Entry* value)
{
  Node *temp=new Node();
  temp->data=value;
  temp->next=NULL;
  if(head==NULL)
    {
      head=temp;
      tail=temp;
      temp=NULL;
    }
  else
    {
      tail->next=temp;
      tail=temp;
    }
}

void List::insertFirst(Entry* value)
{
  Node *temp=new Node();
  temp->data=value;
  temp->next=head;
  head=temp;
  }

Node* List::deleteFirst()
{
  Node* deletedNode = NULL;
  if (this->head != NULL) {
    deletedNode = this->head;
    this->head = head->next;
  }
  return deletedNode;
}

Node* List::deleteElement(Entry* element)
{
  auto *curr = this->head;
  Node *prev;
  while (curr != NULL and curr->data->email != element->email) {
    prev = curr;
    curr = curr->next;
  }
  if (prev == NULL) {
    curr = deleteFirst();
  }
  else if (curr != NULL) {
    prev->next = curr->next;
    curr->next = NULL;
  }
  return curr;
}

void List::sort()
{
  Node* curr;
  Node* prev;
    for(bool didSwap = true; didSwap; ) {
        didSwap = false;
        prev = head;
        for(curr = head; curr->next != NULL; curr = curr->next) {
                if(curr->data->score > curr->next->data->score) {
                        if (head == curr) {
                            head = curr->next;
                            curr->next = head->next;
                            head->next = curr;
                            prev = head;
                        } else {
                            prev->next = curr->next;
                            curr->next = prev->next->next;
                            prev->next->next = curr;
                        }
                        didSwap = true;
                } else if (head != curr) {
                    prev = prev->next;
                }
        }
    }
}

int List::count()
{
  if (this->head == NULL) {
    return 0;
  }

  int num = 1;
  Node* curr;
  for(curr = this->head; curr->next != NULL; curr = curr->next) {
    num = num + 1;
  }
  return num;
}
