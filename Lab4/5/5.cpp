#include <iostream>

struct Node {
	int number;
	Node* next;
};

struct ListNumber {
	int listLength;
	Node* head;
	Node* tail;
};

ListNumber* createEmptyList() {
	ListNumber* ls = new ListNumber;
	ls->listLength = 0;
	ls->head = nullptr;
	ls->tail = nullptr;
	return ls;
}

void add(int n, ListNumber* ls) {
	try {
		Node* newNode = new Node;
		newNode->number = n;
		newNode->next = nullptr;

		if (ls->listLength == 0) {
			ls->head = newNode;
			ls->tail = newNode;
		} else {
			ls->tail->next = newNode;
			ls->tail = newNode;
		}

		ls->listLength++;
	} catch (const std::bad_alloc&) {
		std::cerr << "Bibity bopity boo mem alloc failed\n";
	}
}

void printAllNodes(const Node* currentNode) {
	while (currentNode != nullptr) {
		std::cout << currentNode->number << " ";
		currentNode = currentNode->next;
	}
}

int sumListNumbers(const Node* currentNode) {
	int sum = 0;
	while (currentNode != nullptr) {
		sum += currentNode->number;
		currentNode = currentNode->next;
	}
	return sum;
}

void destroyList(ListNumber*& ls) {
	if (ls == nullptr) {
		return;
	}

	Node* current = ls->head;
	while (current != nullptr) {
		Node* next = current->next;
		delete current;
		current = next;
	}

	delete ls;
	ls = nullptr;
}

int main() {
	ListNumber* ls = createEmptyList();
	bool previousWasZero = false;

	while (true) {
		std::cout << "Enter a number: ";
		int n = 0;
		std::cin >> n;

		if (n == 0) {
			if (previousWasZero) {
				std::cout << "You entered 0 twice in a row. Exiting input.\n";
				break;
			}

			previousWasZero = true;
			std::cout << "You entered 0. Enter 0 again to stop, or a non-zero number to continue.\n";
			continue;
		}

		previousWasZero = false;
		add(n, ls);
	}

	std::cout << "All data in the list are: ";
	printAllNodes(ls->head);
	std::cout << "\nSummation of all numbers is: " << sumListNumbers(ls->head) << "\n";

	destroyList(ls);
	return 0;
}