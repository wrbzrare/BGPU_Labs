#include <iostream>

class Deque {
	/*
	������� ����� ������������ �������
	*/
private:
    int* data;
    int size; 
    int capacity;
public:
    Deque(int capacity) {
    	/*
		����������� ������ ������������ �������
		:param capacity - ������������ ������ �������
		:param data - ��� �������� �������
		:param size - ������� ������ �������
		:param rear - ������ ������ ����� �������
		:param front - ������ �������� ����� �������
		
		������:
		>>> Deque MyDeque(5);
		*/
        this->capacity = capacity;
        this->data = new int[capacity];
        this->size = 0;
    }

    ~Deque() {
    	/*
		���������� ������ �������
		*/
        delete[] data;
    }

    void EnqueueFirst(int item);
    /*
	���������� ������ �������� � ������ �������
	*/
	
	void EnqueueLast(int item);
    /*
	���������� ������ �������� � ����� �������
	*/

    int DequeueFirst();
	/*
	��������� � �������� ������� �������
	
	:return: ������ ������� �������
	
	������:
	>>> MyDeque.dequeue();
	*/
	
	int DequeueLast();
	/*
	��������� � �������� ������� �������
	
	:return: ������ ������� �������
	
	������:
	>>> MyQueue.dequeue();
	*/

    int Count();
	/*
	��������� ���-�� ��������� � �������
	
	:return: ���-�� ��������� � �������
	
	������:
	>>> MyQueue.count();
	*/

    int PeekFirst();
	/*
	��������� ������� �������� � �������
	
	:return: ������ ������� �������
	
	������:
	>>> MyQueue.peek();
	*/
	
	int PeekLast();
	/*
	��������� ������� �������� � �������
	
	:return: ������ ������� �������
	
	������:
	>>> MyQueue.peek();
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
