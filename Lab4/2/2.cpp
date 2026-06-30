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

