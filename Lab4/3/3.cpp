#include <iostream>
using namespace std;

struct student{
    int ID;
    string name;
    int year;
    string degree;
    void add(int ID){
        this->ID=ID;
    }
};
struct element{
    student student;
    element* next;
};
struct List{
    int n;
    element* head;
    element* tail;
};
List* createEmptyList(){
    List* ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}

void add(student s, List* ls){
    element* e = new element;
    e->student = s;
    e->next = nullptr;

    if (ls->n == 0){
        ls->head = e;
        ls->tail = e;
    } else {
        ls->tail->next = e;
        ls->tail = e;
    }

    ls->n++;
}

void printList(List* ls){
    element* current = ls->head;
    while (current != nullptr){
        cout << current->student.ID << " "
             << current->student.name << " "
             << current->student.year << " "
             << current->student.degree << endl;
        current = current->next;
    }
}
int main(){
    List* ls = createEmptyList();

    student s1{1, "Alya", 2, "Computer Science"};
    student s2{2, "Brian", 2, "Information Systems"};
    student s3{3, "Citra", 3, "Computer Engineering"};
    student s4{4, "Dimas", 1, "Software Engineering"};
    student s5{5, "Eka", 4, "Data Science"};

    add(s1, ls);
    add(s2, ls);
    add(s3, ls);
    add(s4, ls);
    add(s5, ls);

    printList(ls);
    return 0;
}