#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int dill_2311110048) {
        data = dill_2311110048;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

void displayChild(TNode *node, int target) {
    if (node != NULL) {
        if (node->data == target) {
            if (node->left != NULL) {
                cout << "Child: " << node->left->data << endl;
            }
            if (node->right != NULL) {
                cout << "Child: " << node->right->data << endl;
            }
        } else {
            displayChild(node->left, target);
            displayChild(node->right, target);
        }
    }
}

void displayDescendant(TNode *node, int target) {
    if (node != NULL) {
        if (node->data == target) {
            preOrder(node);
        } else {
            displayDescendant(node->left, target);
            displayDescendant(node->right, target);
        }
    }
}

TNode* findNode(TNode* node, int target) {
    if (node == NULL) {
        return NULL;
    }
    if (node->data == target) {
        return node;
    }
    TNode* leftResult = findNode(node->left, target);
    if (leftResult != NULL) {
        return leftResult;
    }
    return findNode(node->right, target);
}

void addNode(TNode*& root) {
    int parentData, childData;
    char position;
    cout << "Masukkan data parent node: ";
    cin >> parentData;
    cout << "Masukkan data child node: ";
    cin >> childData;
    cout << "Masukkan posisi child (L/R): ";
    cin >> position;

    if (root == NULL) {
        root = new TNode(childData);
        cout << "Root node created with data: " << childData << endl;
        return;
    }

    TNode* parentNode = findNode(root, parentData);
    if (parentNode != NULL) {
        if (position == 'L' || position == 'l') {
            if (parentNode->left == NULL) {
                parentNode->left = new TNode(childData);
            } else {
                cout << "Left child already exists for node " << parentData << endl;
            }
        } else if (position == 'R' || position == 'r') {
            if (parentNode->right == NULL) {
                parentNode->right = new TNode(childData);
            } else {
                cout << "Right child already exists for node " << parentData << endl;
            }
        } else {
            cout << "Invalid position. Use 'L' for left or 'R' for right." << endl;
        }
    } else {
        cout << "Parent node with data " << parentData << " not found." << endl;
    }
}

int main() {
    TNode* root = NULL;

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Tambah node" << endl;
        cout << "2. Tampilkan tree" << endl;
        cout << "3. Tampilkan child" << endl;
        cout << "4. Tampilkan descendant" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addNode(root);
                break;
            case 2:
                cout << "Pre Order: ";
                preOrder(root);
                cout << endl;
                cout << "In Order: ";
                inOrder(root);
                cout << endl;
                cout << "Post Order: ";
                postOrder(root);
                cout << endl;
                break;
            case 3: {
                int target;
                cout << "Masukkan node target: ";
                cin >> target;
                displayChild(root, target);
                break;
            }
            case 4: {
                int target;
                cout << "Masukkan node target: ";
                cin >> target;
                displayDescendant(root, target);
                cout << endl;
                break;
            }
            case 5:
                cout << "Keluar." << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (choice != 5);

    return 0;
}