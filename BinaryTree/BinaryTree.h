#include <iostream>
#include <vector>

class BinaryTree {
    /*
    Класс Двоичное Дерево Поиска (BinaryTree)

    Поддерживает добавление, удаление, проверку наличия элемента,
    очистку дерева, подсчёт элементов и обходы (прямой, симметричный, обратный).
    */

private:
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node(int val) : value(val), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int count;

    // Вспомогательные функции
    Node* Add(Node* node, int value);
    Node* Remove(Node* node, int value);
    bool Contains(Node* node, int value);
    void Clear(Node* node);
    void Inorder(Node* node, std::vector<int>& result);
    void Preorder(Node* node, std::vector<int>& result);
    void Postorder(Node* node, std::vector<int>& result);

public:
    BinaryTree();                     // Конструктор
    ~BinaryTree();                    // Деструктор

    void Add(int value);             // Добавление элемента
    void Remove(int value);          // Удаление элемента
    bool Contains(int value);        // Проверка наличия
    void Clear();                    // Очистка дерева
    int Count();                     // Количество элементов

    std::vector<int> Inorder();      // Симметричный обход
    std::vector<int> Preorder();     // Прямой обход
    std::vector<int> Postorder();    // Обратный обход
    std::vector<int> GetEnumerator(); // Возвращает все элементы дерева (Inorder)
};
BinaryTree::BinaryTree() {
    root = nullptr;
    count = 0;
}

BinaryTree::~BinaryTree() {
    Clear();
}

void BinaryTree::Add(int value) {
    root = Add(root, value);
    count++;
}

BinaryTree::Node* BinaryTree::Add(Node* node, int value) {
    if (!node) return new Node(value);
    if (value < node->value)
        node->left = Add(node->left, value);
    else
        node->right = Add(node->right, value);
    return node;
}

void BinaryTree::Remove(int value) {
    if (Contains(value)) {
        root = Remove(root, value);
        count--;
    }
}

BinaryTree::Node* BinaryTree::Remove(Node* node, int value) {
    if (!node) return nullptr;
    if (value < node->value) {
        node->left = Remove(node->left, value);
    } else if (value > node->value) {
        node->right = Remove(node->right, value);
    } else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        } else {
            Node* successor = node->right;
            while (successor->left)
                successor = successor->left;
            node->value = successor->value;
            node->right = Remove(node->right, successor->value);
        }
    }
    return node;
}

bool BinaryTree::Contains(int value) {
    return Contains(root, value);
}

bool BinaryTree::Contains(Node* node, int value) {
    if (!node) return false;
    if (value == node->value) return true;
    if (value < node->value)
        return Contains(node->left, value);
    else
        return Contains(node->right, value);
}

void BinaryTree::Clear() {
    Clear(root);
    root = nullptr;
    count = 0;
}

void BinaryTree::Clear(Node* node) {
    if (!node) return;
    Clear(node->left);
    Clear(node->right);
    delete node;
}

int BinaryTree::Count() {
    return count;
}

std::vector<int> BinaryTree::Inorder() {
    std::vector<int> result;
    Inorder(root, result);
    return result;
}

void BinaryTree::Inorder(Node* node, std::vector<int>& result) {
    if (!node) return;
    Inorder(node->left, result);
    result.push_back(node->value);
    Inorder(node->right, result);
}

std::vector<int> BinaryTree::Preorder() {
    std::vector<int> result;
    Preorder(root, result);
    return result;
}

void BinaryTree::Preorder(Node* node, std::vector<int>& result) {
    if (!node) return;
    result.push_back(node->value);
    Preorder(node->left, result);
    Preorder(node->right, result);
}

std::vector<int> BinaryTree::Postorder() {
    std::vector<int> result;
    Postorder(root, result);
    return result;
}

void BinaryTree::Postorder(Node* node, std::vector<int>& result) {
    if (!node) return;
    Postorder(node->left, result);
    Postorder(node->right, result);
    result.push_back(node->value);
}

std::vector<int> BinaryTree::GetEnumerator() {
    // Возвращает элементы в симметричном порядке
    return Inorder();
}
