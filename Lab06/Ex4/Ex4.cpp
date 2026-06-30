#include <iostream>
using namespace std;
struct node {
    int data;
    node* prev;
    node* next;
};
struct List{
    int size;
    node* head;
    node* tail;
    int getsize(){return size;}
};
List* createList(){
    List* ls;
    ls = new List();
    ls->size = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}
void addEnd(List* ls, int data){
    node* element = new node;
    element->data=data;
    element->prev=ls->tail;
    element->next=nullptr;
    if(ls->size==0){
        ls->head=element;
    }
    else{
        ls->tail->next=element;
    }
    ls->tail=element;
    ls->size++;
}
void addBeg(List* ls, int data){
    node* element = new node;
    element->data=data;
    element->prev=nullptr;
    element->next=ls->head;
    if (ls->size == 0){
        ls->tail=element;
    }
    else{
        ls->head->prev = element;
    }
    ls->head = element;
    ls->size++;
}
void addPos(List* ls, int data, int pos){
    if (pos>(ls->size+1)||pos<=0){
        cout<<"Bro the list not that big";
    }
    else if (pos==1){
        addBeg(ls, data);
    }
    else if (pos==(ls->size+1)){
        addEnd(ls, data);
    }
    else{
        node* element = new node;
        element->data = data;
        node* current = ls->head;
        for (int i = 1; i < pos - 1; i++){
            current = current->next;
        }
        element->next = current->next;
        element->prev = current;
        current->next->prev = element;
        current->next = element;
        ls->size++;
    } 
}
void deleteBeg(List* ls){
    if (ls->size == 0) return;
    node* current = ls->head;
    ls->head = current->next;
    if (ls->head != nullptr) {
        ls->head->prev = nullptr;
    } else {
        ls->tail = nullptr;
    }
    delete current;
    ls->size--;
}
void deleteEnd(List* ls){
    if (ls->size == 0) return;
    node* current = ls->tail;
    ls->tail=current->prev;
    if (ls->tail != nullptr) {
        ls->tail->next=nullptr;
    } else {
        ls->head = nullptr;
    }
    delete current;
    ls->size--;
}
void deletePos(List* ls, int pos){
    if (pos > ls->size || pos <= 0){
        cout<<"Bro the list not that big";
    }
    else if (pos == 1){
        deleteBeg(ls);
    }
    else if (pos == ls->size){
        deleteEnd(ls);
    }
    else{
        node* current = ls->head;
        // Move current to the node at 'pos'
        for (int i = 1; i < pos; i++){
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        ls->size--;
    }
}
void min(List* ls){
    if (ls->size == 0) {
        cout << "List is empty, no min\n";
        return;
    }
    int min;
    node* current = ls->head;
    min = current->data;
    while(current != nullptr){
        if(min>current->data){
            min = current->data;
        }
        current = current->next;
    }
    cout<<"Min :"<<min<<endl;
}
void max(List* ls){
    if (ls->size == 0) {
        cout << "List is empty, no max\n";
        return;
    }
    int max;
    node* current = ls->head;
    max = current->data;
    while(current != nullptr){
        if(max<current->data){
            max = current->data;
        }
        current = current->next;
    }
    cout<<"Max :"<<max<<endl;
}
void display(List* ls){
    node* current = ls->head;
    while(current != nullptr){
        cout << current->data << ' ';
        current = current->next;
    }
    cout << '\n';
}
int main(){
    List* ls = createList();
    
    cout << "--- Testing Adding Functions ---\n";
    cout << "addEnd(ls, 3): ";
    addEnd(ls, 3);
    display(ls);
    
    cout << "addBeg(ls, 1): ";
    addBeg(ls, 1);
    display(ls);
    
    cout << "addPos(ls, 2, 2): ";
    addPos(ls, 2, 2);
    display(ls);
    
    cout << "addPos(ls, 4, 4): ";
    addPos(ls, 4, 4);
    display(ls);
    
    cout << "addPos(ls, 5, 10) (invalid): ";
    addPos(ls, 5, 10);
    cout << '\n';

    cout << "\n--- Testing Min/Max Functions ---\n";
    min(ls);
    max(ls);

    cout << "\n--- Testing Deleting Functions ---\n";
    cout << "deleteBeg(ls): ";
    deleteBeg(ls);
    display(ls);
    
    cout << "deleteEnd(ls): ";
    deleteEnd(ls);
    display(ls);
    
    cout << "deletePos(ls, 2): ";
    deletePos(ls, 2); // Deletes element at pos 2
    display(ls);
    
    cout << "deletePos(ls, 10) (invalid): ";
    deletePos(ls, 10);
    cout << '\n';

    return 0;
}