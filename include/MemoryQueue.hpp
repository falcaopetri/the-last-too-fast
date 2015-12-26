/*
    The Last: Too Fast
    ED - 2015/1
    UFSCar - São Carlos
*/
#ifndef MEMORY_QUEUE_H
#define MEMORY_QUEUE_H

#include "Queue.hpp"

using namespace tltf;

namespace tltf {

	template <class T>
	class MemoryQueue {
	private:
    Queue<T> _queue;
    /*
        Guarda o último elemento retirado da fila
    */
    T _previousElement;
    /*
        Informa se _previousElement possui informação ou lixo
    */
    bool _hasPreviousElement;
	public:
        MemoryQueue(); //construtor
        ~MemoryQueue(); //metodo destruitor
		bool push(T); //insere elemento no final da fila
		void pop(); //remove primeiro elemento
		T getCurrent(); //retorna o Elemento atual (1º elemento) da fila
		T getPrevious(); //retorna o último elemento retirado da fila, ou algum lixo
                            // caso hasPreviousElement() seja falso
		bool empty(); //retorna verdadeiro se Fila estiver vazio, falso caso contrario
		bool hasPreviousElement(); //retorna se _previousElement possui informação ou lixo
	};
}

template <class T>
tltf::MemoryQueue<T>::MemoryQueue () {
    _hasPreviousElement = false;
}

template <class T>
tltf::MemoryQueue<T>::~MemoryQueue () {
    while (!empty())
        pop();
}

template <class T>
bool tltf::MemoryQueue<T>::push(T element) {
    _queue.push(element);

    return true;
}

template <class T>
void tltf::MemoryQueue<T>::pop() {
    if (!empty())
    {
        _previousElement = _queue.front();
        _queue.pop();

        _hasPreviousElement = true;
    }
    else
    {
        _hasPreviousElement = false;
    }
}

template <class T>
bool tltf::MemoryQueue<T>::hasPreviousElement() {
    return _hasPreviousElement;
}

template <class T>
T tltf::MemoryQueue<T>::getCurrent() {
    return _queue.front();
}

template <class T>
T tltf::MemoryQueue<T>::getPrevious() {
    return _previousElement;
}

template <class T>
bool tltf::MemoryQueue<T>::empty() {
    return _queue.empty();
}

#endif
