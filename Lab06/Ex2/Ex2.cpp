#include <iostream>
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>
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
int randomInt(int minValue, int maxValue) {
    return minValue + (std::rand() % (maxValue - minValue + 1));
}
int sum(List* list){
    if (list == nullptr) {
        return 0;
    }
    int total = 0;
    element* current = list->head;
    while(current){
        total += current->value;
        current = current->next;
    }
    return total;
}
int main(){
    List* list = createEmptyList();
    cout<<"Enter n number :"<<endl;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        int value = randomInt(1, 100);
        addEnd(list, value);
    }
    cout<<"Sum:"<<sum(list)<<endl;
    double average = sum(list)/list->size;
    cout<<"Average :"<<average<<endl;
    cout << "List after inserts:" << endl;
    display(list);
    return 0;
}