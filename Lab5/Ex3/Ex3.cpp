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
    return 0;
}