#include<bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node* next;
  
  Node(int val): value(val), next(nullptr) {}
};

class LinkedList {
  public:
  Node* head;
  Node* tail;
  
  void insertAtEnd(int value) {
    Node* newNode = new Node(value);
    
    if (head == NULL) {
        head = newNode;
    } else {
        tail -> next = newNode;
    }
    
    tail = newNode;
    tail -> next = head;
  }
  
  int solveJosephus() {
    Node* current = head;
    while(current->next != current) {
        current->next = current->next->next;
        current = current->next;
    }
    return current->value;
  }

};

int main() {
  int t, n;
  cin>>t;
  
  while(t--) {
    cin>>n;
    LinkedList* list = new LinkedList();
    for(int i=1;i<=n;i++){
      list->insertAtEnd(i);
    }
    cout << list->solveJosephus() << endl;
  }
  
  
  return 0;
}