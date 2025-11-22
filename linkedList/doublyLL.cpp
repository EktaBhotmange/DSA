#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if(head == NULL) {
            cout << "LL is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        if(head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;  //if the list becomes empty
        }
        delete temp;
    }

    void pop_back() {
        if(tail->prev == NULL) {
            cout << "LL is empty\n";
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if(tail != NULL) {
            tail->next = NULL;
        } 

        temp->prev = NULL;
        delete temp;
    }

    void Print() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyList dll;

    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.pop_back();

    dll.Print();

    return 0;
}