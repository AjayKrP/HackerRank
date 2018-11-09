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
    Node* maxElement(Node* root);
    Node* minElement(Node* root);
    int height(Node* root);
    bool searchNode(int key, Node* root);
    Node* deleteElement(int key, Node* root);
    void printNode(Node* root);
};

Node* BinarySearchTree::deleteElement(int key, Node *root) {
    if (!root) {
        return root;
    }
    if (root->data < key) {
        root->right = deleteElement(key, root->right);
    } else if (root->data > key) {
        root->left = deleteElement(key, root->left);
    } else{
        if (!root->left) {
            auto *temp = root->right;
            delete(root);
            return temp;
        }
        else if (!root->right) {
            auto *temp = root->left;
            delete(root);
            return temp;
        }
        Node* temp = minElement(root->right);
        root->data = temp->data;
        root->right = deleteElement(temp->data, root->right);
    }
}

bool BinarySearchTree::searchNode(int key, Node *root) {
    if (!root) {
        return false;
    } else{
        if (root->data < key) {
            searchNode(key, root->right);
        } else if (root->data > key) {
            searchNode(key, root->left);
        } else if (root->data == key) {
            return true;
        }
    }
}

Node* BinarySearchTree::maxElement(Node *root) {
    while (root->right) {
        root = root->right;
    }
    return root;
}

Node* BinarySearchTree::minElement(Node *root) {
    while (root->left) {
        root = root->left;
    }
    return root;
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
    //50   30   25   75   82   28   63   70   4   43   74   35
    Node* root = nullptr;
    root = list->addNode(root, 50);
    root = list->addNode(root, 30);
    root = list->addNode(root, 25);
    root = list->addNode(root, 75);
    root = list->addNode(root, 82);
    root = list->addNode(root, 28);
    root = list->addNode(root, 63);
    root = list->addNode(root, 70);
    root = list->addNode(root, 4);
    root = list->addNode(root, 43);
    root = list->addNode(root, 74);
    root = list->addNode(root, 35);
    //list->printNode(root);
    std::cout << "Max:\t" << list->maxElement(root)->data << "\n";
    std::cout << "Min:\t" << list->minElement(root)->data << "\n";
    std::cout << "Height:\t" << list->height(root) << "\n";
    std::cout << list->searchNode(35, root);
    root = list->deleteElement(28, root);
    list->printNode(root);
}
