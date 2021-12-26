#include <iostream>
using namespace std;

class Node {
private:
	int data;
	Node* next;
	Node* previous;
public:
	Node(int initdata) {
		data = initdata;
		next = NULL;
		previous = NULL;
	}
	void setData(int newdata) {
		data = newdata;
	}
	int getData() {
		return data;
	}
	Node* getNext() {
		return next;
	}
	void setNext(Node *newnext) {
		next = newnext;
	}
	Node* getPrev() {
		return previous;
	}
	void setPrev(Node* newprev) {
		previous = newprev;
	}
};
class List {
private:
	Node* head;
public:
	List() {
		head = NULL;
	}
	bool isEmpty() {
		return head == NULL;
	}
	void push_back(int item) {
		Node* current = head;
		Node* prev_value = NULL;
		Node* temp = new Node(item);
		if (head == NULL) {
			temp->setNext(head);
			head = temp;
		}
		else {
			while (current->getNext() != NULL) {
				prev_value = current;
				current = current->getNext();
				
			}
			current->setNext(temp);
			prev_value = current;
			current = current->getNext();
			current->setPrev(prev_value);
			current->setNext(NULL);
		}
		

	}
	void push_front(int item) {
		Node* temp = new Node(item);
		temp->setNext(head);
		if (head != NULL) {
			head->setPrev(temp);
		}
		head = temp;
	}
	void pop_back() {
		if (head->getNext() == NULL) {
			delete head;
			head = NULL;
		}
		else {
			Node* current = head;
			while (current->getNext() != NULL) {
				current = current->getNext();
			}
			current->getPrev()->setNext(NULL);
			delete current;
			current = NULL;
		}
	}
	void pop_front() {
		head = head->getNext();
		if (head != NULL) {
			head->setPrev(NULL);
		}
		
	}
	int get_size() {
		Node* current = head;
		int counter = 0;
		while (current != NULL) {
			counter++;
			current = current->getNext();
		}
		return counter;
	}
	void insert(int item, int index) {
		
		Node* current = head;
		Node* temp = new Node(item);
		if (index == 1) {
			temp->setNext(head);
			head->setPrev(temp);
			head = temp;
		}
		else {
			for (int i = 1; i < index; i++) {
				current = current->getNext();
			}
			current->getPrev()->setNext(temp);
			temp->setPrev(current->getPrev());
			temp->setNext(current);
			current->setPrev(temp);
		}

	}
	int at(int index) {
		Node* current = head;
		for (int i = 1; i < index; i++) {
			current = current->getNext();
		}
		return current->getData();

	}
	void remove(int index) {
		Node* current = head;
		for (int i = 1; i < index; i++) {
			current = current->getNext();
		}
		if (current->getPrev() != NULL) {
			current->getPrev()->setNext(current->getNext());
		}
		else {
			head = current->getNext();
		}
		if (current->getNext() != NULL) {
			current->getNext()->setPrev(current->getPrev());
		}
		else {
			current->getPrev()->setNext(NULL);
		}
		
		delete current;
	}
	void clear() {
		Node* current = head;
		while (current->getNext() != NULL) {
			current = head->getNext();
			delete head;
			head = current;

		}
		delete head;
		head = NULL;
	}
	void set_el(int index, int new_value) {
		Node* current = head;
		for (int i = 1; i < index; i++) {
			current = current->getNext();
		}
		current->setData(new_value);
	}
	bool Contains(List* List) {
		Node* current = head;
		Node* current_seek = List->head;
		bool check = false;
		while (current != NULL) {
			if (current->getData() == current_seek->getData()) {
				check = true;
				current = current->getNext();
				current_seek = current_seek->getNext();
				break;
			}
			else {
				current = current->getNext();
			}
		}
		if (check) {
			while (current != NULL) {
				if (current->getData() == current_seek->getData()) {
					if (current_seek->getNext() == NULL) {
						current_seek = current_seek->getNext();
						break;
					}
					else {
						current = current->getNext();
						current_seek = current_seek->getNext();
					}
				}
				else {
					check = false;
					break;
				}
			}
			if (current == NULL && current_seek != NULL) {
				check = false;
			}
		}
		return check;
	}
	friend ostream& operator << (ostream &stream, const List &list) {
		Node* current = list.head;
		while (current != NULL) {
			stream << current->getData() << "->";
			current = current->getNext();
		}
		stream << "X|\n";
		return stream;
	}
};


int main() {
	List myList;

	myList.push_front(12);
	myList.push_front(15);
	myList.push_front(13);
	myList.push_front(14);
	//myList.push_front(15);
	//myList.push_front(17);
	//myList.push_front(16);
	List myList2;
	//myList2.push_front(11);
	myList2.push_front(12);
	myList2.push_front(13);
	myList2.push_front(14);
	cout << myList.isEmpty() << "\n";
	cout << myList;
	cout << myList2;
	cout << myList.Contains(&myList2);
	
	
	
	return 0;
}
