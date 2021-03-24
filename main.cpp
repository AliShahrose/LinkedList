#include "List.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    List l{};
    l.insert(3);
  l.insertAtHead(2);
  l.insertAtHead(1);
  l.insertAtHead(0);
  l.insertAtTail(4);
  l.insert(5);
    cout << l.traverse(3) << endl;
    // l.deleteAtHead();
    // l.deleteAtTail();
    // l.deleteAtIndex(2);

    cout << l.print() << endl;
    cout << l.size() << endl;
    return 0;
}