#include <iostream>

class Queue {
	/*
	Базовый класс Очередь
	*/
private:
    int* data;
    int front;
    int rear; 
    int size; 
    int capacity;

public:
    Queue(int capacity) {
    	/*
		Конструктор класса Очередь
		:param capacity - Максимальный размер очереди
		:param data - Все элементы очереди
		:param size - Текущий размер очереди
		:param rear - Индекс задней части очереди
		:param front - Индекс передней части очереди
		
		Пример:
		>>> Queue MyQueue(5);
		*/
        this->capacity = capacity;
        this->data = new int[capacity];
        this->front = 0;
        this->rear = 0;
        this->size = 0;
    }

    ~Queue() {
    	/*
		Деструктор класса Очередь
		*/
        delete[] data;
    }

    void enqueue(int item);
    /*
	Добавление нового элемента в очередь
	
	Пример:
	>>> MyQueue.enqueue(5);
	*/

    int dequeue();
	/*
	Получение и удаление первого элемета
	
	:return: Первый элемент очереди
	
	Пример:
	>>> MyQueue.dequeue();
	*/

    int count();
	/*
	Получение кол-ва элементов в очереди
	
	:return: Кол-во элементов в очереди
	
	Пример:
	>>> MyQueue.count();
	*/

    int peek();
	/*
	Получение первого элемента в очереди
	
	:return: Первый элемент очереди
	
	Пример:
	>>> MyQueue.peek();
	*/
};

void Queue::enqueue(int item) {
        if (size == capacity) {
            std::cout << "The queue is full." << std::endl;
            return;
        }
        data[rear] = item;
        rear = rear + 1; 
        size++;
    }

int Queue::dequeue() {
        if (size == 0) {
            std::cout << "InvalidOperationException" << std::endl;
            return -1; 
        }
        int item = data[front];
        front = front + 1; 
        size--;
        return item;
    }

int Queue::count() {
    return size;
}

int Queue::peek() {
    if (size == 0) {
        std::cout << "InvalidOperationException" << std::endl;
        return -1; 
    }
    return data[front];
}
