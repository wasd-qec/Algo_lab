#include <iostream>
using namespace std;
// enqueue dequeue Add an element to the queue Remove an element from the queue 
// front/peek Access the front element in the queue without removing  
// rear Access the last added element without removing it 
//  isEmpty 
//  isFull 
// size  Return the number of elements currently in the queue
//Write a C++ program to implement a queue data structure using an array to store integer numbers. 
// Write functions for: enqueue(), dequeue(), front(), isEmpty(), isFull(), displayQueue(), getSize().  

struct Queue{
    static const int size = 10;
    int Q[size];
    int front;
    int rear;
};

void createEmptyQueue(Queue &q){
    q.front = -1;
    q.rear = -1;
}

bool isEmpty(Queue &q){
    return q.rear == -1;
}

bool isFull(Queue &q){
    return q.rear == q.size - 1;
}

int getSize(Queue &q){
    if (isEmpty(q)) return 0;
    return (q.rear - q.front + 1);
}

int Front(Queue &q){
    if (isEmpty(q)){
        cout << "Queue is Empty!" << endl;
        return -1;
    }
    return q.Q[q.front];
}

void enqueue(Queue &q, int data){
    if (isFull(q)){
        cout << "Q is full (Cannot enqueue " << data << ")" << endl;
        return;
    }
    if (isEmpty(q)){
        q.front = 0;
        q.rear = 0;
    }
    else{
        q.rear++;
    }
    q.Q[q.rear] = data;
    cout << "You have enqueued: " << q.Q[q.rear] << " at index " << q.rear << endl;
}

int dequeue(Queue &q){
    if (isEmpty(q)){
        cout << "Q is Empty" << endl;
        return -1;
    }
    cout << "You have dequeued: " << q.Q[q.front] << " from index " << q.front << endl;
    int element = q.Q[q.front];
    q.Q[q.front] = 0; 
    if (q.front == q.rear){
        q.front = q.rear = -1;
    }
    else {
        q.front++;
    }
    return element;
}

void displayQueue(Queue &q){
    if (isEmpty(q)){
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = q.front; i <= q.rear; i++){
        cout << q.Q[i] << " ";
    }
    cout << "(Size: " << getSize(q) << ")" << endl;
}

int main(){
    Queue q;
    createEmptyQueue(q);

    cout << "--- Enqueuing elements ---" << endl;
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);

    cout << "\n--- Checking Front ---" << endl;
    cout << "Front element: " << Front(q) << endl;

    cout << "\n--- Dequeuing element ---" << endl;
    dequeue(q);
    displayQueue(q);

    cout << "\n--- Enqueuing up to capacity ---" << endl;
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 80);
    enqueue(q, 90);
    enqueue(q, 100);
    enqueue(q, 110); // Fits into the 10th spot (index 9)
    displayQueue(q);

    cout << "\n--- Trying to enqueue when rear is at the end ---" << endl;
    enqueue(q, 120); // Should print "Q is full" because rear is index 9

    cout << "\n--- Dequeuing one element to show wasted space ---" << endl;
    dequeue(q);
    displayQueue(q);
    
    cout << "\n--- Attempting to enqueue after dequeue (demonstrating wasted space) ---" << endl;
    enqueue(q, 120); // Will print "Q is full" because rear is still at index 9!

    return 0;
}