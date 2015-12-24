/*
    The Last: Too Fast
    ED - 2015/1
    UFSCar - São Carlos
*/
#ifndef QUEUE_H
#define QUEUE_H
namespace tltf {

	template <class T>
	class Queue {
	private:

    class Node{
    public:
        T item;
        Node *right;
    };

    Node *_header;
    Node *_last;


	public:
        Queue (); //construtor
        ~Queue (); //metodo destruidor
		bool push(T&); //insere elemento no final da fila
		void pop (); //remove primeiro elemento
		T front(); //mostra o primeiro elemento da fila
		bool empty(); //retorna verdadeiro se Fila estiver vazio, falso caso contrario
	};
}

template <class T>
tltf::Queue<T>::Queue () {
    _header = new Node(); //Cria primeiro nó
    _header->right = _header;
    _last = _header;
    _header->item = T();
}

template <class T>
tltf::Queue<T>::~Queue () {
    while (!empty())
        pop();
    delete (_header);
}

template <class T>
bool tltf::Queue<T>::push(T& element) {
    _last->right = new Node();
    _last = _last->right;
    _last->right = _header;
    _last->item = element;

    return true;
}

template <class T>
void tltf::Queue<T>::pop() {
    if (!empty())
    {
        Node* remove = _header->right;
        _header->right = _header->right->right;
        delete (remove);

        if (empty())
            _last = _header;
    }
}

template <class T>
T tltf::Queue<T>::front() {
    return _header->right->item;
}

template <class T>
bool tltf::Queue<T>::empty() {
    if (_header->right == _header)
        return true;
    else
        return false;
}

#endif
