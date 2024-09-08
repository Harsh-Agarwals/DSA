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

class LinkedList {
  public:
  Node* head; // pointing to head(first node) of the linked list. Since linked list is uninitialised, it points to the some garbage location.
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
    // displayLinkedList();
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
  
  void deleteFromFront() {
    if (head == NULL) {
      cout << "No head -> no deletion;" << endl;
      return;
    }
    
    Node* firstNode = head;
    head = head->next;
    delete firstNode;
  }
  
  void deleteNode(int value) {
    Node* current = head;
    if(current->value == value) {
      cout << "Deleting from front" << endl;
      Node* head2 = current->next;
      delete head;
      head = head2;
      current = head;
    }
    while(current->next != NULL) {
      if(current->next->value == value) {
        Node* toRemove = current->next;
        
        if (current->next->next == NULL) {
          delete toRemove;
          current->next = NULL;
        } else {
          current->next = current->next->next;
          delete toRemove;
        }
      }
      if (current->next != NULL) {
        current=current->next;
      } else {
        continue;
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
};



int main() {
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  
  displayList(head);
  
  LinkedList* lList = new LinkedList(); // creates the LinkedList, which initilizes the head pointer to nullptr
  // pointer-to-object -> member_function(argument)
  // when we have a pointer to an object, we use arrow function to access the object's member functions 
  lList -> insertFront(5);
  cout << "Value at the head is " << lList->getHead() << endl;
  lList -> insertFront(7);
  cout << "Value at the head is " << lList->getHead() << endl;
  lList->displayLinkedList();
  
  lList-> insertBack(6);
  cout << "Value at the head is " << lList->getHead() << endl;
  lList->displayLinkedList();
  cout << "Value at the tail is: " << lList->getTail() << endl;
  
  lList-> insertBack(9);
  lList->displayLinkedList();
  cout << "Value at the tail is: " << lList->getTail() << endl;
  
  lList-> insertAtK(2, 1);
  lList->displayLinkedList();
  cout << "Value at the tail is: " << lList->getTail() << endl;
  
  lList-> insertAtK(4, 4);
  lList->displayLinkedList();
  cout << "Value at the tail is: " << lList->getTail() << endl;
  
  lList-> insertAtK(6, 1);
  lList->displayLinkedList();
  cout << "Value at the tail is: " << lList->getTail() << endl;
  
  lList-> insertAtK(0, 10);
  lList->displayLinkedList();
  cout << "Value at the tail is: " << lList->getTail() << endl;
  
  lList-> insertAtEnd(7);
  lList->displayLinkedList();
  cout << "Value at the tail is: " << lList->getTail() << endl;
  
  cout << "\nDeleting the first Node" << endl;
  lList->deleteFromFront();
  lList->displayLinkedList();
  
  cout << "\nDeleting special node" << endl;
  lList->deleteNode(6);
  lList->displayLinkedList();
  
  cout << "\nDeleting special node" << endl;
  lList->deleteNode(7);
  lList->displayLinkedList();
  
  cout << "\nDeleting special node" << endl;
  lList->deleteNode(1);
  lList->displayLinkedList();
  
  return 0;
}