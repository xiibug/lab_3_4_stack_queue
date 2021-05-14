#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class TQueue
{
protected:
	int length;
	T* x;
	int ind;
	int end;
	int count;
public:


	TQueue(int size = 0);
	TQueue(TQueue<T>& _v);
	~TQueue();

	void Push(T d);
	T Get();

	bool isFull() const;
	bool isEmpty() const;

	TQueue<T>& operator =(const TQueue<T>& _v);
	bool operator==(const TQueue<T>& _v) const;

	template <class T1>
	friend ostream& operator<< (ostream& ostr, const TQueue<T1>& A);
	template <class T1>
	friend istream& operator >> (istream& istr, TQueue<T1>& A);

	template <class T1>
	friend ofstream& operator<< (ofstream& ostr, const TQueue<T1>& A);
	template <class T1>
	friend ifstream& operator >> (ifstream& istr, TQueue<T1>& A);

	int Length() const;

	T FindMin() const;
	T FindMax() const;
};

template <class T1>
ostream& operator<< (ostream& ostr, const TQueue<T1>& A) {
	for (int i = A.ind; i < A.end; (++i) % A.length) {
		ostr << A.x[i] << endl;
	}
	return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TQueue<T1>& A) {
	int count;
	istr >> count;
	for (int i = 0; i < count; i++) {
		T1 d;
		istr >> d;
		A.Push(d);
	}
	return istr;
}

template<class T1>
ofstream& operator<<(ofstream& ostr, const TQueue<T1>& A)
{
	ostr << A.length << ' ' << A.count << endl;
	for (int i = A.ind; i < A.end; (++i) % A.length) {
		ostr << A.x[i] << endl;
	}
	return ostr;
}

template<class T1>
ifstream& operator>>(ifstream& istr, TQueue<T1>& A)
{
	int count;
	istr >> A.length >> count;
	A.x = new T1[A.length];
	A.ind = 0;
	A.end = 0;
	for (int i = 0; i < count; i++) {
		T1 d;
		istr >> d;
		A.Push(d);
	}
	return istr;
}


template<class T>
inline TQueue<T>::TQueue(int size)
{
	if (size < 0) throw - 1;
	this->length = size;
	this->ind = 0;
	this->end = 0;
	this->count = 0;
	this->x = new T[size];
	for (int i = 0; i < this->length; i = i + 1)
		this->x[i] = 0;
}

template <class T>
TQueue<T>::TQueue(TQueue<T>& _v)
{
	this->length = _v.length;
	this->x = new T[this->length];
	this->ind = _v.ind;
	this->end = _v.end;
	this->count = _v.count;

	for (int i = 0; i < this->length; i = i + 1)
		this->x[i] = _v.x[i];
}
template <class T>
TQueue<T>::~TQueue()
{
	this->length = 0;
	if (this->x != 0)
		delete[] this->x;
	else throw - 1;
	this->x = 0;
	this->ind = 0;
	this->end = 0;
	this->count = 0;
}

template<class T>
inline void TQueue<T>::Push(T d)
{
	if (this->count >= this->length)
		throw - 1;
	this->x[this->end % this->length] = d;
	this->end = (this->end + 1) % this->length;
	this->count++;
}

template<class T>
inline T TQueue<T>::Get()
{
	if (this->count == 0)
		throw - 1;
	T d = this->x[this->ind];
	this->ind = (this->ind + 1) % this->length;
	this->count--;
	return d;
}

template<class T>
inline bool TQueue<T>::isFull() const
{
	return count == length;
}

template<class T>
inline bool TQueue<T>::isEmpty() const
{
	return count == 0;
}


template <class T>
TQueue<T>& TQueue<T>::operator =(const TQueue<T>& _v)
{
	if (this == &_v)
		return *this;
	this->length = _v.length;
	delete[] x;
	this->x = new T[this->length];
	for (int i = 0; i < this->length; i++)
		this->x[i] = _v.x[i];
	this->ind = _v.ind;
	this->end = _v.end;
	this->count = _v.count;
	return *this;
}

template<class T>
inline bool TQueue<T>::operator==(const TQueue<T>& _v) const
{
	if (this->count != _v.count || this->ind != _v.ind || this->end != _v.end)
		return false;
	for (int i = 0; i < count; i++)
		if (this->x[(i + ind) % this->length] != _v.x[(i + ind) % this->length])
			return false;
	return true;
}

template <class T>
int TQueue<T>::Length() const
{
	return count;
}

template<class T>
inline T TQueue<T>::FindMin() const
{
	if (this->isEmpty()) throw - 1;
	T min = this->x[ind];
	for (int i = 0; i <count; i++)
		if (this->x[(i+this->ind)%this->length] < min)
			min = this->x[(i + this->ind) % this->length];
	return min;
}

template<class T>
inline T TQueue<T>::FindMax() const
{
	if (this->isEmpty()) throw - 1;
	T max = this->x[ind];
	for (int i = 1; i < count; i++)
		if (this->x[(i + this->ind) % this->length] > max)
			max = this->x[(i + this->ind) % this->length];
	return max;
}


#endif