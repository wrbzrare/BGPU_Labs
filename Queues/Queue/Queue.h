#include <iostream>

class Queue {
	/*
	������� ����� �������
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
		����������� ������ �������
		:param capacity - ������������ ������ �������
		:param data - ��� �������� �������
		:param size - ������� ������ �������
		:param rear - ������ ������ ����� �������
		:param front - ������ �������� ����� �������
		
		������:
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
		���������� ������ �������
		*/
        delete[] data;
    }

    void enqueue(int item);
    /*
	���������� ������ �������� � �������
	
	������:
	>>> MyQueue.enqueue(5);
	*/

    int dequeue();
	/*
	��������� � �������� ������� �������
	
	:return: ������ ������� �������
	
	������:
	>>> MyQueue.dequeue();
	*/

    int count();
	/*
	��������� ���-�� ��������� � �������
	
	:return: ���-�� ��������� � �������
	
	������:
	>>> MyQueue.count();
	*/

    int peek();
	/*
	��������� ������� �������� � �������
	
	:return: ������ ������� �������
	
	������:
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
