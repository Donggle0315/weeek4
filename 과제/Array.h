#ifndef __ARRAY__
#define __ARRAY__

#include <iostream>
using namespace std;

template <class T>
class Array {
	protected:
		T* data;
		int len;
	public:
		Array(int size) {
			if (size <= 0) {
				data = 0;
				len = 0;
				cout << "Array 생성 실패" << endl;
			}
			else {
				data = new T[size];
				len = size;
			}
		}

		~Array() {
			delete(data);
		}

		int length() {
			return len;
		}

		T& operator[](int i) {
			static T tmp;
			if (i < 0 || i >= len) {
				cout << "Array bound error!" << endl;
				return tmp;
			}
			else {
				return data[i];
			}
		}

		T operator[](int i) const {
			if (i < 0 || i >= len) {
				cout << "Array bound error!" << endl;
				return 0;
			}
			else {
				return data[i];
			}
		}
		void print() {
			int i;
			cout << "[";
			for (i = 0; i < len; i++) {
				cout << data[i] << " ";
			}
			cout << "]" << endl;
		}
};

#endif