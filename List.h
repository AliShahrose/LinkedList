#ifndef LIST_H
#define LISH_H

#include <string>

class List
{
private:
    struct Node
    {
        int value{};
        Node* next{};
    };

    Node* head{};
    int total{};
public:
    List (); // Constructor  
    List(List const& other); // Copy Constructor
    List(List&& other); // Move Constructor
    List& operator=(List const& other); // Copy Assignment Operator
    List& operator=(List&& other); //Move Assignment Operator
    ~List(); // Destructor

    bool isEmpty() const;
    int size() const;
    std::string print() const;

    void insertAtHead (int); // Itrative
    void insertAtTail (int); // Iterative
    void insertHelper(Node*, int);
    void insert(int); // Recursive (inserts at head and tail)
    void deleteAtHead();
    void deleteAtTail();
    void deleteAtIndex(int);
    int traverse(int);
};

#endif