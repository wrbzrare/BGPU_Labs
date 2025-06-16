#include "List.h"

int main() {
	system("chcp 1251");
	system("cls");
	
    List myList;

    myList.add(5);
    myList.add(10);
    std::cout << "������: " << myList.size() << "\n"; // 2

    if (myList.contains(10))
        std::cout << "������ �������� 10 \n";

    int val = myList.get(1);
    std::cout << "������� ��� �������� 1: " << val << "\n";

    myList.set(0, 7);
    std::cout << "������� ��� �������� 0 ����� set: " << myList.get(0) << "\n";

    myList.remove(10);
    std::cout << "������ ����� ��������: " << myList.size() << "\n";

    List* cloned = myList.clone();
    std::cout << "������ �����: " << cloned->size() << "\n";

    delete cloned;

    myList.clear();
    std::cout << "������ �� ������? " << (myList.isEmpty() ? "��" : "���") << "\n";

    return 0;
}

