#include <iostream>
using namespace std;

struct Queue{
    int Q[SIZE];
    int front;
    int rear;
};
void createEmptyQueue(Queue &q){
    q.front = -1;
    q.rear = -1;
}
bool isFull(Queue &q){
    return q.rear+1 == SIZE;
}
bool isEmpty(Queue &q, int data){
    return q.rear+1 == SIZE;
}