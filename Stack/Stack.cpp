#include "Stack.h"

int main(){
	system ("chcp 1251");
	system ("cls");
	Stack MyStack(5);
	MyStack.push(1);
	MyStack.push(2);
	MyStack.push(3);
	std::cout<<"���������� ��������� � �����: "<<MyStack.count()<<std::endl;
	std::cout<<"�������� ���������� �������� � �����: "<<MyStack.pop()<<std::endl;
	std::cout<<"�������� ���������� �������� � ����� ����� �������� �����������: "<<MyStack.pop()<<std::endl;
}
