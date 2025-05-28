#include <iostream>
#include <vector>

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
    CNode* tail;
public:
    CircularLinkedList() : tail(nullptr) {}

    void insert(int val) {
        CNode* newNode = new CNode(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void remove(int val) {
        if (!tail) return;
        CNode *curr = tail->next, *prev = tail;
        do {
            if (curr->data == val) {
                if (curr == tail && curr->next == tail) tail = nullptr;
                else {
                    if (curr == tail) tail = prev;
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
    }

    CNode* search(int val) {
        if (!tail) return nullptr;
        CNode* curr = tail->next;
        do {
            if (curr->data == val) return curr;
            curr = curr->next;
        } while (curr != tail->next);
        return nullptr;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);

    CNode* foundNode = cll.search(20);
    if (foundNode) {
        std::cout << "Found: " << foundNode->data << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    cll.remove(20);
    foundNode = cll.search(20);
    if (foundNode) {
        std::cout << "Found: " << foundNode->data << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    return 0;
}