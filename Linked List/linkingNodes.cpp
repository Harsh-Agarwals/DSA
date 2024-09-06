#include<bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node* next;
  
  Node(int val): value(val), next(nullptr) {}
};

void printList(Node* head) {
  Node* current = head;
  while(current != nullptr) {
    cout << current->value << ", " << current->next << endl;
    current = current->next;
  }
}

int main() {
  
  Node* head = new Node(1); // This is constructing the new Node(head) with value 1
  head->next = new Node(2); // We made a new Node with value 3 and the head's next is pointing to this node 
  head->next->next = new Node(3);
  
  cout << "Value at head node is: " << head->value << ", pointing to " << head->next << endl;
  cout << "Value at second node: " << head->next->value << ", pointing to " << head->next->next << endl;
  cout << "Value at third node: " << head->next->next->value << ", pointing to " << head->next->next->next << endl;
  
  // Printing the nodes
  // METHOD-1
  Node* current = head;
  while(current != nullptr) {
    cout << current->value << ", " << current->next << endl;
    current = current->next;
  }
  
  // Method-2
  printList(head);
  
  // Memory cleanup
  // new keyword: dynamic memory allocation => needed to be freed, if not => performance issues
  // Keeping program memory usage under control
  
  // delete x: free up the current node
  // delete x->next: free up the memory allocated to the next node 
  
  
  // This free up the entire nodes
  Node* now = head;
  while(now != nullptr) {
    Node* nextNode = now->next;
    delete now;
    now = nextNode;
  }
  
  cout << "Memory freed!";
  
  return 0;
}