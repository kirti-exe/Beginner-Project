// Library Management System
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Book{
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int id, string title, string author){
        this->id = id;
        this->title = title;
        this->author = author;
        this->isIssued = false;
    }

    void display(){
        cout<<"ID: "<<id   
         <<" | Title: "<<title
         <<" | Author: "<<author
         <<" | Status: "<<(isIssued ? "Issued" : "Available")
         <<endl;
    }
};

class Library{
private:
    vector<Book> books;
public:
    void addBook(int id, string title, string author){
        books.push_back(Book(id, title, author));
        cout<<"Book added successfully.\n";
    }

    void displayBooks(){
        if(books.empty()){
            cout<<"No books available.\n";
            return;
        }
        for(auto &book : books){
            book.display();
        }
    }

    void issueBook(int id){
        for(auto &book : books){
            if(book.id == id){
                if(!book.isIssued){
                    book.isIssued = true;
                    cout<<"Book issued successfully.\n";
                } else {
                    cout<<"Book already issued.\n";
                }
                return;
            }
        }
        cout<<"Book not found.\n";
    }

    void returnBook(int id){
        for(auto &book : books){
            if(book.id == id){
                if(book.isIssued){
                    book.isIssued = false;
                    cout<<"Book returned successfully.\n";
                } else {
                    cout<<"Book not found.\n";
                }
                return;
            }
        }
        cout<<"Book not found.\n";
    }
};

int main(){
    Library lib;
    int choice;

    do{
        cout<<"-----Library Management System-----"<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. Display Book"<<endl;
        cout<<"3. Issue Book"<<endl;
        cout<<"4. Return Book"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1: {
                int id;
                string title, author;
                cout<<"Enter Book ID: ";
                cin>>id;
                cin.ignore();   //clear input buffer
                cout<<"Enter Title: ";
                getline(cin, title);
                cout<<"Enter Author: ";
                getline(cin, author);
                lib.addBook(id, title, author);
            }   break;

            case 2: lib.displayBooks();
                break;

            case 3: {
                int id;
                cout<<"Enter Book ID to issue: ";
                cin>>id;
                lib.issueBook(id);
            }   break;

            case 4: {
                int id;
                cout<<"Enter Book ID to return: ";
                cin>>id;
                lib.returnBook(id);
            }   break;

            case 5: cout<<"Exiting Program. Goodbye!"<<endl;
                break;

            default: cout<<"Invalid Choice. Try again.\n";
        }
    }while(choice != 5);
    return 0;
}
