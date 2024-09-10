#include <bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node* next;
  Node* prev;
  
  Node(int val): value(val), next(nullptr), prev(nullptr) {}
};

class LinkedList {
  public:
  Node* head;
  
  void insertAtIndex(int index, int value) {
    Node* newNode = new Node(value);
    cout << newNode->value << endl;
    
    if(index==0) {
      if(head == NULL) {
        head = newNode;
      } else {
        Node* current = head;
        head = newNode;
        newNode->next = current;
        current->prev = newNode;
      }
      printValues(head);
      return;
    }
    
    Node* current = head;
    int i=0;
    while(i<index-1) {
      current = current->next;
      i++;
    }
    if(i==index-1) {
      if(current->next == NULL) {
        current->next = newNode;
        newNode->prev = current;
        printValues(head);
        return;
      }
      newNode->next = current->next;
      newNode->prev = current;
      current->next->prev = newNode;
      current->next = newNode;
      
      if(current->next == NULL) {
        printValues(head);
      }
      i++;
    }
    printValues(head);
    return;
  }
  
  void deleteValue(int value) {
    Node* current = head;
    if(head->value == value) {
      head=head->next;
      head->prev = NULL;
    }
    current=head;
    while(current->next != NULL) {
      if(current->next->value == value) {
        current->next = current->next->next;
        if(current->next == NULL) {
          printValues(head);
          return;
        }
        current->next->prev = current;
      }
      current = current->next;
    }
    printValues(head);
  }
  
  void printValues(Node* head) {
    Node* current = head;
    cout << current->value << ", " << current->next << ", " << current->prev << endl;
    while(current->next!=NULL) {
      current=current->next;
      cout << current->value << ", " << current->next << ", " << current->prev << endl;
    }
  }
};

int main() {
  LinkedList* lList = new LinkedList();
  lList->insertAtIndex(0, 4);
  cout << "....." << endl;
  lList->insertAtIndex(0, 8);
  cout << "....." << endl;
  lList->insertAtIndex(2, 5);
  cout << "....." << endl;
  lList->insertAtIndex(3, 8);
  cout << "....." << endl;
  lList->insertAtIndex(1, 7);
  cout << "....." << endl;
  lList->insertAtIndex(2, 6);
  cout << "....." << endl;
  lList->insertAtIndex(5, 0);
  cout << "....." << endl;
  lList->deleteValue(7);
  
  return 0;
}