#include "Deque.h"

int main(){
	system("chcp 1251");
	system("cls");
	Deque MyDeque(5);
	MyDeque.EnqueueFirst(52);
	MyDeque.EnqueueLast(42);
	MyDeque.EnqueueLast(32);
	std::cout<<"������ ������� �������: "<<MyDeque.PeekFirst()<<std::endl;
	std::cout<<"��������� ������� �������: "<<MyDeque.PeekLast()<<std::endl;
	MyDeque.EnqueueFirst(35);
	MyDeque.EnqueueLast(55);
	std::cout<<"����� ������ ������� �������: "<<MyDeque.PeekFirst()<<std::endl;
	std::cout<<"����� ��������� ������� �������: "<<MyDeque.PeekLast()<<std::endl;
}
