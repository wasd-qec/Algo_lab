#include <iostream>
using namespace std;

struct Element{
    string name;
    Element* Next;
};
struct List{
    int Length;
    Element *Head;
    Element *Tail;
};
List* createList(){
    List* list = new List();
    list->Length = 0;
    list->Head = nullptr;
    list->Tail = nullptr;
    return list;
}
void addPerson(List* list, string name){
    Element* element = new Element();
    element->name = name;
    element->Next = nullptr;
    if(list->Length == 0){
        list->Head = element;
        list->Tail = element;
        list->Length = 1;
    }
    else {
        element->Next = list->Head;
        list->Head = element;
        list->Length++;
    }
}
void display(List* a){
    Element* temp = a->Head;
    for(int i = 0; i<a->Length; i++){
    cout<<temp->name<<endl;
    temp = temp->Next;
    }
}
int main(){
    List* list = createList();
    bool cont = true;
    while(true){
        cout<<"Enter your name :"<<endl;
        string name;
        cin >> name;
        addPerson(list, name);
        cout<<"Do you wish to not continue(y/n) :";
        string yes;
        cin >> yes;
        if (yes == "y" || yes == "Y"){
            break;
        }
        else{
            continue;
        }
    }
    display(list);
    return 0;
}