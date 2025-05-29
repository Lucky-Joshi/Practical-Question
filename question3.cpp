#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode *prev, *next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void removeFromBeginning() {
        if (!head) return; // List is empty
        DNode* del = head; // Node to be deleted
        head = head->next; // Move head to the next node
        if (head) head->prev = nullptr; // If the list is not empty, set the new head's prev to nullptr
        delete del; // Delete the old head
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    cout << "List after inserting elements: ";
    dll.display();

    dll.removeFromBeginning();
    cout << "List after removing from beginning: ";
    dll.display();

    return 0;
}