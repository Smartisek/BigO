#pragma once
#include <ostream>
using namespace std;
template<class T>
class MyVector {
	T* arr;
	int capacity;
	int n_size;
	void grow();
public:
	MyVector(int x = 5);
	void add(T item);
	void remove(int position);
	int size();
	T get(int position);
	template<class T>
	friend ostream& operator <<(ostream& out, MyVector<T>& item);
};

template<class T>
void MyVector<T>::grow() {
	T* temp = new T[capacity * 2];
	for (int i = 0; i < n_size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	capacity *= 2;
	
}

template<class T>
MyVector<T>::MyVector(int x) {
	arr = new T[x];
	capacity = x;
	n_size = 0;
}

template<class T>
void MyVector<T>::add(T item) {
	if (n_size == capacity) {
		grow();
	}
	arr[n_size] = item;
	n_size++;
}

template<class T>
void MyVector<T>::remove(int position) {
	if (position < 0 || position >= n_size) {
		throw logic_error("Array out of bounds");
	}
	for (int i = position; i < n_size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	n_size--;
}

template<class T>
int MyVector<T>::size() {
	return n_size;
}

template<class T>
T MyVector<T>::get(int position) {
	if (position < 0 || position >= n_size) {
		throw logic_error("Array out of bounds");
	}
	return arr[position];
}

template<class T>
ostream& operator <<(ostream& out, MyVector<T>& item) {
	out << "[";
	for (int i = 0; i < item.n_size; i++) {
		if (i != 0) {
			out << ", ";
		}
		out << item.arr[i];
	}
	out << "]";
	return out;
}