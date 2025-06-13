#include <iostream>

class Deque {
	/*
	Базовый класс Двусторонняя Очередь
	*/
private:
    int* data;
    int size; 
    int capacity;
public:
    Deque(int capacity) {
    	/*
	Конструктор класса Двусторонняя Очередь
		
	:param capacity - Максимальный размер очереди
	:param data - Все элементы очереди
	:param size - Текущий размер очереди
		
	Пример:
	>>> Deque MyDeque(5);
	*/
        this->capacity = capacity;
        this->data = new int[capacity];
        this->size = 0;
    }

    ~Deque() {
    	/*
	Деструктор класса Очередь
	*/
        delete[] data;
    }

    void EnqueueFirst(int item);
	/*
	Добавление нового элемента в начало очереди
	
	:param item - Значение добавляемого элемента
	
	Пример:
	>>> MyDeque.EnqueueFirst(5);
	*/
	
	void EnqueueLast(int item);
	/*
	Добавление нового элемента в конец очереди
	
	:param item - Значение добавляемого элемента
	
	Пример:
	>>> MyDeque.EnqueueLast(5);
	*/

    int DequeueFirst();
	/*
	Получение и удаление первого элемета
	
	:return: Первый элемент очереди
	
	Пример:
	>>> MyDeque.DequeueFirst();
	*/
	
	int DequeueLast();
	/*
	Получение и удаление последнего элемета
	
	:return: Последний элемент очереди
	
	Пример:
	>>> MyDeque.DequeueLast();
	*/

    int Count();
	/*
	Получение кол-ва элементов в очереди
	
	:return: Кол-во элементов в очереди
	
	Пример:
	>>> MyDeque.Count();
	*/

    int PeekFirst();
	/*
	Получение первого элемента в очереди
	
	:return: Первый элемент очереди
	
	Пример:
	>>> MyDeque.peek();
	*/
	
	int PeekLast();
	/*
	Получение последнего элемента в очереди
	
	:return: Последний элемент очереди
	
	Пример:
	>>> MyDeque.peek();
	*/
};

void Deque::EnqueueFirst(int item) {
        if (size == capacity) {
            std::cout << "The deque is full." << std::endl;
            return;
        }
        for (int i = size; i > 0; --i) {
            data[i] = data[i - 1];
        }
        data[0] = item;
        size++;
    }



void Deque::EnqueueLast(int item) {
        if (size == capacity) {
            std::cout << "The deque is full." << std::endl;
            return;
        }
        data[size] = item;
        size++;
    }

int Deque::DequeueFirst() {
        if (size == 0) {
            std::cout << "The deque is empty." << std::endl;
            return -1;
        }
        int item = data[0];
        for (int i = 1; i < size; ++i) {
            data[i - 1] = data[i];
        }
        size--;
        return item;
    }

int Deque::DequeueLast(){
	if (size == 0) {
    	std::cout << "InvalidOperationException" << std::endl;
		return -1;
	}
    size--;
    return data[size];
}

int Deque::Count() {
    return size;
}

int Deque::PeekLast() {
    if (size == 0) {
        std::cout << "InvalidOperationException" << std::endl;
        return -1; 
    }
    return data[size-1];
}

int Deque::PeekFirst() {
    if (size == 0) {
        std::cout << "InvalidOperationException" << std::endl;
        return -1; 
    }
    return data[0];
}
