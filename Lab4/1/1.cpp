#include <iostream>
using namespace std;

struct Element{
    int data;
    Element* next;
};
struct List{
    int n;
    Element* head;
    Element* tail;
};

List* createEmptyList(){
    List* ls = new List;
    ls->head = nullptr;

};
void addBeg(List* ls, int data){
    Element* e = new Element;
    e->data = data;
    e->next = ls->head;
    
}