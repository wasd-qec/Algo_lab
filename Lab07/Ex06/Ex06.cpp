#include <iostream>
#include <string>
using namespace std;
struct stack {
        int size = 100;
        char s[100];
        int top = -1;
};
bool isEmpty(const stack& book) {
    return book.top == -1;
}
bool isFull(const stack& book) {
    return book.top == book.size - 1;
}
void push(stack& book, char data){
    if(isFull(book)){
        cout<<"the stack is full"<<endl;
        return;
    }
    else{
        book.s[book.top+1]=data;
        book.top++;
    }
}
char pop(stack& book){
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
char peek(stack& book){
     if(isEmpty(book)){
        cout<<"the stack is Empty"<<endl;
        return -1;
    }
    else{
        return book.s[book.top];
    }
}
bool compare(char right, char left) {
    if (right == ')' && left == '(') return true;
    if (right == '}' && left == '{') return true;
    if (right == ']' && left == '[') return true;
    
    return false;
}
bool checkBalanced(const string& expr) {
    stack book;
    cout << "\nProcessing string: \"" << expr << "\"" << endl;
    cout << "================================" << endl;

    for (size_t i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        cout << "Step " << i + 1 << ": Character is '" << ch << "'" << endl;

        // When a character is a left delimiter, push it to the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(book, ch);
            cout << "  -> Pushed '" << ch << "' to stack." << endl;
        }
        // When a character is a right delimiter, pop and check if it matches
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(book)) {
                cout << "  -> Error: Found closing '" << ch << "' but the stack is empty!" << endl;
                return false;
            }
            char left = pop(book);
            if (compare(ch, left)) {
                cout << "  -> Popped '" << left << "' and it matches '" << ch << "'." << endl;
            } else {
                cout << "  -> Error: Popped '" << left << "' does NOT match '" << ch << "'!" << endl;
                return false;
            }
        } else {
            cout << "  -> Ignored (not a delimiter)." << endl;
        }

        // Print current stack status
        cout << "  Stack status: ";
        if (isEmpty(book)) {
            cout << "[empty]" << endl;
        } else {
            for (int j = 0; j <= book.top; j++) {
                cout << book.s[j] << " ";
            }
            cout << endl;
        }
        cout << "--------------------------------" << endl;
    }

    // It is balanced when all matchings are true and the stack is empty at the end
    if (isEmpty(book)) {
        cout << "Success: Stack is empty at the end. The string is balanced!" << endl;
        return true;
    } else {
        cout << "Failure: Stack still has elements left. The string is unbalanced!" << endl;
        return false;
    }
}

int main() {
    string input;
    cout << "Enter a string of delimiters (e.g., {([])}): ";
    cin >> input;

    if (checkBalanced(input)) {
        cout << "\nResult: The string is BALANCED!" << endl;
    } else {
        cout << "\nResult: The string is NOT BALANCED." << endl;
    }

    return 0;
}

