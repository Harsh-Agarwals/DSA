#include <iostream>

using namespace std;

// Node structure for doubly linked list
struct Node {
    int songId;
    Node* prev;
    Node* next;
    
    Node(int id) : songId(id), prev(nullptr), next(nullptr) {}
};

class MusicPlayer {
  private:
    Node* head;
    Node* currentSong;

  public:
    MusicPlayer() : head(nullptr), currentSong(nullptr) {}

    // Function to add a song to the end of the list
    void addSong(int songId) {
       Node* newSong = new Node(songId);
       if(head==NULL) {
           head = newSong;
           currentSong = newSong;
           return;
       }
       Node* current = head;
       while(current->next != NULL) {
           current=current->next;
       }
       newSong->prev = current;
       current->next = newSong;
    }

    // Function to play the next song
    void playNext() {
      if(currentSong->next!=NULL) {
          currentSong = currentSong->next;
      }
    }

    // Function to play the previous song
    void playPrev() {
       if(currentSong->prev != NULL) {
           currentSong=currentSong->prev;
       }
    }

    // Function to switch to a specific song
    void switchSong(int songId) {
      Node* current = head;
      while(current->songId != songId) {
          current = current->next;
      }
      currentSong = current;
    }

    // Function to return the songId of the current song playing
    int current() {
      return currentSong->songId;
    }
};

int main() {
    MusicPlayer player;
    int query, songId;
    int q;
    cin >> q;
    while (q--) {
        cin >> query;

        switch (query) {
            case 1:
                cin >> songId;
                player.addSong(songId);
                break;
            case 2:
                player.playNext();
                break;
            case 3:
                player.playPrev();
                break;
            case 4:
                cin >> songId;
                player.switchSong(songId);
                break;
            case 5:
                cout << player.current() << endl;
                break;
            default:
                cout << "Invalid query!" << endl; 
        }
    }

    return 0;
}
