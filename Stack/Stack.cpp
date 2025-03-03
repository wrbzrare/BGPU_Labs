#include "Stack.h"

int main(){
	system ("chcp 1251");
	system ("cls");
	Stack MyStack(5);
	MyStack.push(1);
	MyStack.push(2);
	MyStack.push(3);
	std::cout<<"Количество элементов в Стэке: "<<MyStack.count()<<std::endl;
	std::cout<<"Значение верхневого элемента в стэке: "<<MyStack.pop()<<std::endl;
	std::cout<<"Значение верхневого элемента в стэке после удаления предыдущего: "<<MyStack.pop()<<std::endl;
}
