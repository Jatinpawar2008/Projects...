#include <iostream>
#include <vector>
using namespace std;

class Book{
    public:
    int id;
    Book* left;
    Book* right;
    bool isBook;
    Book(int ID){
        id = ID;
        isBook = true;
        left = right = NULL;
    }
};

Book* insert(Book* rootBook, int id){
    if(rootBook == NULL){
        return new Book(id);
    }
    if(id < rootBook-> id){
        rootBook-> left = insert(rootBook-> left, id);
    }
    else if(id > rootBook-> id){
        rootBook-> right = insert(rootBook-> right, id);
    }
    return rootBook;
}


Book* search(Book* rootBook, int keyId){
    if(rootBook == NULL) return NULL;
    if(keyId == rootBook-> id) return rootBook;

    if(keyId < rootBook-> id){
        return search(rootBook-> left, keyId);
    }
    else if(keyId > rootBook-> id){
        return search(rootBook-> right, keyId);
    }

}

Book* succesor(Book* rootBook){
    while(rootBook-> left != NULL){
        rootBook = rootBook-> left;
    }
    return rootBook;
}


Book* deleteBook(Book* rootBook, int KeyId){
    if(rootBook == NULL) return NULL;

    if(rootBook-> id > KeyId){
        rootBook-> left =  deleteBook(rootBook-> left, KeyId);
    }
    else if(rootBook-> id < KeyId){
        rootBook-> right = deleteBook(rootBook-> right, KeyId);
    }
    else{   //case jaha rootBook-> id == KeyId
        //for one child---
        if(rootBook-> left ==NULL && rootBook-> right == NULL){
            delete rootBook;
            return NULL;
        }
        //for right child---
        if(rootBook->left == NULL){
            Book* temp = rootBook-> right;
            delete rootBook;
            return temp;
        }
        //for left child---
        if(rootBook->right == NULL){
            Book* temp = rootBook-> left;
            delete rootBook;
            return temp;
        }
        // case when both child exist---
        else{
            Book* success = succesor(rootBook-> right);
            rootBook-> id = success->id;
            rootBook-> right = deleteBook(rootBook-> right, success-> id);
        }

    }
    return rootBook;
}

void displayAllBook(Book* rootBook){
    if(rootBook == NULL) return ;
    displayAllBook(rootBook-> left);
    cout<< rootBook-> id;
    displayAllBook(rootBook-> right);
}



int main(){
    Book* rootBook = NULL;
    int choice;

    while(true){
        cout << "\n----===== OCT Library Management Menu =====----\n";
        cout<< "\n 1. Return book : ";   //Insert or Add Book
        cout<< "\n 2. Delete Book : ";
        cout<< "\n 3. Check (Search) Book : ";
        cout<< "\n 4. Display All Books : ";
        cout<< "\nEnter your Choice: <<< ";
        cin>> choice;
        
        if(choice == 1){
            int n;
            cout << "Enter your Book Id no. : ";
            cin >> n;
            rootBook = insert(rootBook,n);
            cout<< "Book "<< n <<  "returned in library ";
        }
        else if (choice == 2){
            int n; 
            cout<< "Enter your Book Id no. : ";
            cin>> n;
            rootBook = deleteBook(rootBook, n);
            cout<< "Book "<< n <<  " issued form library ";
        }
        else if (choice == 3){
            int n; 
            cout<< "Enter your Book Id to search : ";
            cin>> n;
            displayAllBook(rootBook);
        }
    }
    return 0;
}
