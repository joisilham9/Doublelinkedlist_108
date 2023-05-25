#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};


class Doublelinkedlist {
private: 
	Node* START;
public:
	Doublelinkedlist();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void travese();
	void revtraverse();
	void hapus();
	void searchData();
};

Doublelinkedlist::Doublelinkedlist() {
	START = NULL;
}

void Doublelinkedlist::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the studennt :";
	cin >> nim;
	cout << "\nEnter the name of the student : ";
	cin >> nm;
	Node* newNode = new Node(); //step 1
	newNode->noMhs = nim;// step2
	newNode->name = nm; //step 2

	//*inserting a node in the beginning of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START-> noMhs){
		cout << "\nDuplicate number not allowed" << endl;
		return;
	}
	newNode->next = START; // step3
	if (START != NULL)
		START->prev = newNode; // step 4
	newNode->prev = NULL;  // step 5
	START = newNode;  // step 6
	return;
    }
	//*inserting a node between two nodes in the list*/
	Node* current = START; // step 1.a
	Node* previous = NULL; // step 1.b
	while (current->next != NULL && current->next->noMhs < nim) // step 1.c
	{
		previous = current; // 1.d
		current = current->next;
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next;
	newNode->prev = current;
	if (current->next != NULL)
		current->next->prev = newNode;
		current->next = newNode;
}

bool Doublelinkedlist::search(int rollNo, Node** previous, Node** current) {
	*previous = START;
	*current = START;
	while (*current != NULL && rollNo != (*current)->noMhs) {
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}
 
bool Doublelinkedlist::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		START = current->next;

	delete current;
	return true;
}
