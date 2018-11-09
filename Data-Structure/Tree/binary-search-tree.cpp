#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    explicit Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* addNode(Node* root, int data);
    int maxElement(Node* root);
    int minElement(Node* root);
    int height(Node* root);
    void printNode(Node* root);
};

int BinarySearchTree::maxElement(Node *root) {
    while (root->right) {
        root = root->right;
    }
    return root->data;
}

int BinarySearchTree::minElement(Node *root) {
    while (root->left) {
        root = root->left;
    }
    return root->data;
}

int BinarySearchTree::height(Node *root) {
    if (!root) {
        return 0;
    } else{
        int height_l = height(root->left);
        int height_r = height(root->right);
        if (height_l < height_r) {
            return height_r + 1;
        } else{
            return height_l + 1;
        }
    }
}

Node* BinarySearchTree::addNode(Node* root, int data) {
   if (root == nullptr) {
       return new Node(data);
   }
   if (data < root->data) {
       root->left = addNode(root->left, data);
   } else if (data > root->data) {
       root->right = addNode(root->right, data);
   }
   return root;
}

void BinarySearchTree::printNode(Node* root) {
    if (root != nullptr) {
        printNode(root->left);
        printf("%d \n", root->data);
        printNode(root->right);
    }
}

int main() {
    auto* list = new BinarySearchTree();
    Node* root = nullptr;
    root = list->addNode(root, 5);
    root = list->addNode(root, 3);
    root = list->addNode(root, 6);
    list->printNode(root);
    std::cout << "Max:\t" << list->maxElement(root) << "\n";
    std::cout << "Min:\t" << list->minElement(root) << "\n";
    std::cout << "Height:\t" << list->height(root) << "\n";
}
