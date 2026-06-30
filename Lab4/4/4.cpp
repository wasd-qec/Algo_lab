#include <iostream>
#include <string>

struct Student {
	int id;
	std::string name;
	int year;
	std::string program;
};

struct Node {
	Student student;
	Node* next;
};

struct ListStudent {
	int listLength;
	Node* head;
	Node* tail;
};

ListStudent* createEmptyList() {
	ListStudent* ls = new ListStudent;
	ls->listLength = 0;
	ls->head = nullptr;
	ls->tail = nullptr;
	return ls;
}

void add(Student s, ListStudent* ls) {
	try {
		Node* node = new Node;
		node->student = s;
		node->next = nullptr;

		if (ls->listLength == 0) {
			ls->head = node;
			ls->tail = node;
		} else if (ls->listLength > 0) {
			ls->tail->next = node;
			ls->tail = node;
		}

		ls->listLength++;
	} catch (const std::bad_alloc&) {
		std::cerr << "Bibity bopity boo mem alloc failed";
	}
}

void printStudent(Student s) {
	std::cout << s.id << " " << s.name << " " << s.year << " " << s.program << "\n";
}

// Recursion
// void printAllStudents(const Node *node) {
//     if (node == nullptr) return;
//     printStudent(node->student);
//     printAllStudents(node->next);
// }

void printAllStudents(const Node* node) {
	while (node != nullptr) {
		printStudent(node->student);
		node = node->next;
	}
}

void destroyList(ListStudent*& ls) {
	// Check if list pointer is pointing to anything.
	if (ls == nullptr) {
		return;
	}

	Node* current = ls->head;

	// Delete all nodes in the heap one by one.
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}

	delete ls;
	ls = nullptr;
}

int main() {
	ListStudent* ls = createEmptyList();

	// This creates list objects in heap.
	Student s1 = {111, "Caro", 2, "SE"};
	Student s2 = {222, "Monouk", 2, "AI"};
	Student s3 = {333, "Both", 2, "SE"};
	Student s4 = {444, "Thya", 2, "SE"};
	Student s5 = {555, "InNOutBurga", 2, "SE"};

	add(s1, ls);
	add(s2, ls);
	add(s3, ls);
	add(s4, ls);
	add(s5, ls);

	std::cout << "=== Added 5 ===\n";
	printAllStudents(ls->head);

	Student s6 = {666, "Vanheng", 2, "SE"};
	Student s7 = {777, "Lyda", 2, "SE"};

	add(s6, ls);
	add(s7, ls);

	std::cout << "=== Added 2 ===\n";
	printAllStudents(ls->head);

	destroyList(ls);
}