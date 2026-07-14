#include <iostream>
#include <string>
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
    cout << "You have enqueued: Task" << data << endl;
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
        cout << "Task" << element->data;
        if (element->next != nullptr) {
            cout << " -> ";
        }
        element = element->next;
    }
    cout << " (Size: " << getSize(q) << ")" << endl;
}

int main() {
    Queue q;

    cout << "--- Initializing Queue with Tasks ---" << endl;
    // Task 4 is the first, Task 1 is the second, Task 3 is the third, Task 2 is the fourth
    enqueue(q, 4);
    enqueue(q, 1);
    enqueue(q, 3);
    enqueue(q, 2);
    
    cout << endl;
    displayQueue(q);
    cout << endl;

    string response;
    while (!isEmpty(q)) {
        cout << "Do you want to activate a task in your queue now? ";
        cin >> response;
        if (response == "yes") {
            int taskNum = dequeue(q);
            cout << "Doing task " << taskNum << " ..... DONE!" << endl;
            displayQueue(q);
            cout << endl;
        } else {
            cout << "No task activated. Please say 'yes' to activate a task." << endl << endl;
        }
    }

    cout << "All tasks have been processed and the queue is empty." << endl;
    return 0;
}
