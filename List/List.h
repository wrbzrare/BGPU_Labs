#include <iostream>
#include <vector>

class List {
private:
    std::vector<int> data;

public:
    List() {
        /*
        ����������� ������ ������
        
        ������:
        >>> List MyList;
        */
    }

    void add(int value);
        /*
        ��������� ������� � ����� ������
        
        :param value - �������� ������������ ��������
        */

    void clear();
        /*
        ������� ������ �� ���� ���������
        */

    List* clone() {
        /*
        ������ ����� �������� ������
        
        :return - ��������� �� ����� ������-����
        */
        List* newList = new List();
        newList->data = this->data;
        return newList;
    }

    bool contains(int value);
        /*
        ���������, ���������� �� ������� � ������
        
        :param value - ������� ��������
        
        :return - true, ���� ������� ������, ����� false
        */

    int get(int index);
        /*
        ���������� ������� �� �������
        
        :param index - ������� ��������
        
        :return - �������� ��������
        */

    bool isEmpty();
        /*
        ���������, ���� �� ������
        
        :return - true, ���� ������ ����, ����� false
        */

    bool remove(int value);
        /*
        ������� ������ ��������� �������� �� ������
        
        :param value - �������� ��� ��������
        
        :return - true, ���� ������� �����, ����� false
        */


    bool set(int index, int value); 
        /*
        �������� ������� �� ������� �� ����� ��������
        
        :param index - ������� ��������
        :param value - ����� ��������
        
        :return - true, ���� �������, ����� false � ������� ������
        */

    int size();
        /*
        ���������� ������� ������ ������
        
        :return - ������ ������
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
        std::cout << "������: ������ ��� ���������\n";
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
        std::cout << "������: ������ ��� ���������\n";
        return false;
    }
    data[index] = value;
    return true;
}

int List::size() {
    return (int)data.size();
}
