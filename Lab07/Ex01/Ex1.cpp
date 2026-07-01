#include <iostream>
using namespace std;
struct stack {
        int size = 100;
        int s[100];
        int top = -1;
};
bool isEmpty(stack& book){
    if(book.top==-1){
        return true;
    }
    else{
        return false;
    }
}
bool isFull(stack& book){
    if(book.top==book.size-1){
        return true;
    }
    else{
        return false;
    }
}
void push(stack& book, int data){
    if(isFull(book)){
        cout<<"the stack is full"<<endl;
        return;
    }
    else{
        book.s[book.top+1]=data;
        book.top++;
    }
}
int pop(stack& book){
    if(isEmpty(book)){
        cout<<"the stack is Empty"<<endl;
        return -1;
    }
    else{
        int temp = book.s[book.top];
        book.s[book.top]=0;
        book.top--;
        return temp;
}
}
int peek(stack& book){
     if(isEmpty(book)){
        cout<<"the stack is Empty"<<endl;
        return -1;
    }
    else{
        return book.s[book.top];
    }
}
void display(stack& book){
    if(isEmpty(book)){
        cout<<"the stack is Empty"<<endl;
        return;
    }
    else{
        while(book.top!=-1){
            cout<<"LABUBU :"<<book.top+1<<"  "<<pop(book)<<endl;
        }
    }
}
int main() {
    // 1. Create and initialize the stack
    stack myStack;
    myStack.size = 100;
    myStack.top = -1; 
    
    // 2. Test pushing elements
    cout << "Pushing 10, 20, 30..." << endl;
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    // 3. Test peek
    cout << "Peek top element: " << peek(myStack) << endl;

    // 4. Test popping an element
    cout << "Popped element: " << pop(myStack) << endl;

    // 5. Test display
    cout << "Displaying remaining stack:" << endl;
    display(myStack);

    return 0;
}