#include <iostream>
#include <vector>

class List {
private:
    std::vector<int> data;

public:
    List() {
        /*
        Конструктор класса Список
        
        Пример:
        >>> List MyList;
        */
    }

    void add(int value);
        /*
        Добавляет элемент в конец списка
        
        :param value - значение добавляемого элемента
        */

    void clear();
        /*
        Очищает список от всех элементов
        */

    List* clone() {
        /*
        Создаёт копию текущего списка
        
        :return - указатель на новый список-клон
        */
        List* newList = new List();
        newList->data = this->data;
        return newList;
    }

    bool contains(int value);
        /*
        Проверяет, содержится ли элемент в списке
        
        :param value - искомое значение
        
        :return - true, если элемент найден, иначе false
        */

    int get(int index);
        /*
        Возвращает элемент по индексу
        
        :param index - позиция элемента
        
        :return - значение элемента
        */

    bool isEmpty();
        /*
        Проверяет, пуст ли список
        
        :return - true, если список пуст, иначе false
        */

    bool remove(int value);
        /*
        Удаляет первое вхождение элемента из списка
        
        :param value - значение для удаления
        
        :return - true, если элемент удалён, иначе false
        */


    bool set(int index, int value); 
        /*
        Заменяет элемент по индексу на новое значение
        
        :param index - позиция элемента
        :param value - новое значение
        
        :return - true, если успешно, иначе false с выводом ошибки
        */

    int size();
        /*
        Возвращает текущий размер списка
        
        :return - размер списка
        */
};

void List::add(int value) {
    data.push_back(value);
}

void List::clear() {
    data.clear();
}

bool List::contains(int value) {
    for (int v : data) {
        if (v == value) return true;
    }
	return false;
}

int List::get(int index) {
    if (index < 0 || index >= (int)data.size()) {
        std::cout << "Ошибка: индекс вне диапазона\n";
        return 0;
    }
    return data[index];
}

bool List::isEmpty() {
    return data.empty();
}

bool List::remove(int value) {
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] == value) {
            data.erase(data.begin() + i);
            return true;
        }
    }
    return false;
}

bool List::set(int index, int value) {
    if (index < 0 || index >= (int)data.size()) {
        std::cout << "Ошибка: индекс вне диапазона\n";
        return false;
    }
    data[index] = value;
    return true;
}

int List::size() {
    return (int)data.size();
}
