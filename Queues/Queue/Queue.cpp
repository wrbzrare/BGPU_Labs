#include "Queue.h"

int main(){
	system("chcp 1251");
	system("cls");
	Queue MyQueue(5);
	MyQueue.enqueue(52);
	MyQueue.enqueue(14);
	MyQueue.enqueue(88);
	std::cout<<"���-�� ��������� � �������: "<<MyQueue.count()<<std::endl;
	std::cout<<"������� "<<MyQueue.dequeue()<<" ����� �� �������"<<std::endl; 
	std::cout<<"������� "<<MyQueue.peek()<<" ������ � �������"<<std::endl; 
}
