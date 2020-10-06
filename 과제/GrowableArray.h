#ifndef __GROWABLEARRAY__
#define __GROWABLEARRAY__

#include "Array.h"
template <class T>
class GrowableArray :public Array<T> {
	protected:
		T* tmpArray;
	public:
		GrowableArray(int a) :Array<T>(a) {
			Array<T>::len = a;
		}

		~GrowableArray() {
			;
		}

		T& operator[](int i) {
			if (i > Array<T>::len) {
				int j;
				tmpArray = new T[2 * Array<T>::len];
				for (j = 0; j < Array<T>::len; j++) {
					tmpArray[j] = Array<T>::data[j];
				}
				for (j = Array<T>::len; j < 2 * Array<T>::len; j++) {
					tmpArray[j] = 0;
				}
				delete(Array<T>::data);
				Array<T>::data = tmpArray;
				Array<T>::len = 2 * Array<T>::len;
			}
			return Array<T>::operator[](i);
		}

		T operator[](int i)const {
			return Array<T>::operator[](i);
		}
};
#endif