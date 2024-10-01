#include "Templates.h"
#include "Pair.h"
#include "MyVector.h"
template <class T>
T greaterThan(T x, T y)
{
	return x > y ? x : y;
}

void templateMain_q1()
{
	int x, y;
	x = 5;
	y = 10;

	cout << "The largest int is " << greaterThan(x, y) << endl;

	double z, w;
	z = 9.65;
	w = 3.1415986548;
	cout << "The largest double is " << greaterThan(z, w) << endl;
}


template <class T>
T lessThan(T x, T y)
{
	return x < y ? x : y;
}
void templateMain_q2()
{
	int x, y;
	x = 5;
	y = 10;

	cout << "The smallest int is " << lessThan(x, y) << endl;

	double z, w;
	z = 9.65;
	w = 3.1415986548;
	cout << "The smallest double is " << lessThan(z, w) << endl;
}




template <class T>
void print(const list<T>& items)
{
	typename list<T>::const_iterator iter;  // typename is required to tell the compiler that list<T>::const_iterator is a type
	cout << "[";
	for (iter = items.begin(); iter != items.end(); iter++)
	{
		if (iter != items.begin())
			cout << ", ";
		cout << *iter;

	}
	cout << "]";
}
void templateMain_q3()
{
	list<string> strs = { "we", "are", "going", "to", "catch", "a" };
	list<int> nums = { 1,2,3,5,8,9,7,5,3 };

	print(strs);
	print(nums);
}

void templateMain_q4() {
	list <Pair<int, char>> items;

	for (int i = 65; i < 91; i++) {
		items.push_back(Pair<int, char>(i, (char)i));
	}
	print(items);
}

void templateMain_q5() {
	MyVector<int> nums;
	
	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		nums.add(1 + rand() % 20);
		cout << "start"<<i;
	}

	cout << nums;
}