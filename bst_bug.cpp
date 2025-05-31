#include <iostream>
using namespace std;

class BinarySearchTree {
private:
    struct tree_node {
        int data;
        tree_node* left;
        tree_node* right;
        tree_node(int d) : data(d), left(nullptr), right(nullptr) {}
    };
    tree_node* root;

    void inorder(tree_node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(tree_node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(tree_node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    tree_node* insert(tree_node* node, int val) {
        if (!node) return new tree_node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        // 如果相等，不插入（BST不重複）
        return node;
    }

    tree_node* findMin(tree_node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    tree_node* remove(tree_node* node, int val) {
        if (!node) return nullptr;
        if (val < node->data) {
            node->left = remove(node->left, val);
        }
        else if (val > node->data) {
            node->right = remove(node->right, val);
        }
        else {
            // 找到要刪除的節點
            if (!node->left && !node->right) {
                // 無子節點
                delete node;
                return nullptr;
            }
            else if (!node->left) {
                tree_node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                tree_node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                // 有兩個子節點
                tree_node* minRight = findMin(node->right);
                node->data = minRight->data;
                node->right = remove(node->right, minRight->data);
            }
        }
        return node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void remove(int val) {
        root = remove(root, val);
    }

    void print_inorder() {
        inorder(root);
        cout << endl;
    }

    void print_preorder() {
        preorder(root);
        cout << endl;
    }

    void print_postorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    int choice, val;

    while (true) {
        cout << "\nBinary Search Tree Operations\n";
        cout << "1. Insert\n2. Remove\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                bst.insert(val);
                break;
            case 2:
                cout << "Enter value to remove: ";
                cin >> val;
                bst.remove(val);
                break;
            case 3:
                cout << "Inorder: ";
                bst.print_inorder();
                break;
            case 4:
                cout << "Preorder: ";
                bst.print_preorder();
                break;
            case 5:
                cout << "Postorder: ";
                bst.print_postorder();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

