#include <iostream>

class BinaryTree {
    /*
	Базовый класс Двоичное Дерево
    */
private:
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int val) {
            value = val;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;
    int count;

    Node* Add(Node* node, int value);
    Node* Remove(Node* node, int value);
    bool Contains(Node* node, int value);
    void Clear(Node* node);
    void Inorder(Node* node);
    void Preorder(Node* node);
    void Postorder(Node* node);

public:
    BinaryTree() {
        /*
        Конструктор класса BinaryTree

        Пример:
        >>> BinaryTree myTree;
        */
        root = nullptr;
        count = 0;
    }

    void Add(int value);
    void Remove(int value);
    bool Contains(int value);
    void Clear();
    int Count();

    void Inorder();  
    void Preorder();    
    void Postorder();  

    void GetEnumerator();
};

// Вспомогательная рекурсивная вставка
BinaryTree::Node* BinaryTree::Add(Node* node, int value) {
    if (node == nullptr) {
        count++;
        return new Node(value);
    }
    if (value < node->value)
        node->left = Add(node->left, value);
    else if (value > node->value)
        node->right = Add(node->right, value);
    return node;
}

void BinaryTree::Add(int value) {
    root = Add(root, value);
}

// Вспомогательная рекурсивная проверка
bool BinaryTree::Contains(Node* node, int value) {
    if (node == nullptr) return false;
    if (node->value == value) return true;
    if (value < node->value) return Contains(node->left, value);
    return Contains(node->right, value);
}

bool BinaryTree::Contains(int value) {
    return Contains(root, value);
}

// Вспомогательная рекурсивная очистка
void BinaryTree::Clear(Node* node) {
    if (node == nullptr) return;
    Clear(node->left);
    Clear(node->right);
    delete node;
}

void BinaryTree::Clear() {
    Clear(root);
    root = nullptr;
    count = 0;
}

int BinaryTree::Count() {
    return count;
}

// Вспомогательная функция для удаления
BinaryTree::Node* BinaryTree::Remove(Node* node, int value) {
    if (node == nullptr) return nullptr;

    if (value < node->value) {
        node->left = Remove(node->left, value);
    } else if (value > node->value) {
        node->right = Remove(node->right, value);
    } else {
        // найден узел
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            count--;
            return nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            count--;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            count--;
            return temp;
        } else {
            // два потомка: ищем минимальный в правом поддереве
            Node* minNode = node->right;
            while (minNode->left != nullptr)
                minNode = minNode->left;
            node->value = minNode->value;
            node->right = Remove(node->right, minNode->value);
        }
    }

    return node;
}

void BinaryTree::Remove(int value) {
    root = Remove(root, value);
}

// Симметричный обход
void BinaryTree::Inorder(Node* node) {
    if (node == nullptr) return;
    Inorder(node->left);
    std::cout << node->value << " ";
    Inorder(node->right);
}

void BinaryTree::Inorder() {
    Inorder(root);
    std::cout << "\n";
}

// Прямой обход
void BinaryTree::Preorder(Node* node) {
    if (node == nullptr) return;
    std::cout << node->value << " ";
    Preorder(node->left);
    Preorder(node->right);
}

void BinaryTree::Preorder() {
    Preorder(root);
    std::cout << "\n";
}

// Обратный обход
void BinaryTree::Postorder(Node* node) {
    if (node == nullptr) return;
    Postorder(node->left);
    Postorder(node->right);
    std::cout << node->value << " ";
}

void BinaryTree::Postorder() {
    Postorder(root);
    std::cout << "\n";
}

// GetEnumerator — просто вызывает Inorder
void BinaryTree::GetEnumerator() {
    /*
    Метод GetEnumerator — выводит все элементы дерева в симметричном порядке
    */
    Inorder();
}

