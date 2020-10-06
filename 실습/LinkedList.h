#include <iostream>
#include <string>
#ifndef __LinkedList__
#define __LinkedList__

using namespace std;

template <class T >
class Node {
public:
	T data;
	Node<T>* link;
	Node<T>(){
		data=0;
		link=0;
	}
	Node<T>(T element) {
		data = element;
		link = 0;
	}
};

template <class T>
class LinkedList:public Node<T> {
protected:
	Node<T>* first;
	int current_size;
public:
	LinkedList<T>(){
		first = 0;
		current_size = 0;
	}

	int GetSize() {
		return current_size;
	}

	void Insert(T element) {
		Node<T>* newnode = new Node<T>(element);
		newnode->link = first;
		first = newnode;
		current_size++;
	}

	virtual bool Delete(T& element) {
		if (first == 0) {
			return false;
		}
		Node<T>* current = first, * previous = 0;
		while (1) {
			if (current->link == 0) {
				if (previous) {
					previous->link = current->link;
				}
				else {
					first = first->link;
				}
				break;
			}
			previous = current;
			current = current->link;
		}
		element = current->data;
		delete current;
		current_size--;
		return true;
	}

	void Print() {
		int i;
		Node<T>* list = first;
		for (i = 1; i <= current_size; i++) {
			cout << "[" << i << "|" << list->data << "]";
			list = list->link;
			if (i != current_size) {
				cout << "->";
			}
		}
		cout << endl;
	}

};

#endif
