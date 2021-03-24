#include "List.h"
#include <iostream>
#include <string>
List::List() : head{nullptr} {}

List::List(List const& other)
{
  if(other.head == nullptr)
  {
      head = nullptr;
  }
  else
  {
    Node* otherPtr = other.head;
    Node* thisPtr = new Node{other.head->value, nullptr};
    head = thisPtr;
    otherPtr = other.head->next;

    while(otherPtr != nullptr)
    {
      thisPtr->next = new Node{otherPtr->value, nullptr};
      thisPtr = thisPtr->next;
      otherPtr = otherPtr->next;
    }
  }
}

List::List(List&& other) : head{nullptr}
{
  std::swap(head, other.head);
}

List& List::operator=(List const& other)
{
  new (this) List{other};
  return *this;
}

List& List::operator=(List&& other)
{
  std::swap(head, other.head);
  return *this;
}

List::~List()
{
  Node* temp{nullptr};
  Node* del{nullptr};

  temp = head;

  while(temp != nullptr)
  {
    del = temp;
    temp = temp->next;
    delete del;
  }
}

bool List::isEmpty() const
{
  return (head == nullptr);
}

int List::size() const
{
  int count{};
  Node* temp{head};
  while(temp != nullptr)
  {
    temp = temp->next;
    count++;
  }
  return count;
}

std::string List::print() const
{
  if (isEmpty())
	{
		std::string empty{};
		return empty;
	}
  else
  {
    std::string myList{};
    Node* temp = head;

    while (temp != nullptr)
    {
      myList += (std::to_string(temp->value)) + " ";
      temp = temp->next;
    }
    myList.pop_back();
    return myList;
  }
}

void List::insertAtHead (int val)
{
    Node* ptr = new Node{val, head};
    head = ptr;
    total++;
}

void List::insertAtTail(int val)
{
  Node* ptr = new Node{val, nullptr};
  Node* temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }
  temp->next = ptr;
  total++;
}

void List::insertHelper (Node * ptr, int val)
{
  Node *temp{ptr->next};

  if (ptr->next == nullptr)
  {
    ptr->next = new Node{val, nullptr};
  }
  else if (val <= temp->value)
  {
    ptr->next = new Node{val, temp};
  }
  else
  {
    insertHelper(temp, val);
  }
}

void List::insert (int val)
{
  total++;
  if (head == nullptr || val <= head->value)
  {
    head = new Node{val, head};
  }
  else
    {
      insertHelper(head, val);
    }
}

void List::deleteAtHead ()
{
  Node* temp = head;
  head = temp->next;
  delete temp;
  total--;
}

void List::deleteAtTail ()
{
  if(head->next == nullptr)
  {
    deleteAtHead ();
  }
  else
  {
    Node *temp = head;
    Node *temp1 = head->next;

    while (temp->next != nullptr)
    {
      temp = temp->next;
      temp1 = temp->next;

      if (temp->next->next == nullptr)
      {
        delete temp1;
        total--;
        temp->next = nullptr;
      }
    }
  }
}

void List::deleteAtIndex (int index)
{
    if (index < 0 || index >=total)
    {
        // Do nothing
    }
    else if (index == 0)
    {
        deleteAtHead();
    }
    else
    {
      Node *temp = head->next;
      Node *temp1 = head;

      for (int i = 0; i < index - 1; i++)
      {
          temp = temp->next;
          temp1 = temp1->next;
      }

      temp1->next = temp->next;
      delete temp;
      total--;
    }
}

int List::traverse(int index)
{
  int count{};
  if(index < 0 || index > total - 1)
  {
    // Do nothing
  }
  else if (count < index)
  {
    Node* temp{head};
    while(count < index)
    {
      temp = temp->next;
      count++;
    }
    return temp->value;
  }
}