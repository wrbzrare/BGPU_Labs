#include "BinaryTree.h"

int main() {
	system("chcp 1251");
    system("cls");
    
    BinaryTree tree;

    tree.Add(10);
    tree.Add(5);
    tree.Add(15);
    tree.Add(3);

    std::cout << "�������� 5? " << (tree.Contains(5) ? "��" : "���") << "\n";

    std::cout << "������������ ����� (Inorder): ";
    tree.Inorder();

    std::cout << "������ ����� (Preorder): ";
    tree.Preorder();

    std::cout << "�������� ����� (Postorder): ";
    tree.Postorder();

    tree.Remove(5);
    std::cout << "����� �������� 5: ";
    tree.Inorder();

    std::cout << "����� ���������: " << tree.Count() << "\n";

    tree.Clear();
    std::cout << "������ �������. ���������: " << tree.Count() << "\n";

}

