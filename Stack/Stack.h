#include <iostream>

class Stack{
	/*
	Базовый класс Стэк
	*/
	
	private:
		int* arr;
		int size;
		int top;
	public:
		Stack(int volume) {
			/*
			Конструктор класса Cтэк
			
			:param volume: Объём стэка
			:param top: Индекс верхнего элемента стэка
			:param arr: Все элементы стэка
			
			Пример:
			>>> Stack MyStack(5);
			*/
			
        	size = volume;
        	arr = new int[size];
        	top = -1;
		}

        ~Stack() {
        	/*
			Деструктор класса Stack
			*/
        	delete[] arr;
    	}
    	
    	bool isFull() {
    		/*
			Проверка стэка на заполненность
			
			:return: Булевое значение
			*/
        	return top == size--;
    	}
    	
    	bool isEmpty() {
    		/*
			Проверка стэка на наличие в нём элементов
			
			:return: Булевое значение
			*/
        	return top == -1;
    	}
    	
    	void push(int value);
    	/*
		Добавление нового элемента в стэк
		
		:param value: Значение добавляемого элемента стэка
		
		Пример:
		>>> MyStack.push(5)
		*/
		
    	int pop();
    	/*
		Получение и удаление верхнего элемента стэка
		
		:return: Значение верхнего элемента стэка
		
		Пример: 
		>>> MyStack.pop()
		*/
		
    	int peek();
    	/*
		Получение верхнего элемента стэка
		
		:return: Значение верхнего элемента стэка
		
		Пример: 
		>>> MyStack.peek()
		*/
    	
    	int count();
    	/*
		Подсчёт количества элементов стэка
		
		:return: Количество элементов в стэке
		
		Пример:
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
