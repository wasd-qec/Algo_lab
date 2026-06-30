#include <iostream>
using namespace std;
struct element{
    int value;
    element* next;
    element* prev;
};
struct List{
    int size;
    element* head;
    element* tail;
};
List* createEmptyList(){
    List* list = new List();
    list->head=nullptr;
    list->tail=nullptr;
    list->size=0;
    return list;
}
void addBegin(List* list, int num){
    element* node = new element();
    node->value = num;
    node->prev = nullptr;
    node->next = list->head;
    if (list->size == 0){
        list->head = node;
        list->tail = node;
    }
    else{
        list->head->prev = node;
        list->head = node;
    }
    list->size++;
}
void addEnd(List* list, int num){
    element* node = new element();
    node->value = num;
    node->next = nullptr;
    node->prev = list->tail;
    if (list->size == 0){
        list->head = node;
        list->tail = node;
    }
    else{
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}
void addInPosition(List* list, int num, int position){
    if (position<=0||position>list->size+1){
        cout<<"Invalid position"<<endl;
        return;
    }
    if (position==1){
        addBegin(list,num);
    }
    else if (position==list->size+1){
        addEnd(list,num);
    }
    else{
        element* node = new element();
        node->value = num;
        element* current = list->head;
        int i = 1;
        while(i<position-1){
            current = current->next;
            i++;
        }
        node->next = current->next;
        node->prev = current;
        current->next->prev = node;
        current->next = node;
        list->size++;
    }
}
void display(List* list){
    element* current = list->head;
    while(current){
        cout<<current->value<<endl;
        current = current->next;
    }
}
int main(){
    List* list = createEmptyList();

    addBegin(list, 10);
    addBegin(list, 5);
    addEnd(list, 20);
    addInPosition(list, 15, 3);

    cout << "List after inserts:" << endl;
    display(list);
    return 0;
}