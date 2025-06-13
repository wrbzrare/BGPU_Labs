#include "Queue.h"

int main(){
	system("chcp 1251");
	system("cls");
	Queue MyQueue(5);
	MyQueue.enqueue(52);
	MyQueue.enqueue(14);
	MyQueue.enqueue(88);
	std::cout<<"Кол-во элементов в очереди: "<<MyQueue.count()<<std::endl;
	std::cout<<"Элемент "<<MyQueue.dequeue()<<" удалён из очереди"<<std::endl; 
	std::cout<<"Элемент "<<MyQueue.peek()<<" первый в очереди"<<std::endl; 
}
