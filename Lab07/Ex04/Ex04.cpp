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
void toBinary(int data, stack* book){
    int mod, ans=data;
    while(ans!=0){
        mod = ans%2;
        book->push(mod);
        ans = ans/2;
    }
}
int main(){
    stack* book = new stack();
    cout<<"Binary of 12 is :"<<endl;
    toBinary(12,book);
    book->display();
}