#include <iostream>

class Node {
public:
    int data;
    Node* next;

    explicit Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head, *tail;
    void addNode(int data);
    void reverse();
    void printNode();
    void addNodeAtHead(int data);
    void addNodeAtMiddle(int data, int key);
    void deleteNodeAtHead();
    void deleteNodeAtTail();
    void deleteNodeAtMiddle(int key);
};

void LinkedList::deleteNodeAtHead() {
    if (head == nullptr) {
        std::cout << "List already empty!" << std::endl;
    } else{
        auto* temp = head;
        head = head->next;
        delete(temp);
    }
}


void LinkedList::deleteNodeAtTail() {
    if (tail == nullptr) {
        return;
    } else{
        Node* prev = nullptr;
        auto* temp = head;
        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        if (prev) {
            prev->next = nullptr;
            tail = prev;
            delete (temp);
        }
    }
}


void LinkedList::deleteNodeAtMiddle(int key) {
    auto* temp = head;
    if (temp == nullptr) {
        return;
    } else if (temp->data == key) {
        delete(temp);
        head = nullptr;
        tail = nullptr;
    } else{
        Node* prev = nullptr;
        while (temp->next->data == key) {
            prev = temp;
            temp = temp->next;
        }
        if (prev) {
            auto* p = temp->next;
            prev->next = p;
            delete(temp);
        }
    }
}

void LinkedList::addNodeAtMiddle(int data, int key) {
    auto* temp = new Node(data);
    Node* prev = nullptr;
    Node* index = head;
    if (head == nullptr) {
        addNode(data);
    } else{
        while (index->data != key) {
            prev = index;
            index = index->next;
        }

        if (prev) {
            auto* p = prev->next;
            prev->next = temp;
            temp->next = p;
        }
    }
}

void LinkedList::addNodeAtHead(int data) {
    auto* temp = new Node(data);
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else{
        temp->next = head;
        head = temp;
    }
}

void LinkedList::addNode(int data) {
    auto* temp = new Node(data);
    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}





void LinkedList::reverse() {
    Node *prev = nullptr;
    Node* next = nullptr;
    auto* current = head;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
}

void LinkedList::printNode() {
    auto *pItem = head;
    while (pItem) {
        std::cout << pItem->data << "\t";
        pItem = pItem->next;
    }
}


int main() {
    auto* list = new LinkedList();
    for (int i = 0; i <= 5; ++i) {
        list->addNode(i);
    }
    list->addNodeAtHead(-3);
    //list->reverse();

    list->deleteNodeAtHead();
    list->deleteNodeAtTail();
    list->deleteNodeAtMiddle(1);
    //list->addNodeAtMiddle(66, 1);
    list->printNode();
}
