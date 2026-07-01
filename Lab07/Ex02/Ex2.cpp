#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
struct linkedlist{
    int size;
    node* head;
};
struct stack {
        linkedlist* list;

        stack() {
            list = new linkedlist;
            list->size = 0;
            list->head = nullptr;
        }

        void push(int data){
            node* element = new node;
            element->data=data;
            element->next=list->head;
            list->head=element;
            list->size++;
        }
        int pop(){
            if(list->size==0){
                cout<<"The stack is empty"<<endl;
                return -1;
            }
            node* element = list->head;
            int data = element->data;
            list->head=list->head->next;
            delete element;
            list->size--;
            return data;
        }
        void display(){
            if(list->size==0){
                cout<<"The stack is empty"<<endl;
                return;
            }
            node* current = list->head;
            while(current != nullptr){
                cout<<current->data<<"  ";
                current=current->next;
            }
            cout<<endl;
            return;

        }
        int peek(){
            if(list->size==0){
                cout<<"The stack is empty"<<endl;
                return -1;
            }
            return list->head->data;
        }
        int count(){return list->size;}

};

int main() {
    stack myStack;
    
    cout << "Pushing 10, 20, 30..." << endl;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Peek top element: " << myStack.peek() << endl;

    cout << "Popped element: " << myStack.pop() << endl;

    cout << "Displaying remaining stack:" << endl;
    myStack.display();

    return 0;
}