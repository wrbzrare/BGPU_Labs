#include "BinaryTree.h"

int main() {
	system("chcp 1251");
    system("cls");
    
    BinaryTree tree;

    tree.Add(10);
    tree.Add(5);
    tree.Add(15);
    tree.Add(3);

    std::cout << "Содержит 5? " << (tree.Contains(5) ? "Да" : "Нет") << "\n";

    std::cout << "Симметричный обход (Inorder): ";
    tree.Inorder();

    std::cout << "Прямой обход (Preorder): ";
    tree.Preorder();

    std::cout << "Обратный обход (Postorder): ";
    tree.Postorder();

    tree.Remove(5);
    std::cout << "После удаления 5: ";
    tree.Inorder();

    std::cout << "Всего элементов: " << tree.Count() << "\n";

    tree.Clear();
    std::cout << "Дерево очищено. Элементов: " << tree.Count() << "\n";

}

