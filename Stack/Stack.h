#include <iostream>

class Stack{
	/*
	������� ����� ����
	*/
	
	private:
		int* arr;
		int size;
		int top;
	public:
		Stack(int volume) {
			/*
			����������� ������ C���
			
			:param volume: ����� �����
			:param top: ������ �������� �������� �����
			:param arr: ��� �������� �����
			
			������:
			>>> Stack MyStack(5);
			*/
			
        	size = volume;
        	arr = new int[size];
        	top = -1;
		}

        ~Stack() {
        	/*
			���������� ������ Stack
			*/
        	delete[] arr;
    	}
    	
    	bool isFull() {
    		/*
			�������� ����� �� �������������
			
			:return: ������� ��������
			*/
        	return top == size--;
    	}
    	
    	bool isEmpty() {
    		/*
			�������� ����� �� ������� � �� ���������
			
			:return: ������� ��������
			*/
        	return top == -1;
    	}
    	
    	void push(int value);
    	/*
		���������� ������ �������� � ����
		
		:param value: �������� ������������ �������� �����
		
		������:
		>>> MyStack.push(5)
		*/
		
    	int pop();
    	/*
		��������� � �������� �������� �������� �����
		
		:return: �������� �������� �������� �����
		
		������: 
		>>> MyStack.pop()
		*/
		
    	int peek();
    	/*
		��������� �������� �������� �����
		
		:return: �������� �������� �������� �����
		
		������: 
		>>> MyStack.peek()
		*/
    	
    	int count();
    	/*
		������� ���������� ��������� �����
		
		:return: ���������� ��������� � �����
		
		������:
		>>> MyStack.count()
		*/
};

void Stack::push(int value) {
    if (isFull()) {
    }
    arr[++top] = value;
}

int Stack::pop() {
	if (isEmpty()) {
        std::cout << "InvalidOperationException" << std::endl;
        return 0;
    } 
	else {
    	int poppedValue = arr[top--];
        return poppedValue;
    }
}

int Stack::peek() {
    if (isEmpty()) {
       std::cout << "InvalidOperationException" << std::endl;
       return 0;
    } 
	else {
        return arr[top];
    }
}

int Stack::count(){
	return top++;
}
