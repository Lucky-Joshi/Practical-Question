#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {} // Constructor to initialize node with value and next pointer
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {} // Constructor to initialize the linked list
    ~SinglyLinkedList() { // Destructor to free memory
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtPosition(int val, int pos) {
        Node* newNode = new Node(val); // Create a new node
        if (pos == 0) { 
            newNode->next = head; // Insert at the head
            head = newNode;
            return;
        }
        Node* temp = head; // Start from the head
        for (int i = 0; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (!temp) { // If position is out of bounds
            cout << "Position out of bounds\n";
            return;
        }
        newNode->next = temp->next; // Link the new node to the next node
        temp->next = newNode;
    }

    void removeFromEnd() {
        if (!head) return; // List is empty
        if (!head->next) { // Only one element
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head; // Start from the head
        while (temp->next->next) // Traverse to the second last node
            temp = temp->next;
        delete temp->next; // Delete the last node
        temp->next = nullptr; // Set the next of second last node to nullptr
    }

    int search(int val) {
        Node* temp = head;
        int pos = 0;
        while (temp) {
            if (temp->data == val) return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) { // If the list is empty
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) // Traverse to the end of the list
            temp = temp->next;
        temp->next = newNode;
    }

    void removeAtPosition(int pos) {
        if (!head) return; // List is empty
        if (pos == 0) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }
        Node* temp = head;
        for (int i = 0; temp && i < pos - 1; i++)
            temp = temp->next;
        if (!temp || !temp->next) return;
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void isEvenOrOdd() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        cout << (count % 2 == 0 ? "Even" : "Odd") << endl; 
    }
};


int main() {
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.display(); // Output: 10 20 30

    list.insertAtPosition(15, 1);
    list.display(); // Output: 10 15 20 30

    list.removeFromEnd();
    list.display(); // Output: 10 15 20

    cout << "Position of 15: " << list.search(15) << endl; // Output: Position of 15: 1
    cout << "Position of 40: " << list.search(40) << endl; // Output: Position of 40: -1

    cout << "Node count: " << list.countNodes() << endl; // Output: Node count: 3

    list.removeAtPosition(1);
    list.display(); // Output: 10 20

    list.isEvenOrOdd(); // Output: Even

    return 0;
}