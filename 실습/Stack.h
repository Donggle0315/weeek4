#include "LinkedList.h"

template <class T>
class Stack:public LinkedList<T> {
	public:
		virtual bool Delete(T& element) {
			if (LinkedList<T>::first == 0) {
				return false;
			}
			Node<T>* current = LinkedList<T>::first;
			element = current->data;
			LinkedList<T>::first = LinkedList<T>::first->link;
			delete(current);
			LinkedList<T>::current_size--;
			return true;
		}
};
