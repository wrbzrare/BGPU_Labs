#include "BinaryTree.h"

int main() {
    system("chcp 1251");
    system("cls")

    BinaryTree tree;

    tree.Add(5);
    tree.Add(3);
    tree.Add(8);
    tree.Add(4);

    std::cout << "Содержит 4? " << (tree.Contains(4) ? "Да" : "Нет") << "\n";
    std::cout << "Элементов в дереве: " << tree.Count() << "\n";

    std::cout << "Inorder: ";
    for (int v : tree.Inorder()) std::cout << v << " ";
    std::cout << "\n";

    tree.Remove(3);
    std::cout << "После удаления 3, Count = " << tree.Count() << "\n";

    tree.Clear();
    std::cout << "После Clear, Count = " << tree.Count() << "\n";

    return 0;
}
