#include<bits/stdc++.h>
using namespace std;

struct Node {
  int value;
  Node* next;
  
  Node(int val): value(val), next(nullptr) {}
};

void displayList(Node* head) {
  Node* current = head;
  while(current != nullptr) {
    cout << current->value << ", " << current->next << endl;
    current = current->next;
  }
}

void displayCircularLinkedList(Node* tail) {
  cout << "\nCircularLinkedList starting from head:" << endl;
  Node* current = tail->next;
  while(current->next != NULL && current!=tail) {
    cout << current->value << ", " << current->next << endl;
    current = current->next;
  }
}

class LinkedList {
  public:
  Node* head;
  Node* tail;
  
  void insertFront(int value) {
    cout << "Inserting value " << value << endl;
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }
  
  void insertBack(int value) {
    displayLinkedList();
    cout << "Inserting value " << value << endl;
    Node* newNode = new Node(value);
    
    if (head == NULL) {
      head = newNode;
      return;
    }
    
    Node* current = head;
    while(current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
  }
  
  void insertAtEnd(int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
      head = newNode;
      tail = newNode;
      return;
    }
    
    Node* current = head;
    while(current->next != nullptr) {
      current = current->next;
      if(current->next == nullptr) {
        tail = current;
      }
    }
    
    tail->next = newNode;
    tail = newNode;
  }
  
  void insertAtK(int k, int value) {
    Node* newNode = new Node(value);
    
    if (head == nullptr) {
      head = newNode;
      return;
    }
    
    if(k==0) {
      Node* head2 = head;
      head = newNode;
      Node* current = head;
      head->next = head2;
      while(current->next!=nullptr) {
        current = current->next;
      }
      return;
    }
    
    Node* current = head;
    int i=0;
    while(current!=nullptr && i<k-1) {
      current = current->next;
      i++;
    }
    
    while(i>=k-1 && current!=nullptr) {
      if(i==k-1) {
        Node* nextNode = current->next;
        current->next = newNode;
        current = current->next;
        current->next = nextNode;
        current = current->next;
        i++;
      } else {
        current = current->next;
        i++;
      }
    }
  }
  
  int getHead() {
    if (head == NULL) {
      return -1;
    } else {
      return head->value;
    }
  }
  
  int getTail() {
    if (head == NULL) {
      return -1;
    } else {
      Node* current = head;
      while(current->next != nullptr) {
        current = current->next;
      }
      return current->value;
    }
  }
  
  void displayLinkedList() {
    cout << "\nDisplaying the linked List" << endl;
    displayList(head);
    cout << "Head: " << head->value << endl;
  }
  
  // CircularLinkedList methods
  void convertToCircular() {
    Node* current = head;
    Node* tail;
    while(current->next != NULL) {
      current=current->next;
      if(current->next == NULL) {
        tail = current;
      }
    }
    cout << tail->value << ", " << tail->next << endl;
    tail->next = head;
    cout << "CircularLinkedList" << endl;
    cout << tail->value << ", " << tail->next << endl;
  }
  
  void insertionAtCircularEnd(int value) {
    Node* newNode = new Node(value);
    
    if (head == NULL) {
      head = newNode;
    } else {
      tail->next = newNode;
    }
    tail = newNode;
    tail->next = head;
    cout << "CircularLinkedList tail" << endl;
    cout << tail->value << ", " << tail->next << endl;
    displayCircularLinkedList(tail);
  }
  
  void deleteElementOfCL(int value) {
    cout << "Deleting " << value << endl;
    Node* current = head;
    if(head->value == value) {
      current = current->next;
      tail->next = current;
    }
    
    while(current->next != NULL && current!=tail) {
      if(current->next->value == value) {
        current->next = current->next->next;
      }
      current = current->next;
    }
    displayCircularLinkedList(tail);
  }
};

int main() {
  LinkedList* lList = new LinkedList(); 
  lList -> insertFront(5);
  cout << "Value at the head is " << lList->getHead() << endl;
  
  lList-> insertBack(6);
  cout << "Value at the head is " << lList->getHead() << endl;
  lList->displayLinkedList();
  cout << "Value at the tail is: " << lList->getTail() << endl;
  
  lList-> insertAtK(0, 10);
  lList->displayLinkedList();
  cout << "Value at the tail is: " << lList->getTail() << endl;
  
  lList-> insertAtEnd(7);
  lList->displayLinkedList();
  cout << "Value at the tail is: " << lList->getTail() << endl;
  
  lList->convertToCircular();
  lList->insertionAtCircularEnd(1);
  
  lList->deleteElementOfCL(5);
  // lList->deleteElementOfCL(10);
  // lList->deleteElementOfCL(7);
  
  
  return 0;
}