#include<bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node* next;
  
  Node(int val): value(val), next(nullptr) {}
};

int main() {
  
  Node* head = new Node(1); // This is constructing the new Node(head) with value 1 
  
  cout << "Value at head node is: " << head->value << endl;
  
  return 0;
}