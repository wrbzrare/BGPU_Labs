#include "Deque.h"

int main(){
	system("chcp 1251");
	system("cls");
	Deque MyDeque(5);
	MyDeque.EnqueueFirst(52);
	MyDeque.EnqueueLast(42);
	MyDeque.EnqueueLast(32);
	std::cout<<"Первый элемент очереди: "<<MyDeque.PeekFirst()<<std::endl;
	std::cout<<"Последний элемент очереди: "<<MyDeque.PeekLast()<<std::endl;
	MyDeque.EnqueueFirst(35);
	MyDeque.EnqueueLast(55);
	std::cout<<"Новый первый элемент очереди: "<<MyDeque.PeekFirst()<<std::endl;
	std::cout<<"Новый последний элемент очереди: "<<MyDeque.PeekLast()<<std::endl;
}
