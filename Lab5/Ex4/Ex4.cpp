#include <iostream>
using namespace std;
struct product{
    string productid;
    string name;
    double price;
    
};
struct element{
    product prod;
    element* next;
};
struct List{
    int size;
    element* head;
    element* tail;
};
List* createEmptylist(){
    List* list = new List();
    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;
    return list;

}
product createProduct(string productid, string name, double price){
    product prod;
    prod.name = name;
    prod.productid = productid;
    prod.price = price;
    return prod;
}
void addEnd(List* list, product prod){
    element* elemen = new element();
    elemen->next = nullptr;
    elemen->prod = prod;
    if (list->size == 0){
        list->head = elemen;
        list->tail = elemen;
        list->size = 1;
    }
    else {
        list->tail->next = elemen;
        list->tail = elemen;
        list->size++;
    }
}
void addBegin(List* list, product prod){
    element* elemen = new element();
    elemen->next = nullptr;
    elemen->prod = prod;
    if (list->size == 0){
        list->head = elemen;
        list->tail = elemen;
        list->size = 1;
    }
    else {
        elemen->next = list->head;
        list->head = elemen;
        list->size++;
    }
}

void addProductWithCondition(List* list, const product& prod){
    if (prod.price < 50) {
        addBegin(list, prod);
    } else {
        addEnd(list, prod);
    }
}

void display(const List* list){
    const element* cur = list->head;
    while (cur != nullptr) {
        cout << cur->prod.productid << " | "
             << cur->prod.name << " | "
             << cur->prod.price << "\n";
        cur = cur->next;
    }
}
void searchbyName(List* list, string name){
    int i =0;
    element* current = new element();
    current = list->head;
    while(i<list->size){
        if (current->prod.name == name){
            cout<<"The id is:"<<current->prod.productid<<endl;
            cout<<"the name is:"<<current->prod.name<<endl;
            cout<<"The price is:"<<current->prod.price<<endl;
            return;
        }
        else {
            current = current->next;
            i++;
            continue;
        }
    }
}
void searchbyPrice(List* list, double price){
    int i =0;
    element* current = new element();
    current = list->head;
    while(i<list->size){
        if (current->prod.price == price){
            cout<<"The id is:"<<current->prod.productid<<endl;
            cout<<"the name is:"<<current->prod.name<<endl;
            cout<<"The price is:"<<current->prod.price<<endl;
            return;
        }
        else {
            current = current->next;
            i++;
            continue;
        }
    }
}
void updateByProductid(List* list, string id){
    int i =0;
    element* current = new element();
    current = list->head;
    while(i<list->size){
        if (current->prod.productid == id){
            cout<<"The id is:"<<current->prod.productid<<endl;
            cout<<"the name is:"<<current->prod.name<<endl;
            cout<<"The price is:"<<current->prod.price<<endl;
            cout<<"The new id is:";
            cin>>current->prod.productid;
            cout<<"the new name is:";
            cin>>current->prod.name;
            cout<<"The new price is:";
            cin>>current->prod.price;
            return;
        }
        else {
            current = current->next;
            i++;
            continue;
        }
    }
}
int main(){
    List* list = createEmptylist();

    product p1 = createProduct("P01", "Pen", 10.0);
    product p2 = createProduct("P02", "Notebook", 75.0);
    product p3 = createProduct("P03", "Pencil", 2.5);
    product p4 = createProduct("P04", "Calculator", 55.0);

    addProductWithCondition(list, p1);
    addProductWithCondition(list, p2);
    addProductWithCondition(list, p3);
    addProductWithCondition(list, p4);

    display(list);

    cout << "\nSearch by name (Pen):\n";
    searchbyName(list, "Pen");

    cout << "\nSearch by price (75):\n";
    searchbyPrice(list, 75.0);

    cout << "\nUpdate product id P03:\n";
    updateByProductid(list, "P03");

    cout << "\nAfter update:\n";
    display(list);
    return 0;
}