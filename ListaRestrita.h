#ifndef LISTA_RESTRITA_H
#define LISTA_RESTRITA_H

#include <cstdlib>

using namespace std;


template <class T>
class ListaRestrita
{
public:
	ListaRestrita(unsigned max);
	~ListaRestrita();

	bool push_back(T);
	bool push_front(T);
	bool pop_back(T &);
	bool pop_front(T &);

	void print();
private:
	unsigned max;
	unsigned front;
	int back;
	T *array;
};


template <class T>
ListaRestrita<T>::ListaRestrita(unsigned max){
	this->max = max;
	back = -1;
	front = 0;
	array =  new T[max];
}

template <class T>
ListaRestrita<T>::~ListaRestrita(){
	delete [] array;
}

template <class T>
bool ListaRestrita<T>::push_back(T t){
	if(back == max - 1){
		return false;
	}

	back++;
	array[back] = t;
	return true;
}

template <class T>
bool ListaRestrita<T>::push_front(T t){
	if(back == max - 1){
		return false;
	}
	back++;
	for(unsigned i = 0; i <= back; i++){
		array[back + 1 - i] = array[back - i];
	}
	array[0] = t;

	return true;
}

template <class T>
bool ListaRestrita<T>::pop_back(T &t){
	if(back == -1){
		return false;
	}

	t = array[back];
	back--;

	return true;
}

template <class T>
bool ListaRestrita<T>::pop_front(T &t){
	if(back == -1){
		return false;
	}

	t = array[0];

	for(unsigned i = 0; i <= back; i++){
		array[back + i] = array[back + i + 1];
	}
	back--;
	

	return true;
}

template <class T>
void ListaRestrita<T>::print(){
	if(back < 0){
		return;
	}
	for(int i = 0; i <= back; i++){
		std::cout << array[i] << endl;
	}
}


#endif