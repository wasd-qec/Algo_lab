#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

struct Queue {
    int size;
    node* front;
    node* rear;
    Queue() {
        size = 0;
        front = nullptr;
        rear = nullptr;
    }
};

// 2. Write a C++ program to implement a queue data structure using a singly linked list 
// to store integer numbers with the following operations: 
// enqueue(), dequeue(), front(), isEmpty(), isFull(), displayQueue(), getSize().

bool isEmpty(Queue &q) {
    return q.size == 0;
}

bool isFull(Queue &q) {
    return false; // A linked-list queue is not limited by static size
}

int getSize(Queue &q) {
    return q.size;
}

void enqueue(Queue &q, int data) {
    node* element = new node;
    element->data = data;
    element->next = nullptr;
    if (isEmpty(q)) {
        q.size = 1;
        q.front = element;
        q.rear = element;
    } else {
        q.rear->next = element;
        q.rear = element;
        q.size++;
    }
    cout << "You have enqueued: " << data << endl;
}

int front(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue is Empty!" << endl;
        return 0;
    }
    return q.front->data;
}

int dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue is Empty" << endl;
        return 0;
    }
    node* temp = q.front;
    int data = temp->data;
    q.front = q.front->next;
    delete temp;
    q.size--;
    if (q.front == nullptr) {
        q.rear = nullptr;
    }
    return data;
}

void displayQueue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue is empty" << endl;
        return;
    }
    node* element = q.front;
    cout << "Queue: ";
    while (element != nullptr) {
        cout << element->data;
        if (element->next != nullptr) {
            cout << " -> ";
        }
        element = element->next;
    }
    cout << " (Size: " << getSize(q) << ")" << endl;
}

int main() {
    Queue q;

    cout << "--- Checking Initial State ---" << endl;
    cout << "Is queue empty? " << (isEmpty(q) ? "Yes" : "No") << endl;
    cout << "Queue size: " << getSize(q) << endl;

    cout << "\n--- Enqueuing Elements ---" << endl;
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);

    cout << "\n--- Checking Front Element ---" << endl;
    cout << "Front element: " << front(q) << endl;

    cout << "\n--- Dequeuing Elements ---" << endl;
    cout << "Dequeued: " << dequeue(q) << endl;
    displayQueue(q);

    cout << "\n--- Enqueuing More Elements ---" << endl;
    enqueue(q, 40);
    enqueue(q, 50);
    displayQueue(q);

    cout << "Front element: " << front(q) << endl;

    cout << "\n--- Dequeuing Until Empty ---" << endl;
    while (!isEmpty(q)) {
        cout << "Dequeued: " << dequeue(q) << " (Remaining size: " << getSize(q) << ")" << endl;
    }
    displayQueue(q);

    cout << "\n--- Attempting to Dequeue from Empty Queue ---" << endl;
    dequeue(q);

    return 0;
}