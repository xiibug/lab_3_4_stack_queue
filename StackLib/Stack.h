#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>

using namespace std;

template <class T>
class TStack
{
protected:
	int length;
	T* x;
	int ind;
public:

	TStack(int size = 0);
	TStack(TStack<T>& _v);
	~TStack();

	TStack<T>& operator =(const TStack<T>& _v);
	bool operator==(const TStack<T>& _v) const;

	void Push(T d);
	T Get();

	bool isFull() const;
	bool isEmpty() const;

	template <class T1>
	friend ostream& operator<< (ostream& ostr, const TStack<T1>& A);
	template <class T1>
	friend istream& operator >> (istream& istr, TStack<T1>& A);

	int Length() const;
};

template <class T1>
ostream& operator<< (ostream& ostr, const TStack<T1>& A) {
	for (int i = 0; i < A.ind; i++) {
		ostr << A.x[i] << endl;
	}
	return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TStack<T1>& A) {
	int count;
	istr >> count;
	for (int i = 0; i < count; i++) {
		T1 d;
		istr >> d;
		A.Push(d);
	}
	return istr;
}

template<class T>
inline TStack<T>::TStack(int size)
{
	if (size < 0) throw - 1;
	this->length = size;
	this->ind = 0;
	this->x = new T[size];
	for (int i = 0; i < this->length; i = i + 1)
		this->x[i] = 0;
}
template <class T>
TStack<T>::TStack(TStack<T>& _v)
{
	this->length = _v.length;
	this->x = new T[this->length];
	this->ind = _v.ind;
	for (int i = 0; i < this->length; i = i + 1)
		this->x[i] = _v.x[i];
}
template <class T>
TStack<T>::~TStack()
{
	this->length = 0;
	if (this->x != 0)
		delete[] this->x;
	else throw - 1;
	this->x = 0;
	this->ind = 0;
}

template<class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& _v)
{
	if (this == &_v)
		return *this;
	this->length = _v.length;
	delete[] x;
	this->x = new T[this->length];
	for (int i = 0; i < this->length; i++)
		this->x[i] = _v.x[i];
	this->ind = _v.ind;
	return *this;
}

template<class T>
inline bool TStack<T>::operator==(const TStack<T>& _v) const
{
	if (this->length != _v.length || this->ind != _v.ind) return false;
	for (int i = 0; i < ind; i++)
		if (this->x[i] != _v.x[i])
			return false;
	return true;
}


template<class T>
inline void TStack<T>::Push(T d)
{
	if (this->ind >= this->length)
		throw - 1;
	this->x[this->ind] = d;
	(this->ind)++;

}

template<class T>
inline T TStack<T>::Get()
{
	if (this->ind == 0)
		throw - 1;
	T d = this->x[this->ind - 1];
	(this->ind)--;
	return d;
}

template<class T>
inline bool TStack<T>::isFull() const
{
	return (this->ind >= this->length);
}

template<class T>
inline bool TStack<T>::isEmpty() const
{
	return (this->ind == 0);
}

template <class T>
int TStack<T>::Length() const
{
	return ind;
}


#endif