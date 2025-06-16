#include "List.h"

int main() {
    system("chcp 1251");
    system("cls");
	
    List myList;

    myList.add(5);
    myList.add(10);
    std::cout << "Размер: " << myList.size() << "\n"; // 2

    if (myList.contains(10)){
        std::cout << "Список содержит 10 \n";
    }

    int val = myList.get(1);
    std::cout << "Элемент под индексом 1: " << val << "\n";

    myList.set(0, 7);
    std::cout << "Элемент под индексом 0 после set: " << myList.get(0) << "\n";

    myList.remove(10);
    std::cout << "Размер после удаления: " << myList.size() << "\n";

    List* cloned = myList.clone();
    std::cout << "Размер клона: " << cloned->size() << "\n";

    delete cloned;

    myList.clear();
    std::cout << "Пустой ли список? " << (myList.isEmpty() ? "Да" : "Нет") << "\n";
}
