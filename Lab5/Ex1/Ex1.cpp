#include <iostream>
using namespace std;

struct Element{
    char Alp;
    Element* Next;
};
struct List{
    int Length;
    Element* Head;
    Element* Tail;
};
List* CreateEmptyList(){
    List* ls = new List;
    ls->Length=0;
    ls->Head=nullptr;
    ls->Tail=nullptr;
    return ls;
}
void AddAtEnd(List* a, char c){
    Element* b = new Element();
        b->Alp = c;
        b->Next = nullptr;
    if(a->Length==0){
        a->Head = b;
        a->Tail = b;
        a->Length = 1;
    }
    else{
        a->Tail->Next = b ;
        a->Tail = b;
        a->Length++;
    }
}
void display(List* a){
    Element* temp = a->Head;
    for(int i = 0; i<a->Length; i++){
    cout<<temp->Alp<<endl;
    temp = temp->Next;
    }
}
int main(){
    List* list = CreateEmptyList();

    // Method 1: Using for loop with ASCII
    cout << "=== Method 1: For Loop ===" << endl;
    for(int i = 65; i <= 90; i++){  // ASCII 65-90 = A-Z
        AddAtEnd(list, (char)i);
    }
    display(list);
    
    cout << "\n=== Method 2: While Loop ===" << endl;
    // Method 2: Using while loop with ASCII
    List* list2 = CreateEmptyList();
    int ascii = 97;
    while(ascii <= 122){  // ASCII 65-90 = A-Z
        AddAtEnd(list2, (char)ascii);
        ascii++;
    }
    display(list2);
    system("pause");
    return 0;
}