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


	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START-> noMhs){
		cout << "\nDuplicate number not allowed" << endl;
		return;
	}
	newNode->next = START;
	if (START != NULL)
		START->prev = newNode;
	newNode->prev = NULL;
	START = newNode;
	return;
    }

	Node* current = START;
	Node* previous = NULL;
	while (current->next != NULL && current->next->noMhs < nim)
}
