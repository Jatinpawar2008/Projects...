
#include <iostream>
using namespace std;

class Item {
public:
    int code;
    Item* left;
    Item* right;

    Item(int c) {
        code = c;
        left = right = NULL;
    }
};

// Add Item
Item* addItem(Item* root, int code) {
    if (root == NULL)
        return new Item(code);

    if (code < root->code)
        root->left = addItem(root->left, code);
    else if (code > root->code)
        root->right = addItem(root->right, code);

    return root;
}

// Find Item
Item* findItem(Item* root, int key) {
    if (root == NULL || root->code == key)
        return root;

    if (key < root->code)
        return findItem(root->left, key);
    else
        return findItem(root->right, key);
}

// Find Minimum
Item* findMin(Item* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Remove Item
Item* removeItem(Item* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->code)
        root->left = removeItem(root->left, key);
    else if (key > root->code)
        root->right = removeItem(root->right, key);
    else {
        // No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // One child
        if (root->left == NULL) {
            Item* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            Item* temp = root->left;
            delete root;
            return temp;
        }
        // Two children
        Item* temp = findMin(root->right);
        root->code = temp->code;
        root->right = removeItem(root->right, temp->code);
    }
    return root;
}

// Display Inventory (Inorder)
void showInventory(Item* root) {
    if (root == NULL) return;
    showInventory(root->left);
    cout << root->code << " ";
    showInventory(root->right);
}

// Count Items
int countItems(Item* root) {
    if (root == NULL) return 0;
    return 1 + countItems(root->left) + countItems(root->right);
}

int main() {
    Item* root = NULL;
    int choice;

    while (true) {
        cout << "\n\n----===== INVENTORY CONTROL SYSTEM =====----\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Search Item\n";
        cout << "4. Show All Items\n";
        cout << "5. Total Items Count\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int x;
            cout << "Enter Item Code: ";
            cin >> x;
            root = addItem(root, x);
            cout << "Item added successfully";
        }
        else if (choice == 2) {
            int x;
            cout << "Enter Item Code: ";
            cin >> x;
            root = removeItem(root, x);
            cout << "Item removed successfully";
        }
        else if (choice == 3) {
            int x;
            cout << "Enter Item Code to search: ";
            cin >> x;
            if (findItem(root, x))
                cout << "Item FOUND";
            else
                cout << "Item NOT found";
        }
        else if (choice == 4) {
            cout << "Inventory Items: ";
            showInventory(root);
        }
        else if (choice == 5) {
            cout << "Total Items: " << countItems(root);
        }
        else if (choice == 6) {
            cout << "Program Closed";
            break;
        }
        else {
            cout << "Invalid choice!";
        }
    }
    return 0;
}
