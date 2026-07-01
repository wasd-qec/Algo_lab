#include <iostream>
using namespace std;
//Write a program to ask a piece of text from a user. Display the text in a reverse order using stack. 
//Hint: Push each character in the text into stack. Display stack. 
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
int main(){
    stack* book = new stack();
    int data;
    int option= 0;
    while(option == 0){    
    cout<<"Please enter an integer: ";
    cin>>data;
    book->push(data);
    cout<<"Continue? (0 to continue)";
    cin>>option;
}
    book->display();
}