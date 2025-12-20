#include <iostream>
using namespace std;

class Book {
public:
    int code;
    Book* left;
    Book* right;

    Book(int c) {
        code = c;
        left = right = NULL;
    }
};

Book* addBook(Book* root, int code) {
    if (root == NULL)
        return new Book(code);

    if (code < root->code)
        root->left = addBook(root->left, code);
    else if (code > root->code)
        root->right = addBook(root->right, code);

    return root;
}


Book* findBook(Book* root, int key) {
    if (root == NULL || root->code == key)
        return root;

    if (key < root->code)
        return findBook(root->left, key);
    else
        return findBook(root->right, key);
}


Book* findMin(Book* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}


Book* removeBook(Book* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->code)
        root->left = removeBook(root->left, key);
    else if (key > root->code)
        root->right = removeBook(root->right, key);
    else {
        
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        
        if (root->left == NULL) {
            Book* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            Book* temp = root->left;
            delete root;
            return temp;
        }
        
        Book* temp = findMin(root->right);
        root->code = temp->code;
        root->right = removeBook(root->right, temp->code);
    }
    return root;
}




int countBooks(Book* root) {
    if (root == NULL) return 0;
    return 1 + countBooks(root->left) + countBooks(root->right);
}

int main() {
    Book* root = NULL;
    int choice;

    while (true) {
        cout << "\n\n#### LIBRARY MANAGEMENT SYSTEM #####\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Book\n";
        cout << "4. Total Books Count\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int x;
            cout << "Enter Book Code: ";
            cin >> x;
            root = addBook(root, x);
            cout << "Book added successfully";
        }
        else if (choice == 2) {
            int x;
            cout << "Enter Book Code: ";
            cin >> x;
            root = removeBook(root, x);
            cout << "Book removed successfully";
        }
        else if (choice == 3) {
            int x;
            cout << "Enter Book Code to search: ";
            cin >> x;
            if (findBook(root, x))
                cout << "Book FOUND";
            else
                cout << "Book NOT found";
        }
        
        else if (choice == 4) {
            cout << "Total Books: " << countBooks(root);
        }
        
        
        else {
            cout << "Invalid choice!";
        }
    }
    return 0;
}
